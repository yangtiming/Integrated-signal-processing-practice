/*
 *  ======== speech_encdec.c ========
 */

/* Codec Engine include files: */
#include <xdc/std.h>
#include <ti/bios/include/std.h>
#include <ti/sdo/ce/CERuntime.h>
#include <ti/sdo/ce/Engine.h>
#include <ti/sdo/ce/osal/Memory.h>
#include <ti/sdo/ce/speech/sphdec.h>
#include <ti/sdo/ce/speech/sphenc.h>

/* PSP include files: */
#include <psp_common.h>
#include <psp_audio.h>

/* BIOS include files: */
#include <gio.h>
#include <iom.h>

/* Run Time lib include files: */
#include <string.h>

/* 
 * Buffers placed in external memory are aligned on a 128 bytes boundary.
 * In addition, the buffer should be of a size multiple of 128 bytes for 
 * the cache work optimally on the C6x.
 */
#define NUMSAMPLES 2048    /* number of samples in the frame */
#define BUFALIGN   128    /* alignment of buffer to allow use of L2 cache */

/* actual size in MADUs of buf to be submitted to driver by GIO_submit */
#define BUFSIZE     (NUMSAMPLES * sizeof(MdUns)) 

/* Note: G.711 generates 1/2 the size of the input: */
#define EFRAMESIZE  (BUFSIZE / 2)  /* encoded frame */

#define SAMPLE_RATE_G711   8000  // G.711 works on 8Khz.

/* These are defined in the DSP/BIOS configuration file. */
extern SEM_Obj semRx;  /* Blocked on while waiting for input buffer */ 
extern SEM_Obj semTx;  /* Blocked on while waiting for output buffer */ 

/* Buffer to hold encoded data before feeding to encoder: */
//static XDAS_Int8 *encodedBuf;

//static String progName     = "speech_encdec";

/* Codec engine labels for this engine: */
//static String engineName   = "encdec";
//static String decoderName  = "g711dec";
//static String encoderName  = "g711enc";

/* 
 * Ping-pong buffers to be used for transfers.
 * Variables rxDone, rxBusy, txDone, txBusy manipulated by XOR operation
 * are used to keep the status of those ping-pong buffers. 
 */
#pragma DATA_ALIGN(rxBuf, BUFALIGN)
#pragma DATA_ALIGN(txBuf, BUFALIGN)

MdUns rxBuf[2][NUMSAMPLES];
MdUns txBuf[2][NUMSAMPLES];

/*
 * variables that are used to keep track of the usage of the buffers 
 * for both receive and transmit channels
 */
Int rxDone = 0;
Int txDone = 0;

/* inChan and outChan are GIO handles created in speech_encdec  */
GIO_Handle      inChan, outChan;
GIO_AppCallback appReadCb, appWriteCb;

/* Function prototypes */
static Void prime();
static Void rxCallback(Ptr arg, Int status, Ptr bufp, Uns size);  
static Void txCallback(Ptr arg, Int status, Ptr bufp, Uns size);  
static Void encode_decode(SPHENC_Handle enc, SPHDEC_Handle dec);

#define ORD_h1 63
#define LEN_h1 64 
short h1[64] = {//200～3400Hz带通滤波器系数,Q15量化
	-17,     27,     12,    -30,     66,   -119,    106,   -193,
  	66,   -196,   -102,   -110,   -385,      7,   -686,     27,
	-855,   -191,   -767,   -708,   -421,  -1423,      6,  -2058,
	183,  -2209,   -305,  -1410,  -1999,   1226,  -7150,  19215,
	19215,  -7150,   1226,  -1999,  -1410,   -305,  -2209,    183,
	-2058,      6,  -1423,   -421,   -708,   -767,   -191,   -855,
	27,    -686,     7,   -385,   -110,   -102,   -196,     66,
	-193,     106,   -119,     66,    -30,     12,     27,    -17};

short h2[64] = {//200～3400Hz带通滤波器系数,Q15量化
	-10,     20,     10,    -30,     60,   -110,    100,   -190,
  	66,   -196,   -102,   -110,   -385,      7,   -686,     27,
	-855,   -191,   -767,   -708,   -421,  -1423,      6,  -2058,
	183,  -2209,   -305,  -1410,  -1999,   1226,  -7150,  19215,
	19215,  -7150,   1226,  -1999,  -1410,   -305,  -2209,    183,
	-2058,      6,  -1423,   -421,   -708,   -767,   -191,   -855,
	27,    -686,     7,   -385,   -110,   -102,   -196,     66,
	-190,     100,   -110,     60,    -30,     10,     20,    -10};

short h_used[64];

/**/
//experiment 1
int seed=12357L;

