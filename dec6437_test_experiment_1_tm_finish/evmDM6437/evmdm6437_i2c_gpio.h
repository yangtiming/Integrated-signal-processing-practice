/*
 *  Copyright 2006 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  I2C GPIO I/O expander header file
 *
 */

#ifndef I2C_GPIO_
#define I2C_GPIO_

#include "evmdm6437_i2c.h"

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  I2C Addresses                                                           *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define I2C_GPIO_GROUP_0        ( 0x38 | 0 )
#define I2C_GPIO_GROUP_1        ( 0x38 | 1 )
#define I2C_GPIO_GROUP_2        ( 0x38 | 2 )
#define I2C_GPIO_GROUP_3        ( 0x38 | 3 )
#define I2C_GPIO_GROUP_4        ( 0x38 | 4 )
#define I2C_GPIO_GROUP_5        ( 0x38 | 5 )
#define I2C_GPIO_GROUP_6        ( 0x38 | 6 )
#define I2C_GPIO_GROUP_7        ( 0x38 | 7 )

/*
 *  I2C GPIO timeouts
 */
#define I2C_GPIO_MAX_TIMEOUT    ( 0x7FFFFFFF )
#define I2C_GPIO_WAIT_FOREVER   ( -1 )

/* ------------------------------------------------------------------------ *
 *  Prototypes                                                              *
 * ------------------------------------------------------------------------ */
Int16 EVMDM6437_I2C_GPIO_init       ( );
Int16 EVMDM6437_I2C_GPIO_setOutput  ( Uint16 id, Uint16 number, Uint8 output );
Int16 EVMDM6437_I2C_GPIO_getInput   ( Uint16 id, Uint16 number );

Int16 EVMDM6437_I2C_GPIO_getall     ( Uint16 id, Uint16* input );
Int16 EVMDM6437_I2C_GPIO_setall     ( Uint16 id, Uint16 output );

Int16 EVMDM6437_I2C_GPIO_setupIntr  ( );
Int16 EVMDM6437_I2C_GPIO_checkIntr  ( );
Int16 EVMDM6437_I2C_GPIO_waitForIntr( Int32 timeout );

#endif
