#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include "src/structures/graph/Grafo.cpp"

using namespace std;

string input;
string out;
string diretorio;
ifstream entrada;
ofstream saida;

string *getCurrentDirName();

bool ehCmakeDir(const string *path);

void abreInput();

void abreOutput();

int main(const int argc, const char *argv[]) {
    cout << "Trabalho de Grafos" << endl;
    cout << "Alunos: João Victor Pereira dos Anjos" << endl;
    cout << "Alvaro Davi" << endl;

    cout << "Argumentos Necesarios: " << endl;
    cout << "Ler o Readme.md para mais informações" << endl;

    cout << "Argumentos: " << argc << endl;
    for (int i = 0; i < argc; i++) {
        cout << "Argumento " << i << ": " << argv[i] << endl;
    }

    if (argc < 4 || argc > 5) {
        cout << "argumentos invalidos" << endl;
    }


    if (argc == 4) {
        const auto grafo = Grafo::carregar_grafo(&entrada, &saida, argv[2][1]);
        grafo->eh_arvore();
    } else if (argc == 5) {
    } else {
        cout << "argumentos invalidos" << endl;
    }


    return 0;
}

string *getCurrentDirName() {
    char buffer[PATH_MAX];
    getcwd(buffer, PATH_MAX);
    return new string(buffer);
}

void abreInput() {
    const auto path = getCurrentDirName();

    if (ehCmakeDir(path)) {
        path->erase(path->find("cmake-build-debug"), path->length());
    }

    path->append("/").append(diretorio).append("/").append(input);
    entrada.open(*path, ios::in);

    delete path;
}

void abreOutput() {
    const auto path = getCurrentDirName();

    if (ehCmakeDir(path)) {
        path->erase(path->find("cmake-build-debug"), path->length());
    }

    path->append("/output/").append(out);
    saida.open(*path, ios::out | ios::trunc);

    delete path;
}

bool ehCmakeDir(const string *path) {
    return path->find("cmake-build-debug") != string::npos ||
           path->find("cmake-build-release") != string::npos;
}
