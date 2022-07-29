/*
 *  Copyright 2006 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  Definitions & Register
 *
 */
#include <tistdtypes.h>
#ifndef EVMDM6437_
#define EVMDM6437_

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  Variable types                                                          *
 *                                                                          *
 * ------------------------------------------------------------------------ 
#define Uint32  unsigned int
#define Uint16  unsigned short
#define Uint8   unsigned char
#define Int32   int
#define Int16   short
#define Int8    char
 */
/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  Software Breakpoint code                                                *
 *      Uses inline assembly command                                        *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define SW_BREAKPOINT           asm( " SWBP 0" );

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  AEMIF Controller                                                        *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define AEMIF_BASE              0x01E00000
#define AEMIF_AWCCR             *( volatile Uint32* )( AEMIF_BASE + 0x04 )
#define AEMIF_A1CR              *( volatile Uint32* )( AEMIF_BASE + 0x10 )
#define AEMIF_A2CR              *( volatile Uint32* )( AEMIF_BASE + 0x14 )
#define AEMIF_A3CR              *( volatile Uint32* )( AEMIF_BASE + 0x18 )
#define AEMIF_A4CR              *( volatile Uint32* )( AEMIF_BASE + 0x1C )
#define AEMIF_EIRR              *( volatile Uint32* )( AEMIF_BASE + 0x40 )
#define AEMIF_EIMR              *( volatile Uint32* )( AEMIF_BASE + 0x44 )
#define AEMIF_EMISR             *( volatile Uint32* )( AEMIF_BASE + 0x48 )
#define AEMIF_EIMCR             *( volatile Uint32* )( AEMIF_BASE + 0x4C )
#define AEMIF_NANDFCR           *( volatile Uint32* )( AEMIF_BASE + 0x60 )
#define AEMIF_NANDFSR           *( volatile Uint32* )( AEMIF_BASE + 0x64 )
#define AEMIF_NANDECC2          *( volatile Uint32* )( AEMIF_BASE + 0x70 )
#define AEMIF_NANDECC3          *( volatile Uint32* )( AEMIF_BASE + 0x74 )
#define AEMIF_NANDECC4          *( volatile Uint32* )( AEMIF_BASE + 0x78 )
#define AEMIF_NANDECC5          *( volatile Uint32* )( AEMIF_BASE + 0x7C )

#define AEMIF_MAX_TIMEOUT_8BIT  0x3FFFFFFC
#define AEMIF_MAX_TIMEOUT_16BIT 0x3FFFFFFD

#define EMIF_CS2                2
#define EMIF_CS3                3
#define EMIF_CS4                4
#define EMIF_CS5                5

#define EMIF_CS2_BASE           0x42000000
#define EMIF_CS3_BASE           0x44000000
#define EMIF_CS4_BASE           0x46000000
#define EMIF_CS5_BASE           0x48000000

#define EMIF_NAND_MODE          1
#define EMIF_NORMAL_MODE        0

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  Cache Controller                                                        *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define CACHE_BASE              0x01840000
#define CACHE_L2CFG             *( volatile Uint32* )( CACHE_BASE + 0x0000 )
#define CACHE_L1PCFG            *( volatile Uint32* )( CACHE_BASE + 0x0020 )
#define CACHE_L1PCC             *( volatile Uint32* )( CACHE_BASE + 0x0024 )
#define CACHE_L1DCFG            *( volatile Uint32* )( CACHE_BASE + 0x0040 )
#define CACHE_L1DCC             *( volatile Uint32* )( CACHE_BASE + 0x0044 )
#define CACHE_EDMAWEIGHT        *( volatile Uint32* )( CACHE_BASE + 0x1000 )
#define CACHE_L2ALLOC0          *( volatile Uint32* )( CACHE_BASE + 0x2000 )
#define CACHE_L2ALLOC1          *( volatile Uint32* )( CACHE_BASE + 0x2004 )
#define CACHE_L2ALLOC2          *( volatile Uint32* )( CACHE_BASE + 0x2008 )
#define CACHE_L2ALLOC3          *( volatile Uint32* )( CACHE_BASE + 0x200C )
#define CACHE_L2WBAR            *( volatile Uint32* )( CACHE_BASE + 0x4000 )
#define CACHE_L2WWC             *( volatile Uint32* )( CACHE_BASE + 0x4004 )
#define CACHE_L2WIBAR           *( volatile Uint32* )( CACHE_BASE + 0x4010 )
#define CACHE_L2WIWC            *( volatile Uint32* )( CACHE_BASE + 0x4014 )
#define CACHE_L2IBAR            *( volatile Uint32* )( CACHE_BASE + 0x4018 )
#define CACHE_L2IWC             *( volatile Uint32* )( CACHE_BASE + 0x401C )
#define CACHE_L1PIBAR           *( volatile Uint32* )( CACHE_BASE + 0x4020 )
#define CACHE_L1PIWC            *( volatile Uint32* )( CACHE_BASE + 0x4024 )
#define CACHE_L1DWIBAR          *( volatile Uint32* )( CACHE_BASE + 0x4030 )
#define CACHE_L1DWIWC           *( volatile Uint32* )( CACHE_BASE + 0x4034 )
#define CACHE_L1DWBAR           *( volatile Uint32* )( CACHE_BASE + 0x4040 )
#define CACHE_L1DWWC            *( volatile Uint32* )( CACHE_BASE + 0x4044 )
#define CACHE_L1DIBAR           *( volatile Uint32* )( CACHE_BASE + 0x4048 )
#define CACHE_L1DIWC            *( volatile Uint32* )( CACHE_BASE + 0x404C )
#define CACHE_L2WB              *( volatile Uint32* )( CACHE_BASE + 0x5000 )
#define CACHE_L2WBINV           *( volatile Uint32* )( CACHE_BASE + 0x5004 )
#define CACHE_L2INV             *( volatile Uint32* )( CACHE_BASE + 0x5008 )
#define CACHE_L1PINV            *( volatile Uint32* )( CACHE_BASE + 0x5028 )
#define CACHE_L1DWB             *( volatile Uint32* )( CACHE_BASE + 0x5040 )
#define CACHE_L1DWBINV          *( volatile Uint32* )( CACHE_BASE + 0x5044 )
#define CACHE_L1DINV            *( volatile Uint32* )( CACHE_BASE + 0x5048 )
#define CACHE_MAR_BASE          ( CACHE_BASE + 0x8000 )

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  Device Config Controller                                                *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define DEV_CFG_BASE            0x01C40000
#define CFG_PINMUX0             *( volatile Uint32* )( DEV_CFG_BASE + 0x00 )
#define CFG_PINMUX1             *( volatile Uint32* )( DEV_CFG_BASE + 0x04 )
#define CFG_DSPBOOTADDR         *( volatile Uint32* )( DEV_CFG_BASE + 0x08 )
#define CFG_SUSPSRC             *( volatile Uint32* )( DEV_CFG_BASE + 0x0C )
#define CFG_BOOTCFG             *( volatile Uint32* )( DEV_CFG_BASE + 0x14 )
#define CFG_DEVICE_ID           *( volatile Uint32* )( DEV_CFG_BASE + 0x28 )
#define CFG_UHPICTL             *( volatile Uint32* )( DEV_CFG_BASE + 0x30 )
#define CFG_MSTPRI0             *( volatile Uint32* )( DEV_CFG_BASE + 0x3C )
#define CFG_MSTPRI1             *( volatile Uint32* )( DEV_CFG_BASE + 0x40 )
#define CFG_VPSS_CLKCTL         *( volatile Uint32* )( DEV_CFG_BASE + 0x44 )
#define CFG_VDD3P3V_PWDN        *( volatile Uint32* )( DEV_CFG_BASE + 0x48 )
#define CFG_TIMERCTL            *( volatile Uint32* )( DEV_CFG_BASE + 0x84 )
#define CFG_TPTCCCFG            *( volatile Uint32* )( DEV_CFG_BASE + 0x88 )
#define CFG_RSTYPE              *( volatile Uint32* )( DEV_CFG_BASE + 0xE4 )

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  DDR Controller                                                          *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define DDR_REG_BASE            0x20000000
#define DDR_DDRVTPER            *( volatile Uint32* )( 0x01C4004C )
#define DDR_DDRVTPR             *( volatile Uint32* )( 0x01C42038 )
#define DDR_SDRSTAT             *( volatile Uint32* )( DDR_REG_BASE + 0x04 )
#define DDR_SDBCR               *( volatile Uint32* )( DDR_REG_BASE + 0x08 )
#define DDR_SDRCR               *( volatile Uint32* )( DDR_REG_BASE + 0x0C )
#define DDR_SDTIMR              *( volatile Uint32* )( DDR_REG_BASE + 0x10 )
#define DDR_SDTIMR2             *( volatile Uint32* )( DDR_REG_BASE + 0x14 )
#define DDR_PBBPR               *( volatile Uint32* )( DDR_REG_BASE + 0x20 )
#define DDR_IRR                 *( volatile Uint32* )( DDR_REG_BASE + 0xC0 )
#define DDR_IMR                 *( volatile Uint32* )( DDR_REG_BASE + 0xC4 )
#define DDR_IMSR                *( volatile Uint32* )( DDR_REG_BASE + 0xC8 )
#define DDR_IMCR                *( volatile Uint32* )( DDR_REG_BASE + 0xCC )
#define DDR_DDRPHYCR            *( volatile Uint32* )( DDR_REG_BASE + 0xE4 )
#define DDR_VTPIOCR             *( volatile Uint32* )( DDR_REG_BASE + 0xF0 )

#define DDR_BASE                0x80000000  // Start of SDRAM range
#define DDR_SIZE                0x08000000  // 128 MB

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  EDMA Controller                                                         *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define EDMA_BASE               0x01C00000
#define EDMA_CCCFG              *( volatile Uint32* )( EDMA_BASE + 0x04 )

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  EMAC controller                                                         *
 *      Controls the EMAC                                                   *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define EMAC_BASE               0x01C80000
