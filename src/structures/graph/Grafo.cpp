#include <fstream>
#include <sstream>
#include <string>

#include "../../../include/structures/graph/Grafo.h"
#include "../storage/List/List.cpp"

class Node;
using namespace std;

Grafo::Grafo(): Input(nullptr), Output(nullptr), ArestaPonderada(false), VerticePonderado(false),
                Direcionado(false), completo(false),
                bipartido(false),
                arvore(false) {
    this->NOS = new List<Node *>();
}

Grafo::~Grafo() {
    delete this->NOS;
}

bool Grafo::eh_bipartido() {
    return this->bipartido;
}

int Grafo::n_conexo()
{
    return this->componentesConexas;
}

int Grafo::get_ordem() const {
    return this->Ordem;
}

int Grafo::get_grau() const {
    return this->Grau;    
}

bool Grafo::eh_direcionado() const {
    return this->Direcionado;
}

bool Grafo::vertice_ponderado() const {
    return this->VerticePonderado;
}

bool Grafo::aresta_ponderada() const {
    return this->ArestaPonderada;
}

bool Grafo::eh_completo() {
    return this->completo;
}

bool Grafo::eh_arvore() {
    return this->arvore;
}

bool Grafo::possui_articulacao() {
    return this->verticeArticulacao > 0;
}

bool Grafo::possui_ponte() {
    return this->arestaPonte > 0;
}

void Grafo::set_aresta_ponderada(const bool aresta_ponderada) {
    this->ArestaPonderada = aresta_ponderada;
}

void Grafo::set_vertice_ponderado(const bool vertice_ponderado) {
    this->VerticePonderado = vertice_ponderado;
}

void Grafo::set_direcionado(const bool direcionado) {
    this->Direcionado = direcionado;
}

void Grafo::carregar_grafo(ifstream *entrada, ofstream *saida) {
    this->Input = entrada;
    this->Output = saida;

    string line;
    getline(*this->Input, line);

    istringstream iss(line);

    bool direcionado, vPonderado, aPonderada;

    iss >> this->Ordem >> direcionado >> vPonderado >> aPonderada;

    this->set_direcionado(direcionado);
    this->set_vertice_ponderado(vPonderado);
    this->set_aresta_ponderada(aPonderada);

    if (vPonderado) {
        getline(*this->Input, line);
        iss = istringstream(line);

        for (int i = 0; i < this->Ordem; i++) {
            int peso;
            iss >> peso;
            this->NOS->add(new Node(i + 1, peso));
        }
    }

    while (getline(*this->Input, line)) {
        iss = istringstream(line);

        int origem, destino, peso;
        iss >> origem >> destino >> peso;

        if (this->NOS->get(origem) == nullptr) {
            this->NOS->add(new Node(origem, 0));
        }
        if (this->NOS->get(destino) == nullptr) {
            this->NOS->add(new Node(destino, 0));
        }

        auto *noOrigem = this->NOS->get(origem);
        auto *noDestino = this->NOS->get(destino);
    }
}

void Grafo::novo_grafo(ifstream *entrada, ofstream *saida) {
    this->Input = entrada;
    this->Output = saida;
    string line;


    int i = 0;

    while (getline(*this->Input, line) && !this->Input->eof()) {
        istringstream iss(line);

        // iss >>
        i++;
    }
}