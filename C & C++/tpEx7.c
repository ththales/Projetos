/*
    Uma cadeia de caracteres é dita ser palíndromes se a sequência dos caracteres da cadeia da esquerda para
    direita é igual a sequência de caracteres da direita para esquerda. Por exemplo: as seguintes strings são
    palíndromes: ABC12321CBA, ACCA, XYZ6.6ZYX. Faça uma função que retorna verdadeiro(1) se a cadeia de
    caracteres enviada como parâmetro é palíndrome.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char  str[100];
    scanf("%s", str);
    int tam = strlen(str), i, j;
    for(i=0, j=tam-1; i<(tam/2) && str[i]==str[j]; i++, j--);
    if(i==(tam/2))
    {
        printf("E palindrome.\n");
    }
    else
    {
        printf("Nao e palindrome.\n");
    }
    return 0;
}