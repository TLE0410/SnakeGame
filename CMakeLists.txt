cmake_minimum_required(VERSION 2.8.9)
project(snakegame)

set (CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/SnakeGame/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
                    ${SDL2_IMAGE_INCLUDE_DIR}
                    ${SDL2_TTF_INCLUDE_DIR})

include_directories(SnakeGame)

file(GLOB SOURCES "SnakeGame/*.cpp" "SnakeGame/*.h")

add_executable(snakegame ${SOURCES}) 

target_link_libraries(snakegame ${SDL2_LIBRARY}
                            ${SDL2_IMAGE_LIBRARY}
                            ${SDL2_TTF_LIBRARY})

file(COPY ${PROJECT_SOURCE_DIR}/SnakeGame/res/fonts/arcadeclassic.ttf
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/res/fonts/)
file(COPY ${PROJECT_SOURCE_DIR}/SnakeGame/res/images/Snake.png
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/res/images/)