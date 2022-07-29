/*
 * ======== video_encdec.c ========
 *
 */

/* Codec Engine include files: */
#include <xdc/std.h>
#include <ti/sdo/ce/Engine.h>
#include <ti/sdo/ce/osal/Memory.h>
#include <ti/sdo/ce/video/videnc.h>
#include <ti/sdo/ce/video/viddec.h>

/* BIOS include files: */
#include <ti/bios/include/std.h>
#include <tsk.h>

/* Run Time lib include files: */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/* PSP include files: */
#include <psp_vpfe.h>
#include <psp_vpbe.h>
#include <fvid.h>
#include <psp_tvp5146_extVidDecoder.h>

/* BSL include files */
#include <evmdm6437.h>
//#include <evmdm6437_dip.h>

/* Video Params Defaults */
#include <vid_params_default.h>

/* Video Encoder initialization param: */
#define VE_MAX_BR   (4000000)

/* Align on cache-line boundary since encoder uses DMA */
#define BUFALIGN 128

/* Number of buffers to allocate for video capture + display: */
#define FRAME_BUFF_CNT 6

/* This example supports either PAL or NTSC depending on position of JP1 */
#define STANDARD_PAL  0
#define STANDARD_NTSC 1



/* Video Encoder parameters for D1, set depending on PAL vs NTSC: */
static int intraFrameInterval;
static int inputWidth;
static int inputHeight;
static int maxFrameRate;
/* Encoder Input, Encoder output, and Decoder Output Frame sizes */
static int framesize;

/* Video Frame buffers: */
static FVID_Frame *frameBuffTable[FRAME_BUFF_CNT];
static FVID_Frame *frameBuffPtr = NULL;

/* Video Driver Handles: */
static FVID_Handle hGioVpfeCcdc = NULL;
static FVID_Handle hGioVpbeVid0 = NULL;
static FVID_Handle hGioVpbeVenc = NULL;

/* Intermediate buffer for the encoded video stream: */
static XDAS_Int8 *encodedBuf;

/* Codec Engine engine and codec labels, defined in cfg file: */
static String decoderName  = "h264dec";
static String encoderName  = "h264enc";
static String engineName   = "encdec";

static String progName     = "app";

/* Function prototypes */
static Void initVE_StaticParams(VIDENC_Params *vencParams);
static Void initVE_DynamicParams(VIDENC_DynamicParams *encDynParams);
static Void initVD_StaticParams(VIDDEC_Params *vdecParams);
static Void initVD_DynamicParams(VIDDEC_DynamicParams *decDynParams);
static Void encode_decode(VIDENC_Handle enc, VIDDEC_Handle dec);
//static int  read_JP1(void);

/*
 *  ======== video_encdec ========
 */
