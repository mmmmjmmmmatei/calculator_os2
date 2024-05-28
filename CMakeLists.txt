cmake_minimum_required(VERSION 3.21)
project(calculator_os2 C)

set(CMAKE_C_STANDARD 99)

add_executable(calculator_os2 main.c)

set_target_properties(calculator_os2 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

target_link_libraries(calculator_os2 m)
