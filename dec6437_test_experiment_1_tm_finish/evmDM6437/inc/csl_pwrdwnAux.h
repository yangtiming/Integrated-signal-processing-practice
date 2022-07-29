/* ============================================================================
 * Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005
 *
 * Use of this software is controlled by the terms and conditions found in the
 * license agreement under which this software has been supplied.
 * ============================================================================
 */

/** ===========================================================================
 *   @file csl_pwrdwnAux.h
 *   
 *   @brief API Auxilary header file for PWRDWN CSL 
 *   
 *   PATH \\(CSLPATH)\ipmodules\pwrdwn\src
 *
 *   @desc  PWRDWN module
 *   Modification : 30th Aug 2004
 *   Modified function 
 *   Added documentation
 * ============================================================================
 */
#ifndef _CSL_PWRDWNAUX_H
#define _CSL_PWRDWNAUX_H

#include <csl_pwrdwn.h>

#ifdef __cplusplus
extern "C" {
#endif
    
#define CSL_IDEF_INLINE static inline

/** @addtogroup CSL_PWRDWN_FUNCTION_INTERNAL
@{ */

/** ============================================================================
 *   @n@b  CSL_pwrdwnUmap0pageSleep
 *
 *   @b Description
 *   @n Manual power down. Puts specified pages on UMAP 0 to sleep
 *
 *   @b Arguments
 *   @verbatim

            hPwr       Handle to the power down module

            sleep      BitMask of pages on UMAP0 that need to be put to sleep   

     @endverbatim
 *
 *   <b> Return Value </b>  Status (CSL_SOK)
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *    @n Puts specified pages on UMAP 0 to sleep
 *
 *   @b Modifies
 *   @n  None
 *
 *   @b Example
 *   @verbatim

       CSL_PwrdwnObj pwrObj;
    CSL_PwrdwnConfig pwrConfig;
    CSL_PwrdwnHandle hPwr;
    // Init Module
    ...
    if (CSL_pwrdwnInit(NULL) != CSL_SOK)
       exit;
    // Opening a handle for the Module	
	hPwr = CSL_pwrdwnOpen (&pwrObj, CSL_PWRDWN_0, NULL, NULL);
    
	CSL_pwrdwnUmap0pageSleep(hPwr,0xFFFF00FF);

     @endverbatim
 * ===========================================================================
 */
CSL_IDEF_INLINE 
CSL_Status CSL_pwrdwnUmap0pageSleep (
    CSL_PwrdwnHandle hPwr,
    CSL_BitMask32 sleep
)
{
    hPwr->l2pwrdwnRegs->L2PDSLEEP[0] = sleep;
    
	return CSL_SOK;
}


/** ============================================================================
 *   @n@b  CSL_pwrdwnUmap1pageSleep
 *
 *   @b Description
 *   @n Manual power down. Puts specified pages on UMAP 1 to sleep
 *
 *   @b Arguments
 *   @verbatim

            hPwr       Handle to the power down module

            sleep      BitMask of pages on UMAP0 that need to be put to sleep   

     @endverbatim
 *
 *   <b> Return Value </b>  Status (CSL_SOK)
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *    @n Puts specified pages on UMAP 1 to sleep
 *
 *   @b Modifies
 *   @n  None
 *
 *   @b Example
 *   @verbatim

     CSL_PwrdwnObj pwrObj;
     CSL_PwrdwnConfig pwrConfig;
     CSL_PwrdwnHandle hPwr;
     // Init Module
      ...
     if (CSL_pwrdwnInit(NULL) != CSL_SOK)
       exit;
     // Opening a handle for the Module	
	 hPwr = CSL_pwrdwnOpen (&pwrObj, CSL_PWRDWN_0, NULL, NULL);
    
	 CSL_pwrdwnUmap1pageSleep(hPwr,0xFFFF00FF);

     @endverbatim
 * ===========================================================================
 */
CSL_IDEF_INLINE 
CSL_Status CSL_pwrdwnUmap1pageSleep (
    CSL_PwrdwnHandle hPwr,
    CSL_BitMask32 sleep
)
{
    hPwr->l2pwrdwnRegs->L2PDSLEEP[1] = sleep;
	
    return CSL_SOK;
}


/** ============================================================================
 *   @n@b  CSL_pwrdwnUmap0pageWake
 *
 *   @b Description
 *   @n Manual page wake. Awakes specified pages on UMAP 0.
 *
 *   @b Arguments
 *   @verbatim

            hPwr       Handle to the power down module

            wake       BitMask of pages on UMAP0 that need to be woken   

     @endverbatim
 *
 *   <b> Return Value </b>  Status (CSL_SOK)
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *    @n Awakes specified pages on UMAP 0
 *
 *   @b Modifies
 *   @n  None
 *
 *   @b Example
 *   @verbatim

     	CSL_PwrdwnObj pwrObj;
        CSL_PwrdwnConfig pwrConfig;
        CSL_PwrdwnHandle hPwr;
        // Init Module
        ...
        if (CSL_pwrdwnInit(NULL) != CSL_SOK)
          exit;
        // Opening a handle for the Module	
    	hPwr = CSL_pwrdwnOpen (&pwrObj, CSL_PWRDWN_0, NULL, NULL);
    
	    CSL_pwrdwnUmap0pageWake(hPwr,0xFFFF00FF);
     @endverbatim
 * ===========================================================================
 */
CSL_IDEF_INLINE 
CSL_Status CSL_pwrdwnUmap0pageWake (
    CSL_PwrdwnHandle hPwr,
    CSL_BitMask32 wake
)
{
    hPwr->l2pwrdwnRegs->L2PDWAKE[0] = wake;
    
    return CSL_SOK;
}


/** ============================================================================
 *   @n@b  CSL_pwrdwnUmap1pageWake
 *
 *   @b Description
 *   @n Manual page wake. Awakes specified pages on UMAP 1.
 *
 *   @b Arguments
 *   @verbatim

            hPwr       Handle to the power down module

            wake       BitMask of pages on UMAP0 that need to be woken   

     @endverbatim
 *
 *   <b> Return Value </b>  Status (CSL_SOK)
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *    @n Awakes specified pages on UMAP 1
 *
 *   @b Modifies
 *   @n  None
 *
 *   @b Example
 *   @verbatim

     	CSL_PwrdwnObj pwrObj;
        CSL_PwrdwnConfig pwrConfig;
        CSL_PwrdwnHandle hPwr;
        // Init Module
        ...
        if (CSL_pwrdwnInit(NULL) != CSL_SOK)
          exit;
        // Opening a handle for the Module	
    	hPwr = CSL_pwrdwnOpen (&pwrObj, CSL_PWRDWN_0, NULL, NULL);
    
	    CSL_pwrdwnUmap1pageWake(hPwr,0xFFFF00FF);
     @endverbatim
 * ===========================================================================
 */
CSL_IDEF_INLINE
CSL_Status CSL_pwrdwnUmap1pageWake (
    CSL_PwrdwnHandle hPwr,
    CSL_BitMask32 wake
)
{
    hPwr->l2pwrdwnRegs->L2PDWAKE[1] = wake;
    
    return CSL_SOK;
}


/** ============================================================================
 *   @n@b  CSL_pwrdwnUmap0pageAutoEnable
 *
 *   @b Description
 *   @n Umap 0 page auto sleep enable.
 *
 *   @b Arguments
 *   @verbatim

         hPwr       Handle to the power down module

         pageMask  BitMask of pages to be auto-power down enabled
                   (based on elapse of either Period A/B)
                   
         periodB   Whether the auto sleep is based on Period A/B. 
                   A 'TRUE' indicated PeriodB, \n
                   A 'FALSE' indicated PeriodA.      

     @endverbatim
 *
 *   <b> Return Value </b>  Status (CSL_SOK)
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

     	CSL_PwrdwnObj pwrObj;
    CSL_PwrdwnConfig pwrConfig;
    CSL_PwrdwnHandle hPwr;
    // Init Module
    ...
    if (CSL_pwrdwnInit(NULL) != CSL_SOK)
       exit;
    // Opening a handle for the Module	
	hPwr = CSL_pwrdwnOpen (&pwrObj, CSL_PWRDWN_0, NULL, NULL);
    
	CSL_pwrdwnUmap0pageAutoEnable(hPwr,0xFFFF00FF,TRUE);
    
	    CSL_pwrdwnUmap1pageWake(hPwr,0xFFFF00FF);
     @endverbatim
 * ===========================================================================
 */
CSL_IDEF_INLINE
CSL_Status CSL_pwrdwnUmap0pageAutoEnable (
    CSL_PwrdwnHandle hPwr, 
    Uint32 pageMask, 
    Bool periodB
)
{
    hPwr->l2pwrdwnRegs->L2PDAEN[0] |= pageMask;
    
    if (periodB) {
	    hPwr->l2pwrdwnRegs->L2PDAPS[0] |= (pageMask);	
    }
    else {
		hPwr->l2pwrdwnRegs->L2PDAPS[0] &= ~(pageMask);
    }
    
    return CSL_SOK;
}



/** ============================================================================
 *   @n@b  CSL_pwrdwnUmap1pageAutoEnable
 *
 *   @b Description
 *   @n Umap 1 page auto sleep enable.
 *
 *   @b Arguments
 *   @verbatim

         hPwr       Handle to the power down module

         pageMask  BitMask of pages to be auto-power down enabled
                   (based on elapse of either Period A/B)
                   
         periodB   Whether the auto sleep is based on Period A/B. 
                   A 'TRUE' indicated PeriodB, \n
                   A 'FALSE' indicated PeriodA.      

     @endverbatim
 *
 *   <b> Return Value </b>  Status (CSL_SOK)
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

     	CSL_PwrdwnObj pwrObj;
    CSL_PwrdwnConfig pwrConfig;
    CSL_PwrdwnHandle hPwr;
    // Init Module
    ...
    if (CSL_pwrdwnInit(NULL) != CSL_SOK)
       exit;
    // Opening a handle for the Module	
	hPwr = CSL_pwrdwnOpen (&pwrObj, CSL_PWRDWN_0, NULL, NULL);
    
	CSL_pwrdwnUmap1pageAutoEnable(hPwr,0xFFFF00FF,TRUE);
    
	    CSL_pwrdwnUmap1pageWake(hPwr,0xFFFF00FF);
     @endverbatim
 * ===========================================================================
 */
CSL_IDEF_INLINE
CSL_Status CSL_pwrdwnUmap1pageAutoEnable (
    CSL_PwrdwnHandle hPwr,
    Uint32 pageMask, 
    Bool periodB
)
{
    hPwr->l2pwrdwnRegs->L2PDAEN[1] |= (pageMask);
    
    if (periodB) {
		hPwr->l2pwrdwnRegs->L2PDAPS[1] |= (pageMask);
    }
	else {		
		hPwr->l2pwrdwnRegs->L2PDAPS[1] &= ~(pageMask);
    }
    
	return CSL_SOK;	
}


/** ============================================================================
 *   @n@b  CSL_pwrdwnUmap0pageAutoDisable
 *
 *   @b Description
 *   @n  Umap 0 page auto sleep disable.
 *
 *   @b Arguments
 *   @verbatim

         hPwr       Handle to the power down module

         dis        BitMask of the Umap 0 for which auto-sleep needs to be
                    disabled./B).      

     @endverbatim
 *
 *   <b> Return Value </b>  Status (CSL_SOK)
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

      CSL_PwrdwnObj pwrObj;
      CSL_PwrdwnConfig pwrConfig;
      CSL_PwrdwnHandle hPwr;
      // Init Module
      ...
      if (CSL_pwrdwnInit(NULL) != CSL_SOK)
         exit;
      // Opening a handle for the Module	
      hPwr = CSL_pwrdwnOpen (&pwrObj, CSL_PWRDWN_0, NULL, NULL);
      CSL_pwrdwnUmap0pageAutoDisable(hPwr,0xFFFF00FF);
      
     @endverbatim
 * ===========================================================================
 */
CSL_IDEF_INLINE
CSL_Status CSL_pwrdwnUmap0pageAutoDisable (
    CSL_PwrdwnHandle hPwr,
    CSL_BitMask32 dis
)
{
    hPwr->l2pwrdwnRegs->L2PDAEN[0] &= ~(dis);
    
    return CSL_SOK;
}



/** ============================================================================
 *   @n@b  CSL_pwrdwnUmap1pageAutoDisable
 *
 *   @b Description
 *   @n  Umap 1 page auto sleep disable.
 *
 *   @b Arguments
 *   @verbatim

         hPwr       Handle to the power down module

         dis        BitMask of the Umap 1 for which auto-sleep needs to be
                    disabled./B).      

     @endverbatim
 *
 *   <b> Return Value </b>  Status (CSL_SOK)
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

      CSL_PwrdwnObj pwrObj;
      CSL_PwrdwnConfig pwrConfig;
      CSL_PwrdwnHandle hPwr;
      // Init Module
      ...
      if (CSL_pwrdwnInit(NULL) != CSL_SOK)
         exit;
      // Opening a handle for the Module	
      hPwr = CSL_pwrdwnOpen (&pwrObj, CSL_PWRDWN_0, NULL, NULL);
      CSL_pwrdwnUmap1pageAutoDisable(hPwr,0xFFFF00FF);
      
     @endverbatim
 * ===========================================================================
 */
CSL_IDEF_INLINE
CSL_Status CSL_pwrdwnUmap1pageAutoDisable (
    CSL_PwrdwnHandle hPwr,
    CSL_BitMask32 dis
)
{
    hPwr->l2pwrdwnRegs->L2PDAEN[1] &= ~(dis);
    
    return CSL_SOK;
}


/** ============================================================================
 *   @n@b  CSL_pwrdwnGetUmap0SleepStatus
 *
 *   @b Description
 *   @n  Queries Umap 0 page status.
 *
 *   @b Arguments
 *   @verbatim

         hPwr       Handle to the power down module

     @endverbatim
 *
 *   <b> Return Value </b>  Status (CSL_SOK)
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

      CSL_PwrdwnObj pwrObj;
      CSL_PwrdwnConfig pwrConfig;
      CSL_PwrdwnHandle hPwr;
      CSL_BitMask32 statusL2;
      // Init Module
      ...
      if (CSL_pwrdwnInit(NULL) != CSL_SOK)
         exit;
      // Opening a handle for the Module	
	  hPwr = CSL_pwrdwnOpen (&pwrObj, CSL_PWRDWN_0, NULL, NULL);
    
      statusL2 = CSL_pwrdwnGetUmap0SleepStatus(hPwr);
      
     @endverbatim
 * ===========================================================================
 */
CSL_IDEF_INLINE 
CSL_BitMask32 CSL_pwrdwnGetUmap0SleepStatus (
    CSL_PwrdwnHandle hPwr
)
{
    return hPwr->l2pwrdwnRegs->L2PDSTAT[0];
}



/** ============================================================================
 *   @n@b  CSL_pwrdwnGetUmap1SleepStatus
 *
 *   @b Description
 *   @n  Queries Umap 1 page status.
 *
 *   @b Arguments
 *   @verbatim

         hPwr       Handle to the power down module

     @endverbatim
 *
 *   <b> Return Value </b>  Status (CSL_SOK)
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

      CSL_PwrdwnObj pwrObj;
      CSL_PwrdwnConfig pwrConfig;
      CSL_PwrdwnHandle hPwr;
      CSL_BitMask32 statusL2;
      // Init Module
      ...
      if (CSL_pwrdwnInit(NULL) != CSL_SOK)
         exit;
      // Opening a handle for the Module	
	  hPwr = CSL_pwrdwnOpen (&pwrObj, CSL_PWRDWN_0, NULL, NULL);
    
      statusL2 = CSL_pwrdwnGetUmap1SleepStatus(hPwr);
      
     @endverbatim
 * ===========================================================================
 */
CSL_IDEF_INLINE
CSL_BitMask32 CSL_pwrdwnGetUmap1SleepStatus (
    CSL_PwrdwnHandle hPwr
)
{
    return hPwr->l2pwrdwnRegs->L2PDSTAT[1];
}

#ifdef __cplusplus
extern "C" {
#endif

/**
@}
*/
#endif /* _CSL_PWRDWNAUX_H_ */

