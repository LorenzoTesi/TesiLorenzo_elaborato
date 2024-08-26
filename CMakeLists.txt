cmake_minimum_required(VERSION 3.10)
project(Elaborato12)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Test)

set(SOURCE_FILES  Item.cpp Item.h List.cpp List.h User.cpp User.h Data.h Subject.h)
add_executable(Elaborato12 main.cpp)

add_library(core ${SOURCE_FILES})
target_link_libraries(Elaborato12 core)


