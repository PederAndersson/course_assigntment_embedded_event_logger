#include "../header/Event.h"

#include <stdlib.h>
#include <string.h>


time_t currentTime() {
    time_t now = time(NULL);

    return now;
}

sensorType randomSensor() {
    int sensor = rand() % 3;
    return sensor;
}

void initRand() {
    srand(time(NULL));
}


static Event* createEvent(sensorType s) {
    Event* event = malloc(sizeof(Event));
    if (!event) return NULL;

    switch (s) {
        case Temperature : {
            event->_sensor = Temperature;
            strncpy(event->_unit, "C", UNIT_SIZE);
            event->_unit[UNIT_SIZE-1] = '\0';
            event->_value = rand() % 42 + 18;
            event->_Id = rand() % 5 + 1;
            break;

        }
        case Humidity : {
            event->_sensor = Humidity;
            strncpy(event->_unit, "%", UNIT_SIZE);
            event->_unit[UNIT_SIZE-1] = '\0';
            event->_value = rand() % 44 + 40;
            event->_Id = rand()% 5 + 6;
            break;

        }
        case Light : {
            event->_sensor = Light;
            strncpy(event->_unit, "lx", UNIT_SIZE);
            event->_unit[UNIT_SIZE-1] = '\0';
            event->_value = rand() % 201 + 250 ;
            event->_Id = rand() % 5 + 11;
            break;
        }
            default: {free(event); return NULL;}
    }
    event->_timestamp = currentTime();
    return event;
}

Event* newEvent(sensorType s) {
    Event *newEvent = createEvent(s);
    return newEvent;
}

void destroyEvent(eventPtr e) {
    free(e);
}