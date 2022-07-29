/*  ============================================================================
 *   Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005
 *
 *   Use of this software is controlled by the terms and conditions found in the
 *   license agreement under which this software has been supplied.
 *   ===========================================================================
 */

/** @file csl_edmaAux.h
 *
 *    @brief    Header file for functional layer CSL of EDMA
 *
 *  Description
 *    - This file contains inline functions definitions.
 */

/*   ==========================================================
 *   @file  csl_edmaAux.h
 *
 *	@brief    Header file for functional layer CSL of EDMA
 *
 *  Description
 *    - This file contains inline functions definitions.
 *
 *   @path  $(CSLPATH)\\src\\armedma
 *
 *   @desc  EDMA module
 *   Modification : 15th July 2004
 *   Modified function
 *   CSL_edmaChannelMapParamEntry to default the trigger word to 7
 *
 */
#ifndef _CSL_EDMAAUX_H_
#define _CSL_EDMAAUX_H_

#include <csl_edma.h>
#include <socEdma.h>
#include <soc64plus.h>

/**
@addtogroup CSL_EDMA_FUNCTION_CHANNEL_INTERNAL
@{
*/
//pragma CODE_SECTION (CSL_edmaChannelQueryParamMap, ".text:csl_section:edma");

/** =============================================================================
 *   @n@b   CSL_edmaChannelQueryParamMap
 *
 *   @b Description
 *   @n Queries the parameter Entry associated with the channe.
 *
 *   @b Arguments
 *   @verbatim

            hCh        Channel Handle

     @endverbatim
 *
 *   <b> Return Value   
 *   @li                  paramEntry 
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaInit() must be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 *
 *  <b> Usage Constraints: </b>
 *  All @a CSL_edmaInit(), @a CSL_edmaOpen(), @a CSL_edmaChannelOpen() must be
 *  invoked successfully in that order before @a CSL_edmaChannelQueryParamMap()
 *  can  be invoked. If the channel is opened in context of a Region,
 *  @a CSL_edmaRegionOpen() may also need to be invoked before this API.
 *
 *  @b Example:
 *   @verbatim
    CSL_EdmaChanObj ChObj;
    CSL_EdmaChanHandle chHndl;
    CSL_EdmaHwChannelSetup chParam;
    CSL_EdmaHandle     hModHndl;
    CSL_Status modStatus;
    Uint32 paramMap;
    // Initialization
    modStatus = CSL_edmaInit(NULL);
    ...
    // Open Module
    hModHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);

    // Open Channel 0
    chParam.regionNum = CSL_EDMA_REGION_GLOBAL;
    chParam.chaNum = CSL_EDMA_CHA0;
    chHndl = CSL_edmaChannelOpen(&ChObj,
                            CSL_EDMA_0,
                            &chParam,
                            &edmaStatus);

    paramMap = CSL_edmaChannelQueryParamMap(chHndl);
     @endverbatim
 *
 * ===========================================================================
 */
CSL_IDEF_INLINE Uint32  CSL_edmaChannelQueryParamMap(
    /**  a handle to the requested channel instance of the specified EDMA
     *   obtained  through @a CSL_edmaChannelOpen() call */
    CSL_EdmaChanHandle         hEdma
)
{

    Uint32 paramEntry;
    if (hEdma->chaNum  < CSL_EDMA_NUM_DMACH){
#if CSL_EDMA_CHMAPEXIST
        paramEntry = CSL_FEXT(hEdma->ccregs->DCHMAP[hEdma->chaNum],
                              EDMACC_DCHMAP_PAENTRY);
#endif
    } else
        paramEntry =
            CSL_FEXT(hEdma->ccregs->QCHMAP[hEdma->chaNum - CSL_EDMA_NUM_DMACH],
                     EDMACC_QCHMAP_PAENTRY);
    return paramEntry;
}

/* top level control internal API */

/** =============================================================================
 *   @n@b   CSL_edmaHwChannelEnable
 *
 *   @b Description
 *   @n This API enables the event associated with the Channel
 *
 *   @b Arguments
 *   @verbatim

            hCh        Channel Handle

     @endverbatim
 *
 *   <b> Return Value   CSL_Status
 *   @li                    CSL_SOK            - Always returns
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaInit() must be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 *
 *  <b> Usage Constraints: </b>
 *  All @a CSL_edmaInit(), @a CSL_edmaOpen(), @a CSL_edmaChannelOpen() must be
 *  invoked successfully in that order before @a CSL_edmaChannelEnable() can
 *  be invoked. If the channel is opened in context of a Region,
 *  @a CSL_edmaRegionOpen() may also need to be invoked before this API. If a
 *  Shadow region is used then care of the  DRAE settings must be taken.
 *
 *  @b Example:
 *   @verbatim
    
    // Initialization
    CSL_EdmaChanObj ChObj;
    CSL_EdmaChanHandle chHndl;
    CSL_EdmaHwChannelSetup chParam;
    CSL_EdmaHandle     hModHndl;
    CSL_Status modStatus;
    Uint32 paramMap;
    // Initialization
    modStatus = CSL_edmaInit(NULL);
    ...
    // Open Module
    hModHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);

    // Open Channel 0
    chParam.regionNum = CSL_EDMA_REGION_GLOBAL;
    chParam.chaNum = CSL_EDMA_CHA0;
    chHndl = CSL_edmaChannelOpen(&ChObj,
                            CSL_EDMA_0,
                            &chParam,
                            &edmaStatus);

   status = CSL_edmaHwChannelEnable(chHndl);
     @endverbatim
 *
 * ===========================================================================
 */
//#pragma CODE_SECTION (CSL_edmaChannelEnable, ".text:csl_section:edma");
CSL_IDEF_INLINE CSL_Status  CSL_edmaChannelEnable(
    /**  a handle to the EDMA channel instance obtained  through
         the @a CSL_edmaChannelOpen() call */
    CSL_EdmaChanHandle         hEdma
)
{
    /* Ensure this is a normal channel and not a QDMA channel */
    if (hEdma->region == -1) {
        if (hEdma->chaNum >= CSL_EDMA_NUM_DMACH)
            hEdma->ccregs->QEESR = (1 << (hEdma->chaNum - CSL_EDMA_NUM_DMACH));
        else if (hEdma->chaNum < 32)
            hEdma->ccregs->EESR = (1 << hEdma->chaNum);
        else
            hEdma->ccregs->EESRH = (1 << (hEdma->chaNum - 32));
    } else {
        if (hEdma->chaNum >= CSL_EDMA_NUM_DMACH)
            hEdma->ccregs->SHADOW[hEdma->region].QEESR =
                (1 << (hEdma->chaNum - CSL_EDMA_NUM_DMACH));
        else if (hEdma->chaNum < 32)
            hEdma->ccregs->SHADOW[hEdma->region].EESR = (1 << hEdma->chaNum);
        else
            hEdma->ccregs->SHADOW[hEdma->region].EESRH =
                                                (1 << (hEdma->chaNum - 32));
    }
    return CSL_SOK;
}

/** =============================================================================
 *   @n@b   CSL_edmaHwChannelDisable
 *
 *   @b Description
 *   @n This API disables the event associated with the Channel
 *
 *   @b Arguments
 *   @verbatim

            hCh        Channel Handle

     @endverbatim
 *
 *   <b> Return Value   CSL_Status
 *   @li                    CSL_SOK            - Always returns
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaInit() must be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 *
 *  <b> Usage Constraints: </b>
 *  All @a CSL_edmaInit(), @a CSL_edmaOpen(), @a CSL_edmaChannelOpen() must be
 *  invoked successfully in that order before @a CSL_edmaHwChannelDisable() can
 *  be invoked. If the channel is opened in context of a Region,
 *  @a CSL_edmaRegionOpen() may also need to be invoked before this API. If a
 *  Shadow region is used then care of the DRAE settings must be taken.
 *
 *  @b Example:
 *   @verbatim

    CSL_EdmaChanObj ChObj;
    CSL_EdmaChanHandle chHndl;
    CSL_EdmaHwChannelSetup chParam;
    CSL_EdmaHandle     hModHndl;
    CSL_Status modStatus;
    Uint32 paramMap;
    // Initialization
    modStatus = CSL_edmaInit(NULL);
    ...
    // Open Module
    hModHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);

    // Open Channel 0
    chParam.regionNum = CSL_EDMA_REGION_GLOBAL;
    chParam.chaNum = CSL_EDMA_CHA0;
    chHndl = CSL_edmaChannelOpen(&ChObj,
                            CSL_EDMA_0,
                            &chParam,
                            &edmaStatus);

    status = CSL_edmaHwChannelDisable(chHndl);
     @endverbatim
 *
 * ===========================================================================
 */
