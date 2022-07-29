/*  ============================================================================
 *   Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005                 
 *                                                                              
 *   Use of this software is controlled by the terms and conditions found in the
 *   license agreement under which this software has been supplied.             
 *   ===========================================================================
 */ 

/** \file cslr_edc.h
 * 
 * \brief This file contains the Register Desciptions for EDC
 * 
 *********************************************************************/

 
#ifndef _CSLR_EDC_H_
#define _CSLR_EDC_H_

 
#include <cslr.h>

#include <tistdtypes.h>

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint8 RSVD0[4];
    volatile Uint32 L2EDSTAT;
    volatile Uint32 L2EDCMD;
    volatile Uint32 L2EDADDR;
    volatile Uint32 L2EDEN0;
    volatile Uint32 L2EDEN1;
    volatile Uint32 L2EDCPEC;
    volatile Uint32 L2EDNPEC;
    volatile Uint8 RSVD1[996];
    volatile Uint32 L1PEDSTAT;
    volatile Uint32 L1PEDCMD;
    volatile Uint32 L1PEDADDR;
} CSL_EdcRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* L2EDSTAT */

#define CSL_EDC_L2EDSTAT_LOGICEN_MASK    (0x00000001u)
#define CSL_EDC_L2EDSTAT_LOGICEN_SHIFT   (0x00000000u)
#define CSL_EDC_L2EDSTAT_LOGICEN_RESETVAL (0x00000000u)

/*----LOGICEN Tokens----*/
#define CSL_EDC_L2EDSTAT_LOGICEN_YES     (0x00000001u)
#define CSL_EDC_L2EDSTAT_LOGICEN_NO      (0x00000000u)

#define CSL_EDC_L2EDSTAT_LOGICDIS_MASK   (0x00000004u)
#define CSL_EDC_L2EDSTAT_LOGICDIS_SHIFT  (0x00000002u)
#define CSL_EDC_L2EDSTAT_LOGICDIS_RESETVAL (0x00000001u)

/*----LOGICDIS Tokens----*/
#define CSL_EDC_L2EDSTAT_LOGICDIS_YES    (0x00000001u)
#define CSL_EDC_L2EDSTAT_LOGICDIS_NO     (0x00000000u)

#define CSL_EDC_L2EDSTAT_SUSP_MASK       (0x00000008u)
#define CSL_EDC_L2EDSTAT_SUSP_SHIFT      (0x00000003u)
#define CSL_EDC_L2EDSTAT_SUSP_RESETVAL   (0x00000000u)

/*----SUSP Tokens----*/
#define CSL_EDC_L2EDSTAT_SUSP_YES        (0x00000001u)
#define CSL_EDC_L2EDSTAT_SUSP_NO         (0x00000000u)

#define CSL_EDC_L2EDSTAT_DERR_MASK       (0x00000010u)
#define CSL_EDC_L2EDSTAT_DERR_SHIFT      (0x00000004u)
#define CSL_EDC_L2EDSTAT_DERR_RESETVAL   (0x00000000u)

/*----DERR Tokens----*/
#define CSL_EDC_L2EDSTAT_DERR_YES        (0x00000001u)
#define CSL_EDC_L2EDSTAT_DERR_NO         (0x00000000u)

#define CSL_EDC_L2EDSTAT_IERR_MASK       (0x00000020u)
#define CSL_EDC_L2EDSTAT_IERR_SHIFT      (0x00000005u)
#define CSL_EDC_L2EDSTAT_IERR_RESETVAL   (0x00000000u)

/*----IERR Tokens----*/
#define CSL_EDC_L2EDSTAT_IERR_YES        (0x00000001u)
#define CSL_EDC_L2EDSTAT_IERR_NO         (0x00000000u)

#define CSL_EDC_L2EDSTAT_DMAERR_MASK     (0x00000040u)
#define CSL_EDC_L2EDSTAT_DMAERR_SHIFT    (0x00000006u)
#define CSL_EDC_L2EDSTAT_DMAERR_RESETVAL (0x00000000u)

/*----DMAERR Tokens----*/
#define CSL_EDC_L2EDSTAT_DMAERR_YES      (0x00000001u)
#define CSL_EDC_L2EDSTAT_DMAERR_NO       (0x00000000u)

#define CSL_EDC_L2EDSTAT_NERR_MASK       (0x00000300u)
#define CSL_EDC_L2EDSTAT_NERR_SHIFT      (0x00000008u)
#define CSL_EDC_L2EDSTAT_NERR_RESETVAL   (0x00000000u)

