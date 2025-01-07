#ifndef NO_H
#define NO_H

#include <iostream>

using namespace std;

class Node {
public:
    Node(const int ID, const int PESO){
        this->ID = ID;
        this->PESO = PESO;
        this->GRAU_ENTRADA = 0;
        this->GRAU_SAIDA = 0;
        this->PASSOU = false;
    }
    [[nodiscard]] int getId() const { return ID; }
    [[nodiscard]] int getPeso() const { return PESO; }
    [[nodiscard]] int getGrauEntrada() const { return GRAU_ENTRADA; }
    [[nodiscard]] int getGrauSaida() const { return GRAU_SAIDA; }
    [[nodiscard]] bool getPassou() const { return PASSOU; }

private:
    int ID;
    int PESO;
    int GRAU_ENTRADA;
    int GRAU_SAIDA;
    bool PASSOU;
};


#endif //NO_H