//#pragma CODE_SECTION (CSL_edmaChannelDisable, ".text:csl_section:edma");
CSL_IDEF_INLINE CSL_Status  CSL_edmaChannelDisable(
    /**  a handle to the requested channel instance of the specified EDMA
     *   obtained  through the @a CSL_edmaChannelOpen() call */
    CSL_EdmaChanHandle         hEdma
)
{
    /* Ensure this is a normal channel and not a QDMA channel */
    if (hEdma->region == -1) {
        if (hEdma->chaNum >= CSL_EDMA_NUM_DMACH)
            hEdma->ccregs->QEECR = (1 << (hEdma->chaNum - CSL_EDMA_NUM_DMACH));
        else if (hEdma->chaNum < 32)
            hEdma->ccregs->EECR = (1 << hEdma->chaNum);
        else
            hEdma->ccregs->EECRH = (1 << (hEdma->chaNum - 32));
    } else {
        if (hEdma->chaNum >= CSL_EDMA_NUM_DMACH)
            hEdma->ccregs->SHADOW[hEdma->region].QEECR =
                            (1 << (hEdma->chaNum - CSL_EDMA_NUM_DMACH));
        else if (hEdma->chaNum < 32)
            hEdma->ccregs->SHADOW[hEdma->region].EECR = (1 << hEdma->chaNum);
        else
            hEdma->ccregs->SHADOW[hEdma->region].EECRH =
                                                (1 << (hEdma->chaNum - 32));
    }
    return CSL_SOK;
}

/** =============================================================================
 *   @n@b   CSL_edmaChannelEventSet
 *
 *   @b Description
 *   @n Manually triggers an EDMA event by setting the ER register
 *
 *   @b Arguments
 *   @verbatim

            hCh        Channel Handle

     @endverbatim
 *
 *   <b> Return Value   CSL_Status
 *   @li                    CSL_SOK            - Always returns
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaInit() must be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 *
 *  <b> Usage Constraints: </b>
 *  All @a CSL_edmaInit(), @a CSL_edmaOpen(), @a CSL_edmaChannelOpen() must be
 *  invoked successfully in that order before @a CSL_edmaChannelMapParamEntry()
 *   can be invoked. If the channel is opened in context of a Region,
 *  @a CSL_edmaRegionOpen() may also need to be invoked before this API. If a
 *  Shadow region is used then care of the DRAE settings must be taken.
 *
 *  @b Example:
 *   @verbatim

    CSL_EdmaChanObj ChObj;
    CSL_EdmaChanHandle chHndl;
    CSL_EdmaHwChannelSetup chParam;
    CSL_EdmaHandle     hModHndl;
    CSL_Status modStatus;
    Uint32 paramMap;
    // Initialization
    modStatus = CSL_edmaInit(NULL);
    ...
    // Open Module
    hModHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);

    // Open Channel 0
    chParam.regionNum = CSL_EDMA_REGION_GLOBAL;
    chParam.chaNum = CSL_EDMA_CHA0;
    chHndl = CSL_edmaChannelOpen(&ChObj,
                            CSL_EDMA_0,
                            &chParam,
                            &edmaStatus);

    status = CSL_edmaHwEventSet(chHndl);
     @endverbatim
 *
 * ===========================================================================
 */
//#pragma CODE_SECTION (CSL_edmaChannelEventSet, ".text:csl_section:edma");
CSL_IDEF_INLINE CSL_Status  CSL_edmaChannelEventSet(
    /**  a handle to the requested channel instance of the specified EDMA
     *   obtained  through the @a CSL_edmaChannelOpen() call */
    CSL_EdmaChanHandle         hEdma
)
{
    if (hEdma->region == -1)
    {
        if (hEdma->chaNum < 32)
            hEdma->ccregs->ESR = (1 << hEdma->chaNum);
        else if (hEdma->chaNum < CSL_EDMA_NUM_DMACH)
            hEdma->ccregs->ESRH = (1 << (hEdma->chaNum - 32));
        else
            return CSL_ESYS_INVPARAMS;
    } else {
        if (hEdma->chaNum < 32)
            hEdma->ccregs->SHADOW[hEdma->region].ESR = (1 << hEdma->chaNum);
        else if (hEdma->chaNum < CSL_EDMA_NUM_DMACH)
            hEdma->ccregs->SHADOW[hEdma->region].ESRH =
                                            (1 << (hEdma->chaNum - 32));
        else
            return CSL_ESYS_INVPARAMS;
    }
    return CSL_SOK;
}

/** =============================================================================
 *   @n@b   CSL_edmaChannelEventClear
 *
 *   @b Description
 *   @n Clears the EDMA event by writing the ECR register for normal channels
 *      for QDMA channels
 *
 *   @b Arguments
 *   @verbatim

            hCh        Channel Handle

     @endverbatim
 *
 *   <b> Return Value   CSL_Status
 *   @li                    CSL_SOK            - Always returns
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaInit() must be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 *
 *  <b> Usage Constraints: </b>
 *  All @a CSL_edmaInit(), @a CSL_edmaOpen(), @a CSL_edmaChannelOpen() must be
 *  invoked successfully in that order before @a CSL_edmaChannelEventClear()
 *  can be invoked. If the channel is opened in context of a Region,
 *  @a CSL_edmaRegionOpen() may also need to be invoked before this API. If a
 *  Shadow region is used then care of the DRAE settings must be taken.
 *
 *  @b Example:
 *   @verbatim

    CSL_EdmaChanObj ChObj;
    CSL_EdmaChanHandle chHndl;
    CSL_EdmaHwChannelSetup chParam;
    CSL_EdmaHandle     hModHndl;
    CSL_Status modStatus;
    Uint32 paramMap;
    // Initialization
    modStatus = CSL_edmaInit(NULL);
    ...
    // Open Module
    hModHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);

    // Open Channel 0
    chParam.regionNum = CSL_EDMA_REGION_GLOBAL;
    chParam.chaNum = CSL_EDMA_CHA0;
    chHndl = CSL_edmaChannelOpen(&ChObj,
                            CSL_EDMA_0,
                            &chParam,
                            &edmaStatus);

    status = CSL_edmaChannelEventClear(chHndl);
     @endverbatim
 *
 * ===========================================================================
 */
//#pragma CODE_SECTION (CSL_edmaChannelEventSet, ".text:csl_section:edma");
CSL_IDEF_INLINE CSL_Status  CSL_edmaChannelEventClear(
    /**  a handle to the requested channel instance of the specified EDMA
     *   obtained  through the @a CSL_edmaChannelOpen() call */
    CSL_EdmaChanHandle         hEdma
)
{
    if (hEdma->region == -1) {
        if (hEdma->chaNum >= CSL_EDMA_NUM_DMACH)
            return CSL_ESYS_INVPARAMS;
        else if (hEdma->chaNum < 32)
            hEdma->ccregs->ECR = (1 << hEdma->chaNum);
        else
            hEdma->ccregs->ECRH = (1 << (hEdma->chaNum - 32));
    } else {
        if (hEdma->chaNum >= CSL_EDMA_NUM_DMACH)
            return CSL_ESYS_INVPARAMS;
        else if (hEdma->chaNum < 32)
            hEdma->ccregs->SHADOW[hEdma->region].ECR = (1 << hEdma->chaNum);
        else
            hEdma->ccregs->SHADOW[hEdma->region].ECRH =
                                                (1 << (hEdma->chaNum - 32));
    }
    return CSL_SOK;
}

/** =============================================================================
 *   @n@b   CSL_edmaChannelMapParamEntry
 *
 *   @b Description
 *   @n Maps the channel to a given parameter entry
 *
 *   @b Arguments
 *   @verbatim

            hCh        Channel Handle

     @endverbatim
 *
 *   <b> Return Value   CSL_Status
 *   @li                    CSL_SOK            - Always returns
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaInit() must be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 *
 *  <b> Usage Constraints: </b>
 *  All @a CSL_edmaInit(), @a CSL_edmaOpen(), @a CSL_edmaChannelOpen() must be
 *  invoked successfully in that order before @a CSL_edmaChannelMapParamEntry()
 *  can  be invoked. If the channel is opened in context of a Region,
 *  @a CSL_edmaRegionOpen() may also need to be invoked before this API.
 *
 *  @b Example:
 *   @verbatim

    CSL_EdmaChanObj ChObj;
    CSL_EdmaChanHandle chHndl;
    CSL_EdmaHwChannelSetup chParam;
    CSL_EdmaHandle     hModHndl;
    CSL_Status modStatus;
    Uint32 paramMap;
    // Initialization
    modStatus = CSL_edmaInit(NULL);
    ...
    // Open Module
    hModHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);

    // Open Channel 0
    chParam.regionNum = CSL_EDMA_REGION_GLOBAL;
    chParam.chaNum = CSL_EDMA_CHA0;
    chHndl = CSL_edmaChannelOpen(&ChObj,
                            CSL_EDMA_0,
                            &chParam,
                            &edmaStatus);

    status = CSL_edmaChannelMapParamEntry(chHndl, 6);
     @endverbatim
 *
 * ===========================================================================
 */
