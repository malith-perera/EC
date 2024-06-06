cmake_minimum_required(VERSION 3.22)
project(EC)

set(CMAKE_BUILD_TYPE Debug)  #Debug #Release

# Bump up warning levels appropriately for clang, gcc & msvc

# Also set debug/optimization flags depending on the build type. IDE users choose this when

# selecting the build mode in their IDE
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  `--libs --cflags` -ggdb3 -O0 --std=c11 -Wall -lm")
	set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
	set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
	if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else ()
		set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
	endif ()
endif ()


#get_filename_component (PARENT_DIR ${PROJECT_SOURCE_DIR} DIRECTORY)

# Set an output directory for binary ectest
set(BIN_DIR "${PROJECT_SOURCE_DIR}/build")

set (PROJECT_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/include" "${PROJECT_SOURCE_DIR}/.ec" "/usr/local/include")

set (PROJECT_LINK_DIRS ${PROJECT_SOURCE_DIR}/lib)
link_directories (${PROJECT_LINK_DIRS})

#Bring the headers, such as Student.h into the project
include_directories(${PROJECT_INCLUDE_DIRS})

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCE_FILES "${PROJECT_SOURCE_DIR}/src/*.c")

#Generate the shared library from the sources
add_library(EC SHARED ${SOURCE_FILES})

unset(BIN_DIR)
set(BIN_DIR "${PROJECT_SOURCE_DIR}/bin")
set (PROJECT_LINK_DIRS ${PROJECT_SOURCE_DIR}/lib)
set (PROJECT_LINK_LIBS libEC.so)
link_directories (${PROJECT_LINK_DIRS})
add_executable(ec ${SOURCE_FILES})

#Set the location for library installation -- i.e., /usr/lib in this case
# not really necessary in this example. Use "sudo make install" to apply
install(TARGETS EC DESTINATION /usr/lib)


#message ("${PROJECT_SOURCE_DIR}")
