cmake_minimum_required (VERSION 2.6)

project (testMPEG1or2Splitter)

set (testMPEG1or2Splitter_SRC
	src/testMPEG1or2Splitter.cpp
)

set (testMPEG1or2Splitter_DEFINITIONS "")
add_definitions (${testMPEG1or2Splitter_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_executable (testMPEG1or2Splitter ${testMPEG1or2Splitter_SRC})

add_dependencies (testMPEG1or2Splitter UsageEnvironment liveMedia)

target_link_libraries (testMPEG1or2Splitter UsageEnvironment liveMedia)

set_target_properties (testMPEG1or2Splitter PROPERTIES DEBUG_POSTFIX "_d")
