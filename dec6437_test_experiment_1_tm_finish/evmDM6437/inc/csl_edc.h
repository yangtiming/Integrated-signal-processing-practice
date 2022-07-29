/*  ============================================================================
 *   Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005
 *
 *   Use of this software is controlled by the terms and conditions found in the
 *   license agreement under which this software has been supplied.
 *   ===========================================================================
 */
/** @mainpage EDC Module
*
* @section Introduction
*
* @subsection xxx Purpose and Scope
* The purpose of this document is to identify a set of common CSL APIs for
* the EDC Module across various devices. The CSL developer
* is expected to refer to this document while implementing APIs for these
* modules . Some of the listed APIs may not be applicable to a given EDC
*
*
*
* @subsection aaa Terms and Abbreviations
*   -# CSL     :  Chip Support Library
*   -# API     :  Application Programmer Interface
*   -# EDC :  Bandwidth Management Module
*
* @subsection References
*    -# CSL 3.x Technical Requirements Specifications Version 0.5, dated
*       May 14th, 2003
*    -# L2 Controller and L1P Controller Specification (Revision 0.99.4 & 1.01.0)
*
* @subsection Assumptions
*     The abbreviations CSL, EDC have been used throughout this
*     document to refer to the C64Plus Bandwidth Management Module.
*/

/** @file csl_edc.h
*
*  @brief    Header file for functional layer of CSL
*
*  Description
*    - The different enumerations, structure definitions
*      and function declarations
*  @date 8 July, 2004
    updated 29 July, 2004
*  @author Chad Courtney
*
*/

/**
@defgroup CSL_EDC_ENUM  Enumerated Data Types
@ingroup CSL_EDC_API
*/
/**
@defgroup CSL_EDC_API EDC
*/
/**
@defgroup CSL_EDC_DATASTRUCT  EDC Data Structures
@ingroup CSL_EDC_API
*/
/**
@defgroup CSL_EDC_SYMBOL  Symbols
@ingroup CSL_EDC_API
*/
/**
@defgroup CSL_EDC_FUNCTION  Functions
@ingroup CSL_EDC_API
*/

#ifndef _CSL_EDC_H_
#define _CSL_EDC_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <csl.h>
#include <cslr_edc.h>
#include <soc64plus.h>
/**@defgroup CSL_EDC_MEM_ENUM EDC L1P/L2 Memory Specifier.
*  @ingroup CSL_EDC_ENUM
@{*/
/** @brief Memory Specifier for EDC
*
* Used to indicate which memories (L1P or L2) are to be affected by the API
*/
typedef enum {
    /** L1P's EDC will be affected by the APIs when CSL_EDC_L1P is used */
    CSL_EDC_L1P = 0,
    /** L2's EDC will be affected by the APIs when CSL_EDC_L2 is used */
    CSL_EDC_L2 = 1

}CSL_EdcMem;
/**
@}*/

/**@defgroup CSL_EDC_CLR_ACCESS_ENUM EDC Access Type - Parity Error Clear Bit.
*  @ingroup CSL_EDC_ENUM
@{*/
/** @brief Specifies the Access Type for which the parity error is to be cleared.
*
* Used to indicate which access parity error bit to be cleared
*/
typedef enum {
    /** Data fetch parity error bit to be cleared */
    CSL_EDC_DCLR = 0,
    /** Program fetch parity error bit to be cleared */
    CSL_EDC_PCLR = 1,
    /** DMA read parity error bit to be cleared */
    CSL_EDC_DMACLR = 2,
    /** Correctable parity error count value to be cleared */
    CSL_EDC_CECNTCLR = 3,
    /** Non-correctable parity error count value to be cleared */
    CSL_EDC_NCECNTCLR = 4
}CSL_EdcClrAccessType;
/**
@}*/


/**@defgroup CSL_EDC_HW_STATUS_QUERY_ENUM EDC HW Stat Query Type.
*  @ingroup CSL_EDC_ENUM
@{*/
/** @brief EDC Hardware Status Query Type.
*
* Used to indicate what HW Status to query
*/
typedef enum
{
    /** Query enabled/disabled status */
    CSL_EDC_QUERY_ENABLESTAT    = 0,
    /** Query error status */
    CSL_EDC_QUERY_ERRORSTAT     = 1,
    /** Query number of bit error status (L2 only) */
    CSL_EDC_QUERY_NERRSTAT      = 2,
    /** Query bit position of error (L2 only) */
    CSL_EDC_QUERY_BITPOS        = 3,
    /** Query all status (returns EDSTAT register) */
    CSL_EDC_QUERY_ALLSTAT       = 4,
    /** Query page 0 enables (L2 only) */
    CSL_EDC_QUERY_PAGE0         = 5,
    /** Query page 1 enables (L2 only) */
    CSL_EDC_QUERY_PAGE1         = 6,
    /** Query correctable error count (L2 only) */
    CSL_EDC_QUERY_CE_CNT        = 7,
    /** Query non-correctable error count (L2 only) */
    CSL_EDC_QUERY_NCE_CNT       = 8
}CSL_EdcHwStatusQuery;
/**
@}*/

