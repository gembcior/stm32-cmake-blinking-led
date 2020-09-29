cmake_minimum_required(VERSION 3.15)

add_library(trace STATIC)

target_sources(trace
  PRIVATE
    src/string_stream.cpp
    src/trace.cpp
    src/uart_trace.cpp
)

target_include_directories(trace
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(trace
  PRIVATE
    startup
    hal
)
