/*  ============================================================================
 *   Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005
 *
 *   Use of this software is controlled by the terms and conditions found in the
 *   license agreement under which this software has been supplied.
 *   ===========================================================================
 */

/** @file csl_cache.h
 *
 *  @brief    Header file for Cache System Service APIs
 *
 *  Description
 *      The API declarations, enumerations, structure definitions of the
 *      necessary functionality to configure and control (if avalible) L2,
 *      L1D, and L1P Cache.
 *
 *  Date     23th March 2004
 *  Author   Jamon Bowen created
 *
 *  Date     21st June 2004
 *  Author   Ruchika Kharwar
 */

/** @mainpage CACHE
 *
 *  @section Introduction
 *
 *  @subsection xxx Purpose and Scope
 *  The purpose of this document is to detail the Cache APIs.
 *
 *  @subsection aaa Terms and Abbreviations
 *    -# CSL:  Chip Support Library
 *    -# API:  Application Programmer Interface
 *
 *  @subsection References
 *     -# Cache L2
 *     -# Cache L1D
 *     -# Cache L1P
 *
 *  @subsection Assumptions
 *        None worthy of note
 */

#ifndef _CSL_CACHE_H_
#define _CSL_CACHE_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
@defgroup CSLSYS_CACHE_API CACHE
*/

/**
@defgroup CSLSYS_CACHE_SYMBOL  Cache defined Symbols/Macros
@ingroup CSLSYS_CACHE_API
*/

/**
@defgroup CSLSYS_CACHE_ENUM  Cache Enumerated Data Types
@ingroup CSLSYS_CACHE_API
*/

/**
@defgroup CSLSYS_CACHE_FUNCTION  Cache Functions
@ingroup CSLSYS_CACHE_API
*/

/**
@defgroup CSLSYS_CACHE_L1FUNCTION  Cache L1 Functions
@ingroup CSLSYS_CACHE_FUNCTION
*/

/**
@defgroup CSLSYS_CACHE_L2FUNCTION  Cache L2 Functions
@ingroup CSLSYS_CACHE_FUNCTION
*/

#include <csl.h>
#include <cslr_cache.h>
#include <cslsys_soc64plus.h>

/** @addtogroup CSLSYS_CACHE_SYMBOL
* @{ */
#define CACHE_L2_LINESIZE     128
/**< L2 Line Size */
#define CACHE_L1D_LINESIZE    64
/**< L1D Line Size */
#define CACHE_L1P_LINESIZE    32
/**< L1P Line Size */

