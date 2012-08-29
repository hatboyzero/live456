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
// "liveMedia"
// Copyright (c) 1996-2012 Live Networks, Inc.  All rights reserved.
// A 'ServerMediaSubsession' object that creates new, unicast, "RTPSink"s
// on demand, from a stream.
// C++ header

#ifndef _STREAM_SERVER_MEDIA_SUBSESSION_HH
#define _STREAM_SERVER_MEDIA_SUBSESSION_HH

#include "Configuration.hpp"

#ifndef _ON_DEMAND_SERVER_MEDIA_SUBSESSION_HH
#include "OnDemandServerMediaSubsession.hh"
#endif

class LIVEMEDIA_DLL_LINK StreamServerMediaSubsession: public OnDemandServerMediaSubsession {
protected: // we're a virtual base class
  StreamServerMediaSubsession(UsageEnvironment& _env, Boolean reuseFirstSource);
  virtual ~StreamServerMediaSubsession();

public:
    void setFramedSource(FramedSource* inputSource);

protected:
  FramedSource* fInputSource;
};

#endif
