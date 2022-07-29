/*
 *  Copyright 2006 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *
 *  @(#) TCP/IP_Network_Developers_Kit 1.92.00.13 11-17-2006 (ndk-b13)
 */
/*
 *  ======== evmdm6437init.c ========
 *
 */

#include <stdio.h>
#include <netmain.h>
#include <evmdm6437.h>
//#include <evmdm6437_eeprom.h>

// MDIO phy access functions
uint MDIO_phyRegWrite( uint phyIdx, uint phyReg, Uint16 data );

// This string array corresponds to link state as defined in dm6437_mdio.h
static char *LinkStr[] = { "No Link",
                           "10Mb/s Half Duplex",
                           "10Mb/s Full Duplex",
                           "100Mb/s Half Duplex",
                           "100Mb/s Full Duplex"};

static UINT8 bMacAddr[8]={0x0,0x9,0x0e,0x12,0x45,0x34,};

//
// Main Thread
//
// We changed our TCF file to point call this private init
// function. Here we initialize our board and read in our
// MAC address.
//
void dm6437_init()
{
    // Init the board
    EVMDM6437_init();

    // Read the MAC Address from EEPROM
   // EVMDM6437_EEPROM_read (0x00007F00, (Uint32) bMacAddr, 8);
}

//
// DM64LCEMAC_getConfig()
//
// This is a callback from the Ethernet driver. This function
// is used by the driver to get its 6 byte MAC address, and
// to determine which DSP interrupt the EMAC should be mapped to.
//
void DM64LCEMAC_getConfig( UINT8 *pMacAddr, uint *pIntVector )
{
    printf("Using MAC Address: %02x-%02x-%02x-%02x-%02x-%02x\n",
            bMacAddr[0], bMacAddr[1], bMacAddr[2],
            bMacAddr[3], bMacAddr[4], bMacAddr[5]);

    // We fill in the two pointers here. We'll use int 5 for EMAC
    mmCopy( pMacAddr, bMacAddr, 6 );
    *pIntVector = 5;
}

//
// DM64LCEMAC_linkStatus()
//
// This is a callback from the Ethernet driver. This function
// is called whenever there is a change in link state. The
// current PHY and current link state are passed as parameters.
//
void DM64LCEMAC_linkStatus( uint phy, uint linkStatus )
{
    printf("Link Status: %s on PHY %d\n",LinkStr[linkStatus],phy);

#if  0
    /* <TODO> Add the write function call to program LEDs for Micrel */
     
    // Program the LEDs for the Micrel PHY 
    MDIO_phyRegWrite( phy, 0x14, 0xd5d0 );
#endif

}

