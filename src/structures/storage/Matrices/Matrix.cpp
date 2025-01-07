//
// Created by Nashi on 07/01/2025.
//

#include "../../../../include/structures/storage/matrices/Matrix.h"
#include <iostream>

Matrix::Matrix(const int nl, const int nc) {
    this->line= nl;
    this->column = nc;

    this->matrix = vector(this->line,vector<Edge *>(this->column));
}

Matrix::~Matrix() {
}


bool Matrix::verify(const int i, const int j) const {
    return i >= 0 && i < line && j >= 0 && j < column;
}


Edge *Matrix::get(const int i, const int j) {
    if (!verify(i, j)) {
        cout << "Index out of bounds" << endl;
        return nullptr;
    }
    return this->matrix[i][j];
}

void Matrix::add(Edge *info) {
    const auto edge = info;
    const int i = edge->getOrigem()->getId() - 1;
    const int j = edge->getDestino()->getId() - 1;
    this->set(i, j, info);
}


void Matrix::set(const int i, const int j, Edge *info) {
    if (!verify(i, j)) {
        cout << "Index out of bounds" << endl;
        return;
    }
    this->matrix[i][j] = info;
}