#define EMAC_TXIDVER            *( volatile Uint32* )( EMAC_BASE + 0x000 )
#define EMAC_TXCONTROL          *( volatile Uint32* )( EMAC_BASE + 0x004 )
#define EMAC_TXTEARDOWN         *( volatile Uint32* )( EMAC_BASE + 0x008 )
#define EMAC_RXIDVER            *( volatile Uint32* )( EMAC_BASE + 0x010 )
#define EMAC_RXCONTROL          *( volatile Uint32* )( EMAC_BASE + 0x014 )
#define EMAC_RXTEARDOWN         *( volatile Uint32* )( EMAC_BASE + 0x018 )
#define EMAC_TXINTSTATRAW       *( volatile Uint32* )( EMAC_BASE + 0x080 )
#define EMAC_TXINTSTATMASKED    *( volatile Uint32* )( EMAC_BASE + 0x084 )
#define EMAC_TXINTMASKSET       *( volatile Uint32* )( EMAC_BASE + 0x088 )
#define EMAC_TXINTMASKCLEAR     *( volatile Uint32* )( EMAC_BASE + 0x08C )
#define EMAC_MACINVECTOR        *( volatile Uint32* )( EMAC_BASE + 0x090 )
#define EMAC_RXINTSTATRAW       *( volatile Uint32* )( EMAC_BASE + 0x0A0 )
#define EMAC_RXINTSTATMASKED    *( volatile Uint32* )( EMAC_BASE + 0x0A4 )
#define EMAC_RXINTMASKSET       *( volatile Uint32* )( EMAC_BASE + 0x0A8 )
#define EMAC_RXINTMASKCLEAR     *( volatile Uint32* )( EMAC_BASE + 0x0AC )
#define EMAC_MACINTSTATRAW      *( volatile Uint32* )( EMAC_BASE + 0x0B0 )
#define EMAC_MACINTSTATMASKED   *( volatile Uint32* )( EMAC_BASE + 0x0B4 )
#define EMAC_MACINTMASKSET      *( volatile Uint32* )( EMAC_BASE + 0x0B8 )
#define EMAC_MACINTMASKCLEAR    *( volatile Uint32* )( EMAC_BASE + 0x0BC )
#define EMAC_RXMBPENABLE        *( volatile Uint32* )( EMAC_BASE + 0x100 )
#define EMAC_RXUNICASTSET       *( volatile Uint32* )( EMAC_BASE + 0x104 )
#define EMAC_RXUNICASTCLEAR     *( volatile Uint32* )( EMAC_BASE + 0x108 )
#define EMAC_RXMAXLEN           *( volatile Uint32* )( EMAC_BASE + 0x10C )
#define EMAC_RXBUFFEROFFSET     *( volatile Uint32* )( EMAC_BASE + 0x110 )
#define EMAC_RXFILTERLOWTHRESH  *( volatile Uint32* )( EMAC_BASE + 0x114 )
#define EMAC_RX0FLOWTHRESH      *( volatile Uint32* )( EMAC_BASE + 0x120 )
#define EMAC_RX1FLOWTHRESH      *( volatile Uint32* )( EMAC_BASE + 0x124 )
#define EMAC_RX2FLOWTHRESH      *( volatile Uint32* )( EMAC_BASE + 0x128 )
#define EMAC_RX3FLOWTHRESH      *( volatile Uint32* )( EMAC_BASE + 0x12C )
#define EMAC_RX4FLOWTHRESH      *( volatile Uint32* )( EMAC_BASE + 0x130 )
#define EMAC_RX5FLOWTHRESH      *( volatile Uint32* )( EMAC_BASE + 0x134 )
#define EMAC_RX6FLOWTHRESH      *( volatile Uint32* )( EMAC_BASE + 0x138 )
#define EMAC_RX7FLOWTHRESH      *( volatile Uint32* )( EMAC_BASE + 0x13C )
#define EMAC_RX0FREEBUFFER      *( volatile Uint32* )( EMAC_BASE + 0x140 )
#define EMAC_RX1FREEBUFFER      *( volatile Uint32* )( EMAC_BASE + 0x144 )
#define EMAC_RX2FREEBUFFER      *( volatile Uint32* )( EMAC_BASE + 0x148 )
#define EMAC_RX3FREEBUFFER      *( volatile Uint32* )( EMAC_BASE + 0x14C )
#define EMAC_RX4FREEBUFFER      *( volatile Uint32* )( EMAC_BASE + 0x150 )
#define EMAC_RX5FREEBUFFER      *( volatile Uint32* )( EMAC_BASE + 0x154 )
#define EMAC_RX6FREEBUFFER      *( volatile Uint32* )( EMAC_BASE + 0x158 )
#define EMAC_RX7FREEBUFFER      *( volatile Uint32* )( EMAC_BASE + 0x15C )
#define EMAC_MACCONTROL         *( volatile Uint32* )( EMAC_BASE + 0x160 )
#define EMAC_MACSTATUS          *( volatile Uint32* )( EMAC_BASE + 0x164 )
#define EMAC_EMCONTROL          *( volatile Uint32* )( EMAC_BASE + 0x168 )
#define EMAC_FIFOCONTROL        *( volatile Uint32* )( EMAC_BASE + 0x16C )
#define EMAC_MACCONFIG          *( volatile Uint32* )( EMAC_BASE + 0x170 )
#define EMAC_SOFTRESET          *( volatile Uint32* )( EMAC_BASE + 0x174 )
#define EMAC_MACSRCADDRLO       *( volatile Uint32* )( EMAC_BASE + 0x1D0 )
#define EMAC_MACSRCADDRHI       *( volatile Uint32* )( EMAC_BASE + 0x1D4 )
#define EMAC_MACHASH1           *( volatile Uint32* )( EMAC_BASE + 0x1D8 )
#define EMAC_MACHASH2           *( volatile Uint32* )( EMAC_BASE + 0x1DC )
#define EMAC_BOFFTEST           *( volatile Uint32* )( EMAC_BASE + 0x001 )
#define EMAC_TPACETEST          *( volatile Uint32* )( EMAC_BASE + 0x1E4 )
#define EMAC_RXPAUSE            *( volatile Uint32* )( EMAC_BASE + 0x1E8 )
#define EMAC_TXPAUSE            *( volatile Uint32* )( EMAC_BASE + 0x1EC )
#define EMAC_MACADDRLO          *( volatile Uint32* )( EMAC_BASE + 0x500 )
#define EMAC_MACADDRHI          *( volatile Uint32* )( EMAC_BASE + 0x504 )
#define EMAC_MACINDEX           *( volatile Uint32* )( EMAC_BASE + 0x508 )
#define EMAC_TX0HDP             *( volatile Uint32* )( EMAC_BASE + 0x600 )
#define EMAC_TX1HDP             *( volatile Uint32* )( EMAC_BASE + 0x604 )
#define EMAC_TX2HDP             *( volatile Uint32* )( EMAC_BASE + 0x608 )
#define EMAC_TX3HDP             *( volatile Uint32* )( EMAC_BASE + 0x60C )
#define EMAC_TX4HDP             *( volatile Uint32* )( EMAC_BASE + 0x610 )
#define EMAC_TX5HDP             *( volatile Uint32* )( EMAC_BASE + 0x614 )
#define EMAC_TX6HDP             *( volatile Uint32* )( EMAC_BASE + 0x618 )
#define EMAC_TX7HDP             *( volatile Uint32* )( EMAC_BASE + 0x61C )
#define EMAC_RX0HDP             *( volatile Uint32* )( EMAC_BASE + 0x620 )
#define EMAC_RX1HDP             *( volatile Uint32* )( EMAC_BASE + 0x624 )
#define EMAC_RX2HDP             *( volatile Uint32* )( EMAC_BASE + 0x628 )
#define EMAC_RX3HDP             *( volatile Uint32* )( EMAC_BASE + 0x62C )
#define EMAC_RX4HDP             *( volatile Uint32* )( EMAC_BASE + 0x630 )
#define EMAC_RX5HDP             *( volatile Uint32* )( EMAC_BASE + 0x634 )
#define EMAC_RX6HDP             *( volatile Uint32* )( EMAC_BASE + 0x638 )
#define EMAC_RX7HDP             *( volatile Uint32* )( EMAC_BASE + 0x63C )
#define EMAC_TX0CP              *( volatile Uint32* )( EMAC_BASE + 0x640 )
#define EMAC_TX1CP              *( volatile Uint32* )( EMAC_BASE + 0x644 )
#define EMAC_TX2CP              *( volatile Uint32* )( EMAC_BASE + 0x648 )
#define EMAC_TX3CP              *( volatile Uint32* )( EMAC_BASE + 0x64C )
#define EMAC_TX4CP              *( volatile Uint32* )( EMAC_BASE + 0x650 )
#define EMAC_TX5CP              *( volatile Uint32* )( EMAC_BASE + 0x654 )
#define EMAC_TX6CP              *( volatile Uint32* )( EMAC_BASE + 0x658 )
#define EMAC_TX7CP              *( volatile Uint32* )( EMAC_BASE + 0x65C )
#define EMAC_RX0CP              *( volatile Uint32* )( EMAC_BASE + 0x660 )
#define EMAC_RX1CP              *( volatile Uint32* )( EMAC_BASE + 0x664 )
#define EMAC_RX2CP              *( volatile Uint32* )( EMAC_BASE + 0x668 )
#define EMAC_RX3CP              *( volatile Uint32* )( EMAC_BASE + 0x66C )
#define EMAC_RX4CP              *( volatile Uint32* )( EMAC_BASE + 0x670 )
#define EMAC_RX5CP              *( volatile Uint32* )( EMAC_BASE + 0x674 )
#define EMAC_RX6CP              *( volatile Uint32* )( EMAC_BASE + 0x678 )
#define EMAC_RX7CP              *( volatile Uint32* )( EMAC_BASE + 0x67C )
#define EMAC_RXGOODFRAMES       *( volatile Uint32* )( EMAC_BASE + 0x200 )
#define EMAC_RXBCASTFRAMES      *( volatile Uint32* )( EMAC_BASE + 0x204 )
#define EMAC_RXMCASTFRAMES      *( volatile Uint32* )( EMAC_BASE + 0x208 )
#define EMAC_RXPAUSEFRAMES      *( volatile Uint32* )( EMAC_BASE + 0x20C )
#define EMAC_RXCRCERRORS        *( volatile Uint32* )( EMAC_BASE + 0x210 )
#define EMAC_RXALIGNCODEERRORS  *( volatile Uint32* )( EMAC_BASE + 0x214 )
#define EMAC_RXOVERSIZED        *( volatile Uint32* )( EMAC_BASE + 0x218 )
#define EMAC_RXJABBER           *( volatile Uint32* )( EMAC_BASE + 0x21C )
#define EMAC_RXUNDERSIZED       *( volatile Uint32* )( EMAC_BASE + 0x220 )
#define EMAC_RXFRAGMENTS        *( volatile Uint32* )( EMAC_BASE + 0x224 )
#define EMAC_RXFILTERED         *( volatile Uint32* )( EMAC_BASE + 0x228 )
#define EMAC_RXQOSFILTERED      *( volatile Uint32* )( EMAC_BASE + 0x22C )
#define EMAC_RXOCTETS           *( volatile Uint32* )( EMAC_BASE + 0x230 )
#define EMAC_TXGOODFRAMES       *( volatile Uint32* )( EMAC_BASE + 0x234 )
#define EMAC_TXBCASTFRAMES      *( volatile Uint32* )( EMAC_BASE + 0x238 )
#define EMAC_TXMCASTFRAMES      *( volatile Uint32* )( EMAC_BASE + 0x23C )
#define EMAC_TXPAUSEFRAMES      *( volatile Uint32* )( EMAC_BASE + 0x240 )
#define EMAC_TXDEFERRED         *( volatile Uint32* )( EMAC_BASE + 0x244 )
#define EMAC_TXCOLLISION        *( volatile Uint32* )( EMAC_BASE + 0x248 )
#define EMAC_TXSINGLECOLL       *( volatile Uint32* )( EMAC_BASE + 0x24C )
#define EMAC_TXMULTICOLL        *( volatile Uint32* )( EMAC_BASE + 0x250 )
#define EMAC_TXEXCESSIVECOLL    *( volatile Uint32* )( EMAC_BASE + 0x254 )
#define EMAC_TXLATECOLL         *( volatile Uint32* )( EMAC_BASE + 0x258 )
#define EMAC_TXUNDERRUN         *( volatile Uint32* )( EMAC_BASE + 0x25C )
#define EMAC_TXCARRIERSENSE     *( volatile Uint32* )( EMAC_BASE + 0x260 )
#define EMAC_TXOCTETS           *( volatile Uint32* )( EMAC_BASE + 0x264 )
#define EMAC_FRAME64            *( volatile Uint32* )( EMAC_BASE + 0x268 )
#define EMAC_FRAME65T127        *( volatile Uint32* )( EMAC_BASE + 0x26C )
#define EMAC_FRAME128T255       *( volatile Uint32* )( EMAC_BASE + 0x270 )
#define EMAC_FRAME256T511       *( volatile Uint32* )( EMAC_BASE + 0x274 )
#define EMAC_FRAME512T1023      *( volatile Uint32* )( EMAC_BASE + 0x278 )
#define EMAC_FRAME1024TUP       *( volatile Uint32* )( EMAC_BASE + 0x27C )
#define EMAC_NETOCTETS          *( volatile Uint32* )( EMAC_BASE + 0x280 )
#define EMAC_RXSOFOVERRUNS      *( volatile Uint32* )( EMAC_BASE + 0x284 )
#define EMAC_RXMOFOVERRUNS      *( volatile Uint32* )( EMAC_BASE + 0x288 )
#define EMAC_RXDMAOVERRUNS      *( volatile Uint32* )( EMAC_BASE + 0x28C )

/* EMAC Wrapper */
#define EMAC_EWCTL              *( volatile Uint32* )( EMAC_BASE + 0x1004 )
#define EMAC_EWINTTCNT          *( volatile Uint32* )( EMAC_BASE + 0x1008 )

/* EMAC RAM */
#define EMAC_RAM_BASE           0x01C82000
#define EMAC_RAM_LEN            0x00002000

/* Packet Flags */
#define EMAC_DSC_FLAG_SOP               0x80000000
#define EMAC_DSC_FLAG_EOP               0x40000000
#define EMAC_DSC_FLAG_OWNER             0x20000000
#define EMAC_DSC_FLAG_EOQ               0x10000000
#define EMAC_DSC_FLAG_TDOWNCMPLT        0x08000000
#define EMAC_DSC_FLAG_PASSCRC           0x04000000

/* The following flags are RX only */
#define EMAC_DSC_FLAG_JABBER            0x02000000
#define EMAC_DSC_FLAG_OVERSIZE          0x01000000
#define EMAC_DSC_FLAG_FRAGMENT          0x00800000
#define EMAC_DSC_FLAG_UNDERSIZED        0x00400000
#define EMAC_DSC_FLAG_CONTROL           0x00200000
#define EMAC_DSC_FLAG_OVERRUN           0x00100000
#define EMAC_DSC_FLAG_CODEERROR         0x00080000
#define EMAC_DSC_FLAG_ALIGNERROR        0x00040000
#define EMAC_DSC_FLAG_CRCERROR          0x00020000
#define EMAC_DSC_FLAG_NOMATCH           0x00010000

/* Interrupts */
#define EMAC_MACINVECTOR_USERINT        0x80000000
#define EMAC_MACINVECTOR_LINKINT        0x40000000
#define EMAC_MACINVECTOR_HOSTPEND       0x00020000
#define EMAC_MACINVECTOR_STATPEND       0x00010000
#define EMAC_MACINVECTOR_RXPEND         0x0000FF00
#define EMAC_MACINVECTOR_TXPEND         0x000000FF

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  GPIO Control                                                            *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define GPIO_BASE               0x01C67000

#define GPIO_PCR                *( volatile Uint32* )( GPIO_BASE + 0x04 )
#define GPIO_BINTEN             *( volatile Uint32* )( GPIO_BASE + 0x08 )

// For GPIO[0:31]
#define GPIO_DIR_BASE           ( 0x10 )   // Direction Cntl
#define GPIO_OUT_DATA_BASE      ( 0x14 )   // Output data
#define GPIO_SET_DATA_BASE      ( 0x18 )   // Set data
#define GPIO_CLR_DATA_BASE      ( 0x1C )   // Clear data
#define GPIO_IN_DATA_BASE       ( 0x20 )   // Input data
#define GPIO_SET_RIS_TRIG_BASE  ( 0x24 )   // Set rising edge intr
#define GPIO_CLR_RIS_TRIG_BASE  ( 0x28 )   // Clear rising edge intr
#define GPIO_SET_FAL_TRIG_BASE  ( 0x2C )   // Set falling edge intr
#define GPIO_CLR_FAL_TRIG_BASE  ( 0x30 )   // Clear falling edge intr
#define GPIO_INSTAT_BASE        ( 0x34 )   // Intr status
#define GPIO_BASE_OFFSET        0x28

#define GPIO_01_BASE            ( GPIO_BASE + 0x10 )
#define GPIO_23_BASE            ( GPIO_01_BASE + GPIO_BASE_OFFSET )
#define GPIO_45_BASE            ( GPIO_23_BASE + GPIO_BASE_OFFSET )
#define GPIO_6_BASE             ( GPIO_45_BASE + GPIO_BASE_OFFSET )

// For GPIO[0:31]
#define GPIO_DIR01              *( volatile Uint32* )( GPIO_BASE + 0x10 )
#define GPIO_OUT_DATA01         *( volatile Uint32* )( GPIO_BASE + 0x14 )
#define GPIO_SET_DATA01         *( volatile Uint32* )( GPIO_BASE + 0x18 )
#define GPIO_CLR_DATA01         *( volatile Uint32* )( GPIO_BASE + 0x1C )
#define GPIO_IN_DATA01          *( volatile Uint32* )( GPIO_BASE + 0x20 )
#define GPIO_SET_RIS_TRIG01     *( volatile Uint32* )( GPIO_BASE + 0x24 )
#define GPIO_CLR_RIS_TRIG01     *( volatile Uint32* )( GPIO_BASE + 0x28 )
#define GPIO_SET_FAL_TRIG01     *( volatile Uint32* )( GPIO_BASE + 0x2C )
#define GPIO_CLR_FAL_TRIG01     *( volatile Uint32* )( GPIO_BASE + 0x30 )
#define GPIO_INSTAT01           *( volatile Uint32* )( GPIO_BASE + 0x34 )

// For GPIO[32:63]
#define GPIO_DIR23              *( volatile Uint32* )( GPIO_BASE + 0x38 )
#define GPIO_OUT_DATA23         *( volatile Uint32* )( GPIO_BASE + 0x3C )
#define GPIO_SET_DATA23         *( volatile Uint32* )( GPIO_BASE + 0x40 )
#define GPIO_CLR_DATA23         *( volatile Uint32* )( GPIO_BASE + 0x44 )
#define GPIO_IN_DATA23          *( volatile Uint32* )( GPIO_BASE + 0x48 )
#define GPIO_SET_RIS_TRIG23     *( volatile Uint32* )( GPIO_BASE + 0x4C )
#define GPIO_CLR_RIS_TRIG23     *( volatile Uint32* )( GPIO_BASE + 0x50 )
#define GPIO_SET_FAL_TRIG23     *( volatile Uint32* )( GPIO_BASE + 0x54 )
#define GPIO_CLR_FAL_TRIG23     *( volatile Uint32* )( GPIO_BASE + 0x58 )
#define GPIO_INSTAT23           *( volatile Uint32* )( GPIO_BASE + 0x5C )

// For GPIO[64:70]
#define GPIO_DIR45              *( volatile Uint32* )( GPIO_BASE + 0x60 )
#define GPIO_OUT_DATA45         *( volatile Uint32* )( GPIO_BASE + 0x64 )
#define GPIO_SET_DATA45         *( volatile Uint32* )( GPIO_BASE + 0x68 )
#define GPIO_CLR_DATA45         *( volatile Uint32* )( GPIO_BASE + 0x6C )
#define GPIO_IN_DATA45          *( volatile Uint32* )( GPIO_BASE + 0x70 )
#define GPIO_SET_RIS_TRIG45     *( volatile Uint32* )( GPIO_BASE + 0x74 )
#define GPIO_CLR_RIS_TRIG45     *( volatile Uint32* )( GPIO_BASE + 0x78 )
#define GPIO_SET_FAL_TRIG45     *( volatile Uint32* )( GPIO_BASE + 0x7C )
#define GPIO_CLR_FAL_TRIG45     *( volatile Uint32* )( GPIO_BASE + 0x80 )
#define GPIO_INSTAT45           *( volatile Uint32* )( GPIO_BASE + 0x84 )

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  HECC Control                                                            *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define HECC_BASE               0x01C23000
#define HECC_ME                 *( volatile Uint32* )( HECC_BASE + 0x00 )
#define HECC_MD                 *( volatile Uint32* )( HECC_BASE + 0x04 )
#define HECC_TRS                *( volatile Uint32* )( HECC_BASE + 0x08 )
#define HECC_TRR                *( volatile Uint32* )( HECC_BASE + 0x0C )
#define HECC_TA                 *( volatile Uint32* )( HECC_BASE + 0x10 )
#define HECC_AA                 *( volatile Uint32* )( HECC_BASE + 0x14 )
#define HECC_RMP                *( volatile Uint32* )( HECC_BASE + 0x18 )
#define HECC_RML                *( volatile Uint32* )( HECC_BASE + 0x1C )
#define HECC_RFP                *( volatile Uint32* )( HECC_BASE + 0x20 )
#define HECC_GAM                *( volatile Uint32* )( HECC_BASE + 0x24 )
#define HECC_MC                 *( volatile Uint32* )( HECC_BASE + 0x28 )
#define HECC_BTC                *( volatile Uint32* )( HECC_BASE + 0x2C )
#define HECC_ES                 *( volatile Uint32* )( HECC_BASE + 0x30 )
#define HECC_TEC                *( volatile Uint32* )( HECC_BASE + 0x34 )
#define HECC_REC                *( volatile Uint32* )( HECC_BASE + 0x38 )
#define HECC_GIF0               *( volatile Uint32* )( HECC_BASE + 0x3C )
#define HECC_GIM                *( volatile Uint32* )( HECC_BASE + 0x40 )
#define HECC_GIF1               *( volatile Uint32* )( HECC_BASE + 0x44 )
#define HECC_MIM                *( volatile Uint32* )( HECC_BASE + 0x48 )
#define HECC_MIL                *( volatile Uint32* )( HECC_BASE + 0x4C )
#define HECC_OPC                *( volatile Uint32* )( HECC_BASE + 0x50 )
#define HECC_TIOC               *( volatile Uint32* )( HECC_BASE + 0x54 )
#define HECC_RIOC               *( volatile Uint32* )( HECC_BASE + 0x58 )
#define HECC_LNT                *( volatile Uint32* )( HECC_BASE + 0x5C )
#define HECC_TOC                *( volatile Uint32* )( HECC_BASE + 0x60 )
#define HECC_TOS                *( volatile Uint32* )( HECC_BASE + 0x64 )
#define HECC_TIOCE              *( volatile Uint32* )( HECC_BASE + 0x68 )
#define HECC_RIOCE              *( volatile Uint32* )( HECC_BASE + 0x6C )
#define HECC_ETC                *( volatile Uint32* )( HECC_BASE + 0x70 )