//#pragma CODE_SECTION (CSL_edmaChannelMapParamEntry, ".text:csl_section:edma");
CSL_IDEF_INLINE CSL_Status CSL_edmaChannelMapParamEntry(
    /**  a handle to the requested channel instance of the specified EDMA
     *   obtained  through the @a CSL_edmaChannelOpen() call */
    CSL_EdmaChanHandle hEdma,
    /** Param entry number */
    Uint32 paramEntry
)
{
    if (hEdma->chaNum  < CSL_EDMA_NUM_DMACH) {
#if CSL_EDMA_CHMAPEXIST
        CSL_FINS(hEdma->ccregs->DCHMAP[hEdma->chaNum], EDMACC_DCHMAP_PAENTRY,\
                    paramEntry);
#endif
    } else
        hEdma->ccregs->QCHMAP[hEdma->chaNum-CSL_EDMA_NUM_DMACH] = \
                    CSL_FMK(EDMACC_QCHMAP_PAENTRY,paramEntry) |   \
                    CSL_FMK(EDMACC_QCHMAP_TRWORD,7);
    return CSL_SOK;
}

/** =============================================================================
 *   @n@b   CSL_edmaChannelSetTrigWord
 *
 *   @b Description
 *   @n This API maps the channel to paRam entry
 *
 *   @b Arguments
 *   @verbatim

            hCh        Channel Handle

     @endverbatim
 *
 *   <b> Return Value   CSL_Status
 *   @li                    CSL_SOK            - Always returns
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaInit() must be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 *
 * <b> Usage Constraints: </b>
 * All @a CSL_edmaInit(), @a CSL_edmaOpen(), @a CSL_edmaChannelOpen() must be
 * invoked successfully in that order before @a CSL_edmaChannelSetTrigWord() can 
 *  be invoked. If the channel is opened in context of a Region, @a
 *  CSL_edmaRegionOpen() may also need to be invoked before this API.
 *
 *
 * @b Example:
 *   @verbatim

    CSL_EdmaChanObj ChObj;
    CSL_EdmaChanHandle chHndl;
    CSL_EdmaHwChannelSetup chParam;
    CSL_EdmaHandle     hModHndl;
    CSL_Status modStatus;
    Uint32 paramMap;
    // Initialization
    modStatus = CSL_edmaInit(NULL);
    ...
    // Open Module
    hModHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);

    // Open Channel 0
    chParam.regionNum = CSL_EDMA_REGION_GLOBAL;
    chParam.chaNum = CSL_EDMA_CHA0;
    chHndl = CSL_edmaChannelOpen(&ChObj,
                            CSL_EDMA_0,
                            &chParam,
                            &edmaStatus);


    // Setting the Trigger word to be te last one
    status = CSL_edmaChannelSetTrigWord(chHndl, 7);
     @endverbatim
 *
 * ===========================================================================
 */
//#pragma CODE_SECTION (CSL_edmaChannelSetTrigWord, ".text:csl_section:edma");
CSL_IDEF_INLINE CSL_Status  CSL_edmaChannelSetTrigWord(
    /**  a handle to the requested channel instance of the specified EDMA
     *   obtained  through the @a CSL_edmaChannelOpen() call */
    CSL_EdmaChanHandle hEdma,
    /**  trigger word */
    Uint32             trigWord
)
{
    if (hEdma->chaNum  < CSL_EDMA_NUM_DMACH)
        return CSL_ESYS_INVPARAMS;
    else
        CSL_FINS(hEdma->ccregs->QCHMAP[hEdma->chaNum - CSL_EDMA_NUM_DMACH],
                 EDMACC_QCHMAP_TRWORD, trigWord);
    return CSL_SOK;
}

/** =============================================================================
 *   @n@b   CSL_edmaChannelSetEvtQue
 *
 *   @b Description
 *   @n Sets the Channel to the Event Queue specified
 *
 *   @b Arguments
 *   @verbatim

            hCh        Channel Handle

     @endverbatim
 *
 *   <b> Return Value   CSL_Status
 *   @li                    CSL_SOK            - Always returns
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaInit() must be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 *
 * <b> Usage Constraints: </b>
 * All @a CSL_edmaInit(), @a CSL_edmaOpen(), @a CSL_edmaChannelOpen() must be
 * invoked successfully in that order before @a CSL_edmaChannelSetEvtQue() can
 *  be invoked. If the channel is opened in context of a Region,
 *  @a CSL_edmaRegionOpen() may also need to be invoked before this API.
 *
 *
 * @b Example:
 *   @verbatim

    CSL_EdmaChanObj ChObj;
    CSL_EdmaChanHandle chHndl;
    CSL_EdmaHwChannelSetup chParam;
    CSL_EdmaHandle     hModHndl;
    CSL_Status modStatus;
    Uint32 paramMap;
    // Initialization
    modStatus = CSL_edmaInit(NULL);
    ...
    // Open Module
    hModHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);

    // Open Channel 0
    chParam.regionNum = CSL_EDMA_REGION_GLOBAL;
    chParam.chaNum = CSL_EDMA_CHA0;
    chHndl = CSL_edmaChannelOpen(&ChObj,
                            CSL_EDMA_0,
                            &chParam,
                            &edmaStatus);


   // EDMA Chanbnel 0 is submitted to Event queue 3
   status = CSL_edmaChannelSetEvtQue(chHndl, CSL_EDMA_EVT_QUE3);
     @endverbatim
 *
 * ===========================================================================
 */
//#pragma CODE_SECTION (CSL_edmaChannelSetEvtQue, ".text:csl_section:edma");
CSL_IDEF_INLINE CSL_Status CSL_edmaChannelSetEvtQue(
    /**  a handle to the requested channel instance of the specified EDMA
     *   obtained  through the @a CSL_edmaChannelOpen() call */
    CSL_EdmaChanHandle hEdma,
    /**  event queue number
    */
    CSL_EdmaEventQueue evtQue
)
{
    Uint32 _cha, _qNumIndex, _qchMap;
    if (hEdma->chaNum >= CSL_EDMA_NUM_DMACH) {
    /*  Extracting the Channel Number in case of QDMA */
        _cha = hEdma->chaNum - CSL_EDMA_NUM_DMACH;
    /*  Channel to Event Queue mapping */
        CSL_FINSR(hEdma->ccregs->QDMAQNUM,_cha*4 + 2,_cha*4,evtQue);
    } else {
    /*  Finding out the relevant DMAQNUM register and the correct bit positions to
        write into */
        _qNumIndex = hEdma->chaNum >> 3;
        _qchMap = hEdma->chaNum - (_qNumIndex * 8);
        CSL_FINSR(hEdma->ccregs->DMAQNUM[_qNumIndex],_qchMap*4+2,_qchMap*4,evtQue);
    }
    return CSL_SOK;
}
/**
@}
*/
/**
@addtogroup CSL_EDMA_FUNCTION_MODULE_INTERNAL
@{
*/

/** =============================================================================
 *   @n@b   CSL_edmaGetRevision
 *
 *   @b Description
 *   @n Gets the status of the different operations or the current setup of EDMA
 *      module
 *
 *   @b Arguments
 *   @verbatim

            hCh        Channel Handle

     @endverbatim
 *
 *   <b> Return Value   <b/>
 *          revision   Revision of Module
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaInit() must be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 *
 * <b> Usage Constraints: </b>
 * All @a CSL_edmaInit(), @a CSL_edmaOpen(), must be
 * called successfully in that order before @a CSL_edmaGetRevision() can
 * be called.
 *
 *
 * @b Example:
 *   @verbatim

   CSL_EdmaHandle     edmaHndl;
   CSL_Status modStatus;
   // Initialize

   modStatus = CSL_edmaInit(NULL);
   ...

   edmaHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);

   revision = CSL_edmaGetRevision(edmaHndl);
     @endverbatim
 *
 * ===========================================================================
 */
//pragma CODE_SECTION (CSL_edmaGetRevision, ".text:csl_section:edma");
CSL_IDEF_INLINE Uint32  CSL_edmaGetRevision(
    /**  module handle to EDMA module */
    CSL_EdmaHandle         hMod
)
{
    return (hMod->REV);
}

/** =============================================================================
 *   @n@b   CSL_edmaGetEventsMissed
 *
 *   @b Description
 *   @n Queries all the events missed.
 *
 *   @b Arguments
 *   @verbatim

        hMod    Module Handle

        Uint32  Since there may be upto 64 EDMA channels + upto 8 QDMA channels,
 *     this points to an  array of 3, 32 bit elements to hold
 *     all 64 + 8 event missed status bits.
 *     missed [0] - holds status from EMR
 *     missed [1] - holds status from EMRH
 *     missed [2] - holds status from QEMR
     @endverbatim
 *
 *   <b> Return Value   <b/>
 *          edmaStatus   CSL_SOK - Alwaya returns
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaInit() must be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 * <b> Usage Constraints: </b>
 * All @a CSL_edmaInit(), @a CSL_edmaOpen(), must be
 * called successfully in that order before @a CSL_edmaGetEventsMissed() can
 * be called.
 *
 *
 * @b Example:
 *   @verbatim

    CSL_EdmaHandle     edmaHndl;
    CSL_Status modStatus;
    Uint32 missedEdma,missedEdmaHi,missedQdma;
    // Initialize

    modStatus = CSL_edmaInit(NULL);
    ...

    edmaHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);

    // Get missed events
    edmaStatus = CSL_edmaGetEventsMissed(edmaHndl,
                                         &missedEdma,
                                         &missedEdmaHi,
                                         &missedQdma
                                         );
     @endverbatim
 *
 * ===========================================================================
 */
