/*
 *  Copyright 2006 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  Flash interface for Intel/Micron Flash chips & Spansion  Flash chips
 *
 */

#ifndef FLASH_
#define FLASH_

#include "evmdm6437.h"

/* ------------------------------------------------------------------------ *
 *  Flash Memory Property Definitions                                       *
 * ------------------------------------------------------------------------ */
#define FLASH_BASE                  ( EMIF_CS2_BASE )
#define FLASH_END_OR_RANGE          ( EMIF_CS3_BASE )

/* Intel only */
#define FLASH_DEVICE_TOP_PAGES      1
#define FLASH_DEVICE_BOTTOM_PAGES   2

/* ------------------------------------------------------------------------ *
 *  Flash Memory Base Pointers                                              *
 * ------------------------------------------------------------------------ */
#define FLASH_BASE_PTR8         *( volatile Uint8* )FLASH_BASE
#define FLASH_CTL555            *( volatile Uint8* )( FLASH_BASE + 0x555 )
#define FLASH_CTLAAA            *( volatile Uint8* )( FLASH_BASE + 0xAAA )

//#define FLASH_BASE          0x90000000
#define FLASH_SECTORSIZE    0x010000
#define FLASH_SECTORS       0x8
#define FLASH_PAGES         0x8
#define FLASH_PAGESIZE      0x080000
#define FLASH_SIZE          0x400000
/* ------------------------------------------------------------------------ *
 *  Flash Command Codes ( SPANSION )                                        *
 * ------------------------------------------------------------------------ */
#define FLASH_RESET                         0xF0
#define FLASH_CMD_AA                        0xAA
#define FLASH_CMD_55                        0x55
#define FLASH_ID                            0x90
#define FLASH_PROGRAM                       0xA0
#define FLASH_WRITE_BUFFER                  0x25
#define FLASH_PROGRAM_BUFFER                0x29
#define FLASH_ERASE                         0x80
#define FLASH_ERASE_CHIP                    0x10
#define FLASH_ERASE_SECTOR                  0x30
#define FLASH_ERASE_SUSPEND                 0xB0
#define FLASH_ERASE_RESUME                  0x10
#define FLASH_CFI_QUERY                     0x98

/* ------------------------------------------------------------------------ *
 *  Flash Command Codes ( Intel/Micron )                                    *
 * ------------------------------------------------------------------------ */
#define FLASH_READ_ARRAY                    0xFF
#define FLASH_READ_ID                       0x90
#define FLASH_READ_QUERY                    0x98
#define FLASH_READ_STATUS                   0x70
#define FLASH_CLEAR_STATUS                  0x50
#define FLASH_WORD_PROGRAM                  0x40 // -or- 0x10
#define FLASH_WRITE_TO_BUFFER               0xE8
#define FLASH_BUFFERED_EFP                  0x80
#define FLASH_BLOCK_ERASE                   0x20
#define FLASH_ERASE_PRG_SUSPEND             0xB0
#define FLASH_ERASE_PRG_RESUME              0xD0
#define FLASH_CONFIGURATION                 0xB8
#define FLASH_CONFIG_BLOCK_LOCK_BITS        0x60
#define FLASH_SET_LOCK_BITS                 0x01
#define FLASH_CLEAR_LOCK_BITS               0xD0
#define FLASH_PROTECTION_PROGRAM            0xC0

/* ------------------------------------------------------------------------ *
 *  Flash Memory Read Status Register Fields                                *
 * ------------------------------------------------------------------------ */
#define READ_STATUS_REGISTER_ISMS           0x80 // WRITE STATE MACHINE
#define READ_STATUS_REGISTER_ESS            0x40 // ERASE SUSPEND
#define READ_STATUS_REGISTER_ECLBS          0x20 // ERASE & CLEAR LOCK BITS
#define READ_STATUS_REGISTER_PSLBS          0x10 // PROGRAM & SET LOCK BIT
#define READ_STATUS_REGISTER_VPENS          0x08 // PROGRAMMING VOLTAGE
#define READ_STATUS_REGISTER_PSS            0x04 // PROGRAM SUSPEND
#define READ_STATUS_REGISTER_DPS            0x02 // DEVICE PROTECT

/* ------------------------------------------------------------------------ *
 *  Prototypes                                                              *
 * ------------------------------------------------------------------------ */
Int8   EVMDM6437_FLASH_init         ( );
Int8   EVMDM6437_FLASH_read         ( Uint32 src, Uint32 dst, Uint32 length );
Int8   EVMDM6437_FLASH_write        ( Uint32 src, Uint32 dst, Uint32 length );
void   Erase_Entire_Sector			( Uint32 addr_sector );
void   Erase_Entire_Chip			( void );
#endif
