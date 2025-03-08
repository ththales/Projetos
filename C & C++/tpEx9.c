/*
    Fazer um programa para:
    a) Receber uma frase do usuário, caractere a caractere usando getchar() e armazenando no vetor
    (máx. 30 caracteres). Quando o usuário digita enter (‘\n’) a recepção é finalizada.
    b) mostrar cada palavra da frase em uma linha separada, implementando função apropriada para
    esta finalidade.
*/

#include <stdio.h>
#include <string.h>

void mostrarPalavras(char frase[])
{
    int tam = strlen(frase);
    for(int i=0; i<tam; i++)
    {
        if(frase[i]!=' ')
        {
            printf("%c", frase[i]);
        }
        else
        {
            printf("\n");
        }
    }
}

int main()
{
    char frase[30];
    int i = 0;
    do
    {
        frase[i] = getchar();
        i++;
    }while(i<30 && frase[i-1]!='\n');
    frase[i-1] = '\0';
    mostrarPalavras(frase);
    return 0;
}