/*
 *  Copyright 2006 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  Definitions & Register
 *
 */
#include <tistdtypes.h>
#ifndef SPI_FLASH_
#define SPI_FLASH_
/********************************************/
#define WR_ENBALE 		0x06
#define RE_ARRAY	    0x0b
#define RE_ARRAY_Low 	0x03
#define ERASE_4k 		0x20
#define ERASE_32k 		0x52
#define ERASE_64k 		0xd8
#define ERASE_CHIP1 	0x60
#define ERASE_CHIP2 	0xc7
#define WRITE           0x02
#define READ_ID         0x9f
#define READ_REG        0x05
#define WRITE_REG       0x01
#define SEC_PROREG      0x3c
/********************************************/
void mcbsp_init();

void gpio_init();

void Spiwr_byte (char nWrData);

char Spire_byte ();

void Spiwrite(char nWrOp,Uint32 nWrAddr,Uint32 nWrlength, char *ndata);   

void Spiread (char nReOp,Uint32 nReAddr,Uint32 nRelength, char *ndata);

void SpireadArry (char nReOp,Uint32 nReAddr,Uint32 nRelength, char *ndata);

void SpiWritByte (Uint32 nWrAddr, char *ndata);

void SpiWritPage(Uint32 nWrAddr,char *ndata);

void SpiErase4K (Uint32 nWrAddr);

void SpiErase32K (Uint32 nWrAddr);

void SpiErase64K(Uint32 nWrAddr);

void SpiEraseChip();

void SpiWrEnable();

char SpiRe_ReREG();

void SpiWr_ReREG(char ndata);

char SpiRe_WrREG();

Uint8 SpireadID();

void SpiReady();

char SpiRe_SecPro(Uint32 nWrAddr);

void SpiWritUint32(Uint32 nWrAddr, Uint32 *ndata) ;
#endif

