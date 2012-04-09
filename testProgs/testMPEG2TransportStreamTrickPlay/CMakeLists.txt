cmake_minimum_required (VERSION 2.6)

project (testMPEG2TransportStreamTrickPlay)

set (testMPEG2TransportStreamTrickPlay_SRC
	src/testMPEG2TransportStreamTrickPlay.cpp
)

set (testMPEG2TransportStreamTrickPlay_DEFINITIONS "")
add_definitions (${testMPEG2TransportStreamTrickPlay_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_executable (testMPEG2TransportStreamTrickPlay ${testMPEG2TransportStreamTrickPlay_SRC})

add_dependencies (testMPEG2TransportStreamTrickPlay UsageEnvironment groupsock liveMedia BasicUsageEnvironment)

target_link_libraries (testMPEG2TransportStreamTrickPlay UsageEnvironment groupsock liveMedia BasicUsageEnvironment)

set_target_properties (testMPEG2TransportStreamTrickPlay PROPERTIES DEBUG_POSTFIX "_d")
