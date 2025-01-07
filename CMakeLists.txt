cmake_minimum_required(VERSION 3.30)
project(trabalho)

set(CMAKE_CXX_STANDARD 20)

add_library(trabalho STATIC main.cpp
        src/structures/graph/Node.cpp
        src/structures/graph/Node.h
        src/structures/graph/Edge.cpp
        src/structures/graph/Edge.h
        src/structures/storage/Storage.h
        src/structures/storage/List/ListStorage.cpp
        src/structures/storage/List/ListStorage.h
        src/structures/storage/List/ListNode.h
        src/structures/storage/Matrices/Matrix.cpp
        src/structures/storage/Matrices/Matrix.h
        src/structures/graph/Grafo.cpp
        src/structures/graph/Grafo.h
)
