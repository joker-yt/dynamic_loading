project(dynamiclib-test)

cmake_minimum_required(VERSION 3.2.2)

set(dynamiclib-test-VERSION_MAJOR 1)
set(dynamiclib-test-VERSION_MINOR 0)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/libs)
set(CMAKE_CXX_STANDARD 14)

add_library(a SHARED ${PROJECT_SOURCE_DIR}/src/liba.cpp)
add_library(b SHARED ${PROJECT_SOURCE_DIR}/src/libb.cpp)


add_executable(a.out ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(a.out dl a b)
