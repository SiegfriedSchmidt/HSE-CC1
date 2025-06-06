cmake_minimum_required(VERSION 3.30)
project(hash_tables C)

set(CMAKE_C_STANDARD 17)

#add_compile_options(-fPIC -Wall -O3 -march=native)
set(SOURCE_FILES
        random.c
        random.h
        generate.c
        generate.h
        record.c
        record.h
        display.c
        display.h
        hash_table/hash_table.c
        hash_table/hash_table.h
        hash_table/hash_functions.c
        hash_table/hash_functions.h
)

set(CMAKE_SHARED_LIBRARY_SUFFIX .so)
set(CMAKE_SHARED_LIBRARY_PREFIX)

add_executable(hash_tables main.c ${SOURCE_FILES})
add_library(time_measure_lib SHARED time_measure.c time_measure.h ${SOURCE_FILES})
