//Faça um algoritimo para representar a transposta de uma matriz 5x4
#include <iostream>
#include <random>
using namespace std;

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>distribution(1,100);

    int colunas = 5;
    int linhas = 4;

    int matriz[colunas][linhas];
    int matrizTransposta[linhas][colunas];//Matriz transposta inverre colunas e linhas


    for (int i=0; i<colunas;i++)//Colunas
    {
        for (int j=0;j<linhas;j++)//Linhas
        {
            matriz[i][j] = distribution(gen);//Definindo colunas
            matrizTransposta[j][i] = matriz[i][j];//Definindo linhas
        }
    }

    //Exibindo a matriz em forma de tabela
    cout << "Matriz original: " << endl;
    for (int i=0; i<colunas;i++)
    {
        for (int j=0;j<linhas;j++)
        {
            cout << matriz[i][j] << "\t";

        }
        cout << endl;
    }cout << endl;

    cout << "Matriz trnaposta: " << endl;
    for (int i=0; i<linhas;i++)
    {
        for (int j=0;j<colunas;j++)
        {
            cout << matrizTransposta[i][j] << "\t";

        }
        cout << endl;
    }cout << endl;


}