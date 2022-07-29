/**************************************************************************
	filename:	FLASH_PRG.h
	date:		2007/03/15
**************************************************************************/
/*	end of table	*/
#define	TABLE_END		0

/*  function define  */
void WritePage(Uint32 src_addr, Uint32 dst_addr, Uint32 size);
unsigned int TO32(unsigned short datalow, unsigned short datahigh);

/*  useful struct  */
typedef struct _FILE_HEADER
{
	unsigned short fileVersionID;   // Version ID
	unsigned short fileSecNum;		// Number of section headers
	unsigned int   fileTime;		// Time and date stamp
	unsigned int   filePointer;		// File pointer
	unsigned int   fileEntry;		// Number of entries in the symbol table
	unsigned short fileByte;		// Number of bytes in the optional header
	unsigned short fileFlag;		// Flags
	unsigned short fileTargetID;	// Target ID
}   FILE_HEADER, * PFILE_HEADER;

typedef struct _OPTIONAL_FILE_HEADER
{
	unsigned short optionMagic;   	// Magic number
	unsigned short optionVersion;	// Version stamp
	unsigned int   optionExecut;	// Size of executable code
	unsigned int   optionInit;		// Size of initialized data
	unsigned int   optionUninit;	// Size of uninitialized data
	unsigned short EntryPointLo;	// Entry point low bytes
	unsigned short EntryPointHi;	// Entry point high bytes
	unsigned int   optionBeginCode;	// Beginning address of executable code
	unsigned int   optionBeginData;	// Beginning address of executable data
}   OPTIONAL_FILE_HEADER, * POPTIONAL_FILE_HEADER;

typedef struct _SECTION_HEADER
{
	unsigned short secCharacterLo1;	// Section name low bytes
	unsigned short secCharacterLo2; // Section name high bytes
	unsigned short secCharacterHi1;	// Section name low bytes
	unsigned short secCharacterHi2; // Section name high bytes	
	unsigned short secPhyAddrLo;	// Section's physical address low bytes
	unsigned short secPhyAddrHi;	// Section's physical address high bytes
	unsigned int   secVirAddr;		// Section's virtual address
	unsigned short secSizeLo;		// Section size low bytes
	unsigned short secSizeHi;		// Section size high bytes
	unsigned short secRawLo;		// File pointer to raw data low bytes
	unsigned short secRawHi;		// File pointer to raw data high bytes
	unsigned int   secPointerRelo;	// File pointer to relocation entries
	unsigned int   secReserved1;	// Reserved
	unsigned int   secNumRelo;		// Number of relocation entries
	unsigned int   secReserved2;	// Reserved
	unsigned short secFlagLo;		// Flags low bytes
	unsigned short secFlagHi;		// Flags high bytes
	unsigned short secReserved3;	// Reserved
	unsigned short secMemory;		// Memory page number
}   SECTION_HEADER, * PSECTION_HEADER;
