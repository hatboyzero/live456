cmake_minimum_required (VERSION 2.6)

project (testMPEG2TransportReceiver)

set (testMPEG2TransportReceiver_SRC
	src/testMPEG2TransportReceiver.cpp
)

set (testMPEG2TransportReceiver_DEFINITIONS "")
add_definitions (${testMPEG2TransportReceiver_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_executable (testMPEG2TransportReceiver ${testMPEG2TransportReceiver_SRC})

add_dependencies (testMPEG2TransportReceiver UsageEnvironment groupsock liveMedia BasicUsageEnvironment)

target_link_libraries (testMPEG2TransportReceiver UsageEnvironment groupsock liveMedia BasicUsageEnvironment)

set_target_properties (testMPEG2TransportReceiver PROPERTIES DEBUG_POSTFIX "_d")
