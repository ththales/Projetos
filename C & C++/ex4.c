/*
    ENUNCIADO:
    Altere o programa do ex3 para calcular e apresentar a média dos valores entrados e aqueles que são maiores e menores que a média.
*/

#include <stdio.h>

int main()
{
    int A[5], s = 0;
    float med;
    for(int i=0; i<5; i++)
    {
        scanf("%d", &A[i]);
        s += A[i];
    }
    med = s/5.0;
    printf("Media = %.1f\n", med);
    for(int i=0; i<5; i++)
    {
        if(A[i]>med)
        {
            printf("(A[%d] = %d) > Media\n", i, A[i]);
        }
        else
        {
            printf("(A[%d] = %d) < media\n", i, A[i]);
        }
    }
    return 0;
}
