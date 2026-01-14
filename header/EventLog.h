//
// Created by peder on 2026-01-12.
//

#ifndef COURSE_ASSIGNTMENT_EVENTLOG_H
#define COURSE_ASSIGNTMENT_EVENTLOG_H
#include <stdbool.h>

#include "Event.h"

typedef struct EventLog List;
typedef struct EventLog* ListPtr;

typedef struct EventLog {
    Event _node;
    List* _next;
}EventLog;

List* createEmptyList(void);
bool isEmpty(ListPtr l);
void logDestroyList(ListPtr *l);
void logDestroyElement(ListPtr *l, Data d);
void logDestroySensor(ListPtr *l, sensorType s);
void logAppend(ListPtr *l, Event e);
int logSize(ListPtr l);







#endif //COURSE_ASSIGNTMENT_EVENTLOG_H