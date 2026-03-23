//Agora vamos simular um pequeno sistema de estoque utilizando vetores.
#include <iostream>
#include <random>
using namespace std;



int main () {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float>price_distribution(1.0,100.0);
    std::uniform_int_distribution<>distribution(1,100);

    const int MAX_PRODUTOS = 10;
    int codigo[MAX_PRODUTOS];
    float preco[MAX_PRODUTOS];
    int quantidade[MAX_PRODUTOS];
    int consulta;
    bool cadastro = false;
    int op;

    while (op != 6) {
        cout << "\n--- MENU ---" << endl;
        cout << "1 - Cadastrar Produtos" << endl;
        cout << "2 - Consultar Produto" << endl;
        cout << "3 - Alterar preco do Produto" << endl;
        cout << "4 - Excluir Produto" << endl;
        cout << "5 - Listar Produtos" << endl;
        cout << "0 - Sair" << endl;
        cout << "Digite a opcao desejada: ";
        cin >> op;
        cout << endl;


        switch (op) {
            case 1: {
                for (int i=0;i<MAX_PRODUTOS;i++) {
                    codigo[i] = distribution(gen);
                    preco[i] = price_distribution(gen);
                    quantidade[i] = distribution(gen);
                }
                cadastro = true;
                cout << "CADASTRO CONLUIDO" << endl;
                break;
            }
            case 2: {
                    if (cadastro == true) {
                        cout << "Digite o codigo do produto a consultar: ";
                        cin >> consulta;
                        for (int i=0;i<MAX_PRODUTOS;i++) {
                            if (codigo[i] == consulta) {
                                cout << "Codigo: " << codigo[i] << endl;
                                cout << "Preco: " << preco[i] << endl;
                                cout << "Quantidade: " << quantidade[i] << endl;
                            }
                        }
                    }else{cout << "Necessario fazer cadastro";}
                break;
            }

            case 3: {
                if (cadastro == true) {
                    cout << "Digite o código do produto para mudar o preço: ";
                    cin >> consulta;
                    for (int i=0;i<MAX_PRODUTOS;i++) {
                        if (codigo[i] == consulta) {
                            cout << "Digite o novo preço: ";
                            cin >> preco[i];
                        }
                    }
                }else{cout << "Necessario fazer cadastro";}
            }

            case 4: {
                if (cadastro == true) {
                    cout << "Digite o código do produto para excluir: ";
                    cin >> consulta;
                    for (int i=0;i<MAX_PRODUTOS;i++) {
                        if (codigo[i] == consulta) {
                            codigo[i] = 0;
                            preco[i] = 0;
                            quantidade[i] = 0;
                        }
                    }
                }else{cout << "Necessario fazer cadastro";}
            }

            case 5: {
                if (cadastro == true) {
                    for (int i=0;i<MAX_PRODUTOS;i++) {
                        cout << "Codigo: " << codigo[i] << " | ";
                        cout << "Preco: " << preco[i] << " | ";
                        cout << "Quantidade: " << quantidade[i] <<" | "<< endl;
                    }
                }else{cout << "Necessario fazer cadastro";}
                break;
            }

            case 0: {
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