#define HECC_RAM_BASE           0x01C24000
#define HECC_MBX_0              *( volatile Uint32* )( HECC_RAM_BASE + 0x00 )
#define HECC_MBX_1              *( volatile Uint32* )( HECC_RAM_BASE + 0x04 )
#define HECC_MBX_2              *( volatile Uint32* )( HECC_RAM_BASE + 0x08 )
#define HECC_MBX_3              *( volatile Uint32* )( HECC_RAM_BASE + 0x0C )
#define HECC_MBX_4              *( volatile Uint32* )( HECC_RAM_BASE + 0x10 )
#define HECC_MBX_5              *( volatile Uint32* )( HECC_RAM_BASE + 0x14 )
#define HECC_MBX_6              *( volatile Uint32* )( HECC_RAM_BASE + 0x18 )
#define HECC_MBX_7              *( volatile Uint32* )( HECC_RAM_BASE + 0x1C )
#define HECC_MBX_8              *( volatile Uint32* )( HECC_RAM_BASE + 0x20 )
#define HECC_MBX_9              *( volatile Uint32* )( HECC_RAM_BASE + 0x24 )
#define HECC_MBX_10             *( volatile Uint32* )( HECC_RAM_BASE + 0x28 )
#define HECC_MBX_11             *( volatile Uint32* )( HECC_RAM_BASE + 0x2C )
#define HECC_MBX_12             *( volatile Uint32* )( HECC_RAM_BASE + 0x30 )
#define HECC_MBX_13             *( volatile Uint32* )( HECC_RAM_BASE + 0x34 )
#define HECC_MBX_14             *( volatile Uint32* )( HECC_RAM_BASE + 0x38 )
#define HECC_MBX_15             *( volatile Uint32* )( HECC_RAM_BASE + 0x3C )
#define HECC_MBX_16             *( volatile Uint32* )( HECC_RAM_BASE + 0x40 )
#define HECC_MBX_17             *( volatile Uint32* )( HECC_RAM_BASE + 0x44 )
#define HECC_MBX_18             *( volatile Uint32* )( HECC_RAM_BASE + 0x48 )
#define HECC_MBX_19             *( volatile Uint32* )( HECC_RAM_BASE + 0x4C )
#define HECC_MBX_20             *( volatile Uint32* )( HECC_RAM_BASE + 0x50 )
#define HECC_MBX_21             *( volatile Uint32* )( HECC_RAM_BASE + 0x54 )
#define HECC_MBX_22             *( volatile Uint32* )( HECC_RAM_BASE + 0x58 )
#define HECC_MBX_23             *( volatile Uint32* )( HECC_RAM_BASE + 0x5C )
#define HECC_MBX_24             *( volatile Uint32* )( HECC_RAM_BASE + 0x60 )
#define HECC_MBX_25             *( volatile Uint32* )( HECC_RAM_BASE + 0x64 )
#define HECC_MBX_26             *( volatile Uint32* )( HECC_RAM_BASE + 0x68 )
#define HECC_MBX_27             *( volatile Uint32* )( HECC_RAM_BASE + 0x6C )
#define HECC_MBX_28             *( volatile Uint32* )( HECC_RAM_BASE + 0x70 )
#define HECC_MBX_29             *( volatile Uint32* )( HECC_RAM_BASE + 0x74 )
#define HECC_MBX_30             *( volatile Uint32* )( HECC_RAM_BASE + 0x78 )
#define HECC_MBX_31             *( volatile Uint32* )( HECC_RAM_BASE + 0x7C )

#define HECC_LAM_0              *( volatile Uint32* )( HECC_RAM_BASE + 0xE80 )
#define HECC_LAM_1              *( volatile Uint32* )( HECC_RAM_BASE + 0xE84 )
#define HECC_LAM_2              *( volatile Uint32* )( HECC_RAM_BASE + 0xE88 )
#define HECC_LAM_3              *( volatile Uint32* )( HECC_RAM_BASE + 0xE8C )
#define HECC_LAM_4              *( volatile Uint32* )( HECC_RAM_BASE + 0xE90 )
#define HECC_LAM_5              *( volatile Uint32* )( HECC_RAM_BASE + 0xE94 )
#define HECC_LAM_6              *( volatile Uint32* )( HECC_RAM_BASE + 0xE98 )
#define HECC_LAM_7              *( volatile Uint32* )( HECC_RAM_BASE + 0xE9C )
#define HECC_LAM_8              *( volatile Uint32* )( HECC_RAM_BASE + 0xEA0 )
#define HECC_LAM_9              *( volatile Uint32* )( HECC_RAM_BASE + 0xEA4 )
#define HECC_LAM_10             *( volatile Uint32* )( HECC_RAM_BASE + 0xEA8 )
#define HECC_LAM_11             *( volatile Uint32* )( HECC_RAM_BASE + 0xEAC )
#define HECC_LAM_12             *( volatile Uint32* )( HECC_RAM_BASE + 0xEB0 )
#define HECC_LAM_13             *( volatile Uint32* )( HECC_RAM_BASE + 0xEB4 )
#define HECC_LAM_14             *( volatile Uint32* )( HECC_RAM_BASE + 0xEB8 )
#define HECC_LAM_15             *( volatile Uint32* )( HECC_RAM_BASE + 0xEBC )
#define HECC_LAM_16             *( volatile Uint32* )( HECC_RAM_BASE + 0xEC0 )
#define HECC_LAM_17             *( volatile Uint32* )( HECC_RAM_BASE + 0xEC4 )
#define HECC_LAM_18             *( volatile Uint32* )( HECC_RAM_BASE + 0xEC8 )
#define HECC_LAM_19             *( volatile Uint32* )( HECC_RAM_BASE + 0xECC )
#define HECC_LAM_20             *( volatile Uint32* )( HECC_RAM_BASE + 0xED0 )
#define HECC_LAM_21             *( volatile Uint32* )( HECC_RAM_BASE + 0xED4 )
#define HECC_LAM_22             *( volatile Uint32* )( HECC_RAM_BASE + 0xED8 )
#define HECC_LAM_23             *( volatile Uint32* )( HECC_RAM_BASE + 0xEDC )
#define HECC_LAM_24             *( volatile Uint32* )( HECC_RAM_BASE + 0xEE0 )
#define HECC_LAM_25             *( volatile Uint32* )( HECC_RAM_BASE + 0xEE4 )
#define HECC_LAM_26             *( volatile Uint32* )( HECC_RAM_BASE + 0xEE8 )
#define HECC_LAM_27             *( volatile Uint32* )( HECC_RAM_BASE + 0xEEC )
#define HECC_LAM_28             *( volatile Uint32* )( HECC_RAM_BASE + 0xEF0 )
#define HECC_LAM_29             *( volatile Uint32* )( HECC_RAM_BASE + 0xEF4 )
#define HECC_LAM_30             *( volatile Uint32* )( HECC_RAM_BASE + 0xEF8 )
#define HECC_LAM_31             *( volatile Uint32* )( HECC_RAM_BASE + 0xEFC )

#define HECC_MOTS_0             *( volatile Uint32* )( HECC_RAM_BASE + 0xF00 )
#define HECC_MOTS_1             *( volatile Uint32* )( HECC_RAM_BASE + 0xF04 )
#define HECC_MOTS_2             *( volatile Uint32* )( HECC_RAM_BASE + 0xF08 )
#define HECC_MOTS_3             *( volatile Uint32* )( HECC_RAM_BASE + 0xF0C )
#define HECC_MOTS_4             *( volatile Uint32* )( HECC_RAM_BASE + 0xF10 )
#define HECC_MOTS_5             *( volatile Uint32* )( HECC_RAM_BASE + 0xF14 )
#define HECC_MOTS_6             *( volatile Uint32* )( HECC_RAM_BASE + 0xF18 )
#define HECC_MOTS_7             *( volatile Uint32* )( HECC_RAM_BASE + 0xF1C )
#define HECC_MOTS_8             *( volatile Uint32* )( HECC_RAM_BASE + 0xF20 )
#define HECC_MOTS_9             *( volatile Uint32* )( HECC_RAM_BASE + 0xF24 )
#define HECC_MOTS_10            *( volatile Uint32* )( HECC_RAM_BASE + 0xF28 )
#define HECC_MOTS_11            *( volatile Uint32* )( HECC_RAM_BASE + 0xF2C )
#define HECC_MOTS_12            *( volatile Uint32* )( HECC_RAM_BASE + 0xF30 )
#define HECC_MOTS_13            *( volatile Uint32* )( HECC_RAM_BASE + 0xF34 )
#define HECC_MOTS_14            *( volatile Uint32* )( HECC_RAM_BASE + 0xF38 )
#define HECC_MOTS_15            *( volatile Uint32* )( HECC_RAM_BASE + 0xF3C )
#define HECC_MOTS_16            *( volatile Uint32* )( HECC_RAM_BASE + 0xF40 )
#define HECC_MOTS_17            *( volatile Uint32* )( HECC_RAM_BASE + 0xF44 )
#define HECC_MOTS_18            *( volatile Uint32* )( HECC_RAM_BASE + 0xF48 )
#define HECC_MOTS_19            *( volatile Uint32* )( HECC_RAM_BASE + 0xF4C )
#define HECC_MOTS_20            *( volatile Uint32* )( HECC_RAM_BASE + 0xF50 )
#define HECC_MOTS_21            *( volatile Uint32* )( HECC_RAM_BASE + 0xF54 )
#define HECC_MOTS_22            *( volatile Uint32* )( HECC_RAM_BASE + 0xF58 )
#define HECC_MOTS_23            *( volatile Uint32* )( HECC_RAM_BASE + 0xF5C )
#define HECC_MOTS_24            *( volatile Uint32* )( HECC_RAM_BASE + 0xF60 )
#define HECC_MOTS_25            *( volatile Uint32* )( HECC_RAM_BASE + 0xF64 )
#define HECC_MOTS_26            *( volatile Uint32* )( HECC_RAM_BASE + 0xF68 )
#define HECC_MOTS_27            *( volatile Uint32* )( HECC_RAM_BASE + 0xF6C )
#define HECC_MOTS_28            *( volatile Uint32* )( HECC_RAM_BASE + 0xF70 )
#define HECC_MOTS_29            *( volatile Uint32* )( HECC_RAM_BASE + 0xF74 )
#define HECC_MOTS_30            *( volatile Uint32* )( HECC_RAM_BASE + 0xF78 )
#define HECC_MOTS_31            *( volatile Uint32* )( HECC_RAM_BASE + 0xF7C )

#define HECC_MOTO_0             *( volatile Uint32* )( HECC_RAM_BASE + 0xF80 )
#define HECC_MOTO_1             *( volatile Uint32* )( HECC_RAM_BASE + 0xF84 )
#define HECC_MOTO_2             *( volatile Uint32* )( HECC_RAM_BASE + 0xF88 )
#define HECC_MOTO_3             *( volatile Uint32* )( HECC_RAM_BASE + 0xF8C )
#define HECC_MOTO_4             *( volatile Uint32* )( HECC_RAM_BASE + 0xF90 )
#define HECC_MOTO_5             *( volatile Uint32* )( HECC_RAM_BASE + 0xF94 )
#define HECC_MOTO_6             *( volatile Uint32* )( HECC_RAM_BASE + 0xF98 )
#define HECC_MOTO_7             *( volatile Uint32* )( HECC_RAM_BASE + 0xF9C )
#define HECC_MOTO_8             *( volatile Uint32* )( HECC_RAM_BASE + 0xFA0 )
#define HECC_MOTO_9             *( volatile Uint32* )( HECC_RAM_BASE + 0xFA4 )
#define HECC_MOTO_10            *( volatile Uint32* )( HECC_RAM_BASE + 0xFA8 )
#define HECC_MOTO_11            *( volatile Uint32* )( HECC_RAM_BASE + 0xFAC )
#define HECC_MOTO_12            *( volatile Uint32* )( HECC_RAM_BASE + 0xFB0 )
#define HECC_MOTO_13            *( volatile Uint32* )( HECC_RAM_BASE + 0xFB4 )
#define HECC_MOTO_14            *( volatile Uint32* )( HECC_RAM_BASE + 0xFB8 )
#define HECC_MOTO_15            *( volatile Uint32* )( HECC_RAM_BASE + 0xFBC )
#define HECC_MOTO_16            *( volatile Uint32* )( HECC_RAM_BASE + 0xFC0 )
#define HECC_MOTO_17            *( volatile Uint32* )( HECC_RAM_BASE + 0xFC4 )
#define HECC_MOTO_18            *( volatile Uint32* )( HECC_RAM_BASE + 0xFC8 )
#define HECC_MOTO_19            *( volatile Uint32* )( HECC_RAM_BASE + 0xFCC )
#define HECC_MOTO_20            *( volatile Uint32* )( HECC_RAM_BASE + 0xFD0 )
#define HECC_MOTO_21            *( volatile Uint32* )( HECC_RAM_BASE + 0xFD4 )
#define HECC_MOTO_22            *( volatile Uint32* )( HECC_RAM_BASE + 0xFD8 )
#define HECC_MOTO_23            *( volatile Uint32* )( HECC_RAM_BASE + 0xFDC )
#define HECC_MOTO_24            *( volatile Uint32* )( HECC_RAM_BASE + 0xFE0 )
#define HECC_MOTO_25            *( volatile Uint32* )( HECC_RAM_BASE + 0xFE4 )
#define HECC_MOTO_26            *( volatile Uint32* )( HECC_RAM_BASE + 0xFE8 )
#define HECC_MOTO_27            *( volatile Uint32* )( HECC_RAM_BASE + 0xFEC )
#define HECC_MOTO_28            *( volatile Uint32* )( HECC_RAM_BASE + 0xFF0 )
#define HECC_MOTO_29            *( volatile Uint32* )( HECC_RAM_BASE + 0xFF4 )
#define HECC_MOTO_30            *( volatile Uint32* )( HECC_RAM_BASE + 0xFF8 )
#define HECC_MOTO_31            *( volatile Uint32* )( HECC_RAM_BASE + 0xFFC )

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  HPI Controller                                                          *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define HPI_BASE                0x01C67800
#define HPI_PWREMU_MGMT         *( volatile Uint32* )( HPI_BASE + 0x04 )
#define HPI_HPIC                *( volatile Uint32* )( HPI_BASE + 0x30 )
#define HPI_HPIAW               *( volatile Uint32* )( HPI_BASE + 0x34 )
#define HPI_HPIAR               *( volatile Uint32* )( HPI_BASE + 0x08 )

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  I2C Controller                                                          *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define I2C_BASE                0x01C21000
#define I2C_OAR                 *( volatile Uint32* )( I2C_BASE + 0x00 )
#define I2C_ICIMR               *( volatile Uint32* )( I2C_BASE + 0x04 )
#define I2C_ICSTR               *( volatile Uint32* )( I2C_BASE + 0x08 )
#define I2C_ICCLKL              *( volatile Uint32* )( I2C_BASE + 0x0C )
#define I2C_ICCLKH              *( volatile Uint32* )( I2C_BASE + 0x10 )
#define I2C_ICCNT               *( volatile Uint32* )( I2C_BASE + 0x14 )
#define I2C_ICDRR               *( volatile Uint32* )( I2C_BASE + 0x18 )
#define I2C_ICSAR               *( volatile Uint32* )( I2C_BASE + 0x1C )
#define I2C_ICDXR               *( volatile Uint32* )( I2C_BASE + 0x20 )
#define I2C_ICMDR               *( volatile Uint32* )( I2C_BASE + 0x24 )
#define I2C_ICIVR               *( volatile Uint32* )( I2C_BASE + 0x28 )
#define I2C_ICEMDR              *( volatile Uint32* )( I2C_BASE + 0x2C )
#define I2C_ICPSC               *( volatile Uint32* )( I2C_BASE + 0x30 )
#define I2C_ICPID1              *( volatile Uint32* )( I2C_BASE + 0x34 )
#define I2C_ICPID2              *( volatile Uint32* )( I2C_BASE + 0x38 )

