//
// Created by Nashi on 07/01/2025.
//

#ifndef MATRIX2_H
#define MATRIX2_H

#include <vector>

#include "../../graph/basics/Edge.h"

using namespace std;

class Matrix {
    int line;
    int column;
    vector<vector<Edge *>> matrix;
    [[nodiscard]] virtual bool verify(int i, int j) const;

public:
    Matrix(int nl, int nc);

    virtual ~Matrix();

    virtual void set(int i, int j, Edge *info);

    virtual Edge* get(int i, int j);
    [[nodiscard]] virtual int getMatrixSize() const { return line * column; }

    virtual void add(Edge* info);
};



#endif //MATRIX2_H
