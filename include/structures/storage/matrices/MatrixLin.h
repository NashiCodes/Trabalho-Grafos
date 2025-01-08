#ifndef MATRIXLIN_H
#define MATRIXLIN_H

#include <vector>

using namespace std;

/**
 * @brief Classe para armazenamento de dados em forma de matriz
 * Seguir o exemplo de implementação no meu repositório https://github.com/NashiCodes/DataStructs
 * Lá contem um exemplo de implementação de uma matriz comum e uma matriz linha
 * usar o mesmo conceito de modelo para as duas classes
 * @tparam T Tipo de dado a ser armazenado, como arestas ou vertices
 */

class MatrixLin {
    vector<int> matrixLin;
protected:
    int line;
    int column;
    [[nodiscard]] bool verify(int i, int j) const;
    [[nodiscard]] int toLinearIndex(int i, int j) const;

public:
    explicit MatrixLin(int n);

    virtual ~MatrixLin();

    virtual void add(int i, int j, int info);

    virtual int get(int i, int j);

    [[nodiscard]] virtual int getMatrixSize() const { return this->line * this->column; }
};


#endif //MATRIXLIN_H
