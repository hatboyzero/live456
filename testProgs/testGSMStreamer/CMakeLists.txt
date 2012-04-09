cmake_minimum_required (VERSION 2.6)

project (testGSMStreamer)

set (testGSMStreamer_SRC
	src/testGSMStreamer.cpp
)

set (testGSMStreamer_DEFINITIONS "")
add_definitions (${testGSMStreamer_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_executable (testGSMStreamer ${testGSMStreamer_SRC})

add_dependencies (testGSMStreamer UsageEnvironment groupsock liveMedia BasicUsageEnvironment)

target_link_libraries (testGSMStreamer UsageEnvironment groupsock liveMedia BasicUsageEnvironment)

set_target_properties (testGSMStreamer PROPERTIES DEBUG_POSTFIX "_d")
