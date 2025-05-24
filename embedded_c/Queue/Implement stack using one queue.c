// Implementing Stack using Queue
#include <stdio.h>
#include <stdlib.h>

// structure to represent a node
struct Node
{
    int data;
    struct Node* next;
};

struct Queue
{
    struct Node* front;
    struct Node* rear;
};

// function to create a new queue
struct Queue* createQueue(void)
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if(!queue)
    {
        perror("Error allocating memory to create queue");
        exit(EXIT_FAILURE);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

// function to create a new node
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) 
{
    return (queue->front == NULL);
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* queue, int data) 
{
    struct Node* newNode = createNode(data);
    if (isEmpty(queue)) 
    {
        queue->front = queue->rear = newNode;
    } 
    else 
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    int data = queue->front->data;
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    return data;
}

// Function to push an item onto the stack
void push(struct Queue* queue, int value) 
{
    enqueue(queue, value);
}

// Function to pop an item from the stack
int pop(struct Queue* queue) {
    struct Queue* tempQueue = createQueue();
    int poppedItem;

    while (!isEmpty(queue)) 
    {
        int item = dequeue(queue);
        if (isEmpty(queue)) 
        {
            poppedItem = item;
        } 
        else 
        {
            enqueue(tempQueue, item);
        }
    }

    while (!isEmpty(tempQueue)) 
    {
        enqueue(queue, dequeue(tempQueue));
    }

    free(tempQueue);
    return poppedItem;
}

// Function to free all nodes in the queue and the queue itself
void freeQueue(struct Queue* queue) 
{
    while (!isEmpty(queue)) {
        dequeue(queue);  // this already frees each node
    }
    free(queue); // finally free the queue struct
}

int main() {
    
    struct Queue* stack = createQueue();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("Popped element: %d\n", pop(stack));
    printf("Popped element: %d\n", pop(stack));

    push(stack, 4);

    printf("Popped element: %d\n", pop(stack));
    printf("Popped element: %d\n", pop(stack));

    freeQueue(stack);
    return 0;
    return 0;
}