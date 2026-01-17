
#ifndef COURSE_ASSIGNTMENT_EVENTQUEUE_H
#define COURSE_ASSIGNTMENT_EVENTQUEUE_H

#include <stdbool.h>
#include "Event.h"

typedef struct {
    eventPtr* _buffer; //array
    int _writeIdx; // skrivindex
    int _readIdx; // läsindex
    int _capacity; //antal element
    int _count; //antal element kvar att fylla
    bool _full; // flaggar om full
} Queue;


Queue* newQueue(int capacity);
void queueDestroy(Queue* q);
Queue* peek(const Queue* q);
bool queueIsEmpty(const Queue* q);
bool queueIsFull(const Queue* q);
bool queueEnqueue(Queue* q, eventPtr e);
bool queueDequeue(Queue* q, Event** out);
#endif //COURSE_ASSIGNTMENT_EVENTQUEUE_H