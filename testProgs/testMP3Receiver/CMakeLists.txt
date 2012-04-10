cmake_minimum_required (VERSION 2.6)

project (testMP3Receiver)

set (testMP3Receiver_SRC
	src/testMP3Receiver.cpp
)

set (testMP3Receiver_DEFINITIONS "")
add_definitions (${testMP3Receiver_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_executable (testMP3Receiver ${testMP3Receiver_SRC})

add_dependencies (testMP3Receiver UsageEnvironment liveMedia)

target_link_libraries (testMP3Receiver UsageEnvironment liveMedia)

set_target_properties (testMP3Receiver PROPERTIES DEBUG_POSTFIX "_d")