//#pragma CODE_SECTION (CSL_edmaGetEventsMissed, ".text:csl_section:edma");
CSL_IDEF_INLINE CSL_Status  CSL_edmaGetEventsMissed(
    /**  module handle to EDMA */
    CSL_EdmaHandle         hMod,
    /**  a place holder for 0-31 events */
    CSL_BitMask32          *missedLo,
    /**  a place holder for 32-63 events */
    CSL_BitMask32          *missedHi,
    /**  a place holder for QDMA events */
    CSL_BitMask32          *missedQdma
)
{
    /* Reading the missed Status registers */
    *missedLo    = hMod->EMR;
    *missedHi    = hMod->EMRH   ;
    *missedQdma  = hMod->QEMR   ;

    /* Clearing the status registers */
    hMod->EMCR = *missedLo;
    hMod->EMCRH = *missedHi;
    hMod->QEMCR = *missedQdma;
    return CSL_SOK;
}

/** =============================================================================
 *   @n@b   CSL_edmaGetControllerError
 *
 *   @b Description
 *   @n Queries the Channel controller Error Status.
 *
 *   @b Arguments
 *   @verbatim

        hMod        Module Handle

        ccStat      this points to a structure allocated by the user program 
                    that can hold the queried status values.
     @endverbatim
 *
 *   <b> Return Value   <b/>
 *          Status   CSL_SOK - Alwaya returns
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaInit() must be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 *
 * <b> Usage Constraints: </b>
 * All @a CSL_edmaInit(), @a CSL_edmaOpen(), must be
 * called successfully in that order before @a CSL_edmaGetControllerError() can
 * be called.
 *
 *
 * @b Example:
 *   @verbatim

    CSL_EdmaHandle     edmaHndl;
    CSL_Status modStatus;
    CSL_EdmaccStatus ccError;
    // Initialize

    modStatus = CSL_edmaInit(NULL);
    ...

    edmaHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);

    // Get Controller Error
    edmaStatus = CSL_edmaGetControllerError(edmaHndl,&ccError);
   
     @endverbatim
 *
 * ===========================================================================
 */
//#pragma CODE_SECTION (CSL_edmaGetControllerError, ".text:csl_section:edma");
CSL_IDEF_INLINE CSL_Status  CSL_edmaGetControllerError(
    /**  module handle to EDMA */
    CSL_EdmaHandle         hMod,
    /**  a place holder for the Controller Error */
    CSL_EdmaccStatus  *ccStat
)
{
    ccStat->errorMask = hMod->CCERR & 0xFF ;
    ccStat->exceedTcc = (Bool)(CSL_FEXT(hMod->CCERR, EDMACC_CCERR_TCCERR)) ;
    /* Clears the errors */
    hMod->CCERRCLR = ccStat->exceedTcc << 16 | ccStat->errorMask;
    return CSL_SOK;
}

/** =============================================================================
 *   @n@b   CSL_edmaGetIntrPendStatus
 *
 *   @b Description
 *   @n Queries the interrupt status of the interrupts. This is read from the 
 *      Global Channel Register.
 *
 *   @b Arguments
 *   @verbatim

        hMod        Module Handle

        intrLo      status 0-31 of the interrupts
        
        intrHi      status 32-63 of the interrupts
     @endverbatim
 *
 *   <b> Return Value   <b/>
 *          Status   CSL_SOK - Alwaya returns
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaInit() must be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 *
 * <b> Usage Constraints: </b>
 * All @a CSL_edmaInit(), @a CSL_edmaOpen(), must be
 * called successfully in that order before @a CSL_edmaGetIntrPendStatus() can
 * be called.
 *
 *
 * @b Example:
 *   @verbatim

    CSL_EdmaHandle     edmaHndl;
    CSL_Status modStatus;
    Uint32 edmaIntrLo,edmaIntrHi;
    // Initialize

    modStatus = CSL_edmaInit(NULL);
    ...

    edmaHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);

    // Get interrupt pend status
    edmaStatus = CSL_edmaGetIntrPendStatus(edmaHndl,&edmaIntrLo. &edmaIntrHi);

     @endverbatim
 *
 * ===========================================================================
 */
//#pragma CODE_SECTION (CSL_edmaGetIntrPendStatus, ".text:csl_section:edma");
CSL_IDEF_INLINE CSL_Status  CSL_edmaGetIntrPendStatus(
    /**  module handle to EDMA */
    CSL_EdmaHandle         hMod,
    /**  place holder for the interrupt status 0-31*/
    CSL_BitMask32           *intrLo,
    /**  place holder for the interrupt status 32-63*/
    CSL_BitMask32           *intrHi
)
{
    *intrLo = hMod->IPR;
    *intrHi = hMod->IPRH;
    return CSL_SOK;
}
#if CSL_EDMA_MEMPROTECT

/** =============================================================================
 *   @n@b   CSL_edmaGetMemoryProtectionAttrib
 *
 *   @b Description
 *   @n Queries the Memory Access rights of the specified region. This
 *     may be global/view.
 *
 *   @b Arguments
 *   @verbatim

        hMod        Module Handle

        region      region queried. This may refer to the global channel 
                    register space or a specific region/view.
        
     @endverbatim
 *
 *   <b> Return Value   <b/>
 *          CSL_BitMask32 - MPPAG/MPPA[0/1../n] value
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaInit() must be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 *
 * <b> Usage Constraints: </b>
 * All @a CSL_edmaInit(), @a CSL_edmaOpen(), must be
 * called successfully in that order before @a CSL_edmaGetMemoryProtectAttrib() can
 * be called.
 *
 *
 * @b Example:
 *   @verbatim

    CSL_EdmaHandle     edmaHndl;
    CSL_Status modStatus;
    Uint32 edmaIntrLo,edmaIntrHi;
    Uint32 memProt;
    // Initialize

    modStatus = CSL_edmaInit(NULL);
    ...

    edmaHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);


    // Get memory protection attributes
    memProt = CSL_edmaGetMemoryProtectAttrib(edmaHndl,CSL_EDMA_REGION_2);

     @endverbatim
 *
 * ===========================================================================
 */
//#pragma CODE_SECTION (CSL_edmaGetMemoryProtectionAttrib, ".text:csl_section:edma");
CSL_IDEF_INLINE CSL_BitMask32  CSL_edmaGetMemoryProtectionAttrib(
    /**  module handle to EDMA */
    CSL_EdmaHandle         hMod,
    /**  interrupt queried */
    Int        region
)
{
    CSL_BitMask32 mppa;
    if (region < 0)
        mppa = hMod->MPPAG;
    else
        mppa = hMod->MPPA[region];
    return mppa;
}

/** =============================================================================
 *   @n@b   CSL_edmaGetMemoryFaultError
 *
 *   @b Description
 *   @n Queries the Channel controllers memory fault error and the
 *     Error attributes
 *
 *   @b Arguments
 *   @verbatim

        hMod        Module Handle

        memFault    this points to a structure alloctaed by the user program 
                    that can hold the queried the memory fault status values.
     @endverbatim
 *
 *   <b> Return Value   <b/>
 *          Status          (CSL_SOK)
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaInit() must be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 *
 * <b> Usage Constraints: </b>
 * All @a CSL_edmaInit(), @a CSL_edmaOpen(), must be
 * called successfully in that order before @a CSL_edmaGetMemoryFaultError() can
 * be called.
 *
 *
 * @b Example:
 *   @verbatim

    CSL_EdmaMemFaultStatus memFault;
    CSL_EdmaHandle     edmaHndl;
    CSL_Status modStatus;

    // Initialize

    modStatus = CSL_edmaInit(NULL);
    ...

    edmaHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);

    // Get memory protection attributes
    memStatus CSL_edmaGetMemoryFaultError(edmaHndl,&memFault);

     @endverbatim
 *
 * ===========================================================================
 */
//#pragma CODE_SECTION (CSL_edmaGetMemoryFaultError, ".text:csl_section:edma");
CSL_IDEF_INLINE CSL_Status  CSL_edmaGetMemoryFaultError(
    /**  module handle to EDMA */
    CSL_EdmaHandle         hMod,
    /**  a place holder for the memory fault Error status */
    CSL_EdmaMemFaultStatus  *memFault
)
{
    /* Reading the Memory Fault Status registers */
    memFault->addr = hMod->MPFAR;
    memFault->errorMask =  CSL_FEXTR(hMod->MPFSR, 8, 0);
    memFault->fid = CSL_FEXTR(hMod->MPFSR, 12, 9);
    /* Clearing the Memory Fault Error */
    hMod->MPFCR = 1;
    return CSL_SOK;
}

#endif