/*----NERR Tokens----*/
#define CSL_EDC_L2EDSTAT_NERR_1BIT       (0x00000000u)
#define CSL_EDC_L2EDSTAT_NERR_2BIT       (0x00000001u)
#define CSL_EDC_L2EDSTAT_NERR_PERROR     (0x00000003u)

#define CSL_EDC_L2EDSTAT_BITPOS_MASK     (0x00FF0000u)
#define CSL_EDC_L2EDSTAT_BITPOS_SHIFT    (0x00000010u)
#define CSL_EDC_L2EDSTAT_BITPOS_RESETVAL (0x00000000u)

#define CSL_EDC_L2EDSTAT_RESETVAL        (0x00000004u)

/* L2EDCMD */

#define CSL_EDC_L2EDCMD_LOGICEN_MASK     (0x00000001u)
#define CSL_EDC_L2EDCMD_LOGICEN_SHIFT    (0x00000000u)
#define CSL_EDC_L2EDCMD_LOGICEN_RESETVAL (0x00000000u)

/*----LOGICEN Tokens----*/
#define CSL_EDC_L2EDCMD_LOGICEN_YES      (0x00000001u)

#define CSL_EDC_L2EDCMD_LOGICDIS_MASK    (0x00000004u)
#define CSL_EDC_L2EDCMD_LOGICDIS_SHIFT   (0x00000002u)
#define CSL_EDC_L2EDCMD_LOGICDIS_RESETVAL (0x00000001u)

/*----LOGICDIS Tokens----*/
#define CSL_EDC_L2EDCMD_LOGICDIS_YES     (0x00000001u)

#define CSL_EDC_L2EDCMD_SUSP_MASK        (0x00000008u)
#define CSL_EDC_L2EDCMD_SUSP_SHIFT       (0x00000003u)
#define CSL_EDC_L2EDCMD_SUSP_RESETVAL    (0x00000000u)

/*----SUSP Tokens----*/
#define CSL_EDC_L2EDCMD_SUSP_YES         (0x00000001u)

#define CSL_EDC_L2EDCMD_DCLR_MASK        (0x00000010u)
#define CSL_EDC_L2EDCMD_DCLR_SHIFT       (0x00000004u)
#define CSL_EDC_L2EDCMD_DCLR_RESETVAL    (0x00000000u)

/*----DCLR Tokens----*/
#define CSL_EDC_L2EDCMD_DCLR_CLR         (0x00000001u)

#define CSL_EDC_L2EDCMD_ICLR_MASK        (0x00000020u)
#define CSL_EDC_L2EDCMD_ICLR_SHIFT       (0x00000005u)
#define CSL_EDC_L2EDCMD_ICLR_RESETVAL    (0x00000000u)

/*----ICLR Tokens----*/
#define CSL_EDC_L2EDCMD_ICLR_CLR         (0x00000001u)

#define CSL_EDC_L2EDCMD_DMACLR_MASK      (0x00000040u)
#define CSL_EDC_L2EDCMD_DMACLR_SHIFT     (0x00000006u)
#define CSL_EDC_L2EDCMD_DMACLR_RESETVAL  (0x00000000u)

/*----DMACLR Tokens----*/
#define CSL_EDC_L2EDCMD_DMACLR_CLR       (0x00000001u)

#define CSL_EDC_L2EDCMD_RESETVAL         (0x00000004u)

/* L2EDADDR */

#define CSL_EDC_L2EDADDR_SRAM_MASK       (0x00000001u)
#define CSL_EDC_L2EDADDR_SRAM_SHIFT      (0x00000000u)
#define CSL_EDC_L2EDADDR_SRAM_RESETVAL   (0x00000000u)

/*----SRAM Tokens----*/
#define CSL_EDC_L2EDADDR_SRAM_L2CACHE    (0x00000000u)
#define CSL_EDC_L2EDADDR_SRAM_L2SRAM     (0x00000001u)

#define CSL_EDC_L2EDADDR_QLINE_MASK      (0x00000006u)
#define CSL_EDC_L2EDADDR_QLINE_SHIFT     (0x00000001u)
#define CSL_EDC_L2EDADDR_QLINE_RESETVAL  (0x00000000u)

/*----QLINE Tokens----*/
#define CSL_EDC_L2EDADDR_QLINE_QTR1      (0x00000000u)
#define CSL_EDC_L2EDADDR_QLINE_QTR2      (0x00000001u)
#define CSL_EDC_L2EDADDR_QLINE_QTR3      (0x00000002u)
#define CSL_EDC_L2EDADDR_QLINE_QTR4      (0x00000003u)

