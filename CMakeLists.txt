cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/main.cpp
    src/physics/ball.cpp
    src/physics/physics_engine.cpp
    src/physics/common_functions.cpp
    src/graphics/graphics_engine.cpp
)
set(HEADERS
    include/physics/ball.hpp
    include/physics/constants.hpp
    include/physics/physics_engine.hpp
    include/graphics/graphics_engine.hpp
)

add_executable(PhysicsSimulator ${SOURCES})

target_include_directories(PhysicsSimulator PRIVATE ${CMAKE_SOURCE_DIR}/include)

source_group("Header Files" FILES ${HEADERS})

target_compile_options(PhysicsSimulator PRIVATE -Wall -Wextra -Wpedantic)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(PhysicsSimulator PRIVATE sfml-graphics sfml-window sfml-system)
