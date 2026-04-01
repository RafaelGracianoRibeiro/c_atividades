/*Desenvolva um programa em C++ que simule um sistema simples de cadastro
de alunos utilizando vetores e matriz.
O sistema deve permitir as operações de:
• Inserção de dados (Create)
• Consulta de dados (Read)
• Alteração de dados (Update)
• Exclusão de dados (Delete)
Cada aluno deve possuir:
• Nome
• 4 notas
Além disso, o programa deve conter uma função que:
• Recebe as 4 notas de um aluno e uma letra (A ou P)
• Se a letra for A, calcula a média aritmética
• Se a letra for P, calcula a média ponderada, com pesos:
o 2, 3, 4 e 6*/

#include <iostream>
#include <string>

using namespace std;

const int MAX_ALUNOS = 10;
string nomes[MAX_ALUNOS];
float notas[MAX_ALUNOS][4];
int total_alunos = 0;

void cadastrarAluno()
{
    if (total_alunos >= MAX_ALUNOS) {
        cout << "Limite máximo de alunos cadastrados atingido!" << endl;
        return;
    }

    cout << "Digite o nome do aluno: ";
    cin >> nomes[total_alunos];

    for (int i = 0; i < 4; i++) {
        cout << "Digite a nota " << (i + 1) << " do aluno: ";
        cin >> notas[total_alunos][i];
    }

    total_alunos++;
    cout << endl << "Aluno cadastrado com sucesso!" << endl;
}

void listarAlunos()
{
    if (total_alunos < 1)
    {
        cout << "Nenhum aluno cadastrado!" << endl;
    }else
    {
        for (int i = 0; i < total_alunos; i++)
        {
            cout << "Nome: " << nomes[i] << endl;
            for (int j=0; j<4;j++)
            {
                cout << "N" << (j+1) << ": " << notas[i][j] << endl;
            }

        }
    }
}

void alterarAluno()
{
    if (total_alunos < 1)
    {
        cout << "Nenhum aluno cadastrado!" << endl;
    }else
    {
        string nomeBusca;
        cout << "Digite o nome do aluno que deseja alterar as informações: ";
        cin >> nomeBusca;
        int op = -1;

        for (int i=0;i < total_alunos; i++)
        {
            if (nomes[i] == nomeBusca)
            {
                cout << endl << "--Menu de alteração--" << endl;
                cout << "1 - Alterar nome" << endl;
                cout << "2 - Alterar notas" << endl;
                cout << "Escolha uma opcao: ";
                cin >> op;
                switch (op)
                {
                case 1:
                    cout << "Digite o novo nome do aluno: ";
                    cin >> nomes[i];
                    cout << endl << "Nome alterado com sucesso!!!";
                    break;
                case 2:
                    for (int j=0; j<4;j++)
                    {
                        cout << "Digite a nova nota " << (j+1) << " do aluno: ";
                        cin >> notas[i][j];
                    }
                    cout << "Notas alteradas com sucesso";
                    break;
                default:
                    cout << "Opcao invalida!";
                    break;
                }
            }else
            {
                cout << "Aluno não encontrado!";
            }
        }
    }
}


int main()
{
    int opcao = -1;

    while (opcao != 0) {
        cout << endl << "<--- MENU --->" << endl;
        cout << "1 - Cadastrar aluno" << endl;
        cout << "2 - Listar alunos" << endl;
        cout << "3 - Alterar aluno" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarAluno();
                break;
            case 2:
                listarAlunos();
                break;
            case 3:
                alterarAluno();
                break;
            case 0:
                cout << "Saindo do sistema...\n";
                break;
            default:
                cout << "Opcao invalida! Tente novamente.\n";
        }
    }

    return 0;
}
