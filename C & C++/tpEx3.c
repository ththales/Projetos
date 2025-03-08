/*
    Crie um programa que contenha uma matriz de float com três linhas e três colunas.
    Imprima o endereço de cada posição dessa matriz.
*/


#include <stdio.h>

int main()
{
    float x[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            printf("&x[%d][%d] = %p\n", i, j, &x[i][j]);
        }
    }

}