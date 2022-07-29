/*****************************************************\
 *  Copyright 2003, Texas Instruments Incorporated.  *
 *  All rights reserved.                             *
 *  Restricted rights to use, duplicate or disclose  *
 *  this   code   are  granted   through  contract.  *
 \*****************************************************/

/*  @(#) PSP/CSL 3.00.01.00[5912PG1_0] (2003-11-12)  */

/** @file _csl_mcbsp.h
 *
 *  @brief Header file for private functional layer of McBSP CSL
 */

#ifndef __CSL_MCBSP_H_
#define __CSL_MCBSP_H_

#include <csl_types.h>
#include <csl_error.h>
#include <csl_mcbsp.h>

/**************************************************************************\
* MCBSP Private function declarations
\**************************************************************************/

/*
 * ======================================================
 *   @func   _csl_mcbspBlockAssign.c
 *   @desc   The funtion is used to assign block to a particular partition
 *                This is an Internal function and is used by the CSL_mcbspHwControl
 *                function
 *
 *
 *   @arg  hMcbsp
 *              Handle of the McBSP
 *   @arg  partition
 *              Partition to which the block is to be assigned to
 *   @arg  block
 *              Identifies the block
 *   @ret  CSL_Status
 *
 *          CSL_SOK: Successful completion
 *          CSL_ESYS_FAIL: Operation could not the done
 *
 *   @eg
 *     _CSL_mcbspBlockAssign(hMcbsp, CSL_MCBSP_PARTITION_ATX, CSL_MCBSP_BLOCK0);
 *
 * ======================================================
*/
CSL_Status  _CSL_mcbspBlockAssign(
    CSL_McbspHandle                         hMcbsp,
    CSL_McbspPartition                      partition,
    CSL_McbspBlock                          block
);


/*
 * ======================================================
 *   @func   _CSL_mcbspGetAttrs.c
 *   @desc   Function retreives the attributes for the specified MCBSP
 *         onto the Handle passed. This is an Internal function for CSL.
 *         hMcbsp->regs will point to the overlay structure of the specified MCBSP.
 *
 *
 *   @arg  mcbspNum
 *              Tells the MCBSP to be used.
 *   @arg  hMcbsp
 *              Handle to MCBSP Obj used.
 *
 *   @ret  void.
 *
 *   @eg
 *     _CSL_mcbspGetAttrs(CSL_MCBSP_0, hMcbsp);
 *
 * ======================================================
*/
void  _CSL_mcbspGetAttrs(
    CSL_InstNum                            mcbspNum,
    CSL_McbspHandle                        hMcbsp
);


/*
 * ======================================================
 *   @func   _csl_mcbspChannelControl.c
 *   @desc   Eanble one Channel in Multi Channel Selection Mode
 *
 *
 *   @arg  hMcbsp
 *              Device Handle;
 *   @arg  channelNo
 *              Channel Number
 *   @arg  block
 *              Block to which the channel belongs to
 *   @arg  operation
 *              The operation to be performed
 *   @ret  CSL_Status
 *
 *
 *   @eg
 *     MCBSP_Handle hMcbsp;
 *     hMcbsp = CSL_mcbspOpen(hMcbsp, CSL_MCBSP_0, CSL_EXCLUSIVE, &status, NULL);
 *     _CSL_mcbspChannelControl( hMcbsp, 11, 1, CSL_MCBSP_CHAN_RX_ENABLE);
 *
 *
 * ======================================================
*/

CSL_Status  _CSL_mcbspChannelControl(
    CSL_McbspHandle                       hMcbsp,
    Uint16                                channelNo,
    CSL_McbspBlock                        block,
    CSL_McbspChCtrl                       operation
);