/* I2C Field Definitions */
#define ICOAR_MASK_7                    0x007F
#define ICOAR_MASK_10                   0x03FF
#define ICSAR_MASK_7                    0x007F
#define ICSAR_MASK_10                   0x03FF
#define ICOAR_OADDR                     0x007f
#define ICSAR_SADDR                     0x0050

#define ICSTR_SDIR                      0x4000
#define ICSTR_NACKINT                   0x2000
#define ICSTR_BB                        0x1000
#define ICSTR_RSFULL                    0x0800
#define ICSTR_XSMT                      0x0400
#define ICSTR_AAS                       0x0200
#define ICSTR_AD0                       0x0100
#define ICSTR_SCD                       0x0020
#define ICSTR_ICXRDY                    0x0010
#define ICSTR_ICRRDY                    0x0008
#define ICSTR_ARDY                      0x0004
#define ICSTR_NACK                      0x0002
#define ICSTR_AL                        0x0001

#define ICMDR_NACKMOD                   0x8000
#define ICMDR_FREE                      0x4000
#define ICMDR_STT                       0x2000
#define ICMDR_IDLEEN                    0x1000
#define ICMDR_STP                       0x0800
#define ICMDR_MST                       0x0400
#define ICMDR_TRX                       0x0200
#define ICMDR_XA                        0x0100
#define ICMDR_RM                        0x0080
#define ICMDR_DLB                       0x0040
#define ICMDR_IRS                       0x0020
#define ICMDR_STB                       0x0010
#define ICMDR_FDF                       0x0008
#define ICMDR_BC_MASK                   0x0007

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  INTC controller                                                         *
 *      Controls the Interrupts                                             *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define INTC_BASE               0x01800000
#define INTC_EVTFLAG0           *( volatile Uint32* )( INTC_BASE + 0x000 )
#define INTC_EVTFLAG1           *( volatile Uint32* )( INTC_BASE + 0x004 )
#define INTC_EVTFLAG2           *( volatile Uint32* )( INTC_BASE + 0x008 )
#define INTC_EVTFLAG3           *( volatile Uint32* )( INTC_BASE + 0x00C )
#define INTC_EVTSET0            *( volatile Uint32* )( INTC_BASE + 0x020 )
#define INTC_EVTSET1            *( volatile Uint32* )( INTC_BASE + 0x024 )
#define INTC_EVTSET2            *( volatile Uint32* )( INTC_BASE + 0x028 )
#define INTC_EVTSET3            *( volatile Uint32* )( INTC_BASE + 0x02C )
#define INTC_EVTCLR0            *( volatile Uint32* )( INTC_BASE + 0x040 )
#define INTC_EVTCLR1            *( volatile Uint32* )( INTC_BASE + 0x044 )
#define INTC_EVTCLR2            *( volatile Uint32* )( INTC_BASE + 0x048 )
#define INTC_EVTCLR3            *( volatile Uint32* )( INTC_BASE + 0x04C )
#define INTC_EVTMASK0           *( volatile Uint32* )( INTC_BASE + 0x080 )
#define INTC_EVTMASK1           *( volatile Uint32* )( INTC_BASE + 0x084 )
#define INTC_EVTMASK2           *( volatile Uint32* )( INTC_BASE + 0x088 )
#define INTC_EVTMASK3           *( volatile Uint32* )( INTC_BASE + 0x08C )
#define INTC_MEVTFLAG0          *( volatile Uint32* )( INTC_BASE + 0x0A0 )
#define INTC_MEVTFLAG1          *( volatile Uint32* )( INTC_BASE + 0x0A4 )
#define INTC_MEVTFLAG2          *( volatile Uint32* )( INTC_BASE + 0x0A8 )
#define INTC_MEVTFLAG3          *( volatile Uint32* )( INTC_BASE + 0x0AC )
#define INTC_EXPMASK0           *( volatile Uint32* )( INTC_BASE + 0x0C0 )
#define INTC_EXPMASK1           *( volatile Uint32* )( INTC_BASE + 0x0C4 )
#define INTC_EXPMASK2           *( volatile Uint32* )( INTC_BASE + 0x0C8 )
#define INTC_EXPMASK3           *( volatile Uint32* )( INTC_BASE + 0x0CC )
#define INTC_MEXPFLAG0          *( volatile Uint32* )( INTC_BASE + 0x000 )
#define INTC_MEXPFLAG1          *( volatile Uint32* )( INTC_BASE + 0x000 )
#define INTC_MEXPFLAG2          *( volatile Uint32* )( INTC_BASE + 0x000 )
#define INTC_MEXPFLAG3          *( volatile Uint32* )( INTC_BASE + 0x0EC )
#define INTC_INTMUX1            *( volatile Uint32* )( INTC_BASE + 0x104 )
#define INTC_INTMUX2            *( volatile Uint32* )( INTC_BASE + 0x108 )
#define INTC_INTMUX3            *( volatile Uint32* )( INTC_BASE + 0x10C )
#define INTC_AEGMUX0            *( volatile Uint32* )( INTC_BASE + 0x140 )
#define INTC_AEGMUX1            *( volatile Uint32* )( INTC_BASE + 0x144 )
#define INTC_INTXSTAT           *( volatile Uint32* )( INTC_BASE + 0x180 )
#define INTC_INTXCLR            *( volatile Uint32* )( INTC_BASE + 0x184 )
#define INTC_INTDMASK           *( volatile Uint32* )( INTC_BASE + 0x188 )
#define INTC_EVTASRT            *( volatile Uint32* )( INTC_BASE + 0x1C0 )

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  MCASP Controller                                                        *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define MCASP0_BASE             0x01D01000
#define MCASP0_DATA             0x01D01400
#define MCASP0_PID              *( volatile Uint32* )( MCASP0_BASE + 0x000 )
#define MCASP0_PWRDEMU          *( volatile Uint32* )( MCASP0_BASE + 0x004 )
#define MCASP0_PFUNC            *( volatile Uint32* )( MCASP0_BASE + 0x010 )
#define MCASP0_PDIR             *( volatile Uint32* )( MCASP0_BASE + 0x014 )
#define MCASP0_PDOUT            *( volatile Uint32* )( MCASP0_BASE + 0x018 )
#define MCASP0_PDIN/PDSET       *( volatile Uint32* )( MCASP0_BASE + 0x01C )
#define MCASP0_PDCLR            *( volatile Uint32* )( MCASP0_BASE + 0x020 )
#define MCASP0_GBLCTL           *( volatile Uint32* )( MCASP0_BASE + 0x044 )
#define MCASP0_AMUTE            *( volatile Uint32* )( MCASP0_BASE + 0x048 )
#define MCASP0_DLBCTL           *( volatile Uint32* )( MCASP0_BASE + 0x04C )
#define MCASP0_DITCTL           *( volatile Uint32* )( MCASP0_BASE + 0x050 )
#define MCASP0_RGBLCTL          *( volatile Uint32* )( MCASP0_BASE + 0x060 )
#define MCASP0_RMASK            *( volatile Uint32* )( MCASP0_BASE + 0x064 )
#define MCASP0_RFMT             *( volatile Uint32* )( MCASP0_BASE + 0x068 )
#define MCASP0_AFSRCTL          *( volatile Uint32* )( MCASP0_BASE + 0x06C )
#define MCASP0_ACLKRCTL         *( volatile Uint32* )( MCASP0_BASE + 0x070 )
#define MCASP0_AHCLKRCTL        *( volatile Uint32* )( MCASP0_BASE + 0x074 )
#define MCASP0_RTDM             *( volatile Uint32* )( MCASP0_BASE + 0x078 )
#define MCASP0_RINTCTL          *( volatile Uint32* )( MCASP0_BASE + 0x07C )
#define MCASP0_RSTAT            *( volatile Uint32* )( MCASP0_BASE + 0x080 )
#define MCASP0_RSLOT            *( volatile Uint32* )( MCASP0_BASE + 0x084 )
#define MCASP0_RCLKCHK          *( volatile Uint32* )( MCASP0_BASE + 0x088 )
#define MCASP0_XGBLCTL          *( volatile Uint32* )( MCASP0_BASE + 0x0A0 )
#define MCASP0_XMASK            *( volatile Uint32* )( MCASP0_BASE + 0x0A4 )
#define MCASP0_XFMT             *( volatile Uint32* )( MCASP0_BASE + 0x0A8 )
#define MCASP0_AFSXCTL          *( volatile Uint32* )( MCASP0_BASE + 0x0AC )
#define MCASP0_ACLKXCTL         *( volatile Uint32* )( MCASP0_BASE + 0x0B0 )
#define MCASP0_AHCLKXCTL        *( volatile Uint32* )( MCASP0_BASE + 0x0B4 )
#define MCASP0_XTDM             *( volatile Uint32* )( MCASP0_BASE + 0x0B8 )
#define MCASP0_XINTCTL          *( volatile Uint32* )( MCASP0_BASE + 0x0BC )
#define MCASP0_XSTAT            *( volatile Uint32* )( MCASP0_BASE + 0x0C0 )
#define MCASP0_XSLOT            *( volatile Uint32* )( MCASP0_BASE + 0x0C4 )
#define MCASP0_XCLKCHK          *( volatile Uint32* )( MCASP0_BASE + 0x0C8 )
#define MCASP0_DITCSRA0         *( volatile Uint32* )( MCASP0_BASE + 0x100 )
#define MCASP0_DITCSRA1         *( volatile Uint32* )( MCASP0_BASE + 0x104 )
#define MCASP0_DITCSRA2         *( volatile Uint32* )( MCASP0_BASE + 0x108 )
#define MCASP0_DITCSRA3         *( volatile Uint32* )( MCASP0_BASE + 0x10C )
#define MCASP0_DITCSRA4         *( volatile Uint32* )( MCASP0_BASE + 0x110 )
#define MCASP0_DITCSRA5         *( volatile Uint32* )( MCASP0_BASE + 0x114 )
#define MCASP0_DITCSRB0         *( volatile Uint32* )( MCASP0_BASE + 0x118 )
#define MCASP0_DITCSRB1         *( volatile Uint32* )( MCASP0_BASE + 0x11C )
#define MCASP0_DITCSRB2         *( volatile Uint32* )( MCASP0_BASE + 0x120 )
#define MCASP0_DITCSRB3         *( volatile Uint32* )( MCASP0_BASE + 0x124 )
#define MCASP0_DITCSRB4         *( volatile Uint32* )( MCASP0_BASE + 0x128 )
#define MCASP0_DITCSRB5         *( volatile Uint32* )( MCASP0_BASE + 0x12C )
#define MCASP0_DITUDRA0         *( volatile Uint32* )( MCASP0_BASE + 0x130 )
#define MCASP0_DITUDRA1         *( volatile Uint32* )( MCASP0_BASE + 0x134 )
#define MCASP0_DITUDRA2         *( volatile Uint32* )( MCASP0_BASE + 0x138 )
#define MCASP0_DITUDRA3         *( volatile Uint32* )( MCASP0_BASE + 0x13C )
#define MCASP0_DITUDRA4         *( volatile Uint32* )( MCASP0_BASE + 0x140 )
#define MCASP0_DITUDRA5         *( volatile Uint32* )( MCASP0_BASE + 0x144 )
#define MCASP0_DITUDRB0         *( volatile Uint32* )( MCASP0_BASE + 0x148 )
#define MCASP0_DITUDRB1         *( volatile Uint32* )( MCASP0_BASE + 0x14C )
#define MCASP0_DITUDRB2         *( volatile Uint32* )( MCASP0_BASE + 0x150 )
#define MCASP0_DITUDRB3         *( volatile Uint32* )( MCASP0_BASE + 0x154 )
#define MCASP0_DITUDRB4         *( volatile Uint32* )( MCASP0_BASE + 0x158 )
#define MCASP0_DITUDRB5         *( volatile Uint32* )( MCASP0_BASE + 0x15C )
#define MCASP0_SRCTL0           *( volatile Uint32* )( MCASP0_BASE + 0x180 )
#define MCASP0_SRCTL1           *( volatile Uint32* )( MCASP0_BASE + 0x184 )
#define MCASP0_SRCTL2           *( volatile Uint32* )( MCASP0_BASE + 0x188 )
#define MCASP0_SRCTL3           *( volatile Uint32* )( MCASP0_BASE + 0x18C )
#define MCASP0_XBUF0            *( volatile Uint32* )( MCASP0_BASE + 0x200 )
#define MCASP0_XBUF0_16BIT      *( volatile Uint16* )( MCASP0_BASE + 0x200 )
#define MCASP0_XBUF0_32BIT      *( volatile Uint32* )( MCASP0_BASE + 0x200 )
#define MCASP0_XBUF1            *( volatile Uint32* )( MCASP0_BASE + 0x204 )
#define MCASP0_XBUF1_16BIT      *( volatile Uint16* )( MCASP0_BASE + 0x204 )
#define MCASP0_XBUF1_32BIT      *( volatile Uint32* )( MCASP0_BASE + 0x204 )
#define MCASP0_XBUF2            *( volatile Uint32* )( MCASP0_BASE + 0x208 )
#define MCASP0_XBUF2_16BIT      *( volatile Uint16* )( MCASP0_BASE + 0x208 )
#define MCASP0_XBUF2_32BIT      *( volatile Uint32* )( MCASP0_BASE + 0x208 )
#define MCASP0_XBUF3            *( volatile Uint32* )( MCASP0_BASE + 0x20C )
#define MCASP0_XBUF3_16BIT      *( volatile Uint16* )( MCASP0_BASE + 0x20C )
#define MCASP0_XBUF3_32BIT      *( volatile Uint32* )( MCASP0_BASE + 0x20C )
#define MCASP0_RBUF0            *( volatile Uint32* )( MCASP0_BASE + 0x280 )
#define MCASP0_RBUF0_16BIT      *( volatile Uint16* )( MCASP0_BASE + 0x280 )
#define MCASP0_RBUF0_32BIT      *( volatile Uint32* )( MCASP0_BASE + 0x280 )
#define MCASP0_RBUF1            *( volatile Uint32* )( MCASP0_BASE + 0x284 )
#define MCASP0_RBUF1_16BIT      *( volatile Uint16* )( MCASP0_BASE + 0x284 )
#define MCASP0_RBUF1_32BIT      *( volatile Uint32* )( MCASP0_BASE + 0x284 )
#define MCASP0_RBUF2            *( volatile Uint32* )( MCASP0_BASE + 0x288 )
#define MCASP0_RBUF2_16BIT      *( volatile Uint16* )( MCASP0_BASE + 0x288 )
#define MCASP0_RBUF2_32BIT      *( volatile Uint32* )( MCASP0_BASE + 0x288 )
#define MCASP0_RBUF3            *( volatile Uint32* )( MCASP0_BASE + 0x28C )
#define MCASP0_RBUF3_16BIT      *( volatile Uint16* )( MCASP0_BASE + 0x28C )
#define MCASP0_RBUF3_32BIT      *( volatile Uint32* )( MCASP0_BASE + 0x28C )

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  MCBSP Controller                                                        *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define MCBSP0_BASE             0x01D00000
#define MCBSP0_DRR_32BIT        *( volatile Uint32* )( MCBSP0_BASE + 0x00 )
#define MCBSP0_DRR_16BIT        *( volatile Uint16* )( MCBSP0_BASE + 0x00 )
#define MCBSP0_DRR_8BIT         *( volatile Uint8* ) ( MCBSP0_BASE + 0x00 )
#define MCBSP0_DXR_32BIT        *( volatile Uint32* )( MCBSP0_BASE + 0x04 )
#define MCBSP0_DXR_16BIT        *( volatile Uint16* )( MCBSP0_BASE + 0x04 )
#define MCBSP0_DXR_8BIT         *( volatile Uint8* ) ( MCBSP0_BASE + 0x04 )
#define MCBSP0_SPCR             *( volatile Uint32* )( MCBSP0_BASE + 0x08 )
#define MCBSP0_RCR              *( volatile Uint32* )( MCBSP0_BASE + 0x0C )
#define MCBSP0_XCR              *( volatile Uint32* )( MCBSP0_BASE + 0x10 )
#define MCBSP0_SRGR             *( volatile Uint32* )( MCBSP0_BASE + 0x14 )
#define MCBSP0_MCR              *( volatile Uint32* )( MCBSP0_BASE + 0x18 )
#define MCBSP0_PCR              *( volatile Uint32* )( MCBSP0_BASE + 0x24 )
#define MCBSP0_RCERE10          *( volatile Uint32* )( MCBSP0_BASE + 0x28 )
#define MCBSP0_XCERE10          *( volatile Uint32* )( MCBSP0_BASE + 0x2C )
#define MCBSP0_RCERE20          *( volatile Uint32* )( MCBSP0_BASE + 0x30 )
#define MCBSP0_XCERE20          *( volatile Uint32* )( MCBSP0_BASE + 0x34 )
#define MCBSP0_RCERE30          *( volatile Uint32* )( MCBSP0_BASE + 0x38 )
#define MCBSP0_XCERE30          *( volatile Uint32* )( MCBSP0_BASE + 0x3C )

