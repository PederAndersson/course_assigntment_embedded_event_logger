#include "../header/EventQueue.h"

#include <stdlib.h>

static Queue* queueInit(int capacity) {
    Queue* ringBuffer = {};
    ringBuffer->_buffer = (Event*)malloc(sizeof(Event) * capacity);
    ringBuffer->_capacity = capacity;
    ringBuffer->_count = 0;
    ringBuffer->_readIdx = 0;
    ringBuffer->_writeIdx = 0;
    ringBuffer->_full = false;
    return ringBuffer;
}

Queue* newBuffer(int capacity) {
    Queue* ringbuffer = queueInit(capacity);
    return ringbuffer;
}

void queueDestroy(Queue* q) {
    free(q);
}

void peek(Queue* const q) {
    bool full = q->_full;
    int spaceLeft = q->_capacity - q->_count;
    Event data = q->_buffer[q->_readIdx];
}

bool queueIsEmpty(const Queue *q) {
    return q->_count == 0;
}

bool queueIsFull(const Queue *q) {
    return  q->_count == q->_capacity;
}

bool queueEnqueue( Queue *q, const Event e) {
    if (queueIsFull(q)) return false;
    q->_buffer[q->_writeIdx] = e;
    q->_writeIdx++;
    q->_count++;
    return true;
}

bool queueDequeue(Queue *q, Event* out) {
    if (queueIsEmpty(q)) return false;
    *out = q->_buffer[q->_readIdx];
    q->_readIdx++;
    q->_count--;
    return true;
}
