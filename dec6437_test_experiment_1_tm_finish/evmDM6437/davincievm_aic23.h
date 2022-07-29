/*
 *  Copyright 2005 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 *
 *  Not for distribution.
 */

/*
 *  AIC33 header file
 *
 */

#ifndef AIC33_
#define AIC33_

#ifdef __cplusplus
extern "C" {
#endif

#include "evmdm6437_i2c.h"

#ifdef ARM_SIDE

    #include "csl_mcbsp.h"

    extern CSL_McbspHandle mcbsp_handle;
    extern CSL_McbspObj    mcbsp_obj;

#elif DSP_SIDE

#endif

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  AIC33 Definitions                                                       *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define AIC33_I2C_ADDR          0x18    // I2C address

#define AIC33_NUMREGS           102     // Register
#define AIC33_PAGESELECT        0
#define AIC33_RESET             1

#define MicIn					1
#define StereoIn				2
/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  AIC33 Data Structures                                                   *
 *                                                                          *
 * ------------------------------------------------------------------------ */
typedef Int16 AIC33_CodecHandle;        // Codec Handle

typedef struct {                        // Register structure
    Uint16 regs[AIC33_NUMREGS];
} AIC33_Config;

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  AIC33 Prototypes                                                        *
 *                                                                          *
 * ------------------------------------------------------------------------ */
/* Open/Close codec */
AIC33_CodecHandle 
      DAVINCIEVM_AIC33_openCodec ( Uint32 id);
Int16 DAVINCIEVM_AIC33_closeCodec( AIC33_CodecHandle aic33handle );

/* Get/Set registers */
Int16 DAVINCIEVM_AIC33_rget     ( AIC33_CodecHandle aic33handle, Uint16 regnum, Uint16* regval );
Int16 DAVINCIEVM_AIC33_rset     ( AIC33_CodecHandle aic33handle, Uint16 regnum, Uint16 regval );
Int16 DAVINCIEVM_AIC33_rset_mask( AIC33_CodecHandle aic33handle, Uint16 regnum, Uint16 regval, Uint8 mask );
Int16 DAVINCIEVM_AIC33_config   ( AIC33_CodecHandle aic33handle, AIC33_Config *Config );

/* Read/Write 16-bit or 32-bit data */
Int16 DAVINCIEVM_AIC33_read16   ( AIC33_CodecHandle aic33handle, Int16 *val );
Int16 DAVINCIEVM_AIC33_write16  ( AIC33_CodecHandle aic33handle, Int16 val );

/* Special functions */
void DAVINCIEVM_AIC33_mute      ( AIC33_CodecHandle aic33handle, Uint16 mode );

#ifdef __cplusplus
}
#endif

#endif
