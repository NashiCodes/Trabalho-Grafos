//
// Created by Nashi on 06/01/2025.
//

#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include "Grafo.h"


class Grafo_lista final : public Grafo {
    List<Edge *> *ARESTAS;

    vector<int> getVizinhos(int no) override ;
    int getAresta(int origem, int destino) override;

public:
    Grafo_lista();

    ~Grafo_lista() override;

    void addAresta(Node *origem, Node *destino, int peso) override;

    void removeAresta(Node *origem, Node *destino) const;

    void restaurarAresta(Node *origem, Node *destino, int peso);

    void removeVertice(int no) override;

    void salvaGrafos() override;
};


#endif //GRAFO_LISTA_H