/* ARGSUSED */
Int video_encdec(Int argc, String argv[])
{

    int status = 0;
    int result;
    int i;

    Engine_Handle ce = NULL;
    VIDDEC_Handle dec = NULL;
    VIDENC_Handle enc = NULL;

    VIDENC_Status encStatus;
    VIDENC_Params vencParams;
    VIDENC_DynamicParams encDynParams;

    VIDDEC_Status decStatus;
    VIDDEC_Params vdecParams;
    VIDDEC_DynamicParams decDynParams;

    int standard;

    /* Set video display/capture driver params to defaults */
    PSP_VPFE_TVP5146_ConfigParams tvp5146Params = 
       VID_PARAMS_TVP5146_DEFAULT;
    PSP_VPFECcdcConfigParams      vpfeCcdcConfigParams = 
       VID_PARAMS_CCDC_DEFAULT_D1;
    PSP_VPBEOsdConfigParams vpbeOsdConfigParams = 
       VID_PARAMS_OSD_DEFAULT_D1;
    PSP_VPBEVencConfigParams vpbeVencConfigParams;

    printf("video_encdec started.\n");

  //  standard = read_JP1();
    standard =STANDARD_PAL;
  
    /* Update display/capture params based on video standard (PAL/NTSC) */
    if (standard == STANDARD_PAL)  {
       inputWidth  = 720;
       inputHeight = 576;
       intraFrameInterval = 25;
       maxFrameRate = 25000;
       vpbeVencConfigParams.displayStandard = PSP_VPBE_DISPLAY_PAL_INTERLACED_COMPOSITE;
    }
    else {
       inputWidth  = 720;
       inputHeight = 480;
       intraFrameInterval = 30;
       maxFrameRate = 30000;
       vpbeVencConfigParams.displayStandard = PSP_VPBE_DISPLAY_NTSC_INTERLACED_COMPOSITE;
    }
    framesize = (inputWidth * inputHeight * 2 * sizeof(Int8));
    vpfeCcdcConfigParams.height = vpbeOsdConfigParams.height = inputHeight;
    vpfeCcdcConfigParams.width = vpbeOsdConfigParams.width = inputWidth;
    vpfeCcdcConfigParams.pitch = vpbeOsdConfigParams.pitch = inputWidth * 2;

    /* Initialize Video Display Driver:  */
    /* create video input channel */
    if (status == 0) {
       PSP_VPFEChannelParams vpfeChannelParams;
       vpfeChannelParams.id     = PSP_VPFE_CCDC;
       vpfeChannelParams.params = (PSP_VPFECcdcConfigParams*)&vpfeCcdcConfigParams;
       hGioVpfeCcdc = FVID_create("/VPFE0",IOM_INOUT,NULL,&vpfeChannelParams,NULL);
       status = (hGioVpfeCcdc == NULL ? -1 : 0);
    }

    /* create video output channel, plane 0 */
    if (status == 0) {
       PSP_VPBEChannelParams vpbeChannelParams;
       vpbeChannelParams.id     = PSP_VPBE_VIDEO_0;
       vpbeChannelParams.params = (PSP_VPBEOsdConfigParams*)&vpbeOsdConfigParams;
       hGioVpbeVid0 = FVID_create("/VPBE0",IOM_INOUT,NULL,&vpbeChannelParams,NULL);
       status = (hGioVpbeVid0 == NULL ? -1 : 0);
    }

    /* create video output channel, venc */
    if (status == 0) {
       PSP_VPBEChannelParams vpbeChannelParams;
       vpbeChannelParams.id     = PSP_VPBE_VENC;
       vpbeChannelParams.params = (PSP_VPBEVencConfigParams *)&vpbeVencConfigParams;
       hGioVpbeVenc = FVID_create("/VPBE0",IOM_INOUT,NULL,&vpbeChannelParams,NULL);
       status = (hGioVpbeVenc == NULL ? -1 : 0);
    }

    /* configure the TVP5146 video decoder */
    if (status == 0) {
       result = FVID_control(hGioVpfeCcdc, 
            VPFE_ExtVD_BASE+PSP_VPSS_EXT_VIDEO_DECODER_CONFIG, &tvp5146Params);
       status = (result == IOM_COMPLETED ? 0 : -1);
    }

    /* allocate display/capture frame buffers */
    for (i=0; i<FRAME_BUFF_CNT; i++) {
       frameBuffTable[i] = NULL;
    }
    if (status == 0) {
       for (i=0; i<FRAME_BUFF_CNT && status == 0; i++) {
            result = FVID_allocBuffer(hGioVpfeCcdc, &frameBuffTable[i]);
            status = (result == IOM_COMPLETED && frameBuffTable[i] != NULL ? 0 : -1);
       }
    }

    /* prime up the video capture channel */
    if (status == 0) {
        FVID_queue(hGioVpfeCcdc, frameBuffTable[0]);
        FVID_queue(hGioVpfeCcdc, frameBuffTable[1]);
        FVID_queue(hGioVpfeCcdc, frameBuffTable[2]);
    }

    /* prime up the video display channel */
    if (status == 0) {
        FVID_queue(hGioVpbeVid0, frameBuffTable[3]);
        FVID_queue(hGioVpbeVid0, frameBuffTable[4]);
        FVID_queue(hGioVpbeVid0, frameBuffTable[5]);
    }

    /* grab first buffer from input queue */
    if (status == 0) {
        FVID_dequeue(hGioVpfeCcdc, &frameBuffPtr);
    }

    if (status != 0) {
       goto end;
    }

    /* Allocate Encoder output buffer: */
/*    encodedBuf = (XDAS_Int8 *)Memory_contigAlloc(framesize, BUFALIGN);
    if (encodedBuf == NULL) {
        goto end;
    }
    else {
       Memory_cacheWbInv(encodedBuf, framesize);
    }
*/ 
 
    /* use engine to encode, then decode the data */
    encode_decode(enc, dec);

end:

    /* Free Video Driver resources:  */
    if (hGioVpfeCcdc)  {
       for (i=0; i<FRAME_BUFF_CNT && status == 0; i++) {
            FVID_freeBuffer(hGioVpfeCcdc, frameBuffTable[i]);
       }
    }

    /* Delete Channels */
    if (hGioVpfeCcdc)  {
       FVID_delete(hGioVpfeCcdc);
    }
    if (hGioVpbeVid0)  {
       FVID_delete(hGioVpbeVid0);
    }
    if (hGioVpbeVenc)  {
       FVID_delete(hGioVpbeVenc);
    }

    printf("video_encdec done.\n");
    return (0);
}


