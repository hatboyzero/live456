cmake_minimum_required (VERSION 2.6)

project (testMPEG1or2AudioVideoToDarwin)

set (testMPEG1or2AudioVideoToDarwin_SRC
	src/testMPEG1or2AudioVideoToDarwin.cpp
)

set (testMPEG1or2AudioVideoToDarwin_DEFINITIONS "")
add_definitions (${testMPEG1or2AudioVideoToDarwin_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_executable (testMPEG1or2AudioVideoToDarwin ${testMPEG1or2AudioVideoToDarwin_SRC})

add_dependencies (testMPEG1or2AudioVideoToDarwin UsageEnvironment liveMedia)

target_link_libraries (testMPEG1or2AudioVideoToDarwin UsageEnvironment liveMedia)

set_target_properties (testMPEG1or2AudioVideoToDarwin PROPERTIES DEBUG_POSTFIX "_d")
