cmake_minimum_required (VERSION 2.6)

project (vobStreamer)

set (vobStreamer_SRC
	src/vobStreamer.cpp
)

set (vobStreamer_DEFINITIONS "")
add_definitions (${vobStreamer_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_executable (vobStreamer ${vobStreamer_SRC})

add_dependencies (vobStreamer UsageEnvironment groupsock liveMedia BasicUsageEnvironment)

target_link_libraries (vobStreamer UsageEnvironment groupsock liveMedia BasicUsageEnvironment)

set_target_properties (vobStreamer PROPERTIES DEBUG_POSTFIX "_d")