/*
 *  ======== initVE_StaticParams ========
 */
static Void initVE_StaticParams(VIDENC_Params * vencParams)
{
    /* Set Constant Bit Rate, YUV422 Interlaced, little endian: */
    vencParams->size                  = sizeof(VIDENC_Params);
    vencParams->encodingPreset        = XDM_DEFAULT;
    vencParams->rateControlPreset     = IVIDEO_LOW_DELAY;
    vencParams->maxHeight             = inputHeight; 
    vencParams->maxWidth              = inputWidth; 
    vencParams->maxFrameRate          = maxFrameRate;
    vencParams->maxBitRate            = VE_MAX_BR;
    vencParams->dataEndianness        = XDM_BYTE;
    vencParams->maxInterFrameInterval = 0;
    vencParams->inputChromaFormat     = XDM_YUV_422ILE;
    vencParams->inputContentType      = IVIDEO_PROGRESSIVE;

    return;
}       


/*
 * ======== initVE_DynamicParams ========
 */
static Void initVE_DynamicParams(VIDENC_DynamicParams *encDynParams)
{
  encDynParams->inputHeight     = inputHeight;
  encDynParams->inputWidth      = inputWidth;
  encDynParams->refFrameRate    = maxFrameRate;
  encDynParams->targetFrameRate = maxFrameRate;
  encDynParams->targetBitRate   = VE_MAX_BR;
  encDynParams->intraFrameInterval  = intraFrameInterval;
  encDynParams->generateHeader  = XDM_ENCODE_AU;    
  encDynParams->captureWidth    = 0;      
  encDynParams->forceIFrame     = 0;       

  return;
}


/*
 *  ======== initVD_StaticParams ========
 */
static Void initVD_StaticParams(VIDDEC_Params * vdecParams)
{
    /* Set Constant Bit Rate, YUV422 Interlaced, little endian: */
    vdecParams->size                 = sizeof(VIDDEC_Params);

    vdecParams->maxHeight            = inputHeight;
    vdecParams->maxWidth             = inputWidth;
    vdecParams->maxFrameRate         = 0;
    vdecParams->maxBitRate           = 0;
    vdecParams->dataEndianness       = XDM_BYTE;
    vdecParams->forceChromaFormat    = XDM_YUV_422ILE;

    return ;
}    

/*
 * ======== initVD_DynamicParams ========
 */
static Void initVD_DynamicParams(VIDDEC_DynamicParams *decDynParams)
{
  decDynParams->decodeHeader    = XDM_DECODE_AU;
  decDynParams->displayWidth    = 0;
  decDynParams->frameSkipMode   = IVIDEO_NO_SKIP;

  return;
}

void GrayImage(Uint8 *in_data)
{
	Uint32 i,j;
	for(i = 0; i < 576; i++)
		for(j=0; j <720; j++)
		{
			*(Uint8 *)(in_data + (i*720 + j) * 2) = 0x80;
		}
}

