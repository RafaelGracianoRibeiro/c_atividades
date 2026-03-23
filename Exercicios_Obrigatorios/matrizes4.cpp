//Dada uma matriz 5x5 imprima:
//A diagonal principal
//A diagonal secundária
//A soma da linha 4
//A soma da coluna 2
//Tudo exceto a diagonal principal

#include <iostream>
using namespace std;
#include <random>

int main() {
    //Definição para gerar números aleatórios
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<>distribution(1,100);

    int matriz[5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matriz[i][j] = distribution(gen);
        }
    }

    cout << "Matriz gerada: " << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matriz[i][j] << "\t";
        }cout << endl;
    }

    //Imprimindo a diagonal principal
    cout << "Diagonal principal: ";
    for (int i = 0; i < 5; i++) {
        cout << matriz[i][i] << " ";
    }
    cout << endl;

    //Imprimindo a diagonal secundária
    cout << "Diagonal secundaria: ";
    for (int i = 0; i < 5; i++) {
        cout << matriz[i][4 - i] << " ";
    }
    cout << endl;

    //Imprimindo soma da linha 4
    int soma = 0;
    for (int i = 0; i<5; i++) {
        soma += matriz[4][i];
    }cout << "Soma da quarta linha: " << soma << endl;

    //Imprimindo tudo exceto a diagonal principal
    cout << "Tudo exceto a diagonal principal:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i != j) {//Verificando se os indicies do elemento são diferentes
                cout << matriz[i][j] << "\t";
            } else {//Caso sejam iguais adicionar espaço vazio na tabela
                cout << "\t";
            }
        }
        cout << endl;
    }





}