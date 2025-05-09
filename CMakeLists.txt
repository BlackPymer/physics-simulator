cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    src/main.cpp
    src/physics/ball.cpp
)
set(HEADERS
    include/physics/ball.hpp
    include/physics/constants.hpp
)

add_executable(MyExecutable main.cpp)

target_include_directories(MyExecutable PRIVATE include)