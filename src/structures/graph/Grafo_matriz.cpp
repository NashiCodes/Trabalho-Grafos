
#include "Grafo_matriz.h"
#include "../storage/Matrices/Matrix.cpp"
#include "../storage/Matrices/MatrixLin.cpp"
#include "../storage/List/ListStorage.cpp"


Grafo_matriz::Grafo_matriz() {
    this->NOS = new ListStorage<Node *>();
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
        this->ARESTAS = new Matrix(this->Ordem, this->Ordem);
    } else {
        this->ARESTAS = new MatrixLin(this->Ordem, this->Ordem);
    }
}
