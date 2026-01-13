//
// Created by peder on 2026-01-12.
//

#ifndef COURSE_ASSIGNTMENT_EVENTLOG_H
#define COURSE_ASSIGNTMENT_EVENTLOG_H
#include <stdbool.h>

#include "Event.h"

typedef struct EventLog List;
typedef struct EventLog {
    Event _node;
    List* _next;
}EventLog;

List* createEmptylist(void);
bool isEmpty(List *l);
void logDestroyList(List *l);
void logDestroyElement(List *l, Data d);
void logDestroySensor(List *l, sensorType s);
void logAppend(List *l, Event e);
int logSize(List* l);
Event logGetData(List l,Data d );
Event logGetSensor(List l, sensorType s);






#endif //COURSE_ASSIGNTMENT_EVENTLOG_H