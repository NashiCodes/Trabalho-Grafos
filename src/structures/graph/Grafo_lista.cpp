//
// Created by Nashi on 06/01/2025.
//

#include "../../../include/structures/graph/Grafo_lista.h"

class Node;

Grafo_lista::Grafo_lista() {
    this->NOS = new List<Node *>();
    this->ARESTAS = new List<Edge *>();
}

Grafo_lista::~Grafo_lista() {
    delete this->NOS;
}

void Grafo_lista::addAresta(Node *origem, Node *destino, const int peso) {
    const auto Aresta = new Edge(origem, destino, peso);

    origem->addAresta(Aresta);
    destino->set_grau_entrada(destino->getGrauEntrada() + 1);

    if (!this->Direcionado) {
        destino->addAresta(Aresta);
        origem->set_grau_entrada(origem->getGrauEntrada() + 1);
    }

    this->ARESTAS->add(Aresta);
}

void Grafo_lista::removeVertice(const int no) {
    const auto node = this->NOS->get(no);

    if (node == nullptr) {
        return;
    }

    for (const auto aresta: node->getArestas()) {
        const auto destino = aresta->getDestino() == node ? aresta->getOrigem() : aresta->getDestino();
        destino->removeAresta(aresta);
        node->set_grau_entrada(node->getGrauEntrada() - 1);
        this->ARESTAS->remove(aresta);
    }

    this->NOS->remove(node);

    delete node;

    this->Ordem--;
}

void Grafo_lista::salvaGrafos() {
    *this->Output << this->get_ordem() << " " << this->eh_direcionado() << " " << this->vertice_ponderado() << " "
            << this->aresta_ponderada() << endl;

    if (this->vertice_ponderado()) {
        for (int i = 1; i <= this->NOS->getSize(); i++) {
            *this->Output << this->NOS->get(i)->getPeso() << " ";
        }
        *this->Output << endl;
    }

    auto visitados = vector<bool>(this->Ordem + 1, false);
    for (int no = 1; no <= this->NOS->getSize(); no++) {
        for (const auto aresta: this->NOS->get(no)->getArestas()) {
            const auto destino = aresta->getDestino() == this->NOS->get(no)
                                     ? aresta->getOrigem()
                                     : aresta->getDestino();
            if (this->Direcionado) {
                *this->Output << no << " " << destino->getId() << " ";
                if (this->aresta_ponderada()) {
                    *this->Output << aresta->getPeso() << endl;
                } else {
                    *this->Output << endl;
                }
            } else if (!visitados[destino->getId()]) {
                *this->Output << no << " " << destino->getId() << " ";
                if (this->aresta_ponderada()) {
                    *this->Output << aresta->getPeso() << endl;
                } else {
                    *this->Output << endl;
                }
            }
        }
        visitados[no] = true;
    }
}

vector<int> Grafo_lista::getVizinhos(const int no) {
    auto vizinhos = vector<int>();

    for (const auto aresta: this->NOS->get(no)->getArestas()) {
        const auto destino = aresta->getDestino()->getId() == no ? aresta->getOrigem() : aresta->getDestino();

        vizinhos.push_back(destino->getId());
    }

    return vizinhos;
}
