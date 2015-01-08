

set(GMOCK_DIR "../libs/gmock-1.7.0/")

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  option(gtest_force_shared_crt
         "Use shared (DLL) run-time lib even when Google Test is build as a static lib."
         ON)
elseif(APPLE)
  add_definitions(-DGTEST_USE_OWN_TR1_TUPLE=1)
endif()
add_subdirectory(${GMOCK_DIR} ${CMAKE_BINARY_DIR}/gmock)

include_directories(SYSTEM ${GMOCK_DIR}/gtest/include
                           ${GMOCK_DIR}/include)

function(add_gmock_test target)
  add_executable(${target} ${ARGN})
  target_link_libraries(${target} gmock_main)

  add_test(${target} ${target})

  add_custom_command(TARGET ${target}
                     POST_BUILD
                     COMMAND ${target}
                     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                     COMMENT "Running ${target}" VERBATIM)
endfunction()

add_gmock_test(UtilitySplitTest utility_split.cpp)

#add_executable(ShooterTests utility_split.cpp)
#
#target_link_libraries(ShooterTests gmock_main)
#
#add_test(ShooterTests ShooterTests)
