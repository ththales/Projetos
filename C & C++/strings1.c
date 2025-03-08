/*
    Faça um programa que receba um nome completo do usuário e retorne a abreviatura deste nome. Não se
    devem abreviar palavras com dois caracteres ou menos, tais como as preposições: do, de, etc. A abreviatura
    deve vir separada por pontos. Ex: Paulo Jose de Almeida Prado. Abreviatura: P. J. de A. P
*/


#include <stdio.h>
#include <string.h>

int main()
{
    //Declarando variáveis
    char nome[100], abrev[100];
    int i = 0, j = 0; //i -> contador do nome, j -> contador da abreviação

    //Lendo o nome completo da pessoa
    fgets(nome, sizeof(nome), stdin);

    //Repetição para verificar se chegou no final do nome
    while(nome[i]!='\0' && nome[i]!='\n')
    {
        if(nome[i]==' ')
        {
            //O caracter atual do nome é um espaço
            abrev[j] = ' '; //A string abrev recebe um espaço
            j++; //Avançando 1 posição no contador para abrev
            i++; //Avançando 1 posição no contador para nome
        }
        else
        {
            //O caracter atual do nome não é um espaço

            //Verificando se o trecho atual do nome se trata de uma preposição "de", "da" ou "do"
            if(nome[i]=='d' && (nome[i+1]=='e' || nome[i+1]=='a' || nome[i+1]=='o'))
            {
                abrev[j] = nome[i];
                j++;
                abrev[j] = nome[i+1];
                j++;
                i+=2;
            }
            else
            {
                abrev[j] = nome[i]; //A string abrev recebe o caracter atual do nome
                j++; //Avançando 1 posição no contador para abrev
                abrev[j] = '.'; //Adicionando '.' para a posição atual
                j++; //Avançando 1 posição no contador para abrev
                while(nome[i]!=' ' && nome[i]!='\n') //Avançando na string até o próximo espaço do nome
                {
                    i++;
                }
            }
        }
    }
    abrev[j] = '\0'; //Recebendo no ultimo espaço da abreviação o caracter '\0', indicando que acabou a string
    printf("%s", abrev); //Imprimindo a abreviação do nome lido
    return 0;
}