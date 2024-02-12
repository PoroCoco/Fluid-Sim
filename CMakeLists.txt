cmake_minimum_required(VERSION 3.7)

project(FluidSim)

add_compile_options(-Wall -Wextra)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(main src/main.c src/graphics.c src/simulation.c)
target_link_libraries(main ${SDL2_LIBRARIES})