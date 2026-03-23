//Escreva um algoritmo que leia um vetor com 15 posições de  números inteiros.
//Em seguida, escreva somente os números  positivos que se encontram no vetor.

#include <iostream>
using namespace std;



int main(){
    //Declaração de vetor com 15 espaços
    int tamanhoVetor = 15;
    int vetor[tamanhoVetor];
    int i;

    for(i = 0; i < tamanhoVetor; i++){
        //Lendo os 15 numeros inteiros
        cout << "Digite um numero inteiro: ";
        cin >> vetor[i];
    }

    cout << "Elementos positivos do vetor: ";

    for (int i = 0; i < tamanhoVetor; i++) {
        if (vetor[i] > 0) {
            cout << vetor[i] << " ";
        }
    }

    return 0;
}