#ifndef EDGE_H
#define EDGE_H


class Node;

class Edge {
public:

    Edge(const int ID, const int PESO, Node *Origem, Node *Destino){
        this->ID = ID;
        this->PESO = PESO;
        this->Origem = Origem;
        this->Destino = Destino;
    }
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
