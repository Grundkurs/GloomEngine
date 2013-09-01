# --- LeeEngine3/CMakeLists.txt ---

project(LeeEngine3 CXX)
cmake_minimum_required(VERSION 2.8.11)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMake)

IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel." FORCE)
ENDIF(NOT CMAKE_BUILD_TYPE)

# --- Variables ---

if(WIN32)
  set(LEE_PLATFORM_WINDOWS TRUE)
  set(LEE_PLATFORM_LINUX FALSE)
else()
  set(LEE_PLATFORM_WINDOWS FALSE)
  set(LEE_PLATFORM_LINUX TRUE)
endif()

if(CMAKE_BUILD_TYPE EQUAL Debug)
  set(LEE_DEBUG TRUE)
else()
  set(LEE_DEBUG FALSE)
endif()

# --- Compiler flags ---

if(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11 -Wall -Wextra -pedantic")
endif()

# --- Include ---

include(Documentation)

add_subdirectory(3rdParty)

add_subdirectory(Engine)

add_subdirectory(Test)