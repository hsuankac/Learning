#include <stdio.h>

int atoi(char* str)
{
    int result = 0;
    int sign = 1;
    // Examine whether it is signed integer
    if(str[0] == '-')
    {
        sign = -1;
        str++;
    }
    while(*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    return result;
}

int main()
{
    char test[] = "1234";
    int res = atoi(test);
    printf("The atoi function is: %d\n", res);
    return 0;
}