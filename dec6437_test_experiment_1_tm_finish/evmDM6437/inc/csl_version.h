/*  ============================================================================
 *   Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005                 
 *                                                                              
 *   Use of this software is controlled by the terms and conditions found in the
 *   license agreement under which this software has been supplied.             
 *   ===========================================================================
 */

#ifndef _CSL_VERSION_H_
#define _CSL_VERSION_H_

#define CSL_VERSION_ID          (0x03000201)    /* 0xAABBCCDD -> Arch (AA); API Changes (BB); Major (CC); Minor (DD) */
#define CSL_VERSION_STR         "@# CSL Revision: 3.00.02.01;"

extern void CSL_version3_00_02_01( );


#define CSL_CHIP_ID             (0x300)
#define CSL_CHIP_STR            "Chip: HIBARI, PG 1.0"

extern void CSL_chip64plus(void);


static void CSL_versionCheck(void)
{
    CSL_version3_00_02_01();
    CSL_chip64plus();
}

#endif /* _CSL_VERSION_H_ */