#define CSL_EDC_L2EDADDR_L2WAY_MASK      (0x00000018u)
#define CSL_EDC_L2EDADDR_L2WAY_SHIFT     (0x00000003u)
#define CSL_EDC_L2EDADDR_L2WAY_RESETVAL  (0x00000000u)

/*----L2WAY Tokens----*/
#define CSL_EDC_L2EDADDR_L2WAY_WAY0      (0x00000000u)
#define CSL_EDC_L2EDADDR_L2WAY_WAY1      (0x00000001u)
#define CSL_EDC_L2EDADDR_L2WAY_WAY2      (0x00000002u)
#define CSL_EDC_L2EDADDR_L2WAY_WAY3      (0x00000003u)

#define CSL_EDC_L2EDADDR_ADDR_MASK       (0xFFFFFFE0u)
#define CSL_EDC_L2EDADDR_ADDR_SHIFT      (0x00000005u)
#define CSL_EDC_L2EDADDR_ADDR_RESETVAL   (0x00000000u)

#define CSL_EDC_L2EDADDR_RESETVAL        (0x00000000u)

/* L2EDCPEC */

#define CSL_EDC_L2EDCPEC_CNT_MASK        (0x000000FFu)
#define CSL_EDC_L2EDCPEC_CNT_SHIFT       (0x00000000u)
#define CSL_EDC_L2EDCPEC_CNT_RESETVAL    (0x00000000u)

#define CSL_EDC_L2EDCPEC_RESETVAL        (0x00000000u)

/* L2EDNPEC */

#define CSL_EDC_L2EDNPEC_CNT_MASK        (0x000000FFu)
#define CSL_EDC_L2EDNPEC_CNT_SHIFT       (0x00000000u)
#define CSL_EDC_L2EDNPEC_CNT_RESETVAL    (0x00000000u)

#define CSL_EDC_L2EDNPEC_RESETVAL        (0x00000000u)

/* L2EDEN0 */

#define CSL_EDC_L2EDEN0_EN_MASK          (0xFFFFFFFFu)
#define CSL_EDC_L2EDEN0_EN_SHIFT         (0x00000000u)
#define CSL_EDC_L2EDEN0_EN_RESETVAL      (0x00000000u)

#define CSL_EDC_L2EDEN0_RESETVAL         (0x00000000u)

/* L2EDEN1 */

#define CSL_EDC_L2EDEN1_EN_MASK          (0xFFFFFFFFu)
#define CSL_EDC_L2EDEN1_EN_SHIFT         (0x00000000u)
#define CSL_EDC_L2EDEN1_EN_RESETVAL      (0x00000000u)

#define CSL_EDC_L2EDEN1_RESETVAL         (0x00000000u)

/* L1PEDSTAT */

#define CSL_EDC_L1PEDSTAT_LOGICEN_MASK   (0x00000001u)
#define CSL_EDC_L1PEDSTAT_LOGICEN_SHIFT  (0x00000000u)
#define CSL_EDC_L1PEDSTAT_LOGICEN_RESETVAL (0x00000000u)

/*----LOGICEN Tokens----*/
#define CSL_EDC_L1PEDSTAT_LOGICEN_YES    (0x00000001u)
#define CSL_EDC_L1PEDSTAT_LOGICEN_NO     (0x00000000u)

#define CSL_EDC_L1PEDSTAT_LOGICDIS_MASK  (0x00000004u)
#define CSL_EDC_L1PEDSTAT_LOGICDIS_SHIFT (0x00000002u)
#define CSL_EDC_L1PEDSTAT_LOGICDIS_RESETVAL (0x00000001u)

/*----LOGICDIS Tokens----*/
#define CSL_EDC_L1PEDSTAT_LOGICDIS_YES   (0x00000001u)
#define CSL_EDC_L1PEDSTAT_LOGICDIS_NO    (0x00000000u)

#define CSL_EDC_L1PEDSTAT_SUSP_MASK      (0x00000008u)
#define CSL_EDC_L1PEDSTAT_SUSP_SHIFT     (0x00000003u)
#define CSL_EDC_L1PEDSTAT_SUSP_RESETVAL  (0x00000000u)

/*----SUSP Tokens----*/
#define CSL_EDC_L1PEDSTAT_SUSP_YES       (0x00000001u)
#define CSL_EDC_L1PEDSTAT_SUSP_NO        (0x00000000u)

