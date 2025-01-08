//
// Created by Nashi on 06/01/2025.
//

#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include "Grafo.h"


class Grafo_lista final : public Grafo {
public:
    Grafo_lista();

    ~Grafo_lista() override;

    bool eh_bipartido() override;

    int n_conexo() override;

    bool eh_completo() override;

    bool eh_arvore() override;

    bool possui_articulacao() override;

    bool possui_ponte() override;

    void set_direcionado(const bool direcionado) override;
};


#endif //GRAFO_LISTA_H
