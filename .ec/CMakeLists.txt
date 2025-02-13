cmake_minimum_required(VERSION 3.28)
project(MonkeyDong)

set(CMAKE_BUILD_TYPE Debug)  #Debug #Release

# gprof
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
#SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
#SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -pg")

#selecting the build mode in their IDE
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} `pkg-config sdl3 --cflags --libs` -ggdb3 -O0 --std=c23 -Wall -lSDL3_image -lSDL3_mixer -lSDL3_ttf -lm")
    set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
    set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else ()
        set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif ()
endif ()

get_filename_component(PARENT_DIR ${PROJECT_SOURCE_DIR} DIRECTORY)
get_filename_component(PARENT2_DIR ${PARENT_DIR} DIRECTORY)

#include directories add .h headder files
set (PROJECT_INCLUDE_DIRS ${PARENT_DIR}/src ${PARENT_DIR}/include ${PARENT2_DIR}/EC/src/lib ${PARENT2_DIR}/EC/include "/usr/local/include")
include_directories(${PROJECT_INCLUDE_DIRS})

# Create an option to switch between a system sdl library and a vendored SDL library
option(MYGAME_VENDORED "Use vendored libraries" OFF)

if(MYGAME_VENDORED)
    # This assumes you have added SDL as a submodule in vendored/SDL
    add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)
else()
    # 1. Look for a SDL3 package,
    # 2. look for the SDL3-shared component, and
    # 3. fail if the shared component cannot be found.
    find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
endif()

get_filename_component(PARENT_DIR ${PROJECT_SOURCE_DIR} DIRECTORY)
get_filename_component(PARENT2_DIR ${PARENT_DIR} DIRECTORY)

set (PROJECT_INCLUDE_DIRS ${PARENT2_DIR}/engine/include ${PROJECT_SOURCE_DIR}/src ${PARENT2_DIR}/EC/include)
include_directories(${PROJECT_INCLUDE_DIRS})

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCE_FILES "${PARENT_DIR}/src/*.c")

#Link libraries
set (PROJECT_LINK_DIRS ${PARENT2_DIR}/engine/lib ${PARENT2_DIR}/EC)
set (PROJECT_LINK_LIBS libEngine.so libEC.so)
link_directories (${PROJECT_LINK_DIRS})

#Generate executables
add_executable(MonkeyDong ${SOURCE_FILES})

target_link_libraries(MonkeyDong PRIVATE ${PROJECT_LINK_LIBS} SDL3::SDL3 SDL3_image SDL3_mixer SDL3_ttf)

#message ("${PROJECT_SOURCE_DIR}")
