#include <iostream>

#include "src/structures/graph/Grafo.h"

using namespace std;

int main(int argc, const char *argv[]) {
    cout << "Trabalho de Grafos" << endl;
    cout << "Alunos: João Victor Pereira dos Anjos" << endl;
    cout << "Alvaro Davi" << endl;

    cout << "Argumentos Necesarios: " << endl;
    cout << "Ler o Readme.md para mais informações" << endl;

    cout << "Argumentos: " << argc << endl;
    for (int i = 0; i < argc; i++) {
        cout << "Argumento " << i << ": " << argv[i] << endl;
    }

    auto *grafo = Grafo::novo_grafo(argv[2][1]);

    if (argc == 4) {
    } else if (argc == 5) {
    } else {
        cout << "argumentos invalidos" << endl;
    }


    return 0;
}
