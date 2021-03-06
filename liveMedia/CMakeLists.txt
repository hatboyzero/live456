cmake_minimum_required (VERSION 2.6)

project (liveMedia)

if (NOT LIB_TYPE)
	set (LIB_TYPE SHARED)
endif (NOT LIB_TYPE)

set (liveMedia_HEADERS
	AC3AudioFileServerMediaSubsession.hh
	AC3AudioRTPSink.hh
	AC3AudioRTPSource.hh
	AC3AudioStreamFramer.hh
	ADTSAudioFileServerMediaSubsession.hh
	ADTSAudioFileSource.hh
	AMRAudioFileServerMediaSubsession.hh
	AMRAudioFileSink.hh
	AMRAudioFileSource.hh
	AMRAudioRTPSink.hh
	AMRAudioRTPSource.hh
	AMRAudioSource.hh
	AudioInputDevice.hh
	AudioRTPSink.hh
	AVIFileSink.hh
	Base64.hh
	BasicUDPSink.hh
	BasicUDPSource.hh
	ByteStreamFileSource.hh
	ByteStreamMemoryBufferSource.hh
	ByteStreamMultiFileSource.hh
	Configuration.hpp
	DarwinInjector.hh
	DeviceSource.hh
	DigestAuthentication.hh
	DVVideoFileServerMediaSubsession.hh
	DVVideoRTPSink.hh
	DVVideoRTPSource.hh
	DVVideoStreamFramer.hh
	FileServerMediaSubsession.hh
	FileSink.hh
	FramedFileSource.hh
	FramedFilter.hh
	FramedSource.hh
	GSMAudioRTPSink.hh
	H261VideoRTPSource.hh
	H263plusVideoFileServerMediaSubsession.hh
	H263plusVideoRTPSink.hh
	H263plusVideoRTPSource.hh
	H263plusVideoStreamFramer.hh
	H264VideoFileServerMediaSubsession.hh
	H264VideoFileSink.hh
	H264VideoRTPSink.hh
	H264VideoRTPSource.hh
	H264VideoStreamDiscreteFramer.hh
	H264VideoStreamFramer.hh
    H264VideoStreamServerMediaSubsession.hh
	InputFile.hh
	JPEGVideoRTPSink.hh
	JPEGVideoRTPSource.hh
	JPEGVideoSource.hh
	liveMedia.hh
	liveMedia_version.hh
	Locale.hh
	MatroskaFile.hh
	MatroskaFileServerDemux.hh
	Media.hh
	MediaSession.hh
	MediaSink.hh
	MediaSource.hh
	MP3ADU.hh
	MP3ADUinterleaving.hh
	MP3ADURTPSink.hh
	MP3ADURTPSource.hh
	MP3ADUTranscoder.hh
	MP3AudioFileServerMediaSubsession.hh
	MP3FileSource.hh
	MP3HTTPSource.hh
	MP3Transcoder.hh
	MPEG1or2AudioRTPSink.hh
	MPEG1or2AudioRTPSource.hh
	MPEG1or2AudioStreamFramer.hh
	MPEG1or2Demux.hh
	MPEG1or2DemuxedElementaryStream.hh
	MPEG1or2DemuxedServerMediaSubsession.hh
	MPEG1or2FileServerDemux.hh
	MPEG1or2VideoFileServerMediaSubsession.hh
	MPEG1or2VideoRTPSink.hh
	MPEG1or2VideoRTPSource.hh
	MPEG1or2VideoStreamDiscreteFramer.hh
	MPEG1or2VideoStreamFramer.hh
	MPEG2IndexFromTransportStream.hh
	MPEG2TransportFileServerMediaSubsession.hh
	MPEG2TransportStreamFramer.hh
	MPEG2TransportStreamFromESSource.hh
	MPEG2TransportStreamFromPESSource.hh
	MPEG2TransportStreamIndexFile.hh
	MPEG2TransportStreamMultiplexor.hh
	MPEG2TransportStreamTrickModeFilter.hh
	MPEG2TransportUDPServerMediaSubsession.hh
	MPEG4ESVideoRTPSink.hh
	MPEG4ESVideoRTPSource.hh
	MPEG4GenericRTPSink.hh
	MPEG4GenericRTPSource.hh
	MPEG4LATMAudioRTPSink.hh
	MPEG4LATMAudioRTPSource.hh
	MPEG4VideoFileServerMediaSubsession.hh
	MPEG4VideoStreamDiscreteFramer.hh
	MPEG4VideoStreamFramer.hh
    MPEG4VideoStreamServerMediaSubsession.hh
	MPEGVideoStreamFramer.hh
	MultiFramedRTPSink.hh
	MultiFramedRTPSource.hh
	OnDemandServerMediaSubsession.hh
	OutputFile.hh
	PassiveServerMediaSubsession.hh
	QCELPAudioRTPSource.hh
	QuickTimeFileSink.hh
	QuickTimeGenericRTPSource.hh
	RTCP.hh
	RTPInterface.hh
	RTPSink.hh
	RTPSource.hh
	RTSPClient.hh
	RTSPCommon.hh
	RTSPServer.hh
	RTSPServerSupportingHTTPStreaming.hh
	ServerMediaSession.hh
	SimpleRTPSink.hh
	SimpleRTPSource.hh
	SIPClient.hh
	StreamReplicator.hh
    StreamServerMediaSubsession.hh
	T140TextRTPSink.hh
	TCPStreamSink.hh
	TextRTPSink.hh
	uLawAudioFilter.hh
	VideoRTPSink.hh
	VorbisAudioRTPSink.hh
	VorbisAudioRTPSource.hh
	VP8VideoRTPSink.hh
	VP8VideoRTPSource.hh
	WAVAudioFileServerMediaSubsession.hh
	WAVAudioFileSource.hh
)

