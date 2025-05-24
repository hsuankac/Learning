#include <stdio.h>

int singleNum(int* num, int numsize)
{
    int result = 0;
    for(int i = 0; i < numsize; i++)
    {
        result ^= num[i];
    }
    return result;
}

int main()
{
    int num[] = {2, 2, 1};
    printf("Single number is: %d\n", singleNum(num, sizeof(num)/sizeof(int)));
    return 0;
}