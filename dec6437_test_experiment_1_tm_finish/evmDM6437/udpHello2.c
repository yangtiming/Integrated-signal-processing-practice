/*
 *  Copyright 2007 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *
 *  @(#) TCP/IP_Network_Developers_Kit 1.92.00.22 01-10-2007 (ndk-b22)
 */
//--------------------------------------------------------------------------
// IP Stack Server Demonstration Program
//--------------------------------------------------------------------------
// UDPHELLO.C
//
// This program implements a UDP echo server, which echos back any
// input it receives.
//
// Author: Mike A. Denio
//         Magdalena B. Iovescu
// Copyright 1999, 2000 by Texas Instruments Inc.
//-------------------------------------------------------------------------
#include <netmain.h>

//
// dtask_udp_hello() - UDP Echo Server Daemon Function
// (SOCK_DGRAM, port 7)
//
// Returns "1" if socket 's' is still open, and "0" if its been closed
//
int dtask_udp_hello( SOCKET s, UINT32 unused )
{
    struct sockaddr_in sin1;
    struct timeval     to;
    int                i,tmp;
    char               *pBuf;
    HANDLE             hBuffer;

    (void)unused;

    // Configure our socket timeout to be 3 seconds
    to.tv_sec  = 3;
    to.tv_usec = 0;
    setsockopt( s, SOL_SOCKET, SO_SNDTIMEO, &to, sizeof( to ) );
    setsockopt( s, SOL_SOCKET, SO_RCVTIMEO, &to, sizeof( to ) );

    for(;;)
    {
        tmp = sizeof( sin1 );
        i = (int)recvncfrom( s, (void **)&pBuf, 0, &sin1, &tmp, &hBuffer );

        // Spit any data back out
        if( i >= 0 )
        {
            sendto( s, pBuf, i, 0, &sin1, sizeof(sin1) );
            recvncfree( hBuffer );
        }
        else
            break;
    }

    // Since the socket is still open, return "1"
    // (we need to leave UDP sockets open)
    return(1);    
}


