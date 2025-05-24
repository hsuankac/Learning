#include <stdio.h>
#include <math.h>

int toggleRightMostSetBit(int n)
{
    return n ^ (n & (-n));
}

int main()
{
    int num = 10;
    printf("Toggle result: %d\n", toggleRightMostSetBit(num));
}