/*
 *  Copyright 2006 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  UART Header file
 *
 */

#ifndef UART_
#define UART_

#include "evmdm6437.h"

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  UART regs                                                               *
 *                                                                          *
 * ------------------------------------------------------------------------ */
typedef struct {
    volatile Uint32 RBR;
    volatile Uint32 IER;
    volatile Uint32 IIR;
    volatile Uint32 LCR;
    volatile Uint32 MCR;
    volatile Uint32 LSR;
    Uint32 rsvd_18;
    Uint32 rsvd_1c;
    volatile Uint32 DLL;
    volatile Uint32 DLH;
    volatile Uint32 PID1;
    volatile Uint32 PID2;
    volatile Uint32 PWREMU_MGMT;
} UART_REGS;

#define THR     RBR    // THR & RBR occupy the same memory location
#define FCR     IIR    // FCR & IIR occupy the same memory location

/*Set UART parameters */
/*Set Baud rate */
#define baud_2k4	703
#define baud_4k8	352
#define baud_9k6	176
#define baud_19k2	88
#define baud_38k4	44
#define baud_56k	30
#define baud_115k2	15
#define baud_128k	13
/*word length Set*/
#define data_w5     0x00 /*length=5*/
#define data_w6     0x01 /*length=6*/
#define data_w7     0x02 /*length=7*/
#define data_w8     0x03 /*length=8*/

#define data_s1     0x00 /*1 stop bit*/
#define data_s2     0x04 /*1.5 or 2 stop bit*/

#define data_p      0x0000 /*no parity*/
#define data_po     0x0008 /*odd parity*/
#define data_pe     0x0018 /*even parity*/

typedef struct {
    UART_REGS* regs;
} UART_OBJ;

static UART_OBJ UART_MODULE_0 = { ( UART_REGS* )UART0_BASE };
static UART_OBJ UART_MODULE_1 = { ( UART_REGS* )UART1_BASE };

typedef UART_OBJ* UART_Handle;

/* ------------------------------------------------------------------------ *
 *  Prototypes                                                              *
 * ------------------------------------------------------------------------ */
UART_Handle SEEDDEC6437_UART_open(Uint16 UartId,
								  Uint16 UartBaud,
								  Uint8 UartWordLen,
								  Uint8 UartStopBits,
								  Uint8 UartParity);

Int16 EVMDM6437_UART_close( UART_Handle UartHandle );

Int16 EVMDM6437_UART_xmtReady( UART_Handle UartHandle );
Int16 EVMDM6437_UART_rcvReady( UART_Handle UartHandle );

Int16 EVMDM6437_UART_putChar( UART_Handle UartHandle, Uint8 data );
Int16 EVMDM6437_UART_getChar( UART_Handle UartHandle, Uint8* data );

#endif
