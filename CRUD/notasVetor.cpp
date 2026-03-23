//Crie um programa que utilize um vetor para armazenar as notas de 10 alunos.
#include <iostream>
using namespace std;

int main () {
    const int MAX_NOTAS = 10;
    float notas[MAX_NOTAS];
    int num_notas = 0;
    int consulta;
    int op;

    while (op != 6) {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Inserir notas" << endl;
        cout << "2. Exibir notas" << endl;
        cout << "3. Pesquisar notas" << endl;
        cout << "4. Alterar notas" << endl;
        cout << "5. Excluir notas" << endl;
        cout << "6. Sair" << endl;
        cout << "Digite sua opcao: ";
        cin >> op;

        switch (op) {
            case 1: { // Inserir notas
                for (int i=0;i<10;i++) {
                    cout << "Digite a nota " << i + 1 << ": ";
                    cin >> notas[i];
                    num_notas++;
                }
                break;
            }
            case 2: {
                if (num_notas > 0) {
                    cout << "Notas cadastradas:" << endl;
                    for (int i = 0; i < MAX_NOTAS; i++) {
                        cout << "Nota_" << i + 1 << ": " << notas[i] << endl;
                    }
                }else(cout << "Nenhuma nota cadastrada");
                break;
            }
            case 3: {
                if (num_notas > 0) {
                    cout << "Digite qual o numero de 1 a 10 da nota que deseja consultar: ";
                    cin >> consulta;
                    if (consulta > 10 or consulta < 1) {
                        cout << "Posiçao de nota ixistente";
                    }else{cout << "Nota " << consulta << ": " << notas[consulta - 1];}
                }else{cout << "Nao ha notas cadastradas";}
                break;
            }
            case 4: {
                if (num_notas > 0) {
                    cout << "Digite qual o numero de 1 a 10 da nota que deseja alterar: ";
                    cin >> consulta;
                    if (consulta > 10 or consulta < 1) {
                        cout << "Posicao de nota ixistente";
                    }else {
                        cout << "Alterando a nota " << consulta << endl;
                        cout << "Digite a nova nota: ";
                        cin >> notas[consulta - 1];
                    };
                }else{cout << "Nao ha notas cadastradas";}

                break;
            }

            case 5: {
                if (num_notas > 0) {
                    cout << "Digite qual o numero de 1 a 10 da nota que deseja excluir: ";
                    cin >> consulta;
                    notas[consulta - 1] = 0;
                }else{cout << "Nao ha notas cadastradas";}
                break;
            }

            case 6: {
                cout << "Saindo do programa..." << endl;
                break;
            }


            default:
                cout << "Opcao invalida!" << endl;
                break;
        }
    };
}