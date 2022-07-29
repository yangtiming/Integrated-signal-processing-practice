/*
 *  Copyright 2006 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  LED header file
 *
 */

#ifndef LED_
#define LED_

#include "evmdm6437_i2c_gpio.h"

/* I2C Address */
#define LED_I2C_ADDR            I2C_GPIO_GROUP_1

/* ------------------------------------------------------------------------ *
 *  Prototypes                                                              *
 * ------------------------------------------------------------------------ */
Int16 EVMDM6437_LED_init  ( );
Int16 EVMDM6437_LED_on    ( Uint16 num );
Int16 EVMDM6437_LED_off   ( Uint16 num );
Int16 EVMDM6437_LED_toggle( Uint16 num );

#endif