#define MCBSP1_BASE             0x01D00800
#define MCBSP1_DRR_32BIT        *( volatile Uint32* )( MCBSP1_BASE + 0x00 )
#define MCBSP1_DRR_16BIT        *( volatile Uint16* )( MCBSP1_BASE + 0x00 )
#define MCBSP1_DRR_8BIT         *( volatile Uint8* ) ( MCBSP1_BASE + 0x00 )
#define MCBSP1_DXR_32BIT        *( volatile Uint32* )( MCBSP1_BASE + 0x04 )
#define MCBSP1_DXR_16BIT        *( volatile Uint16* )( MCBSP1_BASE + 0x04 )
#define MCBSP1_DXR_8BIT         *( volatile Uint8* ) ( MCBSP1_BASE + 0x04 )
#define MCBSP1_SPCR             *( volatile Uint32* )( MCBSP1_BASE + 0x08 )
#define MCBSP1_RCR              *( volatile Uint32* )( MCBSP1_BASE + 0x0C )
#define MCBSP1_XCR              *( volatile Uint32* )( MCBSP1_BASE + 0x10 )
#define MCBSP1_SRGR             *( volatile Uint32* )( MCBSP1_BASE + 0x14 )
#define MCBSP1_MCR              *( volatile Uint32* )( MCBSP1_BASE + 0x18 )
#define MCBSP1_PCR              *( volatile Uint32* )( MCBSP1_BASE + 0x24 )
#define MCBSP1_RCERE11          *( volatile Uint32* )( MCBSP1_BASE + 0x28 )
#define MCBSP1_XCERE11          *( volatile Uint32* )( MCBSP1_BASE + 0x2C )
#define MCBSP1_RCERE21          *( volatile Uint32* )( MCBSP1_BASE + 0x30 )
#define MCBSP1_XCERE21          *( volatile Uint32* )( MCBSP1_BASE + 0x34 )
#define MCBSP1_RCERE31          *( volatile Uint32* )( MCBSP1_BASE + 0x38 )
#define MCBSP1_XCERE31          *( volatile Uint32* )( MCBSP1_BASE + 0x3C )

#define MCBSP_SPCR_FREE                 0x02000000
#define MCBSP_SPCR_SOFT                 0x01000000
#define MCBSP_SPCR_FRST                 0x00800000
#define MCBSP_SPCR_GRST                 0x00400000
#define MCBSP_SPCR_XSYNCERR             0x00080000
#define MCBSP_SPCR_XEMPTY               0x00040000
#define MCBSP_SPCR_XRDY                 0x00020000
#define MCBSP_SPCR_XRST                 0x00010000
#define MCBSP_SPCR_DLB                  0x00008000
#define MCBSP_SPCR_DXENA                0x00000020
#define MCBSP_SPCR_ABIS                 0x00000010
#define MCBSP_SPCR_RSYNCERR             0x00000008
#define MCBSP_SPCR_RFULL                0x00000004
#define MCBSP_SPCR_RRDY                 0x00000002
#define MCBSP_SPCR_RRST                 0x00000001

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  MDIO Controller                                                         *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define MDIO_BASE               0x01C84000
#define MDIO_VERSION            *( volatile Uint32* )( MDIO_BASE + 0x00 )
#define MDIO_CONTROL            *( volatile Uint32* )( MDIO_BASE + 0x04 )
#define MDIO_ALIVE              *( volatile Uint32* )( MDIO_BASE + 0x08 )
#define MDIO_LINK               *( volatile Uint32* )( MDIO_BASE + 0x0C )
#define MDIO_LINKINTRAW         *( volatile Uint32* )( MDIO_BASE + 0x10 )
#define MDIO_LINKINTMASKED      *( volatile Uint32* )( MDIO_BASE + 0x14 )
#define MDIO_USERINTRAW         *( volatile Uint32* )( MDIO_BASE + 0x20 )
#define MDIO_USERINTMASKED      *( volatile Uint32* )( MDIO_BASE + 0x24 )
#define MDIO_USERINTMASKSET     *( volatile Uint32* )( MDIO_BASE + 0x28 )
#define MDIO_USERINTMASKCLEAR   *( volatile Uint32* )( MDIO_BASE + 0x2C )
#define MDIO_USERACCESS0        *( volatile Uint32* )( MDIO_BASE + 0x80 )
#define MDIO_USERPHYSEL0        *( volatile Uint32* )( MDIO_BASE + 0x84 )
#define MDIO_USERACCESS1        *( volatile Uint32* )( MDIO_BASE + 0x88 )
#define MDIO_USERPHYSEL1        *( volatile Uint32* )( MDIO_BASE + 0x8C )

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  PCI Control                                                             *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define PCI_BASE                0x01C1A000

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  PLL1 Controller                                                         *
 *      Generates DSP, DMA, VPFE clocks                                     *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define PLL1_BASE               0x01C40800
#define PLL1_PID                *( volatile Uint32* )( PLL1_BASE + 0x000 )
#define PLL1_RSTYPE             *( volatile Uint32* )( PLL1_BASE + 0x0E4 )
#define PLL1_PLLCTL             *( volatile Uint32* )( PLL1_BASE + 0x100 )
#define PLL1_PLLM               *( volatile Uint32* )( PLL1_BASE + 0x110 )
#define PLL1_PLLDIV1            *( volatile Uint32* )( PLL1_BASE + 0x118 )
#define PLL1_PLLDIV2            *( volatile Uint32* )( PLL1_BASE + 0x11C )
#define PLL1_PLLDIV3            *( volatile Uint32* )( PLL1_BASE + 0x120 )
#define PLL1_POSTDIV            *( volatile Uint32* )( PLL1_BASE + 0x128 )
#define PLL1_BPDIV              *( volatile Uint32* )( PLL1_BASE + 0x12C )
#define PLL1_PLLCMD             *( volatile Uint32* )( PLL1_BASE + 0x138 )
#define PLL1_PLLSTAT            *( volatile Uint32* )( PLL1_BASE + 0x13C )
#define PLL1_CKEN               *( volatile Uint32* )( PLL1_BASE + 0x148 )
#define PLL1_CKSTAT             *( volatile Uint32* )( PLL1_BASE + 0x14C )
#define PLL1_SYSTAT             *( volatile Uint32* )( PLL1_BASE + 0x150 )

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  PLL2 Controller                                                         *
 *      Generates DDR2, VPBE clocks                                         *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define PLL2_BASE               0x01C40C00
#define PLL2_PID                *( volatile Uint32* )( PLL2_BASE + 0x000 )
#define PLL2_PLLCTL             *( volatile Uint32* )( PLL2_BASE + 0x100 )
#define PLL2_PLLM               *( volatile Uint32* )( PLL2_BASE + 0x110 )
#define PLL2_PLLDIV1            *( volatile Uint32* )( PLL2_BASE + 0x118 )
#define PLL2_PLLDIV2            *( volatile Uint32* )( PLL2_BASE + 0x11C )
#define PLL2_PLLDIV3            *( volatile Uint32* )( PLL2_BASE + 0x120 )
#define PLL2_OSCDIV1            *( volatile Uint32* )( PLL2_BASE + 0x124 )
#define PLL2_POSTDIV            *( volatile Uint32* )( PLL2_BASE + 0x128 )
#define PLL2_BPDIV              *( volatile Uint32* )( PLL2_BASE + 0x12C )
#define PLL2_PLLCMD             *( volatile Uint32* )( PLL2_BASE + 0x138 )
#define PLL2_PLLSTAT            *( volatile Uint32* )( PLL2_BASE + 0x13C )
#define PLL2_ALNCTL             *( volatile Uint32* )( PLL2_BASE + 0x140 )
#define PLL2_DCHANGE            *( volatile Uint32* )( PLL2_BASE + 0x144 )
#define PLL2_CKEN               *( volatile Uint32* )( PLL2_BASE + 0x148 )
#define PLL2_CKSTAT             *( volatile Uint32* )( PLL2_BASE + 0x14C )
#define PLL2_SYSTAT             *( volatile Uint32* )( PLL2_BASE + 0x150 )

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  PSC ( Power and Sleep Controller )                                      *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define PSC_BASE                0x01C41000
#define PSC_GBLCTL              *( volatile Uint32* )( PSC_BASE + 0x010 )
#define PSC_INTEVAL             *( volatile Uint32* )( PSC_BASE + 0x018 )
#define PSC_MERRPR0             *( volatile Uint32* )( PSC_BASE + 0x040 )
#define PSC_MERRPR1             *( volatile Uint32* )( PSC_BASE + 0x044 )
#define PSC_MERRCR0             *( volatile Uint32* )( PSC_BASE + 0x050 )
#define PSC_MERRCR1             *( volatile Uint32* )( PSC_BASE + 0x054 )
#define PSC_PERRPR              *( volatile Uint32* )( PSC_BASE + 0x060 )
#define PSC_PERRCR              *( volatile Uint32* )( PSC_BASE + 0x068 )
#define PSC_PTCMD               *( volatile Uint32* )( PSC_BASE + 0x120 )
#define PSC_PTSTAT              *( volatile Uint32* )( PSC_BASE + 0x128 )
#define PSC_PDSTAT0             *( volatile Uint32* )( PSC_BASE + 0x200 )
#define PSC_PDCTL0              *( volatile Uint32* )( PSC_BASE + 0x300 )
#define PSC_MCKOUT0             *( volatile Uint32* )( PSC_BASE + 0x510 )
#define PSC_MCKOUT1             *( volatile Uint32* )( PSC_BASE + 0x514 )
#define PSC_MDSTAT_BASE         ( PSC_BASE + 0x800 )
#define PSC_MDCTL_BASE          ( PSC_BASE + 0xA00 )

#define LPSC_VPSS_DMA           0
#define LPSC_VPSS_MMR           1
#define LPSC_EDMACC             2
#define LPSC_EDMATC0            3
#define LPSC_EDMATC1            4
#define LPSC_EMACTC2            5
#define LPSC_EMAC_MEMORY        6
#define LPSC_MDIO               7
#define LPSC_EMAC               8
#define LPSC_MCASP0             9
#define LPSC_VLYNQ              11
#define LPSC_HPI                12
#define LPSC_DDR2               13
#define LPSC_EMIFA              14
#define LPSC_PCI                15
#define LPSC_MCBSP0             16
#define LPSC_MCBSP1             17
#define LPSC_I2C                18
#define LPSC_UART0              19
#define LPSC_UART1              20
#define LPSC_HECC               22
#define LPSC_PWM0               23
#define LPSC_PWM1               24
#define LPSC_PWM2               25
#define LPSC_GPIO               26
#define LPSC_TIMER0             27
#define LPSC_TIMER1             28
#define LPSC_C64X               39

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  PWM Controller                                                          *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define PWM0_BASE               0x01C22000
#define PWM0_PID                *( volatile Uint32* )( PWM0_BASE + 0x00 )
#define PWM0_PCR                *( volatile Uint32* )( PWM0_BASE + 0x04 )
#define PWM0_CFG                *( volatile Uint32* )( PWM0_BASE + 0x08 )
#define PWM0_START              *( volatile Uint32* )( PWM0_BASE + 0x0C )
#define PWM0_RPT                *( volatile Uint32* )( PWM0_BASE + 0x10 )
#define PWM0_PER                *( volatile Uint32* )( PWM0_BASE + 0x14 )
#define PWM0_PH1D               *( volatile Uint32* )( PWM0_BASE + 0x18 )

#define PWM1_BASE               0x01C22400
#define PWM1_PID                *( volatile Uint32* )( PWM1_BASE + 0x00 )
#define PWM1_PCR                *( volatile Uint32* )( PWM1_BASE + 0x04 )
#define PWM1_CFG                *( volatile Uint32* )( PWM1_BASE + 0x08 )
#define PWM1_START              *( volatile Uint32* )( PWM1_BASE + 0x0C )
#define PWM1_RPT                *( volatile Uint32* )( PWM1_BASE + 0x10 )
#define PWM1_PER                *( volatile Uint32* )( PWM1_BASE + 0x14 )
#define PWM1_PH1D               *( volatile Uint32* )( PWM1_BASE + 0x18 )

#define PWM2_BASE               0x01C22800
#define PWM2_PID                *( volatile Uint32* )( PWM2_BASE + 0x00 )
#define PWM2_PCR                *( volatile Uint32* )( PWM2_BASE + 0x04 )
#define PWM2_CFG                *( volatile Uint32* )( PWM2_BASE + 0x08 )
#define PWM2_START              *( volatile Uint32* )( PWM2_BASE + 0x0C )
#define PWM2_RPT                *( volatile Uint32* )( PWM2_BASE + 0x10 )
#define PWM2_PER                *( volatile Uint32* )( PWM2_BASE + 0x14 )
#define PWM2_PH1D               *( volatile Uint32* )( PWM2_BASE + 0x18 )

#define PWM_PID                 ( 0x00 )
#define PWM_PCR                 ( 0x04 )
#define PWM_CFG                 ( 0x08 )
#define PWM_START               ( 0x0C )
#define PWM_RPT                 ( 0x10 )
#define PWM_PER                 ( 0x14 )
#define PWM_PH1D                ( 0x18 )

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  Timer Controller                                                        *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define TIMER0_BASE             0x01C21400
#define TIMER0_EMUMGT           *( volatile Uint32* )( TIMER0_BASE + 0x04 )
#define TIMER0_TIM12            *( volatile Uint32* )( TIMER0_BASE + 0x10 )
#define TIMER0_TIM34            *( volatile Uint32* )( TIMER0_BASE + 0x14 )
#define TIMER0_PRD12            *( volatile Uint32* )( TIMER0_BASE + 0x18 )
#define TIMER0_PRD34            *( volatile Uint32* )( TIMER0_BASE + 0x1C )
#define TIMER0_TRC              *( volatile Uint32* )( TIMER0_BASE + 0x20 )
#define TIMER0_TGCR             *( volatile Uint32* )( TIMER0_BASE + 0x24 )

#define TIMER1_BASE             0x01C21800
#define TIMER1_EMUMGT           *( volatile Uint32* )( TIMER1_BASE + 0x04 )
#define TIMER1_TIM12            *( volatile Uint32* )( TIMER1_BASE + 0x10 )
#define TIMER1_TIM34            *( volatile Uint32* )( TIMER1_BASE + 0x14 )
#define TIMER1_PRD12            *( volatile Uint32* )( TIMER1_BASE + 0x18 )
#define TIMER1_PRD34            *( volatile Uint32* )( TIMER1_BASE + 0x1C )
#define TIMER1_TRC              *( volatile Uint32* )( TIMER1_BASE + 0x20 )
#define TIMER1_TGCR             *( volatile Uint32* )( TIMER1_BASE + 0x24 )

