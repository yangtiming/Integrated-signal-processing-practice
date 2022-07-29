/*
 *  Copyright 2006 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  EEPROM Header file [16 Kbytes - 24WC256]
 *
 */

#ifndef EEPROM_
#define EEPROM_

#include "evmdm6437_i2c.h"

/* I2C Address */
#define EEPROM_I2C_ADDR             0x50

/* EEPROM specific settings */
#define EEPROM_PAGE_SIZE            64
#define EEPROM_PAGE_SIZE_POW2       6
#define EEPROM_MAX_BURST_LEN        EEPROM_PAGE_SIZE

/* ------------------------------------------------------------------------ *
 *  Prototypes                                                              *
 * ------------------------------------------------------------------------ */
Int16 EVMDM6437_EEPROM_init ( );
Int16 EVMDM6437_EEPROM_read ( Uint32 src, Uint32 dst, Uint32 length );
Int16 EVMDM6437_EEPROM_write( Uint32 src, Uint32 dst, Uint32 length );

#endif
