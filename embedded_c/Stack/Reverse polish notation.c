#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK_SIZE      1000

bool isNumber(const char* token) 
{
    if (token == NULL || *token == '\0') return false;

    int i = 0;

    // Skip optional '+' or '-' sign
    if (token[0] == '+' || token[0] == '-') {
        i++;
    }

    // If the string is just "+" or "-", it's not a number
    if (token[i] == '\0') return false;

    // Ensure all remaining characters are digits
    for (; token[i] != '\0'; i++) {
        if (!isdigit(token[i])) return false;
    }

    return true;
}

int evalRPN(char** tokens, int size)
{
    int stack[MAX_STACK_SIZE];
    int top = -1;

    for(int i = 0; i < size; i++)
    {
        char* token = tokens[i];
        if(isNumber(token)){
            stack[++top] = atoi(token);
        }else{
            int b = stack[top--];
            int a = stack[top--];
            int result;
            if (strcmp(token, "+") == 0) result = a + b;
            else if (strcmp(token, "-") == 0) result = a - b;
            else if (strcmp(token, "*") == 0) result = a * b;
            else if (strcmp(token, "/") == 0) result = a / b;

            stack[++top] = result;
        }
    }
    return stack[top];
}

int main()
{
    char* tokens[] = {"21", "1", "+", "3", "*"};
    int size = sizeof(tokens) / sizeof(tokens[0]);

    int result = evalRPN(tokens, size);
    printf("Result: %d\n", result);
    return 0;
}