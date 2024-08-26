add_subdirectory(./lib/googletest-main)
set(gtest_SOURCE_DIR, ./lib/googletest-main/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_TEST_FILES runAllTests.cpp TestItem.cpp TestList.cpp TestUser.cpp)
add_executable(runTests ${SOURCE_TEST_FILES})
target_link_libraries(runTests gtest gtest_main core)