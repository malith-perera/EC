cmake_minimum_required (VERSION 3.10)

# Project name and version
project (ec)

set(CMAKE_BUILD_TYPE DEBUG)  #Release

# Bump up warning levels appropriately for clang, gcc & msvc

# Also set debug/optimization flags depending on the build type. IDE users choose this when

# selecting the build mode in their IDE
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  `--libs --cflags` -ggdb3 -O0 --std=c99 -Wall -lm")
	set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
	set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
	if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else ()
		set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
	endif ()
endif ()

get_filename_component(PARENT_DIR  ${PROJECT_SOURCE_DIR} DIRECTORY)

# Set an output directory for our libraries
set (LIB_DIR ${PROJECT_SOURCE_DIR})
set (PROJECT_INCLUDE_DIRS ${PROJECT_SOURCE_DIR})
set (LIB_NAME "lib${PROJECT_NAME}.so")

include_directories (${PROJECT_INCLUDE_DIRS})

#file(GLOB...) allows wildcard additions
file(GLOB SOURCES "*.c")

#Generate the shared library from the sources
add_library(${PROJECT_NAME} SHARED ${SOURCES})

#Generate the static library from the sources
#add_library(${PROJECT_NAME} STATIC ${SOURCES})
#set (LIB_NAME "lib${PROJECT_NAME}.a")

#Use "sudo make install" to set the location /usr/lib
install(TARGETS ${PROJECT_NAME} DESTINATION ${LIB_DIR})

#message ("${LIB_DIR}")
