#include "../header/EventQueue.h"

#include <assert.h>
#include <stdlib.h>

static Queue* queueInit(int capacity) {
    assert(capacity > 0);
    Queue* ringBuffer = malloc(sizeof(Queue));
    assert( ringBuffer != NULL);
    ringBuffer->_buffer = (eventPtr*)malloc(sizeof(Event*) * capacity);
    assert(ringBuffer->_buffer != NULL);
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
    assert(q != NULL);
    free(q->_buffer);
    free(q);
}


bool queueIsEmpty(const Queue *q) {
    assert(q != NULL);
    return q->_count == 0;
}

bool queueIsFull(const Queue *q) {
    assert(q != NULL);
    return  q->_count == q->_capacity;
}

bool queueEnqueue( Queue *q, eventPtr e) {
    assert(q != NULL);
    assert(e != NULL);
    assert(q->_count >= 0 && q->_count <= q->_capacity);
    if (queueIsFull(q)) return false;
    q->_buffer[q->_writeIdx] = e;
    q->_writeIdx = (q->_writeIdx + 1) % q->_capacity;
    q->_count++;
    return true;
}

bool queueDequeue(Queue *q, Event **out) {
    assert(q != NULL);
    assert(out != NULL);
    assert(q->_count >= 0 && q->_count <= q->_capacity);
    if (queueIsEmpty(q)) return false;
    *out = q->_buffer[q->_readIdx];
    q->_buffer[q->_readIdx] = NULL; // empties the queue so only the log has final ownership of the event pointers
    q->_readIdx = (q->_readIdx + 1) % q->_capacity;
    q->_count--;
    return true;
}
