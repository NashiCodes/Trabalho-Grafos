//
// Created by dsalvaro on 07/01/2025.
//
#include <iostream>
#include "../../../../include/structures/storage/matrices/MatrixLin.h"


using namespace std;


MatrixLin::MatrixLin(const int n): Matrix(n) {
    this->matrixLin = vector<int>(n * (n + 1) / 2, 0);
}


MatrixLin::~MatrixLin() = default;


bool MatrixLin::verify(const int i, const int j) const {
    return i > 0 && i <= this->line && j > 0 && j <= this->column;
}


int MatrixLin::toLinearIndex(const int i, const int j) const {
    if (i <= j) {
        const int index = this->line * (i - 1) - (i - 2) * (i - 1) / 2 + (j - i);

        return index;
    }
    return -1;
}


int MatrixLin::get(const int i, const int j) {
    if (!verify(i, j)) {
        return 0;
    }

    if (i > j)
        return matrixLin.at(toLinearIndex(j, i));
    return matrixLin.at(toLinearIndex(i, j));
}


void MatrixLin::add(const int i, const int j, int info) {
    if (!verify(i, j)) {
        return;
    }
    if (i > j)
        matrixLin.at(toLinearIndex(j, i)) = info;
    else
        matrixLin.at(toLinearIndex(i, j)) = info;
}
