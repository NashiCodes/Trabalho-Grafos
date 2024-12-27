//
// Created by Nashi on 27/12/2024.
//

#include "Node.h"

using namespace std;

Node::Node(const int ID, const int PESO) {
    this->ID = ID;
    this->PESO = PESO;
    this->GRAU_ENTRADA = 0;
    this->GRAU_SAIDA = 0;
    this->PASSOU = false;
}