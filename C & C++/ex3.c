/*
    ENUNCIADO:
    Faça um programa em linguagem C que leia 5 valores inteiros, armazeno-os em um vetor, calcule e apresente a soma destes valores.
*/


#include <stdio.h>

int main()
{
    int A[5], s = 0;
    for(int i=0; i<5; i++)
    {
        scanf("%d", &A[i]);
        s += A[i];
    }
    printf("S = %d\n", s);
    return 0;
}