cmake_minimum_required(VERSION 3.5)
project(inflation_calc C)

set(CMAKE_C_STANDARD 99)

add_executable(infcalc infcalc.c)

# Copy cpi.csv to build directory to avoid errors
add_custom_command(
        TARGET infcalc POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/cpi.csv
                ${CMAKE_CURRENT_BINARY_DIR}/cpi.csv)
