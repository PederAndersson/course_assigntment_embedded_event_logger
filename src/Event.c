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


static struct Node* createNode(sensorType s) {
    struct Node* node = malloc(sizeof(struct Node));
    if (!node) return 0;
    node->_timestamp = currentTime();

    switch (s) {
        case Temperature : {
            strncpy(node->_sensor,"Temperature Sensor",SENSOR_NAME_SIZE);
            strncpy(node->_data._unit, "C", UNIT_SIZE);
            int sensorId = 1;
            node->_data._value = rand() % 35 + 18;
            node->_Id = sensorId;
            node->_next = NULL;
            //node->_previous = NULL;
            return node;

        }
        case Humidity : {
            strncpy(node->_sensor, "Humidity Sensor", SENSOR_NAME_SIZE);
            strncpy(node->_data._unit, "%", UNIT_SIZE);
            int sensorId = 2;
            node->_data._value = rand() % 85 + 40;
            node->_Id = sensorId;
            node->_next = NULL;
            //node->_previous = NULL;
            return node;

        }
        case Light : {
            strncpy(node->_sensor, "Light Sensor",SENSOR_NAME_SIZE);
            strncpy(node->_data._unit, "lx", UNIT_SIZE);
            int sensorId = 3;
            node->_data._value = rand() % 450 + 250 ;
            node->_Id = sensorId;
            node->_next = NULL;
            //node->_previous = NULL;
            return node;
        }
            default: {return NULL;}
    }
}
