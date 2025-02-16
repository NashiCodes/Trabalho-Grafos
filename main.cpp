#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include <climits>

// ReSharper disable once CppUnusedIncludeDirective
#include "src/structures/graph/Grafo.cpp"
#include "src/structures/graph/Grafo_lista.cpp"
#include "src/structures/graph/Grafo_matriz.cpp"


using namespace std;

string input;
string out;
string diretorio;
ifstream entrada;
ofstream saida;

string *getCurrentDirName();

void abreAquivos();

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
        return 1;
    }

    const auto grafo = argv[2][1] == 'm'
                           ? static_cast<Grafo *>(new Grafo_matriz())
                           : static_cast<Grafo *>(new Grafo_lista());

    input = argv[3];
    if (argc == 4) {
        out = "descricao.txt";

        abreAquivos();

        grafo->carregar_grafo(&entrada, &saida);
        grafo->salvaDescricao();
    } else if (argc == 5) {
        out = argv[4];

        abreAquivos();

        grafo->novo_grafo(&entrada, &saida);
        grafo->salvaGrafos();
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

void abreAquivos() {
    const auto path = getCurrentDirName();

    path->append("/input/").append(input);
    entrada.open(*path, ios::in);

    path->erase(path->find("input"), path->length());
    path->append("output/").append(out);
    saida.open(*path, ios::out | ios::trunc);

    delete path;

    if (!entrada.is_open() || !saida.is_open()) {
        cout << "Erro ao abrir os arquivos!" << endl;
        exit(1);
    }

    cout << "arquivos aberto" << endl;
}
