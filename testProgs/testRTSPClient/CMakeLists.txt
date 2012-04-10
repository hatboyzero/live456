cmake_minimum_required (VERSION 2.6)

project (testRTSPClient)

set (testRTSPClient_SRC
	src/testRTSPClient.cpp
)

set (testRTSPClient_DEFINITIONS "")
add_definitions (${testRTSPClient_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_executable (testRTSPClient ${testRTSPClient_SRC})

add_dependencies (testRTSPClient UsageEnvironment liveMedia)

target_link_libraries (testRTSPClient UsageEnvironment liveMedia)

set_target_properties (testRTSPClient PROPERTIES DEBUG_POSTFIX "_d")
