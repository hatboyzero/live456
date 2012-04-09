cmake_minimum_required (VERSION 2.6)

project (sapWatch)

set (sapWatch_SRC
	src/sapWatch.cpp
)

set (sapWatch_DEFINITIONS "")
add_definitions (${sapWatch_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_executable (sapWatch ${sapWatch_SRC})

add_dependencies (sapWatch UsageEnvironment groupsock liveMedia BasicUsageEnvironment)

target_link_libraries (sapWatch UsageEnvironment groupsock liveMedia BasicUsageEnvironment)

set_target_properties (sapWatch PROPERTIES DEBUG_POSTFIX "_d")
