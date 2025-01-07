//
// Created by dsalvaro on 07/01/2025.
//
#include <iostream>
#include "../../../../include/structures/storage/matrices/MatrixLin.h"


using namespace std;


MatrixLin::MatrixLin(const int nl, const int nc): Matrix(nl, nc) {
    this->line = nl;
    this->column = nc;
    this->matrix = vector<Edge *>(this->line * this->column);
}


MatrixLin::~MatrixLin() {
    for (const auto &i : matrix) {
        delete i;
    }
}


bool MatrixLin::verify(const int i, const int j) const {
    return i >= 0 && i < line && j >= 0 && j < column;
}


int MatrixLin::toLinearIndex(const int i, const int j) const {
    return i * column + j;
}


Edge *MatrixLin::get(const int i, const int j) {
    if (!verify(i, j)) {
        cout << "Index out of bounds" << endl;
        return nullptr;
    }
    return matrix[toLinearIndex(i, j)];
}


void MatrixLin::add(Edge *info) {
    const auto edge = info;
    const int i = edge->getOrigem()->getId() - 1;
    const int j = edge->getDestino()->getId() - 1;
    this->set(i, j, info);
}


void MatrixLin::set(const int i, const int j, Edge *info)  {
    if (!verify(i, j)) {
        cout << "Index out of bounds" << endl;
        return;
    }
    matrix[toLinearIndex(i, j)] = info;
}
