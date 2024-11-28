cmake_minimum_required(VERSION 3.29..3.31)

add_executable(${SANDBOX_BIN} "src/entry.c")

set_target_properties(
  ${SANDBOX_BIN}
  PROPERTIES C_STANDARD 11
             C_STANDARD_REQUIRED TRUE
             LINKER_LANGUAGE C
             VERSION ${PROJECT_VERSION})

target_compile_options(
  ${SANDBOX_BIN}
  PRIVATE -g
          -Wall
          -Wextra
          -Wpedantic
          -flto=auto
          -march=native
          -mavx2)

find_package(SDL2 REQUIRED)
target_include_directories(${SANDBOX_BIN} PRIVATE "src/")
target_link_libraries(${SANDBOX_BIN} PRIVATE ${ROHAN_LIB} SDL2::SDL2
                                             SDL2::SDL2main)
