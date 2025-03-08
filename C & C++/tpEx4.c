/*
    Crie um programa que contenha um array com cinco elementos inteiros. Leia
    esse array do teclado e imprima o endereço das posições contendo valores
    pares.
*/

#include <stdio.h>

int main()
{
    int x[5];
    for(int i=0; i<5; i++)
    {
        scanf("%d", &x[i]);
    }
    for(int i=0; i<5; i++)
    {
        if(x[i]%2==0)
        {
            printf("&x[%d] = %p\n", i, &x[i]);
        }
    }
    return 0;
}