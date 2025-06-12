#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stdbool.h>

#define RING_BUFFER_SIZE        8   // Must be power of 2

typedef struct {
    volatile uint8_t head;              // write index (ISR)
    volatile uint8_t tail;              // read index (main loop)
    uint8_t buffer[RING_BUFFER_SIZE];   // data buffer
} RingBuffer_t;

void ringBufferInit(RingBuffer_t *rb);
bool ringBufferPush(RingBuffer_t *rb, uint8_t data);
bool ringBufferPop(RingBuffer_t *rb, uint8_t *data);
bool ringBufferIsEmpty(const RingBuffer_t *rb);
bool ringBufferIsFull(const RingBuffer_t *rb);

#endif // RING_BUFFER_H