/** =============================================================================
 *   @n@b   CSL_edmaSetMemoryProtectionAttrib
 *
 *   @b Description
 *   @n Sets specified memory protection attributes for the specifed region.
 *
 *   @b Arguments
 *   @verbatim

        hMod        Module Handle

        edmaRegion  region - this may be specified as one of the many view 
                    supported by the chip or the global memory protection 
                    attributes themselves.
        mpa         Value to be programmed into the MPPAG/MPPA[0/1/2/../n].
                    This is a Bitmask of the protection attributes.
                    
     @endverbatim
 *
 *   <b> Return Value   <b/>
 *          Status          (CSL_SOK)
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaInit() must be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 *
 * <b> Usage Constraints: </b>
 * The EDMA must be succesfully initializedvia @a CSL_edmaInit().
 * CSL_edmaOpen() must be called before usage of this API.
 *
 *
 * @b Example:
 *   @verbatim

    CSL_EdmaHandle     edmaHndl;
    CSL_Status modStatus;

    // Initialize

    modStatus = CSL_edmaInit(NULL);
    ...

    edmaHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);

    // Module Control API
    modStatus = CSL_edmaSetMemoryProtectionAttrib(edmaHndl,CSL_EDMA_REGION_0,
        (CSL_EDMA_MEMACCESS_UX|CSL_EDMA_MEMACCESS_UW|CSL_EDMA_MEMACCESS_UR|
        CSL_EDMA_MEMACCESS_AID2));

     @endverbatim
 *
 * ===========================================================================
 */
#if CSL_EDMA_MEMPROTECT
//#pragma CODE_SECTION (CSL_edmaSetMemoryProtectionAttrib, ".text:csl_section:edma");
CSL_IDEF_INLINE CSL_Status  CSL_edmaSetMemoryProtectionAttrib(
    /**  module handle to EDMA */
    CSL_EdmaHandle         hMod,
    /**  region needing the Memory protection */
    Int        edmaRegion,
    /**  bitMask of the Memory Protection Attributes */
    CSL_BitMask32          mpa
)
{
    if (edmaRegion == CSL_EDMA_REGION_GLOBAL)
        hMod->MPPAG = mpa;
    else
        hMod->MPPA[edmaRegion] = mpa;
    return CSL_SOK;
}
#endif

/** =============================================================================
 *   @n@b   CSL_edmaDmaRegionAccessEnable
 *
 *   @b Description
 *   @n This API sets the DRAE/DRAEH BitMask.
 *
 *   @b Arguments
 *   @verbatim

        hMod        Module Handle

        edmaRegion  region - this may be specified as one of the many view 
                    supported by the chip or the global memory protection 
                    attributes themselves.
                    
        access      region bits to be programmed
        
        drae        Bitmask to be enabled in DRAE
        
        draeh       Bitmask to be enabled in DRAEH
                    
     @endverbatim
 *
 *   <b> Return Value   <b/>
 *          Status 		(CSL_SOK/CSL_ESYS_INVPARAMS)
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaOpen() must be called before usage of this API.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 *
 * <b> Usage Constraints: </b>
 *  The EDMA must be succesfully initializedvia @a CSL_edmaInit().
 * CSL_edmaOpen() must be called before usage of this API.
 *
 *
 * @b Example:
 *   @verbatim

    CSL_EdmaHandle     hModHndl;
    CSL_Status modStatus;

    // Initialize

    modStatus = CSL_edmaInit(NULL);
    ...

    hModHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);

    // Module Control API
    status = CSL_edmaDmaRegionAccessEnable(hModHndl,
                        CSL_EDMA_REGION_0,0x000000FF, 0x000000FF);

     @endverbatim
 *
 * ===========================================================================
 */
//#pragma CODE_SECTION (CSL_edmaDmaRegionAccessEnable, ".text:csl_section:edma");
CSL_IDEF_INLINE CSL_Status  CSL_edmaDmaRegionAccessEnable(
    /**  module handle to EDMA */
    CSL_EdmaHandle         hMod,
    /**  region needing the Memory protection */
    Int        edmaRegion,
    /**  drae bits to be enabled */
    CSL_BitMask32          drae,
    /**  draeh bits to be enabled */
    CSL_BitMask32          draeh
)
{
    int cs;
    if (edmaRegion == CSL_EDMA_REGION_GLOBAL)
        return CSL_ESYS_INVPARAMS;
    cs = _CSL_beginCriticalSection();
   // asm(" dint");
    hMod->DRA[edmaRegion].DRAE |= drae;
    hMod->DRA[edmaRegion].DRAEH |= draeh;
    _CSL_endCriticalSection(cs) ;
    return CSL_SOK;
}

/** =============================================================================
 *   @n@b   CSL_edmaDmaRegionAccessDisable
 *
 *   @b Description
 *   @n This API clears the DRAE/DRAEH BitMask.
 *
 *   @b Arguments
 *   @verbatim

        hMod        Module Handle

        edmaRegion  region - this may be specified as one of the many view 
                    supported by the chip or the global memory protection 
                    attributes themselves.
                    
        access      region bits to be programmed
        
        drae        Bitmask to be disabled in DRAE
        
        draeh       Bitmask to be disabled in DRAEH

     @endverbatim
 *
 *   <b> Return Value   <b/>
 *          Status 		(CSL_SOK/CSL_ESYS_INVPARAMS)
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaOpen() must be called before usage of this API.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 *
 * <b> Usage Constraints: </b>
 *  The EDMA must be succesfully initializedvia @a CSL_edmaInit().
 * CSL_edmaOpen() must be called before usage of this API.
 *
 *
 * @b Example:
 *   @verbatim

    CSL_EdmaHandle     hModHndl;
    CSL_Status modStatus;

    // Initialize

    modStatus = CSL_edmaInit(NULL);
    ...
    hModHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);
    // Module Control API
    status = CSL_edmaDmaRegionAccessDisable(hModHndl,
                    CSL_EDMA_REGION_0,0x000000FF,0x000000FF);

     @endverbatim
 *
 * ===========================================================================
 */
//#pragma CODE_SECTION (CSL_edmaDmaRegionAccessDisable, ".text:csl_section:edma");
CSL_IDEF_INLINE CSL_Status  CSL_edmaDmaRegionAccessDisable(
    /**  module handle to EDMA */
    CSL_EdmaHandle         hMod,
    /**  region needing the Memory protection */
    Int        edmaRegion,
    /**  drae bits to be disabled */
    CSL_BitMask32          drae,
    /**  draeh bits to be disabled */
    CSL_BitMask32          draeh
)
{
    int cs;
    if (edmaRegion == CSL_EDMA_REGION_GLOBAL)
        return CSL_ESYS_INVPARAMS;
    cs = _CSL_beginCriticalSection()    ;
    hMod->DRA[edmaRegion].DRAE &= ~drae;
    hMod->DRA[edmaRegion].DRAEH &= ~draeh;
    _CSL_endCriticalSection(cs) ;
    return CSL_SOK;
}

/** =============================================================================
 *   @n@b   CSL_edmaQdmaRegionAccessEnable
 *
 *   @b Description
 *   @n This API sets the QRAE BitMask.
 *
 *   @b Arguments
 *   @verbatim

        hMod        Module Handle

        edmaRegion  region - this may be specified as one of the many view 
                    supported by the chip or the global memory protection 
                    attributes themselves.
                    
        access      region bits to be programmed
        
        qrae        Bitmask to be enabled in QRAE
        
     @endverbatim
 *
 *   <b> Return Value   <b/>
 *          Status 		(CSL_SOK/CSL_ESYS_INVPARAMS)
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaOpen() must be called before usage of this API.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 *
 * <b> Usage Constraints: </b>
 *  The EDMA must be succesfully initializedvia @a CSL_edmaInit().
 * CSL_edmaOpen() must be called before usage of this API.
 *
 *
 * @b Example:
 *   @verbatim

    CSL_EdmaHandle     hModHndl;
    CSL_Status modStatus;
    // Initialize
    modStatus = CSL_edmaInit(NULL);
    ...

    hModHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);
    // Module Control API
    // ALL 8 Channels allowed
    status = CSL_edmaQdmaRegionAccessEnable(hModHndl,
                        CSL_EDMA_REGION_0,0x000000FF);

     @endverbatim
 *
 * ===========================================================================
 */
//#pragma CODE_SECTION (CSL_edmaQdmaRegionAccessEnable, ".text:csl_section:edma");
CSL_IDEF_INLINE CSL_Status  CSL_edmaQdmaRegionAccessEnable(
    /**  module handle to EDMA */
    CSL_EdmaHandle         hMod,
    /**  region needing the Memory protection */
    Int                    edmaRegion,
    /**  drae bits to be enabled */
    CSL_BitMask32          qrae
)
{
    int cs;
    if (edmaRegion == CSL_EDMA_REGION_GLOBAL)
        return CSL_ESYS_INVPARAMS;
    cs = _CSL_beginCriticalSection()    ;
    hMod->QRAE[edmaRegion] |= qrae;
    _CSL_endCriticalSection(cs) ;
    return CSL_SOK;
}

