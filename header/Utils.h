#ifndef COURSE_ASSIGNTMENT_UTILS_H
#define COURSE_ASSIGNTMENT_UTILS_H
#include "EventLog.h"
#include "sortAlgo.h"
#include "Event.h"
#include "context.h"

void findSensorId(const Context* ctx);
void printSortedLog(sortFunc func, EventLog* log);
void printEvents(const EventLog* log);
void normalizeString(char* str);
void trim(char* str);
void forEach(const Context* ctx, void(*f)(const EventLog* log));
const char* enumToString(sensorType s);
sortFunc chosenSort(Context* ctx);
void clearContext(Context* ctx);
void clearString(char* string);
void convertTime(time_t t);
void parseString(const char* string, Context* ctx);



#endif //COURSE_ASSIGNTMENT_UTILS_H