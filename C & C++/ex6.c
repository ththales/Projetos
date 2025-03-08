#include <stdio.h>

int Soma(int a_cpy, int b_cpy)
{
    return a_cpy+b_cpy;
}

int main()
{
    int a, b, s;
    scanf("%d%d", &a, &b);
    s = Soma(a, b);
    printf("%d", s);
    return 0;
}