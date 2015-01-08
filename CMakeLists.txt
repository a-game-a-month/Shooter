
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

project(Shooter CXX)

enable_testing()

# Compiler specific flags
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
   "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(platform_flags "-Wall -Wextra")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  set(platform_flags "/W4 /WX /EHsc")
endif()

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ${platform_flags}")

set(CMAKE_BUILD_TYPE Debug)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/shooter)

add_subdirectory(shooter)
add_subdirectory(unit_tests)

add_executable(game main.cpp)
target_link_libraries(game shooter_core) 




