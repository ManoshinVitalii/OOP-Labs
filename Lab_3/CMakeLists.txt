cmake_minimum_required(VERSION 3.10)

project(Lab_03)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
add_executable(testing tests.cpp point.cpp figure.cpp hexagon.cpp triangle.cpp octagon.cpp array.cpp)
target_link_libraries(testing ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND testing)
