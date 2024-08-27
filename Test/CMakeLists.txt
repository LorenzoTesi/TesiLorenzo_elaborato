cmake_minimum_required(VERSION 3.5)

add_subdirectory(./lib/googletest-main)
set(gtest_SOURCE_DIR, ./lib/googletest-main/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES RunAllTests.cpp TestItem.cpp TestList.cpp TestUser.cpp)
add_executable(runTests ${TEST_SOURCE_FILES})
target_link_libraries(runTests gtest gtest_main ${CMAKE_PROJECT_NAME}_lib)