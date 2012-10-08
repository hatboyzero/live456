//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License as published by the
// Free Software Foundation; either version 2.1 of the License, or (at your
// option) any later version. (See <http://www.gnu.org/copyleft/lesser.html>.)
// 
// This library is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
// more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this library; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// "liveMedia"
// Copyright (c) 1996-2012 Live Networks, Inc.  All rights reserved.
// A 'ServerMediaSubsession' object that creates new, unicast, "RTPSink"s
// on demand, from a H264 Elementary Stream video stream.
// C++ header
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef _H264_VIDEO_STREAM_SERVER_MEDIA_SUBSESSION_HH
#define _H264_VIDEO_STREAM_SERVER_MEDIA_SUBSESSION_HH

#include "Configuration.hpp"

#ifndef _STREAM_SERVER_MEDIA_SUBSESSION_HH
#include "StreamServerMediaSubsession.hh"
#endif

#include <string>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

class LIVEMEDIA_DLL_LINK H264VideoStreamServerMediaSubsession
:   public StreamServerMediaSubsession
{
    /// @name H264VideoStreamServerMediaSubsession implementation
    /// @{
public:
    static H264VideoStreamServerMediaSubsession* createNew(UsageEnvironment& env,
                                                           Boolean reuseFirstSource,
                                                           I_StreamSourceFactory& _factory,
                                                           char const* spropStr = NULL);

    // Used to implement "getAuxSDPLine()":
    void checkForAuxSDPLine1();
    void afterPlayingDummy1();

    void setSProp(char const* spropStr);

protected:

    void setDoneFlag() { fDoneFlag = ~0; }

    virtual char const* getAuxSDPLine(RTPSink* rtpSink,
                                      FramedSource* inputSource);
    virtual FramedSource* createNewStreamSource(unsigned clientSessionId,
                                                unsigned& estBitrate);
    virtual RTPSink* createNewRTPSink(Groupsock* rtpGroupsock,
                                      unsigned char rtpPayloadTypeIfDynamic,
                                      FramedSource* inputSource);
    /// @}

    /// @name 'Structors
    /// @{
protected:
             H264VideoStreamServerMediaSubsession(UsageEnvironment& _env,
                                                  Boolean reuseFirstSource,
                                                  I_StreamSourceFactory& _factory,
                                                  char const* spropStr);
    virtual ~H264VideoStreamServerMediaSubsession();
    /// @}

    /// @name Member Variables
    /// @{
private:
    char* fAuxSDPLine;
    char fDoneFlag; // used when setting up "fAuxSDPLine"
    RTPSink* fDummyRTPSink; // ditto
    std::string fSPropStr;
    /// @}

};  // class H264VideoStreamServerMediaSubsession

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif  // _H264_VIDEO_STREAM_SERVER_MEDIA_SUBSESSION_HH
