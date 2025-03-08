/*
    Escreva um programa que contenha duas variáveis inteiras. Leia essas variáveis
    do teclado. Em seguida, compare seus endereços e exiba o conteúdo do maior
    endereço.
*/

#include <stdio.h>

int main()
{
    int x, y;
    scanf("%d%d", &x, &y);
    if(&x>&y)
    {
        printf("%d\n", x);
    }
    else
    {
        printf("%d\n", y);
    }
    return 0;
}