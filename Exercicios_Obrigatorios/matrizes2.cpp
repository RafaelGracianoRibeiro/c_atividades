//Faça um programa que multiplique uma matriz 3x3 por uma escala k
#include <iostream>
using namespace std;
#include <random>

int main() {
    //Definição para gerar números aleatórios
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<>distribution(1,100);

    int matriz[3][3];
    int multiplicador;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matriz[i][j] = distribution(gen);
        }
    }
    cout << "Matriz 3x3:" << endl;
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }cout << endl;

    cout << "Digite uma escala para multiplicar a matriz: ";
    cin >> multiplicador;
    cout << endl;

    cout << "Matriz 3x3 multiplicada por " << multiplicador << ":"<<endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matriz[i][j] *= multiplicador;
            cout << matriz[i][j] << "\t";
        }cout << endl;
    }
}