#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>

#include "../storage/list/List.h"
#include "basics/Node.h"

using namespace std;


class Grafo {
public:
    static int RandomNumber(int floor, int ceil);

    Grafo();

    virtual ~Grafo();

    vector<int>* fechoTransitivoDireto(int no);

    void auxFechoTransitivoDireto(int no, vector<int> *visitados);

    [[nodiscard]] bool eh_bipartido();

    bool auxBipartido(int no, int cor, vector<int> *colors);

    [[nodiscard]] int n_conexo();

    [[nodiscard]] int get_ordem() const;

    [[nodiscard]] int get_grau() const;

    [[nodiscard]] bool eh_direcionado() const;

    [[nodiscard]] bool vertice_ponderado() const;

    [[nodiscard]] bool aresta_ponderada() const;

    [[nodiscard]] bool eh_completo();

    [[nodiscard]] bool eh_arvore();
    bool eh_Ciclo(int no, vector<bool>* visitados, int pai);

    [[nodiscard]] bool possui_articulacao();
    void auxArticulacao(vector<bool> *visitados, int pivot, int current);

    [[nodiscard]] bool possui_ponte();
    void auxPonte(int u, vector<bool> &visited, vector<int> &disc, vector<int> &low, int parent, int &time);

    void carregar_grafo(ifstream *entrada, ofstream *saida);

    void novo_grafo(ifstream *entrada, ofstream *saida);

    void set_aresta_ponderada(bool aresta_ponderada);

    void set_vertice_ponderado(bool vertice_ponderado);

    virtual void set_direcionado(bool direcionado);

    virtual void addAresta(Node *origem, Node *destino, int peso);

    void removeAresta(Node *origem, Node *destino);

    void restaurarAresta(Node *origem, Node *destino, int peso);

    void salvaDescricao();

    virtual void salvaGrafos();

    virtual void removeVertice(int no);

    void generateRandomGraph();

    bool existeAresta(Node *nodeA, Node *nodeB);

    bool ehPonte(Node *nodeA, Node *nodeB);

    bool ehArticulacao(Node *nodeA);

    bool verificaConexidade();

    void auxGeraArvore( int no, vector<bool> *visitados, int &auxGrau, vector<int>* vizinhos);

    string getMaiorCaminhoMinimo();

    void floydA0(vector<vector<int>> * dist);

    vector<vector<int>>* Floyd();

private:
    virtual vector<int> getVizinhos(int no) { return {}; }
    virtual int getAresta(int origem, int destino) { return 0; }

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


    bool completoPassado = false;
    bool bipartidoPassado = false;
    bool arvorePassado = false;
};


#endif //GRAFO_H
