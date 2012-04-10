cmake_minimum_required (VERSION 2.6)

project (testH264VideoToTransportStream)

set (testH264VideoToTransportStream_SRC
	src/testH264VideoToTransportStream.cpp
)

set (testH264VideoToTransportStream_DEFINITIONS "")
add_definitions (${testH264VideoToTransportStream_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_executable (testH264VideoToTransportStream ${testH264VideoToTransportStream_SRC})

add_dependencies (testH264VideoToTransportStream UsageEnvironment liveMedia)

target_link_libraries (testH264VideoToTransportStream UsageEnvironment liveMedia)

set_target_properties (testH264VideoToTransportStream PROPERTIES DEBUG_POSTFIX "_d")
