#include <iostream>
#include <list> 
#include <iterator>
#include "dolphin.h"

using namespace std;

void leArquivo() {
    FILE *dolphins;
    int refId, id;
    Dolphin dolphin, refDolphin;

    list <Dolphin> listaTotal;

    char file[] = "dolphins.txt";
    dolphins = fopen(file, "r");

    if (dolphins == NULL) {
        cout << "Erro ao abrir Arquivo" << endl;
    }
    while (fscanf(dolphins, "%d %d", &refId, &id) != EOF) {
        //Seta o Id de cada elemento do Grafo
        dolphin.setId(id);
        //printa o Id
        cout << dolphin.getId() << endl;
        //Manda o elemento do Grafo pra Lista
        listaTotal.push_back(dolphin);
        
        refDolphin.setId(refId);

        dolphin.setConnection(refDolphin);
    }

}

int main() {
        leArquivo();
        cout << "Hello, World!" << endl;
    return 0;
}