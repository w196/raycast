cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
project(raycast)

find_package(SDL2 REQUIRED)
include_directories(raycast ${SDL2_DIR})

set(SOURCES src/main.c src/utils.c src/window.c src/render.c src/player.c)

add_executable(raycast ${SOURCES})
target_compile_options(raycast PRIVATE -c)
target_link_libraries(raycast ${SDL2_LIBRARIES})
