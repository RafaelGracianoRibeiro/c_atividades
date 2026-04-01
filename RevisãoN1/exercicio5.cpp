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
#include <fstream>

using namespace std;

const int MAX_ALUNOS = 10;
string nomes[MAX_ALUNOS];
float notas[MAX_ALUNOS][4];
int total_alunos = 0;

void salvarRegistro()
{
    ofstream arquivo("alunos.txt");

    if (arquivo.is_open())
    {
        arquivo << total_alunos << endl; // Salva o número total de alunos na primeira linha
        for (int i = 0; i < total_alunos; i++)
        {
            arquivo << nomes[i] << endl;
            for (int j = 0; j < 4; j++)
            {
                arquivo << notas[i][j] << " ";
            }
            arquivo << endl;
        }
        arquivo.close();
        cout << "Registros salvos com sucesso no arquivo 'alunos.txt'!" << endl;
    }
    else
    {
        cout << "Erro ao abrir o arquivo para salvar os registros." << endl;
    }
}

void carregarRegistro()
{
    ifstream arquivo("alunos.txt");

    if (arquivo.is_open())
    {
        arquivo >> total_alunos; // Lê o número total de alunos da primeira linha
        for (int i = 0; i < total_alunos; i++)
        {
            arquivo >> nomes[i];
            for (int j = 0; j < 4; j++)
            {
                arquivo >> notas[i][j];
            }
        }
        arquivo.close();
        cout << "Registros carregados com sucesso do arquivo 'alunos.txt'!" << endl;
    }
    else
    {
        cout << "Nenhum registro anterior encontrado. Iniciando um novo cadastro." << endl;
    }
}

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
    salvarRegistro();
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
        bool encontrado = false;

        for (int i=0;i < total_alunos; i++)
        {
            if (nomes[i] == nomeBusca)
            {
                encontrado = true;
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
                break;
            }
            salvarRegistro();
        }

        if (!encontrado)
        {
            cout << "Aluno não encontrado!" << endl;
        }
    }
}

void deletarAluno()
{
    if (total_alunos < 1)
    {
        cout << "Nenhum aluno cadastrado!" << endl;
    }else
    {
        string nomeBusca;
        cout << "Digite o nome do aluno que deseja deletar: ";
        cin >> nomeBusca;
        bool encontrado = false;

        for (int i = 0; i < total_alunos; i++)
        {
            if (nomes[i] == nomeBusca)
            {
                encontrado = true;
                // Move todos os alunos posteriores uma posição para trás (sobrescrevendo o que vai ser deletado)
                for (int j = i; j < total_alunos - 1; j++)
                {
                    nomes[j] = nomes[j + 1];
                    for (int k = 0; k < 4; k++)
                    {
                        notas[j][k] = notas[j + 1][k];
                    }
                }
                total_alunos--; // Reduz o total de alunos
                cout << "Aluno deletado com sucesso!" << endl;
                salvarRegistro();
                break;
            }
        }

        if (!encontrado)
        {
            cout << "Aluno não encontrado!" << endl;
        }
    }
}

void calculaMedias(float n1, float n2, float n3, float n4, char tipo)
{
    if (tipo == 'A')
    {
        float media = (n1 + n2 + n3 + n4) / 4;
        cout << "Media aritmetica: " << media << endl;
    }else if (tipo == 'P')
    {
        float media = ((n1 * 2) + (n2 * 3) + (n3 * 4) + (n4 * 6)) / (2+3+4+6);
        cout << "Media ponderada: " << media << endl;
    }else
    {
        cout << "Tipo de media invalida!" << endl;
    }
}

int main()
{
    int opcao = -1;

    // Tenta carregar os registros salvos ao iniciar o programa
    carregarRegistro();

    while (opcao != 0) {
        cout << endl << "<--- MENU --->" << endl;
        cout << "1 - Cadastrar aluno" << endl;
        cout << "2 - Listar alunos" << endl;
        cout << "3 - Alterar aluno" << endl;
        cout << "4 - Deletar aluno" << endl;
        cout << "5 - Salvar registro" << endl;
        cout << "6 - Calcular media de um aluno" << endl;
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
            case 4:
                deletarAluno();
                break;
            case 5:
                salvarRegistro();
                break;
            case 6:
            {
                if (total_alunos < 1)
                {
                    cout << "Nenhum aluno cadastrado!" << endl;
                }
                else
                {
                    string nomeBusca;
                    cout << "Digite o nome do aluno: ";
                    cin >> nomeBusca;
                    bool encontrado = false;

                    for (int i = 0; i < total_alunos; i++)
                    {
                        if (nomes[i] == nomeBusca)
                        {
                            encontrado = true;
                            char tipoMedia;
                            cout << "Digite o tipo de media (A - Aritmetica, P - Ponderada): ";
                            cin >> tipoMedia;
                            calculaMedias(notas[i][0], notas[i][1], notas[i][2], notas[i][3], tipoMedia);
                            break;
                        }
                    }

                    if (!encontrado)
                    {
                        cout << "Aluno não encontrado!" << endl;
                    }
                }
                break;
            }
            case 0:
                salvarRegistro(); // Salva automaticamente ao sair
                cout << "Saindo do sistema...\n";
                break;
            default:
                cout << "Opcao invalida! Tente novamente.\n";
        }
    }

    return 0;
}