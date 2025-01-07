//
// Created by Nashi on 27/12/2024.
//
#include <iostream>
#include "Matrix.h"

using namespace std;


Matrix::Matrix(const int nl, const int nc) {
    this->line = nl;
    this->column = nc;

    this->matrix = new Edge*[this->line];
    for (int i = 0; i < this->line; i++) {
        this->matrix[i] = new Edge[this->column];
    }
}


Matrix::~Matrix() {
    for (int i = 0; i < line; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}


bool Matrix::verify(const int i, const int j) const {
    return i >= 0 && i < line && j >= 0 && j < column;
}


Edge* Matrix::get(const int i, const int j) {
    if (!verify(i, j)) {
        cout << "Index out of bounds" << endl;
        return nullptr;
    }
    return &matrix[i][j];
}

void Matrix::add(Edge* info) {
    const auto edge = info;
    const int i = edge->getOrigem()->getId();
    const int j = edge->getDestino()->getId();
    this->set(i, j, *info);
}


void Matrix::set(const int i, const int j, const Edge &info) const {
    if (!verify(i, j)) {
        cout << "Index out of bounds" << endl;
        return;
    }
    matrix[i][j] = info;
}