#define TIMER2_BASE             0x01C21C00
#define TIMER2_EMUMGT           *( volatile Uint32* )( TIMER2_BASE + 0x04 )
#define TIMER2_TIM12            *( volatile Uint32* )( TIMER2_BASE + 0x10 )
#define TIMER2_TIM34            *( volatile Uint32* )( TIMER2_BASE + 0x14 )
#define TIMER2_PRD12            *( volatile Uint32* )( TIMER2_BASE + 0x18 )
#define TIMER2_PRD34            *( volatile Uint32* )( TIMER2_BASE + 0x1C )
#define TIMER2_TRC              *( volatile Uint32* )( TIMER2_BASE + 0x20 )
#define TIMER2_TGCR             *( volatile Uint32* )( TIMER2_BASE + 0x24 )
#define TIMER2_WDTCR            *( volatile Uint32* )( TIMER2_BASE + 0x28 )

#define TIMER_EMUMGT            ( 0x04 )
#define TIMER_TIM12             ( 0x10 )
#define TIMER_TIM34             ( 0x14 )
#define TIMER_PRD12             ( 0x18 )
#define TIMER_PRD34             ( 0x1C )
#define TIMER_TRC               ( 0x20 )
#define TIMER_TGCR              ( 0x24 )

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  UART Controller                                                         *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define UART0_BASE              0x01C20000
#define UART0_RBR               *( volatile Uint32* )( UART0_BASE + 0x00 )
#define UART0_THR               *( volatile Uint32* )( UART0_BASE + 0x00 )
#define UART0_IER               *( volatile Uint32* )( UART0_BASE + 0x04 )
#define UART0_IIR               *( volatile Uint32* )( UART0_BASE + 0x08 )
#define UART0_FCR               *( volatile Uint32* )( UART0_BASE + 0x08 )
#define UART0_LCR               *( volatile Uint32* )( UART0_BASE + 0x0C )
#define UART0_MCR               *( volatile Uint32* )( UART0_BASE + 0x10 )
#define UART0_LSR               *( volatile Uint32* )( UART0_BASE + 0x14 )
#define UART0_DLL               *( volatile Uint32* )( UART0_BASE + 0x20 )
#define UART0_DLH               *( volatile Uint32* )( UART0_BASE + 0x24 )
#define UART0_PID1              *( volatile Uint32* )( UART0_BASE + 0x28 )
#define UART0_PID2              *( volatile Uint32* )( UART0_BASE + 0x2C )
#define UART0_PWREMU_MGMT       *( volatile Uint32* )( UART0_BASE + 0x30 )

#define UART1_BASE              0x01C20400
#define UART1_RBR               *( volatile Uint32* )( UART1_BASE + 0x00 )
#define UART1_THR               *( volatile Uint32* )( UART1_BASE + 0x00 )
#define UART1_IER               *( volatile Uint32* )( UART1_BASE + 0x04 )
#define UART1_IIR               *( volatile Uint32* )( UART1_BASE + 0x08 )
#define UART1_FCR               *( volatile Uint32* )( UART1_BASE + 0x08 )
#define UART1_LCR               *( volatile Uint32* )( UART1_BASE + 0x0C )
#define UART1_MCR               *( volatile Uint32* )( UART1_BASE + 0x10 )
#define UART1_LSR               *( volatile Uint32* )( UART1_BASE + 0x14 )
#define UART1_DLL               *( volatile Uint32* )( UART1_BASE + 0x20 )
#define UART1_DLH               *( volatile Uint32* )( UART1_BASE + 0x24 )
#define UART1_PID1              *( volatile Uint32* )( UART1_BASE + 0x28 )
#define UART1_PID2              *( volatile Uint32* )( UART1_BASE + 0x2C )
#define UART1_PWREMU_MGMT       *( volatile Uint32* )( UART1_BASE + 0x30 )

#define UART_RBR                ( 0x00 )
#define UART_THR                ( 0x00 )
#define UART_IER                ( 0x04 )
#define UART_IIR                ( 0x08 )
#define UART_FCR                ( 0x08 )
#define UART_LCR                ( 0x0C )
#define UART_MCR                ( 0x10 )
#define UART_LSR                ( 0x14 )
#define UART_DLL                ( 0x20 )
#define UART_DLH                ( 0x24 )
#define UART_PID1               ( 0x28 )
#define UART_PID2               ( 0x2C )
#define UART_PWREMU_MGMT        ( 0x30 )

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *   VPSS Control                                                           *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define VPSS_BASE               0x01C73400
#define VPSS_PID                *( volatile Uint32* )( VPSS_BASE + 0x000 )
#define VPSS_PCR                *( volatile Uint32* )( VPSS_BASE + 0x004 )
#define VPSS_SDR_REG_EXP        *( volatile Uint32* )( VPSS_BASE + 0x108 )

#define VPSS_CLK_CTRL           *( volatile Uint32* )( 0x01C40044 )

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *   VPBE Control                                                           *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define VPBE_BASE               0x01C72780
#define VPBE_PID                *( volatile Uint32* )( VPBE_BASE + 0x00 )
#define VPBE_PCR                *( volatile Uint32* )( VPBE_BASE + 0x04 )

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *   VPBE On-Screen Display                                                 *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define VPBE_OSD_BASE           0x01C72600
#define VPBE_OSD_MODE           *( volatile Uint32* )( VPBE_OSD_BASE + 0x00 )
#define VPBE_OSD_VIDWINMD       *( volatile Uint32* )( VPBE_OSD_BASE + 0x04 )
#define VPBE_OSD_OSDWIN0MD      *( volatile Uint32* )( VPBE_OSD_BASE + 0x08 )
#define VPBE_OSD_OSDWIN1MD      *( volatile Uint32* )( VPBE_OSD_BASE + 0x0C )
#define VPBE_OSD_RECTCUR        *( volatile Uint32* )( VPBE_OSD_BASE + 0x10 )
#define VPBE_OSD_VIDWIN0OFST    *( volatile Uint32* )( VPBE_OSD_BASE + 0x18 )
#define VPBE_OSD_VIDWIN1OFST    *( volatile Uint32* )( VPBE_OSD_BASE + 0x1C )
#define VPBE_OSD_OSDWIN0OFST    *( volatile Uint32* )( VPBE_OSD_BASE + 0x20 )
#define VPBE_OSD_OSDWIN1OFST    *( volatile Uint32* )( VPBE_OSD_BASE + 0x24 )
#define VPBE_OSD_VIDWIN0ADR     *( volatile Uint32* )( VPBE_OSD_BASE + 0x2C )
#define VPBE_OSD_VIDWIN1ADR     *( volatile Uint32* )( VPBE_OSD_BASE + 0x30 )
#define VPBE_OSD_OSDWIN0ADR     *( volatile Uint32* )( VPBE_OSD_BASE + 0x38 )
#define VPBE_OSD_OSDWIN1ADR     *( volatile Uint32* )( VPBE_OSD_BASE + 0x3C )
#define VPBE_OSD_BASEPX         *( volatile Uint32* )( VPBE_OSD_BASE + 0x40 )
#define VPBE_OSD_BASEPY         *( volatile Uint32* )( VPBE_OSD_BASE + 0x44 )
#define VPBE_OSD_VIDWIN0XP      *( volatile Uint32* )( VPBE_OSD_BASE + 0x48 )
#define VPBE_OSD_VIDWIN0YP      *( volatile Uint32* )( VPBE_OSD_BASE + 0x4C )
#define VPBE_OSD_VIDWIN0XL      *( volatile Uint32* )( VPBE_OSD_BASE + 0x50 )
#define VPBE_OSD_VIDWIN0YL      *( volatile Uint32* )( VPBE_OSD_BASE + 0x54 )
#define VPBE_OSD_VIDWIN1XP      *( volatile Uint32* )( VPBE_OSD_BASE + 0x58 )
#define VPBE_OSD_VIDWIN1YP      *( volatile Uint32* )( VPBE_OSD_BASE + 0x5C )
#define VPBE_OSD_VIDWIN1XL      *( volatile Uint32* )( VPBE_OSD_BASE + 0x60 )
#define VPBE_OSD_VIDWIN1YL      *( volatile Uint32* )( VPBE_OSD_BASE + 0x64 )
#define VPBE_OSD_OSDWIN0XP      *( volatile Uint32* )( VPBE_OSD_BASE + 0x68 )
#define VPBE_OSD_OSDWIN0YP      *( volatile Uint32* )( VPBE_OSD_BASE + 0x6C )
#define VPBE_OSD_OSDWIN0XL      *( volatile Uint32* )( VPBE_OSD_BASE + 0x70 )
#define VPBE_OSD_OSDWIN0YL      *( volatile Uint32* )( VPBE_OSD_BASE + 0x74 )
#define VPBE_OSD_OSDWIN1XP      *( volatile Uint32* )( VPBE_OSD_BASE + 0x78 )
#define VPBE_OSD_OSDWIN1YP      *( volatile Uint32* )( VPBE_OSD_BASE + 0x7C )
#define VPBE_OSD_OSDWIN1XL      *( volatile Uint32* )( VPBE_OSD_BASE + 0x80 )
#define VPBE_OSD_OSDWIN1YL      *( volatile Uint32* )( VPBE_OSD_BASE + 0x84 )
#define VPBE_OSD_CURXP          *( volatile Uint32* )( VPBE_OSD_BASE + 0x88 )
#define VPBE_OSD_CURYP          *( volatile Uint32* )( VPBE_OSD_BASE + 0x8C )
#define VPBE_OSD_CURXL          *( volatile Uint32* )( VPBE_OSD_BASE + 0x90 )
#define VPBE_OSD_CURYL          *( volatile Uint32* )( VPBE_OSD_BASE + 0x94 )
#define VPBE_OSD_W0BMP01        *( volatile Uint32* )( VPBE_OSD_BASE + 0xA0 )
#define VPBE_OSD_W0BMP23        *( volatile Uint32* )( VPBE_OSD_BASE + 0xA4 )
#define VPBE_OSD_W0BMP45        *( volatile Uint32* )( VPBE_OSD_BASE + 0xA8 )
#define VPBE_OSD_W0BMP67        *( volatile Uint32* )( VPBE_OSD_BASE + 0xAC )
#define VPBE_OSD_W0BMP89        *( volatile Uint32* )( VPBE_OSD_BASE + 0xB0 )
#define VPBE_OSD_W0BMPAB        *( volatile Uint32* )( VPBE_OSD_BASE + 0xB4 )
#define VPBE_OSD_W0BMPCD        *( volatile Uint32* )( VPBE_OSD_BASE + 0xB8 )
#define VPBE_OSD_W0BMPEF        *( volatile Uint32* )( VPBE_OSD_BASE + 0xBC )
#define VPBE_OSD_W1BMP01        *( volatile Uint32* )( VPBE_OSD_BASE + 0xC0 )
#define VPBE_OSD_W1BMP23        *( volatile Uint32* )( VPBE_OSD_BASE + 0xC4 )
#define VPBE_OSD_W1BMP45        *( volatile Uint32* )( VPBE_OSD_BASE + 0xC8 )
#define VPBE_OSD_W1BMP67        *( volatile Uint32* )( VPBE_OSD_BASE + 0xCC )
#define VPBE_OSD_W1BMP89        *( volatile Uint32* )( VPBE_OSD_BASE + 0xD0 )
#define VPBE_OSD_W1BMPAB        *( volatile Uint32* )( VPBE_OSD_BASE + 0xD4 )
#define VPBE_OSD_W1BMPCD        *( volatile Uint32* )( VPBE_OSD_BASE + 0xD8 )
#define VPBE_OSD_W1BMPEF        *( volatile Uint32* )( VPBE_OSD_BASE + 0xDC )
#define VPBE_OSD_TI_TEST        *( volatile Uint32* )( VPBE_OSD_BASE + 0xE0 )
#define VPBE_OSD_MISCCTL        *( volatile Uint32* )( VPBE_OSD_BASE + 0xE8 )
#define VPBE_OSD_CLUTRAMYCB     *( volatile Uint32* )( VPBE_OSD_BASE + 0xEC )
#define VPBE_OSD_CLUTRAMCR      *( volatile Uint32* )( VPBE_OSD_BASE + 0xF0 )
#define VPBE_OSD_TRANSPVAL      *( volatile Uint32* )( VPBE_OSD_BASE + 0xF0 )
#define VPBE_OSD_PPVWIN0ADR     *( volatile Uint32* )( VPBE_OSD_BASE + 0xFC )

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *   VPBE Video Encoder                                                     *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define VPBE_VENC_BASE          0x01C72400
#define VPBE_VENC_VMOD          *( volatile Uint32* )( VPBE_VENC_BASE + 0x000 )
#define VPBE_VENC_VIOCTL        *( volatile Uint32* )( VPBE_VENC_BASE + 0x004 )
#define VPBE_VENC_VDPRO         *( volatile Uint32* )( VPBE_VENC_BASE + 0x008 )
#define VPBE_VENC_SYNCCTL       *( volatile Uint32* )( VPBE_VENC_BASE + 0x00C )
#define VPBE_VENC_HSPLS         *( volatile Uint32* )( VPBE_VENC_BASE + 0x010 )
#define VPBE_VENC_VSPLS         *( volatile Uint32* )( VPBE_VENC_BASE + 0x014 )
#define VPBE_VENC_HINT          *( volatile Uint32* )( VPBE_VENC_BASE + 0x018 )
#define VPBE_VENC_HSTART        *( volatile Uint32* )( VPBE_VENC_BASE + 0x01C )
#define VPBE_VENC_HVALID        *( volatile Uint32* )( VPBE_VENC_BASE + 0x020 )
#define VPBE_VENC_VINT          *( volatile Uint32* )( VPBE_VENC_BASE + 0x024 )
#define VPBE_VENC_VSTART        *( volatile Uint32* )( VPBE_VENC_BASE + 0x028 )
#define VPBE_VENC_VVALID        *( volatile Uint32* )( VPBE_VENC_BASE + 0x02C )
#define VPBE_VENC_HSDLY         *( volatile Uint32* )( VPBE_VENC_BASE + 0x030 )
#define VPBE_VENC_VSDLY         *( volatile Uint32* )( VPBE_VENC_BASE + 0x034 )
#define VPBE_VENC_YCCCTL        *( volatile Uint32* )( VPBE_VENC_BASE + 0x038 )
#define VPBE_VENC_RGBCTL        *( volatile Uint32* )( VPBE_VENC_BASE + 0x03C )
#define VPBE_VENC_RGBCLP        *( volatile Uint32* )( VPBE_VENC_BASE + 0x040 )
#define VPBE_VENC_LINECTL       *( volatile Uint32* )( VPBE_VENC_BASE + 0x044 )
#define VPBE_VENC_CULLLINE      *( volatile Uint32* )( VPBE_VENC_BASE + 0x048 )
#define VPBE_VENC_LCDOUT        *( volatile Uint32* )( VPBE_VENC_BASE + 0x04C )
#define VPBE_VENC_BRTS          *( volatile Uint32* )( VPBE_VENC_BASE + 0x050 )
#define VPBE_VENC_BRTW          *( volatile Uint32* )( VPBE_VENC_BASE + 0x054 )
#define VPBE_VENC_ACCTL         *( volatile Uint32* )( VPBE_VENC_BASE + 0x058 )
#define VPBE_VENC_PWMP          *( volatile Uint32* )( VPBE_VENC_BASE + 0x05C )
#define VPBE_VENC_PWMW          *( volatile Uint32* )( VPBE_VENC_BASE + 0x060 )
#define VPBE_VENC_DCLKCTL       *( volatile Uint32* )( VPBE_VENC_BASE + 0x064 )
#define VPBE_VENC_DCLKPTN0      *( volatile Uint32* )( VPBE_VENC_BASE + 0x068 )
#define VPBE_VENC_DCLKPTN1      *( volatile Uint32* )( VPBE_VENC_BASE + 0x06C )
#define VPBE_VENC_DCLKPTN2      *( volatile Uint32* )( VPBE_VENC_BASE + 0x070 )
#define VPBE_VENC_DCLKPTN3      *( volatile Uint32* )( VPBE_VENC_BASE + 0x074 )
#define VPBE_VENC_DCLKPTN0A     *( volatile Uint32* )( VPBE_VENC_BASE + 0x078 )
#define VPBE_VENC_DCLKPTN1A     *( volatile Uint32* )( VPBE_VENC_BASE + 0x07C )
#define VPBE_VENC_DCLKPTN2A     *( volatile Uint32* )( VPBE_VENC_BASE + 0x080 )
#define VPBE_VENC_DCLKPTN3A     *( volatile Uint32* )( VPBE_VENC_BASE + 0x084 )
#define VPBE_VENC_DCLKHS        *( volatile Uint32* )( VPBE_VENC_BASE + 0x088 )
#define VPBE_VENC_DCLKHSA       *( volatile Uint32* )( VPBE_VENC_BASE + 0x08C )
#define VPBE_VENC_DCLKHR        *( volatile Uint32* )( VPBE_VENC_BASE + 0x090 )
#define VPBE_VENC_DCLKVS        *( volatile Uint32* )( VPBE_VENC_BASE + 0x094 )
#define VPBE_VENC_DCLKVR        *( volatile Uint32* )( VPBE_VENC_BASE + 0x098 )
#define VPBE_VENC_CAPCTL        *( volatile Uint32* )( VPBE_VENC_BASE + 0x09C )
#define VPBE_VENC_CAPDO         *( volatile Uint32* )( VPBE_VENC_BASE + 0x0A0 )
#define VPBE_VENC_CAPDE         *( volatile Uint32* )( VPBE_VENC_BASE + 0x0A4 )
#define VPBE_VENC_ATR0          *( volatile Uint32* )( VPBE_VENC_BASE + 0x0A8 )
#define VPBE_VENC_ATR1          *( volatile Uint32* )( VPBE_VENC_BASE + 0x0AC )
#define VPBE_VENC_ATR2          *( volatile Uint32* )( VPBE_VENC_BASE + 0x0B0 )
#define VPBE_VENC_EPSON_LCDCTL  *( volatile Uint32* )( VPBE_VENC_BASE + 0x0B4 )
#define VPBE_VENC_VSTAT         *( volatile Uint32* )( VPBE_VENC_BASE + 0x0B8 )
#define VPBE_VENC_RAMADR        *( volatile Uint32* )( VPBE_VENC_BASE + 0x0BC )
#define VPBE_VENC_RAMPORT       *( volatile Uint32* )( VPBE_VENC_BASE + 0x0C0 )
#define VPBE_VENC_DACTST        *( volatile Uint32* )( VPBE_VENC_BASE + 0x0C4 )
#define VPBE_VENC_YCOLVL        *( volatile Uint32* )( VPBE_VENC_BASE + 0x0C8 )
#define VPBE_VENC_SCPROG        *( volatile Uint32* )( VPBE_VENC_BASE + 0x0CC )
#define VPBE_VENC_CVBS          *( volatile Uint32* )( VPBE_VENC_BASE + 0x0DC )
#define VPBE_VENC_CMPNT         *( volatile Uint32* )( VPBE_VENC_BASE + 0x0E0 )
#define VPBE_VENC_ETMG0         *( volatile Uint32* )( VPBE_VENC_BASE + 0x0E4 )
#define VPBE_VENC_ETMG1         *( volatile Uint32* )( VPBE_VENC_BASE + 0x0E8 )
#define VPBE_VENC_ETMG2         *( volatile Uint32* )( VPBE_VENC_BASE + 0x0EC )
#define VPBE_VENC_ETMG3         *( volatile Uint32* )( VPBE_VENC_BASE + 0x0F0 )
#define VPBE_VENC_DACSEL        *( volatile Uint32* )( VPBE_VENC_BASE + 0x0F4 )
#define VPBE_VENC_ARGBX0        *( volatile Uint32* )( VPBE_VENC_BASE + 0x100 )
#define VPBE_VENC_ARGBX1        *( volatile Uint32* )( VPBE_VENC_BASE + 0x104 )
#define VPBE_VENC_ARGBX2        *( volatile Uint32* )( VPBE_VENC_BASE + 0x108 )
#define VPBE_VENC_ARGBX3        *( volatile Uint32* )( VPBE_VENC_BASE + 0x10C )
#define VPBE_VENC_ARGBX4        *( volatile Uint32* )( VPBE_VENC_BASE + 0x110 )
#define VPBE_VENC_DRGBX0        *( volatile Uint32* )( VPBE_VENC_BASE + 0x114 )
#define VPBE_VENC_DRGBX1        *( volatile Uint32* )( VPBE_VENC_BASE + 0x118 )
#define VPBE_VENC_DRGBX2        *( volatile Uint32* )( VPBE_VENC_BASE + 0x11C )
#define VPBE_VENC_DRGBX3        *( volatile Uint32* )( VPBE_VENC_BASE + 0x120 )
#define VPBE_VENC_DRGBX4        *( volatile Uint32* )( VPBE_VENC_BASE + 0x124 )
#define VPBE_VENC_VSTARTA       *( volatile Uint32* )( VPBE_VENC_BASE + 0x128 )
#define VPBE_VENC_OSDCLK0       *( volatile Uint32* )( VPBE_VENC_BASE + 0x12C )
#define VPBE_VENC_OSDCLK1       *( volatile Uint32* )( VPBE_VENC_BASE + 0x130 )
#define VPBE_VENC_HVLDCL0       *( volatile Uint32* )( VPBE_VENC_BASE + 0x134 )
#define VPBE_VENC_HVLDCL1       *( volatile Uint32* )( VPBE_VENC_BASE + 0x138 )
#define VPBE_VENC_OSDHADV       *( volatile Uint32* )( VPBE_VENC_BASE + 0x13C )
#define VPBE_VENC_SCTEST0       *( volatile Uint32* )( VPBE_VENC_BASE + 0x140 )
#define VPBE_VENC_SCTEST1       *( volatile Uint32* )( VPBE_VENC_BASE + 0x144 )
#define VPBE_VENC_SCTEST2       *( volatile Uint32* )( VPBE_VENC_BASE + 0x148 )
#define VPBE_VENC_VTEST0        *( volatile Uint32* )( VPBE_VENC_BASE + 0x14C )
#define VPBE_VENC_VTEST1        *( volatile Uint32* )( VPBE_VENC_BASE + 0x150 )
#define VPBE_VENC_VTEST2        *( volatile Uint32* )( VPBE_VENC_BASE + 0x154 )