/** macro for calculate the round to line size */
#define CACHE_ROUND_TO_LINESIZE(CACHE,ELCNT,ELSIZE)          \
    ((CACHE_##CACHE##_LINESIZE *                             \
    ((ELCNT)*(ELSIZE)/CACHE_##CACHE##_LINESIZE) + 1) /       \
    (ELSIZE))
/**
@}
*/

/*****************************************************************************\
* global macro declarations
\*****************************************************************************/

/** @addtogroup CSLSYS_CACHE_ENUM
* @{ */

/** @brief Enumeration for Emif ranges
 *
 *  This is used for setting up the cacheability of the EMIF ranges.
 */
typedef enum {

    CACHE_EMIFB_CE00 =  96,
    CACHE_EMIFB_CE01 =  97,
    CACHE_EMIFB_CE02 =  98,
    CACHE_EMIFB_CE03 =  99,
    CACHE_EMIFB_CE10 =  100,
    CACHE_EMIFB_CE11 =  101,
    CACHE_EMIFB_CE12 =  102,
    CACHE_EMIFB_CE13 =  103,
    CACHE_EMIFB_CE20 =  104,
    CACHE_EMIFB_CE21 =  105,
    CACHE_EMIFB_CE22 =  106,
    CACHE_EMIFB_CE23 =  107,
    CACHE_EMIFB_CE30 =  108,
    CACHE_EMIFB_CE31 =  109,
    CACHE_EMIFB_CE32 =  110,
    CACHE_EMIFB_CE33 =  111,

    CACHE_EMIFA_CE00 =   128,
    CACHE_EMIFA_CE01 =   129,
    CACHE_EMIFA_CE02 =   130,
    CACHE_EMIFA_CE03 =   131,
    CACHE_EMIFA_CE04 =   132,
    CACHE_EMIFA_CE05 =   133,
    CACHE_EMIFA_CE06 =   134,
    CACHE_EMIFA_CE07 =   135,
    CACHE_EMIFA_CE08 =   136,
    CACHE_EMIFA_CE09 =   137,
    CACHE_EMIFA_CE010 =  138,
    CACHE_EMIFA_CE011 =  139,
    CACHE_EMIFA_CE012 =  140,
    CACHE_EMIFA_CE013 =  141,
    CACHE_EMIFA_CE014 =  142,
    CACHE_EMIFA_CE015 =  143,

    CACHE_EMIFA_CE10  =  144,
    CACHE_EMIFA_CE11  =  145,
    CACHE_EMIFA_CE12  =  146,
    CACHE_EMIFA_CE13  =  147,
    CACHE_EMIFA_CE14  =  148,
    CACHE_EMIFA_CE15  =  149,
    CACHE_EMIFA_CE16  =  150,
    CACHE_EMIFA_CE17  =  151,
    CACHE_EMIFA_CE18  =  152,
    CACHE_EMIFA_CE19  =  153,
    CACHE_EMIFA_CE110 =  154,
    CACHE_EMIFA_CE111 =  155,
    CACHE_EMIFA_CE112 =  156,
    CACHE_EMIFA_CE113 =  157,
    CACHE_EMIFA_CE114 =  158,
    CACHE_EMIFA_CE115 =  159,

    CACHE_EMIFA_CE20  =  160,
    CACHE_EMIFA_CE21  =  161,
    CACHE_EMIFA_CE22  =  162,
    CACHE_EMIFA_CE23  =  163,
    CACHE_EMIFA_CE24  =  164,
    CACHE_EMIFA_CE25  =  165,
    CACHE_EMIFA_CE26  =  166,
    CACHE_EMIFA_CE27  =  167,
    CACHE_EMIFA_CE28  =  168,
    CACHE_EMIFA_CE29  =  169,
    CACHE_EMIFA_CE210 =  170,
    CACHE_EMIFA_CE211 =  171,
    CACHE_EMIFA_CE212 =  172,
    CACHE_EMIFA_CE213 =  173,
    CACHE_EMIFA_CE214 =  174,
    CACHE_EMIFA_CE215 =  175,


    CACHE_EMIFA_CE30  =  176,
    CACHE_EMIFA_CE31  =  177,
    CACHE_EMIFA_CE32  =  178,
    CACHE_EMIFA_CE33  =  179,
    CACHE_EMIFA_CE34  =  180,
    CACHE_EMIFA_CE35  =  181,
    CACHE_EMIFA_CE36  =  182,
    CACHE_EMIFA_CE37  =  183,
    CACHE_EMIFA_CE38  =  184,
    CACHE_EMIFA_CE39  =  185,
    CACHE_EMIFA_CE310 =  186,
    CACHE_EMIFA_CE311 =  187,
    CACHE_EMIFA_CE312 =  188,
    CACHE_EMIFA_CE313 =  189,
    CACHE_EMIFA_CE314 =  190,
    CACHE_EMIFA_CE315 =  191

} CE_MAR;


/** @brief Enumeration for Cache wait flags
 *
 *  This is used for specifying whether the cache operations should block till
 *  the desired operation is complete.
 */
typedef enum {
    CACHE_NOWAIT       = 0, /**< No blocking, the call exits after
                                 programmation of the control registers */
    CACHE_WAITINTERNAL = 1, /**< Blocking Call,the call exits after the
                                 relevant  cache status registers indicate
                                 completion */
    CACHE_WAIT         = 2  /**< Blocking Call, the call waits not only till
                                 the cache status registers indicate completion,
                                 but also till a write read is issued to the
                                 EMIF registers (if required) */
} CACHE_Wait;

/** @brief Enumeration for Cache Freeze flags
*
*   This is used for reporting back the current state of the L1.
*/
typedef enum {
    CACHE_L1D_NORMAL = 0,   /**< L1D is in Normal State      */
    CACHE_L1D_FREEZE = 1,   /**< L1D is in Freeze State      */
    CACHE_L1P_NORMAL = 3,   /**< L1P is in Normal State      */
    CACHE_L1P_FREEZE = 4,   /**< L1P is in Freeze State      */
    CACHE_L1_NORMAL  = 5,   /**< L1D, L1P is in Normal State */
    CACHE_L1_FREEZE  = 6    /**< L1D, L1P is in Freeze State */
} CACHE_L1_Freeze;

/** @brief Enumeration for L1 (P or D) Sizes */
typedef enum {
    CACHE_L1_0KCACHE  = 0,  /**< No Cache   */
    CACHE_L1_4KCACHE  = 1,  /**< 4KB Cache  */
    CACHE_L1_8KCACHE  = 2,  /**< 8KB Cache  */
    CACHE_L1_16KCACHE = 3,  /**< 16KB Cache */
    CACHE_L1_32KCACHE = 4   /**< 32KB Cache */
} CACHE_L1Size;

/** @brief Enumeration for L2 Sizes */
typedef enum {
    CACHE_0KCACHE   = CSL_CACHE_L2CFG_MODE_0K,   /**< No Cache    */
    CACHE_32KCACHE  = CSL_CACHE_L2CFG_MODE_32K,  /**< 32KB Cache  */
    CACHE_64KCACHE  = CSL_CACHE_L2CFG_MODE_64K,  /**< 64KB Cache  */
    CACHE_128KCACHE = CSL_CACHE_L2CFG_MODE_128K, /**< 128KB Cache */
    CACHE_256KCACHE = CSL_CACHE_L2CFG_MODE_256K  /**< 256KB Cache */
} CACHE_L2Size;

/** @brief Enumeration for L2 Modes */
typedef enum {
    CACHE_L2_NORMAL = CSL_CACHE_L2CFG_L2CC_ENABLED, /**< Enabled/Normal Mode */
    CACHE_L2_FREEZE = CSL_CACHE_L2CFG_L2CC_FREEZE,  /**< Freeze Mode         */
    CACHE_L2_BYPASS = CSL_CACHE_L2CFG_L2CC_BYPASS   /**< Bypass Mode         */
} CACHE_L2Mode;

/**
@}
*/

/** @addtogroup CSLSYS_CACHE_FUNCTION
@{
*/
/** ============================================================================
 *   @n@b CACHE_enableCaching
 *
 *   @b Description
 *   @n Enables caching for the specified memory range.
 *
 *   @b Arguments
 *   @verbatim
            mar        EMIF range
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  Caching for the specified memory range is enabled
 *
 *   @b Modifies
 *   @n MAR register
 *
 *   @b Example
 *   @verbatim
        ...
        CACHE_enableCaching (CACHE_EMIFB_CE00);
        ...
     @endverbatim
 *  ============================================================================
 */
void CACHE_enableCaching (
    CE_MAR                 mar
);

/** ============================================================================
 *   @n@b CACHE_wait
 *
 *   @b Description
 *   @n Waits for previously issued block operations to complete. This does a
 *      partial wait. i.e waits for the cache status register to read back as
 *      done. (if required)
 *
 *   @b  Arguments
 *   @n  None
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Modifies
 *   @n None
 *
 *   @b Example
 *   @verbatim
        ...
        CACHE_wait();
        ...
     @endverbatim
 *  ============================================================================
 */
void CACHE_wait (
    void
);

/** ============================================================================
 *   @n@b CACHE_waitInternal
 *
 *   @b Description
 *   @n Waits for previously issued block operations to complete. This does a
 *      partial wait. i.e waits for the cache status register to read back as
 *      done. (if required)
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Modifies
 *   @n None
 *
 *   @b Example
 *   @verbatim
        ...
        CACHE_waitInternal();
        ...
     @endverbatim
 *  ============================================================================
 */
void CACHE_waitInternal (
    void
);

/**
@}
*/

/** @addtogroup CSLSYS_CACHE_L1FUNCTION
@{
*/

/** ============================================================================
 *   @n@b CACHE_freezeL1
 *
 *   @b Description
 *   @n Freezes the L1P and L1D.
 *   @n As per the specification,
 *   @n a. The new freeze state is programmed in L1DCC, L1PCC.
 *   @n b. The old state is read from the L1DCC, L1PCC from the POPER field.
 *   @n    This latter read accomplishes 2 things, viz. Ensuring the new state
 *         is programmed as well as reading the old programmed value.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *   @n  Old Freeze State (CACHE_L1_Freeze)
 *
 *   @b Example
 *   @verbatim
        ...
        CACHE_L1_Freeze oldFreezeState ;

        oldFreezeState = CACHE_freezeL1();
        ...
     @endverbatim
 *  ============================================================================
 */
CACHE_L1_Freeze CACHE_freezeL1 (
    void
);

/** ============================================================================
 *   @n@b CACHE_unfreezeL1
 *
 *   @b Description
 *   @n Unfreezes the L1P and L1D.
 *   @n As per the specification,
 *   @n a. The new unfreeze state is programmed in L1DCC, L1PCC.
 *   @n b. The old state is read from the L1DCC, L1PCC from the POPER field.
 *   @n    This latter read accomplishes 2 things, viz. Ensuring the new state
 *         is programmed as well as reading the old programmed value.
 *
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *   @n  Old Freeze State (CACHE_L1_Freeze)
 *
 *   @b Example
 *   @verbatim
        ...
        CACHE_L1_Freeze oldFreezeState ;

        oldFreezeState = CACHE_unfreezeL1();
        ...
     @endverbatim
 *  ============================================================================
 */
CACHE_L1_Freeze CACHE_unfreezeL1 (
    void
);

/*----------------------------------------------------------------------------*\
    L1P
\*----------------------------------------------------------------------------*/

/** ============================================================================
 *   @n@b CACHE_setL1pSize
 *
 *   @b Description
 *   @n Sets the L1P size.
 *   @n As per the specification,
 *   @n a. The new size is programmed in L1PCFG.
 *   @n b. L1PCFG is read back to ensure it is set.
 *
 *   @b Arguments
 *   @verbatim
              newSize      New size to be programmed
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  Old Size set for L1P (CACHE_L1Size)
 *
 *   @b Example
 *   @verbatim
        ...
        CACHE_L1Size oldSize ;

        oldSize = CACHE_setL1pSize(CACHE_L1_32KCACHE);
        ...
     @endverbatim
 *  ============================================================================
 */
CACHE_L1Size CACHE_setL1pSize (
    CACHE_L1Size                newSize
);

/** ============================================================================
 *   @n@b CACHE_freezeL1p
 *
 *   @b Description
 *   @n Freezes L1P.
 *   @n As per the specification,
 *   @n a. The new freeze state is programmed in L1PCC.
 *   @n b. The old state is read from the L1PCC from the POPER field.
 *   @n    This latter read accomplishes 2 things, viz. Ensuring the new state
 *         is programmed as well as reading the old programmed value.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *   @n  Old Freeze State (CACHE_L1_Freeze)
 *
 *   @b Example
 *   @verbatim
        ...
        CACHE_L1_Freeze oldFreezeState ;

        oldFreezeState = CACHE_freezeL1p();
        ...
     @endverbatim
 *  ============================================================================
 */
CACHE_L1_Freeze CACHE_freezeL1p (
    void
);

/** ============================================================================
 *   @n@b CACHE_unfreezeL1p
 *
 *   @b Description
 *   @n Unfreezes L1P.
 *   @n As per the specification,
 *   @n a. The normal state is programmed in L1PCC
 *   @n b. The old state is read from the L1PCC from the POPER field.
 *   @n    This latter read accomplishes 2 things, viz. Ensuring the new state
 *         is programmed as well as reading the old programmed value.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *   @n  Old Freeze State (CACHE_L1_Freeze)
 *
 *   @b Example
 *   @verbatim
        ...
        CACHE_L1_Freeze oldFreezeState ;

        oldFreezeState = CACHE_unfreezeL1p();
        ...
     @endverbatim
 *  ============================================================================
 */
CACHE_L1_Freeze CACHE_unfreezeL1p (
    void
);

/* Block Operations */

/** ============================================================================
 *   @n@b CACHE_invL1p
 *
 *   @b Description
 *   @n Invalidates range specified in L1P.
 *   @n As per the specification,
 *   @n a. The start of the range that needs to be invalidated is written
 *         into L1PIBAR
 *   @n b. The byte count is programmed in L1PIWC.
 *
 *   @b Arguments
 *   @verbatim
            blockPtr      Start address of range to be invalidated

            byteCnt       Number of bytes to be invalidated

            wait          Whether the call is blocking (and the extent of wait)
                          till the issue operation is completed.
                          Whether the function must exit on completion/or not.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   @b Example
 *   @verbatim
        ...
        CACHE_invL1p ((Uint32*)(0x1000), 200, CACHE_NOWAIT);
        ...
     @endverbatim
 *  ============================================================================
 */
void CACHE_invL1p (
    void            *blockPtr,
    Uint32           byteCnt,
    CACHE_Wait       wait
);

/* Global Operations */

/** ============================================================================
 *   @n@b CACHE_invAllL1p
 *
 *   @b Description
 *   @n Invalidates all of L1P.
 *   @n As per the specification,
 *   @n a. The L1PINV is programmed.
 *
 *   @b Arguments
 *   @verbatim
            wait          Whether the call is blocking (and the extent of wait)
                          till the issue operation is completed.
                          Whether the function must exit on completion/or not.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   @b Example
 *   @verbatim
        ...
        CACHE_invAllL1p (CACHE_NOWAIT);
        ...
     @endverbatim
 *  ============================================================================
 */
void CACHE_invAllL1p (
    CACHE_Wait         wait
);

/*----------------------------------------------------------------------------*\
    L1D
\*----------------------------------------------------------------------------*/

/** ============================================================================
 *   @n@b CACHE_setL1dSize
 *
 *   @b Description
 *   @n Sets the L1D size.
 *   @n As per the specification,
 *   @n a. The new size is programmed in L1DCFG
 *   @n b. L1DCFG is read back to ensure it is set.
 *
 *   @b Arguments
 *   @verbatim
              newSize      New size to be programmed
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  Old Size set for L1D (CACHE_L1Size)
 *
 *   @b Example
 *   @verbatim
        ...
        CACHE_L1Size oldSize ;

        oldSize = CACHE_setL1dSize(CACHE_L1_32KCACHE);
        ...
     @endverbatim
 *  ============================================================================
 */
CACHE_L1Size CACHE_setL1dSize (
    CACHE_L1Size                newSize
);

/** ============================================================================
 *   @n@b CACHE_freezeL1d
 *
 *   @b Description
 *   @n Freezes L1D.
 *   @n As per the specification,
 *   @n a. The new freeze state is programmed in L1DCC.
 *   @n b. The old state is read from the L1DCC from the POPER field.
 *   @n    This latter read accomplishes 2 things, viz. Ensuring the new state
 *         is programmed as well as reading the old programmed value.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *   @n  Old Freeze State (CACHE_L1_Freeze)
 *
 *   @b Example
 *   @verbatim
        ...
        CACHE_L1_Freeze oldFreezeState ;

        oldFreezeState = CACHE_freezeL1d();
        ...
     @endverbatim
 *  ============================================================================
 */
CACHE_L1_Freeze CACHE_freezeL1d (
    void
);

/** ============================================================================
 *   @n@b CACHE_unfreezeL1d
 *
 *   @b Description
 *   @n Unfreezes L1D.
 *   @n As per the specification,
 *   @n a. The normal state is programmed in L1DCC
 *   @n b. The old state is read from the L1DCC from the POPER field.
 *   @n    This latter read accomplishes 2 things, viz. Ensuring the new state
 *         is programmed as well as reading the old programmed value.
 *
 *   @b Arguments
 *   @n None
 *
 *   <b> Return Value </b>
 *   @n  Old Freeze State (CACHE_L1_Freeze)
 *
 *   @b Example
 *   @verbatim
        ...
        CACHE_L1_Freeze oldFreezeState ;

        oldFreezeState = CACHE_unfreezeL1d();
        ...
     @endverbatim
 *  ============================================================================
 */
CACHE_L1_Freeze CACHE_unfreezeL1d(
    void
);

/* Block Operations */

/** ============================================================================
 *   @n@b CACHE_wbL1d
 *
 *   @b Description
 *   @n Writes back range specified in L1D.
 *   @n As per the specification,
 *   @n a. The start of the range that needs to be written back is programmed
 *         into L1DWBAR.
 *   @n b. The byte count is programmed in L1DWWC.
 *
 *   @b Arguments
 *   @verbatim
            blockPtr      Start address of range to be written back

            byteCnt       Number of bytes to be written back

            wait          Whether the call is blocking (and the extent of wait)
                          till the issue operation is completed or not.
                          Whether the function must exit on completion/or not.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   @b Example
 *   @verbatim
        ...
        CACHE_wbL1d((Uint32*)(0x1000), 200, CACHE_NOWAIT);
        ...
     @endverbatim
 *  ============================================================================
 */
void CACHE_wbL1d (
    void           *blockPtr,
    Uint32          byteCnt,
    CACHE_Wait      wait
);

/** ============================================================================
 *   @n@b CACHE_invL1d
 *
 *   @b Description
 *   @n Invalidates range specified in L1D.
 *   @n As per the specification,
 *   @n a. The start of the range that needs to be invalidated is written
 *         into L1DIBAR.
 *   @n b. The byte count is programmed in L1DIWC.
 *
 *   @b Arguments
 *   @verbatim
            blockPtr      Start address of range to be invalidated

            byteCnt       Number of bytes to be invalidated

            wait          Whether the call is blocking (and the extent of wait)
                          till the issue operation is completed.
                          Whether the function must exit on completion/or not.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   @b Example
 *   @verbatim
        ...
        CACHE_invL1d ((Uint32*)(0x1000), 200, CACHE_NOWAIT);
        ...
     @endverbatim
 *  ============================================================================
 */
void CACHE_invL1d (
    void            *blockPtr,
    Uint32           byteCnt,
    CACHE_Wait       wait
);

/** ============================================================================
 *   @n@b CACHE_wbInvL1d
 *
 *   @b Description
 *   @n Writeback invalidates range specified in L1D.
 *   @n As per the specification,
 *   @n a. The start of the range that needs to be writeback invalidated is
 *         programmed into L1DWIBAR.
 *   @n b. The byte count is programmed in L1DWIWC.
 *
 *   @b Arguments
 *   @verbatim
            blockPtr      Start address of range to be written back invalidated

            byteCnt       Number of bytes to be written back invalidated

            wait          Whether the call is blocking (and the extent of wait)
                          till the issue operation is completed.
                          Whether the function must exit on completion/or not.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   @b Example
 *   @verbatim
        ...
        CACHE_wbInvL1d ((Uint32*)(0x1000),200,CACHE_NOWAIT);
        ...
     @endverbatim
 *  ============================================================================
 */
void CACHE_wbInvL1d (
    void              *blockPtr,
    Uint32             byteCnt,
    CACHE_Wait         wait
);

/* Global Operations */

/** ============================================================================
 *   @n@b CACHE_wbAllL1d
 *
 *   @b Description
 *   @n Writeback All of L1D.
 *   @n As per the specification,
 *   @n a. The L1DWB is programmed.
 *
 *   @b Arguments
 *   @verbatim
            wait          Whether the call is blocking (and the extent of wait)
                          till the issue operation is completed.
                          Whether the function must exit on completion/or not.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   @b Example
 *   @verbatim
        ...
        CACHE_wbAllL1d (CACHE_NOWAIT);
        ...
     @endverbatim
 *  ============================================================================
 */
void CACHE_wbAllL1d (
    CACHE_Wait        wait
);

/** ============================================================================
 *   @n@b CACHE_invAllL1d
 *
 *   @b Description
 *   @n Invalidates All of L1D.
 *   @n As per the specification,
 *   @n a. The L1DINV is programmed.
 *
 *   @b Arguments
 *   @verbatim
            wait          Whether the call is blocking (and the extent of wait)
                          till the issue operation is completed.
                          Whether the function must exit on completion/or not.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   @b Example
 *   @verbatim
        ...
        CACHE_invAllL1d (CACHE_NOWAIT);
        ...
     @endverbatim
 *  ============================================================================
 */
void CACHE_invAllL1d (
    CACHE_Wait         wait
);

/** ============================================================================
 *   @n@b CACHE_wbInvAllL1d
 *
 *   @b Description
 *   @n Writeback invalidates All of L1D.
 *   @n As per the specification,
 *   @n a. The L1DWBINV is programmed.
 *
 *   @b Arguments
 *   @verbatim
            wait          Whether the call is blocking (and the extent of wait)
                          till the issue operation is completed.
                          Whether the function must exit on completion/or not.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   @b Example
 *   @verbatim
        ...
        CACHE_wbInvAllL1d (CACHE_NOWAIT);
        ...
     @endverbatim
 *  ============================================================================
 */
void CACHE_wbInvAllL1d(
    CACHE_Wait wait  /**< Whether the call is blocking (and the extent of wait)
                          till the issue operation is completed or not*/
);

/**
@}
*/

/*----------------------------------------------------------------------------*\
    L2
\*----------------------------------------------------------------------------*/

/** @addtogroup CSLSYS_CACHE_L2FUNCTION
@{
*/

/** ============================================================================
 *   @n@b CACHE_setL2Size
 *
 *   @b Description
 *   @n Sets the L2 size.
 *   @n As per the specification,
 *   @n a. The old size is read from the L2CFG.
 *   @n b. The new size is programmed in L2CFG.
 *   @n c. L2CFG is read back to ensure it is set.
 *
 *   @b Arguments
 *   @verbatim
              newSize      New memory size to be programmed
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  Old Size set for L2 (CACHE_L2Size)
 *
 *   @b Example
 *   @verbatim
        ...
        CACHE_L2Size oldSize ;

        oldSize = CACHE_setL2Size(CACHE_L2_32KCACHE);
        ...
     @endverbatim
 *  ============================================================================
 */
CACHE_L2Size CACHE_setL2Size (
    CACHE_L2Size               newSize
);

/** ============================================================================
 *   @n@b CACHE_setL2Mode
 *
 *   @b Description
 *   @n Sets the L2 mode.
 *   @n As per the specification,
 *   @n a. The old mode is read from the L2CFG.
 *   @n b. The new mode is programmed in L2CFG.
 *   @n c. L2CFG is read back to ensure it is set.
 *
 *   @b Arguments
 *   @verbatim
              newMode      New mode to be programmed
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  Old Mode set for L2 (CACHE_L2Mode)
 *
 *   @b Example
 *   @verbatim
        ...
        CACHE_L2Mode oldMode;

        oldMode = CACHE_setL2Mode(CACHE_L2_NORMAL);
        ...
     @endverbatim
 *  ============================================================================
 */
CACHE_L2Mode CACHE_setL2Mode (
    CACHE_L2Mode               newMode
);

/* Block Operations */

/** ============================================================================
 *   @n@b CACHE_wbL2
 *
 *   @b Description
 *   @n Writes back range specified in L2.
 *   @n As per the specification,
 *   @n a. The start of the range that needs to be written back is programmed
 *         into L2WBAR.
 *   @n b. The byte count is programmed in L2WWC.
 *
 *   @b Arguments
 *   @verbatim
            blockPtr      Start address of range to be written back

            byteCnt       Number of bytes to be written back

            wait          Whether the call is blocking (and the extent of wait)
                          till the issue operation is completed or not.
                          Whether the function must exit on completion/or not.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   @b Example
 *   @verbatim
        ...
        CACHE_wbL2((Uint32*)(0x1000), 200, CACHE_NOWAIT);
        ...
     @endverbatim
 *  ============================================================================
 */
void CACHE_wbL2 (
    void          *blockPtr,
    Uint32         byteCnt,
    CACHE_Wait     wait
);

/** ============================================================================
 *   @n@b CACHE_invL2
 *
 *   @b Description
 *   @n Invalidates range specified in L2.
 *   @n As per the specification,
 *   @n a. The start of the range that needs to be written back is programmed
 *         into L2IBAR
 *   @n b. The byte count is programmed in L2IWC.
 *
 *   @b Arguments
 *   @verbatim
            blockPtr      Start address of range to be invalidated

            byteCnt       Number of bytes to be invalidated

            wait          Whether the call is blocking (and the extent of wait)
                          till the issue operation is completed or not.
                          Whether the function must exit on completion/or not.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   @b Example
 *   @verbatim
        ...
        CACHE_invL2((Uint32*)(0x1000), 200, CACHE_NOWAIT);
        ...
     @endverbatim
 *  ============================================================================
 */
void CACHE_invL2 (
    void           *blockPtr,
    Uint32          byteCnt,
    CACHE_Wait      wait
);

/** ============================================================================
 *   @n@b CACHE_wbInvL2
 *
 *   @b Description
 *   @n Writeback invalidated range specified in L2.
 *   @n As per the specification,
 *   @n a. The start of the range that needs to be written back is programmed
 *         into L2WIBAR
 *   @n b. The byte count is programmed in L2WIWC.
 *
 *   @b Arguments
 *   @verbatim
            blockPtr      Start address of range to be written back invalidated

            byteCnt       Number of bytes to be written back invalidated

            wait          Whether the call is blocking (and the extent of wait)
                          till the issue operation is completed or not.
                          Whether the function must exit on completion/or not.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   @b Example
 *   @verbatim
        ...
        CACHE_wbInvL2((Uint32*)(0x1000), 200, CACHE_NOWAIT);
        ...
     @endverbatim
 *  ============================================================================
 */
void CACHE_wbInvL2 (
    void             *blockPtr,
    Uint32            byteCnt,
    CACHE_Wait        wait
);

/* Global Operations */

/** ============================================================================
 *   @n@b CACHE_wbAllL2
 *
 *   @b Description
 *   @n Writes back all of L2.
 *   @n As per the specification,
 *   @n a. The L2WB needs to be programmed.
 *
 *   @b Arguments
 *   @verbatim
            wait          Whether the call is blocking (and the extent of wait)
                          till the issue operation is completed or not.
                          Whether the function must exit on completion/or not.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   @b Example
 *   @verbatim
        ...
        CACHE_wbAllL2(CACHE_NOWAIT);
        ...
     @endverbatim
 *  ============================================================================
 */
void CACHE_wbAllL2 (
    CACHE_Wait       wait
);

/** ============================================================================
 *   @n@b CACHE_invAllL2
 *
 *   @b Description
 *   @n Invalidates All of L2.
 *   @n As per the specification,
 *   @n a. The L2INV needs to be programmed.
 *
 *   @b Arguments
 *   @verbatim
            wait          Whether the call is blocking (and the extent of wait)
                          till the issue operation is completed or not.
                          Whether the function must exit on completion/or not.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   @b Example
 *   @verbatim
        ...
        CACHE_invAllL2(CACHE_NOWAIT);
        ...
     @endverbatim
 *  ============================================================================
 */
void CACHE_invAllL2 (
    CACHE_Wait        wait
);

/** ============================================================================
 *   @n@b CACHE_wbInvAllL2
 *
 *   @b Description
 *   @n Writeback invalidates All of L2.
 *   @n As per the specification,
 *   @n a. The L2WBINV needs to be programmed.
 *
 *   @b Arguments
 *   @verbatim
            wait          Whether the call is blocking (and the extent of wait)
                          till the issue operation is completed or not.
                          Whether the function must exit on completion/or not.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   @b Example
 *   @verbatim
        ...
        CACHE_wbInvAllL2(CACHE_NOWAIT);
        ...
     @endverbatim
 *  ============================================================================
 */
void CACHE_wbInvAllL2 (
    CACHE_Wait          wait
);

/**
@}
*/

#ifdef __cplusplus
}
#endif

#endif /*_CSL_CACHE_H_*/

