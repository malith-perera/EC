cmake_minimum_required(VERSION 3.22)
project(EC)

# set(CMAKE_BUILD_TYPE Debug)  #Debug #Release

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

get_filename_component (PARENT_DIR ${PROJECT_SOURCE_DIR} DIRECTORY)

# Include
set(PROJECT_INCLUDE_DIRS ${PARENT_DIR}/include ${PARENT_DIR}/tests)
include_directories(${PROJECT_INCLUDE_DIRS})

# Link
set(PROJECT_LINK_DIRS ${PARENT_DIR})
set(PROJECT_LINK_LIBS libEC.so)
link_directories (${PROJECT_LINK_DIRS})

#file(GLOB...) for wildcard additions
file(GLOB EC_SOURCE_FILES "${PARENT_DIR}/src/lib/*.c")
file(GLOB SOURCE_FILES "${PARENT_DIR}/src/ec/*.c")
file(GLOB TEST_SOURCE_FILES "${PARENT_DIR}/tests/*.c")

#Generate the shared library from the sources
add_library(${CMAKE_PROJECT_NAME} SHARED ${EC_SOURCE_FILES})

#Generate the executable
add_executable(ec ${SOURCE_FILES})
add_executable(ec_test ${TEST_SOURCE_FILES})

#Link libraries
target_link_libraries(ec LINK_PUBLIC ${PROJECT_LINK_LIBS})
target_link_libraries(ec_test LINK_PUBLIC ${PROJECT_LINK_LIBS})


#target_link_libraries(test LINK_PUBLIC ${PROJECT_LINK_LIBS} m) # m for math library

#Set the location for library installation -- i.e., /usr/lib in this case
#not really necessary in this example. Use "sudo make install" to apply
#install(TARGETS EC DESTINATION /usr/bin/ec)

#message (${PARENT_DIR})
