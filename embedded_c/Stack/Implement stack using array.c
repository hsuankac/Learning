#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE            100

typedef struct
{
    int top;
    int data[MAX_SIZE];
} Stack;

void initialize(Stack* st)
{
    st->top = -1;
}

bool isEmpty(Stack* st)
{
    return st->top == -1;
}

bool isFull(Stack* st)
{
    return st->top == MAX_SIZE - 1;
}

bool push(Stack* st, int n)
{
    if(isFull(st))
    {   
        printf("Stack is full\n");
        return false;
    }
    st->data[++st->top] = n;
    return true;
}

bool pop(Stack* st, int* n)
{
    if(isEmpty(st))
    {
        printf("Stack is empty\n");
        return false;
    }
    *n = st->data[st->top--];
    return true;
}

bool peek(Stack* st, int* n)
{
    if(isEmpty(st))
    {
        printf("Stack is empty\n");
        return false;
    }
    *n = st->data[st->top];
    return true;
}


int main()
{
    Stack st;
    int top;
    int popEle;
    initialize(&st);
    push(&st, 5);
    push(&st, 4);
    push(&st, 3);
    peek(&st, &top);
    printf("Top element is: %d\n", top);
    pop(&st, &popEle);
    peek(&st, &top);
    printf("Top element is: %d\n", top);
}