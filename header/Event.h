//
// Created by peder on 2026-01-12.
//

#ifndef COURSE_ASSIGNTMENT_EVENT_H
#define COURSE_ASSIGNTMENT_EVENT_H

#include <time.h>

#define SENSOR_NAME_SIZE 20
#define UNIT_SIZE 5


typedef enum Sensor{
    Temperature,
    Humidity,
    Light,
    TYPE_COUNT
} sensorType;

typedef int Data;

typedef struct Event {
    sensorType _sensor;
    int _Id;
    Data _value;
    char _unit[UNIT_SIZE];
    time_t _timestamp;
}Event;

typedef Event* eventPtr;

sensorType randomSensor();

void initRand();

Event* newEvent(sensorType s);


void destroyEvent(eventPtr e);



#endif //COURSE_ASSIGNTMENT_EVENT_H