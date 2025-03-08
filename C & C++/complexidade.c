//Notação assintótica f(n) e complexidade big O

/*
    01) Codifique um algoritmo que multiplique um valor inteiro A por B, usando recursividade
    de somas sucessivas.
*/

/*
    O que vem a ser uma multiplicação de um número por outro?
    Seria, de forma simplificada, a soma sucessiva de um número por ele mesmo X vezes.

    Ex: 2*3 = 2+2+2 = 6
*/

//Código:
int mult(int x, n)
{
    if(n==0) //x*n = x*n = 0
    {
        return 0;
    }
    return x + mult(x, n-1);
}

/*
    Recursão: mult(2, 3)

    - Empilhando
    return 2 + mult(2, 3-1) = 2 + mult(2, 2) = 2 + 4 = 6 //mult(2, 3)
    1ª chamada) return 2 + mult(2, 2-1) = 2 + mult(2, 1) = 2 + 2 = 4 //mult(2, 2)
    2ª chamada) return 2 + mult(2, 1-1) = 2 + mult(2, 0) = 2 + 0 = 2; //mult(2, 1)

    - Desempilhando
    mult(2,3) = 2ª + 1ª = mult(2, 1) + mult(2, 2) = 2 + 4 = 6
*/

/*
    - Notação assintótica f(n)
    if(n==0) -> val = 1 complexidade
    {
        return 0; -> val = 0 complexidade, irrelevante
    }

    Note que no pior caso, onde n!=0, iremos para a linha com a chamada recursiva, até que n==0
    return x + mult(x, n-1); -> val = n complexidade, executado b vezes
    
    Portanto, f(n) = 1 + n

    - Complexidade Big O:
    O termo de grau mais relevante nesse caso é o próprio n, portanto:
    complexidade = O(n)
*/

/*
    02) Faça uma função recursiva que calcule a divisão usando subtrações sucessivas
*/

/*
    O que seria uma divisão?
    Resumindo, o número de vezes que podemos subtrair um número x por y, onde x>=y

    Ex: 12/2 = 12-2 = 10-2 = 8-2 = 6-2 = 4-2 = 2-2 = 6 subtrações possíveis

    Ex2: 7/8 = 0, pois não é possível subtrair x de y (x<y)
*/

//Código
int divi(x, n)
{
    if(x<n) //não é possível mais dividir, logo retornaremos 0
    {
        return 0;
    }
    return 1 + divi(x-n, n);
}

/*
    Recursão: return 1 + divi(x-n, n)
    
    Explicação: retornaremos 1 a cada vez que se for possível dividir, ou seja, estamos contando
    quantas subtrações consigo realizar entre x e n.

    Obs: quando chamamos a função, mantemos o n inalterado, uma vez que se trata do divisor

    Ex: divi(12, 4)
    - Empilhando
    return 1 + divi(12-4, 4) = 1 + divi(8, 4) = 1 + 2 = 3 //divi(12, 4)
    1ª chamada) return 1 + divi(8-4, 4) = 1 + divi(4, 4) = 1 + 1 = 2 //divi(8, 4) 
    2ª chamada) return 1 + divi(4-4, 4) = 1 + divi(0, 4) = 1 + 0 = 1 //divi(4, 4)

    - Desempilhando
    divi(12, 4) = 2ª + 1ª = divi(4, 4) + divi(8, 4) = 1 + 2 = 3
*/

/*
    - Notação assintótica f(n)
    if(x<n) -> val = 1 complexidade
    {
        return 0; -> val = 0 complexidade
    }
    return 1 + divi(x-n, n); -> val = n complexidade

    Portanto, f(n) = 1 + n
    
    - Complexidade Big O:
    O termo de grau mais relevante nesse caso é o próprio n, portanto:
    complexidade = O(n)
*/

/*
    03) Faça um programa que consiga o tamanho de uma string usando recursividade.
*/

/*
    Como desobrir o tamanho de um texto (string)?
    Precisamos saber qual a posição do caracter '\0', pois a partir dela descobrimos qual o tamanho
    dessa string, obviamente sem contar esse caracter

    Ex: str[] = {'B', 'O', 'M', ' ', 'D', 'I', 'A', '\0'}
    o tamanho da string acima é de 7 caracteres (sem o '\0', que indica que o texto terminou)
*/

//Código 01
int strTamanho(char *str) //Nós passamos a primeira posição da string str, por referenciação (*)
{
    if(*str=='\0') //comparando o elemento da posição atual (desreferenciação)
    {
        return 0;
    }
    return 1 + strTamanho(str+1); //uma posição a frente
}

/*
    Recursão: return 1 + strTamanho(str+1);
    
    Explicação: retornaremos 1 a cada vez que se contar um caracter diferente de '\0'. Depois,
    avançamos em +1 posição do vetor str

    Ex: strTamanho(char *str), onde str[0]!='\0'

    Obs: o valor apontado se refere sempre à primeira posição do vetor, ou seja a 0

    str[] = {'O', 'I', '\0'};

    - Empilhando
    return 1 + strTamanho(str[0+1]) = 1 + strTamanho(str[1]) = 1 + 1 = 2 // O tamanho da string
    1ª chamada) return 1 + strTamanho(str[1+1]) = 1 + strTamanho(str[2]) = 1 + 0 = 1 // strTamanho(str[1])
    2ª chamada) return 0 //strTamanho(str[2]) -> no caso, o caracter '\0' retornou 0
    

    - Desempilhando
    strTamanho(char *str) = 0 + 1 + 1 = 2 -> tamanho da string
*/

/*
    - Notação assintótica f(n)
    if(*str=='\0') -> val = 1 complexidade
    {
        return 0; -> val = 0 complexidade
    }
    return 1 + strTamanho(str+1); -> val = n complexidade (não sabemos o tamanho de str)

    Portanto, f(n) = 1 + n
    
    - Complexidade Big O:
    O termo de grau mais relevante nesse caso é o próprio n, portanto:
    complexidade = O(n)
*/