
#ifndef MATRIX_H
#define MATRIX_H
#include "../Storage.h"

/**
 * @brief Classe para armazenamento de dados em forma de matriz
 * Seguir o exemplo de implementação no meu repositório https://github.com/NashiCodes/DataStructs
 * Lá contem um exemplo de implementação de uma matriz comum e uma matriz linha
 * usar o mesmo conceito de modelo para as duas classes
 * @tparam T Tipo de dado a ser armazenado, como arestas ou vertices
 */
template<class T>
class Matrix final : public Storage<T> {
    int line;
    int column;
    T **matrix;
    [[nodiscard]] bool verify(int i, int j) const;

public:
    Matrix(int nl, int nc);
    ~Matrix() override;
    void set(int i, int j, T info);
    T get(int i, int j);
};



#endif //MATRIX_H