/**@defgroup CSL_EDC_ENABLE_STATUS EDC ENABLE Status
*  @ingroup CSL_EDC_ENUM
@{*/
/** @brief EDC Enable/Disable Status
*
* Used to indicate whether EDC is enabled, disabled, or suspended.
*/
typedef enum
{
    /** EDC - enabled */
    CSL_EDC_ENABLED     = 1,
    /** EDC - disabled */
    CSL_EDC_DISABLED    = 2,
    /** EDC - suspended */
    CSL_EDC_SUSPENDED   = 4
}CSL_EdcEnableStatus;
/**
@}*/

/**@defgroup CSL_EDC_ERROR_STATUS EDC error status
*  @ingroup CSL_EDC_ENUM
@{*/
/** @brief EDC error status
*
* Used to indicate EDC access error type.
*/
typedef enum
{
    /** EDC error status - data fetch parity error */
    CSL_EDC_DERR    = 1,
    /** EDC error status - program fetch parity error */
    CSL_EDC_IERR    = 2,
    /** EDC error status - DMA read parity error */
    CSL_EDC_DMAERR  = 4
}CSL_EdcErrorStatus;
/**
@}*/

/**@defgroup CSL_EDC_NUM_ERROR_STATUS EDC bit error number
*  @ingroup CSL_EDC_ENUM
@{*/
/** @brief Indicates the number of EDC bit errors
*
* Used to indicate number of EDC bit errors or if bit error is in parity value.
*/
typedef enum
{
    /** EDC number of bit errors - single bit error */
    CSL_EDC_1BIT    = CSL_EDC_L2EDSTAT_NERR_1BIT,
    /** EDC number of bit errors - double bit error */
    CSL_EDC_2BIT    = CSL_EDC_L2EDSTAT_NERR_2BIT,
    /** EDC number of bit errors - error in parity value */
    CSL_EDC_PERROR  = CSL_EDC_L2EDSTAT_NERR_PERROR
}CSL_EdcNumErrors;
/**
@}*/

/**@defgroup CSL_EDC_UMAP EDC UMAP Page Enables
*  @ingroup CSL_EDC_ENUM
@{*/
/** @brief UMAP Specifier for EDC
*
* Used to indicate which of the UMAPs the page enables are to be applied to.
*/
typedef enum
{
    /** EDC apply page enables to UMAP0 only */
    CSL_EDC_UMAP0   = 0,
    /** EDC apply page enables to UMAP1 only */
    CSL_EDC_UMAP1   = 1,
    /** EDC apply page enables to both UMAP0 and UMAP1 */
    CSL_EDC_UMAPBOTH    = 2
}CSL_EdcUmap;
/**
@}*/

/**@defgroup CSL_EDC_ADDR_L2WAY EDC error L2 way
*  @ingroup CSL_EDC_ENUM
@{*/
/** @brief L2 way specifier for EDC error.
*
* Provides the L2 way for the Address of the detected error.
*/
typedef enum
{
    /** L2 way 0 */
    CSL_EDC_L2WAY_0 = CSL_EDC_L2EDADDR_L2WAY_WAY0,
    /** L2 way 1 */
    CSL_EDC_L2WAY_1 = CSL_EDC_L2EDADDR_L2WAY_WAY1,
    /** L2 way 2 */
    CSL_EDC_L2WAY_2 = CSL_EDC_L2EDADDR_L2WAY_WAY2,
    /** L2 way 3 */
    CSL_EDC_L2WAY_3 = CSL_EDC_L2EDADDR_L2WAY_WAY3
}CSL_EdcAddrL2way;
/**
@}*/

/**@defgroup CSL_EDC_ADDR_QLINE EDC error QLINE
*  @ingroup CSL_EDC_ENUM
@{*/
/** @brief QLINE specifier for EDC error.
*
* Provides the QLINE (1/4 Cache Line) for the address of the detected error.
*/
typedef enum
{
    /** 1st QLINE - (1/4 cache line) SRAM error located in */
    CSL_EDC_QLINE_1 = CSL_EDC_L2EDADDR_QLINE_QTR1,
    /** 2nd QLINE - (1/4 cache line) SRAM error located in */
    CSL_EDC_QLINE_2 = CSL_EDC_L2EDADDR_QLINE_QTR2,
    /** 3rd QLINE - (1/4 cache line) SRAM error located in */
    CSL_EDC_QLINE_3 = CSL_EDC_L2EDADDR_QLINE_QTR3,
    /** 4th QLINE - (1/4 cache line) SRAM error located in */
    CSL_EDC_QLINE_4 = CSL_EDC_L2EDADDR_QLINE_QTR4
}CSL_EdcAddrQline;
/**
@}*/