/*
 * ======================================================
 *   @func   _csl_mcbspClearFrmSyncErr.c
 *   @desc   Clear Frame Sync Error for Receiver and Transmitter.
 *
 *
 *   @arg  hMcbsp
 *              Device Handle;
 *   @arg  chanType
 *              Selects receiver/transmitter.
 *   @ret  void
 *               None
 *
 *   @eg
 *     CSL_McbspHandle hMcbsp;
 *     hMcbsp = CSL_mcbspOpen(hMcbsp, CSL_MCBSP_0, CSL_EXCLUSIVE, &status, NULL);
 *     _CSL_mcbspClearFrmSyncErr( hMcbsp, CSL_MCBSP_RX);
 *
 *
 * ======================================================
*/

void  _CSL_mcbspClearFrmSyncErr(
    CSL_McbspHandle                         hMcbsp,
    CSL_McbspChType                       chanType
);

/*
 * ======================================================
 *   @func   _csl_mcbspIoModeCtrl.c
 *   @desc   Configure selected McBSP pins for Input/Output
 *
 *
 *   @arg  hMcbsp
 *              Device Handle;
 *   @arg  outputSel
 *              Select Pins for output. Bitwise OR of CSL_MCBSP_IO_XXXX
 *   @arg  inputSel
 *              Select Pins for input. Bitwise OR of CSL_MCBSP_IO_XXXX
 *   @ret  void
 *
 *
 *   @eg
 *     CSL_McbspHandle hMcbsp;
 *     hMcbsp = CSL_mcbspOpen(hMcbsp, CSL_MCBSP_0, CSL_EXCLUSIVE, &status, NULL);
 *     _CSL_mcbspIoModeCtrl( hMcbsp,  CSL_MCBSP_IO_CLKX | CSL_MCBSP_IO_CLKR,
 *                                         CSL_MCBSP_IO_FSX | CSL_MCBSP_IO_CLKR );
 *
 * ======================================================
*/

void  _CSL_mcbspIoModeCtrl(
    CSL_McbspHandle                         hMcbsp,
    CSL_BitMask16                           outputSel,
    CSL_BitMask16                           inputSel
);

/*
 * ======================================================
 *   @func   _csl_mcbspResetCtrl.c
 *   @desc   Enable/Disable Frame Sync Logic/Sample Rate Generator and Receiver and Transmitter Operation
 *
 *
 *   @arg  hMcbsp
 *              Device Handle
 *   @arg  selectMask
 *              Selects enable/disable of receiverCfg/transmitter. Bitwise OR of MCBSP_CTRL_XXXX
 *   @ret  void
 *               None
 *
 *
 *   @eg
 *     CSL_McbspHandle hMcbsp;
 *     hMcbsp = CSL_mcbspOpen(hMcbsp, CSL_MCBSP_0, CSL_EXCLUSIVE, &status, NULL);
 *     _CSL_mcbspResetCtrl( hMcbsp, CSL_MCBSP_CTRL_SRG_ENABLE | CSL_MCBSP_CTRL_FSYNC_DISABLE
 *                                 | CSL_MCBSP_CTRL_RX_ENABLE
 *                                 | CSL_MCBSP_CTRL_TX_ENABLE );
 *
 * ======================================================
*/

void  _CSL_mcbspResetCtrl(
    CSL_McbspHandle                         hMcbsp,
    CSL_BitMask16                           selectMask
);

/*
 * ======================================================
 *   @func   _csl_mcbspRegReset.c
 *   @desc   Function to reset all the registers values
 *
 *
 *   @arg  hMcbsp
 *              Device Handle;
 *   @ret  void
 *               None
 *
 *
 *   @eg
 *     CSL_McbspHandle hMcbsp;
 *     hMcbsp = CSL_mcbspOpen(hMcbsp, CSL_MCBSP_0, CSL_EXCLUSIVE, &status, NULL);
 *     _CSL_mcbspRegReset(hMcbsp);
 *
 *
 * ======================================================
*/

void  _CSL_mcbspRegReset(
    CSL_McbspHandle                         hMcbsp
);

#endif