/*
//experiment 2
short y01=5671, y02=0;
*/

/*
//experiment 3
#define ORD2 64
short bp200_3400[ORD2] = {//200～3400Hz带通滤波器系数,Q15量化
	-17,     27,     12,    -30,     66,   -119,    106,   -193,
  	66,   -196,   -102,   -110,   -385,      7,   -686,     27,
	-855,   -191,   -767,   -708,   -421,  -1423,      6,  -2058,
	183,  -2209,   -305,  -1410,  -1999,   1226,  -7150,  19215,
	19215,  -7150,   1226,  -1999,  -1410,   -305,  -2209,    183,
	-2058,      6,  -1423,   -421,   -708,   -767,   -191,   -855,
	27,    -686,     7,   -385,   -110,   -102,   -196,     66,
	-193,     106,   -119,     66,    -30,     12,     27,    -17};

short x[ORD2+512-1];
*/

/*
//experiment 4
int y1 =0,  y2 = 0;
short x1 = 0, x2 = 0;
*/


/*
//experiment 5
#include "math.h"
void fft(float *x, float *y, int n, int sign)
{
    int i,j,k,l,m,n1,n2;
    float c,s,tr,ti,pi=4.0*atan(1.0);

    for(j=i=1;i<16;i++)
	{ 
		m = i; 
		j = 2*j; 
		if(j==n) break;
	}
    for(n1=n-1, j=0,i=0;i<n1;i++)
    {
        if(i<j)  
        {
            tr = x[j];   ti = y[j]; x[j] = x[i]; 
            y[j] = y[i]; x[i] = tr; y[i] = ti;
        }
        k = n/2;    
        while(k<=j) {j=j-k; k = k/2;}
        j = j+k;
    }
    for(n1=l=1;l<=m;l++)
	{    
        n1=2*n1; n2 = n1/2;
        for(j=0;j<n2;j++)
		 {        
		    c=cos(j*pi/n2);
		    s=-sign*sin(j*pi/n2);
           for(i=j;i<n;i+=n1)
			{
	            k=i+n2; 
	            tr=c*x[k]-s*y[k];  ti=c*y[k]+s*x[k];
                x[k]=x[i]-tr;      y[k]=y[i]-ti;    
	            x[i]=x[i]+tr;      y[i]=y[i]+ti;
			}
		 }
	}
    if(sign==-1)
	{    
        for(i=0;i<n;i++) {x[i] /= n; y[i] /= n;}
	}
}
*/

/*
//#define ORD2 0//
short h2[ORD2] = 
{

};
*/

//延迟线初始化
short Delay_L[ORD_h1], Delay_R[ORD_h1];

void FIRfilt_init()
{
	memset(Delay_L, 0, sizeof(short)*ORD_h1);
	memset(Delay_R, 0, sizeof(short)*ORD_h1);
}

/*
 *  ======== speech_encdec ========
 */
/* ARGSUSED */
Int speech_encdec(Int argc, String argv[])
{
    SPHDEC_Handle dec = NULL;
    SPHENC_Handle enc = NULL;

    //Uint32 sampleRate = SAMPLE_RATE_G711;
	
    printf("speech_encdec started.\n");

    /* allocate encoded buffer: */
/*    encodedBuf = (XDAS_Int8 *)Memory_contigAlloc(EFRAMESIZE, BUFALIGN);
    if (encodedBuf == NULL) {
        goto end;
    }
    else {
      Memory_cacheWbInv(encodedBuf, EFRAMESIZE);
    }
*/	  


    /* Initialize IOM driver callbacks */
    appReadCb.fxn  = rxCallback;
    appWriteCb.fxn = txCallback;

    /* Create I/O streams */
    outChan = GIO_create("/udevCodec", IOM_OUTPUT, NULL, NULL, NULL);
    if (outChan == NULL) {
        printf("Create output channel FAILED.\n");
        goto end;
    }

    inChan = GIO_create("/udevCodec", IOM_INPUT, NULL, NULL, NULL);
    if (inChan == NULL) {
        printf("Create input channel FAILED.\n");
        goto end;
    }

    /* Call prime function to prime I/O streams */
    prime();

    /* use engine to encode, then decode the data */
    encode_decode(enc, dec);

end:

    /* Delete the audio I/O channels: */            
    if (inChan)  {
       GIO_delete(inChan);
    }

    if(outChan) {
       GIO_delete(inChan);
    }

    /* free buffers */
/*    if (encodedBuf) {
        Memory_contigFree(encodedBuf, EFRAMESIZE);
    }
*/
    printf("speech_encdec done.\n");

    return (0);
}

/*
 *  ======== encode_decode ========
 */
