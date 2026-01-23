#ifndef COURSE_ASSIGNTMENT_UTILS_H
#define COURSE_ASSIGNTMENT_UTILS_H
#include "EventLog.h"
#include "sortAlgo.h"
#include "Event.h"
#include "context.h"

void findSensorId(Context* ctx);
void printSortedLog(sortFunc func, EventLog* log);
void printEvents(EventLog* log);
void normalizeString(char* str);
void trim(char* str);
void forEach(Context* ctx, void(*f)(EventLog* log));
const char* enumToString(sensorType s);
sortFunc chosenSort(Context* ctx);
void clearContext(Context* ctx);
void clearString(char* string);



#endif //COURSE_ASSIGNTMENT_UTILS_H