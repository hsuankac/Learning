#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void reverse(char str[], int start, int end)
{
    while(start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void reverseWords(char str[])
{
    int len = strlen(str);
    // step 1: Reverse the whole string
    reverse(str, 0, len - 1);

    // step 2: Reverse each word in the reversed string
    int start = 0;
    for(int i = 0; i <= len; i++)
    {
        if(str[i] == ' ' || str[i] == '\0')
        {
            reverse(str, start, i - 1);
            start = i + 1;
        }
    }
}

int main()
{
    char str[] = "Hello world this is C";
    reverseWords(str);
    printf("Reversed: %s\n", str);
    return 0;
}