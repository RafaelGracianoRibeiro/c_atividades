//Escreva um algoritmo que leia dois vetores de 10 posições e faça  a soma dos elementos de mesmo índice,colocando o resultado em  um terceiro vetor.
//Mostre o vetor resultante.

#include <iostream>
using namespace std;
int main () {
    int tamanho = 10;
    int vetor[tamanho];
    int vetor2[tamanho];
    int vetor3[tamanho];

    for (int i = 0; i < tamanho; i++) {
        cout << "Digite um numero inteiro para ser atribuido ao primeiro vetor:  ";
        cin >> vetor[i];
    }

    for (int i = 0; i < tamanho; i++) {
        cout << "Digite um numero inteiro para ser atribuido ao segundo vetor:  ";
        cin >> vetor2[i];
    }

    for (int i = 0; i < tamanho; i++) {
        vetor3[i] = vetor[i] + vetor2[i];
        cout << vetor3[i] << "\t";
    }

}