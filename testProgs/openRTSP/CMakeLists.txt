cmake_minimum_required (VERSION 2.6)

project (openRTSP)

set (openRTSP_SRC
    ../Common/src/playCommon.hh
	../Common/src/playCommon.cpp
	src/openRTSP.cpp
)

set (openRTSP_DEFINITIONS "")
add_definitions (${openRTSP_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_executable (openRTSP ${openRTSP_SRC})

add_dependencies (openRTSP UsageEnvironment liveMedia)

target_link_libraries (openRTSP UsageEnvironment liveMedia)

set_target_properties (openRTSP PROPERTIES DEBUG_POSTFIX "_d")
