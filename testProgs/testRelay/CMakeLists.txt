cmake_minimum_required (VERSION 2.6)

project (testRelay)

set (testRelay_SRC
	src/testRelay.cpp
)

set (testRelay_DEFINITIONS "")
add_definitions (${testRelay_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_executable (testRelay ${testRelay_SRC})

add_dependencies (testRelay UsageEnvironment groupsock liveMedia BasicUsageEnvironment)

target_link_libraries (testRelay UsageEnvironment groupsock liveMedia BasicUsageEnvironment)

set_target_properties (testRelay PROPERTIES DEBUG_POSTFIX "_d")