/** =============================================================================
 *   @n@b   CSL_edmaQdmaRegionAccessDisable
 *
 *   @b Description
 *   @n This API clears the QRAE BitMask.
 *
 *   @b Arguments
 *   @verbatim

        hMod        Module Handle

        edmaRegion  region - this may be specified as one of the many view 
                    supported by the chip or the global memory protection 
                    attributes themselves.
                    
        access      region bits to be programmed
        
        qrae        Bitmask to be disabled in QRAE
        
     @endverbatim
 *
 *   <b> Return Value   <b/>
 *          Status 		(CSL_SOK/CSL_ESYS_INVPARAMS)
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaOpen() must be called before usage of this API.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 *
 * <b> Usage Constraints: </b>
 *  The EDMA must be succesfully initializedvia @a CSL_edmaInit().
 * CSL_edmaOpen() must be called before usage of this API.
 *
 *
 * @b Example:
 *   @verbatim

    CSL_EdmaHandle     hModHndl;
    CSL_Status modStatus;
    // Initialize
    modStatus = CSL_edmaInit(NULL);
    ...

    hModHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);
    // Module Control API
    // ALL 8 Channels disallowed
    status = CSL_edmaQdmaRegionAccessDisable(hModHndl,
                                    CSL_EDMA_REGION_0,0x000000FF);

     @endverbatim
 *
 * ===========================================================================
 */
//#pragma CODE_SECTION (CSL_edmaQdmaRegionAccessDisable, ".text:csl_section:edma");
CSL_IDEF_INLINE CSL_Status  CSL_edmaQdmaRegionAccessDisable(
    /**  module handle to EDMA */
    CSL_EdmaHandle         hMod,
    /**  region needing the Memory protection */
    Int        edmaRegion,
    /**  qrae bits to be disabled */
    CSL_BitMask32          qrae
)
{
    int cs;
    if (edmaRegion == CSL_EDMA_REGION_GLOBAL)
        return CSL_ESYS_INVPARAMS;
    cs = _CSL_beginCriticalSection()    ;
    hMod->QRAE[edmaRegion] &= ~qrae;
    _CSL_endCriticalSection(cs) ;
    return CSL_SOK;
}

/** =============================================================================
 *   @n@b   CSL_edmaEventQueuePrioritySet
 *
 *   @b Description
 *   @n This API sets the Queue priority level to the appropriate value.
 *
 *   @b Arguments
 *   @verbatim

        hMod        Module Handle

        que        	Event queue
        
        pri        	Priority needed to be set for above Event queue
        
     @endverbatim
 *
 *   <b> Return Value   <b/>
 *          Status 		(CSL_SOK/CSL_ESYS_INVPARAMS)
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaOpen() must be called before usage of this API.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 *
 * <b> Usage Constraints: </b>
 *  The EDMA must be succesfully initializedvia @a CSL_edmaInit().
 * CSL_edmaOpen() must be called before usage of this API.
 *
 *
 * @b Example:
 *   @verbatim

    CSL_EdmaHandle     hModHndl;
    CSL_Status modStatus;
    // Initialize
    modStatus = CSL_edmaInit(NULL);
    ...

    hModHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);
    status = CSL_edmaEventQueuePrioritySet(hModHndl,
    									   CSL_EDMA_EVT_QUE0,
    									   CSL_EDMA_VBUSM_PRI2
    									   );

     @endverbatim
 *
 * ===========================================================================
 */
//#pragma CODE_SECTION (CSL_edmaEventQueuePrioritySet, ".text:csl_section:edma");
CSL_IDEF_INLINE CSL_Status  CSL_edmaEventQueuePrioritySet(
    /**  module handle to EDMA */
    CSL_EdmaHandle         hMod,
    /**  Queue for which priority level is required to be set */
    CSL_EdmaEventQueue         que,
    /**  priority to be set */
    CSL_EdmaEventQueuePri      pri
)
{
    int cs;
    cs = _CSL_beginCriticalSection()    ;
    CSL_FINSR(hMod->QUEPRI, (4*que + 2),(4*que),pri);
    _CSL_endCriticalSection(cs);
    return CSL_SOK;
}

/** =============================================================================
 *   @n@b   CSL_EdmaEventQueueTcMap
 *
 *   @b Description
 *   @n This API does the Event Queue to TC Mapping
 *
 *   @b Arguments
 *   @verbatim

        hMod        Module Handle

        que        	Event queue
        
        tc          transfer controller number
        
     @endverbatim
 *
 *   <b> Return Value   <b/>
 *          Status 		(CSL_SOK/CSL_ESYS_INVPARAMS)
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaOpen() must be called before usage of this API.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 *
 * <b> Usage Constraints: </b>
 *  The EDMA must be succesfully initializedvia @a CSL_edmaInit().
 * CSL_edmaOpen() must be called before usage of this API.
 *
 *
 * @b Example:
 *   @verbatim

    CSL_EdmaHandle     hModHndl;
    CSL_Status modStatus;
    // Initialize
    modStatus = CSL_edmaInit(NULL);
    ...

    hModHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);

    status = CSL_edmaEventQueueTcMap(hModHndl,
    								 CSL_EDMA_EVT_QUE0,
    								 CSL_EDMA_TC2
    								 );

     @endverbatim
 *
 * ===========================================================================
 */
//#pragma CODE_SECTION (CSL_edmaEventQueueTcMap, ".text:csl_section:edma");
CSL_IDEF_INLINE CSL_Status  CSL_edmaEventQueueTcMap(
    /**  module handle to EDMA */
    CSL_EdmaHandle         hMod,
    /**  Queue for which priority level is required to be set */
    CSL_EdmaEventQueue     que,
    /**  bitMask of the Memory Protection Attributes */
    CSL_EdmaTc             tc
)
{
    int cs;
    cs = _CSL_beginCriticalSection()    ;
    CSL_FINSR(hMod->QUETCMAP, (4*que + 2),(4*que),tc);
    _CSL_endCriticalSection(cs);
    return CSL_SOK;
}

/** =============================================================================
 *   @n@b   CSL_EdmaEventQueueThresholdSet
 *
 *   @b Description
 *   @n This API sets the Queue threshold to the appropriate level
 *
 *   @b Arguments
 *   @verbatim

        hMod        Module Handle

        que        	Event queue
        
        threshold   target threshold value for the above queue
        
     @endverbatim
 *
 *   <b> Return Value   <b/>
 *          Status 		(CSL_SOK/CSL_ESYS_INVPARAMS)
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaOpen() must be called before usage of this API.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 *
 * <b> Usage Constraints: </b>
 *  The EDMA must be succesfully initializedvia @a CSL_edmaInit().
 * CSL_edmaOpen() must be called before usage of this API.
 *
 *
 * @b Example:
 *   @verbatim

    CSL_EdmaHandle     hModHndl;
    CSL_Status modStatus;
    // Initialize
    modStatus = CSL_edmaInit(NULL);
    ...
    hModHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);

    status = CSL_edmaEventQueueThresholdSet(hModHndl,
    										CSL_EDMA_EVT_QUE0,
    										CSL_EDMA_QUETHRESH_10
    										);
     @endverbatim
 *
 * ===========================================================================
 */
//#pragma CODE_SECTION (CSL_edmaEventQueueThresholdSet, ".text:csl_section:edma");
CSL_IDEF_INLINE CSL_Status  CSL_edmaEventQueueThresholdSet(
    /**  module handle to EDMA */
    CSL_EdmaHandle         hMod,
    /**  Queue for which priority level is required to be set */
    CSL_EdmaEventQueue         que,
    /**  Threshold to be set */
    CSL_EdmaEventQueueThr      threshold
)
{
    int cs;
    cs = _CSL_beginCriticalSection()    ;
    if (que < ((CSL_EdmaEventQueue)4))
        CSL_FINSR(hMod->QWMTHRA, (8*que + 4),(8*que),threshold);
     else
        CSL_FINSR(hMod->QWMTHRB, (8 * (que-4) + 4),(8 * (que-4)),threshold);
    _CSL_endCriticalSection(cs);
    return CSL_SOK;
}

/** =============================================================================
 *   @n@b   CSL_edmaErrorEval
 *
 *   @b Description
 *   @n This API enables enables evaluation of errros for the specified
 *  	view/shadow Region
 *
 *   @b Arguments
 *   @verbatim

        hMod        Module Handle

     @endverbatim
 *
 *   <b> Return Value   <b/>
 *          Status 		(CSL_SOK/CSL_ESYS_INVPARAMS)
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaOpen() must be called before usage of this API.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 *
 * <b> Usage Constraints: </b>
 *  The EDMA must be succesfully initializedvia @a CSL_edmaInit().
 * CSL_edmaOpen() must be called before usage of this API.
 *
 *
 * @b Example:
 *   @verbatim

    CSL_EdmaHandle     hModHndl;
    CSL_Status modStatus;
    // Initialize
    modStatus = CSL_edmaInit(NULL);
    ...
    hModHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);

    // Module Control API
    status = CSL_edmaErrorEval(hModHndl);
     @endverbatim
 *
 * ===========================================================================
 */
