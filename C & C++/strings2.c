/*
    Fazer um programa para:
    a) Receber uma frase do usuário, caractere a caractere usando getchar() e armazenando no vetor
    (máx. 30 caracteres). Quando o usuário digita enter (‘\n’) a recepção é finalizada.
    b) mostrar cada palavra da frase em uma linha separada, implementando função apropriada para
    esta finalidade.
*/

#include <stdio.h>
#include <string.h>

void imprimePalavras(char frase_cpy[]) //Função que imprimirá cada palavra do texto de 30 caracteres
{
    int i = 0;
    while(frase_cpy[i]!='\0') //Enquanto não chegar no fim do texto, ou seja, o caracter atual for diferente de '\0'
    {
        if(frase_cpy[i]!=' ') //Se o caracter atual for diferente de espaço, então imprime a palavra
        {
            putchar(frase_cpy[i]);
        }
        else //Caso contrário, quebra de linha
        {
            printf("\n");
        }
        i++; //Avançando no vetor de caracteres
    }
}

int main()
{
    //Declarando variáveis
    char frase[31]; //Declarando com 31 espaços alocados pois 1 é do caracter '\0'
    int i = 0;

    for(i=0; frase[i-1]!='\n' && i<30; i++)
    {
        frase[i] = getchar(); //Leitura de caracter por caracter
    }

    frase[i] = '\0'; //Recebendo o caracter que indica o final da string

    imprimePalavras(frase);
    return 0;
}