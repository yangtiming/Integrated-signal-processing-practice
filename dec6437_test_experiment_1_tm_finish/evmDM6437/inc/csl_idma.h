/*  ============================================================================
 *   Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005                 
 *                                                                              
 *   Use of this software is controlled by the terms and conditions found in the
 *   license agreement under which this software has been supplied.             
 *   ===========================================================================
 */ 
/*---------------------------------------------------------------------*/
/* NAME                                                                */
/*      idma.h                                                         */
/*                                                                     */
/* REVISION HISTORY:                                                   */
/* 03-25-04...Initial version of Channel 1 routines.......S.Jagadeesh  */
/* 05-20-04...Integration of CSL Register Layer...........C.Courtney   */
/* 06-10-04...Changed Return Types of all functions except Open to     */
/*            Status......................................C.Courtney   */
/* 06-14-04...Removed Open/Close APIs and re-implemented Init API      */
/*            Also redocumented...........................C.Courtney   */
/*                                                                     */
/* DESCRIPTION:                                                        */
/* This file contains various function defeinitions that define a      */
/* IDMA (Internal DMA) for GEM. Functions for Channel0 contain         */
/* support for transferring from GEM internal memory to memory         */
/* hooked to Config space. Channel 1 functions contain support         */
/* for paging from local memories. These may be from Level 1           */
/* data memory to Level 2 memory or shared L2 memory.                  */
/*                                                                     */
/* PRIVATE DATA STRUCTURES:                                            */
/*                                                                     */
/* Private data structures are defined in the header file "idma.h"     */
/* and are shown below:                                                */
/*                                                                     */
/* typedef struct idma1_handle                                         */
/* {                                                                   */
/*     unsigned int status;                                            */
/*     unsigned int reserved;                                          */
/*     unsigned int *src;                                              */
/*     unsigned int *dst;                                              */
/*     unsigned int cnt;                                               */
/* }IDMA1_handle;                                                      */
/*                                                                     */
/* This handle holds all the descriptors needed to issue a Channel 1   */
/* transfer. In the routines shown below, the cnt register             */
/* fields of this structure is used to hold information regarding      */
/* the priority of IDMA relative to CPU, and whether interrupt is      */
/* desired or not. Once these properties are set in the IDMA1_init()   */
/* function, all transfers performed on Channel 1, use this field      */
/* to submit transfers, unless they are re-configured again by         */
/* seperate calls to setpriority and setInt.                           */
/*                                                                     */
/* The following configuration structure holds all the fields needed   */
/* to describe a Channel 0 transfer and has trhe following structure.  */
/*                                                                     */
/* typedef struct idma0_config                                         */
/* {                                                                   */
/*    unsigned int   status;                                           */
/*    unsigned int   mask;                                             */
/*    unsigned int   *src;                                             */
/*    unsigned int   *dst;                                             */
/*    unsigned int   cnt;                                              */
/* }IDMA0_Config;                                                      */
/*                                                                     */
/* The "src" contains the start address in internal memory or          */
/* configspace, the "dst" contains the destination address in          */
/* configspace or internal memory respectively. Transfers from         */
/* configspace to configspace using Channel 1 will raise an            */
/* exception. The mask is a 32-bit field of 1-hot encoding of          */
/* registers to access within the 32-bit register window.  The cnt     */
/* register fields of this structure is used to hold information       */
/* regarding whether interrupt is desired or not. Along with the       */
/* the number of 32-bit fields will be transfered                      */
/*                                                                     */
/* FUNCTIONS SUPPORTED:                                                */
/*                                                                     */
/* CHANNEL 0:                                                          */
/*                                                                     */
/* void IDMA0_config( IDMA_Config *config): This function performs     */
/* a Channel 0 transfer using the paremeters contained in the          */
/* configuration structure pointer "config".                           */
/*                                                                     */
/* void IDMA0_configArgs                                               */
/* (                                                                   */
/*     Uint32 mask,                                                    */
/*     Uint32 *src,                                                    */
/*     Uint32 *dst,                                                    */
/*     Uint8  cnt                                                      */
/*  )                                                                  */
/*                                                                     */
/* This function issues a Channel 0 transfer from source "src"         */
/* to destination "dst" performing "cnt" 32-word transfers in          */
/* which the individual 32-word transfers are controlled by a          */
/* "1-hot" encoding in a 32-bit field "mask". "src" and "dst"          */
/* must be word aligned, cnt must be <=15.                             */
/*                                                                     */
/*                                                                     */
/* Uint32 IDMA0_getStatus(): This function returns the ACTV            */
/* and PEND bits.                                                      */
/*                                                                     */
/* Uint32 IDMA0_wait(): This function waits for all previous           */
/* transfers on Channel 0 to complete by waiting for ACTV == 0         */
/* && PEND==0.                                                         */
/*                                                                     */
/* int IDMA0_setInt(interrupt): This function is used to set           */
/* the IDMA to interrupt the DSP on completion.                        */
/*                                                                     */
/* CHANNEL 1:                                                          */
/*                                                                     */
/* int IDMA1_init(priority, interrupt): This function sets the         */
/* priority and interrupt for transfers on Channel 1, for all          */
/* further transfers. This returns the value of the formatted          */
/* IDMA1_COUNT.                                                        */
/*                                                                     */
/* int IDMA1_copy(src, dst, byteCnt): This function transfers          */
/* "byteCnt" bytes from source "src" to destination "dst".             */
/*                                                                     */
/* int IDMA1_fill(fillValue, dst, byteCnt): This function fills        */
/* destination "dst" with "byteCnt" bytes of the fill, contained       */
/* in fill_value (32-bit field". This requires the "byteCnt" to        */
/* be a multiple of four.                                              */
/*                                                                     */
/* Uint32 IDMA1_getStatus(): This function returns the ACTV and        */
/* PEND bits.                                                          */
/*                                                                     */
/* int IDMA1_wait(): This function waits to make sure that             */
/* all previous transfers on Channel 1 have completed by               */
/* waiting for ACTV==0 && PEND==0.                                     */
/*                                                                     */
/* int IDMA1_setPriority(priority): This function is used to           */
/* set the priority between CPU and IDMA. A value of 0x111             */
/* implies that CPU is higher priority than IDMA. A value              */
/* of 0x0 implies IDMA is higher priority than CPU. These are          */
/* the only values that are allowed.                                   */
/*                                                                     */
/* int IDMA1_setInt(interrupt): This function is used to set           */
/* the IDMA to interrupt the DSP on completion.                        */
/*                                                                     */
/*---------------------------------------------------------------------*/
/* Copyright, Texas Instruments Incorporated.... 1997-2005.            */
/*=====================================================================*/
/*  =========================================================
*   Copyright (c) Texas Instruments Inc 2002, 2003, 2004
*
*   Use of this software is controlled by the terms and conditions found
*   in the license agreement under which this software has been supplied
*   provided
*   ==========================================================
*/
/** @mainpage IDMA Module
*
* @section Introduction
*
* @subsection xxx Purpose and Scope
* The purpose of this document is to identify a set of common CSL APIs for
* the IDMA Module across various devices. The CSL developer
* is expected to refer to this document while implementing APIs for these
* modules . Some of the listed APIs may not be applicable to a given IDMA
*
*
*
* @subsection aaa Terms and Abbreviations
*   -# CSL     :  Chip Support Library
*   -# API     :  Application Programmer Interface
*   -# IDMA :  Bandwidth Management Module
*
* @subsection References
*   -# CSL 3.x Technical Requirements Specifications Version 0.5, dated
*       May 14th, 2003
*   -# L2 Controller and L1P Controller Specification (Revision 0.99.4 &1.01.0)
*
* @subsection Assumptions
*     The abbreviations CSL, IDMA have been used throughout this
*     document to refer to the C64Plus Bandwidth Management Module.
*/

