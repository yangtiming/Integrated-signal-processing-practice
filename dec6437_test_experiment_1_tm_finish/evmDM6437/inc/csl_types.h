/*  ============================================================================
 *   Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005                 
 *                                                                              
 *   Use of this software is controlled by the terms and conditions found in the
 *   license agreement under which this software has been supplied.             
 *   ===========================================================================
 */

#ifndef _CSL_TYPES_H_
#define _CSL_TYPES_H_

#include <tistdtypes.h>

#ifndef TRUE

#define TRUE        ((Bool) 1)
#define FALSE       ((Bool) 0)

#endif

typedef Int16           CSL_Uid;
typedef Int16           CSL_ModuleId;
typedef Uint32          CSL_Xio;

typedef Uint8           CSL_BitMask8;
typedef Uint16          CSL_BitMask16;
typedef Uint32          CSL_BitMask32;

typedef volatile Uint8  CSL_Reg8;
typedef volatile Uint16 CSL_Reg16;
typedef volatile Uint32 CSL_Reg32;

typedef Int16           CSL_Status;
typedef Int16           CSL_InstNum;
typedef Int16           CSL_ChaNum;

typedef enum {
  CSL_EXCLUSIVE = 0,
  CSL_SHARED    = 1
} CSL_OpenMode;

typedef enum {
  CSL_FAIL      = 0,
  CSL_PASS      = 1
} CSL_Test;

#ifndef NULL
#define NULL            ((void*)0)
#endif

#endif /* _CSL_TYPES_H_ */

