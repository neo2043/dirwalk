cmake_minimum_required(VERSION 3.9.2)

project(dirwalk LANGUAGES C)

set(sources dirwalk.c)

option(DIRWALK_SHARED "Build shared library" OFF)
option(DIRWALK_STATIC "Build static library" OFF)

if(DIRWALK_SHARED)
	add_library(dirwalk_shared SHARED ${sources})
	target_include_directories(dirwalk_shared PUBLIC .)
	set_target_properties(dirwalk_shared PROPERTIES OUTPUT_NAME dirwalk)
endif()
if(DIRWALK_STATIC)
	add_library(dirwalk STATIC ${sources})
	target_include_directories(dirwalk PUBLIC .)
endif()
if(NOT (DIRWALK_STATIC OR DIRWALK_SHARED))
	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/cwalk)

	file(GLOB DATASTRUCT_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/vendor/datastructs/*.c)
	file(GLOB DATASTRUCT_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/vendor/datastructs/*.h)
	add_library(datastructs ${DATASTRUCT_SOURCES})
	target_sources(datastructs INTERFACE ${DATASTRUCT_HEADERS})
	target_include_directories(datastructs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vendor/datastructs)

	add_library(dirwalk OBJECT ${sources})
	target_sources(dirwalk INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/dirwalk.h)
	target_link_libraries(dirwalk cwalk datastructs)
endif()