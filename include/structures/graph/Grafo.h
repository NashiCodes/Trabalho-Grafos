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

    virtual bool eh_bipartido();

    virtual int n_conexo();

    [[nodiscard]] int get_ordem() const;

    [[nodiscard]] int get_grau() const;

    [[nodiscard]] bool eh_direcionado() const;

    [[nodiscard]] bool vertice_ponderado() const;

    [[nodiscard]] bool aresta_ponderada() const;

    virtual bool eh_completo();

    virtual bool eh_arvore();

    virtual bool possui_articulacao();

    virtual bool possui_ponte();

    void carregar_grafo(ifstream *entrada, ofstream *saida);

    void novo_grafo(ifstream *entrada, ofstream *saida);

    void set_aresta_ponderada(bool aresta_ponderada);

    void set_vertice_ponderado(bool vertice_ponderado);

    virtual void set_direcionado(bool direcionado);

    virtual void addAresta(Node *origem, Node *destino, int peso) {};

protected:
    ifstream *Input;
    ofstream *Output;
    List<Node *> *NOS;
    int Grau = -1;
    int componentesConexas = -1;
    int arestaPonte = -1;
    int verticeArticulacao = -1;
    int Ordem = -1;
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
