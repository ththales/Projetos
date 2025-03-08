#include <stdio.h>

int main() {
    //Declarando variáveis
    int tam;

    //Lendo o tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    //Declarando variáveis
    int A[tam], menor, aux;

    //Lendo o vetor
    for(int i=0; i<tam; i++) {
        printf("A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    //Ordenando o vetor
    for(int i=0; i<tam-1; i++) {
        //Menor começando na posição i
        menor = i;

        for(int j=i+1; j<tam; j++) {
            //Verificando se o elemento A[j] é menor que o menor até agora
            if(A[j]<A[menor]) {
                menor = j;
            }
        }

        //Trocando os elementos de lugar
        aux = A[i];
        A[i] = A[menor];
        A[menor] = aux;
    }

    //Imprimindo o vetor ordenado
    for(int i=0; i<tam; i++) {
        printf("A[%d] = %d\n", i, A[i]);
    }
    return 0;
}