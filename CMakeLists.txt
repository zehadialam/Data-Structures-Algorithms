cmake_minimum_required(VERSION 3.21)
project(Data_Structures_Implementations)

set(CMAKE_CXX_STANDARD 14)

include_directories("Sorted Linked List")

add_executable(Data_Structures_Implementations
        "Sorted Linked List/Data.cpp"
        "Sorted Linked List/Data.h"
        "Sorted Linked List/SortedLinkedList.cpp"
        "Sorted Linked List/SortedLinkedList.h"
        "Sorted Linked List/Node.h" "Sorted Linked List/main.cpp")
