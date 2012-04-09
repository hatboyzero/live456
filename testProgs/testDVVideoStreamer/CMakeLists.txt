cmake_minimum_required (VERSION 2.6)

project (testDVVideoStreamer)

set (testDVVideoStreamer_SRC
	src/testDVVideoStreamer.cpp
)

set (testDVVideoStreamer_DEFINITIONS "")
add_definitions (${testDVVideoStreamer_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_executable (testDVVideoStreamer ${testDVVideoStreamer_SRC})

add_dependencies (testDVVideoStreamer UsageEnvironment groupsock liveMedia BasicUsageEnvironment)

target_link_libraries (testDVVideoStreamer UsageEnvironment groupsock liveMedia BasicUsageEnvironment)

set_target_properties (testDVVideoStreamer PROPERTIES DEBUG_POSTFIX "_d")