/**@defgroup CSL_EDC_ADDR_SRAM EDC error location (SRAM or Cache)
*  @ingroup CSL_EDC_ENUM
@{*/
/** @brief EDC error in SRAM or Cache
*
*  Specifies whether the EDC error was located in the SRAM or Cache
*
*/
typedef enum
{
    /** EDC error is in cache */
    CSL_EDC_CACHE   = CSL_EDC_L2EDADDR_SRAM_L2CACHE,
    /** EDC error is in SRAM */
    CSL_EDC_SRAM    = CSL_EDC_L2EDADDR_SRAM_L2SRAM
}CSL_EdcAddrSram;
/**
@}*/

/** @addtogroup CSL_EDC_DATASTRUCT
*
* @{ */
/** @brief CSL_EdcAddrInfo has all the fields required locate the parity error
*/
typedef struct CSL_EdcAddrInfo {
    Uint32              addr;       /** Address of the parity error - 5 LSBs always 0 */
    CSL_EdcAddrL2way    l2way;      /** The cache way the error was detected in if in cache */
    CSL_EdcAddrQline    qline;      /** The quarter line in which the parity error was detected */
    CSL_EdcAddrSram     sram;       /** Parity error was detected in SRAM or Cache */
}CSL_EdcAddrInfo;

/**
@}
*/

/** ===========================================================================
 *   @n@b CSL_edcEnable
 *
 *   @b Description
 *        Enables the EDC for the specified memory
 *
 *   @b Arguments
 *   @verbatim

        edcMem          Specificies what memory EDC is to be enabled

     @endverbatim
 *
*   <b> Return Value </b>  CSL_Status
 *                          CSL_SOK            - Always
 *
 *   @b Example
 *   @verbatim
 *        CSL_status        status;
 *        CSL_EdcMem        edcMem = CSL_EDC_L2;
 *
 *        status = CSL_edcEnable (edcMem);
 *  @endverbatim
 * ===========================================================================
 */
CSL_Status  CSL_edcEnable
(
    /** Specificies what memory EDC is to be enabled
     */
    CSL_EdcMem              edcMem
);

/**
@}
*/

/** ===========================================================================
 *   @n@b CSL_edcDisable
 *
 *   @b Description
 *        Disables the EDC for the specified memory
 *
 *   @b Arguments
 *   @verbatim

        edcMem          Specificies what memory EDC is to be disabled

     @endverbatim
 *
*   <b> Return Value </b>  CSL_Status
 *                          CSL_SOK            - Always
 *
 *   @b Example
 *   @verbatim
 *        CSL_status        status;
 *        CSL_EdcMem        edcMem = CSL_EDC_L2;
 *
 *        status = CSL_edcDisable (edcMem);
 *  @endverbatim
 * ===========================================================================
 */
CSL_Status  CSL_edcDisable
(
    /** Specificies what memory EDC is to be enabled
     */
    CSL_EdcMem              edcMem
);

/**
@}
*/

/** ===========================================================================
 *   @n@b CSL_edcClear
 *
 *   @b Description
 *        Clears the Address of the parity error for the specified memory
 *        along with the access type parity error bit
 *
 *   @b Arguments
 *   @verbatim

        edcMem          specificies what memory EDC is to be cleared

        edcAccessType   specificies what fetch type parity error bit is to be
                        cleared

     @endverbatim
 *
*   <b> Return Value </b>  CSL_Status
 *                          CSL_SOK            - Always
 *
 *   @b Example
 *   @verbatim
 *        CSL_status            status;
 *        CSL_EdcMem            edcMem = CSL_EDC_L2;
 *        CSL_EdcClrAccessType  edcAccessType = CSL_EDC_DCLR;

 *        status = CSL_edcClear (edcMem, edcAccessType);
 *  @endverbatim
 * ===========================================================================
 */
CSL_Status  CSL_edcClear
(
    /** Specificies what memory EDC error address is to be cleared
     */
    CSL_EdcMem              edcMem,
    /** Specificies what fetch type parity error bit is to be Cleared
     */
    CSL_EdcClrAccessType    edcAccessType
);

/**
@}
*/

