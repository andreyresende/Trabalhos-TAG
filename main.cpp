#include <iostream>

using namespace std;

void leArquivo() {
    FILE *dolphins;
    int n1, n2;

    char file[] = "dolphins.txt";
    dolphins = fopen(file, "r");

    if (dolphins == NULL) {
        cout << "Erro ao abrir Arquivo" << endl;
    }
    while (fscanf(dolphins, "%d %d", &n1, &n2) != EOF) {
        cout << n1 << " " << n2 << endl;
        //cin >> n1;
    }
}

int main() {
        leArquivo();
        cout << "Hello, World!" << endl;
    return 0;
}