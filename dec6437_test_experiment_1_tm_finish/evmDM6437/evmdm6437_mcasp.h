/*
 *  Copyright 2006 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  MCASP header file
 *
 */

#ifndef MCASP_
#define MCASP_

#include "evmdm6437.h"

/* ------------------------------------------------------------------------ *
 *  MCASP modules                                                           *
 * ------------------------------------------------------------------------ */
#define MCASP_0         0

#define SERIALIZER_0    0
#define SERIALIZER_1    1
#define SERIALIZER_2    2
#define SERIALIZER_3    3
#define SERIALIZER_4    4
#define SERIALIZER_5    5
#define SERIALIZER_6    6
#define SERIALIZER_7    7
#define SERIALIZER_8    8

/* ------------------------------------------------------------------------ *
 *  MCASP interface                                                         *
 * ------------------------------------------------------------------------ */
typedef struct {
    volatile Uint32 PID;
    volatile Uint32 PWRDEMU;
             Uint32 rsvd_08_0c[2];
    volatile Uint32 PFUNC;
    volatile Uint32 PDIR;
    volatile Uint32 PDOUT;
    volatile Uint32 PDIN;
    volatile Uint32 PDCLR;
             Uint32 rsvd_24_40[8];
    volatile Uint32 GBLCTL;
    volatile Uint32 AMUTE;
    volatile Uint32 DLBCTL;
    volatile Uint32 DITCTL;
             Uint32 rsvd_54_5c[3];
    volatile Uint32 RGBLCTL;
    volatile Uint32 RMASK;
    volatile Uint32 RFMT;
    volatile Uint32 AFSRCTL;
    volatile Uint32 ACLKRCTL;
    volatile Uint32 AHCLKRCTL;
    volatile Uint32 RTDM;
    volatile Uint32 RINTCTL;
    volatile Uint32 RSTAT;
    volatile Uint32 RSLOT;
    volatile Uint32 RCLKCHK;
    volatile Uint32 REVTCTL;
             Uint32 rsvd_90_9c[4];
    volatile Uint32 XGBLCTL;
    volatile Uint32 XMASK;
    volatile Uint32 XFMT;
    volatile Uint32 AFSXCTL;
    volatile Uint32 ACLKXCTL;
    volatile Uint32 AHCLKXCTL;
    volatile Uint32 XTDM;
    volatile Uint32 XINTCTL;
    volatile Uint32 XSTAT;
    volatile Uint32 XSLOT;
    volatile Uint32 XCLKCHK;
    volatile Uint32 XEVTCTL;
             Uint32 rsvd_d0_fc[12];
    volatile Uint32 DITCSRA0;
    volatile Uint32 DITCSRA1;
    volatile Uint32 DITCSRA2;
    volatile Uint32 DITCSRA3;
    volatile Uint32 DITCSRA4;
    volatile Uint32 DITCSRA5;
    volatile Uint32 DITCSRB0;
    volatile Uint32 DITCSRB1;
    volatile Uint32 DITCSRB2;
    volatile Uint32 DITCSRB3;
    volatile Uint32 DITCSRB4;
    volatile Uint32 DITCSRB5;
    volatile Uint32 DITUDRA0;
    volatile Uint32 DITUDRA1;
    volatile Uint32 DITUDRA2;
    volatile Uint32 DITUDRA3;
    volatile Uint32 DITUDRA4;
    volatile Uint32 DITUDRA5;
    volatile Uint32 DITUDRB0;
    volatile Uint32 DITUDRB1;
    volatile Uint32 DITUDRB2;
    volatile Uint32 DITUDRB3;
    volatile Uint32 DITUDRB4;
    volatile Uint32 DITUDRB5;
             Uint32 rsvd_160_17c[8];
    volatile Uint32 SRCTL0;
    volatile Uint32 SRCTL1;
    volatile Uint32 SRCTL2;
    volatile Uint32 SRCTL3;
    volatile Uint32 SRCTL4;
    volatile Uint32 SRCTL5;
    volatile Uint32 SRCTL6;
    volatile Uint32 SRCTL7;
    volatile Uint32 SRCTL8;
    volatile Uint32 SRCTL9;
    volatile Uint32 SRCTL10;
    volatile Uint32 SRCTL11;
    volatile Uint32 SRCTL12;
    volatile Uint32 SRCTL13;
    volatile Uint32 SRCTL14;
    volatile Uint32 SRCTL15;
             Uint32 rsvd_1c0_1fc[16];
    volatile Uint32 XBUF0;
    volatile Uint32 XBUF1;
    volatile Uint32 XBUF2;
    volatile Uint32 XBUF3;
    volatile Uint32 XBUF4;
    volatile Uint32 XBUF5;
    volatile Uint32 XBUF6;
    volatile Uint32 XBUF7;
    volatile Uint32 XBUF8;
    volatile Uint32 XBUF9;
    volatile Uint32 XBUF10;
    volatile Uint32 XBUF11;
    volatile Uint32 XBUF12;
    volatile Uint32 XBUF13;
    volatile Uint32 XBUF14;
    volatile Uint32 XBUF15;
             Uint32 rsvd_240_27c[16];
    volatile Uint32 RBUF0;
    volatile Uint32 RBUF1;
    volatile Uint32 RBUF2;
    volatile Uint32 RBUF3;
    volatile Uint32 RBUF4;
    volatile Uint32 RBUF5;
    volatile Uint32 RBUF6;
    volatile Uint32 RBUF7;
    volatile Uint32 RBUF8;
    volatile Uint32 RBUF9;
    volatile Uint32 RBUF10;
    volatile Uint32 RBUF11;
    volatile Uint32 RBUF12;
    volatile Uint32 RBUF13;
    volatile Uint32 RBUF14;
    volatile Uint32 RBUF15;
} MCASP_REGS;

#define PDSET       PDIN    // PDSET & PDIN occupy the same memory location
#define SRCTL_BASE  SRCTL0
#define XBUF_BASE   XBUF0
#define RBUF_BASE   RBUF0

#define GBLCTL_XFRST_ON     0x1000
#define GBLCTL_XSMRST_ON    0x0800
#define GBLCTL_XSRCLR_ON    0x0400
#define GBLCTL_XHCLKRST_ON  0x0200
#define GBLCTL_XCLKRST_ON   0x0100
#define GBLCTL_RFRST_ON     0x0010
#define GBLCTL_RSMRST_ON    0x0008
#define GBLCTL_RSRCLR_ON    0x0004
#define GBLCTL_RHCLKRST_ON  0x0002
#define GBLCTL_RCLKRST_ON   0x0001

typedef struct {
    Uint16 id;
    MCASP_REGS* regs;
} MCASP_OBJ;

static MCASP_OBJ MCASP_MODULE_0 = { MCASP_0, ( MCASP_REGS* )MCASP0_BASE };

typedef MCASP_OBJ* MCASP_Handle;

/* ------------------------------------------------------------------------ *
 *  Prototypes                                                              *
 * ------------------------------------------------------------------------ */
Int16 EVMDM6437_MCASP_open   ( Uint16 id );
Int16 EVMDM6437_MCASP_close  ( Uint16 id );

#endif
