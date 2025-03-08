/*
    Crie uma função que receba como parâmetro uma matriz de números inteiros e a imprima. 
    Não utilize índices para percorrer o vetor, apenas noções utilizando de ponteiros.
*/

#include <stdio.h>

//Usando laço de repetição
void imprimeMatriz(int *mat)
{
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            printf("x[%d][%d] = %d\n", i, j, *mat);
            mat++;
        }
    }
}

int main()
{
    int x[2][2] = {{1, 2}, {3, 4}};
    imprimeMatriz(*x);
    return 0;
}

//Usando recursão
int imprimeMatriz(int *mat, int tot)
{
    if(tot==0)
    {
        return 0;
    }
    printf("%d\n", *mat);
    return imprimeMatriz(mat+1, tot-1);
}

int main()
{
    int x[2][2] = {{1, 2}, {3, 4}}, a, tot_elem = 4;
    a = imprimeMatriz(*x, tot_elem);
    return 0;
}