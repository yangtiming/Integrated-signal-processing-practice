#ifndef _CSLR_CFG_H_
#define _CSLR_CFG_H_

/*********************************************************************
 * Copyright (C) 2003-2004 Texas Instruments Incorporated. 
 * All Rights Reserved 
 *********************************************************************/
 /** \file cslr_cfg.h
 * 
 * \brief This file contains the Register Desciptions for CFG
 * 
 * Path: \\(CSLPATH)\\soc\\davinci\\c64plus\\src
 *********************************************************************/

#include <cslr.h>

#include <tistdtypes.h>

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 MPFAR;
    volatile Uint32 MPFSR;
    volatile Uint32 MPFCR;
} CSL_CfgRegs;

typedef volatile CSL_CfgRegs *CSL_CfgRegsOvly;
/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* MPFAR */

#define CSL_CFG_MPFAR_ADDR_MASK         (0xFFFFFFFFu)
#define CSL_CFG_MPFAR_ADDR_SHIFT        (0x00000000u)
#define CSL_CFG_MPFAR_ADDR_RESETVAL     (0x00000000u)

#define CSL_CFG_MPFAR_RESETVAL          (0x00000000u)

/* MPFSR */

#define CSL_CFG_MPFSR_RESERVED_MASK     (0xFFFF0000u)
#define CSL_CFG_MPFSR_RESERVED_SHIFT    (0x00000010u)
#define CSL_CFG_MPFSR_RESERVED_RESETVAL (0x00000000u)

#define CSL_CFG_MPFSR_FID_MASK          (0x0000FE00u)
#define CSL_CFG_MPFSR_FID_SHIFT         (0x00000009u)
#define CSL_CFG_MPFSR_FID_RESETVAL      (0x00000000u)

/*----FID Tokens----*/
#define CSL_CFG_MPFSR_FID_FAULT         (0x00000001u)
#define CSL_CFG_MPFSR_FID_OK            (0x00000000u)

#define CSL_CFG_MPFSR_LE_MASK           (0x00000100u)
#define CSL_CFG_MPFSR_LE_SHIFT          (0x00000008u)
#define CSL_CFG_MPFSR_LE_RESETVAL       (0x00000000u)

#define CSL_CFG_MPFSR_SECE_MASK         (0x00000080u)
#define CSL_CFG_MPFSR_SECE_SHIFT        (0x00000007u)
#define CSL_CFG_MPFSR_SECE_RESETVAL     (0x00000000u)

/*----SECE Tokens----*/
#define CSL_CFG_MPFSR_SECE_FAULT        (0x00000001u)
#define CSL_CFG_MPFSR_SECE_OK           (0x00000000u)

#define CSL_CFG_MPFSR_ATYPE_MASK        (0x0000003Fu)
#define CSL_CFG_MPFSR_ATYPE_SHIFT       (0x00000000u)
#define CSL_CFG_MPFSR_ATYPE_RESETVAL    (0x00000000u)

/*----ATYPE Tokens----*/
#define CSL_CFG_MPFSR_ATYPE_NONE        (0x00000000u)
#define CSL_CFG_MPFSR_ATYPE_UXE         (0x00000001u)
#define CSL_CFG_MPFSR_ATYPE_UWE         (0x00000002u)
#define CSL_CFG_MPFSR_ATYPE_URE         (0x00000004u)
#define CSL_CFG_MPFSR_ATYPE_SXE         (0x00000008u)
#define CSL_CFG_MPFSR_ATYPE_SWE         (0x00000010u)
#define CSL_CFG_MPFSR_ATYPE_SRE         (0x00000020u)
#define CSL_CFG_MPFSR_ATYPE_INVCLFILL   (0x0000003Fu)
#define CSL_CFG_MPFSR_ATYPE_INVCLWB     (0x00000012u)

#define CSL_CFG_MPFSR_RESETVAL          (0x00000000u)

/* MPFCR */

#define CSL_CFG_MPFCR_RESERVED_MASK     (0xFFFFFFFEu)
#define CSL_CFG_MPFCR_RESERVED_SHIFT    (0x00000001u)
#define CSL_CFG_MPFCR_RESERVED_RESETVAL (0x00000000u)

#define CSL_CFG_MPFCR_MPFCLR_MASK       (0x00000001u)
#define CSL_CFG_MPFCR_MPFCLR_SHIFT      (0x00000000u)
#define CSL_CFG_MPFCR_MPFCLR_RESETVAL   (0x00000000u)

/*----MPFCLR Tokens----*/
#define CSL_CFG_MPFCR_MPFCLR_CLEAR      (0x00000001u)

#define CSL_CFG_MPFCR_RESETVAL          (0x00000000u)

#endif