//#pragma CODE_SECTION (CSL_edmaErrorEval, ".text:csl_section:edma");
CSL_IDEF_INLINE CSL_Status  CSL_edmaErrorEval(
    /**  module handle to EDMA */
    CSL_EdmaHandle         hMod
)
{

    hMod->EEVAL = 1;
    return CSL_SOK;
}

/** =============================================================================
 *   @n@b   CSL_edmaInterruptEnable
 *
 *   @b Description
 *   @n This API enables the interrupts as specified in the BitMask
 *
 *   @b Arguments
 *   @verbatim

        hMod        Module Handle
        
        intrLo      interrupt 0-31 (BitMask32) to be enabled
        
 		intrHi 		interrupt 32-63 (BitMask32) to be enabled

     @endverbatim
 *
 *   <b> Return Value   <b/>
 *          Status 		(CSL_SOK)
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaOpen() must be called before usage of this API.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 *
 * <b> Usage Constraints: </b>
 *  The EDMA must be succesfully initializedvia @a CSL_edmaInit().
 * CSL_edmaOpen() must be called before usage of this API.
 *
 *
 * @b Example:
 *   @verbatim

    CSL_EdmaHandle     hModHndl;
    CSL_Status modStatus;
    // Initialize
    modStatus = CSL_edmaInit(NULL);
    ...
    hModHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);

    status = CSL_edmaInterruptEnable(hModHndl,0x000000E0, 0x0);
     @endverbatim
 *
 * ===========================================================================
 */
//#pragma CODE_SECTION (CSL_edmaInterruptEnable, ".text:csl_section:edma");
CSL_IDEF_INLINE CSL_Status  CSL_edmaInterruptEnable(
    /**  module handle to EDMA */
    CSL_EdmaHandle         hMod,
    /**  interrupt to be enabled 0-31*/
    CSL_BitMask32          intrLo,
    /**  interrupt to be enabled 32-63*/
    CSL_BitMask32          intrHi
)
{
    hMod->IESR = intrLo;
    hMod->IESRH = intrHi;
    return CSL_SOK;
}

/** =============================================================================
 *   @n@b   CSL_edmaInterruptDisable
 *
 *   @b Description
 *   @n This API disables the interrupts as specified
 *
 *   @b Arguments
 *   @verbatim

        hMod        Module Handle
        
        intrLo      interrupt 0-31 (BitMask32) to be disabled
        
 		intrHi 		interrupt 32-63 (BitMask32) to be disabled

     @endverbatim
 *
 *   <b> Return Value   <b/>
 *          Status 		(CSL_SOK)
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaOpen() must be called before usage of this API.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 *
 * <b> Usage Constraints: </b>
 *  The EDMA must be succesfully initializedvia @a CSL_edmaInit().
 * CSL_edmaOpen() must be called before usage of this API.
 *
 *
 * @b Example:
 *   @verbatim

    CSL_EdmaHandle     hModHndl;
    CSL_Status modStatus;
    // Initialize
    modStatus = CSL_edmaInit(NULL);
    ...
    hModHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);

    // Interrupt 5,6,7 disabled
    status = CSL_edmaInterruptDisable(hModHndl,0x000000E0, 0x0);

     @endverbatim
 *
 * ===========================================================================
 */
//#pragma CODE_SECTION (CSL_edmaInterruptDisable, ".text:csl_section:edma");
CSL_IDEF_INLINE CSL_Status  CSL_edmaInterruptDisable(
    /**  module handle to EDMA */
    CSL_EdmaHandle         hMod,
    /**  interrupt to be disabled 0-31*/
    CSL_BitMask32          intrLo,
    /**  interrupt to be disabled 32-63*/
    CSL_BitMask32          intrHi
)
{
    hMod->IECR  = intrLo;
    hMod->IECRH = intrHi;
    return CSL_SOK;
}

/** =============================================================================
 *   @n@b   CSL_edmaInterruptClear
 *
 *   @b Description
 *   @n This API clears the interrupt as specified
 *
 *   @b Arguments
 *   @verbatim

        hMod        Module Handle
        
        intrLo      interrupt 0-31 (BitMask32) to be cleared
        
 		intrHi 		interrupt 32-63 (BitMask32) to be cleared

     @endverbatim
 *
 *   <b> Return Value   <b/>
 *          Status 		(CSL_SOK)
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaOpen() must be called before usage of this API.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 *
 * <b> Usage Constraints: </b>
 *  The EDMA must be succesfully initializedvia @a CSL_edmaInit().
 * CSL_edmaOpen() must be called before usage of this API.
 *
 *
 * @b Example:
 *   @verbatim

    CSL_EdmaHandle     hModHndl;
    CSL_Status modStatus;
    // Initialize
    modStatus = CSL_edmaInit(NULL);
    ...
    hModHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);

    // 5,6,7 cleared
    status = CSL_edmaInterruptClear(hModHndl,0x000000E0,0);

     @endverbatim
 *
 * ===========================================================================
 */
//#pragma CODE_SECTION (CSL_edmaInterruptClear, ".text:csl_section:edma");
CSL_IDEF_INLINE CSL_Status  CSL_edmaInterruptClear(
    /**  module handle to EDMA */
    CSL_EdmaHandle         hMod,
    /**  interrupt to be cleared 0- 31 */
    CSL_BitMask32          intrLo,
    /**  interrupt to be cleared 32 - 63 */
    CSL_BitMask32          intrHi
)
{
    hMod->ICR = intrLo;
    hMod->ICRH = intrHi;
    return CSL_SOK;
}

/** =============================================================================
 *   @n@b   CSL_edmaInterruptEval
 *
 *   @b Description
 *   @n If any enabled interrutps are pending, the tpcc_intN output signal to 
 *		be pulsed
 *
 *   @b Arguments
 *   @verbatim

        hMod        Module Handle
        
     @endverbatim
 *
 *   <b> Return Value   <b/>
 *          Status 		(CSL_SOK)
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaOpen() must be called before usage of this API.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 *
 * <b> Usage Constraints: </b>
 *  The EDMA must be succesfully initializedvia @a CSL_edmaInit().
 * CSL_edmaOpen() must be called before usage of this API.
 *
 *
 * @b Example:
 *   @verbatim

    CSL_EdmaHandle     hModHndl;
    CSL_Status modStatus;
    // Initialize
    modStatus = CSL_edmaInit(NULL);
    ...
    hModHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);


    status = CSL_edmaInterruptEval(hModHndl);

     @endverbatim
 *
 * ===========================================================================
 */
CSL_IDEF_INLINE CSL_Status  CSL_edmaInterruptEval(
    /**  a handle to the requested channel instance of the specified EDMA
     *   obtained  through the @a CSL_edmaOpen() call */
    CSL_EdmaHandle         hMod
)
{
    hMod->IEVAL = 1;
    return CSL_SOK;
}

/**
@}
*/

/**
@addtogroup CSL_EDMA_FUNCTION_SHADOW_INTERNAL
@{
*/

/** =============================================================================
 *   @n@b   CSL_edmaRegionInterruptEnable
 *
 *   @b Description
 *   @n Enables specified interrupt in the Shadow Region.
 *
 *   @b Arguments
 *   @verbatim

        hSh        Shadow Region Handle
        intrLo     interrupt 0-31 to be enabled
        intrHi     interrupt 32-63 to be enabled
  
        
     @endverbatim
 *
 *   <b> Return Value   <b/>
 *          Status 		(CSL_SOK)
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaOpen() must be called before usage of this API.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 *
 * <b> Usage Constraints: </b>
 *  The EDMA must be succesfully initializedvia @a CSL_edmaInit().
 *  CSL_edmaOpen() must be called before usage of this API.
 *
 *
 * @b Example:
 *   @verbatim

    CSL_EdmaObj ModuleObj;
    CSL_EdmaHandle hModHndl;
    CSL_EdmaRegionParam regParam;
    CSL_EdmaRegionObj RegionObj;
    CSL_EdmaRegionHndl shHndl;
    CSL_Status status;
    CSL_EdmaChanObj ChObj;
    CSL_EdmaChanHandle chHndl;

    // Initialization
    CSL_edmaInit(NULL);

    // Open Module
    edmaHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);

    // Region Open
    regParam.regionNum = CSL_EDMA_REGION_0;
    shHndl = CSL_edmaRegionOpen(&RegionObj,CSL_EDMA_0,&regParam,&status);

    status = CSL_edmaRegionInterruptEnable(shHndl,0x0000ffff,0xffff0000);

     @endverbatim
 *
 * ===========================================================================
 */
//#pragma CODE_SECTION (CSL_edmaRegionInterruptEnable, ".text:csl_section:edma");
CSL_IDEF_INLINE CSL_Status  CSL_edmaRegionInterruptEnable(
    /**  a handle to the shadow region already opened */
    CSL_EdmaRegionHandle       hSh,
    /**  interrupt 0-31 to be enabled */
    CSL_BitMask32              intrLo,
    /**  interrupt 32-63 to be enabled  */
    CSL_BitMask32              intrHi
)
{

    hSh->shregs->IESR = intrLo;
    hSh->shregs->IESRH = intrHi;
    return CSL_SOK;
}

