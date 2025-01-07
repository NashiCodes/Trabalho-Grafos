#ifndef GRAFO_H
#define GRAFO_H
#include "../storage/List/ListStorage.cpp"
#include "basics/Edge.cpp"
#include "basics/Node.cpp"


class Grafo {
public:
    Grafo() : Grau(0), Ordem(0), ArestaPonderada(false), VerticePonderado(false),
              Direcionado(false), Input(nullptr), Output(nullptr) {
    }

    virtual ~Grafo() {
        delete this->NOS;
        delete this->ARESTAS;
    }

    virtual bool eh_bipartido() { return false; };

    virtual bool n_conexo() { return false; };

    [[nodiscard]] int get_grau() const {
        return Grau;
    }

    [[nodiscard]] bool eh_direcionado() const {
        return Direcionado;
    }

    [[nodiscard]] bool vertice_ponderado() const {
        return VerticePonderado;
    }

    [[nodiscard]] bool aresta_ponderada() const {
        return ArestaPonderada;
    }

    virtual bool eh_completo() { return false; };

    virtual bool eh_arvore() { return false; };

    virtual bool possui_articulacao() { return false; };

    virtual bool possui_ponte() {
        return false;
    };

    static auto carregar_grafo(ifstream *entrada, ofstream *saida, const char tipo);

    static auto novo_grafo(const char tipo);

    void set_aresta_ponderada(const bool aresta_ponderada) {
        ArestaPonderada = aresta_ponderada;
    }

    void set_vertice_ponderado(const bool vertice_ponderado) {
        VerticePonderado = vertice_ponderado;
    }

    virtual void set_direcionado(const bool direcionado) {
        Direcionado = direcionado;
    }

protected:
    int Grau;
    int Ordem;
    bool ArestaPonderada;
    bool VerticePonderado;
    bool Direcionado;
    ifstream *Input;
    ofstream *Output;
    Storage<Node> *NOS{};
    Storage<Edge> *ARESTAS{};
};


#endif //GRAFO_H
