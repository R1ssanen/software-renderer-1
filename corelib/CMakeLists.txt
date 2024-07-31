cmake_minimum_required(VERSION 3.30)
project(
  sr1
  VERSION 24.1.0
  DESCRIPTION "Testing SIMD accelerated software rendering"
  LANGUAGES C)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

add_library(
  ${PROJECT_NAME} SHARED "src/systems/logging.c" "src/systems/input.c"
                         "src/window.c" "src/application.c")

option(TERM_COLORS "Use ANSI escape codes to color log messages" ON)
if(NOT TERM_COLORS)
  target_compile_definitions(${PROJECT_NAME} PRIVATE LOG_NO_COLOR)
endif()

set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES C_STANDARD 11
             C_STANDARD_REQUIRED TRUE
             C_VISIBILITY_PRESET "hidden"
             C_VISIBILITY_INLINES_HIDDEN TRUE
             LINKER_LANGUAGE C
             VERSION ${PROJECT_VERSION}
             SOVERSION 1)

set(BASE_COMPILE_FLAGS
    -Wall
    -Wextra
    -Wpedantic
    -flto=auto
    -pthread
    -march=native
    -mavx2)

if(NOT CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE STREQUAL "Debug")
  target_compile_options(${PROJECT_NAME} PRIVATE -g ${BASE_COMPILE_FLAGS})
else()
  target_compile_options(${PROJECT_NAME} PRIVATE -O3 ${BASE_COMPILE_FLAGS})
endif()

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC "src/"
  PRIVATE "ext/")

find_package(SDL2 REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC m SDL2::SDL2 SDL2::SDL2main)
