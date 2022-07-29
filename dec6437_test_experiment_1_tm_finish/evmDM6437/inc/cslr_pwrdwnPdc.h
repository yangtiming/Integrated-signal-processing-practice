/* ============================================================================
 * Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005
 *
 * Use of this software is controlled by the terms and conditions found in the
 * license agreement under which this software has been supplied.
 * ============================================================================
 */
 
#ifndef _CSLR_PWRDWNPDC_H_
#define _CSLR_PWRDWNPDC_H_

 /** @file cslr_pwrdwnPdc.h
 * 
 * @brief This file contains the Register Desciptions for PDC
 * 
 *********************************************************************/

#include <cslr.h>

#include <tistdtypes.h>

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 PDCCMD;
} CSL_PdcRegs;
typedef volatile CSL_PdcRegs *CSL_PdcRegsOvly;
/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* PDCCMD */

#define CSL_PDC_PDCCMD_RESERVED_MASK     (0xFFFE0000u)
#define CSL_PDC_PDCCMD_RESERVED_SHIFT    (0x00000011u)
#define CSL_PDC_PDCCMD_RESERVED_RESETVAL (0x00000000u)

#define CSL_PDC_PDCCMD_GEMPD_MASK        (0x00010000u)
#define CSL_PDC_PDCCMD_GEMPD_SHIFT       (0x00000010u)
#define CSL_PDC_PDCCMD_GEMPD_RESETVAL    (0x00000000u)

/*----GEMPD Tokens----*/
#define CSL_PDC_PDCCMD_GEMPD_NORMAL      (0x00000000u)
#define CSL_PDC_PDCCMD_GEMPD_SLEEP       (0x00000001u)

#define CSL_PDC_PDCCMD_EMCMEM_MASK       (0x0000C000u)
#define CSL_PDC_PDCCMD_EMCMEM_SHIFT      (0x0000000Eu)
#define CSL_PDC_PDCCMD_EMCMEM_RESETVAL   (0x00000000u)

/*----EMCMEM Tokens----*/
#define CSL_PDC_PDCCMD_EMCMEM_NONE       (0x00000000u)
#define CSL_PDC_PDCCMD_EMCMEM_MODE1      (0x00000001u)
#define CSL_PDC_PDCCMD_EMCMEM_MODE2      (0x00000002u)
#define CSL_PDC_PDCCMD_EMCMEM_MODE3      (0x00000003u)

#define CSL_PDC_PDCCMD_EMCLOG_MASK       (0x00003000u)
#define CSL_PDC_PDCCMD_EMCLOG_SHIFT      (0x0000000Cu)
#define CSL_PDC_PDCCMD_EMCLOG_RESETVAL   (0x00000000u)

/*----EMCLOG Tokens----*/
#define CSL_PDC_PDCCMD_EMCLOG_ENABLE     (0x00000000u)
#define CSL_PDC_PDCCMD_EMCLOG_DISABLE    (0x00000001u)

#define CSL_PDC_PDCCMD_UMCMEM_MASK       (0x00000C00u)
#define CSL_PDC_PDCCMD_UMCMEM_SHIFT      (0x0000000Au)
#define CSL_PDC_PDCCMD_UMCMEM_RESETVAL   (0x00000000u)

/*----UMCMEM Tokens----*/
#define CSL_PDC_PDCCMD_UMCMEM_NONE       (0x00000000u)
#define CSL_PDC_PDCCMD_UMCMEM_MODE1      (0x00000001u)
#define CSL_PDC_PDCCMD_UMCMEM_MODE2      (0x00000002u)
#define CSL_PDC_PDCCMD_UMCMEM_MODE3      (0x00000003u)

#define CSL_PDC_PDCCMD_UMCLOG_MASK       (0x00000300u)
#define CSL_PDC_PDCCMD_UMCLOG_SHIFT      (0x00000008u)
#define CSL_PDC_PDCCMD_UMCLOG_RESETVAL   (0x00000000u)

/*----UMCLOG Tokens----*/
#define CSL_PDC_PDCCMD_UMCLOG_ENABLE     (0x00000000u)
#define CSL_PDC_PDCCMD_UMCLOG_DISABLE    (0x00000001u)

#define CSL_PDC_PDCCMD_DMCMEM_MASK       (0x000000C0u)
#define CSL_PDC_PDCCMD_DMCMEM_SHIFT      (0x00000006u)
#define CSL_PDC_PDCCMD_DMCMEM_RESETVAL   (0x00000000u)

/*----DMCMEM Tokens----*/
#define CSL_PDC_PDCCMD_DMCMEM_NONE       (0x00000000u)
#define CSL_PDC_PDCCMD_DMCMEM_MODE1      (0x00000001u)
#define CSL_PDC_PDCCMD_DMCMEM_MODE2      (0x00000002u)
#define CSL_PDC_PDCCMD_DMCMEM_MODE3      (0x00000003u)

#define CSL_PDC_PDCCMD_DMCLOG_MASK       (0x00000030u)
#define CSL_PDC_PDCCMD_DMCLOG_SHIFT      (0x00000004u)
#define CSL_PDC_PDCCMD_DMCLOG_RESETVAL   (0x00000000u)

/*----DMCLOG Tokens----*/
#define CSL_PDC_PDCCMD_DMCLOG_ENABLE     (0x00000000u)
#define CSL_PDC_PDCCMD_DMCLOG_DISABLE    (0x00000001u)

#define CSL_PDC_PDCCMD_PMCMEM_MASK       (0x0000000Cu)
#define CSL_PDC_PDCCMD_PMCMEM_SHIFT      (0x00000002u)
#define CSL_PDC_PDCCMD_PMCMEM_RESETVAL   (0x00000000u)

/*----PMCMEM Tokens----*/
#define CSL_PDC_PDCCMD_PMCMEM_NONE       (0x00000000u)
#define CSL_PDC_PDCCMD_PMCMEM_MODE1      (0x00000001u)
#define CSL_PDC_PDCCMD_PMCMEM_MODE2      (0x00000002u)
#define CSL_PDC_PDCCMD_PMCMEM_MODE3      (0x00000003u)

#define CSL_PDC_PDCCMD_PMCLOG_MASK       (0x00000003u)
#define CSL_PDC_PDCCMD_PMCLOG_SHIFT      (0x00000000u)
#define CSL_PDC_PDCCMD_PMCLOG_RESETVAL   (0x00000000u)

/*----PMCLOG Tokens----*/
#define CSL_PDC_PDCCMD_PMCLOG_ENABLE     (0x00000000u)
#define CSL_PDC_PDCCMD_PMCLOG_DISABLE    (0x00000001u)

#define CSL_PDC_PDCCMD_RESETVAL          (0x00000000u)

#endif