/**
@defgroup CSL_IDMA_ENUM  Enumerated Data Types
@ingroup CSL_IDMA_API
*/
/**
@defgroup CSL_IDMA_API IDMA
*/
/**
@defgroup CSL_IDMA_DATASTRUCT  IDMA Data Structures
@ingroup CSL_IDMA_API
*/
/**
@defgroup CSL_IDMA_SYMBOL  Symbols
@ingroup CSL_IDMA_API
*/
/**
@defgroup CSL_IDMA_FUNCTION  Functions
@ingroup CSL_IDMA_API
*/

#ifndef _IDMA_GEM
#define _IDMA_GEM   1

#ifdef __cplusplus
extern "C" {
#endif

#include <csl.h>
#include <cslr_idma.h>
//#include <soc64plus.h>
#define CSL_IDMA_0_REGS           (0x01820000u)
/**@defgroup CSL_IDMA_CHAN IDMA Channel Specifier.
*  @ingroup CSL_IDMA_ENUM
@{*/
/** @brief Specifies which IDMA channel will be used
*
* Used to indicate which IDMA channel (0 or 1) will be used by API
*/
typedef enum {
    IDMA_CHAN_0 = 0,
    IDMA_CHAN_1 = 1
} IDMA_Chan;
/**
@}*/

/**@defgroup CSL_IDMA_INT_EN_ENUM IDMA Interrupt Enable Specifier.
*  @ingroup CSL_IDMA_ENUM
@{*/
/** @brief Specifies whether the interrupt event generation is enabled or
           disabled.
*
* Used to indicate whether the interrupt event generation is enabled
* or disabled.
*/

typedef enum {
    IDMA_INT_DIS    = 0,
    IDMA_INT_EN     = 1
} IDMA_intEn;
/**
@}*/

/**@defgroup CSL_IDMA_PRI_ENUM IDMA Priority Specifier.
*  @ingroup CSL_IDMA_ENUM
@{*/
/** @brief Specifies what priority level the IDMA channel is set to.
*
* Used to specify what priority level the IDMA channel is set to.
*/
typedef enum {
    IDMA_PRI_0 = CSL_IDMA_IDMA1_CNT_PRI_PRI0,
    IDMA_PRI_1 = CSL_IDMA_IDMA1_CNT_PRI_PRI1,
    IDMA_PRI_2 = CSL_IDMA_IDMA1_CNT_PRI_PRI2,
    IDMA_PRI_3 = CSL_IDMA_IDMA1_CNT_PRI_PRI3,
    IDMA_PRI_4 = CSL_IDMA_IDMA1_CNT_PRI_PRI4,
    IDMA_PRI_5 = CSL_IDMA_IDMA1_CNT_PRI_PRI5,
    IDMA_PRI_6 = CSL_IDMA_IDMA1_CNT_PRI_PRI6,
    IDMA_PRI_7 = CSL_IDMA_IDMA1_CNT_PRI_PRI7,
    IDMA_PRI_NULL = -1
}IDMA_priSet;
/**
@}*/

/*
* The pointer to this is passed to all IDMA CSL APIs.
* This structure has the fields required to configure IDMA for any test
* case/application. It should be initialized as per requirements of a
* test case/application and passed on to the setup function.
*/

/** @addtogroup CSL_IDMA_DATASTRUCT
*
* @{ */
/** @brief IDMA1_handle IDMA Channel 1 handle - Contains Status, Source and
* Destination locations and count for channel 1 transfer.
*/
typedef struct idma1_handle {
    unsigned int status;    /**< IDMA channel 0 status */
    unsigned int reserved;
    unsigned int *src;      /**< IDMA channel 0 source location */
    unsigned int *dst;      /**< IDMA channel 0 destination */
    unsigned int cnt;       /**< Number of bytes to be transfered */
}IDMA1_handle;
/**
@}
*/


/** @addtogroup CSL_IDMA_DATASTRUCT
*
* @{ */
/** @brief IDMA0_Config IDMA Channel 0 configuration - Contains Status, Mask,
*   Source and Destination locations and count for channel 0 (configuration)
*   transfer.
*/
typedef struct idma0_config {
    unsigned int   status;  /**< IDMA channel 0 status */
    unsigned int   mask;    /**< IDMA channel 0 mask value */
    unsigned int   *src;    /**< IDMA channel 0 source location */
    unsigned int   *dst;    /**< IDMA channel 0 destination */
    unsigned int   cnt;     /**< Number of bytes to be transfered */
}IDMA0_Config;
/**
@}
*/


typedef unsigned int    Status;
/** Pointer to the IDMA register overlay */
typedef CSL_IdmaRegs *CSL_idmaOvly;


/**
@defgroup CSL_IDMA1_INIT_API IDMA1 Initialization API
@ingroup CSL_IDMA_FUNCTION
@{*/
/** ===========================================================================
 *   @n@b IDMA1_init
 *
 *   @b Description
 *   @n This function obtains a priority and an interrupt flag and remembers
 *      them so that all future transfers on Channel 1 will use these
 *      priorities.  The priority is contained in the argument "priority" and
 *      interrupt flag in "interr".
 *      This function performs IDMA Channel 1 initialization by  setting the
 *      priority level and the enabling/disabling the interrupt event
 *      generation for the channel.
 *
 *   @b Arguments
 *   @verbatim
            priority        Priority 0-7 of handle

            interr          interrupt event generated on/off
     @endverbatim
 *
 *   <b> Return Value </b>  idma1_handle_priv.cnt
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
        Uint32        cnt1;

        // Initialize IDMA Channel 1
        // Set Chan 1 to have Priority 7 and Interrupt Event Gen On
        ...

        cnt1 = IDMA1_init(  IDMA_PRI_7, IDMA_INT_EN);

     @endverbatim
 * ============================================================================
 */
int IDMA1_init (
    IDMA_priSet priority,
    IDMA_intEn  interr
);
/**
@}
*/


/**
@defgroup CSL_IDMA1_COPY_API IDMA1 Copy API
@ingroup CSL_IDMA_FUNCTION
@{*/
/** ===========================================================================
 *   @n@b IDMA1_copy
 *
 *   @b Description
 *   @n IDMA1_copy() transfers "byteCnt" bytes from a source "src"
 *      to a destination "dst". It is assumed that both the source and
 *      destination addresses are in internal memory. Transfers from
 *      addresses that are not in the internal memory will raise an
 *      exception. No checking is performed by this function to check
 *      the correctness of any of the passed in arguments.
 *
 *      Used to transfer "byteCnt" bytes from source "src" to destination "dst"
 *
 *   @b Arguments
 *   @verbatim
            src        Pointer to the source address

            dst        Pointer to the destination address

            byteCnt    Number of bytes to be transferred.
     @endverbatim
 *
 *   <b> Return Value </b>  IDMA handle status.
 *   @li                    zero
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Modifies
 *   @n The hardware registers of IDMA.
 *
 *   @b Example
 *   @verbatim
        Uint32        src;
        Uint32        dst;

        ...

        // Copy src to dst1 - 80 bytes - 20 words
        IDMA1_copy(src, dst1, 80);
     @endverbatim
 * ============================================================================
 */
int IDMA1_copy (
    unsigned int *src,
    unsigned int *dst,
    unsigned int byteCnt
);
/**
@}
*/

/**
@defgroup CSL_IDMA1_FILL_API IDMA1 Fill API
@ingroup CSL_IDMA_FUNCTION
@{*/
/** ===========================================================================
 *   @n@b IDMA1_fill
 *
 *   @b Description
 *   @n IDMA1_fill() Takes a fill value in "fill_value" and fills
 *      "byteCnt" bytes of the "fill_value" to destination "dst".
 *
 *       Used to write "byteCnt" bytes of the fill value "fill_value" to
 *       destination "dst"
 *
 *   @b Arguments
 *   @verbatim
            dst        Pointer to the destination address

            byteCnt    Number of bytes to be transferred.
            
            fill_value Data to be filled
            
     @endverbatim
 *
 *   <b> Return Value </b>  IDMA handle status.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Modifies
 *   @n The hardware registers of IDMA.
 *
 *   @b Example
 *   @verbatim
        Uint32        dst1;

        ...

        IDMA1_fill(dst1, 0x800, 0xAAAABABA);
     @endverbatim
 * ============================================================================
 */
int IDMA1_fill (
    unsigned int *dst,
    unsigned int byteCnt,
    unsigned int fill_value
);
/**
@}
*/

/**
@defgroup CSL_IDMA1_GET_STATUS_API IDMA1 Get Status API
@ingroup CSL_IDMA_FUNCTION
@{*/
/** ===========================================================================
 *   @n@b IDMA1_getStatus
 *
 *   @b Description
 *   @n IDMA1_getStatus() gets the active and pending status of IMDA    
 *      Channel 1 and returns ACTV in the least significant bit and PEND
 *      in the 2nd least significant bit                   
 *
 *      Gets the active and pending status of IDMA channel 1
 *
 *   @b Arguments
 *   @n  None
 *
 *   <b> Return Value </b>  IDMA channel 1 status.
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
        Uint32        stat;
        
        ...
        
        stat = IDMA1_getStatus();
     @endverbatim
 * ============================================================================
 */
Uint32 IDMA1_getStatus(void);
/**
@}
*/

/**
@defgroup CSL_IDMA1_WAIT_API IDMA1 Wait API
@ingroup CSL_IDMA_FUNCTION
@{*/
/** ===========================================================================
 *   @n@b IDMA1_wait
 *
 *   @b Description
 *   @n IDMA1_wait() waits until all previous transfers for IDMA Channel
 *      1 have been completed by making sure that both active and pend  
 *      bits are zero. These are the two least significant bits of the  
 *      status register for the channel.                                
 *
 *      Waits until previous transfers have completed for IDMA channel 1
 *      before returning.
 *
 *   @b Arguments
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
 *   @n  None
 *
 *   @b Example
 *   @verbatim
        Uint32        stat;
        
        ...
        
        stat = IDMA1_getStatus();
        IDMA1_wait();
     @endverbatim
 * ============================================================================
 */
void IDMA1_wait(void);
/**
@}
*/

/**
@defgroup CSL_IDMA1_SET_PRIORITY_API IDMA1 Set Priority API
@ingroup CSL_IDMA_FUNCTION
@{*/
/** ===========================================================================
 *   @n@b IDMA1_setPriority
 *
 *   @b Description
 *   @n IDMA1_setPriority()  sets a "3-bit" priority field which has 
 *      a valid range of 0-7 for priorities 0-7. It returns the a    
 *      "32-bit" count register field back to the user. This 32-bit  
 *      register field will be used in IDMA1_copy() and IDMA1_fill() 
 *      to program the Priority and Interrupt options for IDMA Chan 1
 *
 *      Sets the priority level for IDMA channel 1 transfers
 *
 *   @b Arguments
 *   @verbatim
            priority        Priority 0-7 of handle
            
     @endverbatim
 *
 *   <b> Return Value </b>  idma1_handle_priv.cnt
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
        Uint32        tempCnt;

        ...

        // Set and test Priority level for IDMA1
        tempCnt = IDMA1_setPriority(IDMA_PRI_2);
     @endverbatim
 * ============================================================================
 */
int IDMA1_setPriority(
    IDMA_priSet priority
);
/**
@}
*/

/**
@defgroup CSL_IDMA1_SET_PRIORITY_API IDMA1 Set Priority API
@ingroup CSL_IDMA_FUNCTION
@{*/
/** ===========================================================================
 *   @n@b IDMA1_setInt
 *
 *   @b Description
 *   @n IDMA1_setInt()  sets a the interrupt enable field which       
 *      is used to enable/disable interrupts for IDMA Channel 1.      
 *      It returns the a "32-bit" count register field back to the    
 *      user. This 32-bit register field will be used in IDMA1_copy() 
 *      and IDMA1_fill() to program the Priority and Interrupt options
 *      for IDMA Channel 1                                            
 *
 *      Enables/Disables interrupt event generation for IDMA channel 1 
 *      transfers
 *
 *   @b Arguments
 *   @verbatim
            interr        interrupt event generated on/off
            
     @endverbatim
 *
 *   <b> Return Value </b>  idma1_handle_priv.cnt
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
        Uint32        tempCnt;

        ...

        // Set and test Interrupt event gen for IDMA1 
        tempCnt = IDMA1_setInt(IDMA_INT_DIS);
     @endverbatim
 * ============================================================================
 */
int IDMA1_setInt(
    IDMA_intEn interr
);
/**
@}
*/

/**
@defgroup CSL_IDMA0_INIT_API IDMA0 Initialization API
@ingroup CSL_IDMA_FUNCTION
@{*/
/** ===========================================================================
 *   @n@b IDMA0_init
 *
 *   @b Description
 *   @n This function obtains a interrupt enable setting and    
 *      remembers them so that all future transfers on Channel 0
 *      generate interrupts or not.                             
 *      Initializes the Interrupt Event Generation for IDMA Channel 0
 *
 *   @b Arguments
 *   @verbatim
            interr        interrupt event generated on/off
            
     @endverbatim
 *
 *   <b> Return Value </b>  idma0_configHandle_priv.cnt
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
        Uint32        cnt0;

        ...

        // Initialize IDMA Channel 0           
        // Set Chan 0 to have Interrupt Event Gen On 
        cnt0 = IDMA0_init(IDMA_INT_EN);
        
     @endverbatim
 * ============================================================================
 */
int IDMA0_init (
    IDMA_intEn  interr
);
/**
@}
*/

/**
@defgroup CSL_IDMA0_CONFIG_API IDMA0 Configuration API
@ingroup CSL_IDMA_FUNCTION
@{*/
/** ===========================================================================
 *   @n@b IDMA0_config
 *
 *   @b Description
 *   @n IDMA0_config() - Configures IMDA Channel 0 to perform a transfer
 *      between Internal Memory and Configuration Space based on the    
 *      data in the *config structure.  "mask" provides a 1-hot encoding
 *      for the 32-word tranfer that determines which of the 32-words   
 *      are to be transfered.  In the *config structure "src" provides  
 *      the source location of the transfer and "dst provides the       
 *      destination location of the transfer and both must be word      
 *      aligned. While "cnt" provides the number of 32-word transfers to
 *      perform and must not be greater than 15.            
 *        Initializes the configuration for IDMA Channel 0  including 1-hot 
 *      encoding mask, source location, destination location  and count.  
 *      This is done using the structure IDMA0_Config.            
 *
 *   @b Arguments
 *   @verbatim
            config        Pointer to the Configuration structure
            
     @endverbatim
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
 *   @n The hardware registers of IDMA.
 *
 *   @b Example
 *   @verbatim
        IDMA0_Config   config
        ...
        
        IDMA0_config(&config);
        IDMA0_wait();
        
     @endverbatim
 * ============================================================================
 */
void IDMA0_config(
    IDMA0_Config *config
);
/**
@}
*/

/**
@defgroup CSL_IDMA0_CONFIG_ARGS_API IDMA0 Configuration Args API
@ingroup CSL_IDMA_FUNCTION
@{*/
/** ===========================================================================
 *   @n@b IDMA0_configArgs
 *
 *   @b Description
 *   @n IDMA0_configArgs() - Configures IMDA Channel 0 to perform a     
 *      transfer between Internal Memory and Configuration Space based  
 *      on the inputs to the function.  "mask" provides a 1-hot encoding
 *      for the 32-word tranfer that determines which of the 32-words   
 *      are to be transfered.  "src" provides the source location of the
 *      transfer and "dst provides the destination location of the      
 *      transfer and both must be word aligned. While "cnt" provides the
 *      number of 32-word transfers to perform and must not be greater  
 *      than 15.                                                        
 *        Initializes the configuration for IDMA Channel 0 including 1-hot 
 *      encoding mask, source location, destination location and count.
 *
 *   @b Arguments
 *   @verbatim
            mask        encoding value for the 32-word tranfer 
            
            src         Pointer to the source location of the transfer
            
            dst         Pointer to the destination location of the transfer
            
            cnt         number of 32-word transfers 
            
     @endverbatim
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
 *   @n The hardware registers of IDMA.
 *
 *   @b Example
 *   @verbatim
        Uint32  src,dst;
        Uint32  mask;
        ...
        
        IDMA0_configArgs(mask, src, dst, 1);
        IDMA0_wait();
        
     @endverbatim
 * ============================================================================
 */
void IDMA0_configArgs (
    unsigned int  mask,
    unsigned int  *src,
    unsigned int  *dst,
    unsigned int  cnt
);
/**
@}
*/

/**
@defgroup CSL_IDMA0_GET_STATUS_API IDMA0 Get Status API
@ingroup CSL_IDMA_FUNCTION
@{*/
/** ===========================================================================
 *   @n@b IDMA0_getStatus
 *
 *   @b Description
 *   @n IDMA0_getStatus() gets the active and pending status of IMDA    
 *      Channel 0 and returns ACTV in the least significant bit and PEND
 *      in the 2nd least significant bit                                
 *
 *      Gets the active and pending status of IDMA channel 0
 *
 *   @b Arguments
 *   @n  None
 *
 *   <b> Return Value </b>  IDMA channel 0 status.
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
        Uint32        stat;
        
        ...
        
        stat = IDMA0_getStatus();
     @endverbatim
 * ============================================================================
 */
Uint32 IDMA0_getStatus(void);
/**
@}
*/

/**
@defgroup CSL_IDMA0_WAIT_API IDMA0 Wait API
@ingroup CSL_IDMA_FUNCTION
@{*/
/** ===========================================================================
 *   @n@b IDMA0_wait
 *
 *   @b Description
 *   @n IDMA0_wait() waits until all previous transfers for IDMA Channel
 *      0 have been completed by making sure that both active and pend  
 *      bits are zero. These are the two least significant bits of the  
 *      status register for the channel.                                
 *
 *      Waits until previous transfers have completed for IDMA channel 0
 *      before returning.
 *
 *   @b Arguments
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
 *   @n  None
 *
 *   @b Example
 *   @verbatim
        Uint32        stat;
        
        ...
        
        stat = IDMA0_getStatus();
        IDMA0_wait();
     @endverbatim
 * ============================================================================
 */
void IDMA0_wait(void);
/**
@}
*/

/**
@defgroup CSL_IDMA0_SET_INTERRUPT_API IDMA0 Set Interrupt Enable API
@ingroup CSL_IDMA_FUNCTION
@{*/
/** ===========================================================================
 *   @n@b IDMA0_setInt
 *
 *   @b Description
 *   @n IDMA0_setInt()  sets a the interrupt enable field which       
 *      is used to enable/disable interrupts for IDMA Channel 0.      
 *      It returns the a "32-bit" count register field back to the    
 *      user. This 32-bit register field will be used in              
 *      IDMA0_config() and IDMA0_configArgs() to program the Interrupt
 *      option for IDMA Channel 0                                     
 *
 *      Enables/Disables interrupt event generation for IDMA channel 0 
 *      transfers
 *
 *   @b Arguments
 *   @verbatim
            interr        interrupt event generated on/off
            
     @endverbatim
 *
 *   <b> Return Value </b>  idma0_handle_priv.cnt
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
        Uint32        tempCnt;

        ...

        // Set and test Interrupt event gen for IDMA0 
        tempCnt = IDMA0_setInt(IDMA_INT_DIS);
     @endverbatim
 * ============================================================================
 */
int IDMA0_setInt(
    IDMA_intEn interr
);
/**
@}
*/

/*================================================================*/
/* Texas Instruments Incorporated 1997-2005.                      */
/*----------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif
