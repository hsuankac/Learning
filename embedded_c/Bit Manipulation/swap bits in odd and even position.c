#include <stdio.h>

int main()
{
    int a = 7;
    int even_mask = 0xAAAAAAAA;
    int odd_mask = 0x55555555;
    int even_bits = a & even_mask;
    int odd_bits = a & odd_mask;
    int swap_bits = even_bits >> 1 | odd_bits << 1;
    printf("swapped bit values is: %d\n", swap_bits);
    return 0;

}