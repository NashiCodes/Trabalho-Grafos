
#ifndef MATRIXLIN_H
#define MATRIXLIN_H
#include "../../graph/basics/Edge.h"
#include <vector>

using namespace std;

/**
 * @brief Classe para armazenamento de dados em forma de matriz
 * Seguir o exemplo de implementação no meu repositório https://github.com/NashiCodes/DataStructs
 * Lá contem um exemplo de implementação de uma matriz comum e uma matriz linha
 * usar o mesmo conceito de modelo para as duas classes
 * @tparam T Tipo de dado a ser armazenado, como arestas ou vertices
 */

class MatrixLin final : public Matrix {
    vector<int> matrixLin;
    [[nodiscard]] bool verify(int i, int j) const override;
    [[nodiscard]] static int toLinearIndex(int i, int j) ;

public:
    explicit MatrixLin(int n);
    ~MatrixLin() override;

    void add(int i, int j, int info) override;
    int get(int i, int j) override;

    [[nodiscard]] int getMatrixSize() const override { return this->line * this->column; }
};



#endif //MATRIXLIN_H
