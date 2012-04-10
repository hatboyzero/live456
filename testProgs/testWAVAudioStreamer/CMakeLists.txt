cmake_minimum_required (VERSION 2.6)

project (testWAVAudioStreamer)

set (testWAVAudioStreamer_SRC
	src/testWAVAudioStreamer.cpp
)

set (testWAVAudioStreamer_DEFINITIONS "")
add_definitions (${testWAVAudioStreamer_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_executable (testWAVAudioStreamer ${testWAVAudioStreamer_SRC})

add_dependencies (testWAVAudioStreamer UsageEnvironment liveMedia)

target_link_libraries (testWAVAudioStreamer UsageEnvironment liveMedia)

set_target_properties (testWAVAudioStreamer PROPERTIES DEBUG_POSTFIX "_d")
