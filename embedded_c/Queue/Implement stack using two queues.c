#include <stdio.h>
#include <stdlib.h>

// Node for queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Stack structure (built using two queues)
typedef struct Stack {
    Queue* q1;
    Queue* q2;
} Stack;

// Queue functions
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(Queue* q) {
    if (q->front == NULL) return -1;
    Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return val;
}

int isEmptyQueue(Queue* q) {
    return q->front == NULL;
}

int front(Queue* q) {
    return (q->front != NULL) ? q->front->data : -1;
}

// Stack functions
Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->q1 = createQueue();
    s->q2 = createQueue();
    return s;
}

void push(Stack* s, int val) {
    enqueue(s->q2, val);

    while (!isEmptyQueue(s->q1)) {
        enqueue(s->q2, dequeue(s->q1));
    }

    // Swap q1 and q2
    Queue* temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}

int pop(Stack* s) {
    return dequeue(s->q1);
}

int top(Stack* s) {
    return front(s->q1);
}

int isEmpty(Stack* s) {
    return isEmptyQueue(s->q1);
}

void freeStack(Stack* s) {
    while (!isEmpty(s))
        pop(s);
    free(s->q1);
    free(s->q2);
    free(s);
}

int main() {
    Stack* s = createStack();

    push(s, 10);
    push(s, 20);
    push(s, 30);

    printf("Top: %d\n", top(s));      // 30
    printf("Popped: %d\n", pop(s));   // 30
    printf("Top: %d\n", top(s));      // 20

    freeStack(s);
    return 0;
}