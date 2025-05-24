#include <stdio.h>
#include <math.h>

int rightMostPos(int n)
{

    return n & ~(n - 1);
}

int main()
{
    printf("Right most position = %d\n", rightMostPos(10));
}