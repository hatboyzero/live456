cmake_minimum_required (VERSION 2.6)

project (testMPEG4VideoToDarwin)

set (testMPEG4VideoToDarwin_SRC
	src/testMPEG4VideoToDarwin.cpp
)

set (testMPEG4VideoToDarwin_DEFINITIONS "")
add_definitions (${testMPEG4VideoToDarwin_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_executable (testMPEG4VideoToDarwin ${testMPEG4VideoToDarwin_SRC})

add_dependencies (testMPEG4VideoToDarwin UsageEnvironment groupsock liveMedia BasicUsageEnvironment)

target_link_libraries (testMPEG4VideoToDarwin UsageEnvironment groupsock liveMedia BasicUsageEnvironment)

set_target_properties (testMPEG4VideoToDarwin PROPERTIES DEBUG_POSTFIX "_d")
