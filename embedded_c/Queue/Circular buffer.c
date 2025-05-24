#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5

struct CircularBuffer {
    int buffer[SIZE];
    int head;
    int tail;
    int count;
};

void initBuffer(struct CircularBuffer* cb) {
    cb->head = cb->tail = cb->count = 0;
}

bool isFull(struct CircularBuffer* cb) {
    return cb->count == SIZE;
}

bool isEmpty(struct CircularBuffer* cb) {
    return cb->count == 0;
}

void enqueueCB(struct CircularBuffer* cb, int value) {
    if (isFull(cb)) {
        fprintf(stderr, "Buffer overflow\n");
        return;
    }
    cb->buffer[cb->tail] = value;
    cb->tail = (cb->tail + 1) % SIZE;
    cb->count++;
}

int dequeueCB(struct CircularBuffer* cb) {
    if (isEmpty(cb)) {
        fprintf(stderr, "Buffer underflow\n");
        exit(EXIT_FAILURE);
    }
    int value = cb->buffer[cb->head];
    cb->head = (cb->head + 1) % SIZE;
    cb->count--;
    return value;
}

int main() {
    struct Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    printf("Dequeued: %d\n", dequeue(q));
    freeQueue(q);
}