/* ------------------------------------------------------------------------ *
 *                                                                          *
 *   VPFE CCD Controller                                                    *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define VPFE_CCDC_BASE          0x01C70400
#define VPFE_CCDC_PID           *( volatile Uint32* )( VPFE_CCDC_BASE + 0x00 )
#define VPFE_CCDC_PCR           *( volatile Uint32* )( VPFE_CCDC_BASE + 0x04 )
#define VPFE_CCDC_SYN_MODE      *( volatile Uint32* )( VPFE_CCDC_BASE + 0x08 )
#define VPFE_CCDC_HD_VD_WID     *( volatile Uint32* )( VPFE_CCDC_BASE + 0x0c )
#define VPFE_CCDC_PIX_LINES     *( volatile Uint32* )( VPFE_CCDC_BASE + 0x10 )
#define VPFE_CCDC_HORZ_INFO     *( volatile Uint32* )( VPFE_CCDC_BASE + 0x14 )
#define VPFE_CCDC_VERT_START    *( volatile Uint32* )( VPFE_CCDC_BASE + 0x18 )
#define VPFE_CCDC_VERT_LINES    *( volatile Uint32* )( VPFE_CCDC_BASE + 0x1C )
#define VPFE_CCDC_CULLING       *( volatile Uint32* )( VPFE_CCDC_BASE + 0x20 )
#define VPFE_CCDC_HSIZE_OFF     *( volatile Uint32* )( VPFE_CCDC_BASE + 0x24 )
#define VPFE_CCDC_SDOFST        *( volatile Uint32* )( VPFE_CCDC_BASE + 0x28 )
#define VPFE_CCDC_SDR_ADDR      *( volatile Uint32* )( VPFE_CCDC_BASE + 0x2c )
#define VPFE_CCDC_CLAMP         *( volatile Uint32* )( VPFE_CCDC_BASE + 0x30 )
#define VPFE_CCDC_DCSUB         *( volatile Uint32* )( VPFE_CCDC_BASE + 0x34 )
#define VPFE_CCDC_COLPTN        *( volatile Uint32* )( VPFE_CCDC_BASE + 0x38 )
#define VPFE_CCDC_BLKCMP        *( volatile Uint32* )( VPFE_CCDC_BASE + 0x3c )
#define VPFE_CCDC_FPC_ADDR      *( volatile Uint32* )( VPFE_CCDC_BASE + 0x40 )
#define VPFE_CCDC_FPC           *( volatile Uint32* )( VPFE_CCDC_BASE + 0x44 )
#define VPFE_CCDC_VDINT         *( volatile Uint32* )( VPFE_CCDC_BASE + 0x48 )
#define VPFE_CCDC_ALAW          *( volatile Uint32* )( VPFE_CCDC_BASE + 0x4c )
#define VPFE_CCDC_REC656IF      *( volatile Uint32* )( VPFE_CCDC_BASE + 0x50 )
#define VPFE_CCDC_CCDCFG        *( volatile Uint32* )( VPFE_CCDC_BASE + 0x54 )
#define VPFE_CCDC_FMTCFG        *( volatile Uint32* )( VPFE_CCDC_BASE + 0x58 )
#define VPFE_CCDC_FMT_HORZ      *( volatile Uint32* )( VPFE_CCDC_BASE + 0x5c )
#define VPFE_CCDC_FMT_VERT      *( volatile Uint32* )( VPFE_CCDC_BASE + 0x60 )
#define VPFE_CCDC_FMT_ADDR0     *( volatile Uint32* )( VPFE_CCDC_BASE + 0x64 )
#define VPFE_CCDC_FMT_ADDR1     *( volatile Uint32* )( VPFE_CCDC_BASE + 0x68 )
#define VPFE_CCDC_FMT_ADDR2     *( volatile Uint32* )( VPFE_CCDC_BASE + 0x6c )
#define VPFE_CCDC_FMT_ADDR3     *( volatile Uint32* )( VPFE_CCDC_BASE + 0x70 )
#define VPFE_CCDC_FMT_ADDR4     *( volatile Uint32* )( VPFE_CCDC_BASE + 0x74 )
#define VPFE_CCDC_FMT_ADDR5     *( volatile Uint32* )( VPFE_CCDC_BASE + 0x78 )
#define VPFE_CCDC_FMT_ADDR6     *( volatile Uint32* )( VPFE_CCDC_BASE + 0x7c )
#define VPFE_CCDC_FMT_ADDR7     *( volatile Uint32* )( VPFE_CCDC_BASE + 0x80 )
#define VPFE_CCDC_PRGEVEN_0     *( volatile Uint32* )( VPFE_CCDC_BASE + 0x84 )
#define VPFE_CCDC_PRGEVEN_1     *( volatile Uint32* )( VPFE_CCDC_BASE + 0x88 )
#define VPFE_CCDC_PRGODD_0      *( volatile Uint32* )( VPFE_CCDC_BASE + 0x8c )
#define VPFE_CCDC_PRGODD_1      *( volatile Uint32* )( VPFE_CCDC_BASE + 0x90 )
#define VPFE_CCDC_VP_OUT        *( volatile Uint32* )( VPFE_CCDC_BASE + 0x94 )

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *   VPFE Histogram                                                         *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define VPFE_HIST_BASE          0x01C71000
#define VPFE_HIST_PID           *( volatile Uint32* )( VPFE_HIST_BASE + 0x00 )
#define VPFE_HIST_PCR           *( volatile Uint32* )( VPFE_HIST_BASE + 0x04 )
#define VPFE_HIST_HIST_CNT      *( volatile Uint32* )( VPFE_HIST_BASE + 0x08 )
#define VPFE_HIST_WB_GAIN       *( volatile Uint32* )( VPFE_HIST_BASE + 0x0C )
#define VPFE_HIST_R0_HORZ       *( volatile Uint32* )( VPFE_HIST_BASE + 0x10 )
#define VPFE_HIST_R0_VERT       *( volatile Uint32* )( VPFE_HIST_BASE + 0x14 )
#define VPFE_HIST_R1_HORZ       *( volatile Uint32* )( VPFE_HIST_BASE + 0x18 )
#define VPFE_HIST_R1_VERT       *( volatile Uint32* )( VPFE_HIST_BASE + 0x1C )
#define VPFE_HIST_R2_HORZ       *( volatile Uint32* )( VPFE_HIST_BASE + 0x20 )
#define VPFE_HIST_R2_VERT       *( volatile Uint32* )( VPFE_HIST_BASE + 0x24 )
#define VPFE_HIST_R3_HORZ       *( volatile Uint32* )( VPFE_HIST_BASE + 0x28 )
#define VPFE_HIST_R3_VERT       *( volatile Uint32* )( VPFE_HIST_BASE + 0x2C )
#define VPFE_HIST_HIST_ADDR     *( volatile Uint32* )( VPFE_HIST_BASE + 0x30 )
#define VPFE_HIST_HIST_DATA     *( volatile Uint32* )( VPFE_HIST_BASE + 0x34 )
#define VPFE_HIST_RADD          *( volatile Uint32* )( VPFE_HIST_BASE + 0x38 )
#define VPFE_HIST_RADD_OFF      *( volatile Uint32* )( VPFE_HIST_BASE + 0x3C )
#define VPFE_HIST_H_V_INFO      *( volatile Uint32* )( VPFE_HIST_BASE + 0x40 )

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *   VPFE Hardware 3A ( Auto-Focus / WB / Exposure )                        *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define VPFE_H3A_BASE           0x01C71400
#define VPFE_H3A_PID            *( volatile Uint32* )( VPFE_H3A_BASE + 0x00 )
#define VPFE_H3A_PCR            *( volatile Uint32* )( VPFE_H3A_BASE + 0x04 )
#define VPFE_H3A_AFPAX1         *( volatile Uint32* )( VPFE_H3A_BASE + 0x08 )
#define VPFE_H3A_AFPAX2         *( volatile Uint32* )( VPFE_H3A_BASE + 0x0C )
#define VPFE_H3A_AFPAXSTART     *( volatile Uint32* )( VPFE_H3A_BASE + 0x10 )
#define VPFE_H3A_AFIIRSH        *( volatile Uint32* )( VPFE_H3A_BASE + 0x14 )
#define VPFE_H3A_AFBUFST        *( volatile Uint32* )( VPFE_H3A_BASE + 0x18 )
#define VPFE_H3A_AFCOEF010      *( volatile Uint32* )( VPFE_H3A_BASE + 0x1C )
#define VPFE_H3A_AFCOEF032      *( volatile Uint32* )( VPFE_H3A_BASE + 0x20 )
#define VPFE_H3A_AFCOEFF054     *( volatile Uint32* )( VPFE_H3A_BASE + 0x24 )
#define VPFE_H3A_AFCOEFF076     *( volatile Uint32* )( VPFE_H3A_BASE + 0x28 )
#define VPFE_H3A_AFCOEFF098     *( volatile Uint32* )( VPFE_H3A_BASE + 0x2C )
#define VPFE_H3A_AFCOEFF0010    *( volatile Uint32* )( VPFE_H3A_BASE + 0x30 )
#define VPFE_H3A_AFCOEF110      *( volatile Uint32* )( VPFE_H3A_BASE + 0x34 )
#define VPFE_H3A_AFCOEF132      *( volatile Uint32* )( VPFE_H3A_BASE + 0x38 )
#define VPFE_H3A_AFCOEFF154     *( volatile Uint32* )( VPFE_H3A_BASE + 0x3C )
#define VPFE_H3A_AFCOEFF176     *( volatile Uint32* )( VPFE_H3A_BASE + 0x40 )
#define VPFE_H3A_AFCOEFF198     *( volatile Uint32* )( VPFE_H3A_BASE + 0x44 )
#define VPFE_H3A_AFCOEFF1010    *( volatile Uint32* )( VPFE_H3A_BASE + 0x48 )
#define VPFE_H3A_AEWWIN1        *( volatile Uint32* )( VPFE_H3A_BASE + 0x4C )
#define VPFE_H3A_AEWINSTART     *( volatile Uint32* )( VPFE_H3A_BASE + 0x50 )
#define VPFE_H3A_AEWINBLK       *( volatile Uint32* )( VPFE_H3A_BASE + 0x54 )
#define VPFE_H3A_AEWSUBWIN      *( volatile Uint32* )( VPFE_H3A_BASE + 0x58 )
#define VPFE_H3A_AEWBUFST       *( volatile Uint32* )( VPFE_H3A_BASE + 0x5C )

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *   VPFE Preview Engine                                                    *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define VPFE_PREV_BASE          0x01C70800
#define VPFE_PREV_PID           *( volatile Uint32* )( VPFE_PREV_BASE + 0x00 )
#define VPFE_PREV_PCR           *( volatile Uint32* )( VPFE_PREV_BASE + 0x04 )
#define VPFE_PREV_HORZ_INFO     *( volatile Uint32* )( VPFE_PREV_BASE + 0x08 )
#define VPFE_PREV_VERT_INFO     *( volatile Uint32* )( VPFE_PREV_BASE + 0x0C )
#define VPFE_PREV_RSDR_ADDR     *( volatile Uint32* )( VPFE_PREV_BASE + 0x10 )
#define VPFE_PREV_RADR_OFFSET   *( volatile Uint32* )( VPFE_PREV_BASE + 0x14 )
#define VPFE_PREV_DSDR_ADDR     *( volatile Uint32* )( VPFE_PREV_BASE + 0x18 )
#define VPFE_PREV_DRKF_OFFSET   *( volatile Uint32* )( VPFE_PREV_BASE + 0x1C )
#define VPFE_PREV_WSDR_ADDR     *( volatile Uint32* )( VPFE_PREV_BASE + 0x20 )
#define VPFE_PREV_WADD_OFFSET   *( volatile Uint32* )( VPFE_PREV_BASE + 0x24 )
#define VPFE_PREV_AVE           *( volatile Uint32* )( VPFE_PREV_BASE + 0x28 )
#define VPFE_PREV_HMED          *( volatile Uint32* )( VPFE_PREV_BASE + 0x2C )
#define VPFE_PREV_NF            *( volatile Uint32* )( VPFE_PREV_BASE + 0x30 )
#define VPFE_PREV_WB_DGAIN      *( volatile Uint32* )( VPFE_PREV_BASE + 0x34 )
#define VPFE_PREV_WBGAIN        *( volatile Uint32* )( VPFE_PREV_BASE + 0x38 )
#define VPFE_PREV_WBSEL         *( volatile Uint32* )( VPFE_PREV_BASE + 0x3C )
#define VPFE_PREV_CFA           *( volatile Uint32* )( VPFE_PREV_BASE + 0x40 )
#define VPFE_PREV_BLKADJOFF     *( volatile Uint32* )( VPFE_PREV_BASE + 0x44 )
#define VPFE_PREV_RGB_MAT1      *( volatile Uint32* )( VPFE_PREV_BASE + 0x48 )
#define VPFE_PREV_RGB_MAT2      *( volatile Uint32* )( VPFE_PREV_BASE + 0x4C )
#define VPFE_PREV_RGB_MAT3      *( volatile Uint32* )( VPFE_PREV_BASE + 0x50 )
#define VPFE_PREV_RGB_MAT4      *( volatile Uint32* )( VPFE_PREV_BASE + 0x54 )
#define VPFE_PREV_RGB_MAT5      *( volatile Uint32* )( VPFE_PREV_BASE + 0x58 )
#define VPFE_PREV_RGB_OFF1      *( volatile Uint32* )( VPFE_PREV_BASE + 0x5C )
#define VPFE_PREV_RGB_OFF2      *( volatile Uint32* )( VPFE_PREV_BASE + 0x60 )
#define VPFE_PREV_CSC0          *( volatile Uint32* )( VPFE_PREV_BASE + 0x64 )
#define VPFE_PREV_CSC1          *( volatile Uint32* )( VPFE_PREV_BASE + 0x68 )
#define VPFE_PREV_CSC2          *( volatile Uint32* )( VPFE_PREV_BASE + 0x6C )
#define VPFE_PREV_CSC_OFFSET    *( volatile Uint32* )( VPFE_PREV_BASE + 0x70 )
#define VPFE_PREV_CNT_BRT       *( volatile Uint32* )( VPFE_PREV_BASE + 0x74 )
#define VPFE_PREV_CSUP          *( volatile Uint32* )( VPFE_PREV_BASE + 0x78 )
#define VPFE_PREV_SETUP_YC      *( volatile Uint32* )( VPFE_PREV_BASE + 0x7C )
#define VPFE_PREV_SET_TBL_ADDR  *( volatile Uint32* )( VPFE_PREV_BASE + 0x80 )
#define VPFE_PREV_SET_TBL_DATA  *( volatile Uint32* )( VPFE_PREV_BASE + 0x84 )

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *   VPFE Resizer                                                           *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define VPFE_RESZ_BASE          0x01C70C00
#define VPFE_RESZ_PID           *( volatile Uint32* )( VPFE_RESZ_BASE + 0x00 )
#define VPFE_RESZ_PCR           *( volatile Uint32* )( VPFE_RESZ_BASE + 0x04 )
#define VPFE_RESZ_RSZ_CNT       *( volatile Uint32* )( VPFE_RESZ_BASE + 0x08 )
#define VPFE_RESZ_OUT_SIZE      *( volatile Uint32* )( VPFE_RESZ_BASE + 0x0C )
#define VPFE_RESZ_IN_START      *( volatile Uint32* )( VPFE_RESZ_BASE + 0x10 )
#define VPFE_RESZ_IN_SIZE       *( volatile Uint32* )( VPFE_RESZ_BASE + 0x14 )
#define VPFE_RESZ_SDR_INADD     *( volatile Uint32* )( VPFE_RESZ_BASE + 0x18 )
#define VPFE_RESZ_SDR_INOFF     *( volatile Uint32* )( VPFE_RESZ_BASE + 0x1C )
#define VPFE_RESZ_SDR_OUTADD    *( volatile Uint32* )( VPFE_RESZ_BASE + 0x20 )
#define VPFE_RESZ_SDR_OUTOFF    *( volatile Uint32* )( VPFE_RESZ_BASE + 0x24 )
#define VPFE_RESZ_HFILT10       *( volatile Uint32* )( VPFE_RESZ_BASE + 0x28 )
#define VPFE_RESZ_HFILT32       *( volatile Uint32* )( VPFE_RESZ_BASE + 0x2C )
#define VPFE_RESZ_HFILT54       *( volatile Uint32* )( VPFE_RESZ_BASE + 0x30 )
#define VPFE_RESZ_HFILT76       *( volatile Uint32* )( VPFE_RESZ_BASE + 0x34 )
#define VPFE_RESZ_HFILT98       *( volatile Uint32* )( VPFE_RESZ_BASE + 0x38 )
#define VPFE_RESZ_HFILT1110     *( volatile Uint32* )( VPFE_RESZ_BASE + 0x3C )
#define VPFE_RESZ_HFILT1312     *( volatile Uint32* )( VPFE_RESZ_BASE + 0x40 )
#define VPFE_RESZ_HFILT1514     *( volatile Uint32* )( VPFE_RESZ_BASE + 0x44 )
#define VPFE_RESZ_HFILT1716     *( volatile Uint32* )( VPFE_RESZ_BASE + 0x48 )
#define VPFE_RESZ_HFILT1918     *( volatile Uint32* )( VPFE_RESZ_BASE + 0x4C )
#define VPFE_RESZ_HFILT2120     *( volatile Uint32* )( VPFE_RESZ_BASE + 0x50 )
#define VPFE_RESZ_HFILT2322     *( volatile Uint32* )( VPFE_RESZ_BASE + 0x54 )
#define VPFE_RESZ_HFILT2524     *( volatile Uint32* )( VPFE_RESZ_BASE + 0x58 )
#define VPFE_RESZ_HFILT2726     *( volatile Uint32* )( VPFE_RESZ_BASE + 0x5C )
#define VPFE_RESZ_HFILT2928     *( volatile Uint32* )( VPFE_RESZ_BASE + 0x60 )
#define VPFE_RESZ_HFILT3130     *( volatile Uint32* )( VPFE_RESZ_BASE + 0x64 )
#define VPFE_RESZ_VFILT10       *( volatile Uint32* )( VPFE_RESZ_BASE + 0x68 )
#define VPFE_RESZ_VFILT32       *( volatile Uint32* )( VPFE_RESZ_BASE + 0x6C )
#define VPFE_RESZ_VFILT54       *( volatile Uint32* )( VPFE_RESZ_BASE + 0x70 )
#define VPFE_RESZ_VFILT76       *( volatile Uint32* )( VPFE_RESZ_BASE + 0x74 )
#define VPFE_RESZ_VFILT98       *( volatile Uint32* )( VPFE_RESZ_BASE + 0x78 )
#define VPFE_RESZ_VFILT1110     *( volatile Uint32* )( VPFE_RESZ_BASE + 0x7C )
#define VPFE_RESZ_VFILT1312     *( volatile Uint32* )( VPFE_RESZ_BASE + 0x80 )
#define VPFE_RESZ_VFILT1514     *( volatile Uint32* )( VPFE_RESZ_BASE + 0x84 )
#define VPFE_RESZ_VFILT1716     *( volatile Uint32* )( VPFE_RESZ_BASE + 0x88 )
#define VPFE_RESZ_VFILT1918     *( volatile Uint32* )( VPFE_RESZ_BASE + 0x8C )
#define VPFE_RESZ_VFILT2120     *( volatile Uint32* )( VPFE_RESZ_BASE + 0x90 )
#define VPFE_RESZ_VFILT2322     *( volatile Uint32* )( VPFE_RESZ_BASE + 0x94 )
#define VPFE_RESZ_VFILT2524     *( volatile Uint32* )( VPFE_RESZ_BASE + 0x98 )
#define VPFE_RESZ_VFILT2726     *( volatile Uint32* )( VPFE_RESZ_BASE + 0x9C )
#define VPFE_RESZ_VFILT2928     *( volatile Uint32* )( VPFE_RESZ_BASE + 0xA0 )
#define VPFE_RESZ_VFILT3130     *( volatile Uint32* )( VPFE_RESZ_BASE + 0xA4 )
#define VPFE_RESZ_YENH          *( volatile Uint32* )( VPFE_RESZ_BASE + 0xA8 )

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  VLYNQ controller                                                        *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define VLYNQ_BASE              0x01E01000
#define VLYNQ_REMOTE_BASE       0x4C000000
#define VLYNQ_REMOTE_LEN        0x04000000

// Local
#define VLYNQ_REVID             *( volatile Uint32* )( VLYNQ_BASE + 0x00 )
#define VLYNQ_CTRL              *( volatile Uint32* )( VLYNQ_BASE + 0x04 )
#define VLYNQ_STAT              *( volatile Uint32* )( VLYNQ_BASE + 0x08 )
#define VLYNQ_INTPRI            *( volatile Uint32* )( VLYNQ_BASE + 0x0C )
#define VLYNQ_INTSTATCLR        *( volatile Uint32* )( VLYNQ_BASE + 0x10 )
#define VLYNQ_INTPENDSET        *( volatile Uint32* )( VLYNQ_BASE + 0x14 )
#define VLYNQ_INTPTR            *( volatile Uint32* )( VLYNQ_BASE + 0x18 )
#define VLYNQ_XAM               *( volatile Uint32* )( VLYNQ_BASE + 0x1C )
#define VLYNQ_RAMS1             *( volatile Uint32* )( VLYNQ_BASE + 0x20 )
#define VLYNQ_RAMO1             *( volatile Uint32* )( VLYNQ_BASE + 0x24 )
#define VLYNQ_RAMS2             *( volatile Uint32* )( VLYNQ_BASE + 0x28 )
#define VLYNQ_RAMO2             *( volatile Uint32* )( VLYNQ_BASE + 0x2C )
#define VLYNQ_RAMS3             *( volatile Uint32* )( VLYNQ_BASE + 0x30 )
#define VLYNQ_RAMO3             *( volatile Uint32* )( VLYNQ_BASE + 0x34 )
#define VLYNQ_RAMS4             *( volatile Uint32* )( VLYNQ_BASE + 0x38 )
#define VLYNQ_RAMO4             *( volatile Uint32* )( VLYNQ_BASE + 0x3C )
#define VLYNQ_CHIPVER           *( volatile Uint32* )( VLYNQ_BASE + 0x40 )
#define VLYNQ_AUTNGO            *( volatile Uint32* )( VLYNQ_BASE + 0x44 )

// Remote
#define VLYNQ_RREVID            *( volatile Uint32* )( VLYNQ_BASE + 0x80 )
#define VLYNQ_RCTRL             *( volatile Uint32* )( VLYNQ_BASE + 0x84 )
#define VLYNQ_RSTAT             *( volatile Uint32* )( VLYNQ_BASE + 0x88 )
#define VLYNQ_RINTPRI           *( volatile Uint32* )( VLYNQ_BASE + 0x8C )
#define VLYNQ_RINTSTATCLR       *( volatile Uint32* )( VLYNQ_BASE + 0x90 )
#define VLYNQ_RINTPENDSET       *( volatile Uint32* )( VLYNQ_BASE + 0x94 )
#define VLYNQ_RINTPTR           *( volatile Uint32* )( VLYNQ_BASE + 0x98 )
#define VLYNQ_RXAM              *( volatile Uint32* )( VLYNQ_BASE + 0x9C )
#define VLYNQ_RRAMS1            *( volatile Uint32* )( VLYNQ_BASE + 0xA0 )
#define VLYNQ_RRAMO1            *( volatile Uint32* )( VLYNQ_BASE + 0xA4 )
#define VLYNQ_RRAMS2            *( volatile Uint32* )( VLYNQ_BASE + 0xA8 )
#define VLYNQ_RRAMO2            *( volatile Uint32* )( VLYNQ_BASE + 0xAC )
#define VLYNQ_RRAMS3            *( volatile Uint32* )( VLYNQ_BASE + 0xB0 )
#define VLYNQ_RRAMO3            *( volatile Uint32* )( VLYNQ_BASE + 0xB4 )
#define VLYNQ_RRAMS4            *( volatile Uint32* )( VLYNQ_BASE + 0xB8 )
#define VLYNQ_RRAMO4            *( volatile Uint32* )( VLYNQ_BASE + 0xBC )
#define VLYNQ_RCHIPVER          *( volatile Uint32* )( VLYNQ_BASE + 0xC0 )
#define VLYNQ_RAUTNGO           *( volatile Uint32* )( VLYNQ_BASE + 0xC4 )
#define VLYNQ_RMANNGO           *( volatile Uint32* )( VLYNQ_BASE + 0xC8 )
#define VLYNQ_RNGOSTAT          *( volatile Uint32* )( VLYNQ_BASE + 0xCC )
#define VLYNQ_RINTVEC0          *( volatile Uint32* )( VLYNQ_BASE + 0xE0 )
#define VLYNQ_RINTVEC1          *( volatile Uint32* )( VLYNQ_BASE + 0xE4 )
/* ------------------------------------------------------------------------ *
 *  GPIO                                                      *
 * ------------------------------------------------------------------------ */