static Void encode_decode(SPHENC_Handle enc, SPHDEC_Handle dec)
{
    Int                         n;
    XDM_BufDesc                 inBufDesc;
    XDM_BufDesc                 encodedBufDesc;
    XDM_BufDesc                 outBufDesc;
    Int32                       status;
    XDAS_Int32                  bufSizes = BUFSIZE;
    XDAS_Int32                  ebufSizes = EFRAMESIZE;

    SPHDEC_InArgs               decInArgs;
    SPHDEC_OutArgs              decOutArgs;

    SPHENC_InArgs               encInArgs;
    SPHENC_OutArgs              encOutArgs;
	int 						i, j;

    Uns rxSize = BUFSIZE;
    Uns txSize = BUFSIZE;

	//滤波部分 FIRfilt

short *src2, *dst2;
short inchan_L[512], inchan_R[512],  outchan_L[512],  outchan_R[512];
short delaytmp_L[ORD_h1+512],  delaytmp_R[ORD_h1+512];
int sum_L, sum_R;


    /* prepare "global" buffer descriptor settings */
    inBufDesc.numBufs = encodedBufDesc.numBufs = outBufDesc.numBufs = 1;
    inBufDesc.bufSizes = outBufDesc.bufSizes =  &bufSizes;
    encodedBufDesc.bufSizes = &ebufSizes;

    encInArgs.size = sizeof(encInArgs);
    decInArgs.size = sizeof(decInArgs);
    encOutArgs.size = sizeof(encOutArgs);
    decOutArgs.size = sizeof(decOutArgs);
  
  	FIRfilt_init();

	memcpy(h_used,h1,LEN_h1*2);
    /*
     * Read complete frames from input, encode, decode, and write to output.
     */
    for (n=0;  ; n++)
    {

        XDAS_Int8 *src     = (XDAS_Int8 *)rxBuf[rxDone];
       // XDAS_Int8 *encoded = encodedBuf;
        XDAS_Int8 *dst     = (XDAS_Int8 *)txBuf[txDone];

        /* prepare "per loop" buffer descriptor settings */
        inBufDesc.bufs = &src;
       // encodedBufDesc.bufs = &encoded;
        outBufDesc.bufs = &dst;

		src2 = (XDAS_Int16 *)rxBuf[rxDone]; //
		dst2 = (XDAS_Int16 *)txBuf[txDone]; //

        /* Waiting for receive buffer and transmit buffer */
        SEM_pend(&semRx, SYS_FOREVER);
        SEM_pend(&semTx, SYS_FOREVER);

        /* 
         * Since the src buffer is filled by DMA via the audio driver, and the
         * speech encoder uses the CPU to access that buffer, we must invalidate
         * (but not write back) the cache:
         */

/*		memcpy(dst, src, bufSizes);
		for(i=0;i<bufSizes/8;i++)
		{
			*(dst+i*8)=0;
			*(dst+i*8+1)=0;
		}
*/

//		memcpy(dst, src, bufSizes);
	


		/*--------------FIR-------------------*/
		for(i=0; i<512; i++)
		{
			inchan_L[i] = src2[i*4];
			inchan_R[i] = src2[i*4+2];
		}

		//memcpy(delaytmp_L, Delay_L, sizeof(short)*ORD_h1);
		//memcpy(delaytmp_R, Delay_R, sizeof(short)*ORD_h1);
		//memcpy(&delaytmp_L[ORD_h1], inchan_L, sizeof(short)*512);
		//memcpy(&delaytmp_R[ORD_h1], inchan_R, sizeof(short)*512);

//		SEM_pend(&semRx, SYS_FOREVER);
//        SEM_pend(&semTx, SYS_FOREVER);


/**/
		//experiment 1
     	for(i=0; i<512; i++)
	    {

			outchan_L[i] = inchan_L[i];
			//outchan_R[i] = inchan_R[i];
			//seed=((seed<<11)-(seed<<1)-seed+1)&1048575L;
			//outchan_R[i] = (short)(seed>>5)-16384;
		}
/*
        //experiment 2
	    for(i=0; i<512; i++)
		{

			outchan_L[i] = inchan_L[i];
			//outchan_R[i] = inchan_R[i];
			{
			    int aa;
			  
                aa=(y01*30743L>>14)-y02;
                y02=y01;
                y01=(short)aa;
				outchan_R[i] = y01;
            }
	    }

		//experiment 3
		for(i=0; i<ORD2-1; i++) x[i]=x[512+i];
        for(i=0; i<512; i++) x[i+ORD2-1]=inchan_R[i];

	    for(i=0; i<512; i++)
		{

			outchan_L[i] = inchan_L[i];
			//outchan_R[i] = inchan_R[i];
			{
				int aa;

				for(aa=j=0; j<ORD2; j++) { aa += x[i+j]*bp200_3400[j]; }
				outchan_R[i] =(short)(aa>>15);
			}
		}

		//experiment 4
	    for(i=0; i<512; i++)
		{

			outchan_L[i] = inchan_L[i];
			//outchan_R[i] = inchan_R[i];
			{
				int L_tmp;

				L_tmp  =    (y1>>16)*7807 + ( (y1&0x0000ffff)*7807>>15 )
						     +  (y2>>16)*(-3733) + ( (y2&0x0000ffff)*(-3733) >> 15)
					         + (inchan_R[i]+x2-x1-x1)*1899;
				x2 = x1;
				x1 = inchan_R[i];
				if(L_tmp>134217727L) L_tmp=134217727L;
				if(L_tmp<-134217728L) L_tmp=-134217728L;
				outchan_R[i] =(short)((L_tmp+2048L)>>12);

				L_tmp<<=4;
				y2=y1;
				y1=(L_tmp&0xffff0000)|((L_tmp&0x0000ffff)>>1);

			}
		}




		//experiment 5
		{
     		float x[512], y[512];

		    for(i=0; i<512; i++)
			{

				//outchan_R[i] = inchan_R[i];
				x[i]=inchan_R[i];
				y[i]=0;

			}

			fft(x, y, 512, 1);

			for(i=0; i<512; i++)
			{
			    x[i]=y[i]=0;			
			}
			fft(x, y, 512, -1);

		    for(i=0; i<512; i++)
			{

				outchan_L[i] = inchan_L[i];
				outchan_R[i] = (short)x[i];
			}			
		}

*/



		//memcpy(Delay_L, &delaytmp_L[512], sizeof(short)*ORD_h1);
		//memcpy(Delay_R, &delaytmp_R[512], sizeof(short)*ORD_h1);


		for(i=0; i<512; i++)
		{
			dst2[i*4] = outchan_L[i];
			dst2[i*4+2] = outchan_R[i];
		}
/**/

        /* 
         * Since the out buffer was written by the CPU, and will be submitted
         * to an audio driver accessing that buffer using DMA, we must
         * write back the cache.
         */
        /* Queue up next input buffer, submit output buffer: */
//		SEM_pend(&semRx, SYS_FOREVER);
//        SEM_pend(&semTx, SYS_FOREVER);
        GIO_submit(inChan, IOM_READ, rxBuf[rxDone], &rxSize, &appReadCb);
        GIO_submit(outChan, IOM_WRITE, txBuf[txDone], &txSize, &appWriteCb);

        rxDone = rxDone ^ 1;    /* XOR for rxDone */            
        txDone = txDone ^ 1;    /* XOR for txDone */

    }
}


