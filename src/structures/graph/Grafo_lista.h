//
// Created by Nashi on 06/01/2025.
//

#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H
#include "Grafo.h"
#include "../storage/List/ListStorage.h"
#include "basics/Edge.h"
#include "basics/Node.h"


class Grafo_lista final : public Grafo {
public:
    Grafo_lista() {
        this->NOS = new ListStorage<Node *>();
        this->ARESTAS = new ListStorage<Edge *>();
    }

    ~Grafo_lista() override = default;

    bool eh_bipartido() override { return false; };

    bool n_conexo() override { return false; };

    bool eh_completo() override { return false; };

    bool eh_arvore() override {
        cout << "Grafo Lista" << endl;
        return false;
    };

    bool possui_articulacao() override { return false; };

    bool possui_ponte() override { return false; };
};


#endif //GRAFO_LISTA_H
