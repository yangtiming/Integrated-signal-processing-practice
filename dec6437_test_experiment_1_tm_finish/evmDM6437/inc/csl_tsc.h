/*  ============================================================================
 *   Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005                 
 *                                                                              
 *   Use of this software is controlled by the terms and conditions found in the
 *   license agreement under which this software has been supplied.             
 *   ===========================================================================
 */
 
/** @mainpage CTIMER Module
*
* @section Introduction
*
* @subsection xxx Purpose and Scope
* The purpose of this document is to identify a set of common CSL APIs for 
* the CTIMER 
*
*
* @subsection aaa Terms and Abbreviations
*   -# CSL     :  Chip Support Library
*   -# API     :  Application Programmer Interface
*   -# CTIMER  :  CPU Timer Module
*
* @subsection References
*    -# CSL 3.x Technical Requirements Specifications Version 0.5, dated
*       May 14th, 2003
*    -# Bandwidth Management Specification (Revision 0.22)
*
* @subsection Assumptions
*     The abbreviations CSL, CTIMER have been used throughout this
*     document to refer to the C64Plus CPU Timer.
*/

/** @file csl_tsc.h
*
*  @brief    Header file for functional layer of CSL
*
*  Description
*    - Function declarations
*  @date 9th June, 2004
*  @author Chad Courtney
*/

/**
@defgroup CSL_CTIMER_FUNCTION  Functions
@ingroup CSL_CTIMER_API
*/

#ifndef _CSL_CTIMER_H_
#define _CSL_CTIMER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <csl_error.h>
#include <csl_types.h>


/**
@defgroup CSL_CTIMER_START_API CTIMER Start API
@ingroup CSL_CTIMER_FUNCTION
@{*/
/** ===========================================================================
 *   @n@b CSL_ctimerStart
 *
 *   @b Description
 *   @n Starts the 64 bit CPU Timer.  CPU Timer stops only upon Reset or 
 *      Powerdown.When CPU timer is started (following a reset or powerdown 
 *      of the CPU) it will initialize to 0 and begin incrementing once per 
 *      CPU cycle.  You cannot reset the CPU Timer.  If CSL_ctimerStart is 
 *      called more than once -1 (CSL_ERROR) is returned indicating that a 
 *      subsequent attempt has been made to  start the timer. 
 *      Note: This has no negative effect on the time, but is a reminder that 
 *      the CPU timer is not reset to 0 at this point.
 *
 *   @b Arguments           None
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK             - successful.
 *   @li                    CSL_ESYS_FAIL       - In case of fail to start
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Modifies            None
 *
 *   @b Example
 *   @verbatim
        Uint32          ctimerLow;
        Uint32          ctimerHigh;
        Uint32          tempLow;
        Uint32          tempHigh;
        CSL_Status      stat;   
    
        ...
        
        stat = 0;
        stat = CSL_ctimerStart();
        
 *   @endverbatim
 * ============================================================================
 */
CSL_Status  CSL_ctimerStart(void);


/**
@}
*/
/**
@defgroup CSL_CTIMER_READ_API CTIMER Read API
@ingroup CSL_CTIMER_FUNCTION
@brief Reads the C64 bit CPU Timer.  The lower 32 bits are placed at *ctimerLow
and the upper 32 bits are placed at *ctimerHigh.
@{*/
/** ============================================================================
 *   @n@b CSL_ctimerRead
 *
 *   @b Description
 *   @n Reads the C64 bit CPU Timer. The lower 32 bits are placed at *ctimerLow
 *      and the upper 32 bits are placed at *ctimerHigh.
 *
 *   @b Arguments
 *   @verbatim
            ctimerLow            Pointer to Lower 32 bits of the CPU Timer

            ctimerHigh           Pointer to Upper 32 bits of the CPU Timer 
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK             - For successful.
 *   @li                    CSL_ESYS_FAIL       - In case of fail to read
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Modifies            None
 *
 *   @b Example
 *   @verbatim
        Uint32          ctimerLow;
        Uint32          ctimerHigh;
        Uint32          tempLow;
        Uint32          tempHigh;
        CSL_Status      stat;   
    
        ...
        
        stat = 0;
        stat = CSL_ctimerStart();
        CSL_ctimerRead(&ctimerLow, &ctimerHigh);
        
 *   @endverbatim
 * ============================================================================
 */
CSL_Status  CSL_ctimerRead(
    /** Pointer to where the Lower 32 bits of the CPU Timer 
        Will be stored upon read completion */
    Uint32 *ctimerLow,
    /** Pointer to where the Upper 32 bits of the CPU Timer 
        Will be stored upon read completion */
    Uint32 *ctimerHigh
);
/**
@}*/

#ifdef __cplusplus
}
#endif

#endif



