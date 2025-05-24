#include <stdio.h>

int poOfTwo(int n )
{
    return (n & (n - 1)) == 0 ? 1 : 0;
}

int posOfSet(int n)
{
    int i = 1;
    int pos = 1;
    if(poOfTwo(n) == 0){
        return -1;
    }
    else{
        while((n & i) == 0)
        {
            i <<= 1;
            pos += 1;
        }
    }
    return pos;
}

int main()
{
    int n = 8;
    printf("the position that only bit is set is: %d\n", posOfSet(n));
    return 0;
}