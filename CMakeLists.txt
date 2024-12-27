cmake_minimum_required(VERSION 3.30)
project(trabalho)

set(CMAKE_CXX_STANDARD 20)

add_library(trabalho STATIC main.cpp
        src/structures/Node.cpp
        src/structures/Node.h
        src/structures/Edge.cpp
        src/structures/Edge.h
        src/structures/storage/Storage.h
        src/structures/storage/List/ListStorage.cpp
        src/structures/storage/List/ListStorage.h
        src/structures/storage/List/ListNode.h
        src/structures/storage/Matrices/Matrix.cpp
        src/structures/storage/Matrices/Matrix.h
)
