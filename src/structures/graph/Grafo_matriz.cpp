//
// Created by Nashi on 06/01/2025.
//

#include "Grafo_matriz.h"

Grafo_matriz::~Grafo_matriz() {
    delete this->NOS;
    delete this->ARESTAS;
}

bool Grafo_matriz::eh_bipartido() {
    return false;
}

bool Grafo_matriz::n_conexo() {
    return false;
}

bool Grafo_matriz::eh_completo() {
    return false;
}

bool Grafo_matriz::eh_arvore() {
    return false;
}

bool Grafo_matriz::possui_articulacao() {
    return false;
}

bool Grafo_matriz::possui_ponte() {
    return false;
}

void Grafo_matriz::set_direcionado(const bool direcionado) {
    this->Direcionado = direcionado;

    if (direcionado) {
        this->ARESTAS = new Matrix<Edge>(this->Ordem, this->Ordem);
    } else {
        // Representação linear de matriz triangular
    }
}
