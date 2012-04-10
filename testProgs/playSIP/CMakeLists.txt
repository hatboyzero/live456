cmake_minimum_required (VERSION 2.6)

project (playSIP)

set (playSIP_SRC
    ../Common/src/playCommon.hh
	../Common/src/playCommon.cpp
	src/playSIP.cpp
)

set (playSIP_DEFINITIONS "")
add_definitions (${playSIP_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_executable (playSIP ${playSIP_SRC})

add_dependencies (playSIP UsageEnvironment liveMedia)

target_link_libraries (playSIP UsageEnvironment liveMedia)

set_target_properties (playSIP PROPERTIES DEBUG_POSTFIX "_d")
