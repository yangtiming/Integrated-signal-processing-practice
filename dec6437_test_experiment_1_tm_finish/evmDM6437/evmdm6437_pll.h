/*
 *  Copyright 2006 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  PLL header file
 *
 */

#ifndef PLL_
#define PLL_

#include "evmdm6437.h"

/* ------------------------------------------------------------------------ *
 *  Prototypes                                                              *
 * ------------------------------------------------------------------------ */
Int16 EVMDM6437_enablePll1( Uint16 clock_source, Uint16 pll_mult );
Int16 EVMDM6437_enablePll2( Uint16 clock_source, Uint16 pll_mult,
                            Uint16 vpss_div, Uint16 ddr2_div );

#endif
