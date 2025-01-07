#include <fstream>
#include <sstream>
#include <string>
#include "Grafo.h"

using namespace std;

void Grafo::carregar_grafo(ifstream *entrada, ofstream *saida) {
    string line;
    getline(*entrada, line);

    istringstream iss(line);

    int direcionado, vPonderado, aPonderada;

    iss >> this->Ordem >> direcionado >> vPonderado >> aPonderada;

    this->set_direcionado(direcionado);
    this->set_vertice_ponderado(vPonderado);
    this->set_aresta_ponderada(aPonderada);

    if (vPonderado) {
        getline(*entrada, line);
        iss = istringstream(line);

        for (int i = 0; i < this->Ordem; i++) {
            int peso;
            iss >> peso;
            this->NOS->add(new Node(i + 1, peso));
        }
    }

    while (getline(*entrada, line)) {
        iss = istringstream(line);

        int origem, destino, peso;
        iss >> origem >> destino >> peso;

        if (this->NOS->get(origem) == nullptr) {
            this->NOS->add(new Node(origem, 0));
        }if (this->NOS->get(destino) == nullptr) {
            this->NOS->add(new Node(destino, 0));
        }

        auto *noOrigem = this->NOS->get(origem);
        auto *noDestino = this->NOS->get(destino);

        this->ARESTAS->add(new Edge(this->ARESTAS->getSize() + 1, peso, noOrigem, noDestino));
    }

}
