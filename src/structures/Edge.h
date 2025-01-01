#ifndef EDGE_H
#define EDGE_H
#include "Node.h"


class Edge {
public:
    Edge(int ID, int PESO, Node *Origem, Node *Destino);
private:
    int ID;
    int PESO;
    Node *Origem;
    Node *Destino;

};



#endif //EDGE_H
