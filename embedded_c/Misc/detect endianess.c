#include <stdio.h>

int isLittleEndian()
{
    union
    {
        unsigned int i;
        unsigned char c;
    } test = {.i = 1};
    return test.c;
}

int main()
{
    if(isLittleEndian())
    {
        printf("Little Endian\n");
    }else
    {
        printf("Big Endian\n");
    }
    return 0;
}

// using a pointer cast
// #include <stdio.h>

// int main() {
//     int x = 1;
//     char *ptr = (char*)&x;

//     if (*ptr == 1)
//         printf("Little Endian\n");
//     else
//         printf("Big Endian\n");

//     return 0;
// }