#include <stdio.h>

int add(int a, int b)
{
    int carry = 0;
    while(b > 0)
    {
        carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

int main()
{
    int a = 5, b = 3;
    int result = add(a, b);
    printf("Result: %d\n", result);
}