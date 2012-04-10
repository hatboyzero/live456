cmake_minimum_required (VERSION 2.6)

project (testMPEG1or2VideoReceiver)

set (testMPEG1or2VideoReceiver_SRC
	src/testMPEG1or2VideoReceiver.cpp
)

set (testMPEG1or2VideoReceiver_DEFINITIONS "")
add_definitions (${testMPEG1or2VideoReceiver_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_executable (testMPEG1or2VideoReceiver ${testMPEG1or2VideoReceiver_SRC})

add_dependencies (testMPEG1or2VideoReceiver UsageEnvironment liveMedia)

target_link_libraries (testMPEG1or2VideoReceiver UsageEnvironment liveMedia)

set_target_properties (testMPEG1or2VideoReceiver PROPERTIES DEBUG_POSTFIX "_d")
