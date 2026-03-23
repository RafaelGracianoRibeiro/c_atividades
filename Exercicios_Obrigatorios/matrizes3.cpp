//Leia uma matriz 20x20 e um valor x
//O programa deve fazer uma busca desse valor na matriz informar a localização (linha e coluna)
//Ou uma mensagem de não encontrado.
#include <iostream>
using namespace std;
#include <random>

int main() {
    //Definição para gerar números aleatórios
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<>distribution(1,100);

    int tamanhoMatriz = 10;
    int matriz[tamanhoMatriz][tamanhoMatriz];
    int valorProcurado;
    bool encontrado = false;

    for (int i = 0; i < tamanhoMatriz; i++) {
        for (int j = 0; j < tamanhoMatriz; j++) {
            matriz[i][j] = distribution(gen);
        }
    }

    cout << "Matriz gerada: " << endl;
    for (int i = 0; i < tamanhoMatriz; i++) {
        for (int j = 0; j < tamanhoMatriz; j++) {
            cout << matriz[i][j] << "\t";
        }cout << endl;
    }

    cout << "Digite o valor que deseja verificar: ";
    cin >> valorProcurado;

    for (int i = 0; i <tamanhoMatriz; i++) {
        for (int j = 0; j < tamanhoMatriz; j++) {
            if (matriz[i][j] == valorProcurado) {
                cout << "O valor " << valorProcurado << " foi encontrado no indice [" << i << "][" << j << "]" << endl;
                encontrado = true;
            };
        }
    }

    if (encontrado == false) {
        cout << "O valor nao foi encontrado";
    }

}