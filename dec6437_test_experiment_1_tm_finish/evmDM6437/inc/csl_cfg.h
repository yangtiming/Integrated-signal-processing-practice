/*  ============================================================================
 *   Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005                 
 *                                                                              
 *   Use of this software is controlled by the terms and conditions found in the
 *   license agreement under which this software has been supplied.             
 *   ===========================================================================
 */ 

/** @file csl_cfg.h
 *
 *  @brief   Header file for functional layer of CSL
 *
 *  Description
 *    - The different enumerations, structure definitions
 *      and function declarations
 *
 *  PATH  \\(CSLPATH)\\ipmodules\\config\\src
 *
 *  @date 14th Apr, 2005
 *  @author BRN
 */

/** @mainpage CFG Module
 *
 * @section Introduction
 *
 * @subsection xxx Purpose and Scope
 * The purpose of this document is to identify a set of common CSL APIs for
 * the CFG Module across various devices. The CSL developer
 * is expected to refer to this document while implementing APIs for these
 * modules. Some of the listed APIs may not be applicable to a given CFG
 *
 *
 *
 * @subsection aaa Terms and Abbreviations
 *   -# CSL     :  Chip Support Library
 *   -# API     :  Application Programmer Interface
 *   -# CFG     :  Configuration
 *
 */

/* =============================================================================
 *  Revision History
 *  ===============
 *  14-Apr-2005 Brn file created
 *
 * =============================================================================
 */

/**
@defgroup CSL_CFG_ENUM  Enumerated Data Types
@ingroup CSL_CFG_API
*/
/**
@defgroup CSL_CFG_API CFG
*/
/**
@defgroup CSL_CFG_DATASTRUCT  CFG Data Structures
@ingroup CSL_CFG_API
*/
/**
@defgroup CSL_CFG_SYMBOL  Symbols
@ingroup CSL_CFG_API
*/
/**
@defgroup CSL_CFG_FUNCTION  Functions
@ingroup CSL_CFG_API
*/

#ifndef _CSL_CFG_H_
#define _CSL_CFG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <csl.h>
#include <cslr_cfg.h>
#include <soc64plus.h>

/** @brief Enumeration for queries passed to @a CSL_cfgHwControl()
 *
 * This is used to select the commands to control the operations
 * existing setup of CFG. The arguments to be passed with each
 * enumeration if any are specified next to the enumeration.
 */
typedef enum
{
    /** CFG Hardware control command to clears the error conditions stored in
     *  MPFAR and MPFSR
     */
    CSL_CFG_CMD_CLEAR = 1

}CSL_CfgHwControlCmd;

/** @brief Enumeration for queries passed to @a CSL_cfgGetHwStatus()
 *
 * This is used to get the status of different operations or to get the
 * existing setup of CFG.
 */
typedef enum
{
    /** Status query command to get the Fault Address (response type:
     *  @a Uint16*)
     */
    CSL_CFG_QUERY_FAULT_ADDR = 1,
    /** Status query command to get the Status information of CSL_CfgStatus
     *  (response type: @a CSL_CfgStatus*)
     */
    CSL_CFG_QUERY_STATUS     = 2

}CSL_CfgHwStatusQuery;


/** @addtogroup CSL_CFG_DATASTRUCT
 *
 * @{ */
/** @brief CSL_CfgStatus has all the fields required for the status information
 *         of CFG module.
 */
typedef struct CSL_CfgStatus {
    /** User Execute Fault */
    Uint16  atype;
    /** Security Error */
    Uint16  secError;
    /** Fault Id. The IDof the originator of the faulting access */
    Uint16  faultId;
}CSL_CfgStatus;

/**
@}
*/

/**
@addtogroup CSL_CFG_DATASTRUCT
@{
*/
/** @brief This object contains the reference to the instance of CFG
 * opened using the @a CSL_CfgOpen()
 *
 * The pointer to this is passed to all CFG CSL APIs.
 * This structure has the fields required to configure CFG for any test
 * case/application. It should be initialized as per requirements of a
 * test case/application and passed on to the setup function.
 */
typedef struct CSL_CfgObj {
    /** This is a pointer to the registers of the instance of CFG
     * referred to by this object
     */
    CSL_CfgRegsOvly       regs;
    /** This is the instance of CFG being referred to by this object */
    CSL_InstNum            cfgNum;
}CSL_CfgObj;
/**
@}
*/

/** @brief this is a pointer to @a CSL_CfgObj & is passed as the first
 * parameter to all CFG CSL APIs
 */
typedef struct CSL_CfgObj *CSL_CfgHandle;

/** @brief this is a dummy object for the CFG parameters */
typedef void CSL_CfgParam;

/** @brief this is a dummy object for the CFG Context */
typedef void CSL_CfgContext;

/** ===========================================================================
 *   @n@b CSL_cfgOpen
 *
 *   @b Description
 *        This function populates the peripheral data object for the instance
 *        and returns a handle to the instance.
 *        The open call sets up the data structures for the particular instance
 *        of CFG device. The device can be re-opened anytime after it has
 *        been normally closed if so required. CFG Hardware setup will be
 *        performed at the end of the open call only if the HwSetup Pointer
 *        supplied was non- NULL. The handle returned by this call is input as
 *        an essential argument for rest of the APIs described for this module.
 *
 *   @b Arguments
 *   @verbatim
        pCfgObj         Pointer to the CFG instance object

        cfgNum          Instance of the CFG to be opened.

        pCfgParam       Pointer to module specific parameters

        pStatus         pointer for returning status of the function call
     @endverbatim
 *
 *   <b> Return Value </b> CSL_CfgHandle
 *        Valid CFG instance handle will be returned if status value is
 *        equal to CSL_SOK.
 *
 *   @b Example
 *   @verbatim
 *        CSL_status        status;
 *        CSL_CfgObj        cfgObj;
 *        CSL_CfgHandle     hCfg;
 *
 *        hCfg = CSL_cfgOpen (&cfgObj, CSL_CFG_PER_CNT, NULL, &status);
 *  @endverbatim
 * ===========================================================================
 */
