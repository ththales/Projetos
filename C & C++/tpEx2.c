/*
    Crie um programa que contenha um array de float com 10 elementos. Imprima o endereço de cada posição desse array.
*/

#include <stdio.h>

int main()
{
    float x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(int i=0; i<10; i++)
    {
        printf("&x[%d] = %p\n", i, &x[i]);
    }
    return 0;
}