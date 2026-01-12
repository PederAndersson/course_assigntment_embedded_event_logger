//
// Created by peder on 2026-01-12.
//

#ifndef COURSE_ASSIGNTMENT_EVENT_H
#define COURSE_ASSIGNTMENT_EVENT_H


typedef enum Sensor{
    Temperature,
    Humidity,
    Light,
    TYPE_COUNT
} sensorType;

#define SENSOR_NAME_SIZE 20
#define UNIT_SIZE 5

struct Data {
    int _value;
    char _unit[UNIT_SIZE];
};

struct Node {
    char _sensor[SENSOR_NAME_SIZE];
    int _Id;
    struct Data _data;
    struct tm *_timestamp;
    struct Node* _next;
    //struct Node* _previous;
};

struct tm* currentTime();

sensorType randomSensor();

void initRand();





#endif //COURSE_ASSIGNTMENT_EVENT_H