void GrayImage_y(Uint8 *in_data)
{
	Uint32 i,j;
	for(i = 0; i < 576; i++)
		for(j=0; j <720; j++)
		{
			*(Uint8 *)(in_data +1+ (i*720 + j) * 2) = 0x0;
		}
}

void Y2RGB(Uint8 *in_data, Uint8 *rgb_data)
{
	Uint32 i, j;
	Uint8 Y, Cr, Cb;
	for(i = 0; i < 576; i++)
		for(j = 0; j < 720; j++)
		{
			Y = *(Uint8 *)(in_data +1+ (i*720 + j) * 2);
			Cr = (j%2) ? (*(Uint8 *)(in_data + (i*720 + j) * 2)) : (*(Uint8 *)(in_data + (i*720 + j + 1) * 2));
			Cb = (j%2) ? (*(Uint8 *)(in_data + (i*720 + j - 1) * 2)) : (*(Uint8 *)(in_data + (i*720 + j) * 2));
			*(Uint8 *)(rgb_data + (i*720 + j)*3 + 0) = 1.164*(Y-16) + 1.596*(Cr - 128); //R
			*(Uint8 *)(rgb_data + (i*720 + j)*3 + 1) = 1.164*(Y-16) - 0.813*(Cr - 128) - 0.392*(Cb - 128); //G
			*(Uint8 *)(rgb_data + (i*720 + j)*3 + 2) = 1.164*(Y-16) + 2.017*(Cb - 128); //B

		}
}

void RGB2Y(Uint8 *in_data, Uint8 *rgb_data)
{
	Uint32 i, j;
	Uint8 R, G, B;
	for(i = 0; i < 576; i++)
		for(j = 0; j < 720; j++)
		{
			R = *(Uint8 *)(rgb_data + (i*720 + j)*3 + 0);
			G = *(Uint8 *)(rgb_data + (i*720 + j)*3 + 1);
			B = *(Uint8 *)(rgb_data + (i*720 + j)*3 + 2);
			*(Uint8 *)(in_data + 1 + (i*720 + j) * 2) = 0.257*R + 0.504*G + 0.098*B + 16; //Y
			if(j%2)
				*(Uint8 *)(in_data + (i*720 + j)*2) = 0.439*R - 0.368*G - 0.071*B + 128; //Cr
			else
				*(Uint8 *)(in_data + (i*720 + j)*2) = -0.148*R - 0.291*G + 0.439*B + 128; //Cb
		}
}

void SKIN_Detector(Uint8 *in_data)
{
	Uint32 i, j;
	Uint8 Y, Cr, Cb;
	Uint32 up = 576, down = 0, left = 720, right = 0;
	Uint32 Long1, Short1;
	for(i = 20; i < 556; i++)
		for(j = 20; j < 680; j++)
		{
			//颜色空间转化
			Y = *(Uint8 *)(in_data +1+ (i*720 + j) * 2);
			Cr = (j%2) ? (*(Uint8 *)(in_data + (i*720 + j) * 2)) : (*(Uint8 *)(in_data + (i*720 + j + 1) * 2));
			Cb = (j%2) ? (*(Uint8 *)(in_data + (i*720 + j - 1) * 2)) : (*(Uint8 *)(in_data + (i*720 + j) * 2));

			//肤色判别,利用 Cr Cb 判断人脸的肤色
			if( (Cr > 133) && (Cr < 173) && (Cb > 77) && (Cb < 127) )
			{
//				*(Uint8 *)(in_data +1+ (i*720 + j) * 2) = 0;
//				(*(Uint8 *)(in_data + (i*720 + j) * 2)) = 0;
//				(*(Uint8 *)(in_data + (i*720 + j - 1) * 2)) = 0;

			//up down lef right 分别代表上下左右边界
				if( i < up )
					up = i;
				if( i > down )
					down = i;
				if( j < left )
					left = j;
				if( j > right)
					right = j;
			}

			//除了人脸区域其他像素变成灰色				
			else
			{
//				*(Uint8 *)(in_data +1+ (i*720 + j) * 2) = 0x80;
				(*(Uint8 *)(in_data + (i*720 + j) * 2)) = 0x80;
//				(*(Uint8 *)(in_data + (i*720 + j - 1) * 2)) = 0x80;
			}
			
		}
		Long1 = down - up;
		Short1 = right - left;
		//人脸长宽比位于1.2~1.8之间
		if(((double)Long1/Short1>1.2)&&(double)(Long1/Short1<1.8))
		{
		//画出人脸方框
		for(i = up; i< down;i++)
		{
			*(Uint8 *)(in_data + (i*720 + left) * 2) = 0;
			*(Uint8 *)(in_data + (i*720 + left - 1) * 2) = 0;
			*(Uint8 *)(in_data + (i*720 + right) * 2) = 0;
			*(Uint8 *)(in_data + (i*720 + right - 1) * 2) = 0;
		}

		for( j = left; j < right ; j++ )
		{
			(*(Uint8 *)(in_data + (up*720 + j) * 2)) = 0;
			(*(Uint8 *)(in_data + (up*720 + j - 1) * 2)) = 0;
			(*(Uint8 *)(in_data + (down*720 + j) * 2)) = 0;
			(*(Uint8 *)(in_data + (down*720 + j - 1) * 2)) = 0;

		}
		}

}

