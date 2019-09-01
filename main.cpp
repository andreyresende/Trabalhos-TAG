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
    void mostrar_maximais(list<int> R, list<int> P, list<int> X);
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
    int *ptr;
    while(i <= 62){
        cout <<"O golfinho nº " << i << " possui " << vizinhos[i].size() << " amigo(s)" << endl;
        i++;
    }
}

void Grafo::mostrar_maximais(list<int> R, list<int> P, list<int> X){//Implementado utilizando o algoritmo de Bron-Kerbosch
    _List_const_iterator <int> ponteiro;
    if(P.size() == 0){
        if(X.size() == 0){
            cout << "Clique de tamanho " << R.size() << endl;
            ponteiro = R.begin();
            cout << "Vertices: ";
            for(int i = 0; i < R.size(); i++){
                cout << *ponteiro << ", ";
            }
            cout << endl;
        }
        return;
    }
    for(int i = 0; i < P.size(); i++){
        mostrar_maximais(R, P, X);
    }
}

void Grafo::mostrar_coeficiente(){
    int i = 1, qtd_amigos, busca, aux;
    float coeficiente_grafo, soma_coeficientes = 0, coeficiente_maximo, coeficiente_real = 0;
    _List_const_iterator <int> ponteiro, auxiliar;
    while(i<=62){
        ponteiro           = vizinhos[i].begin();
        auxiliar           = ponteiro;
        qtd_amigos         = vizinhos[i].size();//Quantos vizinhos cada golfinho tem
        coeficiente_maximo = (qtd_amigos*(qtd_amigos-1))/2;
        aux = qtd_amigos;
        for(int j = 0; j < qtd_amigos; j++){
            for(int k = 0; k < aux-1; k++){
                auxiliar++;
                //cout << "Ponteiro = " << *ponteiro << endl;
                //cout << "Testando se tem " << *auxiliar << " no ponteiro" << endl;
                if(find(vizinhos[*ponteiro].begin(), vizinhos[*ponteiro].end(),*auxiliar) != vizinhos[*ponteiro].end()){
                    coeficiente_real++;
                    //cout << "Coeficiente real aumentado, agora está em " << coeficiente_real << endl;
                }
            }
            aux--;
            ponteiro++;
            auxiliar = ponteiro;
        }
        cout << "Coeficiente de aglomeracao do golfinho " << i << " = " << coeficiente_real << "/" << coeficiente_maximo << endl;
        if(coeficiente_maximo != 0)
            soma_coeficientes       += coeficiente_real/coeficiente_maximo;
        coeficiente_real = 0;
        i++; 
    }
    coeficiente_grafo = soma_coeficientes/62;
    cout << "Coeficiente medio do grafo = " << coeficiente_grafo << endl; 
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

int main(){
    list<int> R, P, X;
    for(int i = 1; i <= 62; i++){
        P.push_back(i);
    }
    Grafo grafo(62);
    ler_arquivo(grafo);
    grafo.mostrar_graus();
    grafo.mostrar_coeficiente();
    return 0;
}