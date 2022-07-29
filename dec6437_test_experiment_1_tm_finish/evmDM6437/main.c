/*
 * ======== main.c ========
 *
 */

/* Type systems: */
#include <xdc/std.h>
#include <ti/bios/include/std.h>

/* BIOS include files: */
#include <tsk.h>
#include <sys.h>
#include <trc.h>
#include <ti/sdo/ce/CERuntime.h>

/* PSP include files: */
#include <soc.h>
#include <cslr_sysctl.h>

/* Extra QDMA setup function */
#include <qdma_setup.h>

/* BSL include files */
#include "evmdm6437_uart.h"

/* Set audio task priority higher than video */
#define AUDIO_TSK_PRIORITY (6)
#define VIDEO_TSK_PRIORITY (1)
#define NET_TSK_PRIORITY   (5)
#define UART485_TSK_PRIORITY (7)

extern Int edma3init();
extern Int speech_encdec(Int argc, String argv[]);
extern Int video_encdec(Int argc, String argv[]);
extern int StackTest();
extern void Uart485_Test();

static String taskNameAudio = "speech_encdec";
static String taskNameVideo = "video_encdec";
static String taskNameNet 	= "tskNdkStackTest";
static String taskNameUart485 = "tskUart485Test";

static CSL_SysctlRegsOvly sysModuleRegs = (CSL_SysctlRegsOvly )CSL_SYS_0_REGS;

#define s_mcbsp     * ( volatile Uint8* )0x44000004
#define reset_5150       *( volatile Uint8* )0x44000000
#define DEV_CFG_BASE            0x01C40000
#define CFG_PINMUX1             *( volatile Uint32* )( DEV_CFG_BASE + 0x04 )

void open_global_int()
{
 	/*开全局中断*/
	asm(" MVC CSR,B0 ");
	asm(" OR 1,B0,B0 ");
	asm(" MVC B0,CSR ");
}

void open_int4()
{
 	/*开中断5*/
  	asm(" MVK 10h,B1 ");
	asm(" MVC IER,B0");
	asm(" OR B1,B0,B0");
	asm(" MVC B0,IER");
}

void open_int6()
{
 	/*开中断6*/
  	asm(" MVK 40h,B1 ");
	asm(" MVC IER,B0");
	asm(" OR B1,B0,B0");
	asm(" MVC B0,IER");
}


UART_Handle uart1;




/*
 * ======== main ========
 */
Int main(Int argc, String argv[])
{

    TSK_Attrs attrsVid = TSK_ATTRS;
    TSK_Attrs attrsAudio = TSK_ATTRS;
	TSK_Attrs attrsNet = TSK_ATTRS;
	TSK_Attrs attrsUart485 = TSK_ATTRS;

	TSK_Attrs attrsMytest = TSK_ATTRS;


    /* Initialize BSL library to read jumper switches: */
	//CFG_PINMUX1 = 0x1200000; 
	CFG_PINMUX1|=(1<<24); 
    reset_5150 = 2;
	s_mcbsp=0x01;  
	_wait(1000);

    /* VPSS PinMuxing */
    sysModuleRegs -> PINMUX0    &= (0x005482A3u);
    sysModuleRegs -> PINMUX0    |= (0x005482A3u);
    /* PCIEN    =   0: PINMUX1 - Bit 0 */
    sysModuleRegs -> PINMUX1 &= (0xFFFFFFFEu);
    sysModuleRegs -> VPSSCLKCTL = (0x18u);

    /* Initialization required for the audio driver */
    edma3init();

    /* Initialize Codec Engine: */
//    CERuntime_init();

    /* Configure QMDA priority of codecs to be lower than VPBE */
    qdma_setup();


#if 1 
    /* Setup audio task, and start  (See ../../examples/speech_encdec): */   
    attrsAudio.stacksize = 16 * 1024;  
    attrsAudio.name = taskNameAudio;
    attrsAudio.priority = AUDIO_TSK_PRIORITY;

    if (TSK_create((Fxn)speech_encdec, &attrsAudio, NULL, NULL) == NULL) 
    {
        SYS_abort("main: failed to create speech_encdec thread.");
    }
#endif
#if 1
    /* Setup video task, and start (See ../../examples/video_encdec): */   
    attrsVid.stacksize = 32 * 1024;  
    attrsVid.name = taskNameVideo;
    attrsVid.priority = VIDEO_TSK_PRIORITY;

    if (TSK_create((Fxn)video_encdec, &attrsVid, NULL, NULL) == NULL) 
    {
        SYS_abort("main: failed to create video_encdec thread.");
    }
#endif
#if 1
    /* Setup net task, and start (See ndk_1_92_00_22_eval/packages/ti/ndk/example/network/client): */   
    attrsNet.stacksize = 4 * 1024;  
    attrsNet.name = taskNameNet;
    attrsNet.priority = NET_TSK_PRIORITY;

    if (TSK_create((Fxn)StackTest, &attrsNet, NULL, NULL) == NULL) 
    {
        SYS_abort("main: failed to create udp net thread.");
    }	

	CFG_PINMUX1 |= (1<<8);
	GPIO_DIR45 = 0x0;

    open_global_int();
	open_int4();

  /* Setup uart485 task, and start*/
    attrsUart485.stacksize = 16 * 1024;  
    attrsUart485.name = taskNameUart485;
    attrsUart485.priority = UART485_TSK_PRIORITY;

    if (TSK_create((Fxn)Uart485_Test, &attrsUart485, NULL, NULL) == NULL) {
        SYS_abort("main: failed to create uart485 thread.");
    }

	open_int6();
	/*set up for rs232 */
	CFG_PINMUX1|=(1<<21); 

	/* Open Uart Handle */
	uart1 = SEEDDEC6437_UART_open(1,
								  baud_9k6,
								  data_w8,
								  data_s1,
								  data_p);
	UART1_IER = 1;	


#endif


    return (0);
}
extern short h1[64];
extern short h2[64];
extern short h_used[64];
void setfilterparm(char para)
{
	if(para==0)
		memcpy(h_used,h1,64*2);
	else
		memcpy(h_used,h2,64*2);
}
int   cnt=0;
Uint8 cmd[2];
void Uart232_isr()
{
	Int16 i, tmp;	
	Uint8 rx[256];

	while(1)
	{
		tmp = EVMDM6437_UART_rcvReady( uart1 );
		if(tmp == 1)
			break;
	}
	EVMDM6437_UART_getChar(uart1, &rx[0] );

	cmd[cnt++]=rx[0];
	if(cnt==2)
	{
		switch(cmd[0])
		{
		case 0:
			setfilterparm(cmd[1]);
			break;
		case 1:			
		//setfilterparm(rx[1]);
			break;	
		default:
			break;
		}	
		cnt=0;
	}

	while(1)
	{
		tmp = EVMDM6437_UART_xmtReady( uart1 );
		if(tmp == 1)
			break;
	}

 	EVMDM6437_UART_putChar( uart1, rx[0] );
}