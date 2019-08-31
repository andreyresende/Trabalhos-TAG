#include <iostream>
#include <list>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <string>
#include <cstdlib>

using namespace std;

class Grafo {
    private: 
        int quantidade_vertices;
        list<int> *vizinhos;//Aponta para o vetor de listas
    public: 
    Grafo(int quantidade_vertices);
    void adicionar_relacao(int golfinho1, int golfinho2);
    void mostrar_graus();
    void mostrar_maximais();
    void mostrar_coeficiente();
    void coeficiente_medio();
};

Grafo::Grafo(int quantidade_vertices){//Construtor que inicializa o grafo com a quantidade de vertices e cria o array de listas para os golfinhos
    this->quantidade_vertices = quantidade_vertices;
    vizinhos                  = new list<int>[quantidade_vertices+1];
}

void Grafo::adicionar_relacao(int golfinho1, int golfinho2){
    vizinhos[golfinho1].push_back(golfinho2);
    vizinhos[golfinho2].push_back(golfinho1);
}

void Grafo::mostrar_graus(){
    int i=1;
    while(i <= 62){
        cout <<"O golfinho nº " << i << " possui " << vizinhos[i].size() << " amigo(s)" << endl;
        i++;
    }
    cout << "Teste " << vizinhos[1].() << endl;
}

void Grafo::mostrar_maximais(){//Implementado utilizando o algoritmo de Bron-Kerbosch
    list<int> R, P, X;
    int iterator;
    for(int i=1; i<=62; i++){
        P.push_back(i);
    }
    if(P.empty() && X.empty(){
        cout << "Clique de tamanho " << R.size() << "  - Vertices: ";
        iterator = R.begin();
        while(iterator != NULL){
            cout << iterator << " ";
            iterator++;
        }
        cout << endl;
    }
}

void ler_arquivo(Grafo &grafo){
    FILE *arquivo;
    arquivo = fopen("dolphins.txt","r");
    if(arquivo != NULL){
        int golfinho1, golfinho2;
        while(fscanf(arquivo,"%d" "%d", &golfinho1, &golfinho2) != EOF){
            grafo.adicionar_relacao(golfinho1, golfinho2);
        }
        fclose(arquivo);    
    }
}

int main()
{
    Grafo grafo(62);
    ler_arquivo(grafo);
    grafo.mostrar_graus();
    return 0;
}