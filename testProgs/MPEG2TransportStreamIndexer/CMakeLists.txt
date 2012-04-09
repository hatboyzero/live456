cmake_minimum_required (VERSION 2.6)

project (MPEG2TransportStreamIndexer)

set (MPEG2TransportStreamIndexer_SRC
	src/MPEG2TransportStreamIndexer.cpp
)

set (MPEG2TransportStreamIndexer_DEFINITIONS "")
add_definitions (${MPEG2TransportStreamIndexer_DEFINITIONS})

include_directories (${LIVE456_HOME})

add_executable (MPEG2TransportStreamIndexer ${MPEG2TransportStreamIndexer_SRC})

add_dependencies (MPEG2TransportStreamIndexer UsageEnvironment groupsock liveMedia BasicUsageEnvironment)

target_link_libraries (MPEG2TransportStreamIndexer UsageEnvironment groupsock liveMedia BasicUsageEnvironment)

set_target_properties (MPEG2TransportStreamIndexer PROPERTIES DEBUG_POSTFIX "_d")
