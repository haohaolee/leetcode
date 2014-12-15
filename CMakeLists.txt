cmake_minimum_required(VERSION 2.8.8)

project(leetcode CXX)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")

  include(CheckCXXCompilerFlag)
  CHECK_CXX_COMPILER_FLAG(-std=c++11 HAVE_STD11)
  CHECK_CXX_COMPILER_FLAG(-Wno-unused-local-typedefs HAVE_NOUNUSED_LOCAL_TYPEDEF)

  if (HAVE_NOUNUSED_LOCAL_TYPEDEF)
        ADD_DEFINITIONS("-Wno-unused-local-typedefs")
  endif ()

  if (NOT HAVE_STD11)
      MESSAGE(FATAL_ERROR "No advanced standard C++ support (-std=c++11 not defined).")
  endif ()

  add_definitions("-std=c++11 -Wextra -Wall")

  if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
      add_definitions("-ggdb -g3")
      add_definitions("-D_DEBUG")
  endif ()

elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  set(CMAKE_CXX_FLAGS "/W4 /EHsc")
endif ()

# Locate GTest
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories("util")

file(GLOB SOLUTIONS
    "solutions/*.cpp"
    "util/*.cpp"
)

# Link runTests with gtest
add_executable(run_tests run_tests.cpp ${SOLUTIONS})
target_link_libraries(run_tests ${GTEST_BOTH_LIBRARIES})

