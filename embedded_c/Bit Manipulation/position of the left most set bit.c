#include <stdio.h>

int postLMB(int n)
{
    int pos = 0;
    while(n > 0)
    {
        n = n >> 1;
        pos += 1;
    }
    return pos;
}

int main()
{
    printf("Position of LMB is: %d\n", postLMB(10));
}