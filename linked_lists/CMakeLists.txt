cmake_minimum_required(VERSION 3.22)
project(linked_lists C)

set(CMAKE_C_STANDARD 17)

#set(SOURCE_FILES singly_linked_list.c doubly_linked_list.c)

add_executable(linked_lists_1 main1.c singly_linked_list.c)
add_executable(linked_lists_2 main2.c doubly_linked_list.c)
