#include <stdio.h>

void swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main()
{
    int x = 10, y = 5;
    swap(&x, &y);
    printf("After swapping: x = %d, y = %d\n", x, y);
}