#define CSL_EDC_L1PEDSTAT_IERR_MASK      (0x00000020u)
#define CSL_EDC_L1PEDSTAT_IERR_SHIFT     (0x00000005u)
#define CSL_EDC_L1PEDSTAT_IERR_RESETVAL  (0x00000000u)

/*----IERR Tokens----*/
#define CSL_EDC_L1PEDSTAT_IERR_YES       (0x00000001u)
#define CSL_EDC_L1PEDSTAT_IERR_NO        (0x00000000u)

#define CSL_EDC_L1PEDSTAT_DMAERR_MASK    (0x00000040u)
#define CSL_EDC_L1PEDSTAT_DMAERR_SHIFT   (0x00000006u)
#define CSL_EDC_L1PEDSTAT_DMAERR_RESETVAL (0x00000000u)

/*----DMAERR Tokens----*/
#define CSL_EDC_L1PEDSTAT_DMAERR_YES     (0x00000001u)
#define CSL_EDC_L1PEDSTAT_DMAERR_NO      (0x00000000u)

#define CSL_EDC_L1PEDSTAT_RESETVAL       (0x00000004u)

/* L1PEDCMD */

#define CSL_EDC_L1PEDCMD_LOGICEN_MASK    (0x00000001u)
#define CSL_EDC_L1PEDCMD_LOGICEN_SHIFT   (0x00000000u)
#define CSL_EDC_L1PEDCMD_LOGICEN_RESETVAL (0x00000000u)

/*----LOGICEN Tokens----*/
#define CSL_EDC_L1PEDCMD_LOGICEN_YES     (0x00000001u)

#define CSL_EDC_L1PEDCMD_LOGICDIS_MASK   (0x00000004u)
#define CSL_EDC_L1PEDCMD_LOGICDIS_SHIFT  (0x00000002u)
#define CSL_EDC_L1PEDCMD_LOGICDIS_RESETVAL (0x00000001u)

/*----LOGICDIS Tokens----*/
#define CSL_EDC_L1PEDCMD_LOGICDIS_YES    (0x00000001u)

#define CSL_EDC_L1PEDCMD_SUSP_MASK       (0x00000008u)
#define CSL_EDC_L1PEDCMD_SUSP_SHIFT      (0x00000003u)
#define CSL_EDC_L1PEDCMD_SUSP_RESETVAL   (0x00000000u)

/*----SUSP Tokens----*/
#define CSL_EDC_L1PEDCMD_SUSP_YES        (0x00000001u)

#define CSL_EDC_L1PEDCMD_ICLR_MASK       (0x00000020u)
#define CSL_EDC_L1PEDCMD_ICLR_SHIFT      (0x00000005u)
#define CSL_EDC_L1PEDCMD_ICLR_RESETVAL   (0x00000000u)

/*----ICLR Tokens----*/
#define CSL_EDC_L1PEDCMD_ICLR_CLR        (0x00000001u)

#define CSL_EDC_L1PEDCMD_DMACLR_MASK     (0x00000040u)
#define CSL_EDC_L1PEDCMD_DMACLR_SHIFT    (0x00000006u)
#define CSL_EDC_L1PEDCMD_DMACLR_RESETVAL (0x00000000u)

/*----DMACLR Tokens----*/
#define CSL_EDC_L1PEDCMD_DMACLR_CLR      (0x00000001u)

#define CSL_EDC_L1PEDCMD_RESETVAL        (0x00000004u)

/* L1PEDADDR */

#define CSL_EDC_L1PEDADDR_SRAM_MASK      (0x00000001u)
#define CSL_EDC_L1PEDADDR_SRAM_SHIFT     (0x00000000u)
#define CSL_EDC_L1PEDADDR_SRAM_RESETVAL  (0x00000000u)

/*----SRAM Tokens----*/
#define CSL_EDC_L1PEDADDR_SRAM_L1PCACHE  (0x00000000u)
#define CSL_EDC_L1PEDADDR_SRAM_L1PSRAM   (0x00000001u)

#define CSL_EDC_L1PEDADDR_ADDR_MASK      (0xFFFFFFE0u)
#define CSL_EDC_L1PEDADDR_ADDR_SHIFT     (0x00000005u)
#define CSL_EDC_L1PEDADDR_ADDR_RESETVAL  (0x00000000u)

#define CSL_EDC_L1PEDADDR_RESETVAL       (0x00000000u)

#endif
