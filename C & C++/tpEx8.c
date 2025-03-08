/*
    Faça um programa que receba um nome completo do usuário e retorne a abreviatura deste nome. Não se
    devem abreviar palavras com dois caracteres ou menos, tais como as preposições: do, de, etc. A abreviatura
    deve vir separada por pontos. Ex: Paulo Jose de Almeida Prado. Abreviatura: P. J. de A. P
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char nome[100], abrev[100];
    int i = 0, j = 0;
    fgets(nome, sizeof(nome), stdin);
    while(nome[i]!='\0' && nome[i]!='\n')
    {
        if(nome[i]==' ')
        {
            abrev[j] = ' ';
            j++;
            i++;
        }
        else
        {
            if((nome[i]=='D' || nome[i]=='d') && (nome[i+1]=='a' || nome[i+1]=='e') && nome[i+2]==' ')
            {
                abrev[j] = nome[i];
                j++;
                abrev[j] = nome[i+1];
                j++;
                i+=2;
            }
            else
            {
                abrev[j] = nome[i];
                j++;
                abrev[j] = '.';
                j++;
                while(nome[i]!=' ' && nome[i]!='\n')
                {
                    i++;
                }
            }
        }
    }
    abrev[j] = '\0';
    printf("%s", abrev);
    return 0;
}