

set(srcs
    utility.cpp
    Game.cpp
    Level.cpp)


add_library(shooter_core ${srcs})

# Library lookup

# SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(shooter_core ${SFML_LIBRARIES})
endif()




