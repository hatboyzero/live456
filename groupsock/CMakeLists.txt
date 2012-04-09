cmake_minimum_required (VERSION 2.6)

project (groupsock)

if (NOT LIB_TYPE)
	set (LIB_TYPE SHARED)
endif (NOT LIB_TYPE)

set (groupsock_HEADERS
	Configuration.hpp
	GroupEId.hh
	Groupsock.hh
	groupsock_version.hh
	GroupsockHelper.hh
	IOHandlers.hh
	NetAddress.hh
	NetCommon.h
	NetInterface.hh
	TunnelEncaps.hh
)

set (groupsock_SRC
	${groupsock_HEADERS}
	src/GroupEId.cpp
	src/Groupsock.cpp
	src/GroupsockHelper.cpp
	src/inet.cpp
	src/IOHandlers.cpp
	src/NetAddress.cpp
	src/NetInterface.cpp
)

set (groupsock_DEFINITIONS -DGROUPSOCK_EXPORTS)
add_definitions (${groupsock_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_library (groupsock ${LIB_TYPE} ${groupsock_SRC})

add_dependencies (groupsock UsageEnvironment)

set (groupsock_LIBRARIES UsageEnvironment)
if (WIN32)
	set (groupsock_LIBRARIES ${groupsock_LIBRARIES} ws2_32)
endif (WIN32)
target_link_libraries (groupsock ${groupsock_LIBRARIES})

set_target_properties (groupsock PROPERTIES DEBUG_POSTFIX "_d")

install (FILES
	${groupsock_HEADERS}
	DESTINATION
	"${CMAKE_INSTALL_PREFIX}/include/groupsock"
)