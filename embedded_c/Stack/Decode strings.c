// https://leetcode.com/problems/decode-string/description/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN         10000
#define STACK_SIZE      1000

char* decodeString(const char* s)
{
    char* strStack[STACK_SIZE];
    int countStack[STACK_SIZE];
    int top = -1;

    char* current = (char*)calloc(MAX_LEN, sizeof(char));
    int curLen = 0;
    int num = 0;

    for(int i = 0; s[i]; i++)
    {
        if(isdigit(s[i]))
        {
            num = num * 10 + (s[i] - '0');
        }
        else if(s[i] == '[')
        {
            // push current string and number to stack
            strStack[++top] = current;
            countStack[top] = num;
            current = (char*)calloc(MAX_LEN, sizeof(char));
            curLen = 0;
            num = 0;
        }
        else if(s[i] == ']')
        {   
            // pop from stack
            int repeat = countStack[top];
            char* prev = strStack[top--];

            // allocate space for repeated strings
            char* temp = (char*)calloc(MAX_LEN, sizeof(char));
            for(int i = 0; i < repeat; i++)
            {
                strcat(temp, current);
            }
            strcat(prev, temp);
            free(current);
            free(temp);
            current = prev;
        }
        else
        {
            int len = strlen(current);
            current[len] = s[i];
            current[len + 1] = '\0';
        }
    }
    return current;
}

int main()
{
    const char* encoded = "3[a2[c]]";
    char* decoded = decodeString(encoded);
    printf("Decoded string is: %s\n", decoded);
    free(decoded);
    return 0;
}