//
// Created by peder on 2026-01-12.
//

#ifndef COURSE_ASSIGNTMENT_EVENTLOG_H
#define COURSE_ASSIGNTMENT_EVENTLOG_H
#include <stdbool.h>

#include "Event.h"


typedef struct EventLog* logPtr;

typedef struct EventLog {
    Event* _node;
    logPtr _next;
}EventLog;

logPtr createEmptyList(void);
EventLog* newLog(Event *e);
bool isEmpty(logPtr l);
void logDestroyList(logPtr *l);
void logDestroyElement(logPtr *l, Data d);
void logDestroySensor(logPtr *l, sensorType s);
bool logAppend(logPtr *l, Event *e);
int logSize(logPtr l);







#endif //COURSE_ASSIGNTMENT_EVENTLOG_H