#include <stdio.h>

int main()
{
    int A[10] ={42, 360, 317, 127, 256, 581, 835, 195, 432, 348}, pos, aux;
    for(int i=0; i<9; i++)
    {
        pos = i;
        for(int j=i+1; j<10; j++)
        {
            if(A[j]<A[pos])
            {
                pos = j;
            }
        }
        aux = A[i];
        A[i] = A[pos];
        A[pos] = aux;
    }
    return 0;
}