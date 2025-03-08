/*
    Baseado no exemplo anterior, crie um código que imprima todos os números de 0 até n (ordem crescente) utilizando
    recursividade no código.
*/

#include <stdio.h>

void imprimir(int x)
{
    if(x==0) //Ponto de parada quando x=0
    {
        printf("%d", x);
    }
    else
    {
        imprimir(x-1); //Armazena o valor atual em uma pilha e decrementa em 1 na variável
        //Após imprimir o 0, o sistema desempilha os valores anteriores e faz o código abaixo pendente
        printf(" %d", x); //Após desempilhar o valor atual, ele imprime e continua na lista de desempilhar, quando realizar o código até o
        //último caso pendente da fila, ele retorna pra função int main, onde foi realizada a primeira chamada da função imprimir()
    }
}


int main()
{
    int num;
    scanf("%d", &num);
    imprimir(num);
    return 0;
}
