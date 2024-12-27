#ifndef NO_H
#define NO_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include <set>

using namespace std;

class Node {
public:
    Node(int ID, int PESO);

private:
    int ID;
    int PESO;
    int GRAU_ENTRADA;
    int GRAU_SAIDA;
    bool PASSOU;
};


#endif //NO_H
