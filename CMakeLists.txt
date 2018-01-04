cmake_minimum_required(VERSION 2.8.9)
project(snakegame)

# includes cmake/FindSDL2.cmake
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/SnakeGame/cmake)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

include_directories(SnakeGame)

file(GLOB SOURCES "SnakeGame/*.cpp")

add_executable(snakegame ${SOURCES}) 
target_link_libraries(snakegame ${SDL2_LIBRARY})