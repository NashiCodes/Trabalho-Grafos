#include "../../../include/structures/graph/Grafo_matriz.h"

#include <memory>

#include "../storage/Matrices/MatrixLin.cpp"
#include "../storage/Matrices/Matrix.cpp"

Grafo_matriz::Grafo_matriz() : ARESTAS(nullptr) {
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

void Grafo_matriz::removeVertice(int no) {
    for (int i = 1; i <= this->Ordem; i++) {
        this->ARESTAS->add(no, i, 0);
        this->ARESTAS->add(i, no, 0);
    }

    auto node = this->NOS->get(no);

    this->NOS->remove(this->NOS->get(no));

    delete node;

    this->Ordem--;
}

void Grafo_matriz::salvaGrafos() {
    *this->Output << this->get_ordem() << " " << this->eh_direcionado() << " " << this->vertice_ponderado() << " "
            << this->aresta_ponderada() << endl;

    if (this->vertice_ponderado()) {
        for (int i = 1; i <= this->NOS->getSize(); i++) {
            *this->Output << this->NOS->get(i)->getPeso() << " ";
        }
        *this->Output << endl;
    }

    auto visitados = vector<bool>(this->Ordem + 1, false);
    for (int no = 1; no <= Ordem; no++) {
        for (int i = 1; i <= Ordem; i++) {
            if (this->ARESTAS->get(no, i) != 0) {
                if (this->Direcionado) {
                    *this->Output << no << " " << i << " ";
                    if (this->aresta_ponderada()) {
                        *this->Output << this->ARESTAS->get(no, i) << endl;
                    } else {
                        *this->Output << endl;
                    }
                } else if (!visitados[i]) {
                    *this->Output << no << " " << i << " ";
                    if (this->aresta_ponderada()) {
                        *this->Output << this->ARESTAS->get(no, i) << endl;
                    } else {
                        *this->Output << endl;
                    }
                }
            }
        }
        visitados[no] = true;        
    }
}
