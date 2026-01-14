//
// Created by peder on 2026-01-12.
//

#ifndef COURSE_ASSIGNTMENT_EVENT_H
#define COURSE_ASSIGNTMENT_EVENT_H

#include <time.h>

#define SENSOR_NAME_SIZE 20
#define UNIT_SIZE 5
#define TEMP_ID 1
#define HUM_ID 2
#define LIGHT_ID 3

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
    struct tm _timestamp;
}Event;

sensorType randomSensor();

void initRand();

Event* newEvent(sensorType s);





#endif //COURSE_ASSIGNTMENT_EVENT_H