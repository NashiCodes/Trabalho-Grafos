#include "../../../include/structures/graph/Grafo_matriz.h"
#include "../storage/Matrices/MatrixLin.cpp"
#include "../storage/Matrices/Matrix.cpp"


Grafo_matriz::Grafo_matriz(): ARESTAS(nullptr) {
    this->NOS = new List<Node *>();
}

Grafo_matriz::~Grafo_matriz() {
    delete this->NOS;
    delete this->ARESTAS;
}

vector<int> Grafo_matriz::getVizinhos(const int no) {
    auto vizinhos = vector<int>();

    for (int i = 0; i <= this->Ordem; i++) {
        if (this->ARESTAS->get(no, i) != 0) {
            vizinhos.push_back(i);
        }
    }
    return vizinhos;
}

void Grafo_matriz::set_direcionado(const bool direcionado) {
    this->Direcionado = direcionado;

    if (direcionado) {
        this->ARESTAS = new Matrix(this->Ordem);
    } else {
        this->ARESTAS = new MatrixLin(this->Ordem);
    }
}

void Grafo_matriz::addAresta(Node *origem, Node *destino, const int peso) {
    this->ARESTAS->add(origem->getId(), destino->getId(), peso);
}
