cmake_minimum_required(VERSION 3.30)
project(sorting C)

set(CMAKE_C_STANDARD 17)

#add_compile_options(-fPIC -Wall -O3 -march=native)
set(SOURCE_FILES generate.c random.c display.c
        sorts/merge_sort.c
        sorts/quick_sort.c
        sorts/heap_sort.c
        record.c)

set(CMAKE_SHARED_LIBRARY_SUFFIX .so)
set(CMAKE_SHARED_LIBRARY_PREFIX)

add_executable(sorting main.c ${SOURCE_FILES})
add_library(time_measure_lib SHARED time_measure.c ${SOURCE_FILES})
