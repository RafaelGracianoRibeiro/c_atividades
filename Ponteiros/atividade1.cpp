//Escreva uma função que imprime os elementos de um vetor de float a partir de um endereço inicial (ponteiro) até um endereço final;
//A função recebe como parâmetros dois ponteiros para float (os endereços inicial e final) e deve utilizar notação de ponteiros não de vetores;
//Deve ser criada uma função main() para testar a função implementada com três vetores de tamanhos e conteúdos diferentes;
//A função main deve imprimir duas partes distintas de cada um dos três vetores, utilizando a função criada.

#include <iostream>
#include <iterator> // Necessário para std::size
using namespace std;

// A função foi movida para antes da main() para que o compilador a conheça quando for chamada.
void imprimeVetor(float* inicial, float* final) {
    cout << "Tamanho: " << (final - inicial) << endl;
    while (inicial < final) {
        cout << inicial << " -> ";
        cout << *inicial << endl;
        inicial++;
    }
    cout << endl;
}

int main() {
    float vetor1[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    float vetor2[] = {9.8, 8.7, 7.6, 6.5, 5.4, 4.3, 3.2, 2.1};
    float vetor3[] = {10.0, 20.0, 30.0};

    imprimeVetor(vetor1, vetor1 + size(vetor1));
    imprimeVetor(vetor2, vetor2 + size(vetor2));
    imprimeVetor(vetor3, vetor3 + size(vetor3));
}