set (liveMedia_SRC
	${liveMedia_HEADERS}
	src/AACAudioMatroskaFileServerMediaSubsession.cpp 
	src/AACAudioMatroskaFileServerMediaSubsession.hh 
	src/AC3AudioFileServerMediaSubsession.cpp 
	src/AC3AudioMatroskaFileServerMediaSubsession.cpp 
	src/AC3AudioMatroskaFileServerMediaSubsession.hh 
	src/AC3AudioRTPSink.cpp 
	src/AC3AudioRTPSource.cpp 
	src/AC3AudioStreamFramer.cpp 
	src/ADTSAudioFileServerMediaSubsession.cpp 
	src/ADTSAudioFileSource.cpp 
	src/AMRAudioFileServerMediaSubsession.cpp 
	src/AMRAudioFileSink.cpp 
	src/AMRAudioFileSource.cpp 
	src/AMRAudioRTPSink.cpp 
	src/AMRAudioRTPSource.cpp 
	src/AMRAudioSource.cpp 
	src/AudioInputDevice.cpp 
	src/AudioRTPSink.cpp 
	src/AVIFileSink.cpp 
	src/Base64.cpp 
	src/BasicUDPSink.cpp 
	src/BasicUDPSource.cpp 
	src/BitVector.cpp 
	src/BitVector.hh 
	src/ByteStreamFileSource.cpp 
	src/ByteStreamMemoryBufferSource.cpp 
	src/ByteStreamMultiFileSource.cpp 
	src/DarwinInjector.cpp 
	src/DeviceSource.cpp 
	src/DigestAuthentication.cpp 
	src/DVVideoFileServerMediaSubsession.cpp 
	src/DVVideoRTPSink.cpp 
	src/DVVideoRTPSource.cpp 
	src/DVVideoStreamFramer.cpp 
	src/EBMLNumber.cpp 
	src/EBMLNumber.hh 
	src/FileServerMediaSubsession.cpp 
	src/FileSink.cpp 
	src/FramedFileSource.cpp 
	src/FramedFilter.cpp 
	src/FramedSource.cpp 
	src/GSMAudioRTPSink.cpp 
	src/H261VideoRTPSource.cpp 
	src/H263plusVideoFileServerMediaSubsession.cpp 
	src/H263plusVideoRTPSink.cpp 
	src/H263plusVideoRTPSource.cpp 
	src/H263plusVideoStreamFramer.cpp 
	src/H263plusVideoStreamParser.cpp 
	src/H263plusVideoStreamParser.hh 
	src/H264VideoFileServerMediaSubsession.cpp 
	src/H264VideoFileSink.cpp 
	src/H264VideoMatroskaFileServerMediaSubsession.cpp 
	src/H264VideoMatroskaFileServerMediaSubsession.hh 
	src/H264VideoRTPSink.cpp 
	src/H264VideoRTPSource.cpp 
	src/H264VideoStreamDiscreteFramer.cpp 
	src/H264VideoStreamFramer.cpp 
    src/H264VideoStreamServerMediaSubsession.cpp
	src/InputFile.cpp 
	src/JPEGVideoRTPSink.cpp 
	src/JPEGVideoRTPSource.cpp 
	src/JPEGVideoSource.cpp 
	src/Locale.cpp 
	src/MatroskaDemuxedTrack.cpp 
	src/MatroskaDemuxedTrack.hh 
	src/MatroskaFile.cpp 
	src/MatroskaFileParser.cpp 
	src/MatroskaFileParser.hh 
	src/MatroskaFileServerDemux.cpp 
	src/Media.cpp 
	src/MediaSession.cpp 
	src/MediaSink.cpp 
	src/MediaSource.cpp 
	src/MP3ADU.cpp 
	src/MP3ADUdescriptor.cpp 
	src/MP3ADUdescriptor.hh 
	src/MP3ADUinterleaving.cpp 
	src/MP3ADURTPSink.cpp 
	src/MP3ADURTPSource.cpp 
	src/MP3ADUTranscoder.cpp 
	src/MP3AudioFileServerMediaSubsession.cpp 
	src/MP3AudioMatroskaFileServerMediaSubsession.cpp 
	src/MP3AudioMatroskaFileServerMediaSubsession.hh 
	src/MP3FileSource.cpp 
	src/MP3HTTPSource.cpp 
	src/MP3Internals.cpp 
	src/MP3Internals.hh 
	src/MP3InternalsHuffman.cpp 
	src/MP3InternalsHuffman.hh 
	src/MP3InternalsHuffmanTable.cpp 
	src/MP3StreamState.cpp 
	src/MP3StreamState.hh 
	src/MP3Transcoder.cpp 
	src/MPEG1or2AudioRTPSink.cpp 
	src/MPEG1or2AudioRTPSource.cpp 
	src/MPEG1or2AudioStreamFramer.cpp 
	src/MPEG1or2Demux.cpp 
	src/MPEG1or2DemuxedElementaryStream.cpp 
	src/MPEG1or2DemuxedServerMediaSubsession.cpp 
	src/MPEG1or2FileServerDemux.cpp 
	src/MPEG1or2VideoFileServerMediaSubsession.cpp 
	src/MPEG1or2VideoRTPSink.cpp 
	src/MPEG1or2VideoRTPSource.cpp 
	src/MPEG1or2VideoStreamDiscreteFramer.cpp 
	src/MPEG1or2VideoStreamFramer.cpp 
	src/MPEG2IndexFromTransportStream.cpp 
	src/MPEG2TransportFileServerMediaSubsession.cpp 
	src/MPEG2TransportStreamFramer.cpp 
	src/MPEG2TransportStreamFromESSource.cpp 
	src/MPEG2TransportStreamFromPESSource.cpp 
	src/MPEG2TransportStreamIndexFile.cpp 
	src/MPEG2TransportStreamMultiplexor.cpp 
	src/MPEG2TransportStreamTrickModeFilter.cpp 
	src/MPEG2TransportUDPServerMediaSubsession.cpp 
	src/MPEG4ESVideoRTPSink.cpp 
	src/MPEG4ESVideoRTPSource.cpp 
	src/MPEG4GenericRTPSink.cpp 
	src/MPEG4GenericRTPSource.cpp 
	src/MPEG4LATMAudioRTPSink.cpp 
	src/MPEG4LATMAudioRTPSource.cpp 
	src/MPEG4VideoFileServerMediaSubsession.cpp 
	src/MPEG4VideoStreamDiscreteFramer.cpp 
	src/MPEG4VideoStreamFramer.cpp
    src/MPEG4VideoStreamServerMediaSubsession.cpp 
	src/MPEGVideoStreamFramer.cpp 
	src/MPEGVideoStreamParser.cpp 
	src/MPEGVideoStreamParser.hh 
	src/MultiFramedRTPSink.cpp 
	src/MultiFramedRTPSource.cpp 
	src/OnDemandServerMediaSubsession.cpp 
	src/our_md5.c 
	src/our_md5.h 
	src/our_md5hl.c 
	src/OutputFile.cpp 
	src/PassiveServerMediaSubsession.cpp 
	src/QCELPAudioRTPSource.cpp 
	src/QuickTimeFileSink.cpp 
	src/QuickTimeGenericRTPSource.cpp 
	src/RTCP.cpp 
	src/rtcp_from_spec.c 
	src/rtcp_from_spec.h 
	src/RTPInterface.cpp 
	src/RTPSink.cpp 
	src/RTPSource.cpp 
	src/RTSPClient.cpp 
	src/RTSPCommon.cpp 
	src/RTSPServer.cpp 
	src/RTSPServerSupportingHTTPStreaming.cpp 
	src/ServerMediaSession.cpp 
	src/SimpleRTPSink.cpp 
	src/SimpleRTPSource.cpp 
	src/SIPClient.cpp 
	src/StreamParser.cpp 
	src/StreamParser.hh 
	src/StreamReplicator.cpp 
    src/StreamServerMediaSubsession.cpp
	src/T140TextMatroskaFileServerMediaSubsession.cpp 
	src/T140TextMatroskaFileServerMediaSubsession.hh 
	src/T140TextRTPSink.cpp 
	src/TCPStreamSink.cpp 
	src/TextRTPSink.cpp 
	src/uLawAudioFilter.cpp 
	src/VideoRTPSink.cpp 
	src/VorbisAudioMatroskaFileServerMediaSubsession.cpp 
	src/VorbisAudioMatroskaFileServerMediaSubsession.hh 
	src/VorbisAudioRTPSink.cpp 
	src/VorbisAudioRTPSource.cpp 
	src/VP8VideoMatroskaFileServerMediaSubsession.cpp 
	src/VP8VideoMatroskaFileServerMediaSubsession.hh 
	src/VP8VideoRTPSink.cpp 
	src/VP8VideoRTPSource.cpp 
	src/WAVAudioFileServerMediaSubsession.cpp 
	src/WAVAudioFileSource.cpp 
)

set (liveMedia_DEFINITIONS ${LIVE456_DEFINITIONS} -DLIVEMEDIA_EXPORTS)
add_definitions (${liveMedia_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_library (liveMedia ${LIB_TYPE} ${liveMedia_SRC})

add_dependencies (liveMedia UsageEnvironment)

target_link_libraries (liveMedia UsageEnvironment)

set_target_properties (liveMedia PROPERTIES DEBUG_POSTFIX "_d")

install (FILES
	${liveMedia_HEADERS}
	DESTINATION
	"${CMAKE_INSTALL_PREFIX}/include/liveMedia"
)

install ( TARGETS
	liveMedia
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)
