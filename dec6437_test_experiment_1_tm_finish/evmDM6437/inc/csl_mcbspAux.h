/*  ============================================================================
 *   Copyright (c) Texas Instruments Inc 2002, 2003, 2004
 *
 *   Use of this software is controlled by the terms and conditions found
 *   in the license agreement under which this software has been supplied.
 *  ============================================================================
 */

/** @file csl_mcbspAux.h
 *
 * @brief  Header file for functional layer of CSL
 *
 * Description
 *    - The decribes the definitions of the inline functions
 *
 *  Path: \\(CSLPATH)\\ipmodules\\mcbsp\\src
 */

/* =============================================================================
 *  Revision History
 *  ===============
 *  15-Feb-2005 NSR File Created from CSL_mcbspHwControl.c 
 *                  And CSL_mcbspGetHwStatus.c.
 *
 * =============================================================================
 */

#ifndef _CSL_MCBSPAUX_H_
#define _CSL_MCBSPAUX_H_

#include<csl_mcbsp.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  Status Query Functions of mcbsp.
 */

/** ============================================================================
 *   @n@b CSL_mcbspGetCurRxBlk
 *
 *   @b Description
 *   @n This function enables the MCBSP module.
 *
 *   @b Arguments
 *   @verbatim

            hMcbsp          Handle to MCBSP instance

            response        Placeholder to return status.

     @endverbatim
 *
 *   <b> Return Value </b>  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Modifies
 *   @n  None
 *
 *   @b Example
 *   @verbatim

        CSL_mcbspGetCurRxBlk (hMcbsp, response);

     @endverbatim
 * ===========================================================================
 */
CSL_IDEF_INLINE
void CSL_mcbspGetCurRxBlk (
    /** Pointer to the object that holds reference to the
     *  instance of MCBSP requested after the call
     */
    CSL_McbspHandle        hMcbsp,

    /** Placeholder to return the status. @a void* casted */
    void                 *response
)
{
    *(CSL_McbspBlock *)response = (CSL_McbspBlock)(CSL_FEXT( hMcbsp->regs->MCR, MCBSP_MCR_RCBLK));
}


/** ============================================================================
 *   @n@b CSL_mcbspGetCurTxBlk
 *
 *   @b Description
 *   @n This function enables the MCBSP module.
 *
 *   @b Arguments
 *   @verbatim

            hMcbsp          Handle to MCBSP instance

            response        Placeholder to return status.

     @endverbatim
 *
 *   <b> Return Value </b>  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Modifies
 *   @n  None
 *
 *   @b Example
 *   @verbatim

        CSL_mcbspGetCurTxBlk (hMcbsp, response);

     @endverbatim
 * ===========================================================================
 */
CSL_IDEF_INLINE
void CSL_mcbspGetCurTxBlk (
    /** Pointer to the object that holds reference to the
     *  instance of MCBSP requested after the call
     */
    CSL_McbspHandle        hMcbsp,

    /** Placeholder to return the status. @a void* casted */
    void                 *response
)
{
    *(CSL_McbspBlock *)response = (CSL_McbspBlock)(CSL_FEXT(hMcbsp->regs->MCR, MCBSP_MCR_XCBLK));
}


/** ============================================================================
 *   @n@b CSL_mcbspGetDevStatus
 *
 *   @b Description
 *   @n This function enables the MCBSP module.
 *
 *   @b Arguments
 *   @verbatim

            hMcbsp          Handle to MCBSP instance

            response        Placeholder to return status.

     @endverbatim
 *
 *   <b> Return Value </b>  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Modifies
 *   @n  None
 *
 *   @b Example
 *   @verbatim

        CSL_mcbspGetDevStatus (hMcbsp, response);

     @endverbatim
 * ===========================================================================
 */
CSL_IDEF_INLINE
void CSL_mcbspGetDevStatus (
    /** Pointer to the object that holds reference to the
     *  instance of MCBSP requested after the call
     */
    CSL_McbspHandle        hMcbsp,

    /** Placeholder to return the status. @a void* casted */
    void                 *response
)
{
    *(CSL_BitMask16*)response = (( CSL_FEXT(hMcbsp->regs->SPCR, MCBSP_SPCR_RRDY)) | \
               ( CSL_FEXT(hMcbsp->regs->SPCR, MCBSP_SPCR_XRDY)     << (1)) | \
               ( CSL_FEXT(hMcbsp->regs->SPCR, MCBSP_SPCR_RFULL)    << (2)) | \
               ( CSL_FEXT(hMcbsp->regs->SPCR, MCBSP_SPCR_XEMPTY)   << (3)) | \
               ( CSL_FEXT(hMcbsp->regs->SPCR, MCBSP_SPCR_RSYNCERR) << (4)) | \
               ( CSL_FEXT(hMcbsp->regs->SPCR, MCBSP_SPCR_XSYNCERR) << (5)));
}


