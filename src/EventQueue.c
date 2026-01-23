#include "../header/EventQueue.h"

#include <stdlib.h>

static Queue* queueInit(int capacity) {
    Queue* ringBuffer = malloc(sizeof(Queue));
    ringBuffer->_buffer = (eventPtr*)malloc(sizeof(Event*) * capacity);
    ringBuffer->_capacity = capacity;
    ringBuffer->_count = 0;
    ringBuffer->_readIdx = 0;
    ringBuffer->_writeIdx = 0;
    return ringBuffer;
}

Queue* newQueue(int capacity) {
    Queue* ringbuffer = queueInit(capacity);
    return ringbuffer;
}

void queueDestroy(Queue* q) {
    free(q->_buffer);
    free(q);
}


bool queueIsEmpty(const Queue *q) {
    return q->_count == 0;
}

bool queueIsFull(const Queue *q) {
    return  q->_count == q->_capacity;
}

bool queueEnqueue( Queue *q, eventPtr e) {
    if (queueIsFull(q)) return false;
    q->_buffer[q->_writeIdx] = e;
    q->_writeIdx = (q->_writeIdx + 1) % q->_capacity;
    q->_count++;
    return true;
}

bool queueDequeue(Queue *q, Event **out) {
    if (queueIsEmpty(q)) return false;
    *out = q->_buffer[q->_readIdx];
    q->_buffer[q->_readIdx] = NULL;
    q->_readIdx = (q->_readIdx + 1) % q->_capacity;
    q->_count--;
    return true;
}
