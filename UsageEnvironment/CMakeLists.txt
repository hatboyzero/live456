cmake_minimum_required (VERSION 2.6)

project (UsageEnvironment)

if (NOT LIB_TYPE)
	set (LIB_TYPE SHARED)
endif (NOT LIB_TYPE)

set (UsageEnvironment_HEADERS
	Boolean.hh
	HashTable.hh
	strDup.hh
	UsageEnvironment.hh
	UsageEnvironment_version.hh
)

set (UsageEnvironment_SRC
	${UsageEnvironment_HEADERS}
	src/HashTable.cpp
	src/strDup.cpp
	src/UsageEnvironment.cpp
)

set (UsageEnvironment_DEFINITIONS -DUSAGEENVIRONMENT_EXPORTS)
add_definitions (${UsageEnvironment_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_library (UsageEnvironment ${LIB_TYPE} ${UsageEnvironment_SRC})

set_target_properties (UsageEnvironment PROPERTIES DEBUG_POSTFIX "_d")

install (FILES
	${UsageEnvironment_HEADERS}
	DESTINATION
	"${CMAKE_INSTALL_PREFIX}/include/UsageEnvironment"
)