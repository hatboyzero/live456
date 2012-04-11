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
// Copyright (c) 2012 Matthew Alan Gray - All rights reserved.
// RTP sink for H.264 video (RFC 3984)
// C++ header
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef H264_VIDEO_RTP_SINK_HH_INCLUDED
#define H264_VIDEO_RTP_SINK_HH_INCLUDED

#include "Configuration.hpp"

#include "VideoRTPSink.hh"
#include "FramedFilter.hh"

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
class H264FUAFragmenter;

class LIVEMEDIA_DLL_LINK H264VideoRTPSink
:   public VideoRTPSink
{
    /// @name Types
    /// @{
public:
    /// @}

    /// @name MediaSink implementation
    /// @{
public:
private:
    virtual Boolean sourceIsCompatibleWithUs(MediaSource& source);
    /// @}

    /// @name RTPSink implementation
    /// @{
public:
protected:
    virtual char const* auxSDPLine();
    /// @}

    /// @name MultiFramedRTPSink implementation
    /// @{
public:
private:
    virtual void doSpecialFrameHandling(unsigned fragmentationOffset,
                                        unsigned char* frameStart,
                                        unsigned numBytesInFrame,
                                        struct timeval framePresentationTime,
                                        unsigned numRemainingBytes);
    virtual Boolean frameCanAppearAfterPacketStart(unsigned char const* frameStart,
                                                   unsigned numBytesInFrame) const;
    virtual void stopPlaying();
    virtual Boolean continuePlaying();
    /// @}

    /// @name VideoRTPSink implementation
    /// @{
public:
    /// @}

    /// @name H264VideoRTPSink implementation
    /// @{
public:
    static H264VideoRTPSink* createNew(UsageEnvironment& env,
                                       Groupsock* RTPgs,
                                       unsigned char rtpPayloadFormat);

    static H264VideoRTPSink* createNew(UsageEnvironment& env,
                                       Groupsock* RTPgs,
                                       unsigned char rtpPayloadFormat,
                                       u_int8_t const* sps,
                                       unsigned spsSize,
                                       u_int8_t const* pps,
                                       unsigned ppsSize);

    /// An optional variant of "createNew()", useful if we know, in advance, the 
    /// stream's SPS and PPL NAL units.
    static H264VideoRTPSink* createNew(UsageEnvironment& env,
                                       Groupsock* RTPgs,
                                       unsigned char rtpPayloadFormat,
                                       char const* sPropParameterSetsStr);
    /// @}

    /// @name Inner Structures
    /// @{
protected:
    //-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
    // Because of the ideosyncracies of the H.264 RTP payload format, we implement
    // "H264VideoRTPSink" using a separate "H264FUAFragmenter" class that delivers,
    // to the "H264VideoRTPSink", only fragments that will fit within an outgoing
    // RTP packet.  I.e., we implement fragmentation in this separate "H264FUAFragmenter"
    // class, rather than in "H264VideoRTPSink".
    // (Note: This class should be used only by "H264VideoRTPSink", or a subclass.)
    class LIVEMEDIA_DLL_LINK H264FUAFragmenter
    :   public FramedFilter
    {
        /// @name Types
        /// @{
    public:
        /// @}

        /// @name FramedSource implementation
        /// @{
    public:
    private:
        virtual void doGetNextFrame();
        /// @}

        /// @name FramedFilter implementation
        /// @{
    public:
        /// @}

        /// @name H264FUAFragmenter implementation
        /// @{
    public:
        Boolean lastFragmentCompletedNALUnit() const
        {
            return fLastFragmentCompletedNALUnit;
        }
    private:
        static void afterGettingFrame(void* clientData,
                                      unsigned frameSize,
                                      unsigned numTruncatedBytes,
                                      struct timeval presentationTime,
                                      unsigned durationInMicroseconds);
        void afterGettingFrame1(unsigned frameSize,
                                unsigned numTruncatedBytes,
                                struct timeval presentationTime,
                                unsigned durationInMicroseconds);
        /// @}

        /// @name 'Structors
        /// @{
    public:
                 H264FUAFragmenter(UsageEnvironment& env,
                                   FramedSource* inputSource,
                                   unsigned inputBufferMax,
                                   unsigned maxOutputPacketSize);
        virtual ~H264FUAFragmenter();
        /// @}

        /// @name Member Variables
        /// @{
    private:
        unsigned        fInputBufferSize;
        unsigned        fMaxOutputPacketSize;
        unsigned char*  fInputBuffer;
        unsigned        fNumValidDataBytes;
        unsigned        fCurDataOffset;
        unsigned        fSaveNumTruncatedBytes;
        Boolean         fLastFragmentCompletedNALUnit;
        /// @}

    };  // class H264FUAFragmenter
    //-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
    /// @}

    /// @name 'Structors
    /// @{
protected:
             H264VideoRTPSink(UsageEnvironment& env,
                              Groupsock* RTPgs,
                              unsigned char rtpPayloadFormat,
                              u_int8_t const* sps = NULL,
                              unsigned spsSize = 0,
                              u_int8_t const* pps = NULL,
                              unsigned ppsSize = 0);
    virtual ~H264VideoRTPSink();
    /// @}

    /// @name Member Variables
    /// @{
private:
    char*               fFmtpSDPLine;
    u_int8_t*           fSPS;
    unsigned            fSPSSize;
    u_int8_t*           fPPS;
    unsigned            fPPSSize;
protected:
    H264FUAFragmenter*  fOurFragmenter;
    /// @}

};  // class H264VideoRTPSink

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif  // H264_VIDEO_RTP_SINK_HH_INCLUDED
