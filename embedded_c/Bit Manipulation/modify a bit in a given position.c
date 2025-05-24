#include <stdio.h>

int modifyBit(int n, int p, int b)
{
    int mask = 1 << p;
    n = (n & ~mask) | (b << p);
    return n;
}

int main()
{
    int x = modifyBit(11, 2, 1);
    printf("Bit modify: %d\n", x);
    return 0;
}