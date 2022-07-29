/* ============================================================================
 * Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005
 *
 * Use of this software is controlled by the terms and conditions found in the
 * license agreement under which this software has been supplied.
 * ============================================================================
 */

#ifndef _CSLR_PWRDWNL2_H_
#define _CSLR_PWRDWNL2_H_

 /** @file cslr_pwrdwnL2.h
 * 
 * @brief This file contains the Register Desciptions for L2PWRDWN
 * 
 *********************************************************************/

#include <cslr.h>

#include <tistdtypes.h>

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 L2PDAEN[2];
    volatile Uint8 RSVD0[8];
    volatile Uint32 L2PDAPS[2];
    volatile Uint8 RSVD1[8];
    volatile Uint32 L2PDAP;
    volatile Uint8 RSVD2[28];
    volatile Uint32 L2PDWAKE[2];
    volatile Uint8 RSVD3[8];
    volatile Uint32 L2PDSLEEP[2];
    volatile Uint8 RSVD4[8];
    volatile Uint32 L2PDSTAT[2];
} CSL_L2pwrdwnRegs;
typedef volatile CSL_L2pwrdwnRegs *CSL_L2pwrdwnRegsOvly;
/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* L2PDAEN */

#define CSL_L2PWRDWN_L2PDAEN_PAGEEN_MASK (0xFFFFFFFFu)
#define CSL_L2PWRDWN_L2PDAEN_PAGEEN_SHIFT (0x00000000u)
#define CSL_L2PWRDWN_L2PDAEN_PAGEEN_RESETVAL (0x00000000u)

#define CSL_L2PWRDWN_L2PDAEN_RESETVAL    (0x00000000u)

/* L2PDAPS */

#define CSL_L2PWRDWN_L2PDAPS_PAGEPS_MASK (0xFFFFFFFFu)
#define CSL_L2PWRDWN_L2PDAPS_PAGEPS_SHIFT (0x00000000u)
#define CSL_L2PWRDWN_L2PDAPS_PAGEPS_RESETVAL (0x00000000u)

#define CSL_L2PWRDWN_L2PDAPS_RESETVAL    (0x00000000u)

/* L2PDAP */

#define CSL_L2PWRDWN_L2PDAP_RESERVED_MASK (0xFFFFF000u)
#define CSL_L2PWRDWN_L2PDAP_RESERVED_SHIFT (0x0000000Cu)
#define CSL_L2PWRDWN_L2PDAP_RESERVED_RESETVAL (0x00000000u)

#define CSL_L2PWRDWN_L2PDAP_PERB_MASK    (0x00000F00u)
#define CSL_L2PWRDWN_L2PDAP_PERB_SHIFT   (0x00000008u)
#define CSL_L2PWRDWN_L2PDAP_PERB_RESETVAL (0x00000000u)

/*----PERB Tokens----*/
#define CSL_L2PWRDWN_L2PDAP_PERB_8CLKS   (0x00000000u)
#define CSL_L2PWRDWN_L2PDAP_PERB_16CLKS  (0x00000001u)
#define CSL_L2PWRDWN_L2PDAP_PERB_32CLKS  (0x00000002u)
#define CSL_L2PWRDWN_L2PDAP_PERB_64CLKS  (0x00000003u)
#define CSL_L2PWRDWN_L2PDAP_PERB_128CLKS (0x00000004u)
#define CSL_L2PWRDWN_L2PDAP_PERB_256CLKS (0x00000005u)
#define CSL_L2PWRDWN_L2PDAP_PERB_512CLKS (0x00000006u)
#define CSL_L2PWRDWN_L2PDAP_PERB_1KCLKS  (0x00000007u)
#define CSL_L2PWRDWN_L2PDAP_PERB_2KCLKS  (0x00000008u)
#define CSL_L2PWRDWN_L2PDAP_PERB_4KCLKS  (0x00000009u)
#define CSL_L2PWRDWN_L2PDAP_PERB_8KCLKS  (0x0000000Au)
#define CSL_L2PWRDWN_L2PDAP_PERB_16KCLKS (0x00000009u)
#define CSL_L2PWRDWN_L2PDAP_PERB_32KCLKS (0x0000000Au)

#define CSL_L2PWRDWN_L2PDAP_PERA_MASK    (0x0000000Fu)
#define CSL_L2PWRDWN_L2PDAP_PERA_SHIFT   (0x00000000u)
#define CSL_L2PWRDWN_L2PDAP_PERA_RESETVAL (0x00000000u)

/*----PERA Tokens----*/
#define CSL_L2PWRDWN_L2PDAP_PERA_8CLKS   (0x00000000u)
#define CSL_L2PWRDWN_L2PDAP_PERA_16CLKS  (0x00000001u)
#define CSL_L2PWRDWN_L2PDAP_PERA_32CLKS  (0x00000002u)
#define CSL_L2PWRDWN_L2PDAP_PERA_64CLKS  (0x00000003u)
#define CSL_L2PWRDWN_L2PDAP_PERA_128CLKS (0x00000004u)
#define CSL_L2PWRDWN_L2PDAP_PERA_256CLKS (0x00000005u)
#define CSL_L2PWRDWN_L2PDAP_PERA_512CLKS (0x00000006u)
#define CSL_L2PWRDWN_L2PDAP_PERA_1KCLKS  (0x00000007u)
#define CSL_L2PWRDWN_L2PDAP_PERA_2KCLKS  (0x00000008u)
#define CSL_L2PWRDWN_L2PDAP_PERA_4KCLKS  (0x00000009u)
#define CSL_L2PWRDWN_L2PDAP_PERA_8KCLKS  (0x0000000Au)
#define CSL_L2PWRDWN_L2PDAP_PERA_16KCLKS (0x00000009u)
#define CSL_L2PWRDWN_L2PDAP_PERA_32KCLKS (0x0000000Au)

#define CSL_L2PWRDWN_L2PDAP_RESETVAL     (0x00000000u)

/* L2PDWAKE */

#define CSL_L2PWRDWN_L2PDWAKE_PAGEWCMD_MASK (0xFFFFFFFFu)
#define CSL_L2PWRDWN_L2PDWAKE_PAGEWCMD_SHIFT (0x00000000u)
#define CSL_L2PWRDWN_L2PDWAKE_PAGEWCMD_RESETVAL (0x00000000u)

#define CSL_L2PWRDWN_L2PDWAKE_RESETVAL   (0x00000000u)

/* L2PDSLEEP */

#define CSL_L2PWRDWN_L2PDSLEEP_PAGESCMD_MASK (0xFFFFFFFFu)
#define CSL_L2PWRDWN_L2PDSLEEP_PAGESCMD_SHIFT (0x00000000u)
#define CSL_L2PWRDWN_L2PDSLEEP_PAGESCMD_RESETVAL (0x00000000u)

#define CSL_L2PWRDWN_L2PDSLEEP_RESETVAL  (0x00000000u)

/* L2PDSTAT */

#define CSL_L2PWRDWN_L2PDSTAT_PAGESTAT_MASK (0xFFFFFFFFu)
#define CSL_L2PWRDWN_L2PDSTAT_PAGESTAT_SHIFT (0x00000000u)
#define CSL_L2PWRDWN_L2PDSTAT_PAGESTAT_RESETVAL (0x00000000u)

#define CSL_L2PWRDWN_L2PDSTAT_RESETVAL   (0x00000000u)

#endif
