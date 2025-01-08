//
// Created by dsalvaro on 07/01/2025.
//
#include <iostream>
#include "../../../../include/structures/storage/matrices/MatrixLin.h"


using namespace std;


MatrixLin::MatrixLin(const int n): Matrix(n) {
    this->matrixLin = vector<int>(n * (n + 1) / 2);
}


MatrixLin::~MatrixLin() = default;


bool MatrixLin::verify(const int i, const int j) const {
    return i >= 0 && i < line && j >= 0 && j < column;
}


int MatrixLin::toLinearIndex(const int i, const int j) {
    return i * (i + 1) / 2 + j;
}


int MatrixLin::get(const int i, const int j) {
    if (!verify(i, j)) {
        cout << "Index out of bounds" << endl;
        return -1;
    }
    return matrixLin.at(toLinearIndex(i, j));
}


void MatrixLin::add(const int i, const int j, const int info) {
    if (!verify(i, j)) {
        cout << "Index out of bounds" << endl;
        return;
    }
    matrixLin[toLinearIndex(i, j)] = info;
}
