#include "Grafo.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Grafo_lista.cpp"
#include "Grafo_matriz.cpp"

auto Grafo::carregar_grafo(ifstream *entrada, ofstream *saida, const char tipo) {
    auto *grafo = (tipo == 'm') ? static_cast<Grafo *>(new Grafo_matriz()) : static_cast<Grafo *>(new Grafo_lista());

    string line;
    getline(*entrada, line);

    istringstream iss(line);

    int direcionado, vPonderado, aPonderada;

    iss >> grafo->Ordem >> direcionado >> vPonderado >> aPonderada;

    grafo->set_direcionado(direcionado);
    grafo->set_vertice_ponderado(vPonderado);
    grafo->set_aresta_ponderada(aPonderada);

    if (vPonderado) {
        getline(*entrada, line);
        iss = istringstream(line);

        for (int i = 0; i < grafo->Ordem; i++) {
            int peso;
            iss >> peso;
            grafo->NOS->add(new Node(i + 1, peso));
        }
    }

    while (getline(*entrada, line)) {
        iss = istringstream(line);

        int origem, destino, peso;
        iss >> origem >> destino >> peso;

        if (grafo->NOS->get(origem) == nullptr) {
            grafo->NOS->add(new Node(origem, 0));
        }if (grafo->NOS->get(destino) == nullptr) {
            grafo->NOS->add(new Node(destino, 0));
        }

        auto *noOrigem = grafo->NOS->get(origem);
        auto *noDestino = grafo->NOS->get(destino);

        grafo->ARESTAS->add(new Edge(grafo->ARESTAS->getSize() + 1, peso, noOrigem, noDestino));
    }


    return grafo;
}

auto Grafo::novo_grafo(const char tipo) {
}
