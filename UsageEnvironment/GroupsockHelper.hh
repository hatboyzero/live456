/**********
This library is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the
Free Software Foundation; either version 2.1 of the License, or (at your
option) any later version. (See <http://www.gnu.org/copyleft/lesser.html>.)

This library is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General Public License
along with this library; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
**********/
// "mTunnel" multicast access service
// Copyright (c) 1996-2012 Live Networks, Inc.  All rights reserved.
// Helper routines to implement 'group sockets'
// C++ header

#ifndef _GROUPSOCK_HELPER_HH
#define _GROUPSOCK_HELPER_HH

#include "Configuration.hpp"

#ifndef _NET_ADDRESS_HH
#include "NetAddress.hh"
#endif

USAGEENVIRONMENT_DLL_LINK int setupDatagramSocket(UsageEnvironment& env, Port port);
USAGEENVIRONMENT_DLL_LINK int setupStreamSocket(UsageEnvironment& env,
		      Port port, Boolean makeNonBlocking = True);

USAGEENVIRONMENT_DLL_LINK int readSocket(UsageEnvironment& env,
	       int socket, unsigned char* buffer, unsigned bufferSize,
	       struct sockaddr_in& fromAddress);

USAGEENVIRONMENT_DLL_LINK Boolean writeSocket(UsageEnvironment& env,
		    int socket, struct in_addr address, Port port,
		    u_int8_t ttlArg,
		    unsigned char* buffer, unsigned bufferSize);

USAGEENVIRONMENT_DLL_LINK unsigned getSendBufferSize(UsageEnvironment& env, int socket);
USAGEENVIRONMENT_DLL_LINK unsigned getReceiveBufferSize(UsageEnvironment& env, int socket);
USAGEENVIRONMENT_DLL_LINK unsigned setSendBufferTo(UsageEnvironment& env,
			 int socket, unsigned requestedSize);
USAGEENVIRONMENT_DLL_LINK unsigned setReceiveBufferTo(UsageEnvironment& env,
			    int socket, unsigned requestedSize);
USAGEENVIRONMENT_DLL_LINK unsigned increaseSendBufferTo(UsageEnvironment& env,
			      int socket, unsigned requestedSize);
USAGEENVIRONMENT_DLL_LINK unsigned increaseReceiveBufferTo(UsageEnvironment& env,
				 int socket, unsigned requestedSize);

USAGEENVIRONMENT_DLL_LINK Boolean makeSocketNonBlocking(int sock);
USAGEENVIRONMENT_DLL_LINK Boolean makeSocketBlocking(int sock);

USAGEENVIRONMENT_DLL_LINK Boolean socketJoinGroup(UsageEnvironment& env, int socket,
			netAddressBits groupAddress);
USAGEENVIRONMENT_DLL_LINK Boolean socketLeaveGroup(UsageEnvironment&, int socket,
			 netAddressBits groupAddress);

// source-specific multicast join/leave
USAGEENVIRONMENT_DLL_LINK Boolean socketJoinGroupSSM(UsageEnvironment& env, int socket,
			   netAddressBits groupAddress,
			   netAddressBits sourceFilterAddr);
USAGEENVIRONMENT_DLL_LINK Boolean socketLeaveGroupSSM(UsageEnvironment&, int socket,
			    netAddressBits groupAddress,
			    netAddressBits sourceFilterAddr);

USAGEENVIRONMENT_DLL_LINK Boolean getSourcePort(UsageEnvironment& env, int socket, Port& port);

USAGEENVIRONMENT_DLL_LINK netAddressBits ourIPAddress(UsageEnvironment& env); // in network order

// IP addresses of our sending and receiving interfaces.  (By default, these
// are INADDR_ANY (i.e., 0), specifying the default interface.)
//extern netAddressBits SendingInterfaceAddr;
USAGEENVIRONMENT_DLL_LINK netAddressBits& getSendingInterfaceAddr();
//extern netAddressBits ReceivingInterfaceAddr;
USAGEENVIRONMENT_DLL_LINK netAddressBits& getReceivingInterfaceAddr();

// Allocates a randomly-chosen IPv4 SSM (multicast) address:
USAGEENVIRONMENT_DLL_LINK netAddressBits chooseRandomIPv4SSMAddress(UsageEnvironment& env);

// Returns a simple "hh:mm:ss" string, for use in debugging output (e.g.)
USAGEENVIRONMENT_DLL_LINK char const* timestampString();


#ifdef HAVE_SOCKADDR_LEN
#define SET_SOCKADDR_SIN_LEN(var) var.sin_len = sizeof var
#else
#define SET_SOCKADDR_SIN_LEN(var)
#endif

#define MAKE_SOCKADDR_IN(var,adr,prt) /*adr,prt must be in network order*/\
    struct sockaddr_in var;\
    var.sin_family = AF_INET;\
    var.sin_addr.s_addr = (adr);\
    var.sin_port = (prt);\
    SET_SOCKADDR_SIN_LEN(var);


// By default, we create sockets with the SO_REUSE_* flag set.
// If, instead, you want to create sockets without the SO_REUSE_* flags,
// Then enclose the creation code with:
//          {
//            NoReuse dummy;
//            ...
//          }
class USAGEENVIRONMENT_DLL_LINK NoReuse {
public:
  NoReuse(UsageEnvironment& env);
  ~NoReuse();

private:
  UsageEnvironment& fEnv;
};


// Define the "UsageEnvironment"-specific "groupsockPriv" structure:

struct _groupsockPriv { // There should be only one of these allocated
  HashTable* socketTable;
  int reuseFlag;
};
USAGEENVIRONMENT_DLL_LINK _groupsockPriv* groupsockPriv(UsageEnvironment& env); // allocates it if necessary
USAGEENVIRONMENT_DLL_LINK void reclaimGroupsockPriv(UsageEnvironment& env);


#if defined(__WIN32__) || defined(_WIN32)
// For Windoze, we need to implement our own gettimeofday()
USAGEENVIRONMENT_DLL_LINK int gettimeofday(struct timeval*, int*);
USAGEENVIRONMENT_DLL_LINK int initializeWinsockIfNecessary(void);
#endif

// The following are implemented in inet.c:
USAGEENVIRONMENT_DLL_LINK netAddressBits our_inet_addr(char const*);
USAGEENVIRONMENT_DLL_LINK void our_srandom(unsigned int x);
USAGEENVIRONMENT_DLL_LINK long our_random();
USAGEENVIRONMENT_DLL_LINK u_int32_t our_random32(); // because "our_random()" returns a 31-bit number

#endif
