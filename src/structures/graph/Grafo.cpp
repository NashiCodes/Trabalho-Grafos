#include <fstream>
#include <sstream>
#include <string>

#include "../../../include/structures/graph/Grafo.h"
#include "../storage/List/List.cpp"

class Node;
using namespace std;

Grafo::Grafo() : Input(nullptr), Output(nullptr), ArestaPonderada(false), VerticePonderado(false),
                 Direcionado(false), completo(false),
                 bipartido(false),
                 arvore(false) {
    this->NOS = new List<Node *>();
}

Grafo::~Grafo() {
    delete this->NOS;
}

bool Grafo::eh_bipartido() {
    if (this->bipartidoPassado)
        return this->bipartido;


    this->bipartidoPassado = true;

    const auto colors = new vector<int>(this->Ordem, -1);

    for (int i = 0; i < this->Ordem; i++) {
        if (colors->at(i) == -1) {
            if (!auxBipartido(i, 0, colors))
                return false;
        }
    }

    this->bipartido = true;
    return true;
}

bool Grafo::auxBipartido(const int no, const int cor, vector<int> *colors) {
    colors->at(no) = cor;

    const auto vizinhos = this->getVizinhos(no + 1);

    for (const auto &vizinho: vizinhos) {
        if (colors->at(vizinho - 1) == -1) {
            if (!auxBipartido(vizinho - 1, 1 - cor, colors))
                return false;
        } else if (colors->at(vizinho - 1) == cor) {
            return false;
        }
    }

    return true;
}

int Grafo::n_conexo() const {
    if (this->componentesConexas != -1) {
        return this->componentesConexas;
    }
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

bool Grafo::eh_completo() const {
    if (this->completoPassado)
        return this->completo;

    return this->completo;
}

bool Grafo::eh_arvore() const {
    if (this->arvorePassado)
        return this->arvore;

    return this->arvore;
}

bool Grafo::possui_articulacao() const {
    if (this->verticeArticulacao != -1) {
        return this->verticeArticulacao > 0;
    }

    return this->verticeArticulacao > 0;
}

bool Grafo::possui_ponte() const {
    if (this->arestaPonte != -1) {
        return this->arestaPonte > 0;
    }
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

void Grafo::addAresta(Node *origem, Node *destino, int peso) {
}

void Grafo::salvaDescricao() {
    *this->Output << this->get_grau() << endl;
    *this->Output << this->get_ordem() << endl;
    *this->Output << this->eh_direcionado() << endl;
    *this->Output << this->n_conexo() << endl;
    *this->Output << this->vertice_ponderado() << endl;
    *this->Output << this->aresta_ponderada() << endl;
    *this->Output << this->eh_completo() << endl;
    *this->Output << this->eh_bipartido() << endl;
    *this->Output << this->eh_arvore() << endl;
    *this->Output << this->possui_ponte() << endl;
    *this->Output << this->possui_articulacao() << endl;
}

void Grafo::salvaGrafos() const {
    *this->Output << this->get_ordem() << " " << this->eh_direcionado() << " " << this->vertice_ponderado() << " "
            << this->aresta_ponderada() << endl;

    if (this->vertice_ponderado()) {
        for (int i = 1; i <= this->NOS->getSize(); i++) {
            *this->Output << this->NOS->get(i)->getPeso() << " ";
        }
        *this->Output << endl;
    }

    //TODO: Criar Função para salvar arestas tanto para matriz quanto para lista

    *this->Output << endl;
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

        iss >> origem >> destino;

        if (aPonderada) {
            iss >> peso;
        } else {
            peso = 1;
        }

        if (this->NOS->get(origem) == nullptr) {
            this->NOS->add(new Node(origem, 0));
        }
        if (this->NOS->get(destino) == nullptr) {
            this->NOS->add(new Node(destino, 0));
        }

        auto *noOrigem = this->NOS->get(origem);
        auto *noDestino = this->NOS->get(destino);

        this->addAresta(noOrigem, noDestino, peso);
        this->Grau++;
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