void GrayEqualize(Uint8 *in_data)
{
	int i,j;
    Int intArea, intTemp;
	Int intCount[256];
	Uint8  grayMap[256];
	Uint32 M=576,N=720;
	intArea = M * N;// 计算面积
	for(i = 0; i < 256; i++) //重置计数
		{
			intCount[i] = 0;
		}
	for(i = 0; i <M-2; i++)  //计算灰度值
	for(j = 0; j <N-2; j++)
				{
					intTemp = *(Uint8 *)(in_data + (i*N + j) * 2 + 1);
					intCount[intTemp]++;
				}
		for(i = 0; i < 256; i++)  //计算映射表
			{
				intTemp = 0;
				for(j = 0; j <= i; j++)
				{
					intTemp += intCount[j];
				}
				grayMap[i] = (Uint8)(intTemp * 255 / intArea);
			}
		for(i = 0; i <M-2; i++) //灰度均衡
				for(j =0; j <N-2; j++)
				{
					intTemp = *(Uint8 *)(in_data + (i*N + j) * 2 + 1);
					*(Uint8 *)(in_data + (i*N + j) * 2 + 1) = grayMap[intTemp];
				}
}
					


void LaplacianEdge(Uint8 *in_data)
{
	Int i,j;
	Int d1,d2,intTemp;
	Uint32 M=576,N=720;
		for(i = 0; i <M-2 ; i++)
		for(j = 0; j <N-2 ; j++)
		{
			d1 = - *(Uint8 *)(in_data + (i*N+j+1)*2+1) - *(Uint8 *)(in_data + ((i+1)*N+j+1)*2+1) + *(Uint8 *)(in_data + ((i+1)*N+j+1)*2+1)*4 - *(Uint8 *)(in_data + ((i+1)*N+j+2)*2+1) - *(Uint8 *)(in_data + ((i+2)*N+j+1)*2+1);
			d2 = - *(Uint8 *)(in_data + (i*N+j)*2+1) - *(Uint8 *)(in_data +((i+1)*N+j)*2+1) - *(Uint8 *)(in_data + ((i+2)*N+j)*2+1)- *(Uint8 *)(in_data + (i*N+(j+1))*2+1)+ *(Uint8 *)(in_data +((i+1)*N+j+1)*2+1) * 8 - *(Uint8 *)(in_data + ((i)*N+j+2)*2+1) - *(Uint8 *)(in_data +((i+1)*N+j+2)*2+1)  - *(Uint8 *)(in_data + ((i+2)*N+j+2)*2+1)  - *(Uint8 *)(in_data + ((i+2)*N+j+1)*2+1);
			intTemp = d1 > d2 ? d1 : d2;
			if(intTemp < 0)	intTemp = 0;
			if(intTemp > 255)	intTemp = 255;
			*(Uint8 *)(in_data + (i*N + j) * 2 + 1) = intTemp;
		}
}

