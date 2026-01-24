#ifndef COURSE_ASSIGNTMENT_CONTEXT_H
#define COURSE_ASSIGNTMENT_CONTEXT_H

#include "EventLog.h"
#include "EventQueue.h"
#include "alarmSet.h"

#define BUFFER_SIZE 50
typedef struct {
    EventLog* log;
    Queue* queue;
    bool* Running;
    Alarm* alarm;
    long id;
    long ammount;
    char cmdstring[BUFFER_SIZE];
    char argString[BUFFER_SIZE];
}Context;

#endif //COURSE_ASSIGNTMENT_CONTEXT_H