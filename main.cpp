#include <iostream>
#include <list> 
#include <iterator>
#include "dolphin.h"

using namespace std;
//  Essa funcao adiciona a indexacao base na lista total
/*void verificaMinMax() {
    FILE *dolphins;
    int refId, id
    int minId = 999, maxId = 0;
    int minRefId = 999, maxRefId = 0;
    Dolphin dolphin, refDolphin;

    Graph Grafo;
    //list <Dolphin> listaTotal;

    char file[] = "dolphins.txt";
    dolphins = fopen(file, "r");

    if (dolphins == NULL) {
        cout << "Erro ao abrir Arquivo" << endl;
    }
    while (fscanf(dolphins, "%d %d", &id, &refId) != EOF) {
        //Seta o Id de cada elemento do Grafo
        if (id < minId){
            minId = id;
        }
        if (refId < minRefId){
            minRefId = refId;
        }
    }
    if (minId > minRefId)
        minId = minRefId;
    cout << minId << endl;
    fclose(dolphins);

}*/

void verificaMinMax() {
    FILE *dolphins;
    int refId, id;
    int minId = 999, maxId = 0;
    int minRefId = 999, maxRefId = 0;
    Dolphin dolphin, refDolphin;

    Graph Grafo;
    //list <Dolphin> listaTotal;

    char file[] = "dolphins.txt";
    dolphins = fopen(file, "r");

    if (dolphins == NULL) {
        cout << "Erro ao abrir Arquivo" << endl;
    }
    while (fscanf(dolphins, "%d %d", &id, &refId) != EOF) {
        //Seta o Id de cada elemento do Grafo
        dolphin.setId(id);        
        refDolphin.setId(refId);

        if (Grafo.listaTotal.size() == 0) {
            Grafo.listaTotal.push_back(dolphin);
            //listaTotal.push_back(dolphin);
            dolphin.setConnection(refDolphin);
            cout << dolphin.getId() << " " << refDolphin.getId() << endl;
        }
        else {
            for (auto & i : Grafo.listaTotal ) {
                    //cout << i.getId() << endl;
                    if (id == i.getId()){
                        dolphin.setConnection(refDolphin);
                        cout << i.getId() << " " << refDolphin.getId() << endl;
                    }
            }
        }
    }
    
    fclose(dolphins);

}

/*void leArquivo() {
    FILE *dolphins;
    int refId, id;
    Dolphin dolphin, refDolphin;

    list <Dolphin> listaTotal;

    char file[] = "dolphins.txt";
    dolphins = fopen(file, "r");

    if (dolphins == NULL) {
        cout << "Erro ao abrir Arquivo" << endl;
    }
    while (fscanf(dolphins, "%d %d", &id, &refId) != EOF) {
        //Seta o Id de cada elemento do Grafo
        dolphin.setId(id);

        //Manda o elemento do Grafo pra Lista
        listaTotal.push_back(dolphin);
        
        refDolphin.setId(refId);

        dolphin.setConnection(refDolphin);

        cout << dolphin.getId() << " " << refDolphin.getId() << endl;
    }
    fclose(dolphins);

}*/

int main() {
        //leArquivo();
        verificaMinMax();
        cout << "Hello, World!" << endl;
    return 0;
}