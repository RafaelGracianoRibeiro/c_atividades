//Escreva um algoritimo que solicite 5 nomes e os exiba em lista na tela
//Apos exibir a lista de nomes exiba novamente em ordem inversa
#include <iostream>
#include  <string>
using namespace std;

int main(){
    int tamanhoLista = 5;
    string names[tamanhoLista];

    for (int i=0;i<tamanhoLista;i++)
    {
        cout << "Digite um nome para entrar na lista: ";
        getline(cin, names[i]);
    }

    cout << "Imprimindo a lista de nomes" << endl;
    for (int i=0; i<tamanhoLista; i++)
    {
        cout << i+1 << " -> " << names[i] << endl;
    }

    cout << "Imprimindo a lista de nomes em ordem inversa" << endl;
    for (int i=tamanhoLista-1; i>=0; i--)
    {
        cout << i+1 << " -> " << names[i] << endl;
    }

}