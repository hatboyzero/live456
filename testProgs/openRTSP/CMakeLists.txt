cmake_minimum_required (VERSION 2.6)

project (openRTSP)

set (openRTSP_SRC
	src/openRTSP.cpp
)

set (openRTSP_DEFINITIONS "")
add_definitions (${openRTSP_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_executable (openRTSP ${openRTSP_SRC})

add_dependencies (openRTSP UsageEnvironment groupsock liveMedia BasicUsageEnvironment)

target_link_libraries (openRTSP UsageEnvironment groupsock liveMedia BasicUsageEnvironment)

set_target_properties (openRTSP PROPERTIES DEBUG_POSTFIX "_d")
