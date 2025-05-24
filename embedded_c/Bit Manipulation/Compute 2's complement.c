#include <stdio.h>

int twosCom(int n)
{
    int ones = ~n;
    int twos = ones + 1;
    return twos;
}

int main()
{
    int n = 4;
    printf("Twos complement: %d\n", twosCom(n));
}