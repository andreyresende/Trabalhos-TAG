#include <iostream>
#include <list> 
#include <iterator>
#include "dolphin.h"

using namespace std;

void leArquivo() {
    FILE *dolphins;
    int refId, id;
    int minId = 999, maxId = 0;
    int minRefId = 999, maxRefId = 0;

    bool naoEncontrado = false;

    Graph Grafo;
    //list <Dolphin> listaTotal;

    char file[] = "dolphins.txt";
    dolphins = fopen(file, "r");

    if (dolphins == NULL) {
        cout << "Erro ao abrir Arquivo" << endl;
    }
    while (fscanf(dolphins, "%d %d", &id, &refId) != EOF) {
        //Seta o Id de cada elemento do Grafo
        Dolphin dolphin, refDolphin;

        naoEncontrado = false;
        dolphin.setId(id);        
        refDolphin.setId(refId);
        
        if (Grafo.listaTotal.size() == 0) {
            //listaTotal.push_back(dolphin);
            dolphin.setConnection(refDolphin);
            Grafo.listaTotal.push_back(dolphin);
            //cout << "ELEMENTO ZERO: " << endl;
            //cout << dolphin.getId() << " " << refDolphin.getId() << endl;
        }
        else {
            for (auto & i : Grafo.listaTotal ) {
                //cout << i.getId() << endl;
                if (id == i.getId()){
                    i.setConnection(refDolphin);
                    //cout << "ELEMENTO JA EXISTE: " << endl;
                    //cout << i.getId() << " " << refDolphin.getId() << endl;
                    naoEncontrado = true;
                }
                
            }
            if (!naoEncontrado) {
                //cout << "ELEMENTO NAO EXISTE: " << endl;
                //listaTotal.push_back(dolphin);
                dolphin.setConnection(refDolphin);
                Grafo.listaTotal.push_back(dolphin);
            }
                //cout << dolphin.getId() << " " << refDolphin.getId() << endl;

        }
    }
    
    fclose(dolphins);
    int total = 0;
    for (auto & i : Grafo.listaTotal ) {
        cout << "Base: "<< i.getId() << " " << endl;
        cout << "Tamanho de conexoes: " << i.conexoes.size() << endl;
        for (auto & j : i.conexoes )
            cout << j.getId() << " ";
        cout << endl << endl;
        total += i.conexoes.size();
    }
    cout << "TOTAL DE ELEMENTOS: " << Grafo.listaTotal.size() << endl;
    cout << "TOTAL DE CONEXOES: "<< total << endl;

}

int main() {
        leArquivo();
        //verificaMinMax();
        //cout << "Hello, World!" << endl;
    return 0;
}