CSL_CfgHandle  CSL_cfgOpen
(
    /** Pointer to the handle object - to be allocated by the user
     */
    CSL_CfgObj                  *hCfgObj,
    /** Specifies the instance of CFG to be opened */
    CSL_InstNum                 cfgNum,
    /** Module specific parameters;
     *  Currently there are none; the user should pass 'NULL'
     */
    CSL_CfgParam                *pCfgParam,
    /** Pointer to the variable that holds the holds the status of the open
     *  call
     */
    CSL_Status                  *status
);

/** ============================================================================
 *   @n@b CSL_cfgClose
 *
 *   @b Description
 *   @n This function closes the specified instance of CFG.
 *
 * <b> Usage Constraints: </b>
 * Both @a CSL_cfgInit() and @a CSL_cfgOpen() must be called successfully
 * in that order before @a CSL_cfgClose() can be called.
 *
 *   @arg  hCfg             Handle to the CFG instance
 *
 *   <b> Return Value </b>  CSL_Status
 *                          CSL_SOK            - Close successful
 *                          CSL_ESYS_BADHANDLE - Invalid handle
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Modifies
 *   @n None
 *   @b Example
 *   @verbatim
 *     CSL_cfgClose (hCfg);
 *
 *  @endverbatim
 * =============================================================================
 */
CSL_Status  CSL_cfgClose
(
    /** Pointer to the object that holds reference to the
     * instance of CFG requested after the call
     */
    CSL_CfgHandle           hCfg
);

/** ============================================================================
 *   @n@b CSL_cfgHwControl
 *
 *   @b Description
 *   @n Takes a command of CFG with an optional argument & implements it.
 *
 *   @b Arguments
 *   @verbatim
            hCfg            Handle to the CFG instance

            cmd             The command to this API indicates the action to be
                            taken on CFG.

            arg             An optional argument.

     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li         CSL_SOK               - Status info return successful.
 *   @li         CSL_ESYS_INVCMD       - Invalid command
 *   @li         CSL_ESYS_INVPARAMS    - Invalid parameter
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Modifies
 *   @n The registers of CFG.
 *
 *   @b Example
 *   @verbatim
        CSL_CfgHandle         hCfg;
        CSL_CfgHwControlCmd   cmd;
        void                  arg;

        status = CSL_cfgHwControl (hCfg, cmd, &arg);

     @endverbatim
 * =============================================================================
 */
CSL_Status  CSL_cfgHwControl
(
    /** Pointer to the object that holds reference to the
     * instance of CFG requested after the call
     */
    CSL_CfgHandle           hCfg,
    /** The command to this API which indicates the action to be taken */
    CSL_CfgHwControlCmd     cmd,
    /** Optional argument @a void* casted */
    void                    *cmdArg
);

/** ============================================================================
 *   @n@b CSL_cfgInit
 *
 *   @b Description
 *   @n This is the initialization function for the CFG. This function is
 *      idempotent in that calling it many times is same as calling it once.
 *      This function initializes the CSL data structures, and doesn't affect
 *      the H/W.
 *
 *   @b Arguments
     @verbatim
            pContext   Context information for the instance. Should be NULL
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK - Always returns
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Modifies
 *   @n  None
 *
 *   @b Example
 *   @verbatim
 *    ...
 *    if (CSL_sysInit() == CSL_SOK) {
 *       CSL_cfgInit();
 *    }
 *   @endverbatim
 *  ===========================================================================
 */
CSL_Status  CSL_cfgInit
(
    /** CFG Context */
    CSL_CfgContext      * pContext
);

/** ============================================================================
 *   @n@b CSL_cfgGetHwStatus
 *
 *   @b Description
 *   @n Gets the status of the different operations of CFG.
 *
 *   @b Arguments
 *   @verbatim
            hCfg          Handle to the CFG instance

            query         The query to this API of CFG which indicates the
                          status to be returned.

            response      Placeholder to return the status.

     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK             - Status info return successful
 *   @li                    CSL_ESYS_INVQUERY   - Invalid query command
 *   @li                    CSL_ESYS_INVPARAMS  - Invalid parameter
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
        CSL_CfgHandle          hCfg;
        CSL_CfgHwStatusQuery   query;
        void                   reponse;

        status = CSL_GetcfgHwStatus (hCfg, query, &response);

     @endverbatim
 * =============================================================================
 */
CSL_Status  CSL_cfgGetHwStatus
(
    /** Pointer to the object that holds reference to the
     * instance of CFG requested after the call
     */
    CSL_CfgHandle           hCfg,
    /** The query to this API which indicates the status/setup
     * to be returned
     */
    CSL_CfgHwStatusQuery    myQuery,
    /** Placeholder to return the status; @a void* casted */
    void                    *response
);

#ifdef __cplusplus
}
#endif

#endif
