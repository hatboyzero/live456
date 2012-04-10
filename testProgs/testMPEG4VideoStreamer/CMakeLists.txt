cmake_minimum_required (VERSION 2.6)

project (testMPEG4VideoStreamer)

set (testMPEG4VideoStreamer_SRC
	src/testMPEG4VideoStreamer.cpp
)

set (testMPEG4VideoStreamer_DEFINITIONS "")
add_definitions (${testMPEG4VideoStreamer_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_executable (testMPEG4VideoStreamer ${testMPEG4VideoStreamer_SRC})

add_dependencies (testMPEG4VideoStreamer UsageEnvironment liveMedia)

target_link_libraries (testMPEG4VideoStreamer UsageEnvironment liveMedia)

set_target_properties (testMPEG4VideoStreamer PROPERTIES DEBUG_POSTFIX "_d")
