cmake_minimum_required(VERSION 3.30)
project(sorting C)

set(CMAKE_C_STANDARD 17)

add_executable(sorting main.c generate.c random.c display.c
        sorts/merge_sort.c
        sorts/merge_sort.h
        sorts/quick_sort.c
        sorts/quick_sort.h
        sorts/heap_sort.c
        sorts/heap_sort.h
        record.c)
