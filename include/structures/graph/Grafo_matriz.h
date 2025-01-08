#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H

#include "Grafo.h"

#include "../storage/matrices/Matrix.h"


class Grafo_matriz final : public Grafo {
    Matrix *ARESTAS;

public:
    Grafo_matriz();

    ~Grafo_matriz() override;

    bool eh_bipartido() override;

    int n_conexo() override;

    bool eh_completo() override;

    bool eh_arvore() override;

    bool possui_articulacao() override;

    bool possui_ponte() override;

    void set_direcionado(bool direcionado) override;
};


#endif //GRAFO_MATRIZ_H
