/*
    ENUNCIADO:
    I) Faça um programa em C que leia 10 valores reais e os armazene em um vetor;
    II) Após realizada a leitura, inverta os numeros, ficando o primeiro na ultima posicao e assim consequentemente.
*/

#include <stdio.h>

int main()
{
    int A[10], aux;
    for(int i=0; i<10; i++)
    {
        scanf("%d", &A[i]);
    }
    for(int i=0; i<5; i++)
    {
        aux = A[i];
        A[i] = A[9-i];
        A[9-i] = aux;
    }
    for(int i=0; i<10; i++)
    {
        printf("%d ", A[i]);
    }
    return 0;
}