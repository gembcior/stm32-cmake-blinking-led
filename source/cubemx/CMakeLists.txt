find_package(CMSIS REQUIRED)
find_package(STM32HAL REQUIRED gpio uart)

add_library(cubemx STATIC)

target_sources(cubemx
  PRIVATE
    ${CMSIS_SOURCES}
    ${STM32HAL_SOURCES}
    src/stm32l4xx_hal_msp.c
    src/main.c
    src/gpio.c
    src/usart.c
)

target_include_directories(cubemx
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/cubemx
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${CMSIS_INCLUDE_DIRS}
    ${STM32HAL_INCLUDE_DIR}
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
