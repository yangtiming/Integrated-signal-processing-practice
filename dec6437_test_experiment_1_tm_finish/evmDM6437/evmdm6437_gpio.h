/*
 *  Copyright 2006 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  GPIO header file
 *
 */

#ifndef GPIO_
#define GPIO_

#include "evmdm6437.h"

#define GPIO_IN                 1
#define GPIO_OUT                0

#define GPIO00                  0x00
#define GPIO01                  0x01
#define GPIO02                  0x02
#define GPIO03                  0x03
#define GPIO04                  0x04
#define GPIO05                  0x05
#define GPIO06                  0x06
#define GPIO07                  0x07
#define GPIO08                  0x08
#define GPIO09                  0x09

#define GPIO10                  0x0A
#define GPIO11                  0x0B
#define GPIO12                  0x0C
#define GPIO13                  0x0D
#define GPIO14                  0x0E
#define GPIO15                  0x0F
#define GPIO16                  0x10
#define GPIO17                  0x11
#define GPIO18                  0x12
#define GPIO19                  0x13

#define GPIO20                  0x14
#define GPIO21                  0x15
#define GPIO22                  0x16
#define GPIO23                  0x17
#define GPIO24                  0x18
#define GPIO25                  0x19
#define GPIO26                  0x1A
#define GPIO27                  0x1B
#define GPIO28                  0x1C
#define GPIO29                  0x1D

#define GPIO30                  0x1E
#define GPIO31                  0x1F
#define GPIO32                  0x20
#define GPIO33                  0x21
#define GPIO34                  0x22
#define GPIO35                  0x23
#define GPIO36                  0x24
#define GPIO37                  0x25
#define GPIO38                  0x26
#define GPIO39                  0x27

#define GPIO40                  0x28
#define GPIO41                  0x29
#define GPIO42                  0x2A
#define GPIO43                  0x2B
#define GPIO44                  0x2C
#define GPIO45                  0x2D
#define GPIO46                  0x2E
#define GPIO47                  0x2F
#define GPIO48                  0x30
#define GPIO49                  0x31

#define GPIO50                  0x32
#define GPIO51                  0x33
#define GPIO52                  0x34
#define GPIO53                  0x35
#define GPIO54                  0x36
#define GPIO55                  0x37
#define GPIO56                  0x38
#define GPIO57                  0x39
#define GPIO58                  0x3A
#define GPIO59                  0x3B

#define GPIO60                  0x3C
#define GPIO61                  0x3D
#define GPIO62                  0x3E
#define GPIO63                  0x3F
#define GPIO64                  0x40
#define GPIO65                  0x41
#define GPIO66                  0x42
#define GPIO67                  0x43
#define GPIO68                  0x44
#define GPIO69                  0x45

#define GPIO70                  0x46
#define GPIO71                  0x47
#define GPIO72                  0x48
#define GPIO73                  0x49
#define GPIO74                  0x4A
#define GPIO75                  0x4B
#define GPIO76                  0x4C
#define GPIO77                  0x4D
#define GPIO78                  0x4E
#define GPIO79                  0x4F

#define GPIO80                  0x50
#define GPIO81                  0x51
#define GPIO82                  0x52
#define GPIO83                  0x53
#define GPIO84                  0x54
#define GPIO85                  0x55
#define GPIO86                  0x56
#define GPIO87                  0x57
#define GPIO88                  0x58
#define GPIO89                  0x59

#define GPIO90                  0x5A
#define GPIO91                  0x5B
#define GPIO92                  0x5C
#define GPIO93                  0x5D
#define GPIO94                  0x5E
#define GPIO95                  0x5F
#define GPIO96                  0x60
#define GPIO97                  0x61
#define GPIO98                  0x62
#define GPIO99                  0x63

#define GPIO100                 0x64
#define GPIO101                 0x65
#define GPIO102                 0x66
#define GPIO103                 0x67
#define GPIO104                 0x68
#define GPIO105                 0x69
#define GPIO106                 0x6A
#define GPIO107                 0x6B
#define GPIO108                 0x6C
#define GPIO109                 0x6D

#define GPIO110                 0x6E


typedef struct {
    volatile Uint32 DIR;
    volatile Uint32 OUT_DATA;
    volatile Uint32 SET_DATA;
    volatile Uint32 CLR_DATA;
    volatile Uint32 IN_DATA;
    volatile Uint32 SET_RIS_TRIG;
    volatile Uint32 CLR_RIS_TRIG;
    volatile Uint32 SET_FAL_TRIG;
    volatile Uint32 CLR_FAL_TRIG;
    volatile Uint32 INTSTAT;
} GPIO_REGS;

typedef struct {
    GPIO_REGS* regs;
} GPIO_OBJ;

static GPIO_OBJ GPIO_MODULE_01 = { ( GPIO_REGS* )GPIO_01_BASE };
static GPIO_OBJ GPIO_MODULE_23 = { ( GPIO_REGS* )GPIO_23_BASE };
static GPIO_OBJ GPIO_MODULE_45 = { ( GPIO_REGS* )GPIO_45_BASE };
static GPIO_OBJ GPIO_MODULE_6  = { ( GPIO_REGS* )GPIO_6_BASE };

typedef GPIO_OBJ* GPIO_Handle;

/* ------------------------------------------------------------------------ *
 *  Prototypes                                                              *
 * ------------------------------------------------------------------------ */
Int16 EVMDM6437_GPIO_init       ( );
Int16 EVMDM6437_GPIO_setDir     ( Uint16 number, Uint8 direction );
Int16 EVMDM6437_GPIO_setOutput  ( Uint16 number, Uint8 output );
Int16 EVMDM6437_GPIO_getInput   ( Uint16 number );

#endif
