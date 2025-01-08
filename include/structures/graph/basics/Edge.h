#ifndef EDGE_H
#define EDGE_H


class Node;

class Edge {
public:

    Edge(Node *Origem, Node *Destino, const int PESO) : PESO(PESO), Origem(Origem), Destino(Destino) {}
    [[nodiscard]] int getPeso() const { return PESO; }
    [[nodiscard]] Node *getOrigem() const { return Origem; }
    [[nodiscard]] Node *getDestino() const { return Destino; }
private:
    int PESO;
    Node *Origem;
    Node *Destino;
};



#endif //EDGE_H
