// https://leetcode.com/problems/backspace-string-compare/description/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// build final string after applying backspace
char* processString(const char* str)
{
    int len = strlen(str);
    char* result = (char*)malloc(sizeof(char) * (len + 1));
    int index = 0;
    for(int i = 0; i < len; i++)
    {
        //ab#c
        if(str[i] == '#')
        {
            if(index > 0){
                index--;
            }
        }else{
            result[index++] = str[i];
        }
    }
    result[index] = '\0';
    return result;
}

bool backSpaceCompare(const char* s, const char* t)
{
    char* finals = processString(s);
    char* finalt = processString(t);

    bool equal = strcmp(finals, finalt) == 0;
    free(finals);
    free(finalt);
    return equal;
}

int main()
{
    const char* s = "ab#c";
    const char* t = "ad#c";

    if(backSpaceCompare(s, t))
    {
        printf("Strings are equal after backspace\n");
    }else{
        printf("Strings are not equal after backspace\n");
    }

    return 0;
}