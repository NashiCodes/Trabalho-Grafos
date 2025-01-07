#ifndef GRAFO_H
#define GRAFO_H
#include "../storage/List/ListStorage.cpp"
#include "basics/Edge.h"
#include "basics/Node.h"



class Grafo {
public:
    Grafo() : Grau(0), Direcionado(false), VerticePonderado(false),
                                                        ArestaPonderada(false) {
        this->NOS = new ListStorage<Node>();
        this->ARESTAS = new ListStorage<Edge>();
    }

    virtual ~Grafo() {
        delete this->NOS;
        delete this->ARESTAS;
    }

    virtual bool eh_bipartido() {
        return false;
    }

    virtual bool n_conexo() {
        return false;
    }

    virtual int get_grau() {
        return Grau;
    }

    virtual bool eh_direcionado() {
        return Direcionado;
    }

    virtual bool vertice_ponderado() {
        return VerticePonderado;
    }

    virtual bool aresta_ponderada() {
        return ArestaPonderada;
    }

    virtual bool eh_completo() {
        return false;
    }

    virtual bool eh_arvore() {
        return false;
    }

    virtual bool possui_articulacao() {
        return false;
    }

    virtual bool possui_ponte() {
        return false;
    }

    static void carregar_grafo(){}

    static Grafo *novo_grafo(const char tipo) {
        return new Grafo();
    }

private:
    Storage<Node> *NOS{};
    Storage<Edge> *ARESTAS{};
    int Grau;
    bool Direcionado;
    bool VerticePonderado;
    bool ArestaPonderada;
};


#endif //GRAFO_H