/** ============================================================================
 *   @n@b CSL_mcbspGetTxRstStat
 *
 *   @b Description
 *   @n This function enables the MCBSP module.
 *
 *   @b Arguments
 *   @verbatim

            hMcbsp          Handle to MCBSP instance

            response        Placeholder to return status.

     @endverbatim
 *
 *   <b> Return Value </b>  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Modifies
 *   @n  None
 *
 *   @b Example
 *   @verbatim

        CSL_mcbspGetTxRstStat (hMcbsp, response);

     @endverbatim
 * ===========================================================================
 */
CSL_IDEF_INLINE
void CSL_mcbspGetTxRstStat (
    /** Pointer to the object that holds reference to the
     *  instance of MCBSP requested after the call
     */
    CSL_McbspHandle        hMcbsp,

    /** Placeholder to return the status. @a void* casted */
    void                 *response
)
{
    *(CSL_McbspRstStat *)response = 
                 (CSL_McbspRstStat)(CSL_FEXT(hMcbsp->regs->SPCR, MCBSP_SPCR_XRST));
}


/** ============================================================================
 *   @n@b CSL_mcbspGetRxRstStat
 *
 *   @b Description
 *   @n This function enables the MCBSP module.
 *
 *   @b Arguments
 *   @verbatim

            hMcbsp          Handle to MCBSP instance

            response        Placeholder to return status.

     @endverbatim
 *
 *   <b> Return Value </b>  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Modifies
 *   @n  None
 *
 *   @b Example
 *   @verbatim

       CSL_mcbspGetRxRstStat (hMcbsp, response);

     @endverbatim
 * ===========================================================================
 */
CSL_IDEF_INLINE
void CSL_mcbspGetRxRstStat (
    /** Pointer to the object that holds reference to the
     *  instance of MCBSP requested after the call
     */
    CSL_McbspHandle        hMcbsp,

    /** Placeholder to return the status. @a void* casted */
    void                 *response
)
{
     *(CSL_McbspRstStat *)response = 
                 (CSL_McbspRstStat)(CSL_FEXT(hMcbsp->regs->SPCR, MCBSP_SPCR_RRST));
}


/** ============================================================================
 *   @n@b CSL_mcbspGetPid 
 *
 *   @b Description
 *   @n This function returns the PID of McBSP module.
 *
 *   @b Arguments
 *   @verbatim

            hMcbsp          Handle to MCBSP instance

            response        Placeholder to return status.

     @endverbatim
 *
 *   <b> Return Value </b>  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Modifies
 *   @n  None
 *
 *   @b Example
 *   @verbatim

       CSL_mcbspGetPid (hMcbsp, response);

     @endverbatim
 * ===========================================================================
 */
CSL_IDEF_INLINE
void CSL_mcbspGetPid (
    /** Pointer to the object that holds reference to the
     *  instance of MCBSP requested after the call
     */
    CSL_McbspHandle        hMcbsp,

    /** Placeholder to return the status. @a void* casted */
    void                   *response
)
{
     ((CSL_McbspPeriId *)response)->type = CSL_FEXT(hMcbsp->regs->PID, \
                                                    MCBSP_PID_TYPE); 
     ((CSL_McbspPeriId *)response)->devclass = CSL_FEXT(hMcbsp->regs->PID, \
                                                        MCBSP_PID_CLASS);
     ((CSL_McbspPeriId *)response)->revision = CSL_FEXT(hMcbsp->regs->PID, \
                                                        MCBSP_PID_REVISION);
}

/** Control Commands */

/** ============================================================================
 *   @n@b CSL_mcbspIdleControl 
 *
 *   @b Description
 *   @n This function enables/disables - Frame Sync, Sample Rate Generator and 
 *      XMT/RCV Operation  
 *
 *   @b Arguments
 *   @verbatim

            hMcbsp          Handle to MCBSP instance

            response        Placeholder to return status.

     @endverbatim
 *
 *   <b> Return Value </b>  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Modifies
 *   @n  None
 *
 *   @b Example
 *   @verbatim

       CSL_mcbspIdleControl (hMcbsp, arg);

     @endverbatim
 * =============================================================================
 */
CSL_IDEF_INLINE
void CSL_mcbspIdleControl (
    /** Pointer to the object that holds reference to the
     *  instance of MCBSP requested after the call
     */
    CSL_McbspHandle        hMcbsp,

    /** Placeholder to return the status. @a void* casted */
    void                  *arg
)
{
    CSL_FINS (hMcbsp->regs->PCR, MCBSP_PCR_IDLEN, *(CSL_BitMask16 *)arg);
}

        
#ifdef __cplusplus
extern "C" {
#endif

#endif /* CSL_MCBSPAUX_H_ */


