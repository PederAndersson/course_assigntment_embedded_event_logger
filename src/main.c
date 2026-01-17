#include <stdio.h>
#include <stdlib.h>


#include "../header/Event.h"
#include "../header/EventLog.h"
#include "../header/EventQueue.h"
#include "../header/EventLoop.h"

const char* enumToString(sensorType s) {
    switch (s) {
        case Temperature: { return "Temperature Sensor";}
        case Humidity: {return "Humidity Sensor";}
        case Light: {return "Light Sensor";}
            default: return "Unknown Sensor";
    }
}

void printEvents(EventLog* log) {

        printf("SensorType: %s Id: %d\n", enumToString(log->_node->_sensor), log->_node->_Id);
        printf("Value: %d %s\n", log->_node->_value, log->_node->_unit);
        printf ("Timestamp: %d:%2d:%d\n", log->_node->_timestamp.tm_hour, log->_node->_timestamp.tm_min,log->_node->_timestamp.tm_sec);

}

void forEach(EventLog* log, void (*f)(EventLog* log)) {
    EventLog* current = log;
    if (current == NULL){return;}
    while (current->_next != NULL) {
        (*f)(current);
        current = current->_next;
    }
}

int main(void) {
    initRand();
    int arrayCapacity = 100;
    Queue* queue = newQueue(arrayCapacity);
    EventLog* log = createEmptyList();
    tick(queue,&log,15);

    forEach(log, printEvents);

    logDestroyList(&log);
    queueDestroy(queue);
    return 0;
}
