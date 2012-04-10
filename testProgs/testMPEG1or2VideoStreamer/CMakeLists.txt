cmake_minimum_required (VERSION 2.6)

project (testMPEG1or2VideoStreamer)

set (testMPEG1or2VideoStreamer_SRC
	src/testMPEG1or2VideoStreamer.cpp
)

set (testMPEG1or2VideoStreamer_DEFINITIONS "")
add_definitions (${testMPEG1or2VideoStreamer_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_executable (testMPEG1or2VideoStreamer ${testMPEG1or2VideoStreamer_SRC})

add_dependencies (testMPEG1or2VideoStreamer UsageEnvironment liveMedia)

target_link_libraries (testMPEG1or2VideoStreamer UsageEnvironment liveMedia)

set_target_properties (testMPEG1or2VideoStreamer PROPERTIES DEBUG_POSTFIX "_d")
