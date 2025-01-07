#ifndef EDGE_H
#define EDGE_H
#include "Node.h"


class Edge {
public:
    Edge(int ID, int PESO, Node *Origem, Node *Destino);
    [[nodiscard]] int getId() const { return ID; }
    [[nodiscard]] int getPeso() const { return PESO; }
    [[nodiscard]] Node *getOrigem() const { return Origem; }
    [[nodiscard]] Node *getDestino() const { return Destino; }
private:
    int ID;
    int PESO;
    Node *Origem;
    Node *Destino;

};



#endif //EDGE_H
