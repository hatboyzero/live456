cmake_minimum_required (VERSION 2.6)

project (testReplicator)

set (testReplicator_SRC
	src/testReplicator.cpp
)

set (testReplicator_DEFINITIONS "")
add_definitions (${testReplicator_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_executable (testReplicator ${testReplicator_SRC})

add_dependencies (testReplicator UsageEnvironment liveMedia)

target_link_libraries (testReplicator UsageEnvironment liveMedia)

set_target_properties (testReplicator PROPERTIES DEBUG_POSTFIX "_d")
