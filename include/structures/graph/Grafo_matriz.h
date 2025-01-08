#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H

#include "Grafo.h"

#include "../storage/matrices/Matrix.h"


class Grafo_matriz final : public Grafo {
    Matrix *ARESTAS;

    vector<int> getVizinhos(int no) override ;
public:
    Grafo_matriz();

    ~Grafo_matriz() override;

    void set_direcionado(bool direcionado) override;

    void addAresta(Node *origem, Node *destino, int peso) override;

    void removeVertice(int no) override;
};


#endif //GRAFO_MATRIZ_H
