cmake_minimum_required(VERSION 3.22)
project(linked_lists C)

set(CMAKE_C_STANDARD 17)

add_executable(linked_lists main.c singly_linked_list.c doubly_linked_list.c)
