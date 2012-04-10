cmake_minimum_required (VERSION 2.6)

project (testMPEG1or2AudioVideoStreamer)

set (testMPEG1or2AudioVideoStreamer_SRC
	src/testMPEG1or2AudioVideoStreamer.cpp
)

set (testMPEG1or2AudioVideoStreamer_DEFINITIONS "")
add_definitions (${testMPEG1or2AudioVideoStreamer_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_executable (testMPEG1or2AudioVideoStreamer ${testMPEG1or2AudioVideoStreamer_SRC})

add_dependencies (testMPEG1or2AudioVideoStreamer UsageEnvironment liveMedia)

target_link_libraries (testMPEG1or2AudioVideoStreamer UsageEnvironment liveMedia)

set_target_properties (testMPEG1or2AudioVideoStreamer PROPERTIES DEBUG_POSTFIX "_d")
