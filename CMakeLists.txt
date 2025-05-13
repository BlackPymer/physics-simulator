cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    src/main.cpp
    src/physics/ball.cpp
    src/physics/physics_engine.cpp
    src/physics/common_functions.cpp
)
set(HEADERS
    include/physics/ball.hpp
    include/physics/constants.hpp
    include/physics/physics_engine.hpp
)

add_executable(MyExecutable ${SOURCES})

target_include_directories(MyExecutable PRIVATE include)

# Optionally, add the headers for IDE organization
source_group("Header Files" FILES ${HEADERS})

# Optionally, add compile options for warnings
target_compile_options(MyExecutable PRIVATE -Wall -Wextra -Wpedantic)
