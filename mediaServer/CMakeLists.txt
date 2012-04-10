cmake_minimum_required (VERSION 2.6)

project (mediaServer)

set (mediaServer_SRC
	src/DynamicRTSPServer.cpp
	src/DynamicRTSPServer.hh
	src/live456MediaServer.cpp
	src/version.hh
)

set (mediaServer_DEFINITIONS "")
add_definitions (${mediaServer_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_executable (mediaServer ${mediaServer_SRC})

add_dependencies (mediaServer UsageEnvironment liveMedia)

target_link_libraries (mediaServer UsageEnvironment liveMedia)

set_target_properties (mediaServer PROPERTIES DEBUG_POSTFIX "_d")
