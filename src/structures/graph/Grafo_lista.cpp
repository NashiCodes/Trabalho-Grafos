//
// Created by Nashi on 06/01/2025.
//

#include "../../../include/structures/graph/Grafo_lista.h"

class Node;

Grafo_lista::Grafo_lista() {
    this->NOS = new List<Node *>();
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
}

void Grafo_lista::removeVertice(const int no) {
    const auto node = this->NOS->get(no);

    if (node == nullptr) {
        return;
    }

    for (const auto aresta : node->getArestas()) {
        const auto destino = aresta->getDestino() == node ? aresta->getOrigem() : aresta->getDestino();
        destino->removeAresta(aresta);
        node->set_grau_entrada(node->getGrauEntrada() - 1);
    }

    this->NOS->remove(node);

    delete node;

    this->Ordem--;
}

vector<int> Grafo_lista::getVizinhos(const int no) {
    auto vizinhos = vector<int>();

    for (const auto aresta : this->NOS->get(no)->getArestas()) {
        const auto destino = aresta->getDestino()->getId() == no ? aresta->getOrigem() : aresta->getDestino();

        vizinhos.push_back(destino->getId());
    }

    return vizinhos;
}
