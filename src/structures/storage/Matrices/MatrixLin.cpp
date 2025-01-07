//
// Created by dsalvaro on 07/01/2025.
//
#include <iostream>
#include "MatrixLin.h"
#include "../../graph/basics/Edge.cpp"

using namespace std;

template<typename T>
MatrixLin<T>::MatrixLin(const int nl, const int nc) {
    line = nl;
    column = nc;

    matrix = new T[line * column];
}

template<typename T>
MatrixLin<T>::~MatrixLin() {
    delete[] matrix;
}

template<typename T>
bool MatrixLin<T>::verify(const int i, const int j) const {
    return i >= 0 && i < line && j >= 0 && j < column;
}

template<typename T>
int MatrixLin<T>::toLinearIndex(const int i, const int j) const {
    return i * column + j;
}

template<typename T>
T MatrixLin<T>::get(int i, int j) {
    if (!verify(i, j)) {
        cout << "Index out of bounds" << endl;
        return -1;
    }
    return matrix[toLinearIndex(i, j)];
}

template<class T>
void MatrixLin<T>::add(T *info) {
    auto edge = static_cast<Edge *>(info);
    const int i = edge->getOrigem()->getId();
    const int j = edge->getDestino()->getId();
    this->set(i, j, *info);
}

template<typename T>
void MatrixLin<T>::set(int i, int j, T info) {
    if (!verify(i, j)) {
        cout << "Index out of bounds" << endl;
        return;
    }
    matrix[toLinearIndex(i, j)] = info;
}
