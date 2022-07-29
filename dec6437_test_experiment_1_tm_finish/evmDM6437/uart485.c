
#include <std.h>
#include <tsk.h>
#include "evmdm6437_uart.h"


static Int16 i, tmp;
static UART_Handle uart0;
static Uint8 rx[60];
static Uint8 Scount =0;
static Uint8 Rcount =0;
void Uart485_Test()
{

	for(i=0;i<60;i++)
	{
		rx[i] = 0;
	}
 	/* Open Uart Handle */
	uart0 = SEEDDEC6437_UART_open(0,
								  baud_9k6,
								  data_w8,
								  data_s1,
								  data_p);
	UART0_IER = 1;

	// input	
    GPIO_OUT_DATA45 = 0x0;	
	while(1)
	{
		if(Rcount>=32)
		{
			// output
			GPIO_OUT_DATA45 = 0x800000;
			for(i=0;i<32;i++)
			{
				while(1)
				{
					tmp = EVMDM6437_UART_xmtReady( uart0 );
					if(tmp == 1)
						break;
				}
				EVMDM6437_UART_putChar( uart0, rx[Scount]);
				Scount++;
				if(Scount ==32)
				{
					Scount = 0;
					Rcount = 0;
				}
			}
			TSK_sleep(100);//延迟等待输出完成，才能换向
			// input
			GPIO_OUT_DATA45 = 0x0;
		}
		TSK_sleep(100);
	}
}


void Uart485_isr()
{	
 	// input
	GPIO_OUT_DATA45 = 0x0;
 	while(1)
	{
		tmp = EVMDM6437_UART_rcvReady(uart0 );
		if(tmp == 1)
			break;
	}
		
	EVMDM6437_UART_getChar( uart0, &rx[Rcount]);
	Rcount++;
}


