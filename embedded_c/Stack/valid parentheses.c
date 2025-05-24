#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define a structure for the stack
typedef struct 
{
    char* array;
    int top;
    int capacity;
} stack;

// function to create a new stack
stack* createStack(int capacity)
{
    stack* st = (stack*)malloc(sizeof(stack));
    st->top = -1;
    st->capacity = capacity;
    st->array = (int*)malloc(sizeof(int) * st->capacity);
    return st;
}

bool isEmpty(stack* st)
{
    return st->top == -1;
}

void push(stack* st, char item)
{
    st->array[++st->top] = item;
}

char pop(stack* st)
{
    if(!isEmpty(st))
    {
        return st->array[st->top--];
    }
    return '$'; // placeholder for empty stack
}

bool isValidExpression(char* expression)
{
    stack* st = createStack(strlen(expression));
    for(int i = 0; expression[i]; i++)
    {
        if(expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
        {
            push(st, expression[i]);
        }else if(expression[i] == ')' || expression[i] == ']' || expression[i] == '}')
        {
            // can not start from closing brackets
            if(isEmpty(st))
            {
                free(st->array);
                free(st);
                return false;
            }
            char topChar = pop(st);
            if ((expression[i] == ')' && topChar != '(') ||
                (expression[i] == ']' && topChar != '[') ||
                (expression[i] == '}' && topChar != '{')) 
                {
                    free(st->array);
                    free(st);
                    return false;
                }
        }
    }

    bool result = isEmpty(st);
    free(st->array);
    free(st);
    return result;
}

int main() {
    char expression[] = "{[()]()}";
    printf("The length of the expression: %d\n", strlen(expression));
    if (isValidExpression(expression)) {
        printf("The expression is valid.\n");
    } else {
        printf("The expression is not valid.\n");
    }

    return 0;
}
