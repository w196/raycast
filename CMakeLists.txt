cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
project(raycast)

set(SOURCES src/main.c src/utils.c src/window.c src/render.c src/player.c)

add_subdirectory(external/SDL)
add_subdirectory(external/SDL_image)

add_executable(raycast ${SOURCES})

target_include_directories(raycast
	PUBLIC external/SDL/include
	PUBLIC external/SDL_image)

target_link_libraries(raycast SDL2 SDL2_image)