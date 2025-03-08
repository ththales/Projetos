/*
    Crie uma função que receba como parâmetro um vetor de números inteiros e o imprima.
    Não utilize índices para percorrer o vetor, apenas noções utilizando de ponteiros.
*/
#include <stdio.h>

//Usando laço de repetição
void imprimeVetor(int *vet)
{
    for(int i=0; i<5; i++)
    {
        printf("x[%d] = %d\n", i, *vet);
        vet++;
    }
}

int main()
{
    int x[5] = {1, 2, 3, 4, 5};
    imprimeVetor(x);
    return 0;
}

//Usando recursão
int imprimeVetor(int *vet, int i)
{
    if(*vet>5)
    {
        return 0;
    }
    printf("&x[%d] = %d\n", i, *vet);
    i++;
    return imprimeVetor(vet+1, i);
}

int main()
{
    int x[5] = {1, 2, 3, 4, 5}, a, i = 0;
    a = imprimeVetor(x, i);
    return 0;
}