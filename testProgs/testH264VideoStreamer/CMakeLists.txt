cmake_minimum_required (VERSION 2.6)

project (testH264VideoStreamer)

set (testH264VideoStreamer_SRC
	src/testH264VideoStreamer.cpp
)

set (testH264VideoStreamer_DEFINITIONS "")
add_definitions (${testH264VideoStreamer_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_executable (testH264VideoStreamer ${testH264VideoStreamer_SRC})

add_dependencies (testH264VideoStreamer UsageEnvironment groupsock liveMedia BasicUsageEnvironment)

target_link_libraries (testH264VideoStreamer UsageEnvironment groupsock liveMedia BasicUsageEnvironment)

set_target_properties (testH264VideoStreamer PROPERTIES DEBUG_POSTFIX "_d")
