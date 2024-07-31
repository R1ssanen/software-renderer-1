cmake_minimum_required(VERSION 3.30)
project(
  sr1-testing
  VERSION 24.1.0
  DESCRIPTION "Testing SR1 Engine"
  LANGUAGES C)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

add_executable(${PROJECT_NAME} "src/entry.c")

set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES C_STANDARD 11
             C_STANDARD_REQUIRED TRUE
             LINKER_LANGUAGE C
             VERSION ${PROJECT_VERSION})

set(BASE_COMPILE_FLAGS -Wall -Wextra -Wpedantic -flto=auto -march=native -mavx2)

if(NOT CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE STREQUAL "Debug")
  target_compile_options(${PROJECT_NAME} PRIVATE -g ${BASE_COMPILE_FLAGS})
else()
  target_compile_options(${PROJECT_NAME} PRIVATE -O3 ${BASE_COMPILE_FLAGS})
endif()

target_include_directories(${PROJECT_NAME} PRIVATE "src/" "../corelib/src/")

find_library(corelib NAME sr1 PATHS "../corelib/build/")
target_link_libraries(${PROJECT_NAME} PRIVATE ${corelib})
