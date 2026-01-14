#include "../header/Event.h"

#include <stdlib.h>
#include <string.h>


static struct tm currentTime() {
    time_t now = time(NULL);
    struct tm t = *localtime(&now);
    return t;
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

    switch (s) {
        case Temperature : {
            event->_sensor = Temperature;
            strncpy(event->_unit, "C", UNIT_SIZE);
            event->_unit[UNIT_SIZE-1] = '\0';
            event->_value = rand() % 35 + 18;
            event->_Id = TEMP_ID;
            break;

        }
        case Humidity : {
            event->_sensor = Humidity;
            strncpy(event->_unit, "%", UNIT_SIZE);
            event->_unit[UNIT_SIZE-1] = '\0';
            event->_value = rand() % 85 + 40;
            event->_Id = HUM_ID;
            break;

        }
        case Light : {
            event->_sensor = Light;
            strncpy(event->_unit, "lx", UNIT_SIZE);
            event->_unit[UNIT_SIZE-1] = '\0';
            event->_value = rand() % 450 + 250 ;
            event->_Id = LIGHT_ID;
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
