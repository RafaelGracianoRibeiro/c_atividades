//Criar função que retorne o dobro de um número passado como parametro

#include<iostream>
using namespace std;

int dobro(int n)
{
    return n*2;
}

int main()
{
    int numero;
    cout << "Digite um número para ser multiplicado por 2: ";
    cin >> numero;
    cout << "O dobro de " << numero << " é " << dobro(numero);
}