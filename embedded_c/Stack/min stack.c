// https://leetcode.com/problems/min-stack/description/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE            1000

typedef struct
{
    int data[MAX_SIZE];
    int minData[MAX_SIZE];
    int topIndex;
} MinStack;

// Initialization the stack
void minStackInit(MinStack* stack)
{
    stack->topIndex = -1;
}

// Push an element onto the stack
void minStackPush(MinStack* stack, int x)
{
    if(stack->topIndex == MAX_SIZE - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    stack->topIndex++;
    stack->data[stack->topIndex] = x;
    if(stack->topIndex == 0)
    {
        stack->minData[stack->topIndex] = x;
    }
    else
    {
        stack->minData[stack->topIndex] = x < stack->minData[stack->topIndex - 1] ? x : stack->minData[stack->topIndex - 1];
    }
}

// Pop an element from the stack
void minStackPop(MinStack* stack) {
    if (stack->topIndex == -1) {
        printf("Stack underflow\n");
        return;
    }
    stack->topIndex--;
}

// Get the top element
int minStackTop(MinStack* stack) {
    if (stack->topIndex == -1) {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return stack->data[stack->topIndex];
}

// Retrieve the minimum element
int minStackGetMin(MinStack* stack) 
{
    if (stack->topIndex == -1) {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return stack->minData[stack->topIndex];
}

int main() {
    MinStack stack;
    minStackInit(&stack);

    minStackPush(&stack, 3);
    minStackPush(&stack, 5);
    printf("Min: %d\n", minStackGetMin(&stack)); // 3

    minStackPush(&stack, 2);
    minStackPush(&stack, 1);
    printf("Min: %d\n", minStackGetMin(&stack)); // 1

    minStackPop(&stack);
    printf("Min: %d\n", minStackGetMin(&stack)); // 2

    printf("Top: %d\n", minStackTop(&stack));    // 2

    return 0;
}