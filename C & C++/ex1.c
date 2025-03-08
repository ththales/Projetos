/*
    ENUNCIADO:
    I) Faça um programa em linguagem C que Leia 10 números, cujo intervalo é definido por: {X ∈ inteiros | 10 <= X <= 100};
    II) Armazene-os em um vetor caso o número atual não foi lido anteriormente.
*/

#include <stdio.h>

int main()
{
    int A[10], num, i, j, k;
    for(i=0; i<10; i++)
    {
        scanf("%d", &num);
        while(num<10 || num>100)
        {
            scanf("%d", &num);
            A[i] = 0;
        }
        for(j=0; j<i && num!=A[j]; j++);
        if(j!=i)
        {
            printf("Numero ja lido\n");
            i--;
        }
        else
        {
            A[i] = num;
        }
    }
    for(k=0; k<i; k++)
    {
        if(A[k]!=0)
        {
            printf("%d ", A[k]);
        }
    }
    return 0;
}