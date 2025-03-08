#include <stdio.h>
#include <string.h>

int main()
{
    char str[1001], aux;
    int str_len;
    printf("Digite seu texto para criptografar: ");
    fgets(str, 1001, stdin);
    str_len = strlen(str);
    if(str[str_len-1]=='\n')
    {
        str[str_len-1] = '\0';
        str_len--;
    }
    for(int j=0; j<str_len; j++)
    {
        if((str[j]>='A' && str[j]<='Z') || (str[j]>='a' && str[j]<='z'))
        {
            str[j] += 3;
        }
    }
    for(int j=0, k=str_len-1; j<k; j++, k--)
    {
        aux = str[j];
        str[j] = str[k];
        str[k] = aux;
    }
    for(int j=str_len/2; j<str_len; j++)
    {
        str[j]--;
    }
    printf("%s\n", str);
    system("PAUSE");
    return 0;
}