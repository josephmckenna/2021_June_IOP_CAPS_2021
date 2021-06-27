cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 17)

# set the project name
project(CAPS2021)

# Set build type and optimisations (assume unix like platform)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra -pthread")
set(CMAKE_CXX_FLAGS_DEBUG "-g ")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")


# Find all examples
file(GLOB MAINS ${PROJECT_SOURCE_DIR}/*.cxx)

# Setup all programs in mains folder
foreach(MAIN ${MAINS})
   get_filename_component(MAIN_NAME ${MAIN} NAME_WLE )
   add_executable(${MAIN_NAME}.exe ${MAIN} ${SRC_FILES})
   #install(${MAIN_NAME})
endforeach(MAIN ${MAINS})
