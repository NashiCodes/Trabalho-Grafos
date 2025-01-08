#include <fstream>
#include <algorithm>
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

vector<int> *Grafo::fechoTransitivoDireto(const int no) {
    if (this->NOS->get(no) == nullptr) {
        return {};
    }
    const auto fecho = new vector<int>();
    this->auxFechoTransitivoDireto(no, fecho);

    return fecho;
}

void Grafo::auxFechoTransitivoDireto(const int no, vector<int> *visitados) {
    visitados->push_back(no);

    const auto vizinhos = this->getVizinhos(no);
    for (const auto &vizinho: vizinhos) {
        if (find(visitados->begin(), visitados->end(), vizinho) == visitados->end()) {
            this->auxFechoTransitivoDireto(vizinho, visitados);
        }
    }
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

int Grafo::n_conexo() {
    if (this->componentesConexas != -1) {
        return this->componentesConexas;
    }

    this->componentesConexas = 0;

    auto visitados = vector<bool>();
    auto conexos = vector<vector<int> >();
    for (int i = 0; i < this->Ordem; i++) {
        visitados.push_back(false);
    }

    for (int i = 0; i < this->Ordem; i++) {
        if (!visitados[i]) {
            conexos.emplace_back();
            const auto fecho = this->fechoTransitivoDireto(i + 1);
            if (fecho == nullptr) {
                continue;
            }
            conexos[this->componentesConexas] = *fecho;
            delete fecho;
            for (const auto &no: conexos[this->componentesConexas]) {
                visitados[no - 1] = true;
            }
            this->componentesConexas++;
            if (conexos[this->componentesConexas - 1].size() == this->Ordem) {
                return this->componentesConexas;
            }
        }
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

bool Grafo::eh_completo() {
    if (this->completoPassado)
        return this->completo;

    this->completoPassado = true;

    for (int i = 0; i < this->Ordem; i++) {
        const auto vizinhos = this->getVizinhos(i + 1);
        if (vizinhos.size() != this->Ordem - 1) {
            this->completo = false;
            return false;
        }
    }

    this->completo = true;
    return this->completo;
}

bool Grafo::eh_arvore() {
    if (this->arvorePassado)
        return this->arvore;
    if (this->n_conexo() != 1) {
        this->arvore = false;
        return false;
    }

    auto visitados = vector<bool>(this->Ordem + 1, false);
    if (eh_Ciclo(1, &visitados, -1)) {
        this->arvore = false;
        return false;
    }

    this->arvore = true;
    return this->arvore;
}

bool Grafo::eh_Ciclo(const int no, vector<bool> *visitados, const int pai) {
    visitados->at(no) = true;

    const auto vizinhos = this->getVizinhos(no);
    for (const auto &vizinho: vizinhos) {
        if (!visitados->at(vizinho)) {
            if (eh_Ciclo(vizinho, visitados, no)) {
                return true;
            }
        } else if (vizinho != pai) {
            return true;
        }
    }

    return false;
}

bool Grafo::possui_articulacao() {
    if (this->verticeArticulacao != -1) {
        return this->verticeArticulacao > 0;
    }
    this->verticeArticulacao = 0;

    for (int i = 1; i <= this->Ordem; i++) {
        auto componentes = 0;

        auto visitados = vector<bool>(this->Ordem + 1, false);

        for (int j = 1; j <= this->Ordem; j++) {
            if (!visitados[j] && j != i) {
                componentes++;
                this->auxArticulacao(&visitados, i, j);
            }
        }

        if (componentes > 1) {
            this->verticeArticulacao++;
        }
    }

    return this->verticeArticulacao > 0;
}

void Grafo::auxArticulacao(vector<bool> *visitados, int pivot, int current) {
    visitados->at(current) = true;

    const auto vizinhos = this->getVizinhos(current);
    for (const auto &vizinho: vizinhos) {
        if (!visitados->at(vizinho) && vizinho != pivot) {
            this->auxArticulacao(visitados, pivot, vizinho);
        }
    }
}

bool Grafo::possui_ponte() {
    if (this->arestaPonte != -1) {
        return this->arestaPonte > 0;
    }

    this->arestaPonte = 0;

    auto visitados = vector<bool>(this->Ordem + 1, false);
    auto disc = vector<int>(this->Ordem + 1, -1);
    auto low = vector<int>(this->Ordem + 1, -1);

    constexpr auto parent = -1;
    auto time = 0;

    for (int i = 1; i < this->Ordem; i++) {
        if (!visitados[i])
            this->auxPonte(i, visitados, disc, low, parent, time);
    }

    return this->arestaPonte > 0;
}

void Grafo::auxPonte(const int u, vector<bool> &visited, vector<int> &disc, vector<int> &low, int parent, int &time) {
    visited[u] = true;
    disc[u] = low[u] = ++time;
    const auto vizinhos = this->getVizinhos(u);
    for (const auto &v: vizinhos) {
        if (v != parent) {
            if (visited[v]) {
                low[u] = min(low[u], disc[v]);
            } else {
                parent = u;
                auxPonte(v, visited, disc, low, parent, time);

                low[u] = min(low[u], low[v]);

                if (low[v] > disc[u]) {
                    this->arestaPonte++;
                }
            }
        }
    }
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

    // TODO: Criar Função para salvar arestas tanto para matriz quanto para lista

    *this->Output << endl;
}

void Grafo::removeVertice(int no) {
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
