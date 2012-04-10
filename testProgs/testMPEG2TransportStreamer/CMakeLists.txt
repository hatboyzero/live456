cmake_minimum_required (VERSION 2.6)

project (testMPEG2TransportStreamer)

set (testMPEG2TransportStreamer_SRC
	src/testMPEG2TransportStreamer.cpp
)

set (testMPEG2TransportStreamer_DEFINITIONS "")
add_definitions (${testMPEG2TransportStreamer_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_executable (testMPEG2TransportStreamer ${testMPEG2TransportStreamer_SRC})

add_dependencies (testMPEG2TransportStreamer UsageEnvironment liveMedia)

target_link_libraries (testMPEG2TransportStreamer UsageEnvironment liveMedia)

set_target_properties (testMPEG2TransportStreamer PROPERTIES DEBUG_POSTFIX "_d")
