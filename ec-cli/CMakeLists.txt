cmake_minimum_required(VERSION 3.10.2)
project (ec-cli)

set (CMAKE_BUILD_TYPE DEBUG)  #Release type

# selecting the build mode in their IDE
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  `--libs --cflags` -ggdb3 -O0 --std=c11 -Wall image -lm")
	set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
	set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
	if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else ()
		set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
	endif ()
endif ()

get_filename_component (PARENT_DIR  ${PROJECT_SOURCE_DIR} DIRECTORY)

# Set an output directory for binary
set (BIN_DIR ${PROJECT_SOURCE_DIR})

set (PROJECT_LINK_LIBS libec.so)
set (PROJECT_LINK_DIRS "${PARENT_DIR}/eclib")
link_directories (${PROJECT_LINK_DIRS})

set (PROJECT_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include)
include_directories (${PROJECT_INCLUDE_DIRS} "${PARENT_DIR}/eclib/include")

#file(GLOB...) allows wildcard additions
file (GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.c")

#Generate executable from the sources
add_executable (${PROJECT_NAME} ${SOURCES})
target_link_libraries (${PROJECT_NAME} LINK_PUBLIC ${PROJECT_LINK_LIBS} m)

install (TARGETS ${PROJECT_NAME} DESTINATION ${BIN_DIR})

#message ("${PROJECT_SOURCE_DIR}")
