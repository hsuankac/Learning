#include <stdio.h>

int setAllBitsInRange(int n, int l, int r)
{
    int range = ((1 << r) - 1) ^ ((1 << (l - 1)) - 1);
    return n | range;
}

int main()
{
    int n = 16, l = 2, r = 5;
    printf("set bits in range: %d\n", setAllBitsInRange(n, l, r));
    return 0;
}