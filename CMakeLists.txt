cmake_minimum_required(VERSION 3.29..3.31)
project(
  rohan
  VERSION 24.1.0
  DESCRIPTION "SIMD accelerated software rendering library"
  LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
set(ROHAN_LIB ${PROJECT_NAME})
set(SANDBOX_BIN ${PROJECT_NAME}_sb)

add_subdirectory(rohan)
add_subdirectory(sandbox)
