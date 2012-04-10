cmake_minimum_required (VERSION 2.6)

project (live456)

set (LIVE456_VERSION_MAJOR "0")
set (LIVE456_VERSION_MINOR "1")
set (LIVE456_VERSION_PATCH "0")
set (LIVE456_VERSION "${LIVE456_VERSION_MAJOR}.${LIVE456_VERSION_MINOR}.${LIVE456_VERSION_PATCH}")

set (LIVE456_HOME ${CMAKE_CURRENT_SOURCE_DIR})

set (LIVE456_PROJECTS
	#groupsock
	liveMedia
	mediaServer
	testProgs
	UsageEnvironment
	#WindowsAudioInputDevice
)

foreach (PROJECT_PATH ${LIVE456_PROJECTS})
	message ("-- ${PROJECT_PATH}")
	add_subdirectory ("${PROJECT_PATH}")
endforeach (PROJECT_PATH)

install (FILES
	"${LIVE456_HOME}/COPYING"
	DESTINATION
	"${CMAKE_INSTALL_PREFIX}/"
)

