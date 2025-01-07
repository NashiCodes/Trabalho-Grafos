cmake_minimum_required(VERSION 3.30)
project(trabalho)

set(CMAKE_CXX_STANDARD 20)

add_library(trabalho STATIC main.cpp
        include/structures/graph/basics/Node.h
        include/structures/graph/basics/Edge.h
        include/structures/storage/Storage.h
        src/structures/storage/List/List.cpp
        include/structures/storage/list/List.h
        include/structures/storage/list/ListNode.h
        include/structures/graph/Grafo.h
        src/structures/graph/Grafo_lista.cpp
        include/structures/graph/Grafo_lista.h
        src/structures/graph/Grafo_matriz.cpp
        include/structures/graph/Grafo_matriz.h
        src/structures/graph/Grafo.cpp
        src/structures/storage/Matrices/Matrix.cpp
        include/structures/storage/matrices/Matrix.h
)
