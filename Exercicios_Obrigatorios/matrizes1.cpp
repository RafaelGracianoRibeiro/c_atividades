//Algoritimo que apresenta a soma de duas matrizes 3x5
#include <iostream>
#include <random>
using namespace std;

int main() {
    //Definição para gerar números aleatórios
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<>distribution(1,100);

    int matriz[3][5];
    int matriz2[3][5];
    int matriz3[3][5];


    // Preenchendo a primeira matriz com números aleatórios
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            matriz[i][j] = distribution(gen);
        }
    }

    // Preenchendo a segunda matriz com números aleatórios
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            matriz2[i][j] = distribution(gen);
        }
    }

    //Exibindo o valor da matriz 1
    cout << "Matriz 1:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;

    //Exibindo o valor da matriz 2
    cout << "Matriz 2:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matriz2[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;

    //Somando os valores das matrizes e adicionando à uma terceira
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            matriz3[i][j] = matriz[i][j] + matriz2[i][j];
        }
    }

    //Exibindo a matriz das somas
    cout << "Matriz 3:" << endl;
    for (int i=0;i<3;i++) {
        for (int j=0;j<5;j++) {
            cout << matriz3[i][j] << "\t";
        }
        cout << endl;
    }



}