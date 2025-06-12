#include "lock free ring buffer.h"

void ringBufferInit(RingBuffer_t *rb)
{
    rb->head = 0;
    rb->tail = 0;
}

bool ringBufferIsEmpty(const RingBuffer_t *rb)
{
    return rb->head == rb->tail;
}

bool ringBufferIsFull(const RingBuffer_t *rb)
{
    return ((rb->head + 1) & (RING_BUFFER_SIZE - 1)) == rb->tail;
}

// Called from ISR
bool ringBufferPush(RingBuffer_t *rb, uint8_t data)
{
    uint8_t nextHead = (rb->head + 1) & (RING_BUFFER_SIZE - 1);

    if (nextHead == rb->tail) {
        // Buffer is full, drop data
        return false;
    }

    rb->buffer[rb->head] = data;
    rb->head = nextHead;
    return true;
}

// Called from main loop
bool ringBufferPop(RingBuffer_t *rb, uint8_t *data)
{
    if (rb->head == rb->tail) {
        // Buffer is empty
        return false;
    }

    *data = rb->buffer[rb->tail];
    rb->tail = (rb->tail + 1) & (RING_BUFFER_SIZE - 1);
    return true;
}
