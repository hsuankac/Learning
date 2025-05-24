// https://leetcode.com/problems/basic-calculator-ii/description/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int calculate(const char* s)
{
    int stack[1000];
    int top = -1;
    char sign = '+';
    int num = 0;

    for(int i = 0; s[i]; i++)
    {
        char c = s[i];
        if(isdigit(c))
        {
            num = num * 10 + (c - '0');
        }
        // should not use else if here in order to process the last number
        if((!isdigit(c) && c != ' ') || s[i + 1] == '\0')
        {
            if (sign == '+') 
            {
                stack[++top] = num;
            } 
            else if (sign == '-') 
            {
                stack[++top] = -num;
            } 
            else if (sign == '*') 
            {
                stack[top] *= num;
            } 
            else if (sign == '/') 
            {
                stack[top] /= num;
            }
            sign = c;
            num = 0;
        }
    }

    int result = 0;
    for (int i = 0; i <= top; i++) 
    {
        result += stack[i];
    }
    return result;
}


int main()
{
    char expr[] = "3+2*2";
    int result = calculate(expr);
    printf("Result: %d\n", result); // Output: 7
    return 0;
}