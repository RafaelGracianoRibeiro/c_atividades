//Criando uma função para cada exercício de matriz
#include <iostream>
using namespace std;
#include <random>

void matrizes1() {
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

void matrizes2() {
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

void matrizes3() {
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

void matrizes4() {
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

int main() {
    int escolha;
    cout << "Escolha o exercicio de matriz (1 a 4): ";
    cin >> escolha;

    switch (escolha) {
        case 1:
            matrizes1();
            break;
        case 2:
            matrizes2();
            break;
        case 3:
            matrizes3();
            break;
        case 4:
            matrizes4();
            break;
        default:
            cout << "Não há uma função com essa numeração" << endl;
            break;
    }
}