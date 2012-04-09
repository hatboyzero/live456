cmake_minimum_required (VERSION 2.6)

project (BasicUsageEnvironment)

if (NOT LIB_TYPE)
	set (LIB_TYPE SHARED)
endif (NOT LIB_TYPE)

set (BasicUsageEnvironment_HEADERS
	BasicHashTable.hh
	BasicUsageEnvironment.hh
	BasicUsageEnvironment_version.hh
	BasicUsageEnvironment0.hh
	Configuration.hpp
	DelayQueue.hh
	HandlerSet.hh
)

set (BasicUsageEnvironment_SRC
	${BasicUsageEnvironment_HEADERS}
	src/BasicHashTable.cpp
	src/BasicTaskScheduler.cpp
	src/BasicTaskScheduler0.cpp
	src/BasicUsageEnvironment.cpp
	src/BasicUsageEnvironment0.cpp
	src/DelayQueue.cpp
)

set (BasicUsageEnvironment_DEFINITIONS -DBASICUSAGEENVIRONMENT_EXPORTS)
add_definitions (${BasicUsageEnvironment_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_library (BasicUsageEnvironment ${LIB_TYPE} ${BasicUsageEnvironment_SRC})

add_dependencies (BasicUsageEnvironment groupsock)

target_link_libraries (BasicUsageEnvironment groupsock)

set_target_properties (BasicUsageEnvironment PROPERTIES DEBUG_POSTFIX "_d")

install (FILES
	${BasicUsageEnvironment_HEADERS}
	DESTINATION
	"${CMAKE_INSTALL_PREFIX}/include/BasicUsageEnvironment"
)