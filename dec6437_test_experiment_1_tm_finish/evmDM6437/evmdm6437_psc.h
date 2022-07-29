/*
 *  Copyright 2006 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  PSC header file
 *
 */

#ifndef PSC_
#define PSC_

#include "evmdm6437.h"

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  PSC states                                                              *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define PSC_SWRSTDISABLE    0
#define PSC_SYNCRESET       1
#define PSC_DISABLE         2
#define PSC_ENABLE          3

/* ------------------------------------------------------------------------ *
 *  Prototypes                                                              *
 * ------------------------------------------------------------------------ */
Int16 EVMDM6437_PSC_enableAll   ( );
Int16 EVMDM6437_PSC_changeState ( Uint32 id, Uint16 state );

#endif
