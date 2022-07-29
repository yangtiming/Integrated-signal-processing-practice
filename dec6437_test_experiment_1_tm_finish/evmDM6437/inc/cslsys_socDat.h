/*  ============================================================================
 *   Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005                 
 *                                                                              
 *   Use of this software is controlled by the terms and conditions found in the
 *   license agreement under which this software has been supplied.             
 *   ===========================================================================
 */

#ifndef _SOCDAT_H_
#define _SOCDAT_H_
/**************************************************************************\
* 64 dat soc file
\**************************************************************************/
/**************************************************************************\
*  Parameterizable Configuration:- These are fed directly from the RTL 
*  parameters for the given SOC
\**************************************************************************/
/**************************************************************************\
* Channel Instance count
\**************************************************************************/
/** @brief Number of Generic Channel instances */


/** @brief Enumerations for EDMA channels
*
*  There are 8 QDMA channels -
*
*/

#define    CSL_DAT_QCHA0		   		      0 /**< QDMA Channel 0*/
#define    CSL_DAT_QCHA1		   		      1 /**< QDMA Channel 1*/
#define    CSL_DAT_QCHA2    	   		      2 /**< QDMA Channel 2*/
#define    CSL_DAT_QCHA3		   		      3 /**< QDMA Channel 3*/
#define    CSL_DAT_QCHA4		   		      4 /**< QDMA Channel 4*/
#define    CSL_DAT_QCHA5		   		      5 /**< QDMA Channel 5*/
#define    CSL_DAT_QCHA6		   		      6 /**< QDMA Channel 6*/
#define    CSL_DAT_QCHA7		   		      7 /**< QDMA Channel 7*/

/** @brief Enumerations for EDMA Event Queues
*
*  There are 8 Event Queues. Q0 is the highest priority and Q7 is the least priority
*
*/
typedef enum {
	CSL_DAT_PRI_DEFAULT   = 			   0, /**< Queue 0 is default */  
	CSL_DAT_PRI_0 		   = 			   0, /**< Queue 0 */  
	CSL_DAT_PRI_1 		   = 			   1, /**< Queue 1 */  
	CSL_DAT_PRI_2 		   = 			   2, /**< Queue 2 */  
	CSL_DAT_PRI_3 		   = 			   3, /**< Queue 3 */  
	CSL_DAT_PRI_4 		   = 			   4, /**< Queue 4 */  
	CSL_DAT_PRI_5 		   = 			   5, /**< Queue 5 */  
	CSL_DAT_PRI_6 		   = 			   6, /**< Queue 6 */  
	CSL_DAT_PRI_7 		   = 			   7  /**< Queue 7 */  
} CSL_DatPriority;

/** @brief Enumeration for EDMA Regions 
*
*  
*/

#define	CSL_DAT_REGION_GLOBAL  -1  /**< Global Region */
#define	CSL_DAT_REGION_0  0         /**< EDMA Region 0 */
#define	CSL_DAT_REGION_1  1         /**< EDMA Region 1 */
#define	CSL_DAT_REGION_2  2         /**< EDMA Region 2 */
#define	CSL_DAT_REGION_3  3         /**< EDMA Region 3 */

#endif
