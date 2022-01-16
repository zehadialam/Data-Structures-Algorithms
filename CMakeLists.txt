cmake_minimum_required(VERSION 3.21)
project(Data_Structures_Implementations)

set(CMAKE_CXX_STANDARD 14)

include_directories("Sorted Linked List")

add_executable(Data_Structures_Implementations
        "Hash Table/Data.cpp" "Hash Table/Data.h" "Hash Table/HashTable.cpp" "Hash Table/HashTable.h" "Hash Table/main.cpp")
