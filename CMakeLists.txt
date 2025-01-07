cmake_minimum_required(VERSION 3.30)
project(trabalho)

set(CMAKE_CXX_STANDARD 20)

add_library(trabalho STATIC main.cpp
        src/structures/graph/basics/Node.h
        src/structures/graph/basics/Edge.h
        src/structures/storage/Storage.h
        src/structures/storage/List/ListStorage.cpp
        src/structures/storage/List/ListStorage.h
        src/structures/storage/List/ListNode.h
        src/structures/storage/Matrices/Matrix.cpp
        src/structures/storage/Matrices/Matrix.h
        src/structures/graph/Grafo.h
        src/structures/graph/Grafo_lista.cpp
        src/structures/graph/Grafo_lista.h
        src/structures/graph/Grafo_matriz.cpp
        src/structures/graph/Grafo_matriz.h
        src/structures/graph/Grafo.cpp
)
