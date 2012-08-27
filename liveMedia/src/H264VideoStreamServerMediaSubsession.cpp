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
// on demand, from a H264 video stream.
// Implementation

#include "../H264VideoStreamServerMediaSubsession.hh"
#include "../H264VideoRTPSink.hh"
#include "../H264VideoStreamFramer.hh"

H264VideoStreamServerMediaSubsession*
H264VideoStreamServerMediaSubsession::createNew(UsageEnvironment& env,
                                                Boolean reuseFirstSource) {
    return new H264VideoStreamServerMediaSubsession(env, reuseFirstSource);
}

H264VideoStreamServerMediaSubsession::H264VideoStreamServerMediaSubsession(UsageEnvironment& env,
                                                                           Boolean reuseFirstSource)
:   StreamServerMediaSubsession(env, reuseFirstSource)
,   fAuxSDPLine(NULL)
,   fDoneFlag(0)
,   fDummyRTPSink(NULL)
,   fInputSource(NULL)
{
}

H264VideoStreamServerMediaSubsession::~H264VideoStreamServerMediaSubsession()
{
    delete[] fAuxSDPLine;
}

void H264VideoStreamServerMediaSubsession::setFramedSource(FramedSource* inputSource)
{
    fInputSource = inputSource;
}

static void afterPlayingDummy(void* clientData) {
    H264VideoStreamServerMediaSubsession* subsess = (H264VideoStreamServerMediaSubsession*)clientData;
    subsess->afterPlayingDummy1();
}

void H264VideoStreamServerMediaSubsession::afterPlayingDummy1() {
  // Unschedule any pending 'checking' task:
  envir().taskScheduler().unscheduleDelayedTask(nextTask());
  // Signal the event loop that we're done:
  setDoneFlag();
}

char const* H264VideoStreamServerMediaSubsession::sdpLines()
{
  if (fSDPLines == NULL) {
    // We need to construct a set of SDP lines that describe this
    // subsession (as a unicast stream).  To do so, we first create
    // dummy (unused) source and "RTPSink" objects,
    // whose parameters we use for the SDP lines:
    unsigned estBitrate;
    FramedSource* inputSource = createNewStreamSource(0, estBitrate);
    if (inputSource == NULL) return NULL; // file not found

    struct in_addr dummyAddr;
    dummyAddr.s_addr = 0;
    Groupsock dummyGroupsock(envir(), dummyAddr, 0, 0);
    unsigned char rtpPayloadType = 96 + trackNumber()-1; // if dynamic
    RTPSink* dummyRTPSink
      = createNewRTPSink(&dummyGroupsock, rtpPayloadType, inputSource);

    setSDPLinesFromRTPSink(dummyRTPSink, inputSource, estBitrate);
    Medium::close(dummyRTPSink);
    closeStreamSource(inputSource);
  }

  return fSDPLines;
}

static void checkForAuxSDPLine(void* clientData) {
    H264VideoStreamServerMediaSubsession* subsess = (H264VideoStreamServerMediaSubsession*)clientData;
    subsess->checkForAuxSDPLine1();
}

void H264VideoStreamServerMediaSubsession::checkForAuxSDPLine1() {
  char const* dasl = NULL;

  if (fAuxSDPLine != NULL) {
    // Signal the event loop that we're done:
    setDoneFlag();
  } else if (fDummyRTPSink != NULL && (dasl = fDummyRTPSink->auxSDPLine()) != NULL) {
    fAuxSDPLine = strDup(dasl);
    fDummyRTPSink = NULL;

    // Signal the event loop that we're done:
    setDoneFlag();
  } else {
    // try again after a brief delay:
    int uSecsToDelay = 100000; // 100 ms
    nextTask() = envir().taskScheduler().scheduleDelayedTask(uSecsToDelay,
			      (TaskFunc*)checkForAuxSDPLine, this);
  }
}

char const* H264VideoStreamServerMediaSubsession::getAuxSDPLine(RTPSink* rtpSink, FramedSource* inputSource) {
  if (fAuxSDPLine != NULL) return fAuxSDPLine; // it's already been set up (for a previous client)

  if (fDummyRTPSink == NULL) { // we're not already setting it up for another, concurrent stream
    // Note: For H264 video files, the 'config' information ("profile-level-id" and "sprop-parameter-sets") isn't known
    // until we start reading the file.  This means that "rtpSink"s "auxSDPLine()" will be NULL initially,
    // and we need to start reading data from our file until this changes.
    fDummyRTPSink = rtpSink;

    // Start reading the file:
    fDummyRTPSink->startPlaying(*inputSource, afterPlayingDummy, this);

    // Check whether the sink's 'auxSDPLine()' is ready:
    checkForAuxSDPLine(this);
  }

  envir().taskScheduler().doEventLoop(&fDoneFlag);

  return fAuxSDPLine;
}

FramedSource* H264VideoStreamServerMediaSubsession::createNewStreamSource(unsigned /*clientSessionId*/, unsigned& estBitrate) {
  estBitrate = 500;
  return fInputSource;
}

void H264VideoStreamServerMediaSubsession::closeStreamSource(FramedSource* /*inputSource*/)
{
}

RTPSink* H264VideoStreamServerMediaSubsession
::createNewRTPSink(Groupsock* rtpGroupsock,
		   unsigned char rtpPayloadTypeIfDynamic,
		   FramedSource* /*inputSource*/) {
  return H264VideoRTPSink::createNew(envir(), rtpGroupsock, rtpPayloadTypeIfDynamic);
}
