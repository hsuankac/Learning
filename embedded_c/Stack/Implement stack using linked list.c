#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node* nextNode;
};

struct llStack
{
    struct Node* top;
};

void initialize(struct llStack* st)
{
    st->top = NULL;
}

bool isEmpty(struct llStack* st)
{
    return st->top == NULL;
}

bool push(struct llStack* st, int n)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if(newNode == NULL)
    {
        printf("Unable to allocate memory\n");
        return false;
    }
    newNode->data = n;
    newNode->nextNode = st->top;
    st->top = newNode;
    return true;
}

bool pop(struct llStack* st, int* n)
{
    if(isEmpty(st))
    {
        printf("Stack is empty\n");
        return false;
    }
    struct Node* temp = st->top;
    *n = temp->data;
    st->top = temp->nextNode;
    free(temp);
    return true;
}

bool peek(struct llStack* st, int* n)
{
    if(isEmpty(st))
    {
        printf("Stack is empty\n");
        return false;
    }
    *n = st->top->data;
    return true;
}

void freeStack(struct llStack* st)
{
    struct Node* cur = st->top;
    while(cur)
    {
        struct Node* temp = cur;
        cur = cur->nextNode;
        free(temp);
    }
    st->top = NULL;
}


int main()
{
    struct llStack st;
    int popEle;
    push(&st, 5);
    push(&st, 4);
    push(&st, 3);
    pop(&st, &popEle);
    printf("pop element is: %d\n", popEle);
    return 0;
}