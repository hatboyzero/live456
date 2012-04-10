cmake_minimum_required (VERSION 2.6)

project (UsageEnvironment)

if (NOT LIB_TYPE)
	set (LIB_TYPE SHARED)
endif (NOT LIB_TYPE)

set (UsageEnvironment_HEADERS
    BasicHashTable.hh
    BasicUsageEnvironment.hh
    BasicUsageEnvironment_version.hh
    BasicUsageEnvironment0.hh
	Boolean.hh
	Configuration.hpp
    DelayQueue.hh
	GroupEId.hh
	Groupsock.hh
	groupsock_version.hh
	GroupsockHelper.hh
    HandlerSet.hh
	HashTable.hh
	IOHandlers.hh
	NetAddress.hh
	NetCommon.h
	NetInterface.hh
	strDup.hh
	TunnelEncaps.hh
	UsageEnvironment.hh
	UsageEnvironment_version.hh
)

set (UsageEnvironment_SRC
	${UsageEnvironment_HEADERS}
    src/BasicHashTable.cpp
    src/BasicTaskScheduler.cpp
    src/BasicTaskScheduler0.cpp
    src/BasicUsageEnvironment.cpp
    src/BasicUsageEnvironment0.cpp
    src/DelayQueue.cpp
	src/GroupEId.cpp
	src/Groupsock.cpp
	src/GroupsockHelper.cpp
	src/HashTable.cpp
	src/inet.cpp
	src/IOHandlers.cpp
	src/NetAddress.cpp
	src/NetInterface.cpp
	src/strDup.cpp
	src/UsageEnvironment.cpp
)

set (UsageEnvironment_DEFINITIONS -DUSAGEENVIRONMENT_EXPORTS)
add_definitions (${UsageEnvironment_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_library (UsageEnvironment ${LIB_TYPE} ${UsageEnvironment_SRC})

set (UsageEnvironment_LIBRARIES "")
if (WIN32)
	set (UsageEnvironment_LIBRARIES ${UsageEnvironment_LIBRARIES} ws2_32)
endif (WIN32)
target_link_libraries (UsageEnvironment ${UsageEnvironment_LIBRARIES})

set_target_properties (UsageEnvironment PROPERTIES DEBUG_POSTFIX "_d")

install (FILES
	${UsageEnvironment_HEADERS}
	DESTINATION
	"${CMAKE_INSTALL_PREFIX}/include/UsageEnvironment"
)