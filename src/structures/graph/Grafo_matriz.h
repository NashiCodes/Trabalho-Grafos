//
// Created by Nashi on 06/01/2025.
//

#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H
#include "Grafo.h"
#include "../storage/Matrices/Matrix.cpp"


class Grafo_matriz final : public Grafo {
public:
    Grafo_matriz() {
        this->NOS = new ListStorage<Node>();
    }

    ~Grafo_matriz() override;

    bool eh_bipartido() override;

    bool n_conexo() override;

    bool eh_completo() override;

    bool eh_arvore() override;

    bool possui_articulacao() override;

    bool possui_ponte() override;

    void set_direcionado(bool direcionado) override;
};


#endif //GRAFO_MATRIZ_H