/*
 * ======== prime ========
 */
static Void prime()
{ 
    Uns rxSize = BUFSIZE;
    Uns txSize = BUFSIZE;

    printf("priming...\n");
    
    /* Initialize two buffers of silence for the output priming */    
    memset(txBuf[0], 0, sizeof(txBuf[0]));
    memset(txBuf[1], 0, sizeof(txBuf[1]));       
     
    if (GIO_submit(inChan, IOM_READ, rxBuf[0], &rxSize, &appReadCb) < 0) {
        SYS_abort("GIO_submit of rxBuf[0] failed\n");
    } 
    if (GIO_submit(inChan, IOM_READ, rxBuf[1], &rxSize, &appReadCb) < 0) {
        SYS_abort("GIO_submit of rxBuf[1] failed\n");
    } 
     
    if (GIO_submit(outChan, IOM_WRITE, txBuf[0], &txSize, &appWriteCb) < 0) {
        SYS_abort("GIO_submit of txBuf[0] failed\n");
    } 
    if (GIO_submit(outChan, IOM_WRITE, txBuf[1], &txSize, &appWriteCb) < 0) {
        SYS_abort("GIO_submit of txBuf[1] failed\n");
    } 

}

/*
 *  ======== rxCallback ========
 *
 *  Callback function for the IOM_READ channel 
 */
/* ARGSUSED */
static Void rxCallback(Ptr arg, Int status, Ptr bufp, Uns size)
{
    SEM_post(&semRx);                   /* Post semaphore for the rx channel */
}


/*
 *  ======== txCallback ========
 *
 *  Callback function for the IOM_WRITE channel
 */ 
/* ARGSUSED */
static Void txCallback(Ptr arg, Int status, Ptr bufp, Uns size)
{
    SEM_post(&semTx);                   /* Post semaphore for the tx channel */
}

