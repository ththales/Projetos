/*
    ENUNCIADO:
    I) Faça um programa em linguagem C que leia 10 números inteiros e preencha um vetor A;
    II) Crie um segundo vetor B de mesmo tamanho que terá contido o quadrado dos mesmos números do vetor A;
*/


#include <stdio.h>

int main()
{
    int A[10], B[10];
    for(int i=0; i<10; i++)
    {
        scanf("%d", &A[i]);
        printf("A[%d] = %d\n", i, A[i]);
        B[i] = A[i]*A[i];
        printf("B[%d] = %d\n\n", i, B[i]);
    }
    return 0;
}