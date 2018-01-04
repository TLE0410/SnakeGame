cmake_minimum_required(VERSION 2.8.9)
project(snakegame)

set (CMAKE_CXX_STANDARD 11)

# includes cmake/FindSDL2.cmake
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/SnakeGame/cmake)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

include_directories(SnakeGame)

file(GLOB SOURCES "SnakeGame/*.cpp" "SnakeGame/*.h")

add_executable(snakegame ${SOURCES}) 
target_link_libraries(snakegame ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})
