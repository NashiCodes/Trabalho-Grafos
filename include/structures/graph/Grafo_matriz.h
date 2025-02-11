#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H

#include "Grafo.h"

#include "../storage/matrices/Matrix.h"


class Grafo_matriz final : public Grafo {
    Matrix *ARESTAS;

    vector<int> getVizinhos(int no) override ;
    int getAresta(int origem, int destino) override;
public:
    Grafo_matriz();

    ~Grafo_matriz() override;

    void set_direcionado(bool direcionado) override;

    void addAresta(Node *origem, Node *destino, int peso) override;

    void removeAresta(Node *origem, Node *destino);

    void restaurarAresta(Node *origem, Node *destino, int peso);

    void removeVertice(int no) override;

    void salvaGrafos() override;
};


#endif //GRAFO_MATRIZ_H
