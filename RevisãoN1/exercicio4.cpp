//Crie uma função que receba 3 números inteiros e retorne a média deles

#include <iostream>
using namespace std;

void retornaMedia(int n1, int n2, int n3)
{
    float media = (n1+n2+n3)/3;
    cout << "A média dos números digitados é: " << media;
}

int main()
{
    int n1,n2,n3;

    cout << "Digite o valor do primeiro número: ";
    cin >> n1;
    cout << "Digite valor do segundo número: ";
    cin >> n2;
    cout << "Digite o valor do terceiro número: ";
    cin >> n3;

    retornaMedia(n1,n2,n3);
}