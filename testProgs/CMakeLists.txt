cmake_minimum_required (VERSION 2.6)

option(LIVE456_BUILD_TESTPROGS "Build test programs" TRUE)
if (LIVE456_BUILD_TESTPROGS)
	file (GLOB all_subdirs RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*/CMakeLists.txt")

	foreach (dir ${all_subdirs})
		if (${dir} MATCHES "^([^/]*)//CMakeLists.txt")
		  string (REGEX REPLACE "^([^/]*)//CMakeLists.txt" "\\1" dir_trimmed ${dir})
		  message ("    -- ${dir_trimmed}")
		  add_subdirectory (${dir_trimmed})
		endif()
	endforeach (dir)
endif (LIVE456_BUILD_TESTPROGS)