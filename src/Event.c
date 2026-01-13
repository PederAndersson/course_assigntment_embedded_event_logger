#include "../header/Event.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct tm* currentTime() {
    time_t now = time(NULL);
    struct tm *time = localtime(&now);
    return time;
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
    if (!event) return 0;
    event->_timestamp = currentTime();

    switch (s) {
        case Temperature : {
            strncpy(event->_sensor,"Temperature Sensor",SENSOR_NAME_SIZE);
            strncpy(event->_unit, "C", UNIT_SIZE);
            event->_value = rand() % 35 + 18;
            event->_Id = TEMP_ID;
            return event;

        }
        case Humidity : {
            strncpy(event->_sensor, "Humidity Sensor", SENSOR_NAME_SIZE);
            strncpy(event->_unit, "%", UNIT_SIZE);
            event->_value = rand() % 85 + 40;
            event->_Id = HUM_ID;
            return event;

        }
        case Light : {
            strncpy(event->_sensor, "Light Sensor",SENSOR_NAME_SIZE);
            strncpy(event->_unit, "lx", UNIT_SIZE);
            event->_value = rand() % 450 + 250 ;
            event->_Id = LIGHT_ID;
            return event;
        }
            default: {return NULL;}
    }
}
