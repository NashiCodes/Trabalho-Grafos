#ifndef NO_H
#define NO_H


#include "Edge.h"

#include <vector>
class Edge;
using namespace std;

class Node {
public:
    Node(const int ID, const int PESO) {
        this->ID = ID;
        this->PESO = PESO;
        this->GRAU_ENTRADA = 0;
        this->GRAU_SAIDA = 0;
        this->PASSOU = false;
        this->Arestas = vector<Edge *>();
    }

    [[nodiscard]] int getId() const { return ID; }
    [[nodiscard]] int getPeso() const { return PESO; }
    [[nodiscard]] int getGrauEntrada() const { return GRAU_ENTRADA; }
    [[nodiscard]] int getGrauSaida() const { return GRAU_SAIDA; }
    [[nodiscard]] bool getPassou() const { return PASSOU; }
    [[nodiscard]] vector<Edge *> getArestas() const { return Arestas; }

    void set_grau_entrada(const int grau_entrada) { GRAU_ENTRADA = grau_entrada; }
    void set_grau_saida(const int grau_saida) { GRAU_SAIDA = grau_saida; }

    void addAresta(Edge *aresta) {
        this->Arestas.push_back(aresta);
        this->GRAU_SAIDA++;
    }

private:
    int ID;
    int PESO;
    int GRAU_ENTRADA;
    int GRAU_SAIDA;
    bool PASSOU;
    vector<Edge *> Arestas;
};


#endif //NO_H
