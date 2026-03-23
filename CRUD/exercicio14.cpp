//Crud com matrizes
//Criando um sistema CRUD de produtos com uma matriz [10][3]
//Usando a estrutura de código preço e quantidade
#include <iostream>
using namespace std;


int main() {
    int produtos[10][3];
    int consulta;
    int op;

    while (op != 5) {
        cout << "\n--- MENU ---" << endl;
        cout << "1 - Cadastrar Produtos" << endl;
        cout << "2 - Consultar Produto" << endl;
        cout << "3 - Alterar preco do Produto" << endl;
        cout << "4 - Excluir Produto" << endl;
        cout << "5 - Sair" << endl;
        cout << "Digite a opcao desejada: ";
        cin >> op;
        cout << endl;

        switch (op) {
            case 1: {
                for (int i=0; i<10;i++) {
                    cout << "Digite o codigo do produto: ";
                    cin >> produtos[i][0];
                    cout << "Digite o preco do produto: ";
                    cin >> produtos[i][1];
                    cout << "Digite a quantidade do produto: ";
                    cin >> produtos[i][2];
                }
                break;
            }
            case 2: {
                cout << "Digite o codigo do produto a consultar: ";
                cin >> consulta;
                for (int i=0; i<10; i++) {
                    if (produtos[i][0] == consulta) {
                        cout << "Preço: " << produtos[i][1];
                        cout << "Quatidade: " << produtos[i][2];
                    }
                }
                break;
            }
            case 3: {
                cout << "Digite o codigo do produto a alterar o preco: ";
                cin >> consulta;
                for (int i=0; i<10; i++) {
                    if (produtos[i][0] == consulta) {
                        cout << "Digite o novo preco do produto: ";
                        cin >> produtos[i][1];
                    }
                }
                break;
            }
            case 4: {
                cout << "Digite o codigo do produto a excluir: ";
                cin >> consulta;
                for (int i=0; i<10; i++) {
                    if (produtos[i][0] == consulta) {
                        produtos[i][0] = 0;
                        produtos[i][1] = 0;
                        produtos[i][2] = 0;
                    }
                }
                break;
            }
            case 5: {
                cout << "Saindo do programa..." << endl;
                break;
            }
            default: {
                cout << "Opcao invalida!" << endl;
                break;
            }
        }
    }
}
