
#include "../../../include/structures/graph/Grafo_matriz.h"
#include "../storage/Matrices/MatrixLin.cpp"
#include "../storage/Matrices/Matrix.cpp"


Grafo_matriz::Grafo_matriz(): ARESTAS(nullptr) {
    this->NOS = new List<Node *>();
}

Grafo_matriz::~Grafo_matriz(){
    delete this->NOS;
    delete this->ARESTAS;
}

bool Grafo_matriz::eh_bipartido() {
    return Grafo::eh_bipartido();
}

int Grafo_matriz::n_conexo() {
    return Grafo::n_conexo();
}

bool Grafo_matriz::eh_completo() {
    return Grafo::eh_completo();
}

bool Grafo_matriz::eh_arvore() {
    return Grafo::eh_arvore();
}

bool Grafo_matriz::possui_articulacao() {
    return Grafo::possui_articulacao();
}

bool Grafo_matriz::possui_ponte() {
    return Grafo::possui_ponte();
}

void Grafo_matriz::set_direcionado(const bool direcionado) {
    this->Direcionado = direcionado;

    if (direcionado) {
        this->ARESTAS = new Matrix(this->Ordem, this->Ordem);
    } else {
        this->ARESTAS = new MatrixLin(this->Ordem, this->Ordem);
    }
}
