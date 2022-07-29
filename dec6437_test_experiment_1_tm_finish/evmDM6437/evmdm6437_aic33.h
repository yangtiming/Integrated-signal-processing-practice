/*
 *  Copyright 2006 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  AIC33 header file
 *
 */

#ifndef AIC33_
#define AIC33_

#include "evmdm6437_i2c.h"
#include "evmdm6437_i2c_gpio.h"
#include "evmdm6437_mcasp.h"

#define MCBSP_INTERFACE         0x1000
#define MCASP_INTERFACE         0x2000

/* ------------------------------------------------------------------------ *
 *  AIC33 Definitions                                                       *
 * ------------------------------------------------------------------------ */
/*
#define AIC33_I2C_ADDR          0x18    // I2C address
#define AIC33_I2C_ADDR          0x19    // I2C address
#define AIC33_I2C_ADDR          0x1A    // I2C address */
#define AIC33_I2C_ADDR          0x1B    // I2C address

#define AIC33_18_MCBSP          ( 0x18 | 0 | MCBSP_INTERFACE )
#define AIC33_19_MCBSP          ( 0x18 | 1 | MCBSP_INTERFACE )
#define AIC33_1A_MCBSP          ( 0x18 | 2 | MCBSP_INTERFACE )
#define AIC33_1B_MCBSP          ( 0x18 | 3 | MCBSP_INTERFACE )
#define AIC33_MCBSP_ID          AIC33_1B_MCBSP

#define AIC33_18_MCASP          ( 0x18 | 0 | MCASP_INTERFACE )
#define AIC33_19_MCASP          ( 0x18 | 1 | MCASP_INTERFACE )
#define AIC33_1A_MCASP          ( 0x18 | 2 | MCASP_INTERFACE )
#define AIC33_1B_MCASP          ( 0x18 | 3 | MCASP_INTERFACE )
#define AIC33_MCASP_ID          AIC33_1B_MCASP

#define AIC33_NUMREGS           102     // Register
#define AIC33_PAGESELECT        0
#define AIC33_RESET             1

#define READONLY                0xAA00
#define RESERVED                0xFFFF

/* ------------------------------------------------------------------------ *
 *  AIC33 Data Structures                                                   *
 * ------------------------------------------------------------------------ */
typedef Int16 AIC33_CodecHandle;        // Codec Handle

typedef struct {                        // Register structure
    Uint16 regs[AIC33_NUMREGS];
} AIC33_Config;

/* ------------------------------------------------------------------------ *
 *  Prototypes                                                              *
 * ------------------------------------------------------------------------ */
/* Open/Close codec */
AIC33_CodecHandle
      EVMDM6437_AIC33_openCodec ( Uint32 id, AIC33_Config *Config );
Int16 EVMDM6437_AIC33_closeCodec( AIC33_CodecHandle aic33handle );

/* Get/Set registers */
Int16 EVMDM6437_AIC33_rget     ( AIC33_CodecHandle aic33handle, Uint16 regnum, Uint16* regval );
Int16 EVMDM6437_AIC33_rset     ( AIC33_CodecHandle aic33handle, Uint16 regnum, Uint16 regval );
Int16 EVMDM6437_AIC33_rset_mask( AIC33_CodecHandle aic33handle, Uint16 regnum, Uint16 regval, Uint8 mask );
Int16 EVMDM6437_AIC33_config   ( AIC33_CodecHandle aic33handle, AIC33_Config *Config );

/* Read/Write 16-bit or 32-bit data */
Int16 EVMDM6437_AIC33_read16   ( AIC33_CodecHandle aic33handle, Int16 *val );
Int16 EVMDM6437_AIC33_read32   ( AIC33_CodecHandle aic33handle, Int32 *val );
Int16 EVMDM6437_AIC33_write16  ( AIC33_CodecHandle aic33handle, Int16 val );
Int16 EVMDM6437_AIC33_write32  ( AIC33_CodecHandle aic33handle, Int32 val );

#endif
