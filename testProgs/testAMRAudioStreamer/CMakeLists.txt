cmake_minimum_required (VERSION 2.6)

project (testAMRAudioStreamer)

set (testAMRAudioStreamer_SRC
	src/testAMRAudioStreamer.cpp
)

set (testAMRAudioStreamer_DEFINITIONS "")
add_definitions (${testAMRAudioStreamer_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_executable (testAMRAudioStreamer ${testAMRAudioStreamer_SRC})

add_dependencies (testAMRAudioStreamer UsageEnvironment liveMedia)

target_link_libraries (testAMRAudioStreamer UsageEnvironment liveMedia)

set_target_properties (testAMRAudioStreamer PROPERTIES DEBUG_POSTFIX "_d")
