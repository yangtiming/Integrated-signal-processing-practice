/*  ============================================================================
 *   Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005                 
 *                                                                              
 *   Use of this software is controlled by the terms and conditions found in the
 *   license agreement under which this software has been supplied.             
 *   ===========================================================================
 */

#ifndef _CSLR_EDMACC_H_
#define _CSLR_EDMACC_H_

/** \file cslr_edmacc.h
 * 
 * \brief This file contains the Register Desciptions for EDMACC
 * 
 *********************************************************************/

#include <cslr.h>

#include <tistdtypes.h>

/**************************************************************************\
* Register Overlay Structure for DRA 
\**************************************************************************/
typedef struct  {
    volatile Uint32 DRAE;
    volatile Uint32 DRAEH;
} CSL_EdmaccDraRegs;

/**************************************************************************\
* Register Overlay Structure for QUEEVTENTRY 
\**************************************************************************/
typedef struct  {
    volatile Uint32 EVT_ENTRY;
} CSL_EdmaccQueevtentryRegs;

/**************************************************************************\
* Register Overlay Structure for SHADOW 
\**************************************************************************/
typedef struct  {
    volatile Uint32 ER;
    volatile Uint32 ERH;
    volatile Uint32 ECR;
    volatile Uint32 ECRH;
    volatile Uint32 ESR;
    volatile Uint32 ESRH;
    volatile Uint32 CER;
    volatile Uint32 CERH;
    volatile Uint32 EER;
    volatile Uint32 EERH;
    volatile Uint32 EECR;
    volatile Uint32 EECRH;
    volatile Uint32 EESR;
    volatile Uint32 EESRH;
    volatile Uint32 SER;
    volatile Uint32 SERH;
    volatile Uint32 SECR;
    volatile Uint32 SECRH;
    volatile Uint8 RSVD0[8];
    volatile Uint32 IER;
    volatile Uint32 IERH;
    volatile Uint32 IECR;
    volatile Uint32 IECRH;
    volatile Uint32 IESR;
    volatile Uint32 IESRH;
    volatile Uint32 IPR;
    volatile Uint32 IPRH;
    volatile Uint32 ICR;
    volatile Uint32 ICRH;
    volatile Uint32 IEVAL;
    volatile Uint8 RSVD1[4];
    volatile Uint32 QER;
    volatile Uint32 QEER;
    volatile Uint32 QEECR;
    volatile Uint32 QEESR;
    volatile Uint32 QSER;
    volatile Uint32 QSECR;
    volatile Uint8 RSVD2[360];
} CSL_EdmaccShadowRegs;

typedef volatile CSL_EdmaccShadowRegs  *CSL_EdmaccShadowRegsOvly;
/**************************************************************************\
* Register Overlay Structure for PARAMENTRY 
\**************************************************************************/
typedef struct  {
    volatile Uint32 OPT;
    volatile Uint32 SRC;
    volatile Uint32 A_B_CNT;
    volatile Uint32 DST;
    volatile Uint32 SRC_DST_BIDX;
    volatile Uint32 LINK_BCNTRLD;
    volatile Uint32 SRC_DST_CIDX;
    volatile Uint32 CCNT;
} CSL_EdmaccParamentryRegs;
typedef volatile CSL_EdmaccParamentryRegs  *CSL_EdmaccParamentryRegsOvly;
/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 REV;
    volatile Uint32 CCCFG;
    volatile Uint8 RSVD0[504];
    volatile Uint32 QCHMAP[8];
    volatile Uint8 RSVD1[32];
    volatile Uint32 DMAQNUM[8];
    volatile Uint32 QDMAQNUM;
    volatile Uint8 RSVD2[28];
    volatile Uint32 QUETCMAP;
    volatile Uint32 QUEPRI;
    volatile Uint8 RSVD3[120];
    volatile Uint32 EMR;
    volatile Uint32 EMRH;
    volatile Uint32 EMCR;
    volatile Uint32 EMCRH;
    volatile Uint32 QEMR;
    volatile Uint32 QEMCR;
    volatile Uint32 CCERR;
    volatile Uint32 CCERRCLR;
    volatile Uint32 EEVAL;
    volatile Uint8 RSVD4[28];
    CSL_EdmaccDraRegs DRA[4];
    volatile Uint8 RSVD5[32];
    volatile Uint32 QRAE[4];
    volatile Uint8 RSVD6[112];
    CSL_EdmaccQueevtentryRegs QUEEVTENTRY[2][16];
    volatile Uint8 RSVD7[384];
    volatile Uint32 QSTAT[2];
    volatile Uint8 RSVD8[24];
    volatile Uint32 QWMTHRA;
    volatile Uint32 QWMTHRB;
    volatile Uint8 RSVD9[24];
    volatile Uint32 CCSTAT;
    volatile Uint8 RSVD10[188];
    volatile Uint32 AETCTL;
    volatile Uint32 AETSTAT;
    volatile Uint32 AETCMD;
    volatile Uint8 RSVD11[2292];
    volatile Uint32 ER;
    volatile Uint32 ERH;
    volatile Uint32 ECR;
    volatile Uint32 ECRH;
    volatile Uint32 ESR;
    volatile Uint32 ESRH;
    volatile Uint32 CER;
    volatile Uint32 CERH;
    volatile Uint32 EER;
    volatile Uint32 EERH;
    volatile Uint32 EECR;
    volatile Uint32 EECRH;
    volatile Uint32 EESR;
    volatile Uint32 EESRH;
    volatile Uint32 SER;
    volatile Uint32 SERH;
    volatile Uint32 SECR;
    volatile Uint32 SECRH;
    volatile Uint8 RSVD12[8];
    volatile Uint32 IER;
    volatile Uint32 IERH;
    volatile Uint32 IECR;
    volatile Uint32 IECRH;
    volatile Uint32 IESR;
    volatile Uint32 IESRH;
    volatile Uint32 IPR;
    volatile Uint32 IPRH;
    volatile Uint32 ICR;
    volatile Uint32 ICRH;
    volatile Uint32 IEVAL;
    volatile Uint8 RSVD13[4];
    volatile Uint32 QER;
    volatile Uint32 QEER;
    volatile Uint32 QEECR;
    volatile Uint32 QEESR;
    volatile Uint32 QSER;
    volatile Uint32 QSECR;
    volatile Uint8 RSVD14[3944];
    CSL_EdmaccShadowRegs SHADOW[4];
    volatile Uint8 RSVD15[6144];
    CSL_EdmaccParamentryRegs PARAMENTRY[128];
} CSL_EdmaccRegs;

typedef volatile CSL_EdmaccRegs  *CSL_EdmaccRegsOvly;
/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* REV */

#define CSL_EDMACC_REV_SCHEME_MASK       (0xC0000000u)
#define CSL_EDMACC_REV_SCHEME_SHIFT      (0x0000001Eu)
#define CSL_EDMACC_REV_SCHEME_RESETVAL   (0x00000000u)

#define CSL_EDMACC_REV_FUNCTION_MASK     (0x0FFF0000u)
#define CSL_EDMACC_REV_FUNCTION_SHIFT    (0x00000010u)
#define CSL_EDMACC_REV_FUNCTION_RESETVAL (0x00000001u)

#define CSL_EDMACC_REV_RTL_MASK          (0x0000F800u)
#define CSL_EDMACC_REV_RTL_SHIFT         (0x0000000Bu)
#define CSL_EDMACC_REV_RTL_RESETVAL      (0x00000000u)

#define CSL_EDMACC_REV_MAJOR_MASK        (0x00000700u)
#define CSL_EDMACC_REV_MAJOR_SHIFT       (0x00000008u)
#define CSL_EDMACC_REV_MAJOR_RESETVAL    (0x00000003u)

#define CSL_EDMACC_REV_CUSTOM_MASK       (0x000000C0u)
#define CSL_EDMACC_REV_CUSTOM_SHIFT      (0x00000006u)
#define CSL_EDMACC_REV_CUSTOM_RESETVAL   (0x00000000u)

#define CSL_EDMACC_REV_MINOR_MASK        (0x0000003Fu)
#define CSL_EDMACC_REV_MINOR_SHIFT       (0x00000000u)
#define CSL_EDMACC_REV_MINOR_RESETVAL    (0x00000000u)

#define CSL_EDMACC_REV_RESETVAL          (0x00010300u)

/* CCCFG */

#define CSL_EDMACC_CCCFG_MP_EXIST_MASK   (0x02000000u)
#define CSL_EDMACC_CCCFG_MP_EXIST_SHIFT  (0x00000019u)
#define CSL_EDMACC_CCCFG_MP_EXIST_RESETVAL (0x00000000u)

/*----MP_EXIST Tokens----*/
#define CSL_EDMACC_CCCFG_MP_EXIST_NONE   (0x00000000u)
#define CSL_EDMACC_CCCFG_MP_EXIST_INCLUDED (0x00000001u)

#define CSL_EDMACC_CCCFG_CHMAP_EXIST_MASK (0x01000000u)
#define CSL_EDMACC_CCCFG_CHMAP_EXIST_SHIFT (0x00000018u)
#define CSL_EDMACC_CCCFG_CHMAP_EXIST_RESETVAL (0x00000000u)

/*----CHMAP_EXIST Tokens----*/
#define CSL_EDMACC_CCCFG_CHMAP_EXIST_NONE (0x00000000u)
#define CSL_EDMACC_CCCFG_CHMAP_EXIST_INCLUDED (0x00000001u)

#define CSL_EDMACC_CCCFG_NUM_REGN_MASK   (0x00300000u)
#define CSL_EDMACC_CCCFG_NUM_REGN_SHIFT  (0x00000014u)
#define CSL_EDMACC_CCCFG_NUM_REGN_RESETVAL (0x00000000u)

/*----NUM_REGN Tokens----*/
#define CSL_EDMACC_CCCFG_NUM_REGN_4      (0x00000002u)

#define CSL_EDMACC_CCCFG_NUM_TC_MASK     (0x00070000u)
#define CSL_EDMACC_CCCFG_NUM_TC_SHIFT    (0x00000010u)
#define CSL_EDMACC_CCCFG_NUM_TC_RESETVAL (0x00000001u)

/*----NUM_TC Tokens----*/
#define CSL_EDMACC_CCCFG_NUM_TC_1        (0x00000000u)
#define CSL_EDMACC_CCCFG_NUM_TC_2        (0x00000001u)

#define CSL_EDMACC_CCCFG_NUM_PAENTRY_MASK (0x00007000u)
#define CSL_EDMACC_CCCFG_NUM_PAENTRY_SHIFT (0x0000000Cu)
#define CSL_EDMACC_CCCFG_NUM_PAENTRY_RESETVAL (0x00000003u)

/*----NUM_PAENTRY Tokens----*/
#define CSL_EDMACC_CCCFG_NUM_PAENTRY_128 (0x00000003u)

#define CSL_EDMACC_CCCFG_NUM_INTCH_MASK  (0x00000700u)
#define CSL_EDMACC_CCCFG_NUM_INTCH_SHIFT (0x00000008u)
#define CSL_EDMACC_CCCFG_NUM_INTCH_RESETVAL (0x00000004u)

/*----NUM_INTCH Tokens----*/
#define CSL_EDMACC_CCCFG_NUM_INTCH_8     (0x00000001u)
#define CSL_EDMACC_CCCFG_NUM_INTCH_16    (0x00000002u)
#define CSL_EDMACC_CCCFG_NUM_INTCH_32    (0x00000003u)
#define CSL_EDMACC_CCCFG_NUM_INTCH_64    (0x00000004u)

#define CSL_EDMACC_CCCFG_NUM_QDMACH_MASK (0x00000070u)
#define CSL_EDMACC_CCCFG_NUM_QDMACH_SHIFT (0x00000004u)
#define CSL_EDMACC_CCCFG_NUM_QDMACH_RESETVAL (0x00000004u)

/*----NUM_QDMACH Tokens----*/
#define CSL_EDMACC_CCCFG_NUM_QDMACH_8    (0x00000004u)

#define CSL_EDMACC_CCCFG_NUM_DMACH_MASK  (0x00000007u)
#define CSL_EDMACC_CCCFG_NUM_DMACH_SHIFT (0x00000000u)
#define CSL_EDMACC_CCCFG_NUM_DMACH_RESETVAL (0x00000005u)

/*----NUM_DMACH Tokens----*/
#define CSL_EDMACC_CCCFG_NUM_DMACH_64    (0x00000005u)

#define CSL_EDMACC_CCCFG_RESETVAL        (0x00013445u)

/* QCHMAP */

#define CSL_EDMACC_QCHMAP_PAENTRY_MASK   (0x00003FE0u)
#define CSL_EDMACC_QCHMAP_PAENTRY_SHIFT  (0x00000005u)
#define CSL_EDMACC_QCHMAP_PAENTRY_RESETVAL (0x00000000u)

#define CSL_EDMACC_QCHMAP_TRWORD_MASK    (0x0000001Cu)
#define CSL_EDMACC_QCHMAP_TRWORD_SHIFT   (0x00000002u)
#define CSL_EDMACC_QCHMAP_TRWORD_RESETVAL (0x00000000u)

#define CSL_EDMACC_QCHMAP_RESETVAL       (0x00000000u)

/* DMAQNUM */

#define CSL_EDMACC_DMAQNUM_E7_MASK       (0x70000000u)
#define CSL_EDMACC_DMAQNUM_E7_SHIFT      (0x0000001Cu)
#define CSL_EDMACC_DMAQNUM_E7_RESETVAL   (0x00000000u)

#define CSL_EDMACC_DMAQNUM_E6_MASK       (0x07000000u)
#define CSL_EDMACC_DMAQNUM_E6_SHIFT      (0x00000018u)
#define CSL_EDMACC_DMAQNUM_E6_RESETVAL   (0x00000000u)

#define CSL_EDMACC_DMAQNUM_E5_MASK       (0x00700000u)
#define CSL_EDMACC_DMAQNUM_E5_SHIFT      (0x00000014u)
#define CSL_EDMACC_DMAQNUM_E5_RESETVAL   (0x00000000u)

#define CSL_EDMACC_DMAQNUM_E4_MASK       (0x00070000u)
#define CSL_EDMACC_DMAQNUM_E4_SHIFT      (0x00000010u)
#define CSL_EDMACC_DMAQNUM_E4_RESETVAL   (0x00000000u)

#define CSL_EDMACC_DMAQNUM_E3_MASK       (0x00007000u)
#define CSL_EDMACC_DMAQNUM_E3_SHIFT      (0x0000000Cu)
#define CSL_EDMACC_DMAQNUM_E3_RESETVAL   (0x00000000u)

#define CSL_EDMACC_DMAQNUM_E2_MASK       (0x00000700u)
#define CSL_EDMACC_DMAQNUM_E2_SHIFT      (0x00000008u)
#define CSL_EDMACC_DMAQNUM_E2_RESETVAL   (0x00000000u)

#define CSL_EDMACC_DMAQNUM_E1_MASK       (0x00000070u)
#define CSL_EDMACC_DMAQNUM_E1_SHIFT      (0x00000004u)
#define CSL_EDMACC_DMAQNUM_E1_RESETVAL   (0x00000000u)

#define CSL_EDMACC_DMAQNUM_E0_MASK       (0x00000007u)
#define CSL_EDMACC_DMAQNUM_E0_SHIFT      (0x00000000u)
#define CSL_EDMACC_DMAQNUM_E0_RESETVAL   (0x00000000u)

#define CSL_EDMACC_DMAQNUM_RESETVAL      (0x00000000u)

/* QDMAQNUM */

#define CSL_EDMACC_QDMAQNUM_E7_MASK      (0x70000000u)
#define CSL_EDMACC_QDMAQNUM_E7_SHIFT     (0x0000001Cu)
#define CSL_EDMACC_QDMAQNUM_E7_RESETVAL  (0x00000000u)

#define CSL_EDMACC_QDMAQNUM_E6_MASK      (0x07000000u)
#define CSL_EDMACC_QDMAQNUM_E6_SHIFT     (0x00000018u)
#define CSL_EDMACC_QDMAQNUM_E6_RESETVAL  (0x00000000u)

#define CSL_EDMACC_QDMAQNUM_E5_MASK      (0x00700000u)
#define CSL_EDMACC_QDMAQNUM_E5_SHIFT     (0x00000014u)
#define CSL_EDMACC_QDMAQNUM_E5_RESETVAL  (0x00000000u)

#define CSL_EDMACC_QDMAQNUM_E4_MASK      (0x00070000u)
#define CSL_EDMACC_QDMAQNUM_E4_SHIFT     (0x00000010u)
#define CSL_EDMACC_QDMAQNUM_E4_RESETVAL  (0x00000000u)

#define CSL_EDMACC_QDMAQNUM_E3_MASK      (0x00007000u)
#define CSL_EDMACC_QDMAQNUM_E3_SHIFT     (0x0000000Cu)
#define CSL_EDMACC_QDMAQNUM_E3_RESETVAL  (0x00000000u)

#define CSL_EDMACC_QDMAQNUM_E2_MASK      (0x00000700u)
#define CSL_EDMACC_QDMAQNUM_E2_SHIFT     (0x00000008u)
#define CSL_EDMACC_QDMAQNUM_E2_RESETVAL  (0x00000000u)

#define CSL_EDMACC_QDMAQNUM_E1_MASK      (0x00000070u)
#define CSL_EDMACC_QDMAQNUM_E1_SHIFT     (0x00000004u)
#define CSL_EDMACC_QDMAQNUM_E1_RESETVAL  (0x00000000u)

#define CSL_EDMACC_QDMAQNUM_E0_MASK      (0x00000007u)
#define CSL_EDMACC_QDMAQNUM_E0_SHIFT     (0x00000000u)
#define CSL_EDMACC_QDMAQNUM_E0_RESETVAL  (0x00000000u)

#define CSL_EDMACC_QDMAQNUM_RESETVAL     (0x00000000u)

/* QUETCMAP */

#define CSL_EDMACC_QUETCMAP_TCNUMQ1_MASK (0x00000070u)
#define CSL_EDMACC_QUETCMAP_TCNUMQ1_SHIFT (0x00000004u)
#define CSL_EDMACC_QUETCMAP_TCNUMQ1_RESETVAL (0x00000000u)

#define CSL_EDMACC_QUETCMAP_TCNUMQ0_MASK (0x00000007u)
#define CSL_EDMACC_QUETCMAP_TCNUMQ0_SHIFT (0x00000000u)
#define CSL_EDMACC_QUETCMAP_TCNUMQ0_RESETVAL (0x00000000u)

#define CSL_EDMACC_QUETCMAP_RESETVAL     (0x00000000u)

/* QUEPRI */

#define CSL_EDMACC_QUEPRI_PRIQ1_MASK     (0x00000070u)
#define CSL_EDMACC_QUEPRI_PRIQ1_SHIFT    (0x00000004u)
#define CSL_EDMACC_QUEPRI_PRIQ1_RESETVAL (0x00000000u)

#define CSL_EDMACC_QUEPRI_PRIQ0_MASK     (0x00000007u)
#define CSL_EDMACC_QUEPRI_PRIQ0_SHIFT    (0x00000000u)
#define CSL_EDMACC_QUEPRI_PRIQ0_RESETVAL (0x00000000u)

#define CSL_EDMACC_QUEPRI_RESETVAL       (0x00000000u)

/* EMR */

#define CSL_EDMACC_EMR_E31_MASK          (0x80000000u)
#define CSL_EDMACC_EMR_E31_SHIFT         (0x0000001Fu)
#define CSL_EDMACC_EMR_E31_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMR_E30_MASK          (0x40000000u)
#define CSL_EDMACC_EMR_E30_SHIFT         (0x0000001Eu)
#define CSL_EDMACC_EMR_E30_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMR_E29_MASK          (0x20000000u)
#define CSL_EDMACC_EMR_E29_SHIFT         (0x0000001Du)
#define CSL_EDMACC_EMR_E29_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMR_E28_MASK          (0x10000000u)
#define CSL_EDMACC_EMR_E28_SHIFT         (0x0000001Cu)
#define CSL_EDMACC_EMR_E28_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMR_E27_MASK          (0x08000000u)
#define CSL_EDMACC_EMR_E27_SHIFT         (0x0000001Bu)
#define CSL_EDMACC_EMR_E27_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMR_E26_MASK          (0x04000000u)
#define CSL_EDMACC_EMR_E26_SHIFT         (0x0000001Au)
#define CSL_EDMACC_EMR_E26_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMR_E25_MASK          (0x02000000u)
#define CSL_EDMACC_EMR_E25_SHIFT         (0x00000019u)
#define CSL_EDMACC_EMR_E25_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMR_E24_MASK          (0x01000000u)
#define CSL_EDMACC_EMR_E24_SHIFT         (0x00000018u)
#define CSL_EDMACC_EMR_E24_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMR_E23_MASK          (0x00800000u)
#define CSL_EDMACC_EMR_E23_SHIFT         (0x00000017u)
#define CSL_EDMACC_EMR_E23_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMR_E22_MASK          (0x00400000u)
#define CSL_EDMACC_EMR_E22_SHIFT         (0x00000016u)
#define CSL_EDMACC_EMR_E22_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMR_E21_MASK          (0x00200000u)
#define CSL_EDMACC_EMR_E21_SHIFT         (0x00000015u)
#define CSL_EDMACC_EMR_E21_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMR_E20_MASK          (0x00100000u)
#define CSL_EDMACC_EMR_E20_SHIFT         (0x00000014u)
#define CSL_EDMACC_EMR_E20_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMR_E19_MASK          (0x00080000u)
#define CSL_EDMACC_EMR_E19_SHIFT         (0x00000013u)
#define CSL_EDMACC_EMR_E19_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMR_E18_MASK          (0x00040000u)
#define CSL_EDMACC_EMR_E18_SHIFT         (0x00000012u)
#define CSL_EDMACC_EMR_E18_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMR_E17_MASK          (0x00020000u)
#define CSL_EDMACC_EMR_E17_SHIFT         (0x00000011u)
#define CSL_EDMACC_EMR_E17_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMR_E16_MASK          (0x00010000u)
#define CSL_EDMACC_EMR_E16_SHIFT         (0x00000010u)
#define CSL_EDMACC_EMR_E16_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMR_E15_MASK          (0x00008000u)
#define CSL_EDMACC_EMR_E15_SHIFT         (0x0000000Fu)
#define CSL_EDMACC_EMR_E15_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMR_E14_MASK          (0x00004000u)
#define CSL_EDMACC_EMR_E14_SHIFT         (0x0000000Eu)
#define CSL_EDMACC_EMR_E14_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMR_E13_MASK          (0x00002000u)
#define CSL_EDMACC_EMR_E13_SHIFT         (0x0000000Du)
#define CSL_EDMACC_EMR_E13_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMR_E12_MASK          (0x00001000u)
#define CSL_EDMACC_EMR_E12_SHIFT         (0x0000000Cu)
#define CSL_EDMACC_EMR_E12_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMR_E11_MASK          (0x00000800u)
#define CSL_EDMACC_EMR_E11_SHIFT         (0x0000000Bu)
#define CSL_EDMACC_EMR_E11_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMR_E10_MASK          (0x00000400u)
#define CSL_EDMACC_EMR_E10_SHIFT         (0x0000000Au)
#define CSL_EDMACC_EMR_E10_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMR_E9_MASK           (0x00000200u)
#define CSL_EDMACC_EMR_E9_SHIFT          (0x00000009u)
#define CSL_EDMACC_EMR_E9_RESETVAL       (0x00000000u)

#define CSL_EDMACC_EMR_E8_MASK           (0x00000100u)
#define CSL_EDMACC_EMR_E8_SHIFT          (0x00000008u)
#define CSL_EDMACC_EMR_E8_RESETVAL       (0x00000000u)

#define CSL_EDMACC_EMR_E7_MASK           (0x00000080u)
#define CSL_EDMACC_EMR_E7_SHIFT          (0x00000007u)
#define CSL_EDMACC_EMR_E7_RESETVAL       (0x00000000u)

#define CSL_EDMACC_EMR_E6_MASK           (0x00000040u)
#define CSL_EDMACC_EMR_E6_SHIFT          (0x00000006u)
#define CSL_EDMACC_EMR_E6_RESETVAL       (0x00000000u)

#define CSL_EDMACC_EMR_E5_MASK           (0x00000020u)
#define CSL_EDMACC_EMR_E5_SHIFT          (0x00000005u)
#define CSL_EDMACC_EMR_E5_RESETVAL       (0x00000000u)

#define CSL_EDMACC_EMR_E4_MASK           (0x00000010u)
#define CSL_EDMACC_EMR_E4_SHIFT          (0x00000004u)
#define CSL_EDMACC_EMR_E4_RESETVAL       (0x00000000u)

#define CSL_EDMACC_EMR_E3_MASK           (0x00000008u)
#define CSL_EDMACC_EMR_E3_SHIFT          (0x00000003u)
#define CSL_EDMACC_EMR_E3_RESETVAL       (0x00000000u)

#define CSL_EDMACC_EMR_E2_MASK           (0x00000004u)
#define CSL_EDMACC_EMR_E2_SHIFT          (0x00000002u)
#define CSL_EDMACC_EMR_E2_RESETVAL       (0x00000000u)

#define CSL_EDMACC_EMR_E1_MASK           (0x00000002u)
#define CSL_EDMACC_EMR_E1_SHIFT          (0x00000001u)
#define CSL_EDMACC_EMR_E1_RESETVAL       (0x00000000u)

#define CSL_EDMACC_EMR_E0_MASK           (0x00000001u)
#define CSL_EDMACC_EMR_E0_SHIFT          (0x00000000u)
#define CSL_EDMACC_EMR_E0_RESETVAL       (0x00000000u)

#define CSL_EDMACC_EMR_RESETVAL          (0x00000000u)

/* EMRH */

#define CSL_EDMACC_EMRH_E63_MASK         (0x80000000u)
#define CSL_EDMACC_EMRH_E63_SHIFT        (0x0000001Fu)
#define CSL_EDMACC_EMRH_E63_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_E62_MASK         (0x40000000u)
#define CSL_EDMACC_EMRH_E62_SHIFT        (0x0000001Eu)
#define CSL_EDMACC_EMRH_E62_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_E61_MASK         (0x20000000u)
#define CSL_EDMACC_EMRH_E61_SHIFT        (0x0000001Du)
#define CSL_EDMACC_EMRH_E61_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_E60_MASK         (0x10000000u)
#define CSL_EDMACC_EMRH_E60_SHIFT        (0x0000001Cu)
#define CSL_EDMACC_EMRH_E60_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_E59_MASK         (0x08000000u)
#define CSL_EDMACC_EMRH_E59_SHIFT        (0x0000001Bu)
#define CSL_EDMACC_EMRH_E59_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_E58_MASK         (0x04000000u)
#define CSL_EDMACC_EMRH_E58_SHIFT        (0x0000001Au)
#define CSL_EDMACC_EMRH_E58_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_E57_MASK         (0x02000000u)
#define CSL_EDMACC_EMRH_E57_SHIFT        (0x00000019u)
#define CSL_EDMACC_EMRH_E57_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_E56_MASK         (0x01000000u)
#define CSL_EDMACC_EMRH_E56_SHIFT        (0x00000018u)
#define CSL_EDMACC_EMRH_E56_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_E55_MASK         (0x00800000u)
#define CSL_EDMACC_EMRH_E55_SHIFT        (0x00000017u)
#define CSL_EDMACC_EMRH_E55_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_E54_MASK         (0x00400000u)
#define CSL_EDMACC_EMRH_E54_SHIFT        (0x00000016u)
#define CSL_EDMACC_EMRH_E54_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_E53_MASK         (0x00200000u)
#define CSL_EDMACC_EMRH_E53_SHIFT        (0x00000015u)
#define CSL_EDMACC_EMRH_E53_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_E52_MASK         (0x00100000u)
#define CSL_EDMACC_EMRH_E52_SHIFT        (0x00000014u)
#define CSL_EDMACC_EMRH_E52_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_E51_MASK         (0x00080000u)
#define CSL_EDMACC_EMRH_E51_SHIFT        (0x00000013u)
#define CSL_EDMACC_EMRH_E51_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_E50_MASK         (0x00040000u)
#define CSL_EDMACC_EMRH_E50_SHIFT        (0x00000012u)
#define CSL_EDMACC_EMRH_E50_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_E49_MASK         (0x00020000u)
#define CSL_EDMACC_EMRH_E49_SHIFT        (0x00000011u)
#define CSL_EDMACC_EMRH_E49_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_E48_MASK         (0x00010000u)
#define CSL_EDMACC_EMRH_E48_SHIFT        (0x00000010u)
#define CSL_EDMACC_EMRH_E48_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_E47_MASK         (0x00008000u)
#define CSL_EDMACC_EMRH_E47_SHIFT        (0x0000000Fu)
#define CSL_EDMACC_EMRH_E47_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_E46_MASK         (0x00004000u)
#define CSL_EDMACC_EMRH_E46_SHIFT        (0x0000000Eu)
#define CSL_EDMACC_EMRH_E46_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_E45_MASK         (0x00002000u)
#define CSL_EDMACC_EMRH_E45_SHIFT        (0x0000000Du)
#define CSL_EDMACC_EMRH_E45_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_E44_MASK         (0x00001000u)
#define CSL_EDMACC_EMRH_E44_SHIFT        (0x0000000Cu)
#define CSL_EDMACC_EMRH_E44_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_E43_MASK         (0x00000800u)
#define CSL_EDMACC_EMRH_E43_SHIFT        (0x0000000Bu)
#define CSL_EDMACC_EMRH_E43_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_E42_MASK         (0x00000400u)
#define CSL_EDMACC_EMRH_E42_SHIFT        (0x0000000Au)
#define CSL_EDMACC_EMRH_E42_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_E41_MASK         (0x00000200u)
#define CSL_EDMACC_EMRH_E41_SHIFT        (0x00000009u)
#define CSL_EDMACC_EMRH_E41_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_E40_MASK         (0x00000100u)
#define CSL_EDMACC_EMRH_E40_SHIFT        (0x00000008u)
#define CSL_EDMACC_EMRH_E40_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_E39_MASK         (0x00000080u)
#define CSL_EDMACC_EMRH_E39_SHIFT        (0x00000007u)
#define CSL_EDMACC_EMRH_E39_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_E38_MASK         (0x00000040u)
#define CSL_EDMACC_EMRH_E38_SHIFT        (0x00000006u)
#define CSL_EDMACC_EMRH_E38_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_E37_MASK         (0x00000020u)
#define CSL_EDMACC_EMRH_E37_SHIFT        (0x00000005u)
#define CSL_EDMACC_EMRH_E37_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_E36_MASK         (0x00000010u)
#define CSL_EDMACC_EMRH_E36_SHIFT        (0x00000004u)
#define CSL_EDMACC_EMRH_E36_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_E35_MASK         (0x00000008u)
#define CSL_EDMACC_EMRH_E35_SHIFT        (0x00000003u)
#define CSL_EDMACC_EMRH_E35_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_E34_MASK         (0x00000004u)
#define CSL_EDMACC_EMRH_E34_SHIFT        (0x00000002u)
#define CSL_EDMACC_EMRH_E34_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_E33_MASK         (0x00000002u)
#define CSL_EDMACC_EMRH_E33_SHIFT        (0x00000001u)
#define CSL_EDMACC_EMRH_E33_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_E32_MASK         (0x00000001u)
#define CSL_EDMACC_EMRH_E32_SHIFT        (0x00000000u)
#define CSL_EDMACC_EMRH_E32_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMRH_RESETVAL         (0x00000000u)

/* EMCR */

#define CSL_EDMACC_EMCR_E31_MASK         (0x80000000u)
#define CSL_EDMACC_EMCR_E31_SHIFT        (0x0000001Fu)
#define CSL_EDMACC_EMCR_E31_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMCR_E30_MASK         (0x40000000u)
#define CSL_EDMACC_EMCR_E30_SHIFT        (0x0000001Eu)
#define CSL_EDMACC_EMCR_E30_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMCR_E29_MASK         (0x20000000u)
#define CSL_EDMACC_EMCR_E29_SHIFT        (0x0000001Du)
#define CSL_EDMACC_EMCR_E29_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMCR_E28_MASK         (0x10000000u)
#define CSL_EDMACC_EMCR_E28_SHIFT        (0x0000001Cu)
#define CSL_EDMACC_EMCR_E28_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMCR_E27_MASK         (0x08000000u)
#define CSL_EDMACC_EMCR_E27_SHIFT        (0x0000001Bu)
#define CSL_EDMACC_EMCR_E27_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMCR_E26_MASK         (0x04000000u)
#define CSL_EDMACC_EMCR_E26_SHIFT        (0x0000001Au)
#define CSL_EDMACC_EMCR_E26_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMCR_E25_MASK         (0x02000000u)
#define CSL_EDMACC_EMCR_E25_SHIFT        (0x00000019u)
#define CSL_EDMACC_EMCR_E25_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMCR_E24_MASK         (0x01000000u)
#define CSL_EDMACC_EMCR_E24_SHIFT        (0x00000018u)
#define CSL_EDMACC_EMCR_E24_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMCR_E23_MASK         (0x00800000u)
#define CSL_EDMACC_EMCR_E23_SHIFT        (0x00000017u)
#define CSL_EDMACC_EMCR_E23_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMCR_E22_MASK         (0x00400000u)
#define CSL_EDMACC_EMCR_E22_SHIFT        (0x00000016u)
#define CSL_EDMACC_EMCR_E22_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMCR_E21_MASK         (0x00200000u)
#define CSL_EDMACC_EMCR_E21_SHIFT        (0x00000015u)
#define CSL_EDMACC_EMCR_E21_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMCR_E20_MASK         (0x00100000u)
#define CSL_EDMACC_EMCR_E20_SHIFT        (0x00000014u)
#define CSL_EDMACC_EMCR_E20_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMCR_E19_MASK         (0x00080000u)
#define CSL_EDMACC_EMCR_E19_SHIFT        (0x00000013u)
#define CSL_EDMACC_EMCR_E19_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMCR_E18_MASK         (0x00040000u)
#define CSL_EDMACC_EMCR_E18_SHIFT        (0x00000012u)
#define CSL_EDMACC_EMCR_E18_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMCR_E17_MASK         (0x00020000u)
#define CSL_EDMACC_EMCR_E17_SHIFT        (0x00000011u)
#define CSL_EDMACC_EMCR_E17_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMCR_E16_MASK         (0x00010000u)
#define CSL_EDMACC_EMCR_E16_SHIFT        (0x00000010u)
#define CSL_EDMACC_EMCR_E16_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMCR_E15_MASK         (0x00008000u)
#define CSL_EDMACC_EMCR_E15_SHIFT        (0x0000000Fu)
#define CSL_EDMACC_EMCR_E15_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMCR_E14_MASK         (0x00004000u)
#define CSL_EDMACC_EMCR_E14_SHIFT        (0x0000000Eu)
#define CSL_EDMACC_EMCR_E14_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMCR_E13_MASK         (0x00002000u)
#define CSL_EDMACC_EMCR_E13_SHIFT        (0x0000000Du)
#define CSL_EDMACC_EMCR_E13_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMCR_E12_MASK         (0x00001000u)
#define CSL_EDMACC_EMCR_E12_SHIFT        (0x0000000Cu)
#define CSL_EDMACC_EMCR_E12_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMCR_E11_MASK         (0x00000800u)
#define CSL_EDMACC_EMCR_E11_SHIFT        (0x0000000Bu)
#define CSL_EDMACC_EMCR_E11_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMCR_E10_MASK         (0x00000400u)
#define CSL_EDMACC_EMCR_E10_SHIFT        (0x0000000Au)
#define CSL_EDMACC_EMCR_E10_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EMCR_E9_MASK          (0x00000200u)
#define CSL_EDMACC_EMCR_E9_SHIFT         (0x00000009u)
#define CSL_EDMACC_EMCR_E9_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMCR_E8_MASK          (0x00000100u)
#define CSL_EDMACC_EMCR_E8_SHIFT         (0x00000008u)
#define CSL_EDMACC_EMCR_E8_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMCR_E7_MASK          (0x00000080u)
#define CSL_EDMACC_EMCR_E7_SHIFT         (0x00000007u)
#define CSL_EDMACC_EMCR_E7_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMCR_E6_MASK          (0x00000040u)
#define CSL_EDMACC_EMCR_E6_SHIFT         (0x00000006u)
#define CSL_EDMACC_EMCR_E6_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMCR_E5_MASK          (0x00000020u)
#define CSL_EDMACC_EMCR_E5_SHIFT         (0x00000005u)
#define CSL_EDMACC_EMCR_E5_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMCR_E4_MASK          (0x00000010u)
#define CSL_EDMACC_EMCR_E4_SHIFT         (0x00000004u)
#define CSL_EDMACC_EMCR_E4_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMCR_E3_MASK          (0x00000008u)
#define CSL_EDMACC_EMCR_E3_SHIFT         (0x00000003u)
#define CSL_EDMACC_EMCR_E3_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMCR_E2_MASK          (0x00000004u)
#define CSL_EDMACC_EMCR_E2_SHIFT         (0x00000002u)
#define CSL_EDMACC_EMCR_E2_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMCR_E1_MASK          (0x00000002u)
#define CSL_EDMACC_EMCR_E1_SHIFT         (0x00000001u)
#define CSL_EDMACC_EMCR_E1_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMCR_E0_MASK          (0x00000001u)
#define CSL_EDMACC_EMCR_E0_SHIFT         (0x00000000u)
#define CSL_EDMACC_EMCR_E0_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EMCR_RESETVAL         (0x00000000u)

/* EMCRH */

#define CSL_EDMACC_EMCRH_E63_MASK        (0x80000000u)
#define CSL_EDMACC_EMCRH_E63_SHIFT       (0x0000001Fu)
#define CSL_EDMACC_EMCRH_E63_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_E62_MASK        (0x40000000u)
#define CSL_EDMACC_EMCRH_E62_SHIFT       (0x0000001Eu)
#define CSL_EDMACC_EMCRH_E62_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_E61_MASK        (0x20000000u)
#define CSL_EDMACC_EMCRH_E61_SHIFT       (0x0000001Du)
#define CSL_EDMACC_EMCRH_E61_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_E60_MASK        (0x10000000u)
#define CSL_EDMACC_EMCRH_E60_SHIFT       (0x0000001Cu)
#define CSL_EDMACC_EMCRH_E60_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_E59_MASK        (0x08000000u)
#define CSL_EDMACC_EMCRH_E59_SHIFT       (0x0000001Bu)
#define CSL_EDMACC_EMCRH_E59_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_E58_MASK        (0x04000000u)
#define CSL_EDMACC_EMCRH_E58_SHIFT       (0x0000001Au)
#define CSL_EDMACC_EMCRH_E58_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_E57_MASK        (0x02000000u)
#define CSL_EDMACC_EMCRH_E57_SHIFT       (0x00000019u)
#define CSL_EDMACC_EMCRH_E57_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_E56_MASK        (0x01000000u)
#define CSL_EDMACC_EMCRH_E56_SHIFT       (0x00000018u)
#define CSL_EDMACC_EMCRH_E56_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_E55_MASK        (0x00800000u)
#define CSL_EDMACC_EMCRH_E55_SHIFT       (0x00000017u)
#define CSL_EDMACC_EMCRH_E55_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_E54_MASK        (0x00400000u)
#define CSL_EDMACC_EMCRH_E54_SHIFT       (0x00000016u)
#define CSL_EDMACC_EMCRH_E54_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_E53_MASK        (0x00200000u)
#define CSL_EDMACC_EMCRH_E53_SHIFT       (0x00000015u)
#define CSL_EDMACC_EMCRH_E53_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_E52_MASK        (0x00100000u)
#define CSL_EDMACC_EMCRH_E52_SHIFT       (0x00000014u)
#define CSL_EDMACC_EMCRH_E52_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_E51_MASK        (0x00080000u)
#define CSL_EDMACC_EMCRH_E51_SHIFT       (0x00000013u)
#define CSL_EDMACC_EMCRH_E51_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_E50_MASK        (0x00040000u)
#define CSL_EDMACC_EMCRH_E50_SHIFT       (0x00000012u)
#define CSL_EDMACC_EMCRH_E50_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_E49_MASK        (0x00020000u)
#define CSL_EDMACC_EMCRH_E49_SHIFT       (0x00000011u)
#define CSL_EDMACC_EMCRH_E49_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_E48_MASK        (0x00010000u)
#define CSL_EDMACC_EMCRH_E48_SHIFT       (0x00000010u)
#define CSL_EDMACC_EMCRH_E48_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_E47_MASK        (0x00008000u)
#define CSL_EDMACC_EMCRH_E47_SHIFT       (0x0000000Fu)
#define CSL_EDMACC_EMCRH_E47_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_E46_MASK        (0x00004000u)
#define CSL_EDMACC_EMCRH_E46_SHIFT       (0x0000000Eu)
#define CSL_EDMACC_EMCRH_E46_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_E45_MASK        (0x00002000u)
#define CSL_EDMACC_EMCRH_E45_SHIFT       (0x0000000Du)
#define CSL_EDMACC_EMCRH_E45_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_E44_MASK        (0x00001000u)
#define CSL_EDMACC_EMCRH_E44_SHIFT       (0x0000000Cu)
#define CSL_EDMACC_EMCRH_E44_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_E43_MASK        (0x00000800u)
#define CSL_EDMACC_EMCRH_E43_SHIFT       (0x0000000Bu)
#define CSL_EDMACC_EMCRH_E43_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_E42_MASK        (0x00000400u)
#define CSL_EDMACC_EMCRH_E42_SHIFT       (0x0000000Au)
#define CSL_EDMACC_EMCRH_E42_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_E41_MASK        (0x00000200u)
#define CSL_EDMACC_EMCRH_E41_SHIFT       (0x00000009u)
#define CSL_EDMACC_EMCRH_E41_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_E40_MASK        (0x00000100u)
#define CSL_EDMACC_EMCRH_E40_SHIFT       (0x00000008u)
#define CSL_EDMACC_EMCRH_E40_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_E39_MASK        (0x00000080u)
#define CSL_EDMACC_EMCRH_E39_SHIFT       (0x00000007u)
#define CSL_EDMACC_EMCRH_E39_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_E38_MASK        (0x00000040u)
#define CSL_EDMACC_EMCRH_E38_SHIFT       (0x00000006u)
#define CSL_EDMACC_EMCRH_E38_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_E37_MASK        (0x00000020u)
#define CSL_EDMACC_EMCRH_E37_SHIFT       (0x00000005u)
#define CSL_EDMACC_EMCRH_E37_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_E36_MASK        (0x00000010u)
#define CSL_EDMACC_EMCRH_E36_SHIFT       (0x00000004u)
#define CSL_EDMACC_EMCRH_E36_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_E35_MASK        (0x00000008u)
#define CSL_EDMACC_EMCRH_E35_SHIFT       (0x00000003u)
#define CSL_EDMACC_EMCRH_E35_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_E34_MASK        (0x00000004u)
#define CSL_EDMACC_EMCRH_E34_SHIFT       (0x00000002u)
#define CSL_EDMACC_EMCRH_E34_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_E33_MASK        (0x00000002u)
#define CSL_EDMACC_EMCRH_E33_SHIFT       (0x00000001u)
#define CSL_EDMACC_EMCRH_E33_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_E32_MASK        (0x00000001u)
#define CSL_EDMACC_EMCRH_E32_SHIFT       (0x00000000u)
#define CSL_EDMACC_EMCRH_E32_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EMCRH_RESETVAL        (0x00000000u)

/* QEMR */

#define CSL_EDMACC_QEMR_E7_MASK          (0x00000080u)
#define CSL_EDMACC_QEMR_E7_SHIFT         (0x00000007u)
#define CSL_EDMACC_QEMR_E7_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QEMR_E6_MASK          (0x00000040u)
#define CSL_EDMACC_QEMR_E6_SHIFT         (0x00000006u)
#define CSL_EDMACC_QEMR_E6_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QEMR_E5_MASK          (0x00000020u)
#define CSL_EDMACC_QEMR_E5_SHIFT         (0x00000005u)
#define CSL_EDMACC_QEMR_E5_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QEMR_E4_MASK          (0x00000010u)
#define CSL_EDMACC_QEMR_E4_SHIFT         (0x00000004u)
#define CSL_EDMACC_QEMR_E4_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QEMR_E3_MASK          (0x00000008u)
#define CSL_EDMACC_QEMR_E3_SHIFT         (0x00000003u)
#define CSL_EDMACC_QEMR_E3_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QEMR_E2_MASK          (0x00000004u)
#define CSL_EDMACC_QEMR_E2_SHIFT         (0x00000002u)
#define CSL_EDMACC_QEMR_E2_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QEMR_E1_MASK          (0x00000002u)
#define CSL_EDMACC_QEMR_E1_SHIFT         (0x00000001u)
#define CSL_EDMACC_QEMR_E1_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QEMR_E0_MASK          (0x00000001u)
#define CSL_EDMACC_QEMR_E0_SHIFT         (0x00000000u)
#define CSL_EDMACC_QEMR_E0_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QEMR_RESETVAL         (0x00000000u)

/* QEMCR */

#define CSL_EDMACC_QEMCR_E7_MASK         (0x00000080u)
#define CSL_EDMACC_QEMCR_E7_SHIFT        (0x00000007u)
#define CSL_EDMACC_QEMCR_E7_RESETVAL     (0x00000000u)

#define CSL_EDMACC_QEMCR_E6_MASK         (0x00000040u)
#define CSL_EDMACC_QEMCR_E6_SHIFT        (0x00000006u)
#define CSL_EDMACC_QEMCR_E6_RESETVAL     (0x00000000u)

#define CSL_EDMACC_QEMCR_E5_MASK         (0x00000020u)
#define CSL_EDMACC_QEMCR_E5_SHIFT        (0x00000005u)
#define CSL_EDMACC_QEMCR_E5_RESETVAL     (0x00000000u)

#define CSL_EDMACC_QEMCR_E4_MASK         (0x00000010u)
#define CSL_EDMACC_QEMCR_E4_SHIFT        (0x00000004u)
#define CSL_EDMACC_QEMCR_E4_RESETVAL     (0x00000000u)

#define CSL_EDMACC_QEMCR_E3_MASK         (0x00000008u)
#define CSL_EDMACC_QEMCR_E3_SHIFT        (0x00000003u)
#define CSL_EDMACC_QEMCR_E3_RESETVAL     (0x00000000u)

#define CSL_EDMACC_QEMCR_E2_MASK         (0x00000004u)
#define CSL_EDMACC_QEMCR_E2_SHIFT        (0x00000002u)
#define CSL_EDMACC_QEMCR_E2_RESETVAL     (0x00000000u)

#define CSL_EDMACC_QEMCR_E1_MASK         (0x00000002u)
#define CSL_EDMACC_QEMCR_E1_SHIFT        (0x00000001u)
#define CSL_EDMACC_QEMCR_E1_RESETVAL     (0x00000000u)

#define CSL_EDMACC_QEMCR_E0_MASK         (0x00000001u)
#define CSL_EDMACC_QEMCR_E0_SHIFT        (0x00000000u)
#define CSL_EDMACC_QEMCR_E0_RESETVAL     (0x00000000u)

#define CSL_EDMACC_QEMCR_RESETVAL        (0x00000000u)

/* CCERR */

#define CSL_EDMACC_CCERR_TCCERR_MASK     (0x00010000u)
#define CSL_EDMACC_CCERR_TCCERR_SHIFT    (0x00000010u)
#define CSL_EDMACC_CCERR_TCCERR_RESETVAL (0x00000000u)

#define CSL_EDMACC_CCERR_QTHRXCD1_MASK   (0x00000002u)
#define CSL_EDMACC_CCERR_QTHRXCD1_SHIFT  (0x00000001u)
#define CSL_EDMACC_CCERR_QTHRXCD1_RESETVAL (0x00000000u)

#define CSL_EDMACC_CCERR_QTHRXCD0_MASK   (0x00000001u)
#define CSL_EDMACC_CCERR_QTHRXCD0_SHIFT  (0x00000000u)
#define CSL_EDMACC_CCERR_QTHRXCD0_RESETVAL (0x00000000u)

#define CSL_EDMACC_CCERR_RESETVAL        (0x00000000u)

/* CCERRCLR */

#define CSL_EDMACC_CCERRCLR_TCCERR_MASK  (0x00010000u)
#define CSL_EDMACC_CCERRCLR_TCCERR_SHIFT (0x00000010u)
#define CSL_EDMACC_CCERRCLR_TCCERR_RESETVAL (0x00000000u)

#define CSL_EDMACC_CCERRCLR_QTHRXCD1_MASK (0x00000002u)
#define CSL_EDMACC_CCERRCLR_QTHRXCD1_SHIFT (0x00000001u)
#define CSL_EDMACC_CCERRCLR_QTHRXCD1_RESETVAL (0x00000000u)

#define CSL_EDMACC_CCERRCLR_QTHRXCD0_MASK (0x00000001u)
#define CSL_EDMACC_CCERRCLR_QTHRXCD0_SHIFT (0x00000000u)
#define CSL_EDMACC_CCERRCLR_QTHRXCD0_RESETVAL (0x00000000u)

#define CSL_EDMACC_CCERRCLR_RESETVAL     (0x00000000u)

/* EEVAL */

#define CSL_EDMACC_EEVAL_SET_MASK        (0x00000002u)
#define CSL_EDMACC_EEVAL_SET_SHIFT       (0x00000001u)
#define CSL_EDMACC_EEVAL_SET_RESETVAL    (0x00000000u)

/*----SET Tokens----*/
#define CSL_EDMACC_EEVAL_SET_SET         (0x00000001u)

#define CSL_EDMACC_EEVAL_EVAL_MASK       (0x00000001u)
#define CSL_EDMACC_EEVAL_EVAL_SHIFT      (0x00000000u)
#define CSL_EDMACC_EEVAL_EVAL_RESETVAL   (0x00000000u)

/*----EVAL Tokens----*/
#define CSL_EDMACC_EEVAL_EVAL_EVAL       (0x00000001u)

#define CSL_EDMACC_EEVAL_RESETVAL        (0x00000000u)

/* DRAE */

#define CSL_EDMACC_DRAE_E31_MASK         (0x80000000u)
#define CSL_EDMACC_DRAE_E31_SHIFT        (0x0000001Fu)
#define CSL_EDMACC_DRAE_E31_RESETVAL     (0x00000000u)

#define CSL_EDMACC_DRAE_E30_MASK         (0x40000000u)
#define CSL_EDMACC_DRAE_E30_SHIFT        (0x0000001Eu)
#define CSL_EDMACC_DRAE_E30_RESETVAL     (0x00000000u)

#define CSL_EDMACC_DRAE_E29_MASK         (0x20000000u)
#define CSL_EDMACC_DRAE_E29_SHIFT        (0x0000001Du)
#define CSL_EDMACC_DRAE_E29_RESETVAL     (0x00000000u)

#define CSL_EDMACC_DRAE_E28_MASK         (0x10000000u)
#define CSL_EDMACC_DRAE_E28_SHIFT        (0x0000001Cu)
#define CSL_EDMACC_DRAE_E28_RESETVAL     (0x00000000u)

#define CSL_EDMACC_DRAE_E27_MASK         (0x08000000u)
#define CSL_EDMACC_DRAE_E27_SHIFT        (0x0000001Bu)
#define CSL_EDMACC_DRAE_E27_RESETVAL     (0x00000000u)

#define CSL_EDMACC_DRAE_E26_MASK         (0x04000000u)
#define CSL_EDMACC_DRAE_E26_SHIFT        (0x0000001Au)
#define CSL_EDMACC_DRAE_E26_RESETVAL     (0x00000000u)

#define CSL_EDMACC_DRAE_E25_MASK         (0x02000000u)
#define CSL_EDMACC_DRAE_E25_SHIFT        (0x00000019u)
#define CSL_EDMACC_DRAE_E25_RESETVAL     (0x00000000u)

#define CSL_EDMACC_DRAE_E24_MASK         (0x01000000u)
#define CSL_EDMACC_DRAE_E24_SHIFT        (0x00000018u)
#define CSL_EDMACC_DRAE_E24_RESETVAL     (0x00000000u)

#define CSL_EDMACC_DRAE_E23_MASK         (0x00800000u)
#define CSL_EDMACC_DRAE_E23_SHIFT        (0x00000017u)
#define CSL_EDMACC_DRAE_E23_RESETVAL     (0x00000000u)

#define CSL_EDMACC_DRAE_E22_MASK         (0x00400000u)
#define CSL_EDMACC_DRAE_E22_SHIFT        (0x00000016u)
#define CSL_EDMACC_DRAE_E22_RESETVAL     (0x00000000u)

#define CSL_EDMACC_DRAE_E21_MASK         (0x00200000u)
#define CSL_EDMACC_DRAE_E21_SHIFT        (0x00000015u)
#define CSL_EDMACC_DRAE_E21_RESETVAL     (0x00000000u)

#define CSL_EDMACC_DRAE_E20_MASK         (0x00100000u)
#define CSL_EDMACC_DRAE_E20_SHIFT        (0x00000014u)
#define CSL_EDMACC_DRAE_E20_RESETVAL     (0x00000000u)

#define CSL_EDMACC_DRAE_E19_MASK         (0x00080000u)
#define CSL_EDMACC_DRAE_E19_SHIFT        (0x00000013u)
#define CSL_EDMACC_DRAE_E19_RESETVAL     (0x00000000u)

#define CSL_EDMACC_DRAE_E18_MASK         (0x00040000u)
#define CSL_EDMACC_DRAE_E18_SHIFT        (0x00000012u)
#define CSL_EDMACC_DRAE_E18_RESETVAL     (0x00000000u)

#define CSL_EDMACC_DRAE_E17_MASK         (0x00020000u)
#define CSL_EDMACC_DRAE_E17_SHIFT        (0x00000011u)
#define CSL_EDMACC_DRAE_E17_RESETVAL     (0x00000000u)

#define CSL_EDMACC_DRAE_E16_MASK         (0x00010000u)
#define CSL_EDMACC_DRAE_E16_SHIFT        (0x00000010u)
#define CSL_EDMACC_DRAE_E16_RESETVAL     (0x00000000u)

#define CSL_EDMACC_DRAE_E15_MASK         (0x00008000u)
#define CSL_EDMACC_DRAE_E15_SHIFT        (0x0000000Fu)
#define CSL_EDMACC_DRAE_E15_RESETVAL     (0x00000000u)

#define CSL_EDMACC_DRAE_E14_MASK         (0x00004000u)
#define CSL_EDMACC_DRAE_E14_SHIFT        (0x0000000Eu)
#define CSL_EDMACC_DRAE_E14_RESETVAL     (0x00000000u)

#define CSL_EDMACC_DRAE_E13_MASK         (0x00002000u)
#define CSL_EDMACC_DRAE_E13_SHIFT        (0x0000000Du)
#define CSL_EDMACC_DRAE_E13_RESETVAL     (0x00000000u)

#define CSL_EDMACC_DRAE_E12_MASK         (0x00001000u)
#define CSL_EDMACC_DRAE_E12_SHIFT        (0x0000000Cu)
#define CSL_EDMACC_DRAE_E12_RESETVAL     (0x00000000u)

#define CSL_EDMACC_DRAE_E11_MASK         (0x00000800u)
#define CSL_EDMACC_DRAE_E11_SHIFT        (0x0000000Bu)
#define CSL_EDMACC_DRAE_E11_RESETVAL     (0x00000000u)

#define CSL_EDMACC_DRAE_E10_MASK         (0x00000400u)
#define CSL_EDMACC_DRAE_E10_SHIFT        (0x0000000Au)
#define CSL_EDMACC_DRAE_E10_RESETVAL     (0x00000000u)

#define CSL_EDMACC_DRAE_E9_MASK          (0x00000200u)
#define CSL_EDMACC_DRAE_E9_SHIFT         (0x00000009u)
#define CSL_EDMACC_DRAE_E9_RESETVAL      (0x00000000u)

#define CSL_EDMACC_DRAE_E8_MASK          (0x00000100u)
#define CSL_EDMACC_DRAE_E8_SHIFT         (0x00000008u)
#define CSL_EDMACC_DRAE_E8_RESETVAL      (0x00000000u)

#define CSL_EDMACC_DRAE_E7_MASK          (0x00000080u)
#define CSL_EDMACC_DRAE_E7_SHIFT         (0x00000007u)
#define CSL_EDMACC_DRAE_E7_RESETVAL      (0x00000000u)

#define CSL_EDMACC_DRAE_E6_MASK          (0x00000040u)
#define CSL_EDMACC_DRAE_E6_SHIFT         (0x00000006u)
#define CSL_EDMACC_DRAE_E6_RESETVAL      (0x00000000u)

#define CSL_EDMACC_DRAE_E5_MASK          (0x00000020u)
#define CSL_EDMACC_DRAE_E5_SHIFT         (0x00000005u)
#define CSL_EDMACC_DRAE_E5_RESETVAL      (0x00000000u)

#define CSL_EDMACC_DRAE_E4_MASK          (0x00000010u)
#define CSL_EDMACC_DRAE_E4_SHIFT         (0x00000004u)
#define CSL_EDMACC_DRAE_E4_RESETVAL      (0x00000000u)

#define CSL_EDMACC_DRAE_E3_MASK          (0x00000008u)
#define CSL_EDMACC_DRAE_E3_SHIFT         (0x00000003u)
#define CSL_EDMACC_DRAE_E3_RESETVAL      (0x00000000u)

#define CSL_EDMACC_DRAE_E2_MASK          (0x00000004u)
#define CSL_EDMACC_DRAE_E2_SHIFT         (0x00000002u)
#define CSL_EDMACC_DRAE_E2_RESETVAL      (0x00000000u)

#define CSL_EDMACC_DRAE_E1_MASK          (0x00000002u)
#define CSL_EDMACC_DRAE_E1_SHIFT         (0x00000001u)
#define CSL_EDMACC_DRAE_E1_RESETVAL      (0x00000000u)

#define CSL_EDMACC_DRAE_E0_MASK          (0x00000001u)
#define CSL_EDMACC_DRAE_E0_SHIFT         (0x00000000u)
#define CSL_EDMACC_DRAE_E0_RESETVAL      (0x00000000u)

#define CSL_EDMACC_DRAE_RESETVAL         (0x00000000u)

/* DRAEH */

#define CSL_EDMACC_DRAEH_E63_MASK        (0x80000000u)
#define CSL_EDMACC_DRAEH_E63_SHIFT       (0x0000001Fu)
#define CSL_EDMACC_DRAEH_E63_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_E62_MASK        (0x40000000u)
#define CSL_EDMACC_DRAEH_E62_SHIFT       (0x0000001Eu)
#define CSL_EDMACC_DRAEH_E62_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_E61_MASK        (0x20000000u)
#define CSL_EDMACC_DRAEH_E61_SHIFT       (0x0000001Du)
#define CSL_EDMACC_DRAEH_E61_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_E60_MASK        (0x10000000u)
#define CSL_EDMACC_DRAEH_E60_SHIFT       (0x0000001Cu)
#define CSL_EDMACC_DRAEH_E60_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_E59_MASK        (0x08000000u)
#define CSL_EDMACC_DRAEH_E59_SHIFT       (0x0000001Bu)
#define CSL_EDMACC_DRAEH_E59_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_E58_MASK        (0x04000000u)
#define CSL_EDMACC_DRAEH_E58_SHIFT       (0x0000001Au)
#define CSL_EDMACC_DRAEH_E58_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_E57_MASK        (0x02000000u)
#define CSL_EDMACC_DRAEH_E57_SHIFT       (0x00000019u)
#define CSL_EDMACC_DRAEH_E57_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_E56_MASK        (0x01000000u)
#define CSL_EDMACC_DRAEH_E56_SHIFT       (0x00000018u)
#define CSL_EDMACC_DRAEH_E56_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_E55_MASK        (0x00800000u)
#define CSL_EDMACC_DRAEH_E55_SHIFT       (0x00000017u)
#define CSL_EDMACC_DRAEH_E55_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_E54_MASK        (0x00400000u)
#define CSL_EDMACC_DRAEH_E54_SHIFT       (0x00000016u)
#define CSL_EDMACC_DRAEH_E54_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_E53_MASK        (0x00200000u)
#define CSL_EDMACC_DRAEH_E53_SHIFT       (0x00000015u)
#define CSL_EDMACC_DRAEH_E53_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_E52_MASK        (0x00100000u)
#define CSL_EDMACC_DRAEH_E52_SHIFT       (0x00000014u)
#define CSL_EDMACC_DRAEH_E52_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_E51_MASK        (0x00080000u)
#define CSL_EDMACC_DRAEH_E51_SHIFT       (0x00000013u)
#define CSL_EDMACC_DRAEH_E51_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_E50_MASK        (0x00040000u)
#define CSL_EDMACC_DRAEH_E50_SHIFT       (0x00000012u)
#define CSL_EDMACC_DRAEH_E50_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_E49_MASK        (0x00020000u)
#define CSL_EDMACC_DRAEH_E49_SHIFT       (0x00000011u)
#define CSL_EDMACC_DRAEH_E49_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_E48_MASK        (0x00010000u)
#define CSL_EDMACC_DRAEH_E48_SHIFT       (0x00000010u)
#define CSL_EDMACC_DRAEH_E48_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_E47_MASK        (0x00008000u)
#define CSL_EDMACC_DRAEH_E47_SHIFT       (0x0000000Fu)
#define CSL_EDMACC_DRAEH_E47_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_E46_MASK        (0x00004000u)
#define CSL_EDMACC_DRAEH_E46_SHIFT       (0x0000000Eu)
#define CSL_EDMACC_DRAEH_E46_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_E45_MASK        (0x00002000u)
#define CSL_EDMACC_DRAEH_E45_SHIFT       (0x0000000Du)
#define CSL_EDMACC_DRAEH_E45_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_E44_MASK        (0x00001000u)
#define CSL_EDMACC_DRAEH_E44_SHIFT       (0x0000000Cu)
#define CSL_EDMACC_DRAEH_E44_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_E43_MASK        (0x00000800u)
#define CSL_EDMACC_DRAEH_E43_SHIFT       (0x0000000Bu)
#define CSL_EDMACC_DRAEH_E43_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_E42_MASK        (0x00000400u)
#define CSL_EDMACC_DRAEH_E42_SHIFT       (0x0000000Au)
#define CSL_EDMACC_DRAEH_E42_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_E41_MASK        (0x00000200u)
#define CSL_EDMACC_DRAEH_E41_SHIFT       (0x00000009u)
#define CSL_EDMACC_DRAEH_E41_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_E40_MASK        (0x00000100u)
#define CSL_EDMACC_DRAEH_E40_SHIFT       (0x00000008u)
#define CSL_EDMACC_DRAEH_E40_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_E39_MASK        (0x00000080u)
#define CSL_EDMACC_DRAEH_E39_SHIFT       (0x00000007u)
#define CSL_EDMACC_DRAEH_E39_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_E38_MASK        (0x00000040u)
#define CSL_EDMACC_DRAEH_E38_SHIFT       (0x00000006u)
#define CSL_EDMACC_DRAEH_E38_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_E37_MASK        (0x00000020u)
#define CSL_EDMACC_DRAEH_E37_SHIFT       (0x00000005u)
#define CSL_EDMACC_DRAEH_E37_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_E36_MASK        (0x00000010u)
#define CSL_EDMACC_DRAEH_E36_SHIFT       (0x00000004u)
#define CSL_EDMACC_DRAEH_E36_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_E35_MASK        (0x00000008u)
#define CSL_EDMACC_DRAEH_E35_SHIFT       (0x00000003u)
#define CSL_EDMACC_DRAEH_E35_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_E34_MASK        (0x00000004u)
#define CSL_EDMACC_DRAEH_E34_SHIFT       (0x00000002u)
#define CSL_EDMACC_DRAEH_E34_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_E33_MASK        (0x00000002u)
#define CSL_EDMACC_DRAEH_E33_SHIFT       (0x00000001u)
#define CSL_EDMACC_DRAEH_E33_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_E32_MASK        (0x00000001u)
#define CSL_EDMACC_DRAEH_E32_SHIFT       (0x00000000u)
#define CSL_EDMACC_DRAEH_E32_RESETVAL    (0x00000000u)

#define CSL_EDMACC_DRAEH_RESETVAL        (0x00000000u)

/* QRAE */

#define CSL_EDMACC_QRAE_E7_MASK          (0x00000080u)
#define CSL_EDMACC_QRAE_E7_SHIFT         (0x00000007u)
#define CSL_EDMACC_QRAE_E7_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QRAE_E6_MASK          (0x00000080u)
#define CSL_EDMACC_QRAE_E6_SHIFT         (0x00000007u)
#define CSL_EDMACC_QRAE_E6_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QRAE_E5_MASK          (0x00000080u)
#define CSL_EDMACC_QRAE_E5_SHIFT         (0x00000007u)
#define CSL_EDMACC_QRAE_E5_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QRAE_E4_MASK          (0x00000080u)
#define CSL_EDMACC_QRAE_E4_SHIFT         (0x00000007u)
#define CSL_EDMACC_QRAE_E4_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QRAE_RESERVED_MASK    (0x00000070u)
#define CSL_EDMACC_QRAE_RESERVED_SHIFT   (0x00000004u)
#define CSL_EDMACC_QRAE_RESERVED_RESETVAL (0x00000000u)

#define CSL_EDMACC_QRAE_E3_MASK          (0x00000008u)
#define CSL_EDMACC_QRAE_E3_SHIFT         (0x00000003u)
#define CSL_EDMACC_QRAE_E3_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QRAE_E2_MASK          (0x00000004u)
#define CSL_EDMACC_QRAE_E2_SHIFT         (0x00000002u)
#define CSL_EDMACC_QRAE_E2_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QRAE_E1_MASK          (0x00000002u)
#define CSL_EDMACC_QRAE_E1_SHIFT         (0x00000001u)
#define CSL_EDMACC_QRAE_E1_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QRAE_E0_MASK          (0x00000001u)
#define CSL_EDMACC_QRAE_E0_SHIFT         (0x00000000u)
#define CSL_EDMACC_QRAE_E0_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QRAE_RESETVAL         (0x00000000u)

/* EVT_ENTRY */

#define CSL_EDMACC_EVT_ENTRY_RESV_MASK   (0xFFFFFF00u)
#define CSL_EDMACC_EVT_ENTRY_RESV_SHIFT  (0x00000008u)
#define CSL_EDMACC_EVT_ENTRY_RESV_RESETVAL (0x00000000u)

#define CSL_EDMACC_EVT_ENTRY_EVT_SRC_MASK (0x000000C0u)
#define CSL_EDMACC_EVT_ENTRY_EVT_SRC_SHIFT (0x00000006u)
#define CSL_EDMACC_EVT_ENTRY_EVT_SRC_RESETVAL (0x00000000u)

#define CSL_EDMACC_EVT_ENTRY_EVT_MASK    (0x0000003Fu)
#define CSL_EDMACC_EVT_ENTRY_EVT_SHIFT   (0x00000000u)
#define CSL_EDMACC_EVT_ENTRY_EVT_RESETVAL (0x00000000u)

#define CSL_EDMACC_EVT_ENTRY_RESETVAL    (0x00000000u)

/* QSTAT */

#define CSL_EDMACC_QSTAT_THRXD_MASK      (0x01000000u)
#define CSL_EDMACC_QSTAT_THRXD_SHIFT     (0x00000018u)
#define CSL_EDMACC_QSTAT_THRXD_RESETVAL  (0x00000000u)

#define CSL_EDMACC_QSTAT_RESERVED_MASK   (0x00600000u)
#define CSL_EDMACC_QSTAT_RESERVED_SHIFT  (0x00000015u)
#define CSL_EDMACC_QSTAT_RESERVED_RESETVAL (0x00000000u)

#define CSL_EDMACC_QSTAT_WM_MASK         (0x001F0000u)
#define CSL_EDMACC_QSTAT_WM_SHIFT        (0x00000010u)
#define CSL_EDMACC_QSTAT_WM_RESETVAL     (0x00000000u)

#define CSL_EDMACC_QSTAT_NUMVAL_MASK     (0x00001F00u)
#define CSL_EDMACC_QSTAT_NUMVAL_SHIFT    (0x00000008u)
#define CSL_EDMACC_QSTAT_NUMVAL_RESETVAL (0x00000000u)

#define CSL_EDMACC_QSTAT_STRTPTR_MASK    (0x0000000Fu)
#define CSL_EDMACC_QSTAT_STRTPTR_SHIFT   (0x00000000u)
#define CSL_EDMACC_QSTAT_STRTPTR_RESETVAL (0x00000000u)

#define CSL_EDMACC_QSTAT_RESETVAL        (0x00000000u)

/* QWMTHRA */

#define CSL_EDMACC_QWMTHRA_Q1_MASK       (0x00001F00u)
#define CSL_EDMACC_QWMTHRA_Q1_SHIFT      (0x00000008u)
#define CSL_EDMACC_QWMTHRA_Q1_RESETVAL   (0x00000010u)

#define CSL_EDMACC_QWMTHRA_Q0_MASK       (0x0000001Fu)
#define CSL_EDMACC_QWMTHRA_Q0_SHIFT      (0x00000000u)
#define CSL_EDMACC_QWMTHRA_Q0_RESETVAL   (0x00000010u)

#define CSL_EDMACC_QWMTHRA_RESETVAL      (0x00001010u)

/* QWMTHRB */

#define CSL_EDMACC_QWMTHRB_RESETVAL      (0x00000000u)

/* CCSTAT */

#define CSL_EDMACC_CCSTAT_QUEACTV1_MASK  (0x00020000u)
#define CSL_EDMACC_CCSTAT_QUEACTV1_SHIFT (0x00000011u)
#define CSL_EDMACC_CCSTAT_QUEACTV1_RESETVAL (0x00000000u)

/*----QUEACTV1 Tokens----*/
#define CSL_EDMACC_CCSTAT_QUEACTV1_NONE  (0x00000000u)
#define CSL_EDMACC_CCSTAT_QUEACTV1_ACTIVE (0x00000001u)

#define CSL_EDMACC_CCSTAT_QUEACTV0_MASK  (0x00010000u)
#define CSL_EDMACC_CCSTAT_QUEACTV0_SHIFT (0x00000010u)
#define CSL_EDMACC_CCSTAT_QUEACTV0_RESETVAL (0x00000000u)

/*----QUEACTV0 Tokens----*/
#define CSL_EDMACC_CCSTAT_QUEACTV0_NONE  (0x00000000u)
#define CSL_EDMACC_CCSTAT_QUEACTV0_ACTIVE (0x00000001u)

#define CSL_EDMACC_CCSTAT_COMPACT_MASK   (0x00003F00u)
#define CSL_EDMACC_CCSTAT_COMPACT_SHIFT  (0x00000008u)
#define CSL_EDMACC_CCSTAT_COMPACT_RESETVAL (0x00000000u)

/*----COMPACT Tokens----*/
#define CSL_EDMACC_CCSTAT_COMPACT_NONE   (0x00000000u)

#define CSL_EDMACC_CCSTAT_ACTV_MASK      (0x00000010u)
#define CSL_EDMACC_CCSTAT_ACTV_SHIFT     (0x00000004u)
#define CSL_EDMACC_CCSTAT_ACTV_RESETVAL  (0x00000000u)

/*----ACTV Tokens----*/
#define CSL_EDMACC_CCSTAT_ACTV_IDLE      (0x00000000u)
#define CSL_EDMACC_CCSTAT_ACTV_BUSY      (0x00000001u)

#define CSL_EDMACC_CCSTAT_TRACTV_MASK    (0x00000004u)
#define CSL_EDMACC_CCSTAT_TRACTV_SHIFT   (0x00000002u)
#define CSL_EDMACC_CCSTAT_TRACTV_RESETVAL (0x00000000u)

/*----TRACTV Tokens----*/
#define CSL_EDMACC_CCSTAT_TRACTV_NONE    (0x00000000u)
#define CSL_EDMACC_CCSTAT_TRACTV_ACTIVE  (0x00000001u)

#define CSL_EDMACC_CCSTAT_QEVTACTV_MASK  (0x00000002u)
#define CSL_EDMACC_CCSTAT_QEVTACTV_SHIFT (0x00000001u)
#define CSL_EDMACC_CCSTAT_QEVTACTV_RESETVAL (0x00000000u)

/*----QEVTACTV Tokens----*/
#define CSL_EDMACC_CCSTAT_QEVTACTV_NONE  (0x00000000u)
#define CSL_EDMACC_CCSTAT_QEVTACTV_ACTIVE (0x00000001u)

#define CSL_EDMACC_CCSTAT_EVTACTV_MASK   (0x00000001u)
#define CSL_EDMACC_CCSTAT_EVTACTV_SHIFT  (0x00000000u)
#define CSL_EDMACC_CCSTAT_EVTACTV_RESETVAL (0x00000000u)

/*----EVTACTV Tokens----*/
#define CSL_EDMACC_CCSTAT_EVTACTV_NONE   (0x00000000u)
#define CSL_EDMACC_CCSTAT_EVTACTV_ACTIVE (0x00000001u)

#define CSL_EDMACC_CCSTAT_RESETVAL       (0x00000000u)

/* AETCTL */

#define CSL_EDMACC_AETCTL_EN_MASK        (0x80000000u)
#define CSL_EDMACC_AETCTL_EN_SHIFT       (0x0000001Fu)
#define CSL_EDMACC_AETCTL_EN_RESETVAL    (0x00000000u)

/*----EN Tokens----*/
#define CSL_EDMACC_AETCTL_EN_DISABLE     (0x00000000u)
#define CSL_EDMACC_AETCTL_EN_ENABLE      (0x00000001u)

#define CSL_EDMACC_AETCTL_ENDINT_MASK    (0x00003F00u)
#define CSL_EDMACC_AETCTL_ENDINT_SHIFT   (0x00000008u)
#define CSL_EDMACC_AETCTL_ENDINT_RESETVAL (0x00000000u)

#define CSL_EDMACC_AETCTL_TYPE_MASK      (0x00000040u)
#define CSL_EDMACC_AETCTL_TYPE_SHIFT     (0x00000006u)
#define CSL_EDMACC_AETCTL_TYPE_RESETVAL  (0x00000000u)

/*----TYPE Tokens----*/
#define CSL_EDMACC_AETCTL_TYPE_DMA       (0x00000000u)
#define CSL_EDMACC_AETCTL_TYPE_QDMA      (0x00000001u)

#define CSL_EDMACC_AETCTL_STRTEVT_MASK   (0x0000003Fu)
#define CSL_EDMACC_AETCTL_STRTEVT_SHIFT  (0x00000000u)
#define CSL_EDMACC_AETCTL_STRTEVT_RESETVAL (0x00000000u)

#define CSL_EDMACC_AETCTL_RESETVAL       (0x00000000u)

/* AETSTAT */

#define CSL_EDMACC_AETSTAT_STAT_MASK     (0x00000001u)
#define CSL_EDMACC_AETSTAT_STAT_SHIFT    (0x00000000u)
#define CSL_EDMACC_AETSTAT_STAT_RESETVAL (0x00000000u)

/*----STAT Tokens----*/
#define CSL_EDMACC_AETSTAT_STAT_LOW      (0x00000000u)
#define CSL_EDMACC_AETSTAT_STAT_HIGH     (0x00000001u)

#define CSL_EDMACC_AETSTAT_RESETVAL      (0x00000000u)

/* AETCMD */

#define CSL_EDMACC_AETCMD_CLR_MASK       (0x00000001u)
#define CSL_EDMACC_AETCMD_CLR_SHIFT      (0x00000000u)
#define CSL_EDMACC_AETCMD_CLR_RESETVAL   (0x00000000u)

/*----CLR Tokens----*/
#define CSL_EDMACC_AETCMD_CLR_CLEAR      (0x00000001u)

#define CSL_EDMACC_AETCMD_RESETVAL       (0x00000000u)

/* ER */

#define CSL_EDMACC_ER_E31_MASK           (0x80000000u)
#define CSL_EDMACC_ER_E31_SHIFT          (0x0000001Fu)
#define CSL_EDMACC_ER_E31_RESETVAL       (0x00000000u)

#define CSL_EDMACC_ER_E30_MASK           (0x40000000u)
#define CSL_EDMACC_ER_E30_SHIFT          (0x0000001Eu)
#define CSL_EDMACC_ER_E30_RESETVAL       (0x00000000u)

#define CSL_EDMACC_ER_E29_MASK           (0x20000000u)
#define CSL_EDMACC_ER_E29_SHIFT          (0x0000001Du)
#define CSL_EDMACC_ER_E29_RESETVAL       (0x00000000u)

#define CSL_EDMACC_ER_E28_MASK           (0x10000000u)
#define CSL_EDMACC_ER_E28_SHIFT          (0x0000001Cu)
#define CSL_EDMACC_ER_E28_RESETVAL       (0x00000000u)

#define CSL_EDMACC_ER_E27_MASK           (0x08000000u)
#define CSL_EDMACC_ER_E27_SHIFT          (0x0000001Bu)
#define CSL_EDMACC_ER_E27_RESETVAL       (0x00000000u)

#define CSL_EDMACC_ER_E26_MASK           (0x04000000u)
#define CSL_EDMACC_ER_E26_SHIFT          (0x0000001Au)
#define CSL_EDMACC_ER_E26_RESETVAL       (0x00000000u)

#define CSL_EDMACC_ER_E25_MASK           (0x02000000u)
#define CSL_EDMACC_ER_E25_SHIFT          (0x00000019u)
#define CSL_EDMACC_ER_E25_RESETVAL       (0x00000000u)

#define CSL_EDMACC_ER_E24_MASK           (0x01000000u)
#define CSL_EDMACC_ER_E24_SHIFT          (0x00000018u)
#define CSL_EDMACC_ER_E24_RESETVAL       (0x00000000u)

#define CSL_EDMACC_ER_E23_MASK           (0x00800000u)
#define CSL_EDMACC_ER_E23_SHIFT          (0x00000017u)
#define CSL_EDMACC_ER_E23_RESETVAL       (0x00000000u)

#define CSL_EDMACC_ER_E22_MASK           (0x00400000u)
#define CSL_EDMACC_ER_E22_SHIFT          (0x00000016u)
#define CSL_EDMACC_ER_E22_RESETVAL       (0x00000000u)

#define CSL_EDMACC_ER_E21_MASK           (0x00200000u)
#define CSL_EDMACC_ER_E21_SHIFT          (0x00000015u)
#define CSL_EDMACC_ER_E21_RESETVAL       (0x00000000u)

#define CSL_EDMACC_ER_E20_MASK           (0x00100000u)
#define CSL_EDMACC_ER_E20_SHIFT          (0x00000014u)
#define CSL_EDMACC_ER_E20_RESETVAL       (0x00000000u)

#define CSL_EDMACC_ER_E19_MASK           (0x00080000u)
#define CSL_EDMACC_ER_E19_SHIFT          (0x00000013u)
#define CSL_EDMACC_ER_E19_RESETVAL       (0x00000000u)

#define CSL_EDMACC_ER_E18_MASK           (0x00040000u)
#define CSL_EDMACC_ER_E18_SHIFT          (0x00000012u)
#define CSL_EDMACC_ER_E18_RESETVAL       (0x00000000u)

#define CSL_EDMACC_ER_E17_MASK           (0x00020000u)
#define CSL_EDMACC_ER_E17_SHIFT          (0x00000011u)
#define CSL_EDMACC_ER_E17_RESETVAL       (0x00000000u)

#define CSL_EDMACC_ER_E16_MASK           (0x00010000u)
#define CSL_EDMACC_ER_E16_SHIFT          (0x00000010u)
#define CSL_EDMACC_ER_E16_RESETVAL       (0x00000000u)

#define CSL_EDMACC_ER_E15_MASK           (0x00008000u)
#define CSL_EDMACC_ER_E15_SHIFT          (0x0000000Fu)
#define CSL_EDMACC_ER_E15_RESETVAL       (0x00000000u)

#define CSL_EDMACC_ER_E14_MASK           (0x00004000u)
#define CSL_EDMACC_ER_E14_SHIFT          (0x0000000Eu)
#define CSL_EDMACC_ER_E14_RESETVAL       (0x00000000u)

#define CSL_EDMACC_ER_E13_MASK           (0x00002000u)
#define CSL_EDMACC_ER_E13_SHIFT          (0x0000000Du)
#define CSL_EDMACC_ER_E13_RESETVAL       (0x00000000u)

#define CSL_EDMACC_ER_E12_MASK           (0x00001000u)
#define CSL_EDMACC_ER_E12_SHIFT          (0x0000000Cu)
#define CSL_EDMACC_ER_E12_RESETVAL       (0x00000000u)

#define CSL_EDMACC_ER_E11_MASK           (0x00000800u)
#define CSL_EDMACC_ER_E11_SHIFT          (0x0000000Bu)
#define CSL_EDMACC_ER_E11_RESETVAL       (0x00000000u)

#define CSL_EDMACC_ER_E10_MASK           (0x00000400u)
#define CSL_EDMACC_ER_E10_SHIFT          (0x0000000Au)
#define CSL_EDMACC_ER_E10_RESETVAL       (0x00000000u)

#define CSL_EDMACC_ER_E9_MASK            (0x00000200u)
#define CSL_EDMACC_ER_E9_SHIFT           (0x00000009u)
#define CSL_EDMACC_ER_E9_RESETVAL        (0x00000000u)

#define CSL_EDMACC_ER_E8_MASK            (0x00000100u)
#define CSL_EDMACC_ER_E8_SHIFT           (0x00000008u)
#define CSL_EDMACC_ER_E8_RESETVAL        (0x00000000u)

#define CSL_EDMACC_ER_E7_MASK            (0x00000080u)
#define CSL_EDMACC_ER_E7_SHIFT           (0x00000007u)
#define CSL_EDMACC_ER_E7_RESETVAL        (0x00000000u)

#define CSL_EDMACC_ER_E6_MASK            (0x00000040u)
#define CSL_EDMACC_ER_E6_SHIFT           (0x00000006u)
#define CSL_EDMACC_ER_E6_RESETVAL        (0x00000000u)

#define CSL_EDMACC_ER_E5_MASK            (0x00000020u)
#define CSL_EDMACC_ER_E5_SHIFT           (0x00000005u)
#define CSL_EDMACC_ER_E5_RESETVAL        (0x00000000u)

#define CSL_EDMACC_ER_E4_MASK            (0x00000010u)
#define CSL_EDMACC_ER_E4_SHIFT           (0x00000004u)
#define CSL_EDMACC_ER_E4_RESETVAL        (0x00000000u)

#define CSL_EDMACC_ER_E3_MASK            (0x00000008u)
#define CSL_EDMACC_ER_E3_SHIFT           (0x00000003u)
#define CSL_EDMACC_ER_E3_RESETVAL        (0x00000000u)

#define CSL_EDMACC_ER_E2_MASK            (0x00000004u)
#define CSL_EDMACC_ER_E2_SHIFT           (0x00000002u)
#define CSL_EDMACC_ER_E2_RESETVAL        (0x00000000u)

#define CSL_EDMACC_ER_E1_MASK            (0x00000002u)
#define CSL_EDMACC_ER_E1_SHIFT           (0x00000001u)
#define CSL_EDMACC_ER_E1_RESETVAL        (0x00000000u)

#define CSL_EDMACC_ER_E0_MASK            (0x00000001u)
#define CSL_EDMACC_ER_E0_SHIFT           (0x00000000u)
#define CSL_EDMACC_ER_E0_RESETVAL        (0x00000000u)

#define CSL_EDMACC_ER_RESETVAL           (0x00000000u)

/* ERH */

#define CSL_EDMACC_ERH_E63_MASK          (0x80000000u)
#define CSL_EDMACC_ERH_E63_SHIFT         (0x0000001Fu)
#define CSL_EDMACC_ERH_E63_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_E62_MASK          (0x40000000u)
#define CSL_EDMACC_ERH_E62_SHIFT         (0x0000001Eu)
#define CSL_EDMACC_ERH_E62_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_E61_MASK          (0x20000000u)
#define CSL_EDMACC_ERH_E61_SHIFT         (0x0000001Du)
#define CSL_EDMACC_ERH_E61_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_E60_MASK          (0x10000000u)
#define CSL_EDMACC_ERH_E60_SHIFT         (0x0000001Cu)
#define CSL_EDMACC_ERH_E60_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_E59_MASK          (0x08000000u)
#define CSL_EDMACC_ERH_E59_SHIFT         (0x0000001Bu)
#define CSL_EDMACC_ERH_E59_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_E58_MASK          (0x04000000u)
#define CSL_EDMACC_ERH_E58_SHIFT         (0x0000001Au)
#define CSL_EDMACC_ERH_E58_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_E57_MASK          (0x02000000u)
#define CSL_EDMACC_ERH_E57_SHIFT         (0x00000019u)
#define CSL_EDMACC_ERH_E57_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_E56_MASK          (0x01000000u)
#define CSL_EDMACC_ERH_E56_SHIFT         (0x00000018u)
#define CSL_EDMACC_ERH_E56_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_E55_MASK          (0x00800000u)
#define CSL_EDMACC_ERH_E55_SHIFT         (0x00000017u)
#define CSL_EDMACC_ERH_E55_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_E54_MASK          (0x00400000u)
#define CSL_EDMACC_ERH_E54_SHIFT         (0x00000016u)
#define CSL_EDMACC_ERH_E54_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_E53_MASK          (0x00200000u)
#define CSL_EDMACC_ERH_E53_SHIFT         (0x00000015u)
#define CSL_EDMACC_ERH_E53_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_E52_MASK          (0x00100000u)
#define CSL_EDMACC_ERH_E52_SHIFT         (0x00000014u)
#define CSL_EDMACC_ERH_E52_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_E51_MASK          (0x00080000u)
#define CSL_EDMACC_ERH_E51_SHIFT         (0x00000013u)
#define CSL_EDMACC_ERH_E51_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_E50_MASK          (0x00040000u)
#define CSL_EDMACC_ERH_E50_SHIFT         (0x00000012u)
#define CSL_EDMACC_ERH_E50_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_E49_MASK          (0x00020000u)
#define CSL_EDMACC_ERH_E49_SHIFT         (0x00000011u)
#define CSL_EDMACC_ERH_E49_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_E48_MASK          (0x00010000u)
#define CSL_EDMACC_ERH_E48_SHIFT         (0x00000010u)
#define CSL_EDMACC_ERH_E48_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_E47_MASK          (0x00008000u)
#define CSL_EDMACC_ERH_E47_SHIFT         (0x0000000Fu)
#define CSL_EDMACC_ERH_E47_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_E46_MASK          (0x00004000u)
#define CSL_EDMACC_ERH_E46_SHIFT         (0x0000000Eu)
#define CSL_EDMACC_ERH_E46_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_E45_MASK          (0x00002000u)
#define CSL_EDMACC_ERH_E45_SHIFT         (0x0000000Du)
#define CSL_EDMACC_ERH_E45_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_E44_MASK          (0x00001000u)
#define CSL_EDMACC_ERH_E44_SHIFT         (0x0000000Cu)
#define CSL_EDMACC_ERH_E44_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_E43_MASK          (0x00000800u)
#define CSL_EDMACC_ERH_E43_SHIFT         (0x0000000Bu)
#define CSL_EDMACC_ERH_E43_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_E42_MASK          (0x00000400u)
#define CSL_EDMACC_ERH_E42_SHIFT         (0x0000000Au)
#define CSL_EDMACC_ERH_E42_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_E41_MASK          (0x00000200u)
#define CSL_EDMACC_ERH_E41_SHIFT         (0x00000009u)
#define CSL_EDMACC_ERH_E41_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_E40_MASK          (0x00000100u)
#define CSL_EDMACC_ERH_E40_SHIFT         (0x00000008u)
#define CSL_EDMACC_ERH_E40_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_E39_MASK          (0x00000080u)
#define CSL_EDMACC_ERH_E39_SHIFT         (0x00000007u)
#define CSL_EDMACC_ERH_E39_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_E38_MASK          (0x00000040u)
#define CSL_EDMACC_ERH_E38_SHIFT         (0x00000006u)
#define CSL_EDMACC_ERH_E38_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_E37_MASK          (0x00000020u)
#define CSL_EDMACC_ERH_E37_SHIFT         (0x00000005u)
#define CSL_EDMACC_ERH_E37_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_E36_MASK          (0x00000010u)
#define CSL_EDMACC_ERH_E36_SHIFT         (0x00000004u)
#define CSL_EDMACC_ERH_E36_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_E35_MASK          (0x00000008u)
#define CSL_EDMACC_ERH_E35_SHIFT         (0x00000003u)
#define CSL_EDMACC_ERH_E35_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_E34_MASK          (0x00000004u)
#define CSL_EDMACC_ERH_E34_SHIFT         (0x00000002u)
#define CSL_EDMACC_ERH_E34_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_E33_MASK          (0x00000002u)
#define CSL_EDMACC_ERH_E33_SHIFT         (0x00000001u)
#define CSL_EDMACC_ERH_E33_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_E32_MASK          (0x00000001u)
#define CSL_EDMACC_ERH_E32_SHIFT         (0x00000000u)
#define CSL_EDMACC_ERH_E32_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_RESETVAL          (0x00000000u)

/* ECR */

#define CSL_EDMACC_ECR_E31_MASK          (0x80000000u)
#define CSL_EDMACC_ECR_E31_SHIFT         (0x0000001Fu)
#define CSL_EDMACC_ECR_E31_RESETVAL      (0x00000000u)

/*----E31 Tokens----*/
#define CSL_EDMACC_ECR_E31_CLEAR         (0x00000001u)

#define CSL_EDMACC_ECR_E30_MASK          (0x40000000u)
#define CSL_EDMACC_ECR_E30_SHIFT         (0x0000001Eu)
#define CSL_EDMACC_ECR_E30_RESETVAL      (0x00000000u)

/*----E30 Tokens----*/
#define CSL_EDMACC_ECR_E30_CLEAR         (0x00000001u)

#define CSL_EDMACC_ECR_E29_MASK          (0x20000000u)
#define CSL_EDMACC_ECR_E29_SHIFT         (0x0000001Du)
#define CSL_EDMACC_ECR_E29_RESETVAL      (0x00000000u)

/*----E29 Tokens----*/
#define CSL_EDMACC_ECR_E29_CLEAR         (0x00000001u)

#define CSL_EDMACC_ECR_E28_MASK          (0x10000000u)
#define CSL_EDMACC_ECR_E28_SHIFT         (0x0000001Cu)
#define CSL_EDMACC_ECR_E28_RESETVAL      (0x00000000u)

/*----E28 Tokens----*/
#define CSL_EDMACC_ECR_E28_CLEAR         (0x00000001u)

#define CSL_EDMACC_ECR_E27_MASK          (0x08000000u)
#define CSL_EDMACC_ECR_E27_SHIFT         (0x0000001Bu)
#define CSL_EDMACC_ECR_E27_RESETVAL      (0x00000000u)

/*----E27 Tokens----*/
#define CSL_EDMACC_ECR_E27_CLEAR         (0x00000001u)

#define CSL_EDMACC_ECR_E26_MASK          (0x04000000u)
#define CSL_EDMACC_ECR_E26_SHIFT         (0x0000001Au)
#define CSL_EDMACC_ECR_E26_RESETVAL      (0x00000000u)

/*----E26 Tokens----*/
#define CSL_EDMACC_ECR_E26_CLEAR         (0x00000001u)

#define CSL_EDMACC_ECR_E25_MASK          (0x02000000u)
#define CSL_EDMACC_ECR_E25_SHIFT         (0x00000019u)
#define CSL_EDMACC_ECR_E25_RESETVAL      (0x00000000u)

/*----E25 Tokens----*/
#define CSL_EDMACC_ECR_E25_CLEAR         (0x00000001u)

#define CSL_EDMACC_ECR_E24_MASK          (0x01000000u)
#define CSL_EDMACC_ECR_E24_SHIFT         (0x00000018u)
#define CSL_EDMACC_ECR_E24_RESETVAL      (0x00000000u)

/*----E24 Tokens----*/
#define CSL_EDMACC_ECR_E24_CLEAR         (0x00000001u)

#define CSL_EDMACC_ECR_E23_MASK          (0x00800000u)
#define CSL_EDMACC_ECR_E23_SHIFT         (0x00000017u)
#define CSL_EDMACC_ECR_E23_RESETVAL      (0x00000000u)

/*----E23 Tokens----*/
#define CSL_EDMACC_ECR_E23_CLEAR         (0x00000001u)

#define CSL_EDMACC_ECR_E22_MASK          (0x00400000u)
#define CSL_EDMACC_ECR_E22_SHIFT         (0x00000016u)
#define CSL_EDMACC_ECR_E22_RESETVAL      (0x00000000u)

/*----E22 Tokens----*/
#define CSL_EDMACC_ECR_E22_CLEAR         (0x00000001u)

#define CSL_EDMACC_ECR_E21_MASK          (0x00200000u)
#define CSL_EDMACC_ECR_E21_SHIFT         (0x00000015u)
#define CSL_EDMACC_ECR_E21_RESETVAL      (0x00000000u)

/*----E21 Tokens----*/
#define CSL_EDMACC_ECR_E21_CLEAR         (0x00000001u)

#define CSL_EDMACC_ECR_E20_MASK          (0x00100000u)
#define CSL_EDMACC_ECR_E20_SHIFT         (0x00000014u)
#define CSL_EDMACC_ECR_E20_RESETVAL      (0x00000000u)

/*----E20 Tokens----*/
#define CSL_EDMACC_ECR_E20_CLEAR         (0x00000001u)

#define CSL_EDMACC_ECR_E19_MASK          (0x00080000u)
#define CSL_EDMACC_ECR_E19_SHIFT         (0x00000013u)
#define CSL_EDMACC_ECR_E19_RESETVAL      (0x00000000u)

/*----E19 Tokens----*/
#define CSL_EDMACC_ECR_E19_CLEAR         (0x00000001u)

#define CSL_EDMACC_ECR_E18_MASK          (0x00040000u)
#define CSL_EDMACC_ECR_E18_SHIFT         (0x00000012u)
#define CSL_EDMACC_ECR_E18_RESETVAL      (0x00000000u)

/*----E18 Tokens----*/
#define CSL_EDMACC_ECR_E18_CLEAR         (0x00000001u)

#define CSL_EDMACC_ECR_E17_MASK          (0x00020000u)
#define CSL_EDMACC_ECR_E17_SHIFT         (0x00000011u)
#define CSL_EDMACC_ECR_E17_RESETVAL      (0x00000000u)

/*----E17 Tokens----*/
#define CSL_EDMACC_ECR_E17_CLEAR         (0x00000001u)

#define CSL_EDMACC_ECR_E16_MASK          (0x00010000u)
#define CSL_EDMACC_ECR_E16_SHIFT         (0x00000010u)
#define CSL_EDMACC_ECR_E16_RESETVAL      (0x00000000u)

/*----E16 Tokens----*/
#define CSL_EDMACC_ECR_E16_CLEAR         (0x00000001u)

#define CSL_EDMACC_ECR_E15_MASK          (0x00008000u)
#define CSL_EDMACC_ECR_E15_SHIFT         (0x0000000Fu)
#define CSL_EDMACC_ECR_E15_RESETVAL      (0x00000000u)

/*----E15 Tokens----*/
#define CSL_EDMACC_ECR_E15_CLEAR         (0x00000001u)

#define CSL_EDMACC_ECR_E14_MASK          (0x00004000u)
#define CSL_EDMACC_ECR_E14_SHIFT         (0x0000000Eu)
#define CSL_EDMACC_ECR_E14_RESETVAL      (0x00000000u)

/*----E14 Tokens----*/
#define CSL_EDMACC_ECR_E14_CLEAR         (0x00000001u)

#define CSL_EDMACC_ECR_E13_MASK          (0x00002000u)
#define CSL_EDMACC_ECR_E13_SHIFT         (0x0000000Du)
#define CSL_EDMACC_ECR_E13_RESETVAL      (0x00000000u)

/*----E13 Tokens----*/
#define CSL_EDMACC_ECR_E13_CLEAR         (0x00000001u)

#define CSL_EDMACC_ECR_E12_MASK          (0x00001000u)
#define CSL_EDMACC_ECR_E12_SHIFT         (0x0000000Cu)
#define CSL_EDMACC_ECR_E12_RESETVAL      (0x00000000u)

/*----E12 Tokens----*/
#define CSL_EDMACC_ECR_E12_CLEAR         (0x00000001u)

#define CSL_EDMACC_ECR_E11_MASK          (0x00000800u)
#define CSL_EDMACC_ECR_E11_SHIFT         (0x0000000Bu)
#define CSL_EDMACC_ECR_E11_RESETVAL      (0x00000000u)

/*----E11 Tokens----*/
#define CSL_EDMACC_ECR_E11_CLEAR         (0x00000001u)

#define CSL_EDMACC_ECR_E10_MASK          (0x00000400u)
#define CSL_EDMACC_ECR_E10_SHIFT         (0x0000000Au)
#define CSL_EDMACC_ECR_E10_RESETVAL      (0x00000000u)

/*----E10 Tokens----*/
#define CSL_EDMACC_ECR_E10_CLEAR         (0x00000001u)

#define CSL_EDMACC_ECR_E9_MASK           (0x00000200u)
#define CSL_EDMACC_ECR_E9_SHIFT          (0x00000009u)
#define CSL_EDMACC_ECR_E9_RESETVAL       (0x00000000u)

/*----E9 Tokens----*/
#define CSL_EDMACC_ECR_E9_CLEAR          (0x00000001u)

#define CSL_EDMACC_ECR_E8_MASK           (0x00000100u)
#define CSL_EDMACC_ECR_E8_SHIFT          (0x00000008u)
#define CSL_EDMACC_ECR_E8_RESETVAL       (0x00000000u)

/*----E8 Tokens----*/
#define CSL_EDMACC_ECR_E8_CLEAR          (0x00000001u)

#define CSL_EDMACC_ECR_E7_MASK           (0x00000080u)
#define CSL_EDMACC_ECR_E7_SHIFT          (0x00000007u)
#define CSL_EDMACC_ECR_E7_RESETVAL       (0x00000000u)

/*----E7 Tokens----*/
#define CSL_EDMACC_ECR_E7_CLEAR          (0x00000001u)

#define CSL_EDMACC_ECR_E6_MASK           (0x00000040u)
#define CSL_EDMACC_ECR_E6_SHIFT          (0x00000006u)
#define CSL_EDMACC_ECR_E6_RESETVAL       (0x00000000u)

/*----E6 Tokens----*/
#define CSL_EDMACC_ECR_E6_CLEAR          (0x00000001u)

#define CSL_EDMACC_ECR_E5_MASK           (0x00000020u)
#define CSL_EDMACC_ECR_E5_SHIFT          (0x00000005u)
#define CSL_EDMACC_ECR_E5_RESETVAL       (0x00000000u)

/*----E5 Tokens----*/
#define CSL_EDMACC_ECR_E5_CLEAR          (0x00000001u)

#define CSL_EDMACC_ECR_E4_MASK           (0x00000010u)
#define CSL_EDMACC_ECR_E4_SHIFT          (0x00000004u)
#define CSL_EDMACC_ECR_E4_RESETVAL       (0x00000000u)

/*----E4 Tokens----*/
#define CSL_EDMACC_ECR_E4_CLEAR          (0x00000001u)

#define CSL_EDMACC_ECR_E3_MASK           (0x00000008u)
#define CSL_EDMACC_ECR_E3_SHIFT          (0x00000003u)
#define CSL_EDMACC_ECR_E3_RESETVAL       (0x00000000u)

/*----E3 Tokens----*/
#define CSL_EDMACC_ECR_E3_CLEAR          (0x00000001u)

#define CSL_EDMACC_ECR_E2_MASK           (0x00000004u)
#define CSL_EDMACC_ECR_E2_SHIFT          (0x00000002u)
#define CSL_EDMACC_ECR_E2_RESETVAL       (0x00000000u)

/*----E2 Tokens----*/
#define CSL_EDMACC_ECR_E2_CLEAR          (0x00000001u)

#define CSL_EDMACC_ECR_E1_MASK           (0x00000002u)
#define CSL_EDMACC_ECR_E1_SHIFT          (0x00000001u)
#define CSL_EDMACC_ECR_E1_RESETVAL       (0x00000000u)

/*----E1 Tokens----*/
#define CSL_EDMACC_ECR_E1_CLEAR          (0x00000001u)

#define CSL_EDMACC_ECR_E0_MASK           (0x00000001u)
#define CSL_EDMACC_ECR_E0_SHIFT          (0x00000000u)
#define CSL_EDMACC_ECR_E0_RESETVAL       (0x00000000u)

/*----E0 Tokens----*/
#define CSL_EDMACC_ECR_E0_CLEAR          (0x00000001u)

#define CSL_EDMACC_ECR_RESETVAL          (0x00000000u)

/* ECRH */

#define CSL_EDMACC_ECRH_E63_MASK         (0x80000000u)
#define CSL_EDMACC_ECRH_E63_SHIFT        (0x0000001Fu)
#define CSL_EDMACC_ECRH_E63_RESETVAL     (0x00000000u)

/*----E63 Tokens----*/
#define CSL_EDMACC_ECRH_E63_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_E62_MASK         (0x40000000u)
#define CSL_EDMACC_ECRH_E62_SHIFT        (0x0000001Eu)
#define CSL_EDMACC_ECRH_E62_RESETVAL     (0x00000000u)

/*----E62 Tokens----*/
#define CSL_EDMACC_ECRH_E62_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_E61_MASK         (0x20000000u)
#define CSL_EDMACC_ECRH_E61_SHIFT        (0x0000001Du)
#define CSL_EDMACC_ECRH_E61_RESETVAL     (0x00000000u)

/*----E61 Tokens----*/
#define CSL_EDMACC_ECRH_E61_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_E60_MASK         (0x10000000u)
#define CSL_EDMACC_ECRH_E60_SHIFT        (0x0000001Cu)
#define CSL_EDMACC_ECRH_E60_RESETVAL     (0x00000000u)

/*----E60 Tokens----*/
#define CSL_EDMACC_ECRH_E60_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_E59_MASK         (0x08000000u)
#define CSL_EDMACC_ECRH_E59_SHIFT        (0x0000001Bu)
#define CSL_EDMACC_ECRH_E59_RESETVAL     (0x00000000u)

/*----E59 Tokens----*/
#define CSL_EDMACC_ECRH_E59_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_E58_MASK         (0x04000000u)
#define CSL_EDMACC_ECRH_E58_SHIFT        (0x0000001Au)
#define CSL_EDMACC_ECRH_E58_RESETVAL     (0x00000000u)

/*----E58 Tokens----*/
#define CSL_EDMACC_ECRH_E58_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_E57_MASK         (0x02000000u)
#define CSL_EDMACC_ECRH_E57_SHIFT        (0x00000019u)
#define CSL_EDMACC_ECRH_E57_RESETVAL     (0x00000000u)

/*----E57 Tokens----*/
#define CSL_EDMACC_ECRH_E57_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_E56_MASK         (0x01000000u)
#define CSL_EDMACC_ECRH_E56_SHIFT        (0x00000018u)
#define CSL_EDMACC_ECRH_E56_RESETVAL     (0x00000000u)

/*----E56 Tokens----*/
#define CSL_EDMACC_ECRH_E56_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_E55_MASK         (0x00800000u)
#define CSL_EDMACC_ECRH_E55_SHIFT        (0x00000017u)
#define CSL_EDMACC_ECRH_E55_RESETVAL     (0x00000000u)

/*----E55 Tokens----*/
#define CSL_EDMACC_ECRH_E55_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_E54_MASK         (0x00400000u)
#define CSL_EDMACC_ECRH_E54_SHIFT        (0x00000016u)
#define CSL_EDMACC_ECRH_E54_RESETVAL     (0x00000000u)

/*----E54 Tokens----*/
#define CSL_EDMACC_ECRH_E54_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_E53_MASK         (0x00200000u)
#define CSL_EDMACC_ECRH_E53_SHIFT        (0x00000015u)
#define CSL_EDMACC_ECRH_E53_RESETVAL     (0x00000000u)

/*----E53 Tokens----*/
#define CSL_EDMACC_ECRH_E53_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_E52_MASK         (0x00100000u)
#define CSL_EDMACC_ECRH_E52_SHIFT        (0x00000014u)
#define CSL_EDMACC_ECRH_E52_RESETVAL     (0x00000000u)

/*----E52 Tokens----*/
#define CSL_EDMACC_ECRH_E52_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_E51_MASK         (0x00080000u)
#define CSL_EDMACC_ECRH_E51_SHIFT        (0x00000013u)
#define CSL_EDMACC_ECRH_E51_RESETVAL     (0x00000000u)

/*----E51 Tokens----*/
#define CSL_EDMACC_ECRH_E51_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_E50_MASK         (0x00040000u)
#define CSL_EDMACC_ECRH_E50_SHIFT        (0x00000012u)
#define CSL_EDMACC_ECRH_E50_RESETVAL     (0x00000000u)

/*----E50 Tokens----*/
#define CSL_EDMACC_ECRH_E50_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_E49_MASK         (0x00020000u)
#define CSL_EDMACC_ECRH_E49_SHIFT        (0x00000011u)
#define CSL_EDMACC_ECRH_E49_RESETVAL     (0x00000000u)

/*----E49 Tokens----*/
#define CSL_EDMACC_ECRH_E49_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_E48_MASK         (0x00010000u)
#define CSL_EDMACC_ECRH_E48_SHIFT        (0x00000010u)
#define CSL_EDMACC_ECRH_E48_RESETVAL     (0x00000000u)

/*----E48 Tokens----*/
#define CSL_EDMACC_ECRH_E48_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_E47_MASK         (0x00008000u)
#define CSL_EDMACC_ECRH_E47_SHIFT        (0x0000000Fu)
#define CSL_EDMACC_ECRH_E47_RESETVAL     (0x00000000u)

/*----E47 Tokens----*/
#define CSL_EDMACC_ECRH_E47_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_E46_MASK         (0x00004000u)
#define CSL_EDMACC_ECRH_E46_SHIFT        (0x0000000Eu)
#define CSL_EDMACC_ECRH_E46_RESETVAL     (0x00000000u)

/*----E46 Tokens----*/
#define CSL_EDMACC_ECRH_E46_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_E45_MASK         (0x00002000u)
#define CSL_EDMACC_ECRH_E45_SHIFT        (0x0000000Du)
#define CSL_EDMACC_ECRH_E45_RESETVAL     (0x00000000u)

/*----E45 Tokens----*/
#define CSL_EDMACC_ECRH_E45_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_E44_MASK         (0x00001000u)
#define CSL_EDMACC_ECRH_E44_SHIFT        (0x0000000Cu)
#define CSL_EDMACC_ECRH_E44_RESETVAL     (0x00000000u)

/*----E44 Tokens----*/
#define CSL_EDMACC_ECRH_E44_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_E43_MASK         (0x00000800u)
#define CSL_EDMACC_ECRH_E43_SHIFT        (0x0000000Bu)
#define CSL_EDMACC_ECRH_E43_RESETVAL     (0x00000000u)

/*----E43 Tokens----*/
#define CSL_EDMACC_ECRH_E43_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_E42_MASK         (0x00000400u)
#define CSL_EDMACC_ECRH_E42_SHIFT        (0x0000000Au)
#define CSL_EDMACC_ECRH_E42_RESETVAL     (0x00000000u)

/*----E42 Tokens----*/
#define CSL_EDMACC_ECRH_E42_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_E41_MASK         (0x00000200u)
#define CSL_EDMACC_ECRH_E41_SHIFT        (0x00000009u)
#define CSL_EDMACC_ECRH_E41_RESETVAL     (0x00000000u)

/*----E41 Tokens----*/
#define CSL_EDMACC_ECRH_E41_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_E40_MASK         (0x00000100u)
#define CSL_EDMACC_ECRH_E40_SHIFT        (0x00000008u)
#define CSL_EDMACC_ECRH_E40_RESETVAL     (0x00000000u)

/*----E40 Tokens----*/
#define CSL_EDMACC_ECRH_E40_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_E39_MASK         (0x00000080u)
#define CSL_EDMACC_ECRH_E39_SHIFT        (0x00000007u)
#define CSL_EDMACC_ECRH_E39_RESETVAL     (0x00000000u)

/*----E39 Tokens----*/
#define CSL_EDMACC_ECRH_E39_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_E38_MASK         (0x00000040u)
#define CSL_EDMACC_ECRH_E38_SHIFT        (0x00000006u)
#define CSL_EDMACC_ECRH_E38_RESETVAL     (0x00000000u)

/*----E38 Tokens----*/
#define CSL_EDMACC_ECRH_E38_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_E37_MASK         (0x00000020u)
#define CSL_EDMACC_ECRH_E37_SHIFT        (0x00000005u)
#define CSL_EDMACC_ECRH_E37_RESETVAL     (0x00000000u)

/*----E37 Tokens----*/
#define CSL_EDMACC_ECRH_E37_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_E36_MASK         (0x00000010u)
#define CSL_EDMACC_ECRH_E36_SHIFT        (0x00000004u)
#define CSL_EDMACC_ECRH_E36_RESETVAL     (0x00000000u)

/*----E36 Tokens----*/
#define CSL_EDMACC_ECRH_E36_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_E35_MASK         (0x00000008u)
#define CSL_EDMACC_ECRH_E35_SHIFT        (0x00000003u)
#define CSL_EDMACC_ECRH_E35_RESETVAL     (0x00000000u)

/*----E35 Tokens----*/
#define CSL_EDMACC_ECRH_E35_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_E34_MASK         (0x00000004u)
#define CSL_EDMACC_ECRH_E34_SHIFT        (0x00000002u)
#define CSL_EDMACC_ECRH_E34_RESETVAL     (0x00000000u)

/*----E34 Tokens----*/
#define CSL_EDMACC_ECRH_E34_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_E33_MASK         (0x00000002u)
#define CSL_EDMACC_ECRH_E33_SHIFT        (0x00000001u)
#define CSL_EDMACC_ECRH_E33_RESETVAL     (0x00000000u)

/*----E33 Tokens----*/
#define CSL_EDMACC_ECRH_E33_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_E32_MASK         (0x00000001u)
#define CSL_EDMACC_ECRH_E32_SHIFT        (0x00000000u)
#define CSL_EDMACC_ECRH_E32_RESETVAL     (0x00000000u)

/*----E32 Tokens----*/
#define CSL_EDMACC_ECRH_E32_CLEAR        (0x00000001u)

#define CSL_EDMACC_ECRH_RESETVAL         (0x00000000u)

/* ESR */

#define CSL_EDMACC_ESR_E31_MASK          (0x80000000u)
#define CSL_EDMACC_ESR_E31_SHIFT         (0x0000001Fu)
#define CSL_EDMACC_ESR_E31_RESETVAL      (0x00000000u)

/*----E31 Tokens----*/
#define CSL_EDMACC_ESR_E31_SET           (0x00000001u)

#define CSL_EDMACC_ESR_E30_MASK          (0x40000000u)
#define CSL_EDMACC_ESR_E30_SHIFT         (0x0000001Eu)
#define CSL_EDMACC_ESR_E30_RESETVAL      (0x00000000u)

/*----E30 Tokens----*/
#define CSL_EDMACC_ESR_E30_SET           (0x00000001u)

#define CSL_EDMACC_ESR_E29_MASK          (0x20000000u)
#define CSL_EDMACC_ESR_E29_SHIFT         (0x0000001Du)
#define CSL_EDMACC_ESR_E29_RESETVAL      (0x00000000u)

/*----E29 Tokens----*/
#define CSL_EDMACC_ESR_E29_SET           (0x00000001u)

#define CSL_EDMACC_ESR_E28_MASK          (0x10000000u)
#define CSL_EDMACC_ESR_E28_SHIFT         (0x0000001Cu)
#define CSL_EDMACC_ESR_E28_RESETVAL      (0x00000000u)

/*----E28 Tokens----*/
#define CSL_EDMACC_ESR_E28_SET           (0x00000001u)

#define CSL_EDMACC_ESR_E27_MASK          (0x08000000u)
#define CSL_EDMACC_ESR_E27_SHIFT         (0x0000001Bu)
#define CSL_EDMACC_ESR_E27_RESETVAL      (0x00000000u)

/*----E27 Tokens----*/
#define CSL_EDMACC_ESR_E27_SET           (0x00000001u)

#define CSL_EDMACC_ESR_E26_MASK          (0x04000000u)
#define CSL_EDMACC_ESR_E26_SHIFT         (0x0000001Au)
#define CSL_EDMACC_ESR_E26_RESETVAL      (0x00000000u)

/*----E26 Tokens----*/
#define CSL_EDMACC_ESR_E26_SET           (0x00000001u)

#define CSL_EDMACC_ESR_E25_MASK          (0x02000000u)
#define CSL_EDMACC_ESR_E25_SHIFT         (0x00000019u)
#define CSL_EDMACC_ESR_E25_RESETVAL      (0x00000000u)

/*----E25 Tokens----*/
#define CSL_EDMACC_ESR_E25_SET           (0x00000001u)

#define CSL_EDMACC_ESR_E24_MASK          (0x01000000u)
#define CSL_EDMACC_ESR_E24_SHIFT         (0x00000018u)
#define CSL_EDMACC_ESR_E24_RESETVAL      (0x00000000u)

/*----E24 Tokens----*/
#define CSL_EDMACC_ESR_E24_SET           (0x00000001u)

#define CSL_EDMACC_ESR_E23_MASK          (0x00800000u)
#define CSL_EDMACC_ESR_E23_SHIFT         (0x00000017u)
#define CSL_EDMACC_ESR_E23_RESETVAL      (0x00000000u)

/*----E23 Tokens----*/
#define CSL_EDMACC_ESR_E23_SET           (0x00000001u)

#define CSL_EDMACC_ESR_E22_MASK          (0x00400000u)
#define CSL_EDMACC_ESR_E22_SHIFT         (0x00000016u)
#define CSL_EDMACC_ESR_E22_RESETVAL      (0x00000000u)

/*----E22 Tokens----*/
#define CSL_EDMACC_ESR_E22_SET           (0x00000001u)

#define CSL_EDMACC_ESR_E21_MASK          (0x00200000u)
#define CSL_EDMACC_ESR_E21_SHIFT         (0x00000015u)
#define CSL_EDMACC_ESR_E21_RESETVAL      (0x00000000u)

/*----E21 Tokens----*/
#define CSL_EDMACC_ESR_E21_SET           (0x00000001u)

#define CSL_EDMACC_ESR_E20_MASK          (0x00100000u)
#define CSL_EDMACC_ESR_E20_SHIFT         (0x00000014u)
#define CSL_EDMACC_ESR_E20_RESETVAL      (0x00000000u)

/*----E20 Tokens----*/
#define CSL_EDMACC_ESR_E20_SET           (0x00000001u)

#define CSL_EDMACC_ESR_E19_MASK          (0x00080000u)
#define CSL_EDMACC_ESR_E19_SHIFT         (0x00000013u)
#define CSL_EDMACC_ESR_E19_RESETVAL      (0x00000000u)

/*----E19 Tokens----*/
#define CSL_EDMACC_ESR_E19_SET           (0x00000001u)

#define CSL_EDMACC_ESR_E18_MASK          (0x00040000u)
#define CSL_EDMACC_ESR_E18_SHIFT         (0x00000012u)
#define CSL_EDMACC_ESR_E18_RESETVAL      (0x00000000u)

/*----E18 Tokens----*/
#define CSL_EDMACC_ESR_E18_SET           (0x00000001u)

#define CSL_EDMACC_ESR_E17_MASK          (0x00020000u)
#define CSL_EDMACC_ESR_E17_SHIFT         (0x00000011u)
#define CSL_EDMACC_ESR_E17_RESETVAL      (0x00000000u)

/*----E17 Tokens----*/
#define CSL_EDMACC_ESR_E17_SET           (0x00000001u)

#define CSL_EDMACC_ESR_E16_MASK          (0x00010000u)
#define CSL_EDMACC_ESR_E16_SHIFT         (0x00000010u)
#define CSL_EDMACC_ESR_E16_RESETVAL      (0x00000000u)

/*----E16 Tokens----*/
#define CSL_EDMACC_ESR_E16_SET           (0x00000001u)

#define CSL_EDMACC_ESR_E15_MASK          (0x00008000u)
#define CSL_EDMACC_ESR_E15_SHIFT         (0x0000000Fu)
#define CSL_EDMACC_ESR_E15_RESETVAL      (0x00000000u)

/*----E15 Tokens----*/
#define CSL_EDMACC_ESR_E15_SET           (0x00000001u)

#define CSL_EDMACC_ESR_E14_MASK          (0x00004000u)
#define CSL_EDMACC_ESR_E14_SHIFT         (0x0000000Eu)
#define CSL_EDMACC_ESR_E14_RESETVAL      (0x00000000u)

/*----E14 Tokens----*/
#define CSL_EDMACC_ESR_E14_SET           (0x00000001u)

#define CSL_EDMACC_ESR_E13_MASK          (0x00002000u)
#define CSL_EDMACC_ESR_E13_SHIFT         (0x0000000Du)
#define CSL_EDMACC_ESR_E13_RESETVAL      (0x00000000u)

/*----E13 Tokens----*/
#define CSL_EDMACC_ESR_E13_SET           (0x00000001u)

#define CSL_EDMACC_ESR_E12_MASK          (0x00001000u)
#define CSL_EDMACC_ESR_E12_SHIFT         (0x0000000Cu)
#define CSL_EDMACC_ESR_E12_RESETVAL      (0x00000000u)

/*----E12 Tokens----*/
#define CSL_EDMACC_ESR_E12_SET           (0x00000001u)

#define CSL_EDMACC_ESR_E11_MASK          (0x00000800u)
#define CSL_EDMACC_ESR_E11_SHIFT         (0x0000000Bu)
#define CSL_EDMACC_ESR_E11_RESETVAL      (0x00000000u)

/*----E11 Tokens----*/
#define CSL_EDMACC_ESR_E11_SET           (0x00000001u)

#define CSL_EDMACC_ESR_E10_MASK          (0x00000400u)
#define CSL_EDMACC_ESR_E10_SHIFT         (0x0000000Au)
#define CSL_EDMACC_ESR_E10_RESETVAL      (0x00000000u)

/*----E10 Tokens----*/
#define CSL_EDMACC_ESR_E10_SET           (0x00000001u)

#define CSL_EDMACC_ESR_E9_MASK           (0x00000200u)
#define CSL_EDMACC_ESR_E9_SHIFT          (0x00000009u)
#define CSL_EDMACC_ESR_E9_RESETVAL       (0x00000000u)

/*----E9 Tokens----*/
#define CSL_EDMACC_ESR_E9_SET            (0x00000001u)

#define CSL_EDMACC_ESR_E8_MASK           (0x00000100u)
#define CSL_EDMACC_ESR_E8_SHIFT          (0x00000008u)
#define CSL_EDMACC_ESR_E8_RESETVAL       (0x00000000u)

/*----E8 Tokens----*/
#define CSL_EDMACC_ESR_E8_SET            (0x00000001u)

#define CSL_EDMACC_ESR_E7_MASK           (0x00000080u)
#define CSL_EDMACC_ESR_E7_SHIFT          (0x00000007u)
#define CSL_EDMACC_ESR_E7_RESETVAL       (0x00000000u)

/*----E7 Tokens----*/
#define CSL_EDMACC_ESR_E7_SET            (0x00000001u)

#define CSL_EDMACC_ESR_E6_MASK           (0x00000040u)
#define CSL_EDMACC_ESR_E6_SHIFT          (0x00000006u)
#define CSL_EDMACC_ESR_E6_RESETVAL       (0x00000000u)

/*----E6 Tokens----*/
#define CSL_EDMACC_ESR_E6_SET            (0x00000001u)

#define CSL_EDMACC_ESR_E5_MASK           (0x00000020u)
#define CSL_EDMACC_ESR_E5_SHIFT          (0x00000005u)
#define CSL_EDMACC_ESR_E5_RESETVAL       (0x00000000u)

/*----E5 Tokens----*/
#define CSL_EDMACC_ESR_E5_SET            (0x00000001u)

#define CSL_EDMACC_ESR_E4_MASK           (0x00000010u)
#define CSL_EDMACC_ESR_E4_SHIFT          (0x00000004u)
#define CSL_EDMACC_ESR_E4_RESETVAL       (0x00000000u)

/*----E4 Tokens----*/
#define CSL_EDMACC_ESR_E4_SET            (0x00000001u)

#define CSL_EDMACC_ESR_E3_MASK           (0x00000008u)
#define CSL_EDMACC_ESR_E3_SHIFT          (0x00000003u)
#define CSL_EDMACC_ESR_E3_RESETVAL       (0x00000000u)

/*----E3 Tokens----*/
#define CSL_EDMACC_ESR_E3_SET            (0x00000001u)

#define CSL_EDMACC_ESR_E2_MASK           (0x00000004u)
#define CSL_EDMACC_ESR_E2_SHIFT          (0x00000002u)
#define CSL_EDMACC_ESR_E2_RESETVAL       (0x00000000u)

/*----E2 Tokens----*/
#define CSL_EDMACC_ESR_E2_SET            (0x00000001u)

#define CSL_EDMACC_ESR_E1_MASK           (0x00000002u)
#define CSL_EDMACC_ESR_E1_SHIFT          (0x00000001u)
#define CSL_EDMACC_ESR_E1_RESETVAL       (0x00000000u)

/*----E1 Tokens----*/
#define CSL_EDMACC_ESR_E1_SET            (0x00000001u)

#define CSL_EDMACC_ESR_E0_MASK           (0x00000001u)
#define CSL_EDMACC_ESR_E0_SHIFT          (0x00000000u)
#define CSL_EDMACC_ESR_E0_RESETVAL       (0x00000000u)

/*----E0 Tokens----*/
#define CSL_EDMACC_ESR_E0_SET            (0x00000001u)

#define CSL_EDMACC_ESR_RESETVAL          (0x00000000u)

/* ESRH */

#define CSL_EDMACC_ESRH_E63_MASK         (0x80000000u)
#define CSL_EDMACC_ESRH_E63_SHIFT        (0x0000001Fu)
#define CSL_EDMACC_ESRH_E63_RESETVAL     (0x00000000u)

/*----E63 Tokens----*/
#define CSL_EDMACC_ESRH_E63_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_E62_MASK         (0x40000000u)
#define CSL_EDMACC_ESRH_E62_SHIFT        (0x0000001Eu)
#define CSL_EDMACC_ESRH_E62_RESETVAL     (0x00000000u)

/*----E62 Tokens----*/
#define CSL_EDMACC_ESRH_E62_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_E61_MASK         (0x20000000u)
#define CSL_EDMACC_ESRH_E61_SHIFT        (0x0000001Du)
#define CSL_EDMACC_ESRH_E61_RESETVAL     (0x00000000u)

/*----E61 Tokens----*/
#define CSL_EDMACC_ESRH_E61_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_E60_MASK         (0x10000000u)
#define CSL_EDMACC_ESRH_E60_SHIFT        (0x0000001Cu)
#define CSL_EDMACC_ESRH_E60_RESETVAL     (0x00000000u)

/*----E60 Tokens----*/
#define CSL_EDMACC_ESRH_E60_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_E59_MASK         (0x08000000u)
#define CSL_EDMACC_ESRH_E59_SHIFT        (0x0000001Bu)
#define CSL_EDMACC_ESRH_E59_RESETVAL     (0x00000000u)

/*----E59 Tokens----*/
#define CSL_EDMACC_ESRH_E59_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_E58_MASK         (0x04000000u)
#define CSL_EDMACC_ESRH_E58_SHIFT        (0x0000001Au)
#define CSL_EDMACC_ESRH_E58_RESETVAL     (0x00000000u)

/*----E58 Tokens----*/
#define CSL_EDMACC_ESRH_E58_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_E57_MASK         (0x02000000u)
#define CSL_EDMACC_ESRH_E57_SHIFT        (0x00000019u)
#define CSL_EDMACC_ESRH_E57_RESETVAL     (0x00000000u)

/*----E57 Tokens----*/
#define CSL_EDMACC_ESRH_E57_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_E56_MASK         (0x01000000u)
#define CSL_EDMACC_ESRH_E56_SHIFT        (0x00000018u)
#define CSL_EDMACC_ESRH_E56_RESETVAL     (0x00000000u)

/*----E56 Tokens----*/
#define CSL_EDMACC_ESRH_E56_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_E55_MASK         (0x00800000u)
#define CSL_EDMACC_ESRH_E55_SHIFT        (0x00000017u)
#define CSL_EDMACC_ESRH_E55_RESETVAL     (0x00000000u)

/*----E55 Tokens----*/
#define CSL_EDMACC_ESRH_E55_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_E54_MASK         (0x00400000u)
#define CSL_EDMACC_ESRH_E54_SHIFT        (0x00000016u)
#define CSL_EDMACC_ESRH_E54_RESETVAL     (0x00000000u)

/*----E54 Tokens----*/
#define CSL_EDMACC_ESRH_E54_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_E53_MASK         (0x00200000u)
#define CSL_EDMACC_ESRH_E53_SHIFT        (0x00000015u)
#define CSL_EDMACC_ESRH_E53_RESETVAL     (0x00000000u)

/*----E53 Tokens----*/
#define CSL_EDMACC_ESRH_E53_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_E52_MASK         (0x00100000u)
#define CSL_EDMACC_ESRH_E52_SHIFT        (0x00000014u)
#define CSL_EDMACC_ESRH_E52_RESETVAL     (0x00000000u)

/*----E52 Tokens----*/
#define CSL_EDMACC_ESRH_E52_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_E51_MASK         (0x00080000u)
#define CSL_EDMACC_ESRH_E51_SHIFT        (0x00000013u)
#define CSL_EDMACC_ESRH_E51_RESETVAL     (0x00000000u)

/*----E51 Tokens----*/
#define CSL_EDMACC_ESRH_E51_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_E50_MASK         (0x00040000u)
#define CSL_EDMACC_ESRH_E50_SHIFT        (0x00000012u)
#define CSL_EDMACC_ESRH_E50_RESETVAL     (0x00000000u)

/*----E50 Tokens----*/
#define CSL_EDMACC_ESRH_E50_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_E49_MASK         (0x00020000u)
#define CSL_EDMACC_ESRH_E49_SHIFT        (0x00000011u)
#define CSL_EDMACC_ESRH_E49_RESETVAL     (0x00000000u)

/*----E49 Tokens----*/
#define CSL_EDMACC_ESRH_E49_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_E48_MASK         (0x00010000u)
#define CSL_EDMACC_ESRH_E48_SHIFT        (0x00000010u)
#define CSL_EDMACC_ESRH_E48_RESETVAL     (0x00000000u)

/*----E48 Tokens----*/
#define CSL_EDMACC_ESRH_E48_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_E47_MASK         (0x00008000u)
#define CSL_EDMACC_ESRH_E47_SHIFT        (0x0000000Fu)
#define CSL_EDMACC_ESRH_E47_RESETVAL     (0x00000000u)

/*----E47 Tokens----*/
#define CSL_EDMACC_ESRH_E47_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_E46_MASK         (0x00004000u)
#define CSL_EDMACC_ESRH_E46_SHIFT        (0x0000000Eu)
#define CSL_EDMACC_ESRH_E46_RESETVAL     (0x00000000u)

/*----E46 Tokens----*/
#define CSL_EDMACC_ESRH_E46_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_E45_MASK         (0x00002000u)
#define CSL_EDMACC_ESRH_E45_SHIFT        (0x0000000Du)
#define CSL_EDMACC_ESRH_E45_RESETVAL     (0x00000000u)

/*----E45 Tokens----*/
#define CSL_EDMACC_ESRH_E45_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_E44_MASK         (0x00001000u)
#define CSL_EDMACC_ESRH_E44_SHIFT        (0x0000000Cu)
#define CSL_EDMACC_ESRH_E44_RESETVAL     (0x00000000u)

/*----E44 Tokens----*/
#define CSL_EDMACC_ESRH_E44_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_E43_MASK         (0x00000800u)
#define CSL_EDMACC_ESRH_E43_SHIFT        (0x0000000Bu)
#define CSL_EDMACC_ESRH_E43_RESETVAL     (0x00000000u)

/*----E43 Tokens----*/
#define CSL_EDMACC_ESRH_E43_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_E42_MASK         (0x00000400u)
#define CSL_EDMACC_ESRH_E42_SHIFT        (0x0000000Au)
#define CSL_EDMACC_ESRH_E42_RESETVAL     (0x00000000u)

/*----E42 Tokens----*/
#define CSL_EDMACC_ESRH_E42_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_E41_MASK         (0x00000200u)
#define CSL_EDMACC_ESRH_E41_SHIFT        (0x00000009u)
#define CSL_EDMACC_ESRH_E41_RESETVAL     (0x00000000u)

/*----E41 Tokens----*/
#define CSL_EDMACC_ESRH_E41_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_E40_MASK         (0x00000100u)
#define CSL_EDMACC_ESRH_E40_SHIFT        (0x00000008u)
#define CSL_EDMACC_ESRH_E40_RESETVAL     (0x00000000u)

/*----E40 Tokens----*/
#define CSL_EDMACC_ESRH_E40_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_E39_MASK         (0x00000080u)
#define CSL_EDMACC_ESRH_E39_SHIFT        (0x00000007u)
#define CSL_EDMACC_ESRH_E39_RESETVAL     (0x00000000u)

/*----E39 Tokens----*/
#define CSL_EDMACC_ESRH_E39_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_E38_MASK         (0x00000040u)
#define CSL_EDMACC_ESRH_E38_SHIFT        (0x00000006u)
#define CSL_EDMACC_ESRH_E38_RESETVAL     (0x00000000u)

/*----E38 Tokens----*/
#define CSL_EDMACC_ESRH_E38_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_E37_MASK         (0x00000020u)
#define CSL_EDMACC_ESRH_E37_SHIFT        (0x00000005u)
#define CSL_EDMACC_ESRH_E37_RESETVAL     (0x00000000u)

/*----E37 Tokens----*/
#define CSL_EDMACC_ESRH_E37_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_E36_MASK         (0x00000010u)
#define CSL_EDMACC_ESRH_E36_SHIFT        (0x00000004u)
#define CSL_EDMACC_ESRH_E36_RESETVAL     (0x00000000u)

/*----E36 Tokens----*/
#define CSL_EDMACC_ESRH_E36_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_E35_MASK         (0x00000008u)
#define CSL_EDMACC_ESRH_E35_SHIFT        (0x00000003u)
#define CSL_EDMACC_ESRH_E35_RESETVAL     (0x00000000u)

/*----E35 Tokens----*/
#define CSL_EDMACC_ESRH_E35_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_E34_MASK         (0x00000004u)
#define CSL_EDMACC_ESRH_E34_SHIFT        (0x00000002u)
#define CSL_EDMACC_ESRH_E34_RESETVAL     (0x00000000u)

/*----E34 Tokens----*/
#define CSL_EDMACC_ESRH_E34_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_E33_MASK         (0x00000002u)
#define CSL_EDMACC_ESRH_E33_SHIFT        (0x00000001u)
#define CSL_EDMACC_ESRH_E33_RESETVAL     (0x00000000u)

/*----E33 Tokens----*/
#define CSL_EDMACC_ESRH_E33_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_E32_MASK         (0x00000001u)
#define CSL_EDMACC_ESRH_E32_SHIFT        (0x00000000u)
#define CSL_EDMACC_ESRH_E32_RESETVAL     (0x00000000u)

/*----E32 Tokens----*/
#define CSL_EDMACC_ESRH_E32_SET          (0x00000001u)

#define CSL_EDMACC_ESRH_RESETVAL         (0x00000000u)

/* CER */

#define CSL_EDMACC_CER_E31_MASK          (0x80000000u)
#define CSL_EDMACC_CER_E31_SHIFT         (0x0000001Fu)
#define CSL_EDMACC_CER_E31_RESETVAL      (0x00000000u)

#define CSL_EDMACC_CER_E30_MASK          (0x40000000u)
#define CSL_EDMACC_CER_E30_SHIFT         (0x0000001Eu)
#define CSL_EDMACC_CER_E30_RESETVAL      (0x00000000u)

#define CSL_EDMACC_CER_E29_MASK          (0x20000000u)
#define CSL_EDMACC_CER_E29_SHIFT         (0x0000001Du)
#define CSL_EDMACC_CER_E29_RESETVAL      (0x00000000u)

#define CSL_EDMACC_CER_E28_MASK          (0x10000000u)
#define CSL_EDMACC_CER_E28_SHIFT         (0x0000001Cu)
#define CSL_EDMACC_CER_E28_RESETVAL      (0x00000000u)

#define CSL_EDMACC_CER_E27_MASK          (0x08000000u)
#define CSL_EDMACC_CER_E27_SHIFT         (0x0000001Bu)
#define CSL_EDMACC_CER_E27_RESETVAL      (0x00000000u)

#define CSL_EDMACC_CER_E26_MASK          (0x04000000u)
#define CSL_EDMACC_CER_E26_SHIFT         (0x0000001Au)
#define CSL_EDMACC_CER_E26_RESETVAL      (0x00000000u)

#define CSL_EDMACC_CER_E25_MASK          (0x02000000u)
#define CSL_EDMACC_CER_E25_SHIFT         (0x00000019u)
#define CSL_EDMACC_CER_E25_RESETVAL      (0x00000000u)

#define CSL_EDMACC_CER_E24_MASK          (0x01000000u)
#define CSL_EDMACC_CER_E24_SHIFT         (0x00000018u)
#define CSL_EDMACC_CER_E24_RESETVAL      (0x00000000u)

#define CSL_EDMACC_CER_E23_MASK          (0x00800000u)
#define CSL_EDMACC_CER_E23_SHIFT         (0x00000017u)
#define CSL_EDMACC_CER_E23_RESETVAL      (0x00000000u)

#define CSL_EDMACC_CER_E22_MASK          (0x00400000u)
#define CSL_EDMACC_CER_E22_SHIFT         (0x00000016u)
#define CSL_EDMACC_CER_E22_RESETVAL      (0x00000000u)

#define CSL_EDMACC_CER_E21_MASK          (0x00200000u)
#define CSL_EDMACC_CER_E21_SHIFT         (0x00000015u)
#define CSL_EDMACC_CER_E21_RESETVAL      (0x00000000u)

#define CSL_EDMACC_CER_E20_MASK          (0x00100000u)
#define CSL_EDMACC_CER_E20_SHIFT         (0x00000014u)
#define CSL_EDMACC_CER_E20_RESETVAL      (0x00000000u)

#define CSL_EDMACC_CER_E19_MASK          (0x00080000u)
#define CSL_EDMACC_CER_E19_SHIFT         (0x00000013u)
#define CSL_EDMACC_CER_E19_RESETVAL      (0x00000000u)

#define CSL_EDMACC_CER_E18_MASK          (0x00040000u)
#define CSL_EDMACC_CER_E18_SHIFT         (0x00000012u)
#define CSL_EDMACC_CER_E18_RESETVAL      (0x00000000u)

#define CSL_EDMACC_CER_E17_MASK          (0x00020000u)
#define CSL_EDMACC_CER_E17_SHIFT         (0x00000011u)
#define CSL_EDMACC_CER_E17_RESETVAL      (0x00000000u)

#define CSL_EDMACC_CER_E16_MASK          (0x00010000u)
#define CSL_EDMACC_CER_E16_SHIFT         (0x00000010u)
#define CSL_EDMACC_CER_E16_RESETVAL      (0x00000000u)

#define CSL_EDMACC_CER_E15_MASK          (0x00008000u)
#define CSL_EDMACC_CER_E15_SHIFT         (0x0000000Fu)
#define CSL_EDMACC_CER_E15_RESETVAL      (0x00000000u)

#define CSL_EDMACC_CER_E14_MASK          (0x00004000u)
#define CSL_EDMACC_CER_E14_SHIFT         (0x0000000Eu)
#define CSL_EDMACC_CER_E14_RESETVAL      (0x00000000u)

#define CSL_EDMACC_CER_E13_MASK          (0x00002000u)
#define CSL_EDMACC_CER_E13_SHIFT         (0x0000000Du)
#define CSL_EDMACC_CER_E13_RESETVAL      (0x00000000u)

#define CSL_EDMACC_CER_E12_MASK          (0x00001000u)
#define CSL_EDMACC_CER_E12_SHIFT         (0x0000000Cu)
#define CSL_EDMACC_CER_E12_RESETVAL      (0x00000000u)

#define CSL_EDMACC_CER_E11_MASK          (0x00000800u)
#define CSL_EDMACC_CER_E11_SHIFT         (0x0000000Bu)
#define CSL_EDMACC_CER_E11_RESETVAL      (0x00000000u)

#define CSL_EDMACC_CER_E10_MASK          (0x00000400u)
#define CSL_EDMACC_CER_E10_SHIFT         (0x0000000Au)
#define CSL_EDMACC_CER_E10_RESETVAL      (0x00000000u)

#define CSL_EDMACC_CER_E9_MASK           (0x00000200u)
#define CSL_EDMACC_CER_E9_SHIFT          (0x00000009u)
#define CSL_EDMACC_CER_E9_RESETVAL       (0x00000000u)

#define CSL_EDMACC_CER_E8_MASK           (0x00000100u)
#define CSL_EDMACC_CER_E8_SHIFT          (0x00000008u)
#define CSL_EDMACC_CER_E8_RESETVAL       (0x00000000u)

#define CSL_EDMACC_CER_E7_MASK           (0x00000080u)
#define CSL_EDMACC_CER_E7_SHIFT          (0x00000007u)
#define CSL_EDMACC_CER_E7_RESETVAL       (0x00000000u)

#define CSL_EDMACC_CER_E6_MASK           (0x00000040u)
#define CSL_EDMACC_CER_E6_SHIFT          (0x00000006u)
#define CSL_EDMACC_CER_E6_RESETVAL       (0x00000000u)

#define CSL_EDMACC_CER_E5_MASK           (0x00000020u)
#define CSL_EDMACC_CER_E5_SHIFT          (0x00000005u)
#define CSL_EDMACC_CER_E5_RESETVAL       (0x00000000u)

#define CSL_EDMACC_CER_E4_MASK           (0x00000010u)
#define CSL_EDMACC_CER_E4_SHIFT          (0x00000004u)
#define CSL_EDMACC_CER_E4_RESETVAL       (0x00000000u)

#define CSL_EDMACC_CER_E3_MASK           (0x00000008u)
#define CSL_EDMACC_CER_E3_SHIFT          (0x00000003u)
#define CSL_EDMACC_CER_E3_RESETVAL       (0x00000000u)

#define CSL_EDMACC_CER_E2_MASK           (0x00000004u)
#define CSL_EDMACC_CER_E2_SHIFT          (0x00000002u)
#define CSL_EDMACC_CER_E2_RESETVAL       (0x00000000u)

#define CSL_EDMACC_CER_E1_MASK           (0x00000002u)
#define CSL_EDMACC_CER_E1_SHIFT          (0x00000001u)
#define CSL_EDMACC_CER_E1_RESETVAL       (0x00000000u)

#define CSL_EDMACC_CER_E0_MASK           (0x00000001u)
#define CSL_EDMACC_CER_E0_SHIFT          (0x00000000u)
#define CSL_EDMACC_CER_E0_RESETVAL       (0x00000000u)

#define CSL_EDMACC_CER_RESETVAL          (0x00000000u)

/* CERH */

#define CSL_EDMACC_CERH_E63_MASK         (0x80000000u)
#define CSL_EDMACC_CERH_E63_SHIFT        (0x0000001Fu)
#define CSL_EDMACC_CERH_E63_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_E62_MASK         (0x40000000u)
#define CSL_EDMACC_CERH_E62_SHIFT        (0x0000001Eu)
#define CSL_EDMACC_CERH_E62_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_E61_MASK         (0x20000000u)
#define CSL_EDMACC_CERH_E61_SHIFT        (0x0000001Du)
#define CSL_EDMACC_CERH_E61_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_E60_MASK         (0x10000000u)
#define CSL_EDMACC_CERH_E60_SHIFT        (0x0000001Cu)
#define CSL_EDMACC_CERH_E60_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_E59_MASK         (0x08000000u)
#define CSL_EDMACC_CERH_E59_SHIFT        (0x0000001Bu)
#define CSL_EDMACC_CERH_E59_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_E58_MASK         (0x04000000u)
#define CSL_EDMACC_CERH_E58_SHIFT        (0x0000001Au)
#define CSL_EDMACC_CERH_E58_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_E57_MASK         (0x02000000u)
#define CSL_EDMACC_CERH_E57_SHIFT        (0x00000019u)
#define CSL_EDMACC_CERH_E57_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_E56_MASK         (0x01000000u)
#define CSL_EDMACC_CERH_E56_SHIFT        (0x00000018u)
#define CSL_EDMACC_CERH_E56_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_E55_MASK         (0x00800000u)
#define CSL_EDMACC_CERH_E55_SHIFT        (0x00000017u)
#define CSL_EDMACC_CERH_E55_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_E54_MASK         (0x00400000u)
#define CSL_EDMACC_CERH_E54_SHIFT        (0x00000016u)
#define CSL_EDMACC_CERH_E54_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_E53_MASK         (0x00200000u)
#define CSL_EDMACC_CERH_E53_SHIFT        (0x00000015u)
#define CSL_EDMACC_CERH_E53_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_E52_MASK         (0x00100000u)
#define CSL_EDMACC_CERH_E52_SHIFT        (0x00000014u)
#define CSL_EDMACC_CERH_E52_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_E51_MASK         (0x00080000u)
#define CSL_EDMACC_CERH_E51_SHIFT        (0x00000013u)
#define CSL_EDMACC_CERH_E51_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_E50_MASK         (0x00040000u)
#define CSL_EDMACC_CERH_E50_SHIFT        (0x00000012u)
#define CSL_EDMACC_CERH_E50_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_E49_MASK         (0x00020000u)
#define CSL_EDMACC_CERH_E49_SHIFT        (0x00000011u)
#define CSL_EDMACC_CERH_E49_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_E48_MASK         (0x00010000u)
#define CSL_EDMACC_CERH_E48_SHIFT        (0x00000010u)
#define CSL_EDMACC_CERH_E48_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_E47_MASK         (0x00008000u)
#define CSL_EDMACC_CERH_E47_SHIFT        (0x0000000Fu)
#define CSL_EDMACC_CERH_E47_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_E46_MASK         (0x00004000u)
#define CSL_EDMACC_CERH_E46_SHIFT        (0x0000000Eu)
#define CSL_EDMACC_CERH_E46_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_E45_MASK         (0x00002000u)
#define CSL_EDMACC_CERH_E45_SHIFT        (0x0000000Du)
#define CSL_EDMACC_CERH_E45_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_E44_MASK         (0x00001000u)
#define CSL_EDMACC_CERH_E44_SHIFT        (0x0000000Cu)
#define CSL_EDMACC_CERH_E44_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_E43_MASK         (0x00000800u)
#define CSL_EDMACC_CERH_E43_SHIFT        (0x0000000Bu)
#define CSL_EDMACC_CERH_E43_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_E42_MASK         (0x00000400u)
#define CSL_EDMACC_CERH_E42_SHIFT        (0x0000000Au)
#define CSL_EDMACC_CERH_E42_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_E41_MASK         (0x00000200u)
#define CSL_EDMACC_CERH_E41_SHIFT        (0x00000009u)
#define CSL_EDMACC_CERH_E41_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_E40_MASK         (0x00000100u)
#define CSL_EDMACC_CERH_E40_SHIFT        (0x00000008u)
#define CSL_EDMACC_CERH_E40_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_E39_MASK         (0x00000080u)
#define CSL_EDMACC_CERH_E39_SHIFT        (0x00000007u)
#define CSL_EDMACC_CERH_E39_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_E38_MASK         (0x00000040u)
#define CSL_EDMACC_CERH_E38_SHIFT        (0x00000006u)
#define CSL_EDMACC_CERH_E38_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_E37_MASK         (0x00000020u)
#define CSL_EDMACC_CERH_E37_SHIFT        (0x00000005u)
#define CSL_EDMACC_CERH_E37_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_E36_MASK         (0x00000010u)
#define CSL_EDMACC_CERH_E36_SHIFT        (0x00000004u)
#define CSL_EDMACC_CERH_E36_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_E35_MASK         (0x00000008u)
#define CSL_EDMACC_CERH_E35_SHIFT        (0x00000003u)
#define CSL_EDMACC_CERH_E35_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_E34_MASK         (0x00000004u)
#define CSL_EDMACC_CERH_E34_SHIFT        (0x00000002u)
#define CSL_EDMACC_CERH_E34_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_E33_MASK         (0x00000002u)
#define CSL_EDMACC_CERH_E33_SHIFT        (0x00000001u)
#define CSL_EDMACC_CERH_E33_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_E32_MASK         (0x00000001u)
#define CSL_EDMACC_CERH_E32_SHIFT        (0x00000000u)
#define CSL_EDMACC_CERH_E32_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_RESETVAL         (0x00000000u)

/* EER */

#define CSL_EDMACC_EER_E31_MASK          (0x80000000u)
#define CSL_EDMACC_EER_E31_SHIFT         (0x0000001Fu)
#define CSL_EDMACC_EER_E31_RESETVAL      (0x00000000u)

/*----E31 Tokens----*/
#define CSL_EDMACC_EER_E31_              (0x00000001u)

#define CSL_EDMACC_EER_E30_MASK          (0x40000000u)
#define CSL_EDMACC_EER_E30_SHIFT         (0x0000001Eu)
#define CSL_EDMACC_EER_E30_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EER_E29_MASK          (0x20000000u)
#define CSL_EDMACC_EER_E29_SHIFT         (0x0000001Du)
#define CSL_EDMACC_EER_E29_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EER_E28_MASK          (0x10000000u)
#define CSL_EDMACC_EER_E28_SHIFT         (0x0000001Cu)
#define CSL_EDMACC_EER_E28_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EER_E27_MASK          (0x08000000u)
#define CSL_EDMACC_EER_E27_SHIFT         (0x0000001Bu)
#define CSL_EDMACC_EER_E27_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EER_E26_MASK          (0x04000000u)
#define CSL_EDMACC_EER_E26_SHIFT         (0x0000001Au)
#define CSL_EDMACC_EER_E26_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EER_E25_MASK          (0x02000000u)
#define CSL_EDMACC_EER_E25_SHIFT         (0x00000019u)
#define CSL_EDMACC_EER_E25_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EER_E24_MASK          (0x01000000u)
#define CSL_EDMACC_EER_E24_SHIFT         (0x00000018u)
#define CSL_EDMACC_EER_E24_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EER_E23_MASK          (0x00800000u)
#define CSL_EDMACC_EER_E23_SHIFT         (0x00000017u)
#define CSL_EDMACC_EER_E23_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EER_E22_MASK          (0x00400000u)
#define CSL_EDMACC_EER_E22_SHIFT         (0x00000016u)
#define CSL_EDMACC_EER_E22_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EER_E21_MASK          (0x00200000u)
#define CSL_EDMACC_EER_E21_SHIFT         (0x00000015u)
#define CSL_EDMACC_EER_E21_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EER_E20_MASK          (0x00100000u)
#define CSL_EDMACC_EER_E20_SHIFT         (0x00000014u)
#define CSL_EDMACC_EER_E20_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EER_E19_MASK          (0x00080000u)
#define CSL_EDMACC_EER_E19_SHIFT         (0x00000013u)
#define CSL_EDMACC_EER_E19_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EER_E18_MASK          (0x00040000u)
#define CSL_EDMACC_EER_E18_SHIFT         (0x00000012u)
#define CSL_EDMACC_EER_E18_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EER_E17_MASK          (0x00020000u)
#define CSL_EDMACC_EER_E17_SHIFT         (0x00000011u)
#define CSL_EDMACC_EER_E17_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EER_E16_MASK          (0x00010000u)
#define CSL_EDMACC_EER_E16_SHIFT         (0x00000010u)
#define CSL_EDMACC_EER_E16_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EER_E15_MASK          (0x00008000u)
#define CSL_EDMACC_EER_E15_SHIFT         (0x0000000Fu)
#define CSL_EDMACC_EER_E15_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EER_E14_MASK          (0x00004000u)
#define CSL_EDMACC_EER_E14_SHIFT         (0x0000000Eu)
#define CSL_EDMACC_EER_E14_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EER_E13_MASK          (0x00002000u)
#define CSL_EDMACC_EER_E13_SHIFT         (0x0000000Du)
#define CSL_EDMACC_EER_E13_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EER_E12_MASK          (0x00001000u)
#define CSL_EDMACC_EER_E12_SHIFT         (0x0000000Cu)
#define CSL_EDMACC_EER_E12_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EER_E11_MASK          (0x00000800u)
#define CSL_EDMACC_EER_E11_SHIFT         (0x0000000Bu)
#define CSL_EDMACC_EER_E11_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EER_E10_MASK          (0x00000400u)
#define CSL_EDMACC_EER_E10_SHIFT         (0x0000000Au)
#define CSL_EDMACC_EER_E10_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EER_E9_MASK           (0x00000200u)
#define CSL_EDMACC_EER_E9_SHIFT          (0x00000009u)
#define CSL_EDMACC_EER_E9_RESETVAL       (0x00000000u)

#define CSL_EDMACC_EER_E8_MASK           (0x00000100u)
#define CSL_EDMACC_EER_E8_SHIFT          (0x00000008u)
#define CSL_EDMACC_EER_E8_RESETVAL       (0x00000000u)

#define CSL_EDMACC_EER_E7_MASK           (0x00000080u)
#define CSL_EDMACC_EER_E7_SHIFT          (0x00000007u)
#define CSL_EDMACC_EER_E7_RESETVAL       (0x00000000u)

#define CSL_EDMACC_EER_E6_MASK           (0x00000040u)
#define CSL_EDMACC_EER_E6_SHIFT          (0x00000006u)
#define CSL_EDMACC_EER_E6_RESETVAL       (0x00000000u)

#define CSL_EDMACC_EER_E5_MASK           (0x00000020u)
#define CSL_EDMACC_EER_E5_SHIFT          (0x00000005u)
#define CSL_EDMACC_EER_E5_RESETVAL       (0x00000000u)

#define CSL_EDMACC_EER_E4_MASK           (0x00000010u)
#define CSL_EDMACC_EER_E4_SHIFT          (0x00000004u)
#define CSL_EDMACC_EER_E4_RESETVAL       (0x00000000u)

#define CSL_EDMACC_EER_E3_MASK           (0x00000008u)
#define CSL_EDMACC_EER_E3_SHIFT          (0x00000003u)
#define CSL_EDMACC_EER_E3_RESETVAL       (0x00000000u)

#define CSL_EDMACC_EER_E2_MASK           (0x00000004u)
#define CSL_EDMACC_EER_E2_SHIFT          (0x00000002u)
#define CSL_EDMACC_EER_E2_RESETVAL       (0x00000000u)

#define CSL_EDMACC_EER_E1_MASK           (0x00000002u)
#define CSL_EDMACC_EER_E1_SHIFT          (0x00000001u)
#define CSL_EDMACC_EER_E1_RESETVAL       (0x00000000u)

#define CSL_EDMACC_EER_E0_MASK           (0x00000001u)
#define CSL_EDMACC_EER_E0_SHIFT          (0x00000000u)
#define CSL_EDMACC_EER_E0_RESETVAL       (0x00000000u)

#define CSL_EDMACC_EER_RESETVAL          (0x00000000u)

/* EERH */

#define CSL_EDMACC_EERH_E63_MASK         (0x80000000u)
#define CSL_EDMACC_EERH_E63_SHIFT        (0x0000001Fu)
#define CSL_EDMACC_EERH_E63_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_E62_MASK         (0x40000000u)
#define CSL_EDMACC_EERH_E62_SHIFT        (0x0000001Eu)
#define CSL_EDMACC_EERH_E62_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_E61_MASK         (0x20000000u)
#define CSL_EDMACC_EERH_E61_SHIFT        (0x0000001Du)
#define CSL_EDMACC_EERH_E61_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_E60_MASK         (0x10000000u)
#define CSL_EDMACC_EERH_E60_SHIFT        (0x0000001Cu)
#define CSL_EDMACC_EERH_E60_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_E59_MASK         (0x08000000u)
#define CSL_EDMACC_EERH_E59_SHIFT        (0x0000001Bu)
#define CSL_EDMACC_EERH_E59_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_E58_MASK         (0x04000000u)
#define CSL_EDMACC_EERH_E58_SHIFT        (0x0000001Au)
#define CSL_EDMACC_EERH_E58_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_E57_MASK         (0x02000000u)
#define CSL_EDMACC_EERH_E57_SHIFT        (0x00000019u)
#define CSL_EDMACC_EERH_E57_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_E56_MASK         (0x01000000u)
#define CSL_EDMACC_EERH_E56_SHIFT        (0x00000018u)
#define CSL_EDMACC_EERH_E56_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_E55_MASK         (0x00800000u)
#define CSL_EDMACC_EERH_E55_SHIFT        (0x00000017u)
#define CSL_EDMACC_EERH_E55_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_E54_MASK         (0x00400000u)
#define CSL_EDMACC_EERH_E54_SHIFT        (0x00000016u)
#define CSL_EDMACC_EERH_E54_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_E53_MASK         (0x00200000u)
#define CSL_EDMACC_EERH_E53_SHIFT        (0x00000015u)
#define CSL_EDMACC_EERH_E53_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_E52_MASK         (0x00100000u)
#define CSL_EDMACC_EERH_E52_SHIFT        (0x00000014u)
#define CSL_EDMACC_EERH_E52_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_E51_MASK         (0x00080000u)
#define CSL_EDMACC_EERH_E51_SHIFT        (0x00000013u)
#define CSL_EDMACC_EERH_E51_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_E50_MASK         (0x00040000u)
#define CSL_EDMACC_EERH_E50_SHIFT        (0x00000012u)
#define CSL_EDMACC_EERH_E50_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_E49_MASK         (0x00020000u)
#define CSL_EDMACC_EERH_E49_SHIFT        (0x00000011u)
#define CSL_EDMACC_EERH_E49_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_E48_MASK         (0x00010000u)
#define CSL_EDMACC_EERH_E48_SHIFT        (0x00000010u)
#define CSL_EDMACC_EERH_E48_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_E47_MASK         (0x00008000u)
#define CSL_EDMACC_EERH_E47_SHIFT        (0x0000000Fu)
#define CSL_EDMACC_EERH_E47_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_E46_MASK         (0x00004000u)
#define CSL_EDMACC_EERH_E46_SHIFT        (0x0000000Eu)
#define CSL_EDMACC_EERH_E46_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_E45_MASK         (0x00002000u)
#define CSL_EDMACC_EERH_E45_SHIFT        (0x0000000Du)
#define CSL_EDMACC_EERH_E45_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_E44_MASK         (0x00001000u)
#define CSL_EDMACC_EERH_E44_SHIFT        (0x0000000Cu)
#define CSL_EDMACC_EERH_E44_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_E43_MASK         (0x00000800u)
#define CSL_EDMACC_EERH_E43_SHIFT        (0x0000000Bu)
#define CSL_EDMACC_EERH_E43_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_E42_MASK         (0x00000400u)
#define CSL_EDMACC_EERH_E42_SHIFT        (0x0000000Au)
#define CSL_EDMACC_EERH_E42_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_E41_MASK         (0x00000200u)
#define CSL_EDMACC_EERH_E41_SHIFT        (0x00000009u)
#define CSL_EDMACC_EERH_E41_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_E40_MASK         (0x00000100u)
#define CSL_EDMACC_EERH_E40_SHIFT        (0x00000008u)
#define CSL_EDMACC_EERH_E40_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_E39_MASK         (0x00000080u)
#define CSL_EDMACC_EERH_E39_SHIFT        (0x00000007u)
#define CSL_EDMACC_EERH_E39_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_E38_MASK         (0x00000040u)
#define CSL_EDMACC_EERH_E38_SHIFT        (0x00000006u)
#define CSL_EDMACC_EERH_E38_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_E37_MASK         (0x00000020u)
#define CSL_EDMACC_EERH_E37_SHIFT        (0x00000005u)
#define CSL_EDMACC_EERH_E37_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_E36_MASK         (0x00000010u)
#define CSL_EDMACC_EERH_E36_SHIFT        (0x00000004u)
#define CSL_EDMACC_EERH_E36_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_E35_MASK         (0x00000008u)
#define CSL_EDMACC_EERH_E35_SHIFT        (0x00000003u)
#define CSL_EDMACC_EERH_E35_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_E34_MASK         (0x00000004u)
#define CSL_EDMACC_EERH_E34_SHIFT        (0x00000002u)
#define CSL_EDMACC_EERH_E34_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_E33_MASK         (0x00000002u)
#define CSL_EDMACC_EERH_E33_SHIFT        (0x00000001u)
#define CSL_EDMACC_EERH_E33_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_E32_MASK         (0x00000001u)
#define CSL_EDMACC_EERH_E32_SHIFT        (0x00000000u)
#define CSL_EDMACC_EERH_E32_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_RESETVAL         (0x00000000u)

/* EECR */

#define CSL_EDMACC_EECR_E31_MASK         (0x80000000u)
#define CSL_EDMACC_EECR_E31_SHIFT        (0x0000001Fu)
#define CSL_EDMACC_EECR_E31_RESETVAL     (0x00000000u)

/*----E31 Tokens----*/
#define CSL_EDMACC_EECR_E31_CLEAR        (0x00000001u)

#define CSL_EDMACC_EECR_E30_MASK         (0x40000000u)
#define CSL_EDMACC_EECR_E30_SHIFT        (0x0000001Eu)
#define CSL_EDMACC_EECR_E30_RESETVAL     (0x00000000u)

/*----E30 Tokens----*/
#define CSL_EDMACC_EECR_E30_CLEAR        (0x00000001u)

#define CSL_EDMACC_EECR_E29_MASK         (0x20000000u)
#define CSL_EDMACC_EECR_E29_SHIFT        (0x0000001Du)
#define CSL_EDMACC_EECR_E29_RESETVAL     (0x00000000u)

/*----E29 Tokens----*/
#define CSL_EDMACC_EECR_E29_CLEAR        (0x00000001u)

#define CSL_EDMACC_EECR_E28_MASK         (0x10000000u)
#define CSL_EDMACC_EECR_E28_SHIFT        (0x0000001Cu)
#define CSL_EDMACC_EECR_E28_RESETVAL     (0x00000000u)

/*----E28 Tokens----*/
#define CSL_EDMACC_EECR_E28_CLEAR        (0x00000001u)

#define CSL_EDMACC_EECR_E27_MASK         (0x08000000u)
#define CSL_EDMACC_EECR_E27_SHIFT        (0x0000001Bu)
#define CSL_EDMACC_EECR_E27_RESETVAL     (0x00000000u)

/*----E27 Tokens----*/
#define CSL_EDMACC_EECR_E27_CLEAR        (0x00000001u)

#define CSL_EDMACC_EECR_E26_MASK         (0x04000000u)
#define CSL_EDMACC_EECR_E26_SHIFT        (0x0000001Au)
#define CSL_EDMACC_EECR_E26_RESETVAL     (0x00000000u)

/*----E26 Tokens----*/
#define CSL_EDMACC_EECR_E26_CLEAR        (0x00000001u)

#define CSL_EDMACC_EECR_E25_MASK         (0x02000000u)
#define CSL_EDMACC_EECR_E25_SHIFT        (0x00000019u)
#define CSL_EDMACC_EECR_E25_RESETVAL     (0x00000000u)

/*----E25 Tokens----*/
#define CSL_EDMACC_EECR_E25_CLEAR        (0x00000001u)

#define CSL_EDMACC_EECR_E24_MASK         (0x01000000u)
#define CSL_EDMACC_EECR_E24_SHIFT        (0x00000018u)
#define CSL_EDMACC_EECR_E24_RESETVAL     (0x00000000u)

/*----E24 Tokens----*/
#define CSL_EDMACC_EECR_E24_CLEAR        (0x00000001u)

#define CSL_EDMACC_EECR_E23_MASK         (0x00800000u)
#define CSL_EDMACC_EECR_E23_SHIFT        (0x00000017u)
#define CSL_EDMACC_EECR_E23_RESETVAL     (0x00000000u)

/*----E23 Tokens----*/
#define CSL_EDMACC_EECR_E23_CLEAR        (0x00000001u)

#define CSL_EDMACC_EECR_E22_MASK         (0x00400000u)
#define CSL_EDMACC_EECR_E22_SHIFT        (0x00000016u)
#define CSL_EDMACC_EECR_E22_RESETVAL     (0x00000000u)

/*----E22 Tokens----*/
#define CSL_EDMACC_EECR_E22_CLEAR        (0x00000001u)

#define CSL_EDMACC_EECR_E21_MASK         (0x00200000u)
#define CSL_EDMACC_EECR_E21_SHIFT        (0x00000015u)
#define CSL_EDMACC_EECR_E21_RESETVAL     (0x00000000u)

/*----E21 Tokens----*/
#define CSL_EDMACC_EECR_E21_CLEAR        (0x00000001u)

#define CSL_EDMACC_EECR_E20_MASK         (0x00100000u)
#define CSL_EDMACC_EECR_E20_SHIFT        (0x00000014u)
#define CSL_EDMACC_EECR_E20_RESETVAL     (0x00000000u)

/*----E20 Tokens----*/
#define CSL_EDMACC_EECR_E20_CLEAR        (0x00000001u)

#define CSL_EDMACC_EECR_E19_MASK         (0x00080000u)
#define CSL_EDMACC_EECR_E19_SHIFT        (0x00000013u)
#define CSL_EDMACC_EECR_E19_RESETVAL     (0x00000000u)

/*----E19 Tokens----*/
#define CSL_EDMACC_EECR_E19_CLEAR        (0x00000001u)

#define CSL_EDMACC_EECR_E18_MASK         (0x00040000u)
#define CSL_EDMACC_EECR_E18_SHIFT        (0x00000012u)
#define CSL_EDMACC_EECR_E18_RESETVAL     (0x00000000u)

/*----E18 Tokens----*/
#define CSL_EDMACC_EECR_E18_CLEAR        (0x00000001u)

#define CSL_EDMACC_EECR_E17_MASK         (0x00020000u)
#define CSL_EDMACC_EECR_E17_SHIFT        (0x00000011u)
#define CSL_EDMACC_EECR_E17_RESETVAL     (0x00000000u)

/*----E17 Tokens----*/
#define CSL_EDMACC_EECR_E17_CLEAR        (0x00000001u)

#define CSL_EDMACC_EECR_E16_MASK         (0x00010000u)
#define CSL_EDMACC_EECR_E16_SHIFT        (0x00000010u)
#define CSL_EDMACC_EECR_E16_RESETVAL     (0x00000000u)

/*----E16 Tokens----*/
#define CSL_EDMACC_EECR_E16_CLEAR        (0x00000001u)

#define CSL_EDMACC_EECR_E15_MASK         (0x00008000u)
#define CSL_EDMACC_EECR_E15_SHIFT        (0x0000000Fu)
#define CSL_EDMACC_EECR_E15_RESETVAL     (0x00000000u)

/*----E15 Tokens----*/
#define CSL_EDMACC_EECR_E15_CLEAR        (0x00000001u)

#define CSL_EDMACC_EECR_E14_MASK         (0x00004000u)
#define CSL_EDMACC_EECR_E14_SHIFT        (0x0000000Eu)
#define CSL_EDMACC_EECR_E14_RESETVAL     (0x00000000u)

/*----E14 Tokens----*/
#define CSL_EDMACC_EECR_E14_CLEAR        (0x00000001u)

#define CSL_EDMACC_EECR_E13_MASK         (0x00002000u)
#define CSL_EDMACC_EECR_E13_SHIFT        (0x0000000Du)
#define CSL_EDMACC_EECR_E13_RESETVAL     (0x00000000u)

/*----E13 Tokens----*/
#define CSL_EDMACC_EECR_E13_CLEAR        (0x00000001u)

#define CSL_EDMACC_EECR_E12_MASK         (0x00001000u)
#define CSL_EDMACC_EECR_E12_SHIFT        (0x0000000Cu)
#define CSL_EDMACC_EECR_E12_RESETVAL     (0x00000000u)

/*----E12 Tokens----*/
#define CSL_EDMACC_EECR_E12_CLEAR        (0x00000001u)

#define CSL_EDMACC_EECR_E11_MASK         (0x00000800u)
#define CSL_EDMACC_EECR_E11_SHIFT        (0x0000000Bu)
#define CSL_EDMACC_EECR_E11_RESETVAL     (0x00000000u)

/*----E11 Tokens----*/
#define CSL_EDMACC_EECR_E11_CLEAR        (0x00000001u)

#define CSL_EDMACC_EECR_E10_MASK         (0x00000400u)
#define CSL_EDMACC_EECR_E10_SHIFT        (0x0000000Au)
#define CSL_EDMACC_EECR_E10_RESETVAL     (0x00000000u)

/*----E10 Tokens----*/
#define CSL_EDMACC_EECR_E10_CLEAR        (0x00000001u)

#define CSL_EDMACC_EECR_E9_MASK          (0x00000200u)
#define CSL_EDMACC_EECR_E9_SHIFT         (0x00000009u)
#define CSL_EDMACC_EECR_E9_RESETVAL      (0x00000000u)

/*----E9 Tokens----*/
#define CSL_EDMACC_EECR_E9_CLEAR         (0x00000001u)

#define CSL_EDMACC_EECR_E8_MASK          (0x00000100u)
#define CSL_EDMACC_EECR_E8_SHIFT         (0x00000008u)
#define CSL_EDMACC_EECR_E8_RESETVAL      (0x00000000u)

/*----E8 Tokens----*/
#define CSL_EDMACC_EECR_E8_CLEAR         (0x00000001u)

#define CSL_EDMACC_EECR_E7_MASK          (0x00000080u)
#define CSL_EDMACC_EECR_E7_SHIFT         (0x00000007u)
#define CSL_EDMACC_EECR_E7_RESETVAL      (0x00000000u)

/*----E7 Tokens----*/
#define CSL_EDMACC_EECR_E7_CLEAR         (0x00000001u)

#define CSL_EDMACC_EECR_E6_MASK          (0x00000040u)
#define CSL_EDMACC_EECR_E6_SHIFT         (0x00000006u)
#define CSL_EDMACC_EECR_E6_RESETVAL      (0x00000000u)

/*----E6 Tokens----*/
#define CSL_EDMACC_EECR_E6_CLEAR         (0x00000001u)

#define CSL_EDMACC_EECR_E5_MASK          (0x00000020u)
#define CSL_EDMACC_EECR_E5_SHIFT         (0x00000005u)
#define CSL_EDMACC_EECR_E5_RESETVAL      (0x00000000u)

/*----E5 Tokens----*/
#define CSL_EDMACC_EECR_E5_CLEAR         (0x00000001u)

#define CSL_EDMACC_EECR_E4_MASK          (0x00000010u)
#define CSL_EDMACC_EECR_E4_SHIFT         (0x00000004u)
#define CSL_EDMACC_EECR_E4_RESETVAL      (0x00000000u)

/*----E4 Tokens----*/
#define CSL_EDMACC_EECR_E4_CLEAR         (0x00000001u)

#define CSL_EDMACC_EECR_E3_MASK          (0x00000008u)
#define CSL_EDMACC_EECR_E3_SHIFT         (0x00000003u)
#define CSL_EDMACC_EECR_E3_RESETVAL      (0x00000000u)

/*----E3 Tokens----*/
#define CSL_EDMACC_EECR_E3_CLEAR         (0x00000001u)

#define CSL_EDMACC_EECR_E2_MASK          (0x00000004u)
#define CSL_EDMACC_EECR_E2_SHIFT         (0x00000002u)
#define CSL_EDMACC_EECR_E2_RESETVAL      (0x00000000u)

/*----E2 Tokens----*/
#define CSL_EDMACC_EECR_E2_CLEAR         (0x00000001u)

#define CSL_EDMACC_EECR_E1_MASK          (0x00000002u)
#define CSL_EDMACC_EECR_E1_SHIFT         (0x00000001u)
#define CSL_EDMACC_EECR_E1_RESETVAL      (0x00000000u)

/*----E1 Tokens----*/
#define CSL_EDMACC_EECR_E1_CLEAR         (0x00000001u)

#define CSL_EDMACC_EECR_E0_MASK          (0x00000001u)
#define CSL_EDMACC_EECR_E0_SHIFT         (0x00000000u)
#define CSL_EDMACC_EECR_E0_RESETVAL      (0x00000000u)

/*----E0 Tokens----*/
#define CSL_EDMACC_EECR_E0_CLEAR         (0x00000001u)

#define CSL_EDMACC_EECR_RESETVAL         (0x00000000u)

/* EECRH */

#define CSL_EDMACC_EECRH_E63_MASK        (0x80000000u)
#define CSL_EDMACC_EECRH_E63_SHIFT       (0x0000001Fu)
#define CSL_EDMACC_EECRH_E63_RESETVAL    (0x00000000u)

/*----E63 Tokens----*/
#define CSL_EDMACC_EECRH_E63_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_E62_MASK        (0x40000000u)
#define CSL_EDMACC_EECRH_E62_SHIFT       (0x0000001Eu)
#define CSL_EDMACC_EECRH_E62_RESETVAL    (0x00000000u)

/*----E62 Tokens----*/
#define CSL_EDMACC_EECRH_E62_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_E61_MASK        (0x20000000u)
#define CSL_EDMACC_EECRH_E61_SHIFT       (0x0000001Du)
#define CSL_EDMACC_EECRH_E61_RESETVAL    (0x00000000u)

/*----E61 Tokens----*/
#define CSL_EDMACC_EECRH_E61_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_E60_MASK        (0x10000000u)
#define CSL_EDMACC_EECRH_E60_SHIFT       (0x0000001Cu)
#define CSL_EDMACC_EECRH_E60_RESETVAL    (0x00000000u)

/*----E60 Tokens----*/
#define CSL_EDMACC_EECRH_E60_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_E59_MASK        (0x08000000u)
#define CSL_EDMACC_EECRH_E59_SHIFT       (0x0000001Bu)
#define CSL_EDMACC_EECRH_E59_RESETVAL    (0x00000000u)

/*----E59 Tokens----*/
#define CSL_EDMACC_EECRH_E59_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_E58_MASK        (0x04000000u)
#define CSL_EDMACC_EECRH_E58_SHIFT       (0x0000001Au)
#define CSL_EDMACC_EECRH_E58_RESETVAL    (0x00000000u)

/*----E58 Tokens----*/
#define CSL_EDMACC_EECRH_E58_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_E57_MASK        (0x02000000u)
#define CSL_EDMACC_EECRH_E57_SHIFT       (0x00000019u)
#define CSL_EDMACC_EECRH_E57_RESETVAL    (0x00000000u)

/*----E57 Tokens----*/
#define CSL_EDMACC_EECRH_E57_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_E56_MASK        (0x01000000u)
#define CSL_EDMACC_EECRH_E56_SHIFT       (0x00000018u)
#define CSL_EDMACC_EECRH_E56_RESETVAL    (0x00000000u)

/*----E56 Tokens----*/
#define CSL_EDMACC_EECRH_E56_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_E55_MASK        (0x00800000u)
#define CSL_EDMACC_EECRH_E55_SHIFT       (0x00000017u)
#define CSL_EDMACC_EECRH_E55_RESETVAL    (0x00000000u)

/*----E55 Tokens----*/
#define CSL_EDMACC_EECRH_E55_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_E54_MASK        (0x00400000u)
#define CSL_EDMACC_EECRH_E54_SHIFT       (0x00000016u)
#define CSL_EDMACC_EECRH_E54_RESETVAL    (0x00000000u)

/*----E54 Tokens----*/
#define CSL_EDMACC_EECRH_E54_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_E53_MASK        (0x00200000u)
#define CSL_EDMACC_EECRH_E53_SHIFT       (0x00000015u)
#define CSL_EDMACC_EECRH_E53_RESETVAL    (0x00000000u)

/*----E53 Tokens----*/
#define CSL_EDMACC_EECRH_E53_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_E52_MASK        (0x00100000u)
#define CSL_EDMACC_EECRH_E52_SHIFT       (0x00000014u)
#define CSL_EDMACC_EECRH_E52_RESETVAL    (0x00000000u)

/*----E52 Tokens----*/
#define CSL_EDMACC_EECRH_E52_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_E51_MASK        (0x00080000u)
#define CSL_EDMACC_EECRH_E51_SHIFT       (0x00000013u)
#define CSL_EDMACC_EECRH_E51_RESETVAL    (0x00000000u)

/*----E51 Tokens----*/
#define CSL_EDMACC_EECRH_E51_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_E50_MASK        (0x00040000u)
#define CSL_EDMACC_EECRH_E50_SHIFT       (0x00000012u)
#define CSL_EDMACC_EECRH_E50_RESETVAL    (0x00000000u)

/*----E50 Tokens----*/
#define CSL_EDMACC_EECRH_E50_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_E49_MASK        (0x00020000u)
#define CSL_EDMACC_EECRH_E49_SHIFT       (0x00000011u)
#define CSL_EDMACC_EECRH_E49_RESETVAL    (0x00000000u)

/*----E49 Tokens----*/
#define CSL_EDMACC_EECRH_E49_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_E48_MASK        (0x00010000u)
#define CSL_EDMACC_EECRH_E48_SHIFT       (0x00000010u)
#define CSL_EDMACC_EECRH_E48_RESETVAL    (0x00000000u)

/*----E48 Tokens----*/
#define CSL_EDMACC_EECRH_E48_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_E47_MASK        (0x00008000u)
#define CSL_EDMACC_EECRH_E47_SHIFT       (0x0000000Fu)
#define CSL_EDMACC_EECRH_E47_RESETVAL    (0x00000000u)

/*----E47 Tokens----*/
#define CSL_EDMACC_EECRH_E47_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_E46_MASK        (0x00004000u)
#define CSL_EDMACC_EECRH_E46_SHIFT       (0x0000000Eu)
#define CSL_EDMACC_EECRH_E46_RESETVAL    (0x00000000u)

/*----E46 Tokens----*/
#define CSL_EDMACC_EECRH_E46_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_E45_MASK        (0x00002000u)
#define CSL_EDMACC_EECRH_E45_SHIFT       (0x0000000Du)
#define CSL_EDMACC_EECRH_E45_RESETVAL    (0x00000000u)

/*----E45 Tokens----*/
#define CSL_EDMACC_EECRH_E45_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_E44_MASK        (0x00001000u)
#define CSL_EDMACC_EECRH_E44_SHIFT       (0x0000000Cu)
#define CSL_EDMACC_EECRH_E44_RESETVAL    (0x00000000u)

/*----E44 Tokens----*/
#define CSL_EDMACC_EECRH_E44_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_E43_MASK        (0x00000800u)
#define CSL_EDMACC_EECRH_E43_SHIFT       (0x0000000Bu)
#define CSL_EDMACC_EECRH_E43_RESETVAL    (0x00000000u)

/*----E43 Tokens----*/
#define CSL_EDMACC_EECRH_E43_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_E42_MASK        (0x00000400u)
#define CSL_EDMACC_EECRH_E42_SHIFT       (0x0000000Au)
#define CSL_EDMACC_EECRH_E42_RESETVAL    (0x00000000u)

/*----E42 Tokens----*/
#define CSL_EDMACC_EECRH_E42_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_E41_MASK        (0x00000200u)
#define CSL_EDMACC_EECRH_E41_SHIFT       (0x00000009u)
#define CSL_EDMACC_EECRH_E41_RESETVAL    (0x00000000u)

/*----E41 Tokens----*/
#define CSL_EDMACC_EECRH_E41_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_E40_MASK        (0x00000100u)
#define CSL_EDMACC_EECRH_E40_SHIFT       (0x00000008u)
#define CSL_EDMACC_EECRH_E40_RESETVAL    (0x00000000u)

/*----E40 Tokens----*/
#define CSL_EDMACC_EECRH_E40_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_E39_MASK        (0x00000080u)
#define CSL_EDMACC_EECRH_E39_SHIFT       (0x00000007u)
#define CSL_EDMACC_EECRH_E39_RESETVAL    (0x00000000u)

/*----E39 Tokens----*/
#define CSL_EDMACC_EECRH_E39_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_E38_MASK        (0x00000040u)
#define CSL_EDMACC_EECRH_E38_SHIFT       (0x00000006u)
#define CSL_EDMACC_EECRH_E38_RESETVAL    (0x00000000u)

/*----E38 Tokens----*/
#define CSL_EDMACC_EECRH_E38_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_E37_MASK        (0x00000020u)
#define CSL_EDMACC_EECRH_E37_SHIFT       (0x00000005u)
#define CSL_EDMACC_EECRH_E37_RESETVAL    (0x00000000u)

/*----E37 Tokens----*/
#define CSL_EDMACC_EECRH_E37_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_E36_MASK        (0x00000010u)
#define CSL_EDMACC_EECRH_E36_SHIFT       (0x00000004u)
#define CSL_EDMACC_EECRH_E36_RESETVAL    (0x00000000u)

/*----E36 Tokens----*/
#define CSL_EDMACC_EECRH_E36_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_E35_MASK        (0x00000008u)
#define CSL_EDMACC_EECRH_E35_SHIFT       (0x00000003u)
#define CSL_EDMACC_EECRH_E35_RESETVAL    (0x00000000u)

/*----E35 Tokens----*/
#define CSL_EDMACC_EECRH_E35_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_E34_MASK        (0x00000004u)
#define CSL_EDMACC_EECRH_E34_SHIFT       (0x00000002u)
#define CSL_EDMACC_EECRH_E34_RESETVAL    (0x00000000u)

/*----E34 Tokens----*/
#define CSL_EDMACC_EECRH_E34_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_E33_MASK        (0x00000002u)
#define CSL_EDMACC_EECRH_E33_SHIFT       (0x00000001u)
#define CSL_EDMACC_EECRH_E33_RESETVAL    (0x00000000u)

/*----E33 Tokens----*/
#define CSL_EDMACC_EECRH_E33_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_E32_MASK        (0x00000001u)
#define CSL_EDMACC_EECRH_E32_SHIFT       (0x00000000u)
#define CSL_EDMACC_EECRH_E32_RESETVAL    (0x00000000u)

/*----E32 Tokens----*/
#define CSL_EDMACC_EECRH_E32_CLEAR       (0x00000001u)

#define CSL_EDMACC_EECRH_RESETVAL        (0x00000000u)

/* EESR */

#define CSL_EDMACC_EESR_E31_MASK         (0x80000000u)
#define CSL_EDMACC_EESR_E31_SHIFT        (0x0000001Fu)
#define CSL_EDMACC_EESR_E31_RESETVAL     (0x00000000u)

/*----E31 Tokens----*/
#define CSL_EDMACC_EESR_E31_SET          (0x00000001u)

#define CSL_EDMACC_EESR_E30_MASK         (0x40000000u)
#define CSL_EDMACC_EESR_E30_SHIFT        (0x0000001Eu)
#define CSL_EDMACC_EESR_E30_RESETVAL     (0x00000000u)

/*----E30 Tokens----*/
#define CSL_EDMACC_EESR_E30_SET          (0x00000001u)

#define CSL_EDMACC_EESR_E29_MASK         (0x20000000u)
#define CSL_EDMACC_EESR_E29_SHIFT        (0x0000001Du)
#define CSL_EDMACC_EESR_E29_RESETVAL     (0x00000000u)

/*----E29 Tokens----*/
#define CSL_EDMACC_EESR_E29_SET          (0x00000001u)

#define CSL_EDMACC_EESR_E28_MASK         (0x10000000u)
#define CSL_EDMACC_EESR_E28_SHIFT        (0x0000001Cu)
#define CSL_EDMACC_EESR_E28_RESETVAL     (0x00000000u)

/*----E28 Tokens----*/
#define CSL_EDMACC_EESR_E28_SET          (0x00000001u)

#define CSL_EDMACC_EESR_E27_MASK         (0x08000000u)
#define CSL_EDMACC_EESR_E27_SHIFT        (0x0000001Bu)
#define CSL_EDMACC_EESR_E27_RESETVAL     (0x00000000u)

/*----E27 Tokens----*/
#define CSL_EDMACC_EESR_E27_SET          (0x00000001u)

#define CSL_EDMACC_EESR_E26_MASK         (0x04000000u)
#define CSL_EDMACC_EESR_E26_SHIFT        (0x0000001Au)
#define CSL_EDMACC_EESR_E26_RESETVAL     (0x00000000u)

/*----E26 Tokens----*/
#define CSL_EDMACC_EESR_E26_SET          (0x00000001u)

#define CSL_EDMACC_EESR_E25_MASK         (0x02000000u)
#define CSL_EDMACC_EESR_E25_SHIFT        (0x00000019u)
#define CSL_EDMACC_EESR_E25_RESETVAL     (0x00000000u)

/*----E25 Tokens----*/
#define CSL_EDMACC_EESR_E25_SET          (0x00000001u)

#define CSL_EDMACC_EESR_E24_MASK         (0x01000000u)
#define CSL_EDMACC_EESR_E24_SHIFT        (0x00000018u)
#define CSL_EDMACC_EESR_E24_RESETVAL     (0x00000000u)

/*----E24 Tokens----*/
#define CSL_EDMACC_EESR_E24_SET          (0x00000001u)

#define CSL_EDMACC_EESR_E23_MASK         (0x00800000u)
#define CSL_EDMACC_EESR_E23_SHIFT        (0x00000017u)
#define CSL_EDMACC_EESR_E23_RESETVAL     (0x00000000u)

/*----E23 Tokens----*/
#define CSL_EDMACC_EESR_E23_SET          (0x00000001u)

#define CSL_EDMACC_EESR_E22_MASK         (0x00400000u)
#define CSL_EDMACC_EESR_E22_SHIFT        (0x00000016u)
#define CSL_EDMACC_EESR_E22_RESETVAL     (0x00000000u)

/*----E22 Tokens----*/
#define CSL_EDMACC_EESR_E22_SET          (0x00000001u)

#define CSL_EDMACC_EESR_E21_MASK         (0x00200000u)
#define CSL_EDMACC_EESR_E21_SHIFT        (0x00000015u)
#define CSL_EDMACC_EESR_E21_RESETVAL     (0x00000000u)

/*----E21 Tokens----*/
#define CSL_EDMACC_EESR_E21_SET          (0x00000001u)

#define CSL_EDMACC_EESR_E20_MASK         (0x00100000u)
#define CSL_EDMACC_EESR_E20_SHIFT        (0x00000014u)
#define CSL_EDMACC_EESR_E20_RESETVAL     (0x00000000u)

/*----E20 Tokens----*/
#define CSL_EDMACC_EESR_E20_SET          (0x00000001u)

#define CSL_EDMACC_EESR_E19_MASK         (0x00080000u)
#define CSL_EDMACC_EESR_E19_SHIFT        (0x00000013u)
#define CSL_EDMACC_EESR_E19_RESETVAL     (0x00000000u)

/*----E19 Tokens----*/
#define CSL_EDMACC_EESR_E19_SET          (0x00000001u)

#define CSL_EDMACC_EESR_E18_MASK         (0x00040000u)
#define CSL_EDMACC_EESR_E18_SHIFT        (0x00000012u)
#define CSL_EDMACC_EESR_E18_RESETVAL     (0x00000000u)

/*----E18 Tokens----*/
#define CSL_EDMACC_EESR_E18_SET          (0x00000001u)

#define CSL_EDMACC_EESR_E17_MASK         (0x00020000u)
#define CSL_EDMACC_EESR_E17_SHIFT        (0x00000011u)
#define CSL_EDMACC_EESR_E17_RESETVAL     (0x00000000u)

/*----E17 Tokens----*/
#define CSL_EDMACC_EESR_E17_SET          (0x00000001u)

#define CSL_EDMACC_EESR_E16_MASK         (0x00010000u)
#define CSL_EDMACC_EESR_E16_SHIFT        (0x00000010u)
#define CSL_EDMACC_EESR_E16_RESETVAL     (0x00000000u)

/*----E16 Tokens----*/
#define CSL_EDMACC_EESR_E16_SET          (0x00000001u)

#define CSL_EDMACC_EESR_E15_MASK         (0x00008000u)
#define CSL_EDMACC_EESR_E15_SHIFT        (0x0000000Fu)
#define CSL_EDMACC_EESR_E15_RESETVAL     (0x00000000u)

/*----E15 Tokens----*/
#define CSL_EDMACC_EESR_E15_SET          (0x00000001u)

#define CSL_EDMACC_EESR_E14_MASK         (0x00004000u)
#define CSL_EDMACC_EESR_E14_SHIFT        (0x0000000Eu)
#define CSL_EDMACC_EESR_E14_RESETVAL     (0x00000000u)

/*----E14 Tokens----*/
#define CSL_EDMACC_EESR_E14_SET          (0x00000001u)

#define CSL_EDMACC_EESR_E13_MASK         (0x00002000u)
#define CSL_EDMACC_EESR_E13_SHIFT        (0x0000000Du)
#define CSL_EDMACC_EESR_E13_RESETVAL     (0x00000000u)

/*----E13 Tokens----*/
#define CSL_EDMACC_EESR_E13_SET          (0x00000001u)

#define CSL_EDMACC_EESR_E12_MASK         (0x00001000u)
#define CSL_EDMACC_EESR_E12_SHIFT        (0x0000000Cu)
#define CSL_EDMACC_EESR_E12_RESETVAL     (0x00000000u)

/*----E12 Tokens----*/
#define CSL_EDMACC_EESR_E12_SET          (0x00000001u)

#define CSL_EDMACC_EESR_E11_MASK         (0x00000800u)
#define CSL_EDMACC_EESR_E11_SHIFT        (0x0000000Bu)
#define CSL_EDMACC_EESR_E11_RESETVAL     (0x00000000u)

/*----E11 Tokens----*/
#define CSL_EDMACC_EESR_E11_SET          (0x00000001u)

#define CSL_EDMACC_EESR_E10_MASK         (0x00000400u)
#define CSL_EDMACC_EESR_E10_SHIFT        (0x0000000Au)
#define CSL_EDMACC_EESR_E10_RESETVAL     (0x00000000u)

/*----E10 Tokens----*/
#define CSL_EDMACC_EESR_E10_SET          (0x00000001u)

#define CSL_EDMACC_EESR_E9_MASK          (0x00000200u)
#define CSL_EDMACC_EESR_E9_SHIFT         (0x00000009u)
#define CSL_EDMACC_EESR_E9_RESETVAL      (0x00000000u)

/*----E9 Tokens----*/
#define CSL_EDMACC_EESR_E9_SET           (0x00000001u)

#define CSL_EDMACC_EESR_E8_MASK          (0x00000100u)
#define CSL_EDMACC_EESR_E8_SHIFT         (0x00000008u)
#define CSL_EDMACC_EESR_E8_RESETVAL      (0x00000000u)

/*----E8 Tokens----*/
#define CSL_EDMACC_EESR_E8_SET           (0x00000001u)

#define CSL_EDMACC_EESR_E7_MASK          (0x00000080u)
#define CSL_EDMACC_EESR_E7_SHIFT         (0x00000007u)
#define CSL_EDMACC_EESR_E7_RESETVAL      (0x00000000u)

/*----E7 Tokens----*/
#define CSL_EDMACC_EESR_E7_SET           (0x00000001u)

#define CSL_EDMACC_EESR_E6_MASK          (0x00000040u)
#define CSL_EDMACC_EESR_E6_SHIFT         (0x00000006u)
#define CSL_EDMACC_EESR_E6_RESETVAL      (0x00000000u)

/*----E6 Tokens----*/
#define CSL_EDMACC_EESR_E6_SET           (0x00000001u)

#define CSL_EDMACC_EESR_E5_MASK          (0x00000020u)
#define CSL_EDMACC_EESR_E5_SHIFT         (0x00000005u)
#define CSL_EDMACC_EESR_E5_RESETVAL      (0x00000000u)

/*----E5 Tokens----*/
#define CSL_EDMACC_EESR_E5_SET           (0x00000001u)

#define CSL_EDMACC_EESR_E4_MASK          (0x00000010u)
#define CSL_EDMACC_EESR_E4_SHIFT         (0x00000004u)
#define CSL_EDMACC_EESR_E4_RESETVAL      (0x00000000u)

/*----E4 Tokens----*/
#define CSL_EDMACC_EESR_E4_SET           (0x00000001u)

#define CSL_EDMACC_EESR_E3_MASK          (0x00000008u)
#define CSL_EDMACC_EESR_E3_SHIFT         (0x00000003u)
#define CSL_EDMACC_EESR_E3_RESETVAL      (0x00000000u)

/*----E3 Tokens----*/
#define CSL_EDMACC_EESR_E3_SET           (0x00000001u)

#define CSL_EDMACC_EESR_E2_MASK          (0x00000004u)
#define CSL_EDMACC_EESR_E2_SHIFT         (0x00000002u)
#define CSL_EDMACC_EESR_E2_RESETVAL      (0x00000000u)

/*----E2 Tokens----*/
#define CSL_EDMACC_EESR_E2_SET           (0x00000001u)

#define CSL_EDMACC_EESR_E1_MASK          (0x00000002u)
#define CSL_EDMACC_EESR_E1_SHIFT         (0x00000001u)
#define CSL_EDMACC_EESR_E1_RESETVAL      (0x00000000u)

/*----E1 Tokens----*/
#define CSL_EDMACC_EESR_E1_SET           (0x00000001u)

#define CSL_EDMACC_EESR_E0_MASK          (0x00000001u)
#define CSL_EDMACC_EESR_E0_SHIFT         (0x00000000u)
#define CSL_EDMACC_EESR_E0_RESETVAL      (0x00000000u)

/*----E0 Tokens----*/
#define CSL_EDMACC_EESR_E0_SET           (0x00000001u)

#define CSL_EDMACC_EESR_RESETVAL         (0x00000000u)

/* EESRH */

#define CSL_EDMACC_EESRH_E63_MASK        (0x80000000u)
#define CSL_EDMACC_EESRH_E63_SHIFT       (0x0000001Fu)
#define CSL_EDMACC_EESRH_E63_RESETVAL    (0x00000000u)

/*----E63 Tokens----*/
#define CSL_EDMACC_EESRH_E63_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_E62_MASK        (0x40000000u)
#define CSL_EDMACC_EESRH_E62_SHIFT       (0x0000001Eu)
#define CSL_EDMACC_EESRH_E62_RESETVAL    (0x00000000u)

/*----E62 Tokens----*/
#define CSL_EDMACC_EESRH_E62_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_E61_MASK        (0x20000000u)
#define CSL_EDMACC_EESRH_E61_SHIFT       (0x0000001Du)
#define CSL_EDMACC_EESRH_E61_RESETVAL    (0x00000000u)

/*----E61 Tokens----*/
#define CSL_EDMACC_EESRH_E61_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_E60_MASK        (0x10000000u)
#define CSL_EDMACC_EESRH_E60_SHIFT       (0x0000001Cu)
#define CSL_EDMACC_EESRH_E60_RESETVAL    (0x00000000u)

/*----E60 Tokens----*/
#define CSL_EDMACC_EESRH_E60_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_E59_MASK        (0x08000000u)
#define CSL_EDMACC_EESRH_E59_SHIFT       (0x0000001Bu)
#define CSL_EDMACC_EESRH_E59_RESETVAL    (0x00000000u)

/*----E59 Tokens----*/
#define CSL_EDMACC_EESRH_E59_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_E58_MASK        (0x04000000u)
#define CSL_EDMACC_EESRH_E58_SHIFT       (0x0000001Au)
#define CSL_EDMACC_EESRH_E58_RESETVAL    (0x00000000u)

/*----E58 Tokens----*/
#define CSL_EDMACC_EESRH_E58_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_E57_MASK        (0x02000000u)
#define CSL_EDMACC_EESRH_E57_SHIFT       (0x00000019u)
#define CSL_EDMACC_EESRH_E57_RESETVAL    (0x00000000u)

/*----E57 Tokens----*/
#define CSL_EDMACC_EESRH_E57_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_E56_MASK        (0x01000000u)
#define CSL_EDMACC_EESRH_E56_SHIFT       (0x00000018u)
#define CSL_EDMACC_EESRH_E56_RESETVAL    (0x00000000u)

/*----E56 Tokens----*/
#define CSL_EDMACC_EESRH_E56_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_E55_MASK        (0x00800000u)
#define CSL_EDMACC_EESRH_E55_SHIFT       (0x00000017u)
#define CSL_EDMACC_EESRH_E55_RESETVAL    (0x00000000u)

/*----E55 Tokens----*/
#define CSL_EDMACC_EESRH_E55_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_E54_MASK        (0x00400000u)
#define CSL_EDMACC_EESRH_E54_SHIFT       (0x00000016u)
#define CSL_EDMACC_EESRH_E54_RESETVAL    (0x00000000u)

/*----E54 Tokens----*/
#define CSL_EDMACC_EESRH_E54_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_E53_MASK        (0x00200000u)
#define CSL_EDMACC_EESRH_E53_SHIFT       (0x00000015u)
#define CSL_EDMACC_EESRH_E53_RESETVAL    (0x00000000u)

/*----E53 Tokens----*/
#define CSL_EDMACC_EESRH_E53_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_E52_MASK        (0x00100000u)
#define CSL_EDMACC_EESRH_E52_SHIFT       (0x00000014u)
#define CSL_EDMACC_EESRH_E52_RESETVAL    (0x00000000u)

/*----E52 Tokens----*/
#define CSL_EDMACC_EESRH_E52_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_E51_MASK        (0x00080000u)
#define CSL_EDMACC_EESRH_E51_SHIFT       (0x00000013u)
#define CSL_EDMACC_EESRH_E51_RESETVAL    (0x00000000u)

/*----E51 Tokens----*/
#define CSL_EDMACC_EESRH_E51_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_E50_MASK        (0x00040000u)
#define CSL_EDMACC_EESRH_E50_SHIFT       (0x00000012u)
#define CSL_EDMACC_EESRH_E50_RESETVAL    (0x00000000u)

/*----E50 Tokens----*/
#define CSL_EDMACC_EESRH_E50_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_E49_MASK        (0x00020000u)
#define CSL_EDMACC_EESRH_E49_SHIFT       (0x00000011u)
#define CSL_EDMACC_EESRH_E49_RESETVAL    (0x00000000u)

/*----E49 Tokens----*/
#define CSL_EDMACC_EESRH_E49_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_E48_MASK        (0x00010000u)
#define CSL_EDMACC_EESRH_E48_SHIFT       (0x00000010u)
#define CSL_EDMACC_EESRH_E48_RESETVAL    (0x00000000u)

/*----E48 Tokens----*/
#define CSL_EDMACC_EESRH_E48_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_E47_MASK        (0x00008000u)
#define CSL_EDMACC_EESRH_E47_SHIFT       (0x0000000Fu)
#define CSL_EDMACC_EESRH_E47_RESETVAL    (0x00000000u)

/*----E47 Tokens----*/
#define CSL_EDMACC_EESRH_E47_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_E46_MASK        (0x00004000u)
#define CSL_EDMACC_EESRH_E46_SHIFT       (0x0000000Eu)
#define CSL_EDMACC_EESRH_E46_RESETVAL    (0x00000000u)

/*----E46 Tokens----*/
#define CSL_EDMACC_EESRH_E46_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_E45_MASK        (0x00002000u)
#define CSL_EDMACC_EESRH_E45_SHIFT       (0x0000000Du)
#define CSL_EDMACC_EESRH_E45_RESETVAL    (0x00000000u)

/*----E45 Tokens----*/
#define CSL_EDMACC_EESRH_E45_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_E44_MASK        (0x00001000u)
#define CSL_EDMACC_EESRH_E44_SHIFT       (0x0000000Cu)
#define CSL_EDMACC_EESRH_E44_RESETVAL    (0x00000000u)

/*----E44 Tokens----*/
#define CSL_EDMACC_EESRH_E44_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_E43_MASK        (0x00000800u)
#define CSL_EDMACC_EESRH_E43_SHIFT       (0x0000000Bu)
#define CSL_EDMACC_EESRH_E43_RESETVAL    (0x00000000u)

/*----E43 Tokens----*/
#define CSL_EDMACC_EESRH_E43_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_E42_MASK        (0x00000400u)
#define CSL_EDMACC_EESRH_E42_SHIFT       (0x0000000Au)
#define CSL_EDMACC_EESRH_E42_RESETVAL    (0x00000000u)

/*----E42 Tokens----*/
#define CSL_EDMACC_EESRH_E42_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_E41_MASK        (0x00000200u)
#define CSL_EDMACC_EESRH_E41_SHIFT       (0x00000009u)
#define CSL_EDMACC_EESRH_E41_RESETVAL    (0x00000000u)

/*----E41 Tokens----*/
#define CSL_EDMACC_EESRH_E41_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_E40_MASK        (0x00000100u)
#define CSL_EDMACC_EESRH_E40_SHIFT       (0x00000008u)
#define CSL_EDMACC_EESRH_E40_RESETVAL    (0x00000000u)

/*----E40 Tokens----*/
#define CSL_EDMACC_EESRH_E40_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_E39_MASK        (0x00000080u)
#define CSL_EDMACC_EESRH_E39_SHIFT       (0x00000007u)
#define CSL_EDMACC_EESRH_E39_RESETVAL    (0x00000000u)

/*----E39 Tokens----*/
#define CSL_EDMACC_EESRH_E39_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_E38_MASK        (0x00000040u)
#define CSL_EDMACC_EESRH_E38_SHIFT       (0x00000006u)
#define CSL_EDMACC_EESRH_E38_RESETVAL    (0x00000000u)

/*----E38 Tokens----*/
#define CSL_EDMACC_EESRH_E38_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_E37_MASK        (0x00000020u)
#define CSL_EDMACC_EESRH_E37_SHIFT       (0x00000005u)
#define CSL_EDMACC_EESRH_E37_RESETVAL    (0x00000000u)

/*----E37 Tokens----*/
#define CSL_EDMACC_EESRH_E37_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_E36_MASK        (0x00000010u)
#define CSL_EDMACC_EESRH_E36_SHIFT       (0x00000004u)
#define CSL_EDMACC_EESRH_E36_RESETVAL    (0x00000000u)

/*----E36 Tokens----*/
#define CSL_EDMACC_EESRH_E36_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_E35_MASK        (0x00000008u)
#define CSL_EDMACC_EESRH_E35_SHIFT       (0x00000003u)
#define CSL_EDMACC_EESRH_E35_RESETVAL    (0x00000000u)

/*----E35 Tokens----*/
#define CSL_EDMACC_EESRH_E35_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_E34_MASK        (0x00000004u)
#define CSL_EDMACC_EESRH_E34_SHIFT       (0x00000002u)
#define CSL_EDMACC_EESRH_E34_RESETVAL    (0x00000000u)

/*----E34 Tokens----*/
#define CSL_EDMACC_EESRH_E34_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_E33_MASK        (0x00000002u)
#define CSL_EDMACC_EESRH_E33_SHIFT       (0x00000001u)
#define CSL_EDMACC_EESRH_E33_RESETVAL    (0x00000000u)

/*----E33 Tokens----*/
#define CSL_EDMACC_EESRH_E33_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_E32_MASK        (0x00000001u)
#define CSL_EDMACC_EESRH_E32_SHIFT       (0x00000000u)
#define CSL_EDMACC_EESRH_E32_RESETVAL    (0x00000000u)

/*----E32 Tokens----*/
#define CSL_EDMACC_EESRH_E32_SET         (0x00000001u)

#define CSL_EDMACC_EESRH_RESETVAL        (0x00000000u)

/* SER */

#define CSL_EDMACC_SER_E31_MASK          (0x80000000u)
#define CSL_EDMACC_SER_E31_SHIFT         (0x0000001Fu)
#define CSL_EDMACC_SER_E31_RESETVAL      (0x00000000u)

#define CSL_EDMACC_SER_E30_MASK          (0x40000000u)
#define CSL_EDMACC_SER_E30_SHIFT         (0x0000001Eu)
#define CSL_EDMACC_SER_E30_RESETVAL      (0x00000000u)

#define CSL_EDMACC_SER_E29_MASK          (0x20000000u)
#define CSL_EDMACC_SER_E29_SHIFT         (0x0000001Du)
#define CSL_EDMACC_SER_E29_RESETVAL      (0x00000000u)

#define CSL_EDMACC_SER_E28_MASK          (0x10000000u)
#define CSL_EDMACC_SER_E28_SHIFT         (0x0000001Cu)
#define CSL_EDMACC_SER_E28_RESETVAL      (0x00000000u)

#define CSL_EDMACC_SER_E27_MASK          (0x08000000u)
#define CSL_EDMACC_SER_E27_SHIFT         (0x0000001Bu)
#define CSL_EDMACC_SER_E27_RESETVAL      (0x00000000u)

#define CSL_EDMACC_SER_E26_MASK          (0x04000000u)
#define CSL_EDMACC_SER_E26_SHIFT         (0x0000001Au)
#define CSL_EDMACC_SER_E26_RESETVAL      (0x00000000u)

#define CSL_EDMACC_SER_E25_MASK          (0x02000000u)
#define CSL_EDMACC_SER_E25_SHIFT         (0x00000019u)
#define CSL_EDMACC_SER_E25_RESETVAL      (0x00000000u)

#define CSL_EDMACC_SER_E24_MASK          (0x01000000u)
#define CSL_EDMACC_SER_E24_SHIFT         (0x00000018u)
#define CSL_EDMACC_SER_E24_RESETVAL      (0x00000000u)

#define CSL_EDMACC_SER_E23_MASK          (0x00800000u)
#define CSL_EDMACC_SER_E23_SHIFT         (0x00000017u)
#define CSL_EDMACC_SER_E23_RESETVAL      (0x00000000u)

#define CSL_EDMACC_SER_E22_MASK          (0x00400000u)
#define CSL_EDMACC_SER_E22_SHIFT         (0x00000016u)
#define CSL_EDMACC_SER_E22_RESETVAL      (0x00000000u)

#define CSL_EDMACC_SER_E21_MASK          (0x00200000u)
#define CSL_EDMACC_SER_E21_SHIFT         (0x00000015u)
#define CSL_EDMACC_SER_E21_RESETVAL      (0x00000000u)

#define CSL_EDMACC_SER_E20_MASK          (0x00100000u)
#define CSL_EDMACC_SER_E20_SHIFT         (0x00000014u)
#define CSL_EDMACC_SER_E20_RESETVAL      (0x00000000u)

#define CSL_EDMACC_SER_E19_MASK          (0x00080000u)
#define CSL_EDMACC_SER_E19_SHIFT         (0x00000013u)
#define CSL_EDMACC_SER_E19_RESETVAL      (0x00000000u)

#define CSL_EDMACC_SER_E18_MASK          (0x00040000u)
#define CSL_EDMACC_SER_E18_SHIFT         (0x00000012u)
#define CSL_EDMACC_SER_E18_RESETVAL      (0x00000000u)

#define CSL_EDMACC_SER_E17_MASK          (0x00020000u)
#define CSL_EDMACC_SER_E17_SHIFT         (0x00000011u)
#define CSL_EDMACC_SER_E17_RESETVAL      (0x00000000u)

#define CSL_EDMACC_SER_E16_MASK          (0x00010000u)
#define CSL_EDMACC_SER_E16_SHIFT         (0x00000010u)
#define CSL_EDMACC_SER_E16_RESETVAL      (0x00000000u)

#define CSL_EDMACC_SER_E15_MASK          (0x00008000u)
#define CSL_EDMACC_SER_E15_SHIFT         (0x0000000Fu)
#define CSL_EDMACC_SER_E15_RESETVAL      (0x00000000u)

#define CSL_EDMACC_SER_E14_MASK          (0x00004000u)
#define CSL_EDMACC_SER_E14_SHIFT         (0x0000000Eu)
#define CSL_EDMACC_SER_E14_RESETVAL      (0x00000000u)

#define CSL_EDMACC_SER_E13_MASK          (0x00002000u)
#define CSL_EDMACC_SER_E13_SHIFT         (0x0000000Du)
#define CSL_EDMACC_SER_E13_RESETVAL      (0x00000000u)

#define CSL_EDMACC_SER_E12_MASK          (0x00001000u)
#define CSL_EDMACC_SER_E12_SHIFT         (0x0000000Cu)
#define CSL_EDMACC_SER_E12_RESETVAL      (0x00000000u)

#define CSL_EDMACC_SER_E11_MASK          (0x00000800u)
#define CSL_EDMACC_SER_E11_SHIFT         (0x0000000Bu)
#define CSL_EDMACC_SER_E11_RESETVAL      (0x00000000u)

#define CSL_EDMACC_SER_E10_MASK          (0x00000400u)
#define CSL_EDMACC_SER_E10_SHIFT         (0x0000000Au)
#define CSL_EDMACC_SER_E10_RESETVAL      (0x00000000u)

#define CSL_EDMACC_SER_E9_MASK           (0x00000200u)
#define CSL_EDMACC_SER_E9_SHIFT          (0x00000009u)
#define CSL_EDMACC_SER_E9_RESETVAL       (0x00000000u)

#define CSL_EDMACC_SER_E8_MASK           (0x00000100u)
#define CSL_EDMACC_SER_E8_SHIFT          (0x00000008u)
#define CSL_EDMACC_SER_E8_RESETVAL       (0x00000000u)

#define CSL_EDMACC_SER_E7_MASK           (0x00000080u)
#define CSL_EDMACC_SER_E7_SHIFT          (0x00000007u)
#define CSL_EDMACC_SER_E7_RESETVAL       (0x00000000u)

#define CSL_EDMACC_SER_E6_MASK           (0x00000040u)
#define CSL_EDMACC_SER_E6_SHIFT          (0x00000006u)
#define CSL_EDMACC_SER_E6_RESETVAL       (0x00000000u)

#define CSL_EDMACC_SER_E5_MASK           (0x00000020u)
#define CSL_EDMACC_SER_E5_SHIFT          (0x00000005u)
#define CSL_EDMACC_SER_E5_RESETVAL       (0x00000000u)

#define CSL_EDMACC_SER_E4_MASK           (0x00000010u)
#define CSL_EDMACC_SER_E4_SHIFT          (0x00000004u)
#define CSL_EDMACC_SER_E4_RESETVAL       (0x00000000u)

#define CSL_EDMACC_SER_E3_MASK           (0x00000008u)
#define CSL_EDMACC_SER_E3_SHIFT          (0x00000003u)
#define CSL_EDMACC_SER_E3_RESETVAL       (0x00000000u)

#define CSL_EDMACC_SER_E2_MASK           (0x00000004u)
#define CSL_EDMACC_SER_E2_SHIFT          (0x00000002u)
#define CSL_EDMACC_SER_E2_RESETVAL       (0x00000000u)

#define CSL_EDMACC_SER_E1_MASK           (0x00000002u)
#define CSL_EDMACC_SER_E1_SHIFT          (0x00000001u)
#define CSL_EDMACC_SER_E1_RESETVAL       (0x00000000u)

#define CSL_EDMACC_SER_E0_MASK           (0x00000001u)
#define CSL_EDMACC_SER_E0_SHIFT          (0x00000000u)
#define CSL_EDMACC_SER_E0_RESETVAL       (0x00000000u)

#define CSL_EDMACC_SER_RESETVAL          (0x00000000u)

/* SERH */

#define CSL_EDMACC_SERH_E63_MASK         (0x80000000u)
#define CSL_EDMACC_SERH_E63_SHIFT        (0x0000001Fu)
#define CSL_EDMACC_SERH_E63_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_E62_MASK         (0x40000000u)
#define CSL_EDMACC_SERH_E62_SHIFT        (0x0000001Eu)
#define CSL_EDMACC_SERH_E62_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_E61_MASK         (0x20000000u)
#define CSL_EDMACC_SERH_E61_SHIFT        (0x0000001Du)
#define CSL_EDMACC_SERH_E61_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_E60_MASK         (0x10000000u)
#define CSL_EDMACC_SERH_E60_SHIFT        (0x0000001Cu)
#define CSL_EDMACC_SERH_E60_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_E59_MASK         (0x08000000u)
#define CSL_EDMACC_SERH_E59_SHIFT        (0x0000001Bu)
#define CSL_EDMACC_SERH_E59_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_E58_MASK         (0x04000000u)
#define CSL_EDMACC_SERH_E58_SHIFT        (0x0000001Au)
#define CSL_EDMACC_SERH_E58_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_E57_MASK         (0x02000000u)
#define CSL_EDMACC_SERH_E57_SHIFT        (0x00000019u)
#define CSL_EDMACC_SERH_E57_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_E56_MASK         (0x01000000u)
#define CSL_EDMACC_SERH_E56_SHIFT        (0x00000018u)
#define CSL_EDMACC_SERH_E56_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_E55_MASK         (0x00800000u)
#define CSL_EDMACC_SERH_E55_SHIFT        (0x00000017u)
#define CSL_EDMACC_SERH_E55_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_E54_MASK         (0x00400000u)
#define CSL_EDMACC_SERH_E54_SHIFT        (0x00000016u)
#define CSL_EDMACC_SERH_E54_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_E53_MASK         (0x00200000u)
#define CSL_EDMACC_SERH_E53_SHIFT        (0x00000015u)
#define CSL_EDMACC_SERH_E53_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_E52_MASK         (0x00100000u)
#define CSL_EDMACC_SERH_E52_SHIFT        (0x00000014u)
#define CSL_EDMACC_SERH_E52_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_E51_MASK         (0x00080000u)
#define CSL_EDMACC_SERH_E51_SHIFT        (0x00000013u)
#define CSL_EDMACC_SERH_E51_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_E50_MASK         (0x00040000u)
#define CSL_EDMACC_SERH_E50_SHIFT        (0x00000012u)
#define CSL_EDMACC_SERH_E50_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_E49_MASK         (0x00020000u)
#define CSL_EDMACC_SERH_E49_SHIFT        (0x00000011u)
#define CSL_EDMACC_SERH_E49_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_E48_MASK         (0x00010000u)
#define CSL_EDMACC_SERH_E48_SHIFT        (0x00000010u)
#define CSL_EDMACC_SERH_E48_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_E47_MASK         (0x00008000u)
#define CSL_EDMACC_SERH_E47_SHIFT        (0x0000000Fu)
#define CSL_EDMACC_SERH_E47_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_E46_MASK         (0x00004000u)
#define CSL_EDMACC_SERH_E46_SHIFT        (0x0000000Eu)
#define CSL_EDMACC_SERH_E46_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_E45_MASK         (0x00002000u)
#define CSL_EDMACC_SERH_E45_SHIFT        (0x0000000Du)
#define CSL_EDMACC_SERH_E45_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_E44_MASK         (0x00001000u)
#define CSL_EDMACC_SERH_E44_SHIFT        (0x0000000Cu)
#define CSL_EDMACC_SERH_E44_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_E43_MASK         (0x00000800u)
#define CSL_EDMACC_SERH_E43_SHIFT        (0x0000000Bu)
#define CSL_EDMACC_SERH_E43_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_E42_MASK         (0x00000400u)
#define CSL_EDMACC_SERH_E42_SHIFT        (0x0000000Au)
#define CSL_EDMACC_SERH_E42_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_E41_MASK         (0x00000200u)
#define CSL_EDMACC_SERH_E41_SHIFT        (0x00000009u)
#define CSL_EDMACC_SERH_E41_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_E40_MASK         (0x00000100u)
#define CSL_EDMACC_SERH_E40_SHIFT        (0x00000008u)
#define CSL_EDMACC_SERH_E40_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_E39_MASK         (0x00000080u)
#define CSL_EDMACC_SERH_E39_SHIFT        (0x00000007u)
#define CSL_EDMACC_SERH_E39_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_E38_MASK         (0x00000040u)
#define CSL_EDMACC_SERH_E38_SHIFT        (0x00000006u)
#define CSL_EDMACC_SERH_E38_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_E37_MASK         (0x00000020u)
#define CSL_EDMACC_SERH_E37_SHIFT        (0x00000005u)
#define CSL_EDMACC_SERH_E37_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_E36_MASK         (0x00000010u)
#define CSL_EDMACC_SERH_E36_SHIFT        (0x00000004u)
#define CSL_EDMACC_SERH_E36_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_E35_MASK         (0x00000008u)
#define CSL_EDMACC_SERH_E35_SHIFT        (0x00000003u)
#define CSL_EDMACC_SERH_E35_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_E34_MASK         (0x00000004u)
#define CSL_EDMACC_SERH_E34_SHIFT        (0x00000002u)
#define CSL_EDMACC_SERH_E34_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_E33_MASK         (0x00000002u)
#define CSL_EDMACC_SERH_E33_SHIFT        (0x00000001u)
#define CSL_EDMACC_SERH_E33_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_E32_MASK         (0x00000001u)
#define CSL_EDMACC_SERH_E32_SHIFT        (0x00000000u)
#define CSL_EDMACC_SERH_E32_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_RESETVAL         (0x00000000u)

/* SECR */

#define CSL_EDMACC_SECR_E31_MASK         (0x80000000u)
#define CSL_EDMACC_SECR_E31_SHIFT        (0x0000001Fu)
#define CSL_EDMACC_SECR_E31_RESETVAL     (0x00000000u)

/*----E31 Tokens----*/
#define CSL_EDMACC_SECR_E31_CLEAR        (0x00000001u)

#define CSL_EDMACC_SECR_E30_MASK         (0x40000000u)
#define CSL_EDMACC_SECR_E30_SHIFT        (0x0000001Eu)
#define CSL_EDMACC_SECR_E30_RESETVAL     (0x00000000u)

/*----E30 Tokens----*/
#define CSL_EDMACC_SECR_E30_CLEAR        (0x00000001u)

#define CSL_EDMACC_SECR_E29_MASK         (0x20000000u)
#define CSL_EDMACC_SECR_E29_SHIFT        (0x0000001Du)
#define CSL_EDMACC_SECR_E29_RESETVAL     (0x00000000u)

/*----E29 Tokens----*/
#define CSL_EDMACC_SECR_E29_CLEAR        (0x00000001u)

#define CSL_EDMACC_SECR_E28_MASK         (0x10000000u)
#define CSL_EDMACC_SECR_E28_SHIFT        (0x0000001Cu)
#define CSL_EDMACC_SECR_E28_RESETVAL     (0x00000000u)

/*----E28 Tokens----*/
#define CSL_EDMACC_SECR_E28_CLEAR        (0x00000001u)

#define CSL_EDMACC_SECR_E27_MASK         (0x08000000u)
#define CSL_EDMACC_SECR_E27_SHIFT        (0x0000001Bu)
#define CSL_EDMACC_SECR_E27_RESETVAL     (0x00000000u)

/*----E27 Tokens----*/
#define CSL_EDMACC_SECR_E27_CLEAR        (0x00000001u)

#define CSL_EDMACC_SECR_E26_MASK         (0x04000000u)
#define CSL_EDMACC_SECR_E26_SHIFT        (0x0000001Au)
#define CSL_EDMACC_SECR_E26_RESETVAL     (0x00000000u)

/*----E26 Tokens----*/
#define CSL_EDMACC_SECR_E26_CLEAR        (0x00000001u)

#define CSL_EDMACC_SECR_E25_MASK         (0x02000000u)
#define CSL_EDMACC_SECR_E25_SHIFT        (0x00000019u)
#define CSL_EDMACC_SECR_E25_RESETVAL     (0x00000000u)

/*----E25 Tokens----*/
#define CSL_EDMACC_SECR_E25_CLEAR        (0x00000001u)

#define CSL_EDMACC_SECR_E24_MASK         (0x01000000u)
#define CSL_EDMACC_SECR_E24_SHIFT        (0x00000018u)
#define CSL_EDMACC_SECR_E24_RESETVAL     (0x00000000u)

/*----E24 Tokens----*/
#define CSL_EDMACC_SECR_E24_CLEAR        (0x00000001u)

#define CSL_EDMACC_SECR_E23_MASK         (0x00800000u)
#define CSL_EDMACC_SECR_E23_SHIFT        (0x00000017u)
#define CSL_EDMACC_SECR_E23_RESETVAL     (0x00000000u)

/*----E23 Tokens----*/
#define CSL_EDMACC_SECR_E23_CLEAR        (0x00000001u)

#define CSL_EDMACC_SECR_E22_MASK         (0x00400000u)
#define CSL_EDMACC_SECR_E22_SHIFT        (0x00000016u)
#define CSL_EDMACC_SECR_E22_RESETVAL     (0x00000000u)

/*----E22 Tokens----*/
#define CSL_EDMACC_SECR_E22_CLEAR        (0x00000001u)

#define CSL_EDMACC_SECR_E21_MASK         (0x00200000u)
#define CSL_EDMACC_SECR_E21_SHIFT        (0x00000015u)
#define CSL_EDMACC_SECR_E21_RESETVAL     (0x00000000u)

/*----E21 Tokens----*/
#define CSL_EDMACC_SECR_E21_CLEAR        (0x00000001u)

#define CSL_EDMACC_SECR_E20_MASK         (0x00100000u)
#define CSL_EDMACC_SECR_E20_SHIFT        (0x00000014u)
#define CSL_EDMACC_SECR_E20_RESETVAL     (0x00000000u)

/*----E20 Tokens----*/
#define CSL_EDMACC_SECR_E20_CLEAR        (0x00000001u)

#define CSL_EDMACC_SECR_E19_MASK         (0x00080000u)
#define CSL_EDMACC_SECR_E19_SHIFT        (0x00000013u)
#define CSL_EDMACC_SECR_E19_RESETVAL     (0x00000000u)

/*----E19 Tokens----*/
#define CSL_EDMACC_SECR_E19_CLEAR        (0x00000001u)

#define CSL_EDMACC_SECR_E18_MASK         (0x00040000u)
#define CSL_EDMACC_SECR_E18_SHIFT        (0x00000012u)
#define CSL_EDMACC_SECR_E18_RESETVAL     (0x00000000u)

/*----E18 Tokens----*/
#define CSL_EDMACC_SECR_E18_CLEAR        (0x00000001u)

#define CSL_EDMACC_SECR_E17_MASK         (0x00020000u)
#define CSL_EDMACC_SECR_E17_SHIFT        (0x00000011u)
#define CSL_EDMACC_SECR_E17_RESETVAL     (0x00000000u)

/*----E17 Tokens----*/
#define CSL_EDMACC_SECR_E17_CLEAR        (0x00000001u)

#define CSL_EDMACC_SECR_E16_MASK         (0x00010000u)
#define CSL_EDMACC_SECR_E16_SHIFT        (0x00000010u)
#define CSL_EDMACC_SECR_E16_RESETVAL     (0x00000000u)

/*----E16 Tokens----*/
#define CSL_EDMACC_SECR_E16_CLEAR        (0x00000001u)

#define CSL_EDMACC_SECR_E15_MASK         (0x00008000u)
#define CSL_EDMACC_SECR_E15_SHIFT        (0x0000000Fu)
#define CSL_EDMACC_SECR_E15_RESETVAL     (0x00000000u)

/*----E15 Tokens----*/
#define CSL_EDMACC_SECR_E15_CLEAR        (0x00000001u)

#define CSL_EDMACC_SECR_E14_MASK         (0x00004000u)
#define CSL_EDMACC_SECR_E14_SHIFT        (0x0000000Eu)
#define CSL_EDMACC_SECR_E14_RESETVAL     (0x00000000u)

/*----E14 Tokens----*/
#define CSL_EDMACC_SECR_E14_CLEAR        (0x00000001u)

#define CSL_EDMACC_SECR_E13_MASK         (0x00002000u)
#define CSL_EDMACC_SECR_E13_SHIFT        (0x0000000Du)
#define CSL_EDMACC_SECR_E13_RESETVAL     (0x00000000u)

/*----E13 Tokens----*/
#define CSL_EDMACC_SECR_E13_CLEAR        (0x00000001u)

#define CSL_EDMACC_SECR_E12_MASK         (0x00001000u)
#define CSL_EDMACC_SECR_E12_SHIFT        (0x0000000Cu)
#define CSL_EDMACC_SECR_E12_RESETVAL     (0x00000000u)

/*----E12 Tokens----*/
#define CSL_EDMACC_SECR_E12_CLEAR        (0x00000001u)

#define CSL_EDMACC_SECR_E11_MASK         (0x00000800u)
#define CSL_EDMACC_SECR_E11_SHIFT        (0x0000000Bu)
#define CSL_EDMACC_SECR_E11_RESETVAL     (0x00000000u)

/*----E11 Tokens----*/
#define CSL_EDMACC_SECR_E11_CLEAR        (0x00000001u)

#define CSL_EDMACC_SECR_E10_MASK         (0x00000400u)
#define CSL_EDMACC_SECR_E10_SHIFT        (0x0000000Au)
#define CSL_EDMACC_SECR_E10_RESETVAL     (0x00000000u)

/*----E10 Tokens----*/
#define CSL_EDMACC_SECR_E10_CLEAR        (0x00000001u)

#define CSL_EDMACC_SECR_E9_MASK          (0x00000200u)
#define CSL_EDMACC_SECR_E9_SHIFT         (0x00000009u)
#define CSL_EDMACC_SECR_E9_RESETVAL      (0x00000000u)

/*----E9 Tokens----*/
#define CSL_EDMACC_SECR_E9_CLEAR         (0x00000001u)

#define CSL_EDMACC_SECR_E8_MASK          (0x00000100u)
#define CSL_EDMACC_SECR_E8_SHIFT         (0x00000008u)
#define CSL_EDMACC_SECR_E8_RESETVAL      (0x00000000u)

/*----E8 Tokens----*/
#define CSL_EDMACC_SECR_E8_CLEAR         (0x00000001u)

#define CSL_EDMACC_SECR_E7_MASK          (0x00000080u)
#define CSL_EDMACC_SECR_E7_SHIFT         (0x00000007u)
#define CSL_EDMACC_SECR_E7_RESETVAL      (0x00000000u)

/*----E7 Tokens----*/
#define CSL_EDMACC_SECR_E7_CLEAR         (0x00000001u)

#define CSL_EDMACC_SECR_E6_MASK          (0x00000040u)
#define CSL_EDMACC_SECR_E6_SHIFT         (0x00000006u)
#define CSL_EDMACC_SECR_E6_RESETVAL      (0x00000000u)

/*----E6 Tokens----*/
#define CSL_EDMACC_SECR_E6_CLEAR         (0x00000001u)

#define CSL_EDMACC_SECR_E5_MASK          (0x00000020u)
#define CSL_EDMACC_SECR_E5_SHIFT         (0x00000005u)
#define CSL_EDMACC_SECR_E5_RESETVAL      (0x00000000u)

/*----E5 Tokens----*/
#define CSL_EDMACC_SECR_E5_CLEAR         (0x00000001u)

#define CSL_EDMACC_SECR_E4_MASK          (0x00000010u)
#define CSL_EDMACC_SECR_E4_SHIFT         (0x00000004u)
#define CSL_EDMACC_SECR_E4_RESETVAL      (0x00000000u)

/*----E4 Tokens----*/
#define CSL_EDMACC_SECR_E4_CLEAR         (0x00000001u)

#define CSL_EDMACC_SECR_E3_MASK          (0x00000008u)
#define CSL_EDMACC_SECR_E3_SHIFT         (0x00000003u)
#define CSL_EDMACC_SECR_E3_RESETVAL      (0x00000000u)

/*----E3 Tokens----*/
#define CSL_EDMACC_SECR_E3_CLEAR         (0x00000001u)

#define CSL_EDMACC_SECR_E2_MASK          (0x00000004u)
#define CSL_EDMACC_SECR_E2_SHIFT         (0x00000002u)
#define CSL_EDMACC_SECR_E2_RESETVAL      (0x00000000u)

/*----E2 Tokens----*/
#define CSL_EDMACC_SECR_E2_CLEAR         (0x00000001u)

#define CSL_EDMACC_SECR_E1_MASK          (0x00000002u)
#define CSL_EDMACC_SECR_E1_SHIFT         (0x00000001u)
#define CSL_EDMACC_SECR_E1_RESETVAL      (0x00000000u)

/*----E1 Tokens----*/
#define CSL_EDMACC_SECR_E1_CLEAR         (0x00000001u)

#define CSL_EDMACC_SECR_E0_MASK          (0x00000001u)
#define CSL_EDMACC_SECR_E0_SHIFT         (0x00000000u)
#define CSL_EDMACC_SECR_E0_RESETVAL      (0x00000000u)

/*----E0 Tokens----*/
#define CSL_EDMACC_SECR_E0_CLEAR         (0x00000001u)

#define CSL_EDMACC_SECR_RESETVAL         (0x00000000u)

/* SECRH */

#define CSL_EDMACC_SECRH_E63_MASK        (0x80000000u)
#define CSL_EDMACC_SECRH_E63_SHIFT       (0x0000001Fu)
#define CSL_EDMACC_SECRH_E63_RESETVAL    (0x00000000u)

/*----E63 Tokens----*/
#define CSL_EDMACC_SECRH_E63_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_E62_MASK        (0x40000000u)
#define CSL_EDMACC_SECRH_E62_SHIFT       (0x0000001Eu)
#define CSL_EDMACC_SECRH_E62_RESETVAL    (0x00000000u)

/*----E62 Tokens----*/
#define CSL_EDMACC_SECRH_E62_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_E61_MASK        (0x20000000u)
#define CSL_EDMACC_SECRH_E61_SHIFT       (0x0000001Du)
#define CSL_EDMACC_SECRH_E61_RESETVAL    (0x00000000u)

/*----E61 Tokens----*/
#define CSL_EDMACC_SECRH_E61_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_E60_MASK        (0x10000000u)
#define CSL_EDMACC_SECRH_E60_SHIFT       (0x0000001Cu)
#define CSL_EDMACC_SECRH_E60_RESETVAL    (0x00000000u)

/*----E60 Tokens----*/
#define CSL_EDMACC_SECRH_E60_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_E59_MASK        (0x08000000u)
#define CSL_EDMACC_SECRH_E59_SHIFT       (0x0000001Bu)
#define CSL_EDMACC_SECRH_E59_RESETVAL    (0x00000000u)

/*----E59 Tokens----*/
#define CSL_EDMACC_SECRH_E59_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_E58_MASK        (0x04000000u)
#define CSL_EDMACC_SECRH_E58_SHIFT       (0x0000001Au)
#define CSL_EDMACC_SECRH_E58_RESETVAL    (0x00000000u)

/*----E58 Tokens----*/
#define CSL_EDMACC_SECRH_E58_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_E57_MASK        (0x02000000u)
#define CSL_EDMACC_SECRH_E57_SHIFT       (0x00000019u)
#define CSL_EDMACC_SECRH_E57_RESETVAL    (0x00000000u)

/*----E57 Tokens----*/
#define CSL_EDMACC_SECRH_E57_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_E56_MASK        (0x01000000u)
#define CSL_EDMACC_SECRH_E56_SHIFT       (0x00000018u)
#define CSL_EDMACC_SECRH_E56_RESETVAL    (0x00000000u)

/*----E56 Tokens----*/
#define CSL_EDMACC_SECRH_E56_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_E55_MASK        (0x00800000u)
#define CSL_EDMACC_SECRH_E55_SHIFT       (0x00000017u)
#define CSL_EDMACC_SECRH_E55_RESETVAL    (0x00000000u)

/*----E55 Tokens----*/
#define CSL_EDMACC_SECRH_E55_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_E54_MASK        (0x00400000u)
#define CSL_EDMACC_SECRH_E54_SHIFT       (0x00000016u)
#define CSL_EDMACC_SECRH_E54_RESETVAL    (0x00000000u)

/*----E54 Tokens----*/
#define CSL_EDMACC_SECRH_E54_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_E53_MASK        (0x00200000u)
#define CSL_EDMACC_SECRH_E53_SHIFT       (0x00000015u)
#define CSL_EDMACC_SECRH_E53_RESETVAL    (0x00000000u)

/*----E53 Tokens----*/
#define CSL_EDMACC_SECRH_E53_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_E52_MASK        (0x00100000u)
#define CSL_EDMACC_SECRH_E52_SHIFT       (0x00000014u)
#define CSL_EDMACC_SECRH_E52_RESETVAL    (0x00000000u)

/*----E52 Tokens----*/
#define CSL_EDMACC_SECRH_E52_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_E51_MASK        (0x00080000u)
#define CSL_EDMACC_SECRH_E51_SHIFT       (0x00000013u)
#define CSL_EDMACC_SECRH_E51_RESETVAL    (0x00000000u)

/*----E51 Tokens----*/
#define CSL_EDMACC_SECRH_E51_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_E50_MASK        (0x00040000u)
#define CSL_EDMACC_SECRH_E50_SHIFT       (0x00000012u)
#define CSL_EDMACC_SECRH_E50_RESETVAL    (0x00000000u)

/*----E50 Tokens----*/
#define CSL_EDMACC_SECRH_E50_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_E49_MASK        (0x00020000u)
#define CSL_EDMACC_SECRH_E49_SHIFT       (0x00000011u)
#define CSL_EDMACC_SECRH_E49_RESETVAL    (0x00000000u)

/*----E49 Tokens----*/
#define CSL_EDMACC_SECRH_E49_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_E48_MASK        (0x00010000u)
#define CSL_EDMACC_SECRH_E48_SHIFT       (0x00000010u)
#define CSL_EDMACC_SECRH_E48_RESETVAL    (0x00000000u)

/*----E48 Tokens----*/
#define CSL_EDMACC_SECRH_E48_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_E47_MASK        (0x00008000u)
#define CSL_EDMACC_SECRH_E47_SHIFT       (0x0000000Fu)
#define CSL_EDMACC_SECRH_E47_RESETVAL    (0x00000000u)

/*----E47 Tokens----*/
#define CSL_EDMACC_SECRH_E47_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_E46_MASK        (0x00004000u)
#define CSL_EDMACC_SECRH_E46_SHIFT       (0x0000000Eu)
#define CSL_EDMACC_SECRH_E46_RESETVAL    (0x00000000u)

/*----E46 Tokens----*/
#define CSL_EDMACC_SECRH_E46_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_E45_MASK        (0x00002000u)
#define CSL_EDMACC_SECRH_E45_SHIFT       (0x0000000Du)
#define CSL_EDMACC_SECRH_E45_RESETVAL    (0x00000000u)

/*----E45 Tokens----*/
#define CSL_EDMACC_SECRH_E45_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_E44_MASK        (0x00001000u)
#define CSL_EDMACC_SECRH_E44_SHIFT       (0x0000000Cu)
#define CSL_EDMACC_SECRH_E44_RESETVAL    (0x00000000u)

/*----E44 Tokens----*/
#define CSL_EDMACC_SECRH_E44_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_E43_MASK        (0x00000800u)
#define CSL_EDMACC_SECRH_E43_SHIFT       (0x0000000Bu)
#define CSL_EDMACC_SECRH_E43_RESETVAL    (0x00000000u)

/*----E43 Tokens----*/
#define CSL_EDMACC_SECRH_E43_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_E42_MASK        (0x00000400u)
#define CSL_EDMACC_SECRH_E42_SHIFT       (0x0000000Au)
#define CSL_EDMACC_SECRH_E42_RESETVAL    (0x00000000u)

/*----E42 Tokens----*/
#define CSL_EDMACC_SECRH_E42_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_E41_MASK        (0x00000200u)
#define CSL_EDMACC_SECRH_E41_SHIFT       (0x00000009u)
#define CSL_EDMACC_SECRH_E41_RESETVAL    (0x00000000u)

/*----E41 Tokens----*/
#define CSL_EDMACC_SECRH_E41_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_E40_MASK        (0x00000100u)
#define CSL_EDMACC_SECRH_E40_SHIFT       (0x00000008u)
#define CSL_EDMACC_SECRH_E40_RESETVAL    (0x00000000u)

/*----E40 Tokens----*/
#define CSL_EDMACC_SECRH_E40_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_E39_MASK        (0x00000080u)
#define CSL_EDMACC_SECRH_E39_SHIFT       (0x00000007u)
#define CSL_EDMACC_SECRH_E39_RESETVAL    (0x00000000u)

/*----E39 Tokens----*/
#define CSL_EDMACC_SECRH_E39_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_E38_MASK        (0x00000040u)
#define CSL_EDMACC_SECRH_E38_SHIFT       (0x00000006u)
#define CSL_EDMACC_SECRH_E38_RESETVAL    (0x00000000u)

/*----E38 Tokens----*/
#define CSL_EDMACC_SECRH_E38_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_E37_MASK        (0x00000020u)
#define CSL_EDMACC_SECRH_E37_SHIFT       (0x00000005u)
#define CSL_EDMACC_SECRH_E37_RESETVAL    (0x00000000u)

/*----E37 Tokens----*/
#define CSL_EDMACC_SECRH_E37_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_E36_MASK        (0x00000010u)
#define CSL_EDMACC_SECRH_E36_SHIFT       (0x00000004u)
#define CSL_EDMACC_SECRH_E36_RESETVAL    (0x00000000u)

/*----E36 Tokens----*/
#define CSL_EDMACC_SECRH_E36_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_E35_MASK        (0x00000008u)
#define CSL_EDMACC_SECRH_E35_SHIFT       (0x00000003u)
#define CSL_EDMACC_SECRH_E35_RESETVAL    (0x00000000u)

/*----E35 Tokens----*/
#define CSL_EDMACC_SECRH_E35_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_E34_MASK        (0x00000004u)
#define CSL_EDMACC_SECRH_E34_SHIFT       (0x00000002u)
#define CSL_EDMACC_SECRH_E34_RESETVAL    (0x00000000u)

/*----E34 Tokens----*/
#define CSL_EDMACC_SECRH_E34_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_E33_MASK        (0x00000002u)
#define CSL_EDMACC_SECRH_E33_SHIFT       (0x00000001u)
#define CSL_EDMACC_SECRH_E33_RESETVAL    (0x00000000u)

/*----E33 Tokens----*/
#define CSL_EDMACC_SECRH_E33_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_E32_MASK        (0x00000001u)
#define CSL_EDMACC_SECRH_E32_SHIFT       (0x00000000u)
#define CSL_EDMACC_SECRH_E32_RESETVAL    (0x00000000u)

/*----E32 Tokens----*/
#define CSL_EDMACC_SECRH_E32_CLEAR       (0x00000001u)

#define CSL_EDMACC_SECRH_RESETVAL        (0x00000000u)

/* IER */

#define CSL_EDMACC_IER_I31_MASK          (0x80000000u)
#define CSL_EDMACC_IER_I31_SHIFT         (0x0000001Fu)
#define CSL_EDMACC_IER_I31_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IER_I30_MASK          (0x40000000u)
#define CSL_EDMACC_IER_I30_SHIFT         (0x0000001Eu)
#define CSL_EDMACC_IER_I30_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IER_I29_MASK          (0x20000000u)
#define CSL_EDMACC_IER_I29_SHIFT         (0x0000001Du)
#define CSL_EDMACC_IER_I29_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IER_I28_MASK          (0x10000000u)
#define CSL_EDMACC_IER_I28_SHIFT         (0x0000001Cu)
#define CSL_EDMACC_IER_I28_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IER_I27_MASK          (0x08000000u)
#define CSL_EDMACC_IER_I27_SHIFT         (0x0000001Bu)
#define CSL_EDMACC_IER_I27_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IER_I26_MASK          (0x04000000u)
#define CSL_EDMACC_IER_I26_SHIFT         (0x0000001Au)
#define CSL_EDMACC_IER_I26_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IER_I25_MASK          (0x02000000u)
#define CSL_EDMACC_IER_I25_SHIFT         (0x00000019u)
#define CSL_EDMACC_IER_I25_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IER_I24_MASK          (0x01000000u)
#define CSL_EDMACC_IER_I24_SHIFT         (0x00000018u)
#define CSL_EDMACC_IER_I24_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IER_I23_MASK          (0x00800000u)
#define CSL_EDMACC_IER_I23_SHIFT         (0x00000017u)
#define CSL_EDMACC_IER_I23_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IER_I22_MASK          (0x00400000u)
#define CSL_EDMACC_IER_I22_SHIFT         (0x00000016u)
#define CSL_EDMACC_IER_I22_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IER_I21_MASK          (0x00200000u)
#define CSL_EDMACC_IER_I21_SHIFT         (0x00000015u)
#define CSL_EDMACC_IER_I21_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IER_I20_MASK          (0x00100000u)
#define CSL_EDMACC_IER_I20_SHIFT         (0x00000014u)
#define CSL_EDMACC_IER_I20_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IER_I19_MASK          (0x00080000u)
#define CSL_EDMACC_IER_I19_SHIFT         (0x00000013u)
#define CSL_EDMACC_IER_I19_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IER_I18_MASK          (0x00040000u)
#define CSL_EDMACC_IER_I18_SHIFT         (0x00000012u)
#define CSL_EDMACC_IER_I18_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IER_I17_MASK          (0x00020000u)
#define CSL_EDMACC_IER_I17_SHIFT         (0x00000011u)
#define CSL_EDMACC_IER_I17_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IER_I16_MASK          (0x00010000u)
#define CSL_EDMACC_IER_I16_SHIFT         (0x00000010u)
#define CSL_EDMACC_IER_I16_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IER_I15_MASK          (0x00008000u)
#define CSL_EDMACC_IER_I15_SHIFT         (0x0000000Fu)
#define CSL_EDMACC_IER_I15_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IER_I14_MASK          (0x00004000u)
#define CSL_EDMACC_IER_I14_SHIFT         (0x0000000Eu)
#define CSL_EDMACC_IER_I14_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IER_I13_MASK          (0x00002000u)
#define CSL_EDMACC_IER_I13_SHIFT         (0x0000000Du)
#define CSL_EDMACC_IER_I13_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IER_I12_MASK          (0x00001000u)
#define CSL_EDMACC_IER_I12_SHIFT         (0x0000000Cu)
#define CSL_EDMACC_IER_I12_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IER_I11_MASK          (0x00000800u)
#define CSL_EDMACC_IER_I11_SHIFT         (0x0000000Bu)
#define CSL_EDMACC_IER_I11_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IER_I10_MASK          (0x00000400u)
#define CSL_EDMACC_IER_I10_SHIFT         (0x0000000Au)
#define CSL_EDMACC_IER_I10_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IER_I9_MASK           (0x00000200u)
#define CSL_EDMACC_IER_I9_SHIFT          (0x00000009u)
#define CSL_EDMACC_IER_I9_RESETVAL       (0x00000000u)

#define CSL_EDMACC_IER_I8_MASK           (0x00000100u)
#define CSL_EDMACC_IER_I8_SHIFT          (0x00000008u)
#define CSL_EDMACC_IER_I8_RESETVAL       (0x00000000u)

#define CSL_EDMACC_IER_I7_MASK           (0x00000080u)
#define CSL_EDMACC_IER_I7_SHIFT          (0x00000007u)
#define CSL_EDMACC_IER_I7_RESETVAL       (0x00000000u)

#define CSL_EDMACC_IER_I6_MASK           (0x00000040u)
#define CSL_EDMACC_IER_I6_SHIFT          (0x00000006u)
#define CSL_EDMACC_IER_I6_RESETVAL       (0x00000000u)

#define CSL_EDMACC_IER_I5_MASK           (0x00000020u)
#define CSL_EDMACC_IER_I5_SHIFT          (0x00000005u)
#define CSL_EDMACC_IER_I5_RESETVAL       (0x00000000u)

#define CSL_EDMACC_IER_I4_MASK           (0x00000010u)
#define CSL_EDMACC_IER_I4_SHIFT          (0x00000004u)
#define CSL_EDMACC_IER_I4_RESETVAL       (0x00000000u)

#define CSL_EDMACC_IER_I3_MASK           (0x00000008u)
#define CSL_EDMACC_IER_I3_SHIFT          (0x00000003u)
#define CSL_EDMACC_IER_I3_RESETVAL       (0x00000000u)

#define CSL_EDMACC_IER_I2_MASK           (0x00000004u)
#define CSL_EDMACC_IER_I2_SHIFT          (0x00000002u)
#define CSL_EDMACC_IER_I2_RESETVAL       (0x00000000u)

#define CSL_EDMACC_IER_I1_MASK           (0x00000002u)
#define CSL_EDMACC_IER_I1_SHIFT          (0x00000001u)
#define CSL_EDMACC_IER_I1_RESETVAL       (0x00000000u)

#define CSL_EDMACC_IER_I0_MASK           (0x00000001u)
#define CSL_EDMACC_IER_I0_SHIFT          (0x00000000u)
#define CSL_EDMACC_IER_I0_RESETVAL       (0x00000000u)

#define CSL_EDMACC_IER_RESETVAL          (0x00000000u)

/* IERH */

#define CSL_EDMACC_IERH_I63_MASK         (0x80000000u)
#define CSL_EDMACC_IERH_I63_SHIFT        (0x0000001Fu)
#define CSL_EDMACC_IERH_I63_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_I62_MASK         (0x40000000u)
#define CSL_EDMACC_IERH_I62_SHIFT        (0x0000001Eu)
#define CSL_EDMACC_IERH_I62_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_I61_MASK         (0x20000000u)
#define CSL_EDMACC_IERH_I61_SHIFT        (0x0000001Du)
#define CSL_EDMACC_IERH_I61_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_I60_MASK         (0x10000000u)
#define CSL_EDMACC_IERH_I60_SHIFT        (0x0000001Cu)
#define CSL_EDMACC_IERH_I60_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_I59_MASK         (0x08000000u)
#define CSL_EDMACC_IERH_I59_SHIFT        (0x0000001Bu)
#define CSL_EDMACC_IERH_I59_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_I58_MASK         (0x04000000u)
#define CSL_EDMACC_IERH_I58_SHIFT        (0x0000001Au)
#define CSL_EDMACC_IERH_I58_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_I57_MASK         (0x02000000u)
#define CSL_EDMACC_IERH_I57_SHIFT        (0x00000019u)
#define CSL_EDMACC_IERH_I57_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_I56_MASK         (0x01000000u)
#define CSL_EDMACC_IERH_I56_SHIFT        (0x00000018u)
#define CSL_EDMACC_IERH_I56_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_I55_MASK         (0x00800000u)
#define CSL_EDMACC_IERH_I55_SHIFT        (0x00000017u)
#define CSL_EDMACC_IERH_I55_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_I54_MASK         (0x00400000u)
#define CSL_EDMACC_IERH_I54_SHIFT        (0x00000016u)
#define CSL_EDMACC_IERH_I54_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_I53_MASK         (0x00200000u)
#define CSL_EDMACC_IERH_I53_SHIFT        (0x00000015u)
#define CSL_EDMACC_IERH_I53_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_I52_MASK         (0x00100000u)
#define CSL_EDMACC_IERH_I52_SHIFT        (0x00000014u)
#define CSL_EDMACC_IERH_I52_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_I51_MASK         (0x00080000u)
#define CSL_EDMACC_IERH_I51_SHIFT        (0x00000013u)
#define CSL_EDMACC_IERH_I51_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_I50_MASK         (0x00040000u)
#define CSL_EDMACC_IERH_I50_SHIFT        (0x00000012u)
#define CSL_EDMACC_IERH_I50_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_I49_MASK         (0x00020000u)
#define CSL_EDMACC_IERH_I49_SHIFT        (0x00000011u)
#define CSL_EDMACC_IERH_I49_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_I48_MASK         (0x00010000u)
#define CSL_EDMACC_IERH_I48_SHIFT        (0x00000010u)
#define CSL_EDMACC_IERH_I48_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_I47_MASK         (0x00008000u)
#define CSL_EDMACC_IERH_I47_SHIFT        (0x0000000Fu)
#define CSL_EDMACC_IERH_I47_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_I46_MASK         (0x00004000u)
#define CSL_EDMACC_IERH_I46_SHIFT        (0x0000000Eu)
#define CSL_EDMACC_IERH_I46_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_I45_MASK         (0x00002000u)
#define CSL_EDMACC_IERH_I45_SHIFT        (0x0000000Du)
#define CSL_EDMACC_IERH_I45_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_I44_MASK         (0x00001000u)
#define CSL_EDMACC_IERH_I44_SHIFT        (0x0000000Cu)
#define CSL_EDMACC_IERH_I44_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_I43_MASK         (0x00000800u)
#define CSL_EDMACC_IERH_I43_SHIFT        (0x0000000Bu)
#define CSL_EDMACC_IERH_I43_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_I42_MASK         (0x00000400u)
#define CSL_EDMACC_IERH_I42_SHIFT        (0x0000000Au)
#define CSL_EDMACC_IERH_I42_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_I41_MASK         (0x00000200u)
#define CSL_EDMACC_IERH_I41_SHIFT        (0x00000009u)
#define CSL_EDMACC_IERH_I41_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_I40_MASK         (0x00000100u)
#define CSL_EDMACC_IERH_I40_SHIFT        (0x00000008u)
#define CSL_EDMACC_IERH_I40_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_I39_MASK         (0x00000080u)
#define CSL_EDMACC_IERH_I39_SHIFT        (0x00000007u)
#define CSL_EDMACC_IERH_I39_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_I38_MASK         (0x00000040u)
#define CSL_EDMACC_IERH_I38_SHIFT        (0x00000006u)
#define CSL_EDMACC_IERH_I38_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_I37_MASK         (0x00000020u)
#define CSL_EDMACC_IERH_I37_SHIFT        (0x00000005u)
#define CSL_EDMACC_IERH_I37_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_I36_MASK         (0x00000010u)
#define CSL_EDMACC_IERH_I36_SHIFT        (0x00000004u)
#define CSL_EDMACC_IERH_I36_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_I35_MASK         (0x00000008u)
#define CSL_EDMACC_IERH_I35_SHIFT        (0x00000003u)
#define CSL_EDMACC_IERH_I35_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_I34_MASK         (0x00000004u)
#define CSL_EDMACC_IERH_I34_SHIFT        (0x00000002u)
#define CSL_EDMACC_IERH_I34_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_I33_MASK         (0x00000002u)
#define CSL_EDMACC_IERH_I33_SHIFT        (0x00000001u)
#define CSL_EDMACC_IERH_I33_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_I32_MASK         (0x00000001u)
#define CSL_EDMACC_IERH_I32_SHIFT        (0x00000000u)
#define CSL_EDMACC_IERH_I32_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_RESETVAL         (0x00000000u)

/* IECR */

#define CSL_EDMACC_IECR_I31_MASK         (0x80000000u)
#define CSL_EDMACC_IECR_I31_SHIFT        (0x0000001Fu)
#define CSL_EDMACC_IECR_I31_RESETVAL     (0x00000000u)

/*----I31 Tokens----*/
#define CSL_EDMACC_IECR_I31_CLEAR        (0x00000001u)

#define CSL_EDMACC_IECR_I30_MASK         (0x40000000u)
#define CSL_EDMACC_IECR_I30_SHIFT        (0x0000001Eu)
#define CSL_EDMACC_IECR_I30_RESETVAL     (0x00000000u)

/*----I30 Tokens----*/
#define CSL_EDMACC_IECR_I30_CLEAR        (0x00000001u)

#define CSL_EDMACC_IECR_I29_MASK         (0x20000000u)
#define CSL_EDMACC_IECR_I29_SHIFT        (0x0000001Du)
#define CSL_EDMACC_IECR_I29_RESETVAL     (0x00000000u)

/*----I29 Tokens----*/
#define CSL_EDMACC_IECR_I29_CLEAR        (0x00000001u)

#define CSL_EDMACC_IECR_I28_MASK         (0x10000000u)
#define CSL_EDMACC_IECR_I28_SHIFT        (0x0000001Cu)
#define CSL_EDMACC_IECR_I28_RESETVAL     (0x00000000u)

/*----I28 Tokens----*/
#define CSL_EDMACC_IECR_I28_CLEAR        (0x00000001u)

#define CSL_EDMACC_IECR_I27_MASK         (0x08000000u)
#define CSL_EDMACC_IECR_I27_SHIFT        (0x0000001Bu)
#define CSL_EDMACC_IECR_I27_RESETVAL     (0x00000000u)

/*----I27 Tokens----*/
#define CSL_EDMACC_IECR_I27_CLEAR        (0x00000001u)

#define CSL_EDMACC_IECR_I26_MASK         (0x04000000u)
#define CSL_EDMACC_IECR_I26_SHIFT        (0x0000001Au)
#define CSL_EDMACC_IECR_I26_RESETVAL     (0x00000000u)

/*----I26 Tokens----*/
#define CSL_EDMACC_IECR_I26_CLEAR        (0x00000001u)

#define CSL_EDMACC_IECR_I25_MASK         (0x02000000u)
#define CSL_EDMACC_IECR_I25_SHIFT        (0x00000019u)
#define CSL_EDMACC_IECR_I25_RESETVAL     (0x00000000u)

/*----I25 Tokens----*/
#define CSL_EDMACC_IECR_I25_CLEAR        (0x00000001u)

#define CSL_EDMACC_IECR_I24_MASK         (0x01000000u)
#define CSL_EDMACC_IECR_I24_SHIFT        (0x00000018u)
#define CSL_EDMACC_IECR_I24_RESETVAL     (0x00000000u)

/*----I24 Tokens----*/
#define CSL_EDMACC_IECR_I24_CLEAR        (0x00000001u)

#define CSL_EDMACC_IECR_I23_MASK         (0x00800000u)
#define CSL_EDMACC_IECR_I23_SHIFT        (0x00000017u)
#define CSL_EDMACC_IECR_I23_RESETVAL     (0x00000000u)

/*----I23 Tokens----*/
#define CSL_EDMACC_IECR_I23_CLEAR        (0x00000001u)

#define CSL_EDMACC_IECR_I22_MASK         (0x00400000u)
#define CSL_EDMACC_IECR_I22_SHIFT        (0x00000016u)
#define CSL_EDMACC_IECR_I22_RESETVAL     (0x00000000u)

/*----I22 Tokens----*/
#define CSL_EDMACC_IECR_I22_CLEAR        (0x00000001u)

#define CSL_EDMACC_IECR_I21_MASK         (0x00200000u)
#define CSL_EDMACC_IECR_I21_SHIFT        (0x00000015u)
#define CSL_EDMACC_IECR_I21_RESETVAL     (0x00000000u)

/*----I21 Tokens----*/
#define CSL_EDMACC_IECR_I21_CLEAR        (0x00000001u)

#define CSL_EDMACC_IECR_I20_MASK         (0x00100000u)
#define CSL_EDMACC_IECR_I20_SHIFT        (0x00000014u)
#define CSL_EDMACC_IECR_I20_RESETVAL     (0x00000000u)

/*----I20 Tokens----*/
#define CSL_EDMACC_IECR_I20_CLEAR        (0x00000001u)

#define CSL_EDMACC_IECR_I19_MASK         (0x00080000u)
#define CSL_EDMACC_IECR_I19_SHIFT        (0x00000013u)
#define CSL_EDMACC_IECR_I19_RESETVAL     (0x00000000u)

/*----I19 Tokens----*/
#define CSL_EDMACC_IECR_I19_CLEAR        (0x00000001u)

#define CSL_EDMACC_IECR_I18_MASK         (0x00040000u)
#define CSL_EDMACC_IECR_I18_SHIFT        (0x00000012u)
#define CSL_EDMACC_IECR_I18_RESETVAL     (0x00000000u)

/*----I18 Tokens----*/
#define CSL_EDMACC_IECR_I18_CLEAR        (0x00000001u)

#define CSL_EDMACC_IECR_I17_MASK         (0x00020000u)
#define CSL_EDMACC_IECR_I17_SHIFT        (0x00000011u)
#define CSL_EDMACC_IECR_I17_RESETVAL     (0x00000000u)

/*----I17 Tokens----*/
#define CSL_EDMACC_IECR_I17_CLEAR        (0x00000001u)

#define CSL_EDMACC_IECR_I16_MASK         (0x00010000u)
#define CSL_EDMACC_IECR_I16_SHIFT        (0x00000010u)
#define CSL_EDMACC_IECR_I16_RESETVAL     (0x00000000u)

/*----I16 Tokens----*/
#define CSL_EDMACC_IECR_I16_CLEAR        (0x00000001u)

#define CSL_EDMACC_IECR_I15_MASK         (0x00008000u)
#define CSL_EDMACC_IECR_I15_SHIFT        (0x0000000Fu)
#define CSL_EDMACC_IECR_I15_RESETVAL     (0x00000000u)

/*----I15 Tokens----*/
#define CSL_EDMACC_IECR_I15_CLEAR        (0x00000001u)

#define CSL_EDMACC_IECR_I14_MASK         (0x00004000u)
#define CSL_EDMACC_IECR_I14_SHIFT        (0x0000000Eu)
#define CSL_EDMACC_IECR_I14_RESETVAL     (0x00000000u)

/*----I14 Tokens----*/
#define CSL_EDMACC_IECR_I14_CLEAR        (0x00000001u)

#define CSL_EDMACC_IECR_I13_MASK         (0x00002000u)
#define CSL_EDMACC_IECR_I13_SHIFT        (0x0000000Du)
#define CSL_EDMACC_IECR_I13_RESETVAL     (0x00000000u)

/*----I13 Tokens----*/
#define CSL_EDMACC_IECR_I13_CLEAR        (0x00000001u)

#define CSL_EDMACC_IECR_I12_MASK         (0x00001000u)
#define CSL_EDMACC_IECR_I12_SHIFT        (0x0000000Cu)
#define CSL_EDMACC_IECR_I12_RESETVAL     (0x00000000u)

/*----I12 Tokens----*/
#define CSL_EDMACC_IECR_I12_CLEAR        (0x00000001u)

#define CSL_EDMACC_IECR_I11_MASK         (0x00000800u)
#define CSL_EDMACC_IECR_I11_SHIFT        (0x0000000Bu)
#define CSL_EDMACC_IECR_I11_RESETVAL     (0x00000000u)

/*----I11 Tokens----*/
#define CSL_EDMACC_IECR_I11_CLEAR        (0x00000001u)

#define CSL_EDMACC_IECR_I10_MASK         (0x00000400u)
#define CSL_EDMACC_IECR_I10_SHIFT        (0x0000000Au)
#define CSL_EDMACC_IECR_I10_RESETVAL     (0x00000000u)

/*----I10 Tokens----*/
#define CSL_EDMACC_IECR_I10_CLEAR        (0x00000001u)

#define CSL_EDMACC_IECR_I9_MASK          (0x00000200u)
#define CSL_EDMACC_IECR_I9_SHIFT         (0x00000009u)
#define CSL_EDMACC_IECR_I9_RESETVAL      (0x00000000u)

/*----I9 Tokens----*/
#define CSL_EDMACC_IECR_I9_CLEAR         (0x00000001u)

#define CSL_EDMACC_IECR_I8_MASK          (0x00000100u)
#define CSL_EDMACC_IECR_I8_SHIFT         (0x00000008u)
#define CSL_EDMACC_IECR_I8_RESETVAL      (0x00000000u)

/*----I8 Tokens----*/
#define CSL_EDMACC_IECR_I8_CLEAR         (0x00000001u)

#define CSL_EDMACC_IECR_I7_MASK          (0x00000080u)
#define CSL_EDMACC_IECR_I7_SHIFT         (0x00000007u)
#define CSL_EDMACC_IECR_I7_RESETVAL      (0x00000000u)

/*----I7 Tokens----*/
#define CSL_EDMACC_IECR_I7_CLEAR         (0x00000001u)

#define CSL_EDMACC_IECR_I6_MASK          (0x00000040u)
#define CSL_EDMACC_IECR_I6_SHIFT         (0x00000006u)
#define CSL_EDMACC_IECR_I6_RESETVAL      (0x00000000u)

/*----I6 Tokens----*/
#define CSL_EDMACC_IECR_I6_CLEAR         (0x00000001u)

#define CSL_EDMACC_IECR_I5_MASK          (0x00000020u)
#define CSL_EDMACC_IECR_I5_SHIFT         (0x00000005u)
#define CSL_EDMACC_IECR_I5_RESETVAL      (0x00000000u)

/*----I5 Tokens----*/
#define CSL_EDMACC_IECR_I5_CLEAR         (0x00000001u)

#define CSL_EDMACC_IECR_I4_MASK          (0x00000010u)
#define CSL_EDMACC_IECR_I4_SHIFT         (0x00000004u)
#define CSL_EDMACC_IECR_I4_RESETVAL      (0x00000000u)

/*----I4 Tokens----*/
#define CSL_EDMACC_IECR_I4_CLEAR         (0x00000001u)

#define CSL_EDMACC_IECR_I3_MASK          (0x00000008u)
#define CSL_EDMACC_IECR_I3_SHIFT         (0x00000003u)
#define CSL_EDMACC_IECR_I3_RESETVAL      (0x00000000u)

/*----I3 Tokens----*/
#define CSL_EDMACC_IECR_I3_CLEAR         (0x00000001u)

#define CSL_EDMACC_IECR_I2_MASK          (0x00000004u)
#define CSL_EDMACC_IECR_I2_SHIFT         (0x00000002u)
#define CSL_EDMACC_IECR_I2_RESETVAL      (0x00000000u)

/*----I2 Tokens----*/
#define CSL_EDMACC_IECR_I2_CLEAR         (0x00000001u)

#define CSL_EDMACC_IECR_I1_MASK          (0x00000002u)
#define CSL_EDMACC_IECR_I1_SHIFT         (0x00000001u)
#define CSL_EDMACC_IECR_I1_RESETVAL      (0x00000000u)

/*----I1 Tokens----*/
#define CSL_EDMACC_IECR_I1_CLEAR         (0x00000001u)

#define CSL_EDMACC_IECR_I0_MASK          (0x00000001u)
#define CSL_EDMACC_IECR_I0_SHIFT         (0x00000000u)
#define CSL_EDMACC_IECR_I0_RESETVAL      (0x00000000u)

/*----I0 Tokens----*/
#define CSL_EDMACC_IECR_I0_CLEAR         (0x00000001u)

#define CSL_EDMACC_IECR_RESETVAL         (0x00000000u)

/* IECRH */

#define CSL_EDMACC_IECRH_I63_MASK        (0x80000000u)
#define CSL_EDMACC_IECRH_I63_SHIFT       (0x0000001Fu)
#define CSL_EDMACC_IECRH_I63_RESETVAL    (0x00000000u)

/*----I63 Tokens----*/
#define CSL_EDMACC_IECRH_I63_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_I62_MASK        (0x40000000u)
#define CSL_EDMACC_IECRH_I62_SHIFT       (0x0000001Eu)
#define CSL_EDMACC_IECRH_I62_RESETVAL    (0x00000000u)

/*----I62 Tokens----*/
#define CSL_EDMACC_IECRH_I62_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_I61_MASK        (0x20000000u)
#define CSL_EDMACC_IECRH_I61_SHIFT       (0x0000001Du)
#define CSL_EDMACC_IECRH_I61_RESETVAL    (0x00000000u)

/*----I61 Tokens----*/
#define CSL_EDMACC_IECRH_I61_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_I60_MASK        (0x10000000u)
#define CSL_EDMACC_IECRH_I60_SHIFT       (0x0000001Cu)
#define CSL_EDMACC_IECRH_I60_RESETVAL    (0x00000000u)

/*----I60 Tokens----*/
#define CSL_EDMACC_IECRH_I60_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_I59_MASK        (0x08000000u)
#define CSL_EDMACC_IECRH_I59_SHIFT       (0x0000001Bu)
#define CSL_EDMACC_IECRH_I59_RESETVAL    (0x00000000u)

/*----I59 Tokens----*/
#define CSL_EDMACC_IECRH_I59_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_I58_MASK        (0x04000000u)
#define CSL_EDMACC_IECRH_I58_SHIFT       (0x0000001Au)
#define CSL_EDMACC_IECRH_I58_RESETVAL    (0x00000000u)

/*----I58 Tokens----*/
#define CSL_EDMACC_IECRH_I58_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_I57_MASK        (0x02000000u)
#define CSL_EDMACC_IECRH_I57_SHIFT       (0x00000019u)
#define CSL_EDMACC_IECRH_I57_RESETVAL    (0x00000000u)

/*----I57 Tokens----*/
#define CSL_EDMACC_IECRH_I57_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_I56_MASK        (0x01000000u)
#define CSL_EDMACC_IECRH_I56_SHIFT       (0x00000018u)
#define CSL_EDMACC_IECRH_I56_RESETVAL    (0x00000000u)

/*----I56 Tokens----*/
#define CSL_EDMACC_IECRH_I56_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_I55_MASK        (0x00800000u)
#define CSL_EDMACC_IECRH_I55_SHIFT       (0x00000017u)
#define CSL_EDMACC_IECRH_I55_RESETVAL    (0x00000000u)

/*----I55 Tokens----*/
#define CSL_EDMACC_IECRH_I55_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_I54_MASK        (0x00400000u)
#define CSL_EDMACC_IECRH_I54_SHIFT       (0x00000016u)
#define CSL_EDMACC_IECRH_I54_RESETVAL    (0x00000000u)

/*----I54 Tokens----*/
#define CSL_EDMACC_IECRH_I54_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_I53_MASK        (0x00200000u)
#define CSL_EDMACC_IECRH_I53_SHIFT       (0x00000015u)
#define CSL_EDMACC_IECRH_I53_RESETVAL    (0x00000000u)

/*----I53 Tokens----*/
#define CSL_EDMACC_IECRH_I53_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_I52_MASK        (0x00100000u)
#define CSL_EDMACC_IECRH_I52_SHIFT       (0x00000014u)
#define CSL_EDMACC_IECRH_I52_RESETVAL    (0x00000000u)

/*----I52 Tokens----*/
#define CSL_EDMACC_IECRH_I52_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_I51_MASK        (0x00080000u)
#define CSL_EDMACC_IECRH_I51_SHIFT       (0x00000013u)
#define CSL_EDMACC_IECRH_I51_RESETVAL    (0x00000000u)

/*----I51 Tokens----*/
#define CSL_EDMACC_IECRH_I51_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_I50_MASK        (0x00040000u)
#define CSL_EDMACC_IECRH_I50_SHIFT       (0x00000012u)
#define CSL_EDMACC_IECRH_I50_RESETVAL    (0x00000000u)

/*----I50 Tokens----*/
#define CSL_EDMACC_IECRH_I50_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_I49_MASK        (0x00020000u)
#define CSL_EDMACC_IECRH_I49_SHIFT       (0x00000011u)
#define CSL_EDMACC_IECRH_I49_RESETVAL    (0x00000000u)

/*----I49 Tokens----*/
#define CSL_EDMACC_IECRH_I49_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_I48_MASK        (0x00010000u)
#define CSL_EDMACC_IECRH_I48_SHIFT       (0x00000010u)
#define CSL_EDMACC_IECRH_I48_RESETVAL    (0x00000000u)

/*----I48 Tokens----*/
#define CSL_EDMACC_IECRH_I48_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_I47_MASK        (0x00008000u)
#define CSL_EDMACC_IECRH_I47_SHIFT       (0x0000000Fu)
#define CSL_EDMACC_IECRH_I47_RESETVAL    (0x00000000u)

/*----I47 Tokens----*/
#define CSL_EDMACC_IECRH_I47_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_I46_MASK        (0x00004000u)
#define CSL_EDMACC_IECRH_I46_SHIFT       (0x0000000Eu)
#define CSL_EDMACC_IECRH_I46_RESETVAL    (0x00000000u)

/*----I46 Tokens----*/
#define CSL_EDMACC_IECRH_I46_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_I45_MASK        (0x00002000u)
#define CSL_EDMACC_IECRH_I45_SHIFT       (0x0000000Du)
#define CSL_EDMACC_IECRH_I45_RESETVAL    (0x00000000u)

/*----I45 Tokens----*/
#define CSL_EDMACC_IECRH_I45_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_I44_MASK        (0x00001000u)
#define CSL_EDMACC_IECRH_I44_SHIFT       (0x0000000Cu)
#define CSL_EDMACC_IECRH_I44_RESETVAL    (0x00000000u)

/*----I44 Tokens----*/
#define CSL_EDMACC_IECRH_I44_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_I43_MASK        (0x00000800u)
#define CSL_EDMACC_IECRH_I43_SHIFT       (0x0000000Bu)
#define CSL_EDMACC_IECRH_I43_RESETVAL    (0x00000000u)

/*----I43 Tokens----*/
#define CSL_EDMACC_IECRH_I43_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_I42_MASK        (0x00000400u)
#define CSL_EDMACC_IECRH_I42_SHIFT       (0x0000000Au)
#define CSL_EDMACC_IECRH_I42_RESETVAL    (0x00000000u)

/*----I42 Tokens----*/
#define CSL_EDMACC_IECRH_I42_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_I41_MASK        (0x00000200u)
#define CSL_EDMACC_IECRH_I41_SHIFT       (0x00000009u)
#define CSL_EDMACC_IECRH_I41_RESETVAL    (0x00000000u)

/*----I41 Tokens----*/
#define CSL_EDMACC_IECRH_I41_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_I40_MASK        (0x00000100u)
#define CSL_EDMACC_IECRH_I40_SHIFT       (0x00000008u)
#define CSL_EDMACC_IECRH_I40_RESETVAL    (0x00000000u)

/*----I40 Tokens----*/
#define CSL_EDMACC_IECRH_I40_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_I39_MASK        (0x00000080u)
#define CSL_EDMACC_IECRH_I39_SHIFT       (0x00000007u)
#define CSL_EDMACC_IECRH_I39_RESETVAL    (0x00000000u)

/*----I39 Tokens----*/
#define CSL_EDMACC_IECRH_I39_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_I38_MASK        (0x00000040u)
#define CSL_EDMACC_IECRH_I38_SHIFT       (0x00000006u)
#define CSL_EDMACC_IECRH_I38_RESETVAL    (0x00000000u)

/*----I38 Tokens----*/
#define CSL_EDMACC_IECRH_I38_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_I37_MASK        (0x00000020u)
#define CSL_EDMACC_IECRH_I37_SHIFT       (0x00000005u)
#define CSL_EDMACC_IECRH_I37_RESETVAL    (0x00000000u)

/*----I37 Tokens----*/
#define CSL_EDMACC_IECRH_I37_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_I36_MASK        (0x00000010u)
#define CSL_EDMACC_IECRH_I36_SHIFT       (0x00000004u)
#define CSL_EDMACC_IECRH_I36_RESETVAL    (0x00000000u)

/*----I36 Tokens----*/
#define CSL_EDMACC_IECRH_I36_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_I35_MASK        (0x00000008u)
#define CSL_EDMACC_IECRH_I35_SHIFT       (0x00000003u)
#define CSL_EDMACC_IECRH_I35_RESETVAL    (0x00000000u)

/*----I35 Tokens----*/
#define CSL_EDMACC_IECRH_I35_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_I34_MASK        (0x00000004u)
#define CSL_EDMACC_IECRH_I34_SHIFT       (0x00000002u)
#define CSL_EDMACC_IECRH_I34_RESETVAL    (0x00000000u)

/*----I34 Tokens----*/
#define CSL_EDMACC_IECRH_I34_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_I33_MASK        (0x00000002u)
#define CSL_EDMACC_IECRH_I33_SHIFT       (0x00000001u)
#define CSL_EDMACC_IECRH_I33_RESETVAL    (0x00000000u)

/*----I33 Tokens----*/
#define CSL_EDMACC_IECRH_I33_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_I32_MASK        (0x00000001u)
#define CSL_EDMACC_IECRH_I32_SHIFT       (0x00000000u)
#define CSL_EDMACC_IECRH_I32_RESETVAL    (0x00000000u)

/*----I32 Tokens----*/
#define CSL_EDMACC_IECRH_I32_CLEAR       (0x00000001u)

#define CSL_EDMACC_IECRH_RESETVAL        (0x00000000u)

/* IESR */

#define CSL_EDMACC_IESR_I31_MASK         (0x80000000u)
#define CSL_EDMACC_IESR_I31_SHIFT        (0x0000001Fu)
#define CSL_EDMACC_IESR_I31_RESETVAL     (0x00000000u)

/*----I31 Tokens----*/
#define CSL_EDMACC_IESR_I31_SET          (0x00000001u)

#define CSL_EDMACC_IESR_I30_MASK         (0x40000000u)
#define CSL_EDMACC_IESR_I30_SHIFT        (0x0000001Eu)
#define CSL_EDMACC_IESR_I30_RESETVAL     (0x00000000u)

/*----I30 Tokens----*/
#define CSL_EDMACC_IESR_I30_SET          (0x00000001u)

#define CSL_EDMACC_IESR_I29_MASK         (0x20000000u)
#define CSL_EDMACC_IESR_I29_SHIFT        (0x0000001Du)
#define CSL_EDMACC_IESR_I29_RESETVAL     (0x00000000u)

/*----I29 Tokens----*/
#define CSL_EDMACC_IESR_I29_SET          (0x00000001u)

#define CSL_EDMACC_IESR_I28_MASK         (0x10000000u)
#define CSL_EDMACC_IESR_I28_SHIFT        (0x0000001Cu)
#define CSL_EDMACC_IESR_I28_RESETVAL     (0x00000000u)

/*----I28 Tokens----*/
#define CSL_EDMACC_IESR_I28_SET          (0x00000001u)

#define CSL_EDMACC_IESR_I27_MASK         (0x08000000u)
#define CSL_EDMACC_IESR_I27_SHIFT        (0x0000001Bu)
#define CSL_EDMACC_IESR_I27_RESETVAL     (0x00000000u)

/*----I27 Tokens----*/
#define CSL_EDMACC_IESR_I27_SET          (0x00000001u)

#define CSL_EDMACC_IESR_I26_MASK         (0x04000000u)
#define CSL_EDMACC_IESR_I26_SHIFT        (0x0000001Au)
#define CSL_EDMACC_IESR_I26_RESETVAL     (0x00000000u)

/*----I26 Tokens----*/
#define CSL_EDMACC_IESR_I26_SET          (0x00000001u)

#define CSL_EDMACC_IESR_I25_MASK         (0x02000000u)
#define CSL_EDMACC_IESR_I25_SHIFT        (0x00000019u)
#define CSL_EDMACC_IESR_I25_RESETVAL     (0x00000000u)

/*----I25 Tokens----*/
#define CSL_EDMACC_IESR_I25_SET          (0x00000001u)

#define CSL_EDMACC_IESR_I24_MASK         (0x01000000u)
#define CSL_EDMACC_IESR_I24_SHIFT        (0x00000018u)
#define CSL_EDMACC_IESR_I24_RESETVAL     (0x00000000u)

/*----I24 Tokens----*/
#define CSL_EDMACC_IESR_I24_SET          (0x00000001u)

#define CSL_EDMACC_IESR_I23_MASK         (0x00800000u)
#define CSL_EDMACC_IESR_I23_SHIFT        (0x00000017u)
#define CSL_EDMACC_IESR_I23_RESETVAL     (0x00000000u)

/*----I23 Tokens----*/
#define CSL_EDMACC_IESR_I23_SET          (0x00000001u)

#define CSL_EDMACC_IESR_I22_MASK         (0x00400000u)
#define CSL_EDMACC_IESR_I22_SHIFT        (0x00000016u)
#define CSL_EDMACC_IESR_I22_RESETVAL     (0x00000000u)

/*----I22 Tokens----*/
#define CSL_EDMACC_IESR_I22_SET          (0x00000001u)

#define CSL_EDMACC_IESR_I21_MASK         (0x00200000u)
#define CSL_EDMACC_IESR_I21_SHIFT        (0x00000015u)
#define CSL_EDMACC_IESR_I21_RESETVAL     (0x00000000u)

/*----I21 Tokens----*/
#define CSL_EDMACC_IESR_I21_SET          (0x00000001u)

#define CSL_EDMACC_IESR_I20_MASK         (0x00100000u)
#define CSL_EDMACC_IESR_I20_SHIFT        (0x00000014u)
#define CSL_EDMACC_IESR_I20_RESETVAL     (0x00000000u)

/*----I20 Tokens----*/
#define CSL_EDMACC_IESR_I20_SET          (0x00000001u)

#define CSL_EDMACC_IESR_I19_MASK         (0x00080000u)
#define CSL_EDMACC_IESR_I19_SHIFT        (0x00000013u)
#define CSL_EDMACC_IESR_I19_RESETVAL     (0x00000000u)

/*----I19 Tokens----*/
#define CSL_EDMACC_IESR_I19_SET          (0x00000001u)

#define CSL_EDMACC_IESR_I18_MASK         (0x00040000u)
#define CSL_EDMACC_IESR_I18_SHIFT        (0x00000012u)
#define CSL_EDMACC_IESR_I18_RESETVAL     (0x00000000u)

/*----I18 Tokens----*/
#define CSL_EDMACC_IESR_I18_SET          (0x00000001u)

#define CSL_EDMACC_IESR_I17_MASK         (0x00020000u)
#define CSL_EDMACC_IESR_I17_SHIFT        (0x00000011u)
#define CSL_EDMACC_IESR_I17_RESETVAL     (0x00000000u)

/*----I17 Tokens----*/
#define CSL_EDMACC_IESR_I17_SET          (0x00000001u)

#define CSL_EDMACC_IESR_I16_MASK         (0x00010000u)
#define CSL_EDMACC_IESR_I16_SHIFT        (0x00000010u)
#define CSL_EDMACC_IESR_I16_RESETVAL     (0x00000000u)

/*----I16 Tokens----*/
#define CSL_EDMACC_IESR_I16_SET          (0x00000001u)

#define CSL_EDMACC_IESR_I15_MASK         (0x00008000u)
#define CSL_EDMACC_IESR_I15_SHIFT        (0x0000000Fu)
#define CSL_EDMACC_IESR_I15_RESETVAL     (0x00000000u)

/*----I15 Tokens----*/
#define CSL_EDMACC_IESR_I15_SET          (0x00000001u)

#define CSL_EDMACC_IESR_I14_MASK         (0x00004000u)
#define CSL_EDMACC_IESR_I14_SHIFT        (0x0000000Eu)
#define CSL_EDMACC_IESR_I14_RESETVAL     (0x00000000u)

/*----I14 Tokens----*/
#define CSL_EDMACC_IESR_I14_SET          (0x00000001u)

#define CSL_EDMACC_IESR_I13_MASK         (0x00002000u)
#define CSL_EDMACC_IESR_I13_SHIFT        (0x0000000Du)
#define CSL_EDMACC_IESR_I13_RESETVAL     (0x00000000u)

/*----I13 Tokens----*/
#define CSL_EDMACC_IESR_I13_SET          (0x00000001u)

#define CSL_EDMACC_IESR_I12_MASK         (0x00001000u)
#define CSL_EDMACC_IESR_I12_SHIFT        (0x0000000Cu)
#define CSL_EDMACC_IESR_I12_RESETVAL     (0x00000000u)

/*----I12 Tokens----*/
#define CSL_EDMACC_IESR_I12_SET          (0x00000001u)

#define CSL_EDMACC_IESR_I11_MASK         (0x00000800u)
#define CSL_EDMACC_IESR_I11_SHIFT        (0x0000000Bu)
#define CSL_EDMACC_IESR_I11_RESETVAL     (0x00000000u)

/*----I11 Tokens----*/
#define CSL_EDMACC_IESR_I11_SET          (0x00000001u)

#define CSL_EDMACC_IESR_I10_MASK         (0x00000400u)
#define CSL_EDMACC_IESR_I10_SHIFT        (0x0000000Au)
#define CSL_EDMACC_IESR_I10_RESETVAL     (0x00000000u)

/*----I10 Tokens----*/
#define CSL_EDMACC_IESR_I10_SET          (0x00000001u)

#define CSL_EDMACC_IESR_I9_MASK          (0x00000200u)
#define CSL_EDMACC_IESR_I9_SHIFT         (0x00000009u)
#define CSL_EDMACC_IESR_I9_RESETVAL      (0x00000000u)

/*----I9 Tokens----*/
#define CSL_EDMACC_IESR_I9_SET           (0x00000001u)

#define CSL_EDMACC_IESR_I8_MASK          (0x00000100u)
#define CSL_EDMACC_IESR_I8_SHIFT         (0x00000008u)
#define CSL_EDMACC_IESR_I8_RESETVAL      (0x00000000u)

/*----I8 Tokens----*/
#define CSL_EDMACC_IESR_I8_SET           (0x00000001u)

#define CSL_EDMACC_IESR_I7_MASK          (0x00000080u)
#define CSL_EDMACC_IESR_I7_SHIFT         (0x00000007u)
#define CSL_EDMACC_IESR_I7_RESETVAL      (0x00000000u)

/*----I7 Tokens----*/
#define CSL_EDMACC_IESR_I7_SET           (0x00000001u)

#define CSL_EDMACC_IESR_I6_MASK          (0x00000040u)
#define CSL_EDMACC_IESR_I6_SHIFT         (0x00000006u)
#define CSL_EDMACC_IESR_I6_RESETVAL      (0x00000000u)

/*----I6 Tokens----*/
#define CSL_EDMACC_IESR_I6_SET           (0x00000001u)

#define CSL_EDMACC_IESR_I5_MASK          (0x00000020u)
#define CSL_EDMACC_IESR_I5_SHIFT         (0x00000005u)
#define CSL_EDMACC_IESR_I5_RESETVAL      (0x00000000u)

/*----I5 Tokens----*/
#define CSL_EDMACC_IESR_I5_SET           (0x00000001u)

#define CSL_EDMACC_IESR_I4_MASK          (0x00000010u)
#define CSL_EDMACC_IESR_I4_SHIFT         (0x00000004u)
#define CSL_EDMACC_IESR_I4_RESETVAL      (0x00000000u)

/*----I4 Tokens----*/
#define CSL_EDMACC_IESR_I4_SET           (0x00000001u)

#define CSL_EDMACC_IESR_I3_MASK          (0x00000008u)
#define CSL_EDMACC_IESR_I3_SHIFT         (0x00000003u)
#define CSL_EDMACC_IESR_I3_RESETVAL      (0x00000000u)

/*----I3 Tokens----*/
#define CSL_EDMACC_IESR_I3_SET           (0x00000001u)

#define CSL_EDMACC_IESR_I2_MASK          (0x00000004u)
#define CSL_EDMACC_IESR_I2_SHIFT         (0x00000002u)
#define CSL_EDMACC_IESR_I2_RESETVAL      (0x00000000u)

/*----I2 Tokens----*/
#define CSL_EDMACC_IESR_I2_SET           (0x00000001u)

#define CSL_EDMACC_IESR_I1_MASK          (0x00000002u)
#define CSL_EDMACC_IESR_I1_SHIFT         (0x00000001u)
#define CSL_EDMACC_IESR_I1_RESETVAL      (0x00000000u)

/*----I1 Tokens----*/
#define CSL_EDMACC_IESR_I1_SET           (0x00000001u)

#define CSL_EDMACC_IESR_I0_MASK          (0x00000001u)
#define CSL_EDMACC_IESR_I0_SHIFT         (0x00000000u)
#define CSL_EDMACC_IESR_I0_RESETVAL      (0x00000000u)

/*----I0 Tokens----*/
#define CSL_EDMACC_IESR_I0_SET           (0x00000001u)

#define CSL_EDMACC_IESR_RESETVAL         (0x00000000u)

/* IESRH */

#define CSL_EDMACC_IESRH_I63_MASK        (0x80000000u)
#define CSL_EDMACC_IESRH_I63_SHIFT       (0x0000001Fu)
#define CSL_EDMACC_IESRH_I63_RESETVAL    (0x00000000u)

/*----I63 Tokens----*/
#define CSL_EDMACC_IESRH_I63_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_I62_MASK        (0x40000000u)
#define CSL_EDMACC_IESRH_I62_SHIFT       (0x0000001Eu)
#define CSL_EDMACC_IESRH_I62_RESETVAL    (0x00000000u)

/*----I62 Tokens----*/
#define CSL_EDMACC_IESRH_I62_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_I61_MASK        (0x20000000u)
#define CSL_EDMACC_IESRH_I61_SHIFT       (0x0000001Du)
#define CSL_EDMACC_IESRH_I61_RESETVAL    (0x00000000u)

/*----I61 Tokens----*/
#define CSL_EDMACC_IESRH_I61_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_I60_MASK        (0x10000000u)
#define CSL_EDMACC_IESRH_I60_SHIFT       (0x0000001Cu)
#define CSL_EDMACC_IESRH_I60_RESETVAL    (0x00000000u)

/*----I60 Tokens----*/
#define CSL_EDMACC_IESRH_I60_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_I59_MASK        (0x08000000u)
#define CSL_EDMACC_IESRH_I59_SHIFT       (0x0000001Bu)
#define CSL_EDMACC_IESRH_I59_RESETVAL    (0x00000000u)

/*----I59 Tokens----*/
#define CSL_EDMACC_IESRH_I59_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_I58_MASK        (0x04000000u)
#define CSL_EDMACC_IESRH_I58_SHIFT       (0x0000001Au)
#define CSL_EDMACC_IESRH_I58_RESETVAL    (0x00000000u)

/*----I58 Tokens----*/
#define CSL_EDMACC_IESRH_I58_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_I57_MASK        (0x02000000u)
#define CSL_EDMACC_IESRH_I57_SHIFT       (0x00000019u)
#define CSL_EDMACC_IESRH_I57_RESETVAL    (0x00000000u)

/*----I57 Tokens----*/
#define CSL_EDMACC_IESRH_I57_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_I56_MASK        (0x01000000u)
#define CSL_EDMACC_IESRH_I56_SHIFT       (0x00000018u)
#define CSL_EDMACC_IESRH_I56_RESETVAL    (0x00000000u)

/*----I56 Tokens----*/
#define CSL_EDMACC_IESRH_I56_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_I55_MASK        (0x00800000u)
#define CSL_EDMACC_IESRH_I55_SHIFT       (0x00000017u)
#define CSL_EDMACC_IESRH_I55_RESETVAL    (0x00000000u)

/*----I55 Tokens----*/
#define CSL_EDMACC_IESRH_I55_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_I54_MASK        (0x00400000u)
#define CSL_EDMACC_IESRH_I54_SHIFT       (0x00000016u)
#define CSL_EDMACC_IESRH_I54_RESETVAL    (0x00000000u)

/*----I54 Tokens----*/
#define CSL_EDMACC_IESRH_I54_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_I53_MASK        (0x00200000u)
#define CSL_EDMACC_IESRH_I53_SHIFT       (0x00000015u)
#define CSL_EDMACC_IESRH_I53_RESETVAL    (0x00000000u)

/*----I53 Tokens----*/
#define CSL_EDMACC_IESRH_I53_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_I52_MASK        (0x00100000u)
#define CSL_EDMACC_IESRH_I52_SHIFT       (0x00000014u)
#define CSL_EDMACC_IESRH_I52_RESETVAL    (0x00000000u)

/*----I52 Tokens----*/
#define CSL_EDMACC_IESRH_I52_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_I51_MASK        (0x00080000u)
#define CSL_EDMACC_IESRH_I51_SHIFT       (0x00000013u)
#define CSL_EDMACC_IESRH_I51_RESETVAL    (0x00000000u)

/*----I51 Tokens----*/
#define CSL_EDMACC_IESRH_I51_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_I50_MASK        (0x00040000u)
#define CSL_EDMACC_IESRH_I50_SHIFT       (0x00000012u)
#define CSL_EDMACC_IESRH_I50_RESETVAL    (0x00000000u)

/*----I50 Tokens----*/
#define CSL_EDMACC_IESRH_I50_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_I49_MASK        (0x00020000u)
#define CSL_EDMACC_IESRH_I49_SHIFT       (0x00000011u)
#define CSL_EDMACC_IESRH_I49_RESETVAL    (0x00000000u)

/*----I49 Tokens----*/
#define CSL_EDMACC_IESRH_I49_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_I48_MASK        (0x00010000u)
#define CSL_EDMACC_IESRH_I48_SHIFT       (0x00000010u)
#define CSL_EDMACC_IESRH_I48_RESETVAL    (0x00000000u)

/*----I48 Tokens----*/
#define CSL_EDMACC_IESRH_I48_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_I47_MASK        (0x00008000u)
#define CSL_EDMACC_IESRH_I47_SHIFT       (0x0000000Fu)
#define CSL_EDMACC_IESRH_I47_RESETVAL    (0x00000000u)

/*----I47 Tokens----*/
#define CSL_EDMACC_IESRH_I47_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_I46_MASK        (0x00004000u)
#define CSL_EDMACC_IESRH_I46_SHIFT       (0x0000000Eu)
#define CSL_EDMACC_IESRH_I46_RESETVAL    (0x00000000u)

/*----I46 Tokens----*/
#define CSL_EDMACC_IESRH_I46_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_I45_MASK        (0x00002000u)
#define CSL_EDMACC_IESRH_I45_SHIFT       (0x0000000Du)
#define CSL_EDMACC_IESRH_I45_RESETVAL    (0x00000000u)

/*----I45 Tokens----*/
#define CSL_EDMACC_IESRH_I45_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_I44_MASK        (0x00001000u)
#define CSL_EDMACC_IESRH_I44_SHIFT       (0x0000000Cu)
#define CSL_EDMACC_IESRH_I44_RESETVAL    (0x00000000u)

/*----I44 Tokens----*/
#define CSL_EDMACC_IESRH_I44_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_I43_MASK        (0x00000800u)
#define CSL_EDMACC_IESRH_I43_SHIFT       (0x0000000Bu)
#define CSL_EDMACC_IESRH_I43_RESETVAL    (0x00000000u)

/*----I43 Tokens----*/
#define CSL_EDMACC_IESRH_I43_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_I42_MASK        (0x00000400u)
#define CSL_EDMACC_IESRH_I42_SHIFT       (0x0000000Au)
#define CSL_EDMACC_IESRH_I42_RESETVAL    (0x00000000u)

/*----I42 Tokens----*/
#define CSL_EDMACC_IESRH_I42_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_I41_MASK        (0x00000200u)
#define CSL_EDMACC_IESRH_I41_SHIFT       (0x00000009u)
#define CSL_EDMACC_IESRH_I41_RESETVAL    (0x00000000u)

/*----I41 Tokens----*/
#define CSL_EDMACC_IESRH_I41_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_I40_MASK        (0x00000100u)
#define CSL_EDMACC_IESRH_I40_SHIFT       (0x00000008u)
#define CSL_EDMACC_IESRH_I40_RESETVAL    (0x00000000u)

/*----I40 Tokens----*/
#define CSL_EDMACC_IESRH_I40_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_I39_MASK        (0x00000080u)
#define CSL_EDMACC_IESRH_I39_SHIFT       (0x00000007u)
#define CSL_EDMACC_IESRH_I39_RESETVAL    (0x00000000u)

/*----I39 Tokens----*/
#define CSL_EDMACC_IESRH_I39_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_I38_MASK        (0x00000040u)
#define CSL_EDMACC_IESRH_I38_SHIFT       (0x00000006u)
#define CSL_EDMACC_IESRH_I38_RESETVAL    (0x00000000u)

/*----I38 Tokens----*/
#define CSL_EDMACC_IESRH_I38_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_I37_MASK        (0x00000020u)
#define CSL_EDMACC_IESRH_I37_SHIFT       (0x00000005u)
#define CSL_EDMACC_IESRH_I37_RESETVAL    (0x00000000u)

/*----I37 Tokens----*/
#define CSL_EDMACC_IESRH_I37_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_I36_MASK        (0x00000010u)
#define CSL_EDMACC_IESRH_I36_SHIFT       (0x00000004u)
#define CSL_EDMACC_IESRH_I36_RESETVAL    (0x00000000u)

/*----I36 Tokens----*/
#define CSL_EDMACC_IESRH_I36_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_I35_MASK        (0x00000008u)
#define CSL_EDMACC_IESRH_I35_SHIFT       (0x00000003u)
#define CSL_EDMACC_IESRH_I35_RESETVAL    (0x00000000u)

/*----I35 Tokens----*/
#define CSL_EDMACC_IESRH_I35_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_I34_MASK        (0x00000004u)
#define CSL_EDMACC_IESRH_I34_SHIFT       (0x00000002u)
#define CSL_EDMACC_IESRH_I34_RESETVAL    (0x00000000u)

/*----I34 Tokens----*/
#define CSL_EDMACC_IESRH_I34_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_I33_MASK        (0x00000002u)
#define CSL_EDMACC_IESRH_I33_SHIFT       (0x00000001u)
#define CSL_EDMACC_IESRH_I33_RESETVAL    (0x00000000u)

/*----I33 Tokens----*/
#define CSL_EDMACC_IESRH_I33_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_I32_MASK        (0x00000001u)
#define CSL_EDMACC_IESRH_I32_SHIFT       (0x00000000u)
#define CSL_EDMACC_IESRH_I32_RESETVAL    (0x00000000u)

/*----I32 Tokens----*/
#define CSL_EDMACC_IESRH_I32_SET         (0x00000001u)

#define CSL_EDMACC_IESRH_RESETVAL        (0x00000000u)

/* IPR */

#define CSL_EDMACC_IPR_I31_MASK          (0x80000000u)
#define CSL_EDMACC_IPR_I31_SHIFT         (0x0000001Fu)
#define CSL_EDMACC_IPR_I31_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IPR_I30_MASK          (0x40000000u)
#define CSL_EDMACC_IPR_I30_SHIFT         (0x0000001Eu)
#define CSL_EDMACC_IPR_I30_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IPR_I29_MASK          (0x20000000u)
#define CSL_EDMACC_IPR_I29_SHIFT         (0x0000001Du)
#define CSL_EDMACC_IPR_I29_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IPR_I28_MASK          (0x10000000u)
#define CSL_EDMACC_IPR_I28_SHIFT         (0x0000001Cu)
#define CSL_EDMACC_IPR_I28_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IPR_I27_MASK          (0x08000000u)
#define CSL_EDMACC_IPR_I27_SHIFT         (0x0000001Bu)
#define CSL_EDMACC_IPR_I27_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IPR_I26_MASK          (0x04000000u)
#define CSL_EDMACC_IPR_I26_SHIFT         (0x0000001Au)
#define CSL_EDMACC_IPR_I26_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IPR_I25_MASK          (0x02000000u)
#define CSL_EDMACC_IPR_I25_SHIFT         (0x00000019u)
#define CSL_EDMACC_IPR_I25_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IPR_I24_MASK          (0x01000000u)
#define CSL_EDMACC_IPR_I24_SHIFT         (0x00000018u)
#define CSL_EDMACC_IPR_I24_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IPR_I23_MASK          (0x00800000u)
#define CSL_EDMACC_IPR_I23_SHIFT         (0x00000017u)
#define CSL_EDMACC_IPR_I23_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IPR_I22_MASK          (0x00400000u)
#define CSL_EDMACC_IPR_I22_SHIFT         (0x00000016u)
#define CSL_EDMACC_IPR_I22_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IPR_I21_MASK          (0x00200000u)
#define CSL_EDMACC_IPR_I21_SHIFT         (0x00000015u)
#define CSL_EDMACC_IPR_I21_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IPR_I20_MASK          (0x00100000u)
#define CSL_EDMACC_IPR_I20_SHIFT         (0x00000014u)
#define CSL_EDMACC_IPR_I20_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IPR_I19_MASK          (0x00080000u)
#define CSL_EDMACC_IPR_I19_SHIFT         (0x00000013u)
#define CSL_EDMACC_IPR_I19_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IPR_I18_MASK          (0x00040000u)
#define CSL_EDMACC_IPR_I18_SHIFT         (0x00000012u)
#define CSL_EDMACC_IPR_I18_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IPR_I17_MASK          (0x00020000u)
#define CSL_EDMACC_IPR_I17_SHIFT         (0x00000011u)
#define CSL_EDMACC_IPR_I17_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IPR_I16_MASK          (0x00010000u)
#define CSL_EDMACC_IPR_I16_SHIFT         (0x00000010u)
#define CSL_EDMACC_IPR_I16_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IPR_I15_MASK          (0x00008000u)
#define CSL_EDMACC_IPR_I15_SHIFT         (0x0000000Fu)
#define CSL_EDMACC_IPR_I15_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IPR_I14_MASK          (0x00004000u)
#define CSL_EDMACC_IPR_I14_SHIFT         (0x0000000Eu)
#define CSL_EDMACC_IPR_I14_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IPR_I13_MASK          (0x00002000u)
#define CSL_EDMACC_IPR_I13_SHIFT         (0x0000000Du)
#define CSL_EDMACC_IPR_I13_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IPR_I12_MASK          (0x00001000u)
#define CSL_EDMACC_IPR_I12_SHIFT         (0x0000000Cu)
#define CSL_EDMACC_IPR_I12_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IPR_I11_MASK          (0x00000800u)
#define CSL_EDMACC_IPR_I11_SHIFT         (0x0000000Bu)
#define CSL_EDMACC_IPR_I11_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IPR_I10_MASK          (0x00000400u)
#define CSL_EDMACC_IPR_I10_SHIFT         (0x0000000Au)
#define CSL_EDMACC_IPR_I10_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IPR_I9_MASK           (0x00000200u)
#define CSL_EDMACC_IPR_I9_SHIFT          (0x00000009u)
#define CSL_EDMACC_IPR_I9_RESETVAL       (0x00000000u)

#define CSL_EDMACC_IPR_I8_MASK           (0x00000100u)
#define CSL_EDMACC_IPR_I8_SHIFT          (0x00000008u)
#define CSL_EDMACC_IPR_I8_RESETVAL       (0x00000000u)

#define CSL_EDMACC_IPR_I7_MASK           (0x00000080u)
#define CSL_EDMACC_IPR_I7_SHIFT          (0x00000007u)
#define CSL_EDMACC_IPR_I7_RESETVAL       (0x00000000u)

#define CSL_EDMACC_IPR_I6_MASK           (0x00000040u)
#define CSL_EDMACC_IPR_I6_SHIFT          (0x00000006u)
#define CSL_EDMACC_IPR_I6_RESETVAL       (0x00000000u)

#define CSL_EDMACC_IPR_I5_MASK           (0x00000020u)
#define CSL_EDMACC_IPR_I5_SHIFT          (0x00000005u)
#define CSL_EDMACC_IPR_I5_RESETVAL       (0x00000000u)

#define CSL_EDMACC_IPR_I4_MASK           (0x00000010u)
#define CSL_EDMACC_IPR_I4_SHIFT          (0x00000004u)
#define CSL_EDMACC_IPR_I4_RESETVAL       (0x00000000u)

#define CSL_EDMACC_IPR_I3_MASK           (0x00000008u)
#define CSL_EDMACC_IPR_I3_SHIFT          (0x00000003u)
#define CSL_EDMACC_IPR_I3_RESETVAL       (0x00000000u)

#define CSL_EDMACC_IPR_I2_MASK           (0x00000004u)
#define CSL_EDMACC_IPR_I2_SHIFT          (0x00000002u)
#define CSL_EDMACC_IPR_I2_RESETVAL       (0x00000000u)

#define CSL_EDMACC_IPR_I1_MASK           (0x00000002u)
#define CSL_EDMACC_IPR_I1_SHIFT          (0x00000001u)
#define CSL_EDMACC_IPR_I1_RESETVAL       (0x00000000u)

#define CSL_EDMACC_IPR_I0_MASK           (0x00000001u)
#define CSL_EDMACC_IPR_I0_SHIFT          (0x00000000u)
#define CSL_EDMACC_IPR_I0_RESETVAL       (0x00000000u)

#define CSL_EDMACC_IPR_RESETVAL          (0x00000000u)

/* IPRH */

#define CSL_EDMACC_IPRH_I63_MASK         (0x80000000u)
#define CSL_EDMACC_IPRH_I63_SHIFT        (0x0000001Fu)
#define CSL_EDMACC_IPRH_I63_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_I62_MASK         (0x40000000u)
#define CSL_EDMACC_IPRH_I62_SHIFT        (0x0000001Eu)
#define CSL_EDMACC_IPRH_I62_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_I61_MASK         (0x20000000u)
#define CSL_EDMACC_IPRH_I61_SHIFT        (0x0000001Du)
#define CSL_EDMACC_IPRH_I61_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_I60_MASK         (0x10000000u)
#define CSL_EDMACC_IPRH_I60_SHIFT        (0x0000001Cu)
#define CSL_EDMACC_IPRH_I60_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_I59_MASK         (0x08000000u)
#define CSL_EDMACC_IPRH_I59_SHIFT        (0x0000001Bu)
#define CSL_EDMACC_IPRH_I59_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_I58_MASK         (0x04000000u)
#define CSL_EDMACC_IPRH_I58_SHIFT        (0x0000001Au)
#define CSL_EDMACC_IPRH_I58_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_I57_MASK         (0x02000000u)
#define CSL_EDMACC_IPRH_I57_SHIFT        (0x00000019u)
#define CSL_EDMACC_IPRH_I57_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_I56_MASK         (0x01000000u)
#define CSL_EDMACC_IPRH_I56_SHIFT        (0x00000018u)
#define CSL_EDMACC_IPRH_I56_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_I55_MASK         (0x00800000u)
#define CSL_EDMACC_IPRH_I55_SHIFT        (0x00000017u)
#define CSL_EDMACC_IPRH_I55_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_I54_MASK         (0x00400000u)
#define CSL_EDMACC_IPRH_I54_SHIFT        (0x00000016u)
#define CSL_EDMACC_IPRH_I54_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_I53_MASK         (0x00200000u)
#define CSL_EDMACC_IPRH_I53_SHIFT        (0x00000015u)
#define CSL_EDMACC_IPRH_I53_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_I52_MASK         (0x00100000u)
#define CSL_EDMACC_IPRH_I52_SHIFT        (0x00000014u)
#define CSL_EDMACC_IPRH_I52_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_I51_MASK         (0x00080000u)
#define CSL_EDMACC_IPRH_I51_SHIFT        (0x00000013u)
#define CSL_EDMACC_IPRH_I51_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_I50_MASK         (0x00040000u)
#define CSL_EDMACC_IPRH_I50_SHIFT        (0x00000012u)
#define CSL_EDMACC_IPRH_I50_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_I49_MASK         (0x00020000u)
#define CSL_EDMACC_IPRH_I49_SHIFT        (0x00000011u)
#define CSL_EDMACC_IPRH_I49_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_I48_MASK         (0x00010000u)
#define CSL_EDMACC_IPRH_I48_SHIFT        (0x00000010u)
#define CSL_EDMACC_IPRH_I48_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_I47_MASK         (0x00008000u)
#define CSL_EDMACC_IPRH_I47_SHIFT        (0x0000000Fu)
#define CSL_EDMACC_IPRH_I47_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_I46_MASK         (0x00004000u)
#define CSL_EDMACC_IPRH_I46_SHIFT        (0x0000000Eu)
#define CSL_EDMACC_IPRH_I46_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_I45_MASK         (0x00002000u)
#define CSL_EDMACC_IPRH_I45_SHIFT        (0x0000000Du)
#define CSL_EDMACC_IPRH_I45_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_I44_MASK         (0x00001000u)
#define CSL_EDMACC_IPRH_I44_SHIFT        (0x0000000Cu)
#define CSL_EDMACC_IPRH_I44_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_I43_MASK         (0x00000800u)
#define CSL_EDMACC_IPRH_I43_SHIFT        (0x0000000Bu)
#define CSL_EDMACC_IPRH_I43_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_I42_MASK         (0x00000400u)
#define CSL_EDMACC_IPRH_I42_SHIFT        (0x0000000Au)
#define CSL_EDMACC_IPRH_I42_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_I41_MASK         (0x00000200u)
#define CSL_EDMACC_IPRH_I41_SHIFT        (0x00000009u)
#define CSL_EDMACC_IPRH_I41_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_I40_MASK         (0x00000100u)
#define CSL_EDMACC_IPRH_I40_SHIFT        (0x00000008u)
#define CSL_EDMACC_IPRH_I40_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_I39_MASK         (0x00000080u)
#define CSL_EDMACC_IPRH_I39_SHIFT        (0x00000007u)
#define CSL_EDMACC_IPRH_I39_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_I38_MASK         (0x00000040u)
#define CSL_EDMACC_IPRH_I38_SHIFT        (0x00000006u)
#define CSL_EDMACC_IPRH_I38_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_I37_MASK         (0x00000020u)
#define CSL_EDMACC_IPRH_I37_SHIFT        (0x00000005u)
#define CSL_EDMACC_IPRH_I37_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_I36_MASK         (0x00000010u)
#define CSL_EDMACC_IPRH_I36_SHIFT        (0x00000004u)
#define CSL_EDMACC_IPRH_I36_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_I35_MASK         (0x00000008u)
#define CSL_EDMACC_IPRH_I35_SHIFT        (0x00000003u)
#define CSL_EDMACC_IPRH_I35_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_I34_MASK         (0x00000004u)
#define CSL_EDMACC_IPRH_I34_SHIFT        (0x00000002u)
#define CSL_EDMACC_IPRH_I34_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_I33_MASK         (0x00000002u)
#define CSL_EDMACC_IPRH_I33_SHIFT        (0x00000001u)
#define CSL_EDMACC_IPRH_I33_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_I32_MASK         (0x00000001u)
#define CSL_EDMACC_IPRH_I32_SHIFT        (0x00000000u)
#define CSL_EDMACC_IPRH_I32_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_RESETVAL         (0x00000000u)

/* ICR */

#define CSL_EDMACC_ICR_I31_MASK          (0x80000000u)
#define CSL_EDMACC_ICR_I31_SHIFT         (0x0000001Fu)
#define CSL_EDMACC_ICR_I31_RESETVAL      (0x00000000u)

/*----I31 Tokens----*/
#define CSL_EDMACC_ICR_I31_CLEAR         (0x00000001u)

#define CSL_EDMACC_ICR_I30_MASK          (0x40000000u)
#define CSL_EDMACC_ICR_I30_SHIFT         (0x0000001Eu)
#define CSL_EDMACC_ICR_I30_RESETVAL      (0x00000000u)

/*----I30 Tokens----*/
#define CSL_EDMACC_ICR_I30_CLEAR         (0x00000001u)

#define CSL_EDMACC_ICR_I29_MASK          (0x20000000u)
#define CSL_EDMACC_ICR_I29_SHIFT         (0x0000001Du)
#define CSL_EDMACC_ICR_I29_RESETVAL      (0x00000000u)

/*----I29 Tokens----*/
#define CSL_EDMACC_ICR_I29_CLEAR         (0x00000001u)

#define CSL_EDMACC_ICR_I28_MASK          (0x10000000u)
#define CSL_EDMACC_ICR_I28_SHIFT         (0x0000001Cu)
#define CSL_EDMACC_ICR_I28_RESETVAL      (0x00000000u)

/*----I28 Tokens----*/
#define CSL_EDMACC_ICR_I28_CLEAR         (0x00000001u)

#define CSL_EDMACC_ICR_I27_MASK          (0x08000000u)
#define CSL_EDMACC_ICR_I27_SHIFT         (0x0000001Bu)
#define CSL_EDMACC_ICR_I27_RESETVAL      (0x00000000u)

/*----I27 Tokens----*/
#define CSL_EDMACC_ICR_I27_CLEAR         (0x00000001u)

#define CSL_EDMACC_ICR_I26_MASK          (0x04000000u)
#define CSL_EDMACC_ICR_I26_SHIFT         (0x0000001Au)
#define CSL_EDMACC_ICR_I26_RESETVAL      (0x00000000u)

/*----I26 Tokens----*/
#define CSL_EDMACC_ICR_I26_CLEAR         (0x00000001u)

#define CSL_EDMACC_ICR_I25_MASK          (0x02000000u)
#define CSL_EDMACC_ICR_I25_SHIFT         (0x00000019u)
#define CSL_EDMACC_ICR_I25_RESETVAL      (0x00000000u)

/*----I25 Tokens----*/
#define CSL_EDMACC_ICR_I25_CLEAR         (0x00000001u)

#define CSL_EDMACC_ICR_I24_MASK          (0x01000000u)
#define CSL_EDMACC_ICR_I24_SHIFT         (0x00000018u)
#define CSL_EDMACC_ICR_I24_RESETVAL      (0x00000000u)

/*----I24 Tokens----*/
#define CSL_EDMACC_ICR_I24_CLEAR         (0x00000001u)

#define CSL_EDMACC_ICR_I23_MASK          (0x00800000u)
#define CSL_EDMACC_ICR_I23_SHIFT         (0x00000017u)
#define CSL_EDMACC_ICR_I23_RESETVAL      (0x00000000u)

/*----I23 Tokens----*/
#define CSL_EDMACC_ICR_I23_CLEAR         (0x00000001u)

#define CSL_EDMACC_ICR_I22_MASK          (0x00400000u)
#define CSL_EDMACC_ICR_I22_SHIFT         (0x00000016u)
#define CSL_EDMACC_ICR_I22_RESETVAL      (0x00000000u)

/*----I22 Tokens----*/
#define CSL_EDMACC_ICR_I22_CLEAR         (0x00000001u)

#define CSL_EDMACC_ICR_I21_MASK          (0x00200000u)
#define CSL_EDMACC_ICR_I21_SHIFT         (0x00000015u)
#define CSL_EDMACC_ICR_I21_RESETVAL      (0x00000000u)

/*----I21 Tokens----*/
#define CSL_EDMACC_ICR_I21_CLEAR         (0x00000001u)

#define CSL_EDMACC_ICR_I20_MASK          (0x00100000u)
#define CSL_EDMACC_ICR_I20_SHIFT         (0x00000014u)
#define CSL_EDMACC_ICR_I20_RESETVAL      (0x00000000u)

/*----I20 Tokens----*/
#define CSL_EDMACC_ICR_I20_CLEAR         (0x00000001u)

#define CSL_EDMACC_ICR_I19_MASK          (0x00080000u)
#define CSL_EDMACC_ICR_I19_SHIFT         (0x00000013u)
#define CSL_EDMACC_ICR_I19_RESETVAL      (0x00000000u)

/*----I19 Tokens----*/
#define CSL_EDMACC_ICR_I19_CLEAR         (0x00000001u)

#define CSL_EDMACC_ICR_I18_MASK          (0x00040000u)
#define CSL_EDMACC_ICR_I18_SHIFT         (0x00000012u)
#define CSL_EDMACC_ICR_I18_RESETVAL      (0x00000000u)

/*----I18 Tokens----*/
#define CSL_EDMACC_ICR_I18_CLEAR         (0x00000001u)

#define CSL_EDMACC_ICR_I17_MASK          (0x00020000u)
#define CSL_EDMACC_ICR_I17_SHIFT         (0x00000011u)
#define CSL_EDMACC_ICR_I17_RESETVAL      (0x00000000u)

/*----I17 Tokens----*/
#define CSL_EDMACC_ICR_I17_CLEAR         (0x00000001u)

#define CSL_EDMACC_ICR_I16_MASK          (0x00010000u)
#define CSL_EDMACC_ICR_I16_SHIFT         (0x00000010u)
#define CSL_EDMACC_ICR_I16_RESETVAL      (0x00000000u)

/*----I16 Tokens----*/
#define CSL_EDMACC_ICR_I16_CLEAR         (0x00000001u)

#define CSL_EDMACC_ICR_I15_MASK          (0x00008000u)
#define CSL_EDMACC_ICR_I15_SHIFT         (0x0000000Fu)
#define CSL_EDMACC_ICR_I15_RESETVAL      (0x00000000u)

/*----I15 Tokens----*/
#define CSL_EDMACC_ICR_I15_CLEAR         (0x00000001u)

#define CSL_EDMACC_ICR_I14_MASK          (0x00004000u)
#define CSL_EDMACC_ICR_I14_SHIFT         (0x0000000Eu)
#define CSL_EDMACC_ICR_I14_RESETVAL      (0x00000000u)

/*----I14 Tokens----*/
#define CSL_EDMACC_ICR_I14_CLEAR         (0x00000001u)

#define CSL_EDMACC_ICR_I13_MASK          (0x00002000u)
#define CSL_EDMACC_ICR_I13_SHIFT         (0x0000000Du)
#define CSL_EDMACC_ICR_I13_RESETVAL      (0x00000000u)

/*----I13 Tokens----*/
#define CSL_EDMACC_ICR_I13_CLEAR         (0x00000001u)

#define CSL_EDMACC_ICR_I12_MASK          (0x00001000u)
#define CSL_EDMACC_ICR_I12_SHIFT         (0x0000000Cu)
#define CSL_EDMACC_ICR_I12_RESETVAL      (0x00000000u)

/*----I12 Tokens----*/
#define CSL_EDMACC_ICR_I12_CLEAR         (0x00000001u)

#define CSL_EDMACC_ICR_I11_MASK          (0x00000800u)
#define CSL_EDMACC_ICR_I11_SHIFT         (0x0000000Bu)
#define CSL_EDMACC_ICR_I11_RESETVAL      (0x00000000u)

/*----I11 Tokens----*/
#define CSL_EDMACC_ICR_I11_CLEAR         (0x00000001u)

#define CSL_EDMACC_ICR_I10_MASK          (0x00000400u)
#define CSL_EDMACC_ICR_I10_SHIFT         (0x0000000Au)
#define CSL_EDMACC_ICR_I10_RESETVAL      (0x00000000u)

/*----I10 Tokens----*/
#define CSL_EDMACC_ICR_I10_CLEAR         (0x00000001u)

#define CSL_EDMACC_ICR_I9_MASK           (0x00000200u)
#define CSL_EDMACC_ICR_I9_SHIFT          (0x00000009u)
#define CSL_EDMACC_ICR_I9_RESETVAL       (0x00000000u)

/*----I9 Tokens----*/
#define CSL_EDMACC_ICR_I9_CLEAR          (0x00000001u)

#define CSL_EDMACC_ICR_I8_MASK           (0x00000100u)
#define CSL_EDMACC_ICR_I8_SHIFT          (0x00000008u)
#define CSL_EDMACC_ICR_I8_RESETVAL       (0x00000000u)

/*----I8 Tokens----*/
#define CSL_EDMACC_ICR_I8_CLEAR          (0x00000001u)

#define CSL_EDMACC_ICR_I7_MASK           (0x00000080u)
#define CSL_EDMACC_ICR_I7_SHIFT          (0x00000007u)
#define CSL_EDMACC_ICR_I7_RESETVAL       (0x00000000u)

/*----I7 Tokens----*/
#define CSL_EDMACC_ICR_I7_CLEAR          (0x00000001u)

#define CSL_EDMACC_ICR_I6_MASK           (0x00000040u)
#define CSL_EDMACC_ICR_I6_SHIFT          (0x00000006u)
#define CSL_EDMACC_ICR_I6_RESETVAL       (0x00000000u)

/*----I6 Tokens----*/
#define CSL_EDMACC_ICR_I6_CLEAR          (0x00000001u)

#define CSL_EDMACC_ICR_I5_MASK           (0x00000020u)
#define CSL_EDMACC_ICR_I5_SHIFT          (0x00000005u)
#define CSL_EDMACC_ICR_I5_RESETVAL       (0x00000000u)

/*----I5 Tokens----*/
#define CSL_EDMACC_ICR_I5_CLEAR          (0x00000001u)

#define CSL_EDMACC_ICR_I4_MASK           (0x00000010u)
#define CSL_EDMACC_ICR_I4_SHIFT          (0x00000004u)
#define CSL_EDMACC_ICR_I4_RESETVAL       (0x00000000u)

/*----I4 Tokens----*/
#define CSL_EDMACC_ICR_I4_CLEAR          (0x00000001u)

#define CSL_EDMACC_ICR_I3_MASK           (0x00000008u)
#define CSL_EDMACC_ICR_I3_SHIFT          (0x00000003u)
#define CSL_EDMACC_ICR_I3_RESETVAL       (0x00000000u)

/*----I3 Tokens----*/
#define CSL_EDMACC_ICR_I3_CLEAR          (0x00000001u)

#define CSL_EDMACC_ICR_I2_MASK           (0x00000004u)
#define CSL_EDMACC_ICR_I2_SHIFT          (0x00000002u)
#define CSL_EDMACC_ICR_I2_RESETVAL       (0x00000000u)

/*----I2 Tokens----*/
#define CSL_EDMACC_ICR_I2_CLEAR          (0x00000001u)

#define CSL_EDMACC_ICR_I1_MASK           (0x00000002u)
#define CSL_EDMACC_ICR_I1_SHIFT          (0x00000001u)
#define CSL_EDMACC_ICR_I1_RESETVAL       (0x00000000u)

/*----I1 Tokens----*/
#define CSL_EDMACC_ICR_I1_CLEAR          (0x00000001u)

#define CSL_EDMACC_ICR_I0_MASK           (0x00000001u)
#define CSL_EDMACC_ICR_I0_SHIFT          (0x00000000u)
#define CSL_EDMACC_ICR_I0_RESETVAL       (0x00000000u)

/*----I0 Tokens----*/
#define CSL_EDMACC_ICR_I0_CLEAR          (0x00000001u)

#define CSL_EDMACC_ICR_RESETVAL          (0x00000000u)

/* ICRH */

#define CSL_EDMACC_ICRH_I63_MASK         (0x80000000u)
#define CSL_EDMACC_ICRH_I63_SHIFT        (0x0000001Fu)
#define CSL_EDMACC_ICRH_I63_RESETVAL     (0x00000000u)

/*----I63 Tokens----*/
#define CSL_EDMACC_ICRH_I63_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_I62_MASK         (0x40000000u)
#define CSL_EDMACC_ICRH_I62_SHIFT        (0x0000001Eu)
#define CSL_EDMACC_ICRH_I62_RESETVAL     (0x00000000u)

/*----I62 Tokens----*/
#define CSL_EDMACC_ICRH_I62_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_I61_MASK         (0x20000000u)
#define CSL_EDMACC_ICRH_I61_SHIFT        (0x0000001Du)
#define CSL_EDMACC_ICRH_I61_RESETVAL     (0x00000000u)

/*----I61 Tokens----*/
#define CSL_EDMACC_ICRH_I61_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_I60_MASK         (0x10000000u)
#define CSL_EDMACC_ICRH_I60_SHIFT        (0x0000001Cu)
#define CSL_EDMACC_ICRH_I60_RESETVAL     (0x00000000u)

/*----I60 Tokens----*/
#define CSL_EDMACC_ICRH_I60_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_I59_MASK         (0x08000000u)
#define CSL_EDMACC_ICRH_I59_SHIFT        (0x0000001Bu)
#define CSL_EDMACC_ICRH_I59_RESETVAL     (0x00000000u)

/*----I59 Tokens----*/
#define CSL_EDMACC_ICRH_I59_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_I58_MASK         (0x04000000u)
#define CSL_EDMACC_ICRH_I58_SHIFT        (0x0000001Au)
#define CSL_EDMACC_ICRH_I58_RESETVAL     (0x00000000u)

/*----I58 Tokens----*/
#define CSL_EDMACC_ICRH_I58_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_I57_MASK         (0x02000000u)
#define CSL_EDMACC_ICRH_I57_SHIFT        (0x00000019u)
#define CSL_EDMACC_ICRH_I57_RESETVAL     (0x00000000u)

/*----I57 Tokens----*/
#define CSL_EDMACC_ICRH_I57_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_I56_MASK         (0x01000000u)
#define CSL_EDMACC_ICRH_I56_SHIFT        (0x00000018u)
#define CSL_EDMACC_ICRH_I56_RESETVAL     (0x00000000u)

/*----I56 Tokens----*/
#define CSL_EDMACC_ICRH_I56_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_I55_MASK         (0x00800000u)
#define CSL_EDMACC_ICRH_I55_SHIFT        (0x00000017u)
#define CSL_EDMACC_ICRH_I55_RESETVAL     (0x00000000u)

/*----I55 Tokens----*/
#define CSL_EDMACC_ICRH_I55_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_I54_MASK         (0x00400000u)
#define CSL_EDMACC_ICRH_I54_SHIFT        (0x00000016u)
#define CSL_EDMACC_ICRH_I54_RESETVAL     (0x00000000u)

/*----I54 Tokens----*/
#define CSL_EDMACC_ICRH_I54_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_I53_MASK         (0x00200000u)
#define CSL_EDMACC_ICRH_I53_SHIFT        (0x00000015u)
#define CSL_EDMACC_ICRH_I53_RESETVAL     (0x00000000u)

/*----I53 Tokens----*/
#define CSL_EDMACC_ICRH_I53_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_I52_MASK         (0x00100000u)
#define CSL_EDMACC_ICRH_I52_SHIFT        (0x00000014u)
#define CSL_EDMACC_ICRH_I52_RESETVAL     (0x00000000u)

/*----I52 Tokens----*/
#define CSL_EDMACC_ICRH_I52_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_I51_MASK         (0x00080000u)
#define CSL_EDMACC_ICRH_I51_SHIFT        (0x00000013u)
#define CSL_EDMACC_ICRH_I51_RESETVAL     (0x00000000u)

/*----I51 Tokens----*/
#define CSL_EDMACC_ICRH_I51_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_I50_MASK         (0x00040000u)
#define CSL_EDMACC_ICRH_I50_SHIFT        (0x00000012u)
#define CSL_EDMACC_ICRH_I50_RESETVAL     (0x00000000u)

/*----I50 Tokens----*/
#define CSL_EDMACC_ICRH_I50_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_I49_MASK         (0x00020000u)
#define CSL_EDMACC_ICRH_I49_SHIFT        (0x00000011u)
#define CSL_EDMACC_ICRH_I49_RESETVAL     (0x00000000u)

/*----I49 Tokens----*/
#define CSL_EDMACC_ICRH_I49_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_I48_MASK         (0x00010000u)
#define CSL_EDMACC_ICRH_I48_SHIFT        (0x00000010u)
#define CSL_EDMACC_ICRH_I48_RESETVAL     (0x00000000u)

/*----I48 Tokens----*/
#define CSL_EDMACC_ICRH_I48_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_I47_MASK         (0x00008000u)
#define CSL_EDMACC_ICRH_I47_SHIFT        (0x0000000Fu)
#define CSL_EDMACC_ICRH_I47_RESETVAL     (0x00000000u)

/*----I47 Tokens----*/
#define CSL_EDMACC_ICRH_I47_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_I46_MASK         (0x00004000u)
#define CSL_EDMACC_ICRH_I46_SHIFT        (0x0000000Eu)
#define CSL_EDMACC_ICRH_I46_RESETVAL     (0x00000000u)

/*----I46 Tokens----*/
#define CSL_EDMACC_ICRH_I46_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_I45_MASK         (0x00002000u)
#define CSL_EDMACC_ICRH_I45_SHIFT        (0x0000000Du)
#define CSL_EDMACC_ICRH_I45_RESETVAL     (0x00000000u)

/*----I45 Tokens----*/
#define CSL_EDMACC_ICRH_I45_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_I44_MASK         (0x00001000u)
#define CSL_EDMACC_ICRH_I44_SHIFT        (0x0000000Cu)
#define CSL_EDMACC_ICRH_I44_RESETVAL     (0x00000000u)

/*----I44 Tokens----*/
#define CSL_EDMACC_ICRH_I44_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_I43_MASK         (0x00000800u)
#define CSL_EDMACC_ICRH_I43_SHIFT        (0x0000000Bu)
#define CSL_EDMACC_ICRH_I43_RESETVAL     (0x00000000u)

/*----I43 Tokens----*/
#define CSL_EDMACC_ICRH_I43_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_I42_MASK         (0x00000400u)
#define CSL_EDMACC_ICRH_I42_SHIFT        (0x0000000Au)
#define CSL_EDMACC_ICRH_I42_RESETVAL     (0x00000000u)

/*----I42 Tokens----*/
#define CSL_EDMACC_ICRH_I42_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_I41_MASK         (0x00000200u)
#define CSL_EDMACC_ICRH_I41_SHIFT        (0x00000009u)
#define CSL_EDMACC_ICRH_I41_RESETVAL     (0x00000000u)

/*----I41 Tokens----*/
#define CSL_EDMACC_ICRH_I41_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_I40_MASK         (0x00000100u)
#define CSL_EDMACC_ICRH_I40_SHIFT        (0x00000008u)
#define CSL_EDMACC_ICRH_I40_RESETVAL     (0x00000000u)

/*----I40 Tokens----*/
#define CSL_EDMACC_ICRH_I40_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_I39_MASK         (0x00000080u)
#define CSL_EDMACC_ICRH_I39_SHIFT        (0x00000007u)
#define CSL_EDMACC_ICRH_I39_RESETVAL     (0x00000000u)

/*----I39 Tokens----*/
#define CSL_EDMACC_ICRH_I39_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_I38_MASK         (0x00000040u)
#define CSL_EDMACC_ICRH_I38_SHIFT        (0x00000006u)
#define CSL_EDMACC_ICRH_I38_RESETVAL     (0x00000000u)

/*----I38 Tokens----*/
#define CSL_EDMACC_ICRH_I38_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_I37_MASK         (0x00000020u)
#define CSL_EDMACC_ICRH_I37_SHIFT        (0x00000005u)
#define CSL_EDMACC_ICRH_I37_RESETVAL     (0x00000000u)

/*----I37 Tokens----*/
#define CSL_EDMACC_ICRH_I37_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_I36_MASK         (0x00000010u)
#define CSL_EDMACC_ICRH_I36_SHIFT        (0x00000004u)
#define CSL_EDMACC_ICRH_I36_RESETVAL     (0x00000000u)

/*----I36 Tokens----*/
#define CSL_EDMACC_ICRH_I36_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_I35_MASK         (0x00000008u)
#define CSL_EDMACC_ICRH_I35_SHIFT        (0x00000003u)
#define CSL_EDMACC_ICRH_I35_RESETVAL     (0x00000000u)

/*----I35 Tokens----*/
#define CSL_EDMACC_ICRH_I35_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_I34_MASK         (0x00000004u)
#define CSL_EDMACC_ICRH_I34_SHIFT        (0x00000002u)
#define CSL_EDMACC_ICRH_I34_RESETVAL     (0x00000000u)

/*----I34 Tokens----*/
#define CSL_EDMACC_ICRH_I34_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_I33_MASK         (0x00000002u)
#define CSL_EDMACC_ICRH_I33_SHIFT        (0x00000001u)
#define CSL_EDMACC_ICRH_I33_RESETVAL     (0x00000000u)

/*----I33 Tokens----*/
#define CSL_EDMACC_ICRH_I33_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_I32_MASK         (0x00000001u)
#define CSL_EDMACC_ICRH_I32_SHIFT        (0x00000000u)
#define CSL_EDMACC_ICRH_I32_RESETVAL     (0x00000000u)

/*----I32 Tokens----*/
#define CSL_EDMACC_ICRH_I32_CLEAR        (0x00000001u)

#define CSL_EDMACC_ICRH_RESETVAL         (0x00000000u)

/* IEVAL */

#define CSL_EDMACC_IEVAL_SET_MASK        (0x00000002u)
#define CSL_EDMACC_IEVAL_SET_SHIFT       (0x00000001u)
#define CSL_EDMACC_IEVAL_SET_RESETVAL    (0x00000000u)

/*----SET Tokens----*/
#define CSL_EDMACC_IEVAL_SET_SET         (0x00000001u)

#define CSL_EDMACC_IEVAL_EVAL_MASK       (0x00000001u)
#define CSL_EDMACC_IEVAL_EVAL_SHIFT      (0x00000000u)
#define CSL_EDMACC_IEVAL_EVAL_RESETVAL   (0x00000000u)

/*----EVAL Tokens----*/
#define CSL_EDMACC_IEVAL_EVAL_EVAL       (0x00000001u)

#define CSL_EDMACC_IEVAL_RESETVAL        (0x00000000u)

/* QER */

#define CSL_EDMACC_QER_E7_MASK           (0x00000080u)
#define CSL_EDMACC_QER_E7_SHIFT          (0x00000007u)
#define CSL_EDMACC_QER_E7_RESETVAL       (0x00000000u)

#define CSL_EDMACC_QER_E6_MASK           (0x00000040u)
#define CSL_EDMACC_QER_E6_SHIFT          (0x00000006u)
#define CSL_EDMACC_QER_E6_RESETVAL       (0x00000000u)

#define CSL_EDMACC_QER_E5_MASK           (0x00000020u)
#define CSL_EDMACC_QER_E5_SHIFT          (0x00000005u)
#define CSL_EDMACC_QER_E5_RESETVAL       (0x00000000u)

#define CSL_EDMACC_QER_E4_MASK           (0x00000010u)
#define CSL_EDMACC_QER_E4_SHIFT          (0x00000004u)
#define CSL_EDMACC_QER_E4_RESETVAL       (0x00000000u)

#define CSL_EDMACC_QER_E3_MASK           (0x00000008u)
#define CSL_EDMACC_QER_E3_SHIFT          (0x00000003u)
#define CSL_EDMACC_QER_E3_RESETVAL       (0x00000000u)

#define CSL_EDMACC_QER_E2_MASK           (0x00000004u)
#define CSL_EDMACC_QER_E2_SHIFT          (0x00000002u)
#define CSL_EDMACC_QER_E2_RESETVAL       (0x00000000u)

#define CSL_EDMACC_QER_E1_MASK           (0x00000002u)
#define CSL_EDMACC_QER_E1_SHIFT          (0x00000001u)
#define CSL_EDMACC_QER_E1_RESETVAL       (0x00000000u)

#define CSL_EDMACC_QER_E0_MASK           (0x00000001u)
#define CSL_EDMACC_QER_E0_SHIFT          (0x00000000u)
#define CSL_EDMACC_QER_E0_RESETVAL       (0x00000000u)

#define CSL_EDMACC_QER_RESETVAL          (0x00000000u)

/* QEER */

#define CSL_EDMACC_QEER_E7_MASK          (0x00000080u)
#define CSL_EDMACC_QEER_E7_SHIFT         (0x00000007u)
#define CSL_EDMACC_QEER_E7_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QEER_E6_MASK          (0x00000040u)
#define CSL_EDMACC_QEER_E6_SHIFT         (0x00000006u)
#define CSL_EDMACC_QEER_E6_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QEER_E5_MASK          (0x00000020u)
#define CSL_EDMACC_QEER_E5_SHIFT         (0x00000005u)
#define CSL_EDMACC_QEER_E5_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QEER_E4_MASK          (0x00000010u)
#define CSL_EDMACC_QEER_E4_SHIFT         (0x00000004u)
#define CSL_EDMACC_QEER_E4_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QEER_E3_MASK          (0x00000008u)
#define CSL_EDMACC_QEER_E3_SHIFT         (0x00000003u)
#define CSL_EDMACC_QEER_E3_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QEER_E2_MASK          (0x00000004u)
#define CSL_EDMACC_QEER_E2_SHIFT         (0x00000002u)
#define CSL_EDMACC_QEER_E2_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QEER_E1_MASK          (0x00000002u)
#define CSL_EDMACC_QEER_E1_SHIFT         (0x00000001u)
#define CSL_EDMACC_QEER_E1_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QEER_E0_MASK          (0x00000001u)
#define CSL_EDMACC_QEER_E0_SHIFT         (0x00000000u)
#define CSL_EDMACC_QEER_E0_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QEER_RESETVAL         (0x00000000u)

/* QEECR */

#define CSL_EDMACC_QEECR_E7_MASK         (0x00000080u)
#define CSL_EDMACC_QEECR_E7_SHIFT        (0x00000007u)
#define CSL_EDMACC_QEECR_E7_RESETVAL     (0x00000000u)

/*----E7 Tokens----*/
#define CSL_EDMACC_QEECR_E7_CLEAR        (0x00000001u)

#define CSL_EDMACC_QEECR_E6_MASK         (0x00000040u)
#define CSL_EDMACC_QEECR_E6_SHIFT        (0x00000006u)
#define CSL_EDMACC_QEECR_E6_RESETVAL     (0x00000000u)

/*----E6 Tokens----*/
#define CSL_EDMACC_QEECR_E6_CLEAR        (0x00000001u)

#define CSL_EDMACC_QEECR_E5_MASK         (0x00000020u)
#define CSL_EDMACC_QEECR_E5_SHIFT        (0x00000005u)
#define CSL_EDMACC_QEECR_E5_RESETVAL     (0x00000000u)

/*----E5 Tokens----*/
#define CSL_EDMACC_QEECR_E5_CLEAR        (0x00000001u)

#define CSL_EDMACC_QEECR_E4_MASK         (0x00000010u)
#define CSL_EDMACC_QEECR_E4_SHIFT        (0x00000004u)
#define CSL_EDMACC_QEECR_E4_RESETVAL     (0x00000000u)

/*----E4 Tokens----*/
#define CSL_EDMACC_QEECR_E4_CLEAR        (0x00000001u)

#define CSL_EDMACC_QEECR_E3_MASK         (0x00000008u)
#define CSL_EDMACC_QEECR_E3_SHIFT        (0x00000003u)
#define CSL_EDMACC_QEECR_E3_RESETVAL     (0x00000000u)

/*----E3 Tokens----*/
#define CSL_EDMACC_QEECR_E3_CLEAR        (0x00000001u)

#define CSL_EDMACC_QEECR_E2_MASK         (0x00000004u)
#define CSL_EDMACC_QEECR_E2_SHIFT        (0x00000002u)
#define CSL_EDMACC_QEECR_E2_RESETVAL     (0x00000000u)

/*----E2 Tokens----*/
#define CSL_EDMACC_QEECR_E2_CLEAR        (0x00000001u)

#define CSL_EDMACC_QEECR_E1_MASK         (0x00000002u)
#define CSL_EDMACC_QEECR_E1_SHIFT        (0x00000001u)
#define CSL_EDMACC_QEECR_E1_RESETVAL     (0x00000000u)

/*----E1 Tokens----*/
#define CSL_EDMACC_QEECR_E1_CLEAR        (0x00000001u)

#define CSL_EDMACC_QEECR_E0_MASK         (0x00000001u)
#define CSL_EDMACC_QEECR_E0_SHIFT        (0x00000000u)
#define CSL_EDMACC_QEECR_E0_RESETVAL     (0x00000000u)

/*----E0 Tokens----*/
#define CSL_EDMACC_QEECR_E0_CLEAR        (0x00000001u)

#define CSL_EDMACC_QEECR_RESETVAL        (0x00000000u)

/* QEESR */

#define CSL_EDMACC_QEESR_E7_MASK         (0x00000080u)
#define CSL_EDMACC_QEESR_E7_SHIFT        (0x00000007u)
#define CSL_EDMACC_QEESR_E7_RESETVAL     (0x00000000u)

/*----E7 Tokens----*/
#define CSL_EDMACC_QEESR_E7_SET          (0x00000001u)

#define CSL_EDMACC_QEESR_E6_MASK         (0x00000040u)
#define CSL_EDMACC_QEESR_E6_SHIFT        (0x00000006u)
#define CSL_EDMACC_QEESR_E6_RESETVAL     (0x00000000u)

/*----E6 Tokens----*/
#define CSL_EDMACC_QEESR_E6_SET          (0x00000001u)

#define CSL_EDMACC_QEESR_E5_MASK         (0x00000020u)
#define CSL_EDMACC_QEESR_E5_SHIFT        (0x00000005u)
#define CSL_EDMACC_QEESR_E5_RESETVAL     (0x00000000u)

/*----E5 Tokens----*/
#define CSL_EDMACC_QEESR_E5_SET          (0x00000001u)

#define CSL_EDMACC_QEESR_E4_MASK         (0x00000010u)
#define CSL_EDMACC_QEESR_E4_SHIFT        (0x00000004u)
#define CSL_EDMACC_QEESR_E4_RESETVAL     (0x00000000u)

/*----E4 Tokens----*/
#define CSL_EDMACC_QEESR_E4_SET          (0x00000001u)

#define CSL_EDMACC_QEESR_E3_MASK         (0x00000008u)
#define CSL_EDMACC_QEESR_E3_SHIFT        (0x00000003u)
#define CSL_EDMACC_QEESR_E3_RESETVAL     (0x00000000u)

/*----E3 Tokens----*/
#define CSL_EDMACC_QEESR_E3_SET          (0x00000001u)

#define CSL_EDMACC_QEESR_E2_MASK         (0x00000004u)
#define CSL_EDMACC_QEESR_E2_SHIFT        (0x00000002u)
#define CSL_EDMACC_QEESR_E2_RESETVAL     (0x00000000u)

/*----E2 Tokens----*/
#define CSL_EDMACC_QEESR_E2_SET          (0x00000001u)

#define CSL_EDMACC_QEESR_E1_MASK         (0x00000002u)
#define CSL_EDMACC_QEESR_E1_SHIFT        (0x00000001u)
#define CSL_EDMACC_QEESR_E1_RESETVAL     (0x00000000u)

/*----E1 Tokens----*/
#define CSL_EDMACC_QEESR_E1_SET          (0x00000001u)

#define CSL_EDMACC_QEESR_E0_MASK         (0x00000001u)
#define CSL_EDMACC_QEESR_E0_SHIFT        (0x00000000u)
#define CSL_EDMACC_QEESR_E0_RESETVAL     (0x00000000u)

/*----E0 Tokens----*/
#define CSL_EDMACC_QEESR_E0_SET          (0x00000001u)

#define CSL_EDMACC_QEESR_RESETVAL        (0x00000000u)

/* QSER */

#define CSL_EDMACC_QSER_E7_MASK          (0x00000080u)
#define CSL_EDMACC_QSER_E7_SHIFT         (0x00000007u)
#define CSL_EDMACC_QSER_E7_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QSER_E6_MASK          (0x00000040u)
#define CSL_EDMACC_QSER_E6_SHIFT         (0x00000006u)
#define CSL_EDMACC_QSER_E6_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QSER_E5_MASK          (0x00000020u)
#define CSL_EDMACC_QSER_E5_SHIFT         (0x00000005u)
#define CSL_EDMACC_QSER_E5_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QSER_E4_MASK          (0x00000010u)
#define CSL_EDMACC_QSER_E4_SHIFT         (0x00000004u)
#define CSL_EDMACC_QSER_E4_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QSER_E3_MASK          (0x00000008u)
#define CSL_EDMACC_QSER_E3_SHIFT         (0x00000003u)
#define CSL_EDMACC_QSER_E3_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QSER_E2_MASK          (0x00000004u)
#define CSL_EDMACC_QSER_E2_SHIFT         (0x00000002u)
#define CSL_EDMACC_QSER_E2_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QSER_E1_MASK          (0x00000002u)
#define CSL_EDMACC_QSER_E1_SHIFT         (0x00000001u)
#define CSL_EDMACC_QSER_E1_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QSER_E0_MASK          (0x00000001u)
#define CSL_EDMACC_QSER_E0_SHIFT         (0x00000000u)
#define CSL_EDMACC_QSER_E0_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QSER_RESETVAL         (0x00000000u)

/* QSECR */

#define CSL_EDMACC_QSECR_E7_MASK         (0x00000080u)
#define CSL_EDMACC_QSECR_E7_SHIFT        (0x00000007u)
#define CSL_EDMACC_QSECR_E7_RESETVAL     (0x00000000u)

/*----E7 Tokens----*/
#define CSL_EDMACC_QSECR_E7_CLEAR        (0x00000001u)

#define CSL_EDMACC_QSECR_E6_MASK         (0x00000040u)
#define CSL_EDMACC_QSECR_E6_SHIFT        (0x00000006u)
#define CSL_EDMACC_QSECR_E6_RESETVAL     (0x00000000u)

/*----E6 Tokens----*/
#define CSL_EDMACC_QSECR_E6_CLEAR        (0x00000001u)

#define CSL_EDMACC_QSECR_E5_MASK         (0x00000020u)
#define CSL_EDMACC_QSECR_E5_SHIFT        (0x00000005u)
#define CSL_EDMACC_QSECR_E5_RESETVAL     (0x00000000u)

/*----E5 Tokens----*/
#define CSL_EDMACC_QSECR_E5_CLEAR        (0x00000001u)

#define CSL_EDMACC_QSECR_E4_MASK         (0x00000010u)
#define CSL_EDMACC_QSECR_E4_SHIFT        (0x00000004u)
#define CSL_EDMACC_QSECR_E4_RESETVAL     (0x00000000u)

/*----E4 Tokens----*/
#define CSL_EDMACC_QSECR_E4_CLEAR        (0x00000001u)

#define CSL_EDMACC_QSECR_E3_MASK         (0x00000008u)
#define CSL_EDMACC_QSECR_E3_SHIFT        (0x00000003u)
#define CSL_EDMACC_QSECR_E3_RESETVAL     (0x00000000u)

/*----E3 Tokens----*/
#define CSL_EDMACC_QSECR_E3_CLEAR        (0x00000001u)

#define CSL_EDMACC_QSECR_E2_MASK         (0x00000004u)
#define CSL_EDMACC_QSECR_E2_SHIFT        (0x00000002u)
#define CSL_EDMACC_QSECR_E2_RESETVAL     (0x00000000u)

/*----E2 Tokens----*/
#define CSL_EDMACC_QSECR_E2_CLEAR        (0x00000001u)

#define CSL_EDMACC_QSECR_E1_MASK         (0x00000002u)
#define CSL_EDMACC_QSECR_E1_SHIFT        (0x00000001u)
#define CSL_EDMACC_QSECR_E1_RESETVAL     (0x00000000u)

/*----E1 Tokens----*/
#define CSL_EDMACC_QSECR_E1_CLEAR        (0x00000001u)

#define CSL_EDMACC_QSECR_E0_MASK         (0x00000001u)
#define CSL_EDMACC_QSECR_E0_SHIFT        (0x00000000u)
#define CSL_EDMACC_QSECR_E0_RESETVAL     (0x00000000u)

/*----E0 Tokens----*/
#define CSL_EDMACC_QSECR_E0_CLEAR        (0x00000001u)

#define CSL_EDMACC_QSECR_RESETVAL        (0x00000000u)

/* OPT */

#define CSL_EDMACC_OPT_PRIV_MASK         (0x80000000u)
#define CSL_EDMACC_OPT_PRIV_SHIFT        (0x0000001Fu)
#define CSL_EDMACC_OPT_PRIV_RESETVAL     (0x00000000u)

/*----PRIV Tokens----*/
#define CSL_EDMACC_OPT_PRIV_USER         (0x00000000u)
#define CSL_EDMACC_OPT_PRIV_SUPERVISOR   (0x00000001u)

#define CSL_EDMACC_OPT_SECURE_MASK       (0x40000000u)
#define CSL_EDMACC_OPT_SECURE_SHIFT      (0x0000001Eu)
#define CSL_EDMACC_OPT_SECURE_RESETVAL   (0x00000000u)

/*----SECURE Tokens----*/
#define CSL_EDMACC_OPT_SECURE_SECURE     (0x00000000u)
#define CSL_EDMACC_OPT_SECURE_NONSECURE  (0x00000001u)

#define CSL_EDMACC_OPT_PRIVID_MASK       (0x0F000000u)
#define CSL_EDMACC_OPT_PRIVID_SHIFT      (0x00000018u)
#define CSL_EDMACC_OPT_PRIVID_RESETVAL   (0x00000000u)

#define CSL_EDMACC_OPT_ITCCHEN_MASK      (0x00800000u)
#define CSL_EDMACC_OPT_ITCCHEN_SHIFT     (0x00000017u)
#define CSL_EDMACC_OPT_ITCCHEN_RESETVAL  (0x00000000u)

/*----ITCCHEN Tokens----*/
#define CSL_EDMACC_OPT_ITCCHEN_DISABLE   (0x00000000u)
#define CSL_EDMACC_OPT_ITCCHEN_ENABLE    (0x00000001u)

#define CSL_EDMACC_OPT_TCCHEN_MASK       (0x00400000u)
#define CSL_EDMACC_OPT_TCCHEN_SHIFT      (0x00000016u)
#define CSL_EDMACC_OPT_TCCHEN_RESETVAL   (0x00000000u)

/*----TCCHEN Tokens----*/
#define CSL_EDMACC_OPT_TCCHEN_DISABLE    (0x00000000u)
#define CSL_EDMACC_OPT_TCCHEN_ENABLE     (0x00000001u)

#define CSL_EDMACC_OPT_ITCINTEN_MASK     (0x00200000u)
#define CSL_EDMACC_OPT_ITCINTEN_SHIFT    (0x00000015u)
#define CSL_EDMACC_OPT_ITCINTEN_RESETVAL (0x00000000u)

/*----ITCINTEN Tokens----*/
#define CSL_EDMACC_OPT_ITCINTEN_DISABLE  (0x00000000u)
#define CSL_EDMACC_OPT_ITCINTEN_ENABLE   (0x00000001u)

#define CSL_EDMACC_OPT_TCINTEN_MASK      (0x00100000u)
#define CSL_EDMACC_OPT_TCINTEN_SHIFT     (0x00000014u)
#define CSL_EDMACC_OPT_TCINTEN_RESETVAL  (0x00000000u)

/*----TCINTEN Tokens----*/
#define CSL_EDMACC_OPT_TCINTEN_DISABLE   (0x00000000u)
#define CSL_EDMACC_OPT_TCINTEN_ENABLE    (0x00000001u)

#define CSL_EDMACC_OPT_WIMODE_MASK       (0x00080000u)
#define CSL_EDMACC_OPT_WIMODE_SHIFT      (0x00000013u)
#define CSL_EDMACC_OPT_WIMODE_RESETVAL   (0x00000000u)

/*----WIMODE Tokens----*/
#define CSL_EDMACC_OPT_WIMODE_NORMAL     (0x00000000u)
#define CSL_EDMACC_OPT_WIMODE_BKWDCOMPAT (0x00000001u)

#define CSL_EDMACC_OPT_TCC_MASK          (0x0003F000u)
#define CSL_EDMACC_OPT_TCC_SHIFT         (0x0000000Cu)
#define CSL_EDMACC_OPT_TCC_RESETVAL      (0x00000000u)

#define CSL_EDMACC_OPT_TCCMODE_MASK      (0x00000800u)
#define CSL_EDMACC_OPT_TCCMODE_SHIFT     (0x0000000Bu)
#define CSL_EDMACC_OPT_TCCMODE_RESETVAL  (0x00000000u)

/*----TCCMODE Tokens----*/
#define CSL_EDMACC_OPT_TCCMODE_NORMAL    (0x00000000u)
#define CSL_EDMACC_OPT_TCCMODE_EARY      (0x00000001u)

#define CSL_EDMACC_OPT_FWID_MASK         (0x00000700u)
#define CSL_EDMACC_OPT_FWID_SHIFT        (0x00000008u)
#define CSL_EDMACC_OPT_FWID_RESETVAL     (0x00000000u)

/*----FWID Tokens----*/
#define CSL_EDMACC_OPT_FWID_8            (0x00000000u)
#define CSL_EDMACC_OPT_FWID_16           (0x00000001u)
#define CSL_EDMACC_OPT_FWID_32           (0x00000002u)
#define CSL_EDMACC_OPT_FWID_64           (0x00000003u)
#define CSL_EDMACC_OPT_FWID_128          (0x00000004u)
#define CSL_EDMACC_OPT_FWID_256          (0x00000005u)

#define CSL_EDMACC_OPT_STATIC_MASK       (0x00000008u)
#define CSL_EDMACC_OPT_STATIC_SHIFT      (0x00000003u)
#define CSL_EDMACC_OPT_STATIC_RESETVAL   (0x00000000u)

/*----STATIC Tokens----*/
#define CSL_EDMACC_OPT_STATIC_NORMAL     (0x00000000u)
#define CSL_EDMACC_OPT_STATIC_STATIC     (0x00000001u)

#define CSL_EDMACC_OPT_SYNCDIM_MASK      (0x00000004u)
#define CSL_EDMACC_OPT_SYNCDIM_SHIFT     (0x00000002u)
#define CSL_EDMACC_OPT_SYNCDIM_RESETVAL  (0x00000000u)

/*----SYNCDIM Tokens----*/
#define CSL_EDMACC_OPT_SYNCDIM_ASYNC     (0x00000000u)
#define CSL_EDMACC_OPT_SYNCDIM_ABSYNC    (0x00000001u)

#define CSL_EDMACC_OPT_DAM_MASK          (0x00000002u)
#define CSL_EDMACC_OPT_DAM_SHIFT         (0x00000001u)
#define CSL_EDMACC_OPT_DAM_RESETVAL      (0x00000000u)

/*----DAM Tokens----*/
#define CSL_EDMACC_OPT_DAM_INCR          (0x00000000u)
#define CSL_EDMACC_OPT_DAM_FIFO          (0x00000001u)

#define CSL_EDMACC_OPT_SAM_MASK          (0x00000001u)
#define CSL_EDMACC_OPT_SAM_SHIFT         (0x00000000u)
#define CSL_EDMACC_OPT_SAM_RESETVAL      (0x00000000u)

/*----SAM Tokens----*/
#define CSL_EDMACC_OPT_SAM_INCR          (0x00000000u)
#define CSL_EDMACC_OPT_SAM_FIFO          (0x00000001u)

#define CSL_EDMACC_OPT_RESETVAL          (0x00000000u)

/* SRC */

#define CSL_EDMACC_SRC_SRC_MASK          (0xFFFFFFFFu)
#define CSL_EDMACC_SRC_SRC_SHIFT         (0x00000000u)
#define CSL_EDMACC_SRC_SRC_RESETVAL      (0x00000000u)

#define CSL_EDMACC_SRC_RESETVAL          (0x00000000u)

/* A_B_CNT */

#define CSL_EDMACC_A_B_CNT_BCNT_MASK     (0xFFFF0000u)
#define CSL_EDMACC_A_B_CNT_BCNT_SHIFT    (0x00000010u)
#define CSL_EDMACC_A_B_CNT_BCNT_RESETVAL (0x00000000u)

#define CSL_EDMACC_A_B_CNT_ACNT_MASK     (0x0000FFFFu)
#define CSL_EDMACC_A_B_CNT_ACNT_SHIFT    (0x00000000u)
#define CSL_EDMACC_A_B_CNT_ACNT_RESETVAL (0x00000000u)

#define CSL_EDMACC_A_B_CNT_RESETVAL      (0x00000000u)

/* DST */

#define CSL_EDMACC_DST_DST_MASK          (0xFFFFFFFFu)
#define CSL_EDMACC_DST_DST_SHIFT         (0x00000000u)
#define CSL_EDMACC_DST_DST_RESETVAL      (0x00000000u)

#define CSL_EDMACC_DST_RESETVAL          (0x00000000u)

/* SRC_DST_BIDX */

#define CSL_EDMACC_SRC_DST_BIDX_DSTBIDX_MASK (0xFFFF0000u)
#define CSL_EDMACC_SRC_DST_BIDX_DSTBIDX_SHIFT (0x00000010u)
#define CSL_EDMACC_SRC_DST_BIDX_DSTBIDX_RESETVAL (0x00000000u)

#define CSL_EDMACC_SRC_DST_BIDX_SRCBIDX_MASK (0x0000FFFFu)
#define CSL_EDMACC_SRC_DST_BIDX_SRCBIDX_SHIFT (0x00000000u)
#define CSL_EDMACC_SRC_DST_BIDX_SRCBIDX_RESETVAL (0x00000000u)

#define CSL_EDMACC_SRC_DST_BIDX_RESETVAL (0x00000000u)

/* LINK_BCNTRLD */

#define CSL_EDMACC_LINK_BCNTRLD_BCNTRLD_MASK (0xFFFF0000u)
#define CSL_EDMACC_LINK_BCNTRLD_BCNTRLD_SHIFT (0x00000010u)
#define CSL_EDMACC_LINK_BCNTRLD_BCNTRLD_RESETVAL (0x00000000u)

#define CSL_EDMACC_LINK_BCNTRLD_LINK_MASK (0x0000FFFFu)
#define CSL_EDMACC_LINK_BCNTRLD_LINK_SHIFT (0x00000000u)
#define CSL_EDMACC_LINK_BCNTRLD_LINK_RESETVAL (0x00000000u)

#define CSL_EDMACC_LINK_BCNTRLD_RESETVAL (0x00000000u)

/* SRC_DST_CIDX */

#define CSL_EDMACC_SRC_DST_CIDX_DSTCIDX_MASK (0xFFFF0000u)
#define CSL_EDMACC_SRC_DST_CIDX_DSTCIDX_SHIFT (0x00000010u)
#define CSL_EDMACC_SRC_DST_CIDX_DSTCIDX_RESETVAL (0x00000000u)

#define CSL_EDMACC_SRC_DST_CIDX_SRCCIDX_MASK (0x0000FFFFu)
#define CSL_EDMACC_SRC_DST_CIDX_SRCCIDX_SHIFT (0x00000000u)
#define CSL_EDMACC_SRC_DST_CIDX_SRCCIDX_RESETVAL (0x00000000u)

#define CSL_EDMACC_SRC_DST_CIDX_RESETVAL (0x00000000u)

/* CCNT */

#define CSL_EDMACC_CCNT_CCNT_MASK        (0x0000FFFFu)
#define CSL_EDMACC_CCNT_CCNT_SHIFT       (0x00000000u)
#define CSL_EDMACC_CCNT_CCNT_RESETVAL    (0x00000000u)

#define CSL_EDMACC_CCNT_RESETVAL         (0x00000000u)

/* ER */

#define CSL_EDMACC_ER_REG_MASK           (0xFFFFFFFFu)
#define CSL_EDMACC_ER_REG_SHIFT          (0x00000000u)
#define CSL_EDMACC_ER_REG_RESETVAL       (0x00000000u)

#define CSL_EDMACC_ER_RESETVAL           (0x00000000u)

/* ERH */

#define CSL_EDMACC_ERH_REG_MASK          (0xFFFFFFFFu)
#define CSL_EDMACC_ERH_REG_SHIFT         (0x00000000u)
#define CSL_EDMACC_ERH_REG_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ERH_RESETVAL          (0x00000000u)

/* ECR */

#define CSL_EDMACC_ECR_REG_MASK          (0xFFFFFFFFu)
#define CSL_EDMACC_ECR_REG_SHIFT         (0x00000000u)
#define CSL_EDMACC_ECR_REG_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ECR_RESETVAL          (0x00000000u)

/* ECRH */

#define CSL_EDMACC_ECRH_REG_MASK         (0xFFFFFFFFu)
#define CSL_EDMACC_ECRH_REG_SHIFT        (0x00000000u)
#define CSL_EDMACC_ECRH_REG_RESETVAL     (0x00000000u)

#define CSL_EDMACC_ECRH_RESETVAL         (0x00000000u)

/* ESR */

#define CSL_EDMACC_ESR_REG_MASK          (0xFFFFFFFFu)
#define CSL_EDMACC_ESR_REG_SHIFT         (0x00000000u)
#define CSL_EDMACC_ESR_REG_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ESR_RESETVAL          (0x00000000u)

/* ESRH */

#define CSL_EDMACC_ESRH_REG_MASK         (0xFFFFFFFFu)
#define CSL_EDMACC_ESRH_REG_SHIFT        (0x00000000u)
#define CSL_EDMACC_ESRH_REG_RESETVAL     (0x00000000u)

#define CSL_EDMACC_ESRH_RESETVAL         (0x00000000u)

/* CER */

#define CSL_EDMACC_CER_REG_MASK          (0xFFFFFFFFu)
#define CSL_EDMACC_CER_REG_SHIFT         (0x00000000u)
#define CSL_EDMACC_CER_REG_RESETVAL      (0x00000000u)

#define CSL_EDMACC_CER_RESETVAL          (0x00000000u)

/* CERH */

#define CSL_EDMACC_CERH_REG_MASK         (0xFFFFFFFFu)
#define CSL_EDMACC_CERH_REG_SHIFT        (0x00000000u)
#define CSL_EDMACC_CERH_REG_RESETVAL     (0x00000000u)

#define CSL_EDMACC_CERH_RESETVAL         (0x00000000u)

/* EER */

#define CSL_EDMACC_EER_REG_MASK          (0xFFFFFFFFu)
#define CSL_EDMACC_EER_REG_SHIFT         (0x00000000u)
#define CSL_EDMACC_EER_REG_RESETVAL      (0x00000000u)

#define CSL_EDMACC_EER_RESETVAL          (0x00000000u)

/* EERH */

#define CSL_EDMACC_EERH_REG_MASK         (0xFFFFFFFFu)
#define CSL_EDMACC_EERH_REG_SHIFT        (0x00000000u)
#define CSL_EDMACC_EERH_REG_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EERH_RESETVAL         (0x00000000u)

/* EECR */

#define CSL_EDMACC_EECR_REG_MASK         (0xFFFFFFFFu)
#define CSL_EDMACC_EECR_REG_SHIFT        (0x00000000u)
#define CSL_EDMACC_EECR_REG_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EECR_RESETVAL         (0x00000000u)

/* EECRH */

#define CSL_EDMACC_EECRH_REG_MASK        (0xFFFFFFFFu)
#define CSL_EDMACC_EECRH_REG_SHIFT       (0x00000000u)
#define CSL_EDMACC_EECRH_REG_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EECRH_RESETVAL        (0x00000000u)

/* EESR */

#define CSL_EDMACC_EESR_REG_MASK         (0xFFFFFFFFu)
#define CSL_EDMACC_EESR_REG_SHIFT        (0x00000000u)
#define CSL_EDMACC_EESR_REG_RESETVAL     (0x00000000u)

#define CSL_EDMACC_EESR_RESETVAL         (0x00000000u)

/* EESRH */

#define CSL_EDMACC_EESRH_REG_MASK        (0xFFFFFFFFu)
#define CSL_EDMACC_EESRH_REG_SHIFT       (0x00000000u)
#define CSL_EDMACC_EESRH_REG_RESETVAL    (0x00000000u)

#define CSL_EDMACC_EESRH_RESETVAL        (0x00000000u)

/* SER */

#define CSL_EDMACC_SER_REG_MASK          (0xFFFFFFFFu)
#define CSL_EDMACC_SER_REG_SHIFT         (0x00000000u)
#define CSL_EDMACC_SER_REG_RESETVAL      (0x00000000u)

#define CSL_EDMACC_SER_RESETVAL          (0x00000000u)

/* SERH */

#define CSL_EDMACC_SERH_REG_MASK         (0xFFFFFFFFu)
#define CSL_EDMACC_SERH_REG_SHIFT        (0x00000000u)
#define CSL_EDMACC_SERH_REG_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SERH_RESETVAL         (0x00000000u)

/* SECR */

#define CSL_EDMACC_SECR_REG_MASK         (0xFFFFFFFFu)
#define CSL_EDMACC_SECR_REG_SHIFT        (0x00000000u)
#define CSL_EDMACC_SECR_REG_RESETVAL     (0x00000000u)

#define CSL_EDMACC_SECR_RESETVAL         (0x00000000u)

/* SECRH */

#define CSL_EDMACC_SECRH_REG_MASK        (0xFFFFFFFFu)
#define CSL_EDMACC_SECRH_REG_SHIFT       (0x00000000u)
#define CSL_EDMACC_SECRH_REG_RESETVAL    (0x00000000u)

#define CSL_EDMACC_SECRH_RESETVAL        (0x00000000u)

/* IER */

#define CSL_EDMACC_IER_REG_MASK          (0xFFFFFFFFu)
#define CSL_EDMACC_IER_REG_SHIFT         (0x00000000u)
#define CSL_EDMACC_IER_REG_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IER_RESETVAL          (0x00000000u)

/* IERH */

#define CSL_EDMACC_IERH_REG_MASK         (0xFFFFFFFFu)
#define CSL_EDMACC_IERH_REG_SHIFT        (0x00000000u)
#define CSL_EDMACC_IERH_REG_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IERH_RESETVAL         (0x00000000u)

/* IECR */

#define CSL_EDMACC_IECR_REG_MASK         (0xFFFFFFFFu)
#define CSL_EDMACC_IECR_REG_SHIFT        (0x00000000u)
#define CSL_EDMACC_IECR_REG_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IECR_RESETVAL         (0x00000000u)

/* IECRH */

#define CSL_EDMACC_IECRH_REG_MASK        (0xFFFFFFFFu)
#define CSL_EDMACC_IECRH_REG_SHIFT       (0x00000000u)
#define CSL_EDMACC_IECRH_REG_RESETVAL    (0x00000000u)

#define CSL_EDMACC_IECRH_RESETVAL        (0x00000000u)

/* IESR */

#define CSL_EDMACC_IESR_REG_MASK         (0xFFFFFFFFu)
#define CSL_EDMACC_IESR_REG_SHIFT        (0x00000000u)
#define CSL_EDMACC_IESR_REG_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IESR_RESETVAL         (0x00000000u)

/* IESRH */

#define CSL_EDMACC_IESRH_REG_MASK        (0xFFFFFFFFu)
#define CSL_EDMACC_IESRH_REG_SHIFT       (0x00000000u)
#define CSL_EDMACC_IESRH_REG_RESETVAL    (0x00000000u)

#define CSL_EDMACC_IESRH_RESETVAL        (0x00000000u)

/* IPR */

#define CSL_EDMACC_IPR_REG_MASK          (0xFFFFFFFFu)
#define CSL_EDMACC_IPR_REG_SHIFT         (0x00000000u)
#define CSL_EDMACC_IPR_REG_RESETVAL      (0x00000000u)

#define CSL_EDMACC_IPR_RESETVAL          (0x00000000u)

/* IPRH */

#define CSL_EDMACC_IPRH_REG_MASK         (0xFFFFFFFFu)
#define CSL_EDMACC_IPRH_REG_SHIFT        (0x00000000u)
#define CSL_EDMACC_IPRH_REG_RESETVAL     (0x00000000u)

#define CSL_EDMACC_IPRH_RESETVAL         (0x00000000u)

/* ICR */

#define CSL_EDMACC_ICR_REG_MASK          (0xFFFFFFFFu)
#define CSL_EDMACC_ICR_REG_SHIFT         (0x00000000u)
#define CSL_EDMACC_ICR_REG_RESETVAL      (0x00000000u)

#define CSL_EDMACC_ICR_RESETVAL          (0x00000000u)

/* ICRH */

#define CSL_EDMACC_ICRH_REG_MASK         (0xFFFFFFFFu)
#define CSL_EDMACC_ICRH_REG_SHIFT        (0x00000000u)
#define CSL_EDMACC_ICRH_REG_RESETVAL     (0x00000000u)

#define CSL_EDMACC_ICRH_RESETVAL         (0x00000000u)

/* IEVAL */

#define CSL_EDMACC_IEVAL_REG_MASK        (0xFFFFFFFFu)
#define CSL_EDMACC_IEVAL_REG_SHIFT       (0x00000000u)
#define CSL_EDMACC_IEVAL_REG_RESETVAL    (0x00000000u)

#define CSL_EDMACC_IEVAL_RESETVAL        (0x00000000u)

/* QER */

#define CSL_EDMACC_QER_REG_MASK          (0xFFFFFFFFu)
#define CSL_EDMACC_QER_REG_SHIFT         (0x00000000u)
#define CSL_EDMACC_QER_REG_RESETVAL      (0x00000000u)

#define CSL_EDMACC_QER_RESETVAL          (0x00000000u)

/* QEER */

#define CSL_EDMACC_QEER_REG_MASK         (0xFFFFFFFFu)
#define CSL_EDMACC_QEER_REG_SHIFT        (0x00000000u)
#define CSL_EDMACC_QEER_REG_RESETVAL     (0x00000000u)

#define CSL_EDMACC_QEER_RESETVAL         (0x00000000u)

/* QEECR */

#define CSL_EDMACC_QEECR_REG_MASK        (0xFFFFFFFFu)
#define CSL_EDMACC_QEECR_REG_SHIFT       (0x00000000u)
#define CSL_EDMACC_QEECR_REG_RESETVAL    (0x00000000u)

#define CSL_EDMACC_QEECR_RESETVAL        (0x00000000u)

/* QEESR */

#define CSL_EDMACC_QEESR_REG_MASK        (0xFFFFFFFFu)
#define CSL_EDMACC_QEESR_REG_SHIFT       (0x00000000u)
#define CSL_EDMACC_QEESR_REG_RESETVAL    (0x00000000u)

#define CSL_EDMACC_QEESR_RESETVAL        (0x00000000u)

/* QSER */

#define CSL_EDMACC_QSER_REG_MASK         (0xFFFFFFFFu)
#define CSL_EDMACC_QSER_REG_SHIFT        (0x00000000u)
#define CSL_EDMACC_QSER_REG_RESETVAL     (0x00000000u)

#define CSL_EDMACC_QSER_RESETVAL         (0x00000000u)

/* QSECR */

#define CSL_EDMACC_QSECR_REG_MASK        (0xFFFFFFFFu)
#define CSL_EDMACC_QSECR_REG_SHIFT       (0x00000000u)
#define CSL_EDMACC_QSECR_REG_RESETVAL    (0x00000000u)

#define CSL_EDMACC_QSECR_RESETVAL        (0x00000000u)

#endif
