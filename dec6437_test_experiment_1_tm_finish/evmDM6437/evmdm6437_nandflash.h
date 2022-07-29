/*
 *  Copyright 2006 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  NAND Flash header file
 *
 */

#ifndef NANDFLASH_
#define NANDFLASH_

#include "evmdm6437.h"

#define USE_ECC

/* ------------------------------------------------------------------------ *
 *  Flash Device - SAMSUNG NAND Flash Memory K9F5608U0B                     *
 * ------------------------------------------------------------------------ */
#define MFG_SAMSUNG                 0xEC

#define DEV_K9F5608U0B              0x75
#define DEV_K9F5608U0B_PAGE_COUNT   32 * 2048 // 32 pages * 2048 blocks

#define DEV_K9F5608Q0B              0x35
#define DEV_K9F5608Q0B_PAGE_COUNT   32 * 2048 // 32 pages * 2048 blocks

#define DEV_K9F2808U0C              0x73
#define DEV_K9F2808U0C_PAGE_COUNT   32 * 1024 // 32 pages * 1024 blocks

#define DEV_K9K1208Q0C              0x36
#define DEV_K9K1208Q0C_PAGE_COUNT   32 * 4096 // 32 pages * 4096 blocks

#define DEV_SMCARD_128              0x79
#define DEV_SMCARD_128_PAGE_COUNT   32 * 8192 // 32 pages * 8192 blocks


#define MFG_STI                     0x20

#define DEV_NAND512W3A              0x76
#define DEV_NAND512W3A_PAGE_COUNT   32 * 4096

/* ------------------------------------------------------------------------ *
 *  Flash Memory Property Definitions                                       *
 * ------------------------------------------------------------------------ */
#define NAND_BASE                  0x42000000  // SNAND.CS0 BASE
#define NAND_PAGESIZE              4 * 1024
#define NAND_PAGESIZE_POW2         9
#define NAND_SPARESIZE             128
#define NAND_SPARESIZE_POW2        4
#define NAND_PAGES_PER_BLOCK       128
#define NAND_PAGES_PER_BLOCK_POW2  5

#define NAND_BLOCKSIZE             \
        NAND_PAGESIZE * NAND_PAGES_PER_BLOCK

#define NAND_BLOCKSIZE_POW2        \
        NAND_PAGESIZE_POW2 + NAND_PAGES_PER_BLOCK_POW2

/* ------------------------------------------------------------------------ *
 *  NAND Flash Command Codes                                                *
 * ------------------------------------------------------------------------ */
#define CMD_READ                    0x00
#define CMD_READ_CONFIRM            0x30
#define CMD_READ_HALF               0x01
#define CMD_READ_SPARE              0x50
#define CMD_READID                  0x90
#define CMD_RESET                   0xff
#define CMD_POINTER_MAIN            0x00
#define CMD_POINTER_MAIN_HALF       0x01
#define CMD_POINTER_SPARE           0x50
#define CMD_PROGRAM                 0x80
#define CMD_PROGRAM_CONFIRM         0x10
#define CMD_COPYBACK                0x00
#define CMD_COPYBACK_CONFIRM        0x8A
#define CMD_ERASE                   0x60
#define CMD_ERASE_CONFIRM           0xd0
#define CMD_STATUS                  0x70
#define CMD_CHIP1_STATUS            0xF1
#define CMD_CHIP2_STATUS            0xF2

/* ------------------------------------------------------------------------ *
 *  NAND Flash Status Register Definitions                                  *
 * ------------------------------------------------------------------------ */
#define CMD_STATUS_SUCCESS          0xFFFE
#define CMD_STATUS_ERROR            0x0001
#define CMD_STATUS_BUSY             0xFFBF
#define CMD_STATUS_READY            0x0040
#define CMD_STATUS_WPROTECT         0xFF7F
#define CMD_STATUS_NOWPROTECT       0x0080

/* ------------------------------------------------------------------------ *
 *  NAND Flash Memory Data Pointer                                          *
 * ------------------------------------------------------------------------ */
#define NAND_BASE_PTR       *( volatile Uint8* )( NAND_BASE + 0x00 )
#define NAND_CLE_PTR        *( volatile Uint8* )( NAND_BASE + 0x10 )
#define NAND_ALE_PTR        *( volatile Uint8* )( NAND_BASE + 0x0B )

#define NAND_ASSERT_CE( )   ;
#define NAND_DEASSERT_CE( ) ;

#define NAND_READ_RB        ( ( *( volatile Uint32* )( 0x01E00064 ) ) & 1 )

/* ------------------------------------------------------------------------ *
 *  NAND Flash R/B functions                                                *
 * ------------------------------------------------------------------------ */
#define NAND_ERR_NOERROR            ( 0 )
#define NAND_ERR_TIMEOUT            ( -1 )

/* ------------------------------------------------------------------------ *
 *  Address decoding                                                        *
 *      _4 = 26 address bits [00-07]--->[09-16]--->[17-24]--->[25-26]       *
 *      _3 = 24 address bits [09-16]--->[17-24]--->[25-26]                  *
 *      _2 = 16 address bits [17-24]--->[25-26]                             *
 *      _1 =  8 address bits [25-26]                                        *
 * ------------------------------------------------------------------------ */
#define NAND_DATA           NAND_BASE_PTR

#define NAND_CMD( cmd )     NAND_CLE_PTR = cmd;
/*
#define NAND_ADDR_4( addr ) NAND_ALE_PTR = addr;       NAND_ADDR_3( addr );
#define NAND_ADDR_3( addr ) NAND_ALE_PTR = addr >> 9;  NAND_ADDR_2( addr );
#define NAND_ADDR_2( addr ) NAND_ALE_PTR = addr >> 17; NAND_ADDR_1( addr );
#define NAND_ADDR_1( addr ) NAND_ALE_PTR = addr >> 25;
*/

#define NAND_ADDR_4( addr ) NAND_ALE_PTR = (addr >> 0) & 0xff; NAND_ADDR_3( addr );
#define NAND_ADDR_3( addr ) NAND_ALE_PTR = (addr >> 8) & 0x1f; NAND_ADDR_2( addr );
#define NAND_ADDR_2( addr ) NAND_ALE_PTR = (addr >> 13) & 0xff; NAND_ADDR_1( addr );
#define NAND_ADDR_1( addr ) NAND_ALE_PTR = (addr >> 21) & 0xff; NAND_ADDR_0( addr );
#define NAND_ADDR_0( addr ) NAND_ALE_PTR = (addr >> 29) & 0x0f; 

/* ------------------------------------------------------------------------ *
 *  Prototypes                                                              *
 * ------------------------------------------------------------------------ */
Int16  EVMDM6437_NAND_init          ( );

Uint32 EVMDM6437_NAND_getTotalPages ( );

Int16  EVMDM6437_NAND_erase         ( Uint32 start, Uint32 block_count );
Int16  EVMDM6437_NAND_readPage      ( Uint32 src, Uint32 dst, Uint32 page_count );
Int16  EVMDM6437_NAND_writePage     ( Uint32 src, Uint32 dst, Uint32 page_count );

#endif
