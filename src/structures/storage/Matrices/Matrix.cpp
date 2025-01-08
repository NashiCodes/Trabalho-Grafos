//
// Created by Nashi on 07/01/2025.
//

#include "../../../../include/structures/storage/matrices/Matrix.h"
#include <iostream>

Matrix::Matrix(const int n): line(n), column(n) {
    this->matrix = vector(this->line, vector<int>(this->column));
}

Matrix::~Matrix() = default;

void Matrix::add(const int i, const int j, const int info) {
    if (!verify(i, j)) {
        cout << "Index out of bounds" << endl;
        return;
    }
    this->matrix[i][j] = info;
}


bool Matrix::verify(const int i, const int j) const {
    return i >= 0 && i < line && j >= 0 && j < column;
}


int Matrix::get(const int i, const int j) {
    if (!verify(i, j)) {
        cout << "Index out of bounds" << endl;
        return -1;
    }
    return this->matrix[i][j];
}


