//
// Created by dsalvaro on 07/01/2025.
//
#include <iostream>
#include "MatrixLin.h"
#include "../../graph/basics/Edge.h"

using namespace std;


MatrixLin::MatrixLin(const int nl, const int nc) {
    line = nl;
    column = nc;

    matrix = new Edge*[line * column];
}


MatrixLin::~MatrixLin() {
    delete[] matrix;
}


bool MatrixLin::verify(const int i, const int j) const {
    return i >= 0 && i < line && j >= 0 && j < column;
}


int MatrixLin::toLinearIndex(const int i, const int j) const {
    return i * column + j;
}


Edge* MatrixLin::get(int i, int j) {
    if (!verify(i, j)) {
        cout << "Index out of bounds" << endl;
        return nullptr;
    }
    return matrix[toLinearIndex(i, j)];
}


void MatrixLin::add(Edge *info) {
    auto edge = info;
    const int i = edge->getOrigem()->getId();
    const int j = edge->getDestino()->getId();
    this->set(i, j, info);
}


void MatrixLin::set(int i, int j, Edge* info) {
    if (!verify(i, j)) {
        cout << "Index out of bounds" << endl;
        return;
    }
    matrix[toLinearIndex(i, j)] = info;
}
