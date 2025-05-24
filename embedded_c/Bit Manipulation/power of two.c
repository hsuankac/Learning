#include <stdio.h>
#include <stdbool.h>

bool powerOfTwo(int n)
{
    return (n & (n - 1)) == 0 ? true : false;
}

int main()
{
    int n = 8;
    printf("is power of two: %d\n", powerOfTwo(n));
}