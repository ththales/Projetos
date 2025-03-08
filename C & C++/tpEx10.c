/*
    Faça um programa que dado 2 palavras, determine:
    a) Se as palavras são iguais;
    b) Caso as palavras sejam diferentes, qual delas tem maior comprimento (não esquecer a possibilidade de existirem palavras diferentes de mesmo tamanho);
    c) Verifique se a segunda palavra é uma sub-string da primeira:
    Exemplo: Palavra1 = casamento e Palavra2 = casa
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100], str2[100];
    int tam1, tam2, i = 0, cont_sub = 0;
    scanf("%s %s", str1, str2);
    tam1 = strlen(str1);
    tam2 = strlen(str2);
    printf("tam1 = %d\n", tam1);
    printf("tam2 = %d\n", tam2);
    if(strcmp(str1, str2)==0)
    {
        printf("Sao iguais\n");
    }
    else
    {
        printf("Sao diferentes\n");
        if(tam1>tam2)
        {
            printf("A primeira e maior\n");
        }
        else
        {
            if(tam1<tam2)
            {
                printf("A segunda e maior\n");
            }
            else
            {
                printf("Ambas possuem o mesmo tamanho\n");
            }
        }
    }
    /*
    while(str2[i]==str1[i] && i<tam2)
    {
        cont_sub++;
        if(cont_sub==4)
        {
            i = tam2;
        }
        i++;
    }
    if(cont_sub==4)
    {
        printf("str2 e sub-string de str1\n");
    }
    else
    {
        printf("str2 nao e sub-string de str1\n");
    }*/
    if(strstr(str2, str1))
    {
        printf("str2 e sub-string de str1\n");
    }
    else
    {
        printf("str2 nao e sub-string de str1\n");
    }
    return 0;

}