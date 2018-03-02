cmake_minimum_required(VERSION 3.9)
project(snakegame)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/SnakeGame/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
                    ${SDL2_IMAGE_INCLUDE_DIR}
                    ${SDL2_TTF_INCLUDE_DIR})

include_directories(SnakeGame)

file(GLOB SOURCES "SnakeGame/*.cpp" "SnakeGame/*.h")

set(FONT_RESOURCES
        SnakeGame/res/fonts/arcadeclassic.ttf)

set_property(
        SOURCE "${FONT_RESOURCES}"
        PROPERTY MACOSX_PACKAGE_LOCATION "Resources/fonts")

add_executable(snakegame MACOSX_BUNDLE ${SOURCES} ${FONT_RESOURCES})

set_target_properties(snakegame PROPERTIES
        MACOSX_BUNDLE TRUE
        MACOSX_FRAMEWORK_IDENTIFIER org.cmake.ExecutableTarget)

set_property(TARGET snakegame PROPERTY CXX_STANDARD 14)

target_link_libraries(snakegame ${SDL2_LIBRARY}
                            ${SDL2_IMAGE_LIBRARY}
                            ${SDL2_TTF_LIBRARY})