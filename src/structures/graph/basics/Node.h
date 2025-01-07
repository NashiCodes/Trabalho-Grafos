#ifndef NO_H
#define NO_H

#include <iostream>

using namespace std;

class Node {
public:
    Node(int ID, int PESO);
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
