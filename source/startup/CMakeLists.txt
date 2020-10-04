add_library(startup STATIC)

target_sources(startup
  PRIVATE
    src/startup.cpp
)

target_include_directories(startup
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(startup
  PRIVATE
    cubemx
    hal
)
