cmake_minimum_required (VERSION 2.6)

project (WindowsAudioInputDevice)

set (WindowsAudioInputDevice_SRC
	src/showAudioInputPorts.cpp 
	src/WindowsAudioInputDevice_common.cpp 
	src/WindowsAudioInputDevice_common.hh 
	src/WindowsAudioInputDevice_mixer.cpp 
	src/WindowsAudioInputDevice_mixer.hh 
	src/WindowsAudioInputDevice_noMixer.cpp 
	src/WindowsAudioInputDevice_noMixer.hh 
)

set (WindowsAudioInputDevice_DEFINITIONS "")
add_definitions (${WindowsAudioInputDevice_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_executable (WindowsAudioInputDevice ${WindowsAudioInputDevice_SRC})

add_dependencies (WindowsAudioInputDevice UsageEnvironment groupsock liveMedia BasicUsageEnvironment)

target_link_libraries (WindowsAudioInputDevice UsageEnvironment groupsock liveMedia BasicUsageEnvironment)

set_target_properties (WindowsAudioInputDevice PROPERTIES DEBUG_POSTFIX "_d")