void SobelEdge(Uint8 *in_data)
{
	Int i,j;
	Int d1,d2,intTemp; 
	Uint32 M=576,N=720;
	for(i = 0; i <M-2; i++)
		for(j =0; j <N-2;j++)
		{
			d1 = - *(Uint8 *)(in_data + (i*N+j)*2+1) - *(Uint8 *)(in_data + (i*N+j+1)*2+1) * 2 - *(Uint8 *)(in_data + (i*N+j+2)*2+1) + *(Uint8 *)(in_data + ((i+2)*N+j)*2+1) + *(Uint8 *)(in_data + ((i+2)*N+j+1)*2+1) * 2 + *(Uint8 *)(in_data + ((i+2)*N+j+2)*2+1);
			d2 = - *(Uint8 *)(in_data + (i*N+j)*2+1) - *(Uint8 *)(in_data +((i+1)*N+j)*2+1) * 2- *(Uint8 *)(in_data + ((i+2)*N+j)*2+1) + *(Uint8 *)(in_data + ((i)*N+j+2)*2+1) + *(Uint8 *)(in_data +((i+1)*N+j+2)*2+1) * 2 + *(Uint8 *)(in_data + ((i+2)*N+j+2)*2+1);
			intTemp = d1 > d2 ? d1 : d2;
			if(intTemp < 0)	intTemp = 0;
			if(intTemp > 255)	intTemp = 255;
			*(Uint8 *)(in_data + (i*N + j) * 2 + 1) = intTemp;
		}
}
void MedianFilter(Uint8 *in_data)
{
	int i,j,a,b;
	Uint8 aValue[9],bTemp;
	Uint32 M=576,N=720;
	for(i = 0; i <M-2; i++)
		for(j =0; j <N-2;j++)
		{
			aValue[0] = *(Uint8 *)(in_data + ((i-1)*N + (j-1))*2+1); 
			aValue[1] =	*(Uint8 *)(in_data + ((i-1)*N + j)*2+1); 
			aValue[2] =	*(Uint8 *)(in_data + ((i-1)*N + (j+1))*2+1); 
			aValue[3] =	*(Uint8 *)(in_data + (i*N + (j-1))*2+1); 	
			aValue[4] =	*(Uint8 *)(in_data + (i*N + j)*2+1); 
			aValue[5] =	*(Uint8 *)(in_data + (i*N + (j+1))*2+1); 
			aValue[6] =	*(Uint8 *)(in_data + ((i+1)*N + (j-1))*2+1);
			aValue[7] =	*(Uint8 *)(in_data + ((i+1)*N + j)*2+1);
			aValue[8] =	*(Uint8 *)(in_data + ((i+1)*N + (j+1))*2+1);
			for(b=0;b<5;b++)//排序
				for(a=b;a<=8;a++)
				{
					if(aValue[b]>aValue[a])
{
						bTemp = aValue[b];
						aValue[b] = aValue[a];
						aValue[a] = bTemp;
					}
				}
			*(Uint8 *)(in_data + (i*N + j) * 2 + 1) = aValue[4];
		}
}
void GradsSharp(Uint8 *in_data) //梯度锐化
{
	Int i,j;
	Int intTemp;
	Uint32 M=576,N=720;
	for(i = 0; i <M-2; i++)
		for(j =0; j <N-2;j++)
		{
              {
			intTemp = abs(*(Uint8 *)(in_data + (i*N + j)*2+1) - *(Uint8 *)(in_data + ((i+1)*N + (j+1))*2+1)) +abs(*(Uint8 *)(in_data + ((i+1)*N + j)*2+1) - *(Uint8 *)(in_data + (i*N + (j+1))*2+1));
			if(intTemp < 0)		intTemp = 0;
			if(intTemp > 255)		intTemp = 255;
			*(Uint8 *)(in_data + (i*N + j) * 2 + 1) = intTemp;
			}
		}
}

