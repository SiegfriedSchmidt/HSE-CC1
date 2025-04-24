cmake_minimum_required(VERSION 3.30)
project(search_structures C)

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
        search/linear_search.c
        search/linear_search.h
        search/binary_search.c
        search/binary_search.h
        search/red_black_search.c
        search/red_black_search.h
        search/all_searches.h)

set(CMAKE_SHARED_LIBRARY_SUFFIX .so)
set(CMAKE_SHARED_LIBRARY_PREFIX)

add_executable(search_structures main.c ${SOURCE_FILES})
add_library(time_measure_lib SHARED time_measure.c time_measure.h ${SOURCE_FILES})
