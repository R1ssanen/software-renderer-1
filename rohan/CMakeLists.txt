cmake_minimum_required(VERSION 3.29..3.31)

add_library(${ROHAN_LIB} SHARED "src/log.c" "src/render.c" "src/target.c")

target_compile_options(
  ${ROHAN_LIB}
  PRIVATE -g
          -Wall
          -Wextra
          -Wpedantic
          -flto=auto
          -pthread
          -march=native
          -mavx2)

option(TERM_COLORS "Use ANSI escape codes to color log messages" ON)
if(NOT TERM_COLORS)
  target_compile_definitions(${ROHAN_LIB} PUBLIC ROHAN_LOG_NO_COLOR)
endif()

set_target_properties(
  ${ROHAN_LIB}
  PROPERTIES VERSION ${PROJECT_VERSION}
             SOVERSION 1
             C_STANDARD 11
             C_STANDARD_REQUIRED TRUE
             C_VISIBILITY_PRESET "hidden"
             C_VISIBILITY_INLINES_HIDDEN TRUE
             LINKER_LANGUAGE C
             LIBRARY_OUTPUT_DIRECTORY ".")

target_link_libraries(${ROHAN_LIB} PUBLIC m)
target_include_directories(${ROHAN_LIB} PUBLIC "src" "ext")
