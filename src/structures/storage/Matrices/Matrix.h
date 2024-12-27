//
// Created by Nashi on 27/12/2024.
//

#ifndef MATRIX_H
#define MATRIX_H
#include "../Storage.h"

template<class T>
class Matrix final : public Storage<T> {
private:
    int line;
    int column;
    T **matrix;
    bool verify(int line, int column);

public:

};



#endif //MATRIX_H