/** =============================================================================
 *   @n@b   CSL_edmaRegionInterruptDisable
 *
 *   @b Description
 *   @n This API disables the interrupts for the shadow region.
 *
 *   @b Arguments
 *   @verbatim

        hSh        Shadow Region Handle
        intrLo     interrupt 0-31 to be disabled
        intrHi     interrupt 32-63 to be disabled
  

     @endverbatim
 *
 *   <b> Return Value   <b/>
 *          Status 		(CSL_SOK)
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaOpen() must be called before usage of this API.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 *
 * <b> Usage Constraints: </b>
 *  The EDMA must be succesfully initializedvia @a CSL_edmaInit().
 *  CSL_edmaOpen() must be called before usage of this API. Care needs to be 
 *	taken of the DRAE settings.
 *
 *
 * @b Example:
 *   @verbatim

    CSL_EdmaObj ModuleObj;
    CSL_EdmaHandle hModHndl;
    CSL_EdmaRegionParam regParam;
    CSL_EdmaRegionObj RegionObj;
    CSL_EdmaRegionHndl shHndl;
    CSL_Status status;
    CSL_EdmaChanObj ChObj;
    CSL_EdmaChanHandle chHndl;

    // Initialization
    CSL_edmaInit(NULL);

    // Open Module
    edmaHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);

    // Region Open
    regParam.regionNum = CSL_EDMA_REGION_0;
    shHndl = CSL_edmaRegionOpen(&RegionObj,CSL_EDMA_0,&regParam,&status);

    status = CSL_edmaRegionInterruptDisable(shHndl,0x0000ffff,0xffff0000);

     @endverbatim
 *
 * ===========================================================================
 */
//#pragma CODE_SECTION (CSL_edmaRegionInterruptDisable, ".text:csl_section:edma");
CSL_IDEF_INLINE CSL_Status  CSL_edmaRegionInterruptDisable(
    /**  a handle to the shadow region already opened */
    CSL_EdmaRegionHandle       hSh,
    /**  interrupt 0-31 to be disabled */
    CSL_BitMask32              intrLo,
    /**  interrupt 32-63 to be disabled */
    CSL_BitMask32              intrHi
)
{
    hSh->shregs->IECR = intrLo;
    hSh->shregs->IECRH = intrHi;
    return CSL_SOK;
}

/** =============================================================================
 *   @n@b   CSL_edmaRegionInterruptClear
 *
 *   @b Description
 *   @n This API clears the interrupts for the shadow region.
 *
 *   @b Arguments
 *   @verbatim

        hSh        Shadow Region Handle
        intrLo     interrupt 0-31 to be cleared
        intrHi     interrupt 32-63 to be cleared
  
        
     @endverbatim
 *
 *   <b> Return Value   <b/>
 *          Status 		(CSL_SOK)
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaOpen() must be called before usage of this API.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 *
 * <b> Usage Constraints: </b>
 *  The EDMA must be succesfully initializedvia @a CSL_edmaInit().
 *  CSL_edmaOpen() must be called before usage of this API. Care needs to be 
 *	taken of the DRAE settings.
 *
 *
 * @b Example:
 *   @verbatim

    CSL_EdmaObj ModuleObj;
    CSL_EdmaHandle hModHndl;
    CSL_EdmaRegionParam regParam;
    CSL_EdmaRegionObj RegionObj;
    CSL_EdmaRegionHndl shHndl;
    CSL_Status status;
    CSL_EdmaChanObj ChObj;
    CSL_EdmaChanHandle chHndl;

    // Initialization
    CSL_edmaInit(NULL);

    // Open Module
    edmaHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);

    // Region Open
    regParam.regionNum = CSL_EDMA_REGION_0;
    shHndl = CSL_edmaRegionOpen(&RegionObj,CSL_EDMA_0,&regParam,&status);
    ...
    status = CSL_edmaRegionInterruptClear(shHndl,0x0000ffff,0xffff0000);

     @endverbatim
 *
 * ===========================================================================
 */
//#pragma CODE_SECTION (CSL_edmaRegionInterruptClear, ".text:csl_section:edma");
CSL_IDEF_INLINE CSL_Status  CSL_edmaRegionInterruptClear(
    /**  a handle to the shadow region already opened */
    CSL_EdmaRegionHandle       hSh,
    /**  interrupt 0-31 to be enabled */
    CSL_BitMask32              intrLo,
    /**  interrupt 32-63 to be enabled */
    CSL_BitMask32              intrHi
)
{

    hSh->shregs->ICR = intrLo;
    hSh->shregs->ICRH = intrHi ;
    return CSL_SOK;
}

/** =============================================================================
 *   @n@b   CSL_edmaRegionInterruptEval
 *
 *   @b Description
 *   @n Sets EVAL bit of the IEVAL register in the specifed shadow region
 *   register space.
 *
 *   @b Arguments
 *   @verbatim

        hSh        Shadow Region Handle

     @endverbatim
 *
 *   <b> Return Value   <b/>
 *          Status 		(CSL_SOK)
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaOpen() must be called before usage of this API.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 *
 * <b> Usage Constraints: </b>
 *  The EDMA must be succesfully initializedvia @a CSL_edmaInit().
 *  CSL_edmaOpen() must be called before usage of this API. 
 *
 *
 * @b Example:
 *   @verbatim

    CSL_EdmaObj ModuleObj;
    CSL_EdmaHandle hModHndl;
    CSL_EdmaRegionParam regParam;
    CSL_EdmaRegionObj RegionObj;
    CSL_EdmaRegionHndl shHndl;
    CSL_Status status;
    CSL_EdmaChanObj ChObj;
    CSL_EdmaChanHandle chHndl;

    // Initialization
    CSL_edmaInit(NULL);

    // Open Module
    edmaHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);

    // Region Open
    regParam.regionNum = CSL_EDMA_REGION_0;
    shHndl = CSL_edmaRegionOpen(&RegionObj,CSL_EDMA_0,&regParam,&status);
    ...

    status = CSL_edmaRegionInterruptEval(shHndl);

     @endverbatim
 *
 * ===========================================================================
 */
//#pragma CODE_SECTION (CSL_edmaRegionInterruptEval, ".text:csl_section:edma");
CSL_IDEF_INLINE CSL_Status  CSL_edmaRegionInterruptEval(
    /**  a handle to the shadow region already opened */
    CSL_EdmaRegionHandle           hSh
)
{
    hSh->shregs->IEVAL = 1;
    return CSL_SOK;
}

/** =============================================================================
 *   @n@b   CSL_edmaGetRegionIntrPendStatus
 *
 *   @b Description
 *   @n Queries the interrupt Pend status in the shadow region.
 *
 *   @b Arguments
 *   @verbatim

        hSh        Shadow Region Handle
        
        *intrLo    Place holder for interrupt Status 0-31
        
        *intrHi    Place holder for interrupt Status 32-63
      
     @endverbatim
 *
 *   <b> Return Value   <b/>
 *          Status 		(CSL_SOK)
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_edmaOpen() must be called before usage of this API.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Modifies
 *   @n  None
 *
 *
 * <b> Usage Constraints: </b>
 * @a CSL_edmaInit(), CSL_edmaRegionOpen must have been called successfully
 * before this function can be called.The user must allocate space for this
 * and this API fills in the system specified fields.
 *
 *
 * @b Example:
 *   @verbatim

    CSL_EdmaObj ModuleObj;
    CSL_EdmaHandle hModHndl;
    CSL_EdmaRegionParam regParam;
    CSL_EdmaRegionObj RegionObj;
    CSL_EdmaRegionHndl shHndl;
    CSL_Status status;
    CSL_EdmaChanObj ChObj;
    CSL_EdmaChanHandle chHndl;
    CSL_BitMask32 intrPend[2];

    // Initialization
    CSL_edmaInit(NULL);

    // Open Module
    edmaHndl = CSL_edmaOpen(NULL,CSL_EDMA_0,NULL,&modStatus);

    // Region Open
    regParam.regionNum = CSL_EDMA_REGION_0;
    shHndl = CSL_edmaRegionOpen(&RegionObj,CSL_EDMA_0,&regParam,&status);

    // Query the shadow region
    CSL_edmaGetRegionIntrPendStatus(shHndl, &intrPend[0], &intrPend[1]);

     @endverbatim
 *
 * ===========================================================================
 */
//#pragma CODE_SECTION (CSL_edmaGetRegionIntrPendStatus, ".text:csl_section:edma");
CSL_IDEF_INLINE CSL_Status  CSL_edmaGetRegionIntrPendStatus(
    /**  a handle to the shadow region already opened */
    CSL_EdmaRegionHandle       hSh,
    /**  interrupt 0-31 queried */
    CSL_BitMask32              *intrLo,
    /**  interrupt 32-63 queried */
    CSL_BitMask32              *intrHi
)
{
    if (intrLo!=NULL)
        *intrLo = hSh->shregs->IPR;
    if (intrHi!=NULL)
        *intrHi = hSh->shregs->IPRH;
    return CSL_SOK;
}
/**
@}
*/
#endif
