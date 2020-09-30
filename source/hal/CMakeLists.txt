add_library(hal STATIC)

target_sources(hal
  PRIVATE
    src/hal_cpu.cpp
    src/hal_gpio.cpp
    src/hal_uart.cpp
)

target_include_directories(hal
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(hal
  PUBLIC
    cubemx
)
