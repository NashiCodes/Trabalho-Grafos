//
// Created by Nashi on 27/12/2024.
//

#include "Edge.h"

Edge::Edge(const int ID, const int PESO, Node *Origem, Node *Destino) {
    this->ID = ID;
    this->PESO = PESO;
    this->Origem = Origem;
    this->Destino = Destino;
}
