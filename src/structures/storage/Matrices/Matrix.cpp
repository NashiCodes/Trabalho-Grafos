//
// Created by Nashi on 07/01/2025.
//

#include "../../../../include/structures/storage/matrices/Matrix.h"
#include <iostream>

Matrix::Matrix(const int n): line(n), column(n) {
    this->matrix = vector(this->line, vector<int>(this->column, 0));
}

Matrix::~Matrix() = default;

void Matrix::add(const int i, const int j, const int info) {
    if (!verify(i - 1, j - 1)) {
        return;
    }
    this->matrix[i - 1][j - 1] = info;
}


bool Matrix::verify(const int i, const int j) const {
    return i >= 0 && i < line && j >= 0 && j < column;
}


int Matrix::get(const int i, const int j) {
    if (!verify(i - 1, j - 1)) {
        return 0;
    }
    return this->matrix[i - 1][j - 1];
}
