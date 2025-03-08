/*
    Função ou procedimento recursivo é aquela que chama a si mesma

    Ex: Imprimir todos os números de n até 0
*/

#include <stdio.h>
#include <stdlib.h>


void imprimir(int x)
{
    if(x==0) //Ponto de parada para o encerramento das chamadas (caso contrário teríamos um loop infinito)
    {
        printf("%d", x);
        //Note: como aqui não temos chamada recursiva pois x=0, então se encerra nossa função
    }
    else
    {
        printf("%d ", x); //Imprimindo os números maiores que 0
        imprimir(x-1); //Chamando a função para resolver um problema mais interno, decrementando a instancia X para a proxima rodada na função
        //Após chamar a função, ela vai resolvendo os problemas dos próximos números, acumulando as contas e imprimindo até chegar x=0
        //Depois, ele desempilha as chamadas anteriores, verificando se há algum código abaixo da chamada da função, como nesse caso não há,
        //ele só termina direto, voltando para a função main
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    while(n<0)
    {
        printf("Numero invalido, tente novamente: ");
        scanf("%d", &n);
    }
    imprimir(n);
    return 0;
}