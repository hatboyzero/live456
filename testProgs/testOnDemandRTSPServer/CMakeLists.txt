cmake_minimum_required (VERSION 2.6)

project (testOnDemandRTSPServer)

set (testOnDemandRTSPServer_SRC
	src/testOnDemandRTSPServer.cpp
)

set (testOnDemandRTSPServer_DEFINITIONS "")
add_definitions (${testOnDemandRTSPServer_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_executable (testOnDemandRTSPServer ${testOnDemandRTSPServer_SRC})

add_dependencies (testOnDemandRTSPServer UsageEnvironment groupsock liveMedia BasicUsageEnvironment)

target_link_libraries (testOnDemandRTSPServer UsageEnvironment groupsock liveMedia BasicUsageEnvironment)

set_target_properties (testOnDemandRTSPServer PROPERTIES DEBUG_POSTFIX "_d")
