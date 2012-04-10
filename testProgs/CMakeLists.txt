cmake_minimum_required (VERSION 2.6)

option(LIVE456_BUILD_TESTPROGS "Build test programs" TRUE)
if (LIVE456_BUILD_TESTPROGS)

	set (TESTPROGS
		MPEG2TransportStreamIndexer
		openRTSP
		playSIP
		sapWatch
		testAMRAudioStreamer
		testDVVideoStreamer
		#testGSMStreamer
		testH264VideoStreamer
		testH264VideoToTransportStream
		testMP3Receiver
		testMP3Streamer
		testMPEG1or2AudioVideoStreamer
		testMPEG1or2AudioVideoToDarwin
		testMPEG1or2ProgramToTransportStream
		testMPEG1or2Splitter
		testMPEG1or2VideoReceiver
		testMPEG1or2VideoStreamer
		testMPEG2TransportReceiver
		testMPEG2TransportStreamer
		testMPEG2TransportStreamTrickPlay
		testMPEG4VideoStreamer
		testMPEG4VideoToDarwin
		testOnDemandRTSPServer
		testRelay
		testReplicator
		testRTSPClient
		testWAVAudioStreamer
		vobStreamer
	)

	foreach (PROG ${TESTPROGS})
		message ("    -- ${PROG}")
		add_subdirectory (${PROG})
	endforeach (dir)
endif (LIVE456_BUILD_TESTPROGS)
