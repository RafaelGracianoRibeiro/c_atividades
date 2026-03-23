//Escreva um algoritmo que leia um vetor com 8 posições de  números inteiros.
//Em seguida, leia um novo valor do usuário e  verifique se  valor se encontra no vetor.
//Se estiver, informe a  posição desse elemento no vetor.
//Caso o elemento não esteja no  vetor, apresente uma mensagem informando “O número não se  encontra no vetor”

#include <iostream>
using namespace std;

int main() {
    int vetorTamanho = 8;
    int vetor[vetorTamanho];
    int valorProcurado;
    bool encontrado = false;

    for (int i = 0; i < vetorTamanho; i++) {
        cout << "Digite um numero inteiro para ser anexado ao vetor: ";
        cin >> vetor[i];
    }

    cout << "Digite o valor que deseja verificar: ";
    cin >> valorProcurado;

    for (int i = 0; i < vetorTamanho; i++) {
        if (valorProcurado == vetor[i]) {
            cout << "O valor " << valorProcurado << " foi encontrado no indice " << i << endl;
            encontrado = true;
        }
    }

    if (encontrado == false) {
        cout << "O valor nao foi encontrado";
    }

}

