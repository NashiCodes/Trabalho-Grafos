//
// Created by Nashi on 07/01/2025.
//

#ifndef MATRIX2_H
#define MATRIX2_H

#include <vector>


using namespace std;

class Matrix {
    vector<vector<int> > matrix;
protected:
    int line;
    int column;

    [[nodiscard]] virtual bool verify(int i, int j) const;

public:
    explicit Matrix(int n);

    virtual ~Matrix();

    virtual void add(int i, int j, int info);

    virtual int get(int i, int j);

    [[nodiscard]] virtual int getMatrixSize() const { return this->line * this->column; }
};


#endif //MATRIX2_H
