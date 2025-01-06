//
// Created by Nashi on 27/12/2024.
//
#include <iostream>
#include "Matrix.h"

using namespace std;

template <typename T>
Matrix<T>::Matrix(int nl, int nc) {
    line = nl;
    column = nc;

    matrix = new T*[line];
    for(int i = 0; i < line; i++) {
        matrix[i] = new int[column];
    }
}

template <typename T>
Matrix<T>::~Matrix() {
    for(int i = 0; i < line; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

template <typename T>
bool Matrix<T>::verify(int i, int j) {
    return i >= 0 && i < line && j >= 0 && j < column;
}

template <typename T>
T Matrix<T>::get(int i, int j) {
    if(!verify(i, j)) {
        cout << "Index out of bounds" << endl;
        return -1;
    }
    return matrix[i][j];
}

template <typename T>
void Matrix<T>::set(int i, int j, T info) {
    if(!verify(i, j)) {
        cout << "Index out of bounds" << endl;
        return;
    }
    matrix[i][j] = info;
}