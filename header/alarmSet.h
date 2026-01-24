#ifndef COURSE_ASSIGNTMENT_ALARMSET_H
#define COURSE_ASSIGNTMENT_ALARMSET_H
#include "Event.h"
#include <stdbool.h>

#define MAX_ALARMS 15

typedef struct set{
    int sensorId[MAX_ALARMS];
    int size;
} Alarm;

void alarmInit(Alarm* alarm);
bool containsId(Alarm* alarmSet, Event* e);
bool addAlarm(Alarm* alarmSet, Event* e);
bool removeAlarm(Alarm* alarmSet,Event* e);




#endif //COURSE_ASSIGNTMENT_ALARMSET_H