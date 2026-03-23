//Crie um algoritmo que leia uma matriz  5x5.
//Em seguida,  conte quantos números pares existem na matriz.

#include <iostream>
using namespace std;

int main() {
    int matriz[5][2];
    int soma = 0;


    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++){
            cout << "Digite o valor da posicao [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            soma += matriz[i][j];
        }

    }

    cout << "A media dos elementos na matriz e: " << soma / 10 << endl;
}