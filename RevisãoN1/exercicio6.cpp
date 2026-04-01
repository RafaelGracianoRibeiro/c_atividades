/*Faça um procedimento que recebe a idade de um nadador por parâmetro e
retorna, também por parâmetro, a categoria desse nadador de acordo com a
tabela abaixo:
Idade Categoria
5 a 7 anos Infantil A
8 a 10 anos Infantil B
11-13 anos Juvenil A
14-17 anos Juvenil B
Maiores de 18 anos (inclusive) Adulto*/

#include <iostream>
using namespace std;

void retornaCategoria(int age)
{
    if (age < 5)
    {
        cout << age << " anos - Categoria: Invalida" << endl;
    }else if (age > 4 && age < 8)
    {
        cout << age << " anos - Categoria: Infantil A" << endl;
    }else if (age > 7 && age < 11)
    {
        cout << age << " anos - Categoria: Infantil B" << endl;
    }else if (age > 10 && age < 14){
        cout << age << " anos - Categoria: Juvenil A" << endl;
    }else if (age > 13 && age < 18)
    {
        cout << age << " anos - Categoria: Juvenil B" << endl;
    }else
    {
        cout << age << " anos - Categoria: Adulto" << endl;
    }
}

int main()
{
    int idade = 0;
    for (int i=0; i<20;i++)
    {
        retornaCategoria(i);
    }
}