/** ===========================================================================
 *   @n@b CSL_edcGetAddr
 *
 *   @b Description
 *        Used to get the Address location of the parity error.
 *
 *   @b Arguments
 *   @verbatim

        edcMem          specificies what memory EDC is to be cleared

        edcAddr         pointer to the structure for returning Address, L2 Way,
                        Qline, SRAM/Cache Info for error

     @endverbatim
 *
*   <b> Return Value </b>  CSL_Status
 *                          CSL_SOK            - Always
 *
 *   @b Example
 *   @verbatim
 *        CSL_status            status;
 *        CSL_EdcMem            edcMem = CSL_EDC_L2;
 *        CSL_EdcAddrInfo       edcAddr = CSL_EDC_DCLR;

 *        status = CSL_edcGetAddr (edcMem, &edcAddr);
 *  @endverbatim
 * ===========================================================================
 */
CSL_Status  CSL_edcGetAddr
(
    /** Specificies what memory EDC Address Info is to be aquired for
     */
    CSL_EdcMem              edcMem,
    /** Structure for returning Address, L2 Way, Qline, SRAM/Cache Info for error
     */
    CSL_EdcAddrInfo         *edcAddr
);
/**
@}
*/

/** ===========================================================================
 *   @n@b CSL_edcGetHwStatus
 *
 *   @b Description
 *        Gets the requested HW Status of the specified memory
 *
 *   @b Arguments
 *   @verbatim

        edcMem          specificies what memory EDC is to be cleared

        query           Statur query

        response        place holder for status

     @endverbatim
 *
*   <b> Return Value </b>  CSL_Status
 *                          CSL_SOK            - Always
 *
 *   @b Example
 *   @verbatim
 *        CSL_status                status;
 *        CSL_EdcMem                edcMem = CSL_EDC_L2;
 *        CSL_EdcHwStatusQuery      query = CSL_EDC_QUERY_ENABLESTAT;
          void                      *response;

 *        status = CSL_edcGetHwStatus (edcMem, query, response);
 *  @endverbatim
 * ===========================================================================
 */
CSL_Status  CSL_edcGetHwStatus
(
    /** Specificies what memory EDC status is to be obtained for
     */
    CSL_EdcMem              edcMem,
    /** The query to this API which indicates the status
     *  to be returned
     */
    CSL_EdcHwStatusQuery    query,
    /** Placeholder to return the status. @a void* casted
    */
    void                    *response
);

/**
@}
*/

/** ===========================================================================
 *   @n@b CSL_edcPageEnable
 *
 *   @b Description
 *        Used to enable the pages for EDC
 *
 *   @b Arguments
 *   @verbatim

        mask          Specifies what pages of the given map(s) are to be
                      enabled by setting the bit corresponding to the page to 1

        umap          Specificies which map(s) to apply mask to (MAP0, MAP1,
                      or BOTH)

     @endverbatim
 *
*   <b> Return Value </b>  CSL_Status
 *                          CSL_SOK            - Always
 *
 *   @b Example
 *   @verbatim
 *        Uint32                      mask;
 *        CSL_EdcUmap                 umap;
 *
 *        status = CSL_edcPageEnable (mask, umap);
 *  @endverbatim
 * ===========================================================================
 */
/**
@defgroup CSL_EDC_PAGE_ENABLE_API EDC Page Enable API
@ingroup CSL_EDC_FUNCTION
@brief Used to enable the pages for EDC.
@{*/
CSL_Status  CSL_edcPageEnable
(
    /** Specifies what pages of the given map(s) are to be enabled by setting the
    * bit corresponding to the page to 1
    */
    Uint32                      mask,
    /** Specificies which map(s) to apply mask to (MAP0, MAP1, or BOTH)
     */
    CSL_EdcUmap                 umap
);

/**
@}
*/

/**
@defgroup EXAMPLE Example Usage in an ISR
@ingroup CSL_EDC_API
@{
@code
In order to clarify on the usage of some of the CSL APIs, a skeleton is presented below

Example: Interrupt driven Low level Driver
Main routine
Void main(){
    CSL_EdcAddrInfo     *Addr;
    CSL_Status          stat;
    Uint32              *AllStat;

// Initialize system before making any module calls specific calls
    if(CSL_sysInit() == CSL_SOK){
        CSL_edcInit();
    }

// Enable EDC for L2 memory
    stat = CSL_edcEnable(CSL_EDC_L2);
    exit;

// EDC code to be placed in an ISR to Get Information when a failure occurs
    stat    CSL_edcGetHwStatus(L2, CSL_EDC_QUERY_ALLSTAT, AllStat)
    stat    CSL_edcGetAddr(L2, Addr);
    exit;

} // End of Main

@endcode
@}
*/

#ifdef __cplusplus
}
#endif

#endif



