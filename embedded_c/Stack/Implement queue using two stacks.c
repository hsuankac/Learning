#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

typedef struct {
    Stack s1;
    Stack s2;
} Queue;


void initStack(Stack* s) {
    s->top = -1;
}

bool isStackEmpty(Stack* s) {
    return s->top == -1;
}

bool isStackFull(Stack* s) {
    return s->top == MAX - 1;
}

bool push(Stack* s, int val) {
    if (isStackFull(s)) return false;
    s->data[++(s->top)] = val;
    return true;
}

bool pop(Stack* s, int* val) {
    if (isStackEmpty(s)) return false;
    *val = s->data[(s->top)--];
    return true;
}

bool peek(Stack* s, int* val) {
    if (isStackEmpty(s)) return false;
    *val = s->data[s->top];
    return true;
}

void initQueue(Queue* q) {
    initStack(&q->s1);
    initStack(&q->s2);
}

// Enqueue operation (O(1))
bool enqueue(Queue* q, int value) {
    return push(&q->s1, value);
}

// Dequeue operation (Amortized O(1), worst O(n))
bool dequeue(Queue* q, int* val) {
    if (isStackEmpty(&q->s2)) 
    {
        int temp;
        while (!isStackEmpty(&q->s1)) {
            pop(&q->s1, &temp);
            push(&q->s2, temp);
        }
    }
    return pop(&q->s2, val);
}

// Peek front element
bool front(Queue* q, int* val) {
    if (isStackEmpty(&q->s2)) {
        int temp;
        while (!isStackEmpty(&q->s1)) {
            pop(&q->s1, &temp);
            push(&q->s2, temp);
        }
    }
    return peek(&q->s2, val);
}

// Check if queue is empty
bool isQueueEmpty(Queue* q) {
    return isStackEmpty(&q->s1) && isStackEmpty(&q->s2);
}

int main() 
{
    Queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    int val;
    dequeue(&q, &val);  printf("Dequeued: %d\n", val); // 10
    front(&q, &val);    printf("Front: %d\n", val);    // 20

    enqueue(&q, 40);
    while (!isQueueEmpty(&q)) {
        dequeue(&q, &val);
        printf("Dequeued: %d\n", val);
    }

    return 0;
}