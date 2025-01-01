
#ifndef MATRIX_H
#define MATRIX_H
#include "../Storage.h"

/**
 * @brief Classe para armazenamento de dados em forma de matriz
 * Seguir o exemplo de implementação no meu repositório https://github.com/NashiCodes/DataStructs
 * Lá contem um exemplo de implementação de uma matriz comum e uma matriz linha
 * usar o mesmo conceito de template para as duas classes
 * @tparam T Tipo de dado a ser armazenado, como arestas ou vertices
 */
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