#define GPIO_SPICS  	*( volatile Uint32* )0x01C6708C
#define GPIO_SPICS_DOWN 0xFFFFFFFD
#define GPIO_SPICS_UP   0xFFFFFFFF
/* ------------------------------------------------------------------------ *
 *  Function Renaming                                                       *
 * ------------------------------------------------------------------------ */
#define EVMDM6437_wait          _wait
#define EVMDM6437_waitusec      _waitusec

#define EVMDM6437_setupPinMux   _setupPinMux
#define EVMDM6437_setPinMux     _setPinMux
#define EVMDM6437_clrPinMux     _clrPinMux

#define EVMDM6437_resetEMIF     _resetEMIF
#define EVMDM6437_setupEMIF     _setupEMIF

/* ------------------------------------------------------------------------ *
 *  Prototypes                                                              *
 * ------------------------------------------------------------------------ */
/* Board Initialization */
Int16 EVMDM6437_init( );

/* Wait Functions */
void _wait( Uint32 delay );
void _waitusec( Uint32 usec );

/* Pin Mux Functions */
Int16 _setupPinMux( );
Int16 _setPinMux( Uint32 pinmux0, Uint32 pinmux1 );
Int16 _clrPinMux( Uint32 pinmux0, Uint32 pinmux1 );

/* EMIF Funtions */
Int16 _resetEMIF( Uint16 chip_select );
Int16 _setupEMIF( Uint16 chip_select, Uint32 timing_settings, Uint16 emif_mode );

#endif
