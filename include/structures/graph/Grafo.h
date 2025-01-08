#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>

#include "../storage/list/List.h"
#include "basics/Node.h"

using namespace std;


class Grafo {
public:
    Grafo();

    virtual ~Grafo();

    bool eh_bipartido();
    bool auxBipartido(int no, int cor, vector<int> *colors);

    int n_conexo();

    [[nodiscard]] int get_ordem() const;

    [[nodiscard]] int get_grau() const;

    [[nodiscard]] bool eh_direcionado() const;

    [[nodiscard]] bool vertice_ponderado() const;

    [[nodiscard]] bool aresta_ponderada() const;

    bool eh_completo();

    bool eh_arvore();

    bool possui_articulacao();

    bool possui_ponte();

    void carregar_grafo(ifstream *entrada, ofstream *saida);

    void novo_grafo(ifstream *entrada, ofstream *saida);

    void set_aresta_ponderada(bool aresta_ponderada);

    void set_vertice_ponderado(bool vertice_ponderado);

    virtual void set_direcionado(bool direcionado);

    virtual void addAresta(Node *origem, Node *destino, int peso);
private:

    virtual vector<int> getVizinhos(int no) { return {}; }

protected:
    ifstream *Input;
    ofstream *Output;
    List<Node *> *NOS;
    int Grau = 0;
    int componentesConexas = -1;
    int arestaPonte = -1;
    int verticeArticulacao = -1;
    int Ordem = 0;
    bool ArestaPonderada;
    bool VerticePonderado;
    bool Direcionado;
    bool completo;
    bool bipartido;
    bool arvore;

    bool ArestaPonderadaPassado = false;
    bool VerticePonderadoPassado = false;
    bool DirecionadoPassado = false;
    bool completoPassado = false;
    bool bipartidoPassado = false;
    bool arvorePassado = false;
};



#endif //GRAFO_H
