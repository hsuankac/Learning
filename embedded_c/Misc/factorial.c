#include <stdio.h>

// c program to find factorial of a given number
unsigned int factorial(unsigned int n)
{
    if(n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int main()
{
    int n = 5;
    printf("Factorial of 5 is: %d\n", factorial(5));
    return 0;
}