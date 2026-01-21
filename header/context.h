#ifndef COURSE_ASSIGNTMENT_CONTEXT_H
#define COURSE_ASSIGNTMENT_CONTEXT_H

#include "ProgramManager.h"
#include "EventQueue.h"
typedef struct {
    EventLog* log;
    Event* Event;
    Queue* queue;
    bool* Running;
}Context;

#endif //COURSE_ASSIGNTMENT_CONTEXT_H