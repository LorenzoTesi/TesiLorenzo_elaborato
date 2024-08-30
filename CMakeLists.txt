cmake_minimum_required(VERSION 3.18)
project(Elaborato12)

set(CXX_STANDARD 11)

add_subdirectory(Test)

set(SOURCE_FILES Subject.h Data.h Item.h Item.cpp List.h List.cpp User.h User.cpp
        Observer.h)
add_executable(${CMAKE_PROJECT_NAME} main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} core)


