//
// Created by Nashi on 06/01/2025.
//

#include "../../../include/structures/graph/Grafo_lista.h"
#include "Grafo.cpp"

class Node;

Grafo_lista::Grafo_lista() {
    this->NOS = new List<Node *>();
}

Grafo_lista::~Grafo_lista() {
    delete this->NOS;
}

bool Grafo_lista::eh_bipartido() {
    if (this->bipartidoPassado)
        return this->bipartido;

    // TODO: Implementar
    return false;
}

int Grafo_lista::n_conexo() {
    if (this->componentesConexas != -1)
        return this->componentesConexas;

    // TODO: Implementar
    return false;
}

bool Grafo_lista::eh_completo() {
    if (this->completoPassado)
        return this->completo;

    // TODO: Implementar
    return false;
}

bool Grafo_lista::eh_arvore() {
    if (this->arvorePassado)
        return this->arvore;

    // TODO: Implementar
    return false;
}

bool Grafo_lista::possui_articulacao() {
    if (this->verticeArticulacao != -1)
        return this->verticeArticulacao > 0;

    // TODO: Implementar
    return false;
}

bool Grafo_lista::possui_ponte() {
    if (this->arestaPonte != -1)
        return this->arestaPonte > 0;

    // TODO: Implementar
    return false;
}

void Grafo_lista::set_direcionado(const bool direcionado) {
    Grafo::set_direcionado(direcionado);
}
