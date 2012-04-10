cmake_minimum_required (VERSION 2.6)

project (testMP3Streamer)

set (testMP3Streamer_SRC
	src/testMP3Streamer.cpp
)

set (testMP3Streamer_DEFINITIONS "")
add_definitions (${testMP3Streamer_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_executable (testMP3Streamer ${testMP3Streamer_SRC})

add_dependencies (testMP3Streamer UsageEnvironment liveMedia)

target_link_libraries (testMP3Streamer UsageEnvironment liveMedia)

set_target_properties (testMP3Streamer PROPERTIES DEBUG_POSTFIX "_d")