void HorizTranspose(Uint8 *in_data)
{
	int i,j;
	Uint32 M=576,N=720;
	for(i = M/2; i <M-2; i++)
		for(j=0; j <N-2; j++)	//y从M/2开始,将图像上半部分做水平镜像
		{
			*(Uint8 *)(in_data + (i*N + j) * 2 + 1) = *(Uint8 *)(in_data + ((M - i)*N + j) * 2 + 1);
			*(Uint8 *)(in_data + (i*N + j) * 2 ) = *(Uint8 *)(in_data + ((M - i)*N + j) * 2);
		}
}
void VertTranspose(Uint8 *in_data)
{
	int i,j;
	Uint32 M=576,N=720;
	for(i = 0; i <M-2; i++)
		for(j=0; j <N-2; j++)	//x从N/2开始,左半图像垂直镜像显示到右半部分
		{
			*(Uint8 *)(in_data + (i*N + j) * 2 + 1) = *(Uint8 *)(in_data + (i*N +N- j) * 2 + 1);// i*N + j为i行j列点的像素存放地址，每个像素的两个变量占两个地址
		
		}
}


//================================================================
void Histogram(Uint8 *in_data)
{

GrayImage(in_data);
//VertTranspose(in_data);
MedianFilter(in_data);
GrayEqualize(in_data);
//Histogramw(in_data);
//GradsSharp(in_data);
//SobelEdge(in_data);
LaplacianEdge(in_data);


}
static Void encode_decode(VIDENC_Handle enc, VIDDEC_Handle dec)
{
    Int32                       n, frame=0;

    XDM_BufDesc                 inBufDesc;
    XDM_BufDesc                 encodedBufDesc;
    XDM_BufDesc                 outBufDesc;
    Int32                       status;

    XDAS_Int32                  ibufSizes;
    XDAS_Int32                  ebufSizes;
    XDAS_Int32                  obufSizes;

    VIDDEC_InArgs               decInArgs;
    VIDDEC_OutArgs              decOutArgs;

    VIDENC_InArgs               encInArgs;
    VIDENC_OutArgs              encOutArgs;

    XDAS_Int8                   *src;
    XDAS_Int8                   *encoded;
    XDAS_Int8                   *dst;

    /* Initialize .size fields */
    encInArgs.size = sizeof(encInArgs);
    decInArgs.size = sizeof(decInArgs);
    encOutArgs.size = sizeof(encOutArgs);
    decOutArgs.size = sizeof(decOutArgs);

    /* Set numbufs for vencParams.inputChromaFormat = XDM_YUV_422ILE: */
    inBufDesc.numBufs = encodedBufDesc.numBufs = outBufDesc.numBufs = 1;

    ibufSizes = ebufSizes = obufSizes = framesize;

    inBufDesc.bufSizes       = &ibufSizes;
    encodedBufDesc.bufSizes  = &ebufSizes;
    outBufDesc.bufSizes      = &obufSizes;

    /*
     * Read complete frames from in, encode, decode, and write to out.
     */
    printf("Starting encode/decode loopback ...\n");
    for (n=0;;n++) {
        /* prepare "per loop" buffer descriptor settings */
        inBufDesc.bufs = &src;
        encoded = encodedBuf;
        encodedBufDesc.bufs = &encodedBuf;
        outBufDesc.bufs = &dst;

        /* grab a fresh video input frame */
        FVID_exchange(hGioVpfeCcdc, &frameBuffPtr);
		Histogram(frameBuffPtr->frame.frameBufferPtr);
        
        /* Set as input buffer to Encoder: */
      //  src = frameBuffPtr->frame.frameBufferPtr;
	//	GrayImage(frameBuffPtr->frame.frameBufferPtr);
	//	GrayImage_y(frameBuffPtr->frame.frameBufferPtr);

 	//	Memory_cacheWbInv(dst, framesize);
        /* display the video frame */
        FVID_exchange(hGioVpbeVid0, &frameBuffPtr);
		//printf("frame = %d\n", frame);
		//frame++;

    }
}
