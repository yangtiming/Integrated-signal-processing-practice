/*
 *  Copyright 2006 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  DIP Switch header file
 *
 */

#ifndef DIP_
#define DIP_

#include "evmdm6437_i2c_gpio.h"

/* ------------------------------------------------------------------------ *
 *  Definitions                                                             *
 * ------------------------------------------------------------------------ */
#define JP1_JUMPER         -4
#define SW7_SWITCH         -3
#define DIP_0               0
#define DIP_1               1
#define DIP_2               2
#define DIP_3               3

/*
 *  Switch Settings
 */
#define DIP_DOWN            0       // DIP switch is DOWN
#define DIP_UP              1       // DIP switch is UP

#define JP1_JUMPER_PAL      0       // JP1 set to PAL
#define JP1_JUMPER_NTSC     1       // JP1 set to NTSC

#define SW7_SWITCH_LEFT     0       // SW7 set to LEFT
#define SW7_SWITCH_RIGHT    1       // SW7 set to RIGHT

/* ------------------------------------------------------------------------ *
 *  Prototypes                                                              *
 * ------------------------------------------------------------------------ */
Int16 EVMDM6437_DIP_init( );
Int16 EVMDM6437_DIP_get( Int32 dip_num );

#define EVMDM6437_DIP_wait  EVMDM6437_I2C_GPIO_waitForIntr

#endif
