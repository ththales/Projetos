/*
    02- a) função recursiva que multiplique um dado inteiro A por B, usando somas sucessivas
*/

int mult(int a, int b){
    if(b==0){ //1 instrução
        return 0;
    }
    if(b==1){ //1 instrução
        return a;
    }
    return a + mult(a, b-1); //1 instrução e n instruções
}

f(n) = 3*n
complexidade = O(n)

/*
    b) função recursiva que calcule a divisão usando subtrações sucessivas
*/

int divi(a, b){
    if(a<b){ //1 instrução
        return 0;
    }
    return 1 + divi(a-b, b); //1 instrução e n instruções
}

f(n) = 2*n
complexidade = O(n)

/*
    c) função recursiva que calcule o resto da divisão usando subtrações sucessivas
*/

int resto(a, b){
    if(a<b) //1 instrução
    {
        return a;
    }
    return resto(a-b, b); //n instruções
}

f(n) = n
complexidade = O(n)

/*
    d) função recursiva que calcule a potência de um número usando multiplicações sucessivas
*/

int pot(a, b){
    if(b==0){ //1 instrução
        return 1;
    }
    if(b==1){ //1 instrução
        return a;
    }
    return a*pot(a, b-1); //1 instrução e n instruções
}

f(n) = 3*n
complexidade = O(n)

/*
    e) função recursiva que calcule a quantidade de caracteres de uma string
*/

int qtdCaracteres(char *str)
{
    if(*str=='\0') //1 instrução
    {
        return 0;
    }
    return 1+qtdCaracteres(str+1); //1 instrução e n instruções
}

f(n) = 2*n
complexidade = O(n)

/*
    f) função recursiva que calcule o valor da serie S, descrita a seguir, para n>0:
    s = 1 + 1/2! + 1/3! + ... + 1/n!
*/

int fat(int x)
{
    if(x<=1) //1 instrução
    {
        return 1;
    }
    return x*fat(x-1); //1 instrução e n instruções
}

fat(4) = 24
    4*fat(3) = 4*6 = 24
        3*fat(2) = 3*2 = 6
            2*fat(1) = 2*1 = 2
                1

double serie(int x)
{
    if(x==1) //1 instrução
    {
        return 1;
    }
    return 1/fat(x) + serie(x-1); //1 instrução e 2 chamadas recursivas = n*n = n²
}

serie(4) = 1.207
    1/fat(4) + serie(x-1) = 1/24 + serie(3) = 0.041 + 1.16667 = 1.20767
        1/fat(3) + serie(x-1) = 1/6 + serie(2) = 0.1666 + 1.5 = 1.16667
            1/fat(2) + serie(x-1) = 1/2 + serie(1) = 0.5 + 1 = 1.5
                1
    

f(n) = 1 + 1 + n + 1 + 1 + n² = n² + n + 4
complexidade = O(n²)