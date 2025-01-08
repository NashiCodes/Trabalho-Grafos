
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
    int line;
    int column;
    vector<Edge *> matrix;
    [[nodiscard]] bool verify(int i, int j) const override;
    [[nodiscard]] int toLinearIndex(int i, int j) const;

public:
    MatrixLin(int nl, int nc);
    ~MatrixLin() override;

    void set(int i, int j, Edge* info) override;
    Edge* get(int i, int j) override;

    [[nodiscard]] int getMatrixSize() const override { return line * column; }

    void add(Edge *info) override;
};



#endif //MATRIXLIN_H
