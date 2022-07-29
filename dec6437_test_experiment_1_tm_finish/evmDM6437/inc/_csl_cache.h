/*  ============================================================================
 *   Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005
 *
 *   Use of this software is controlled by the terms and conditions found in the
 *   license agreement under which this software has been supplied.
 *   ===========================================================================
 */

/** \file _csl_cache.h
 *
 *  \brief This file defines the functions in the Cache driver.
 *
 *  Date 22th March 2004
 *  Author Jamon Bowen
 *
 *  Description
 *  - The functions in this driver contian all of the necessary
 *       functionallity the configure the (if avalible) L2, L1D, and L1P Cache.
 *  Last Modified: 22th March 2004
 *
 *  Modifications 1:
 *  - Jamon Bowen
 *  - Created
 *  - Date: 23th March 2004
 *
 */

#ifndef __CSL_CACHE_H_
#define __CSL_CACHE_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    CACHE_WAIT_NONE       = 0,
    CACHE_WAIT_L1DINVALL  = 1,
    CACHE_WAIT_L1DINV     = 2,
    CACHE_WAIT_L1DWBALL   = 3,
    CACHE_WAIT_L1DWB      = 4,
    CACHE_WAIT_L1DWBINVALL= 5,
    CACHE_WAIT_L1DWBINV   = 6,
    CACHE_WAIT_L1PINVALL  = 7,
    CACHE_WAIT_L1PINV     = 8,
    CACHE_WAIT_L2INVALL   = 9,
    CACHE_WAIT_L2INV      = 10,
    CACHE_WAIT_L2WBALL    = 11,
    CACHE_WAIT_L2WB       = 12,
    CACHE_WAIT_L2WBINVALL = 13,
    CACHE_WAIT_L2WBINV    = 14
} CACHE_waitState;

extern volatile CACHE_waitState _CSL_cachebusyState;

typedef enum {
    CACHE_EMIF_NONE = 0,
    CACHE_EMIF_A    = 1,
    CACHE_EMIF_B    = 2,
    CACHE_EMIF_AB   = 3
}CACHE_emifState;

extern volatile CACHE_emifState _CSL_cacheEmifState;

#define CSL_CACHE_EMIF_ISRANGE(addr) \
                    ((CSL_CACHE_EMIF_MASK  >> ((addr >> 27) & 0x1f)) & 0x1)
#define CSL_CACHE_EMIF_ISEMIFBRANGE(addr) \
                    ((CSL_CACHE_EMIFB_MASK >> ((addr >> 27) & 0x1f)) & 0x1)
void _CSL_cacheApplyPatch();
void _CACHE_wait(CACHE_Wait);

#define CSL_CACHE_EMIF_MASK  0x00030000
#define CSL_CACHE_EMIFB_MASK 0

/* DDR EMIF Control registers */
#define CSL_CACHE_EMIFA_REG     *(volatile unsigned int*) 0x20000000
#define CSL_CACHE_EMIFA_PATCH() { CSL_CACHE_EMIFA_REG = 0; \
                                  CSL_CACHE_EMIFA_REG; }
#define CSL_CACHE_EMIFB_PATCH() {}

#ifdef __cplusplus
}
#endif
#endif /*__CSL_CACHE_H_ */

