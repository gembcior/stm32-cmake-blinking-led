cmake_minimum_required(VERSION 3.15)
project(source C CXX ASM)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

add_subdirectory(irq)
add_subdirectory(crt)
add_subdirectory(cubemx)
add_subdirectory(hal)
add_subdirectory(trace)
add_subdirectory(startup)
add_subdirectory(main)
