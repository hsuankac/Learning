#include <stdio.h>

int hammingWeight(int n)
{
    int count = 0;
    while(n > 0)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int main()
{
    int n = 11;
    printf("No. of 1 bit is: %d\n", hammingWeight(n));
    return 0;
}