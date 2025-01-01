#ifndef GRAFO_H
#define GRAFO_H
#include "Node.h"
#include "storage/Storage.h"


class Edge;

class Grafo {
public:
    Grafo(Storage<Node> *NOS, Storage<Edge> *ARESTAS) : Grau(0), Direcionado(false), VerticePonderado(false),
                                                        ArestaPonderada(false) {
        this->NOS = NOS;
        this->ARESTAS = ARESTAS;
    }

    bool eh_bipartido();

    bool n_conexo();

    int get_grau();

    bool eh_direcionado();

    bool vertice_ponderado();

    bool aresta_ponderada();

    bool eh_completo();

    bool eh_arvore();

    bool possui_articulacao();

    bool possui_ponte();

    void carregar_grafo();

    Grafo *novo_grafo();

private:
    Storage<Node> *NOS;
    Storage<Edge> *ARESTAS;
    int Grau;
    bool Direcionado;
    bool VerticePonderado;
    bool ArestaPonderada;
};


#endif //GRAFO_H
