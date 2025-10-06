cmake_minimum_required(VERSION 3.20)
project(Arkanoid LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.6 COMPONENTS system window graphics REQUIRED)

add_executable(Arkanoid
    src/main.cpp
    src/paddle.cpp
    src/paddle.hpp
    src/ball.cpp
    src/ball.hpp
)

target_link_libraries(Arkanoid PRIVATE sfml-system sfml-window sfml-graphics)
