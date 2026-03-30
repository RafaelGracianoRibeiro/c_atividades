//Escreva uma função que encontra um valor em um vetor de inteiros e retorna um ponteiro para o primeiro endereço onde este valor foi encontrado ou NULL caso o valor não esteja no vetor;
//A função recebe como parâmetro dois ponteiros para inteiros (os endereços inicial e final) e deve utilizar notação de ponteiros não de vetores;
//Deve ser criada uma função main() para testar a função implementada. Na função main deve ser declarado um vetor de tamanho 10, com três ocorrências do valor 2;
//A main() deve utilizar a função criada para encontrar e imprimir os endereços de memória de todas as ocorrências do valor 2, em um laço, até que o vetor tenha sido pesquisado.
//Defina a constante NULL se necessário.

#include <iostream>
using namespace std;

void procuraNumero(int* inicial, int* final, int numero) {
    bool achado = false;
    for (int* ip = inicial; ip < final; ip++) {
        if (*ip == numero) {
            cout << "Valor " << numero << " encontrado no endereco " << ip << endl;
            achado = true;
        }
    }if (achado == false) {cout << "Valor " << numero << " nao encontrado" << endl;}
}

int main() {

    int vtr[] = {1,2,3,4,5,6,2,8,9,2};
    procuraNumero(vtr, vtr + 10, 2);

}