#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int* array;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity)
{
    Stack* st = (Stack*)malloc(sizeof(Stack));
    st->top = -1;
    st->capacity = capacity;
    // allocate space for array
    st->array = (int*)malloc(sizeof(int) * st->capacity);
    return st;
}

bool isEmpty(Stack* st)
{
    return st->top == -1;
}

void push(Stack* st, int item)
{
    if(st->top == (st->capacity - 1))
    {
        printf("Stack is full\n");
        return;
    }
    st->array[++st->top] = item;
}

int pop(Stack* st)
{
    if(isEmpty(st))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return st->array[st->top--];
}

void enqueue(Stack* st, int item)
{
    push(st, item);
}

int dequeue(Stack* st)
{
    if(isEmpty(st))
    {
        printf("Queue is empty, can not pop\n");
        return -1;
    }
    int item = pop(st);

    // if the stack is empty, return the popped item
    if(isEmpty(st))
    {
        return item;
    }

    // recursively dequeue the remaining item
    int temp = dequeue(st);
    push(st, item);
    return temp;
}

int main()
{
    Stack* stack = createStack(100);

    enqueue(stack, 1);
    enqueue(stack, 2);
    enqueue(stack, 3);

    printf("Dequeued: %d\n", dequeue(stack));
    printf("Dequeued: %d\n", dequeue(stack));

    enqueue(stack, 4);

    printf("Dequeued: %d\n", dequeue(stack));
    printf("Dequeued: %d\n", dequeue(stack));

    free(stack->array);
    free(stack);
    return 0;
}