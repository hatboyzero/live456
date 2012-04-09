cmake_minimum_required (VERSION 2.6)

project (testMPEG1or2ProgramToTransportStream)

set (testMPEG1or2ProgramToTransportStream_SRC
	src/testMPEG1or2ProgramToTransportStream.cpp
)

set (testMPEG1or2ProgramToTransportStream_DEFINITIONS "")
add_definitions (${testMPEG1or2ProgramToTransportStream_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_executable (testMPEG1or2ProgramToTransportStream ${testMPEG1or2ProgramToTransportStream_SRC})

add_dependencies (testMPEG1or2ProgramToTransportStream UsageEnvironment groupsock liveMedia BasicUsageEnvironment)

target_link_libraries (testMPEG1or2ProgramToTransportStream UsageEnvironment groupsock liveMedia BasicUsageEnvironment)

set_target_properties (testMPEG1or2ProgramToTransportStream PROPERTIES DEBUG_POSTFIX "_d")
