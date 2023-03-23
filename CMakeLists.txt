cmake_minimum_required(VERSION 3.7)

project(cutre)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(SOURCES
    src/main.cpp
    src/frameBuffer.cpp
    src/frameBufferSDL.cpp
    src/renderer.cpp
    src/camera.cpp
    src/lightSources.cpp
    src/scene.cpp
    src/shape.cpp
    src/sphere.cpp
    src/vector.cpp
    src/colour.cpp
    src/pointLight.cpp
    src/lambert.cpp
    src/material.cpp)

add_executable(cutre ${SOURCES})
target_link_libraries(cutre ${SDL2_LIBRARIES})
