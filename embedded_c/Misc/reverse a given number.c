#include <stdio.h>

int reverseNum(int num)
{
    int res = 0;
    while(num > 0)
    {
        int digit = num % 10;
        res = res * 10 + digit;
        num /= 10;
    }
    return res;
}


int main()
{
    int n = 123;
    printf("After reversing 123: %d\n", reverseNum(n));
}