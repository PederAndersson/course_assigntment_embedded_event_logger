#include "../header/ProgramManager.h"

#include <stdio.h>

void printMainMenu() {
    printf("1. Start program.\n"
    "2. Print log\n"
    "3. Sort log.\n"
    "4. Find Sensor.\n"
    "5. Find value.\n"
    "6. Help. \n"
    "7. Exit.\n");
}

void printSubmenu(MenuFunctions m) {
    switch (m) {
        case Run: {
            printf("run program for how many cycles? \n");
            break;
        }
        case PrintLog: {
            printf("Print full log or specific sensor?\n");
            break;
        }
        case SortLog: {
            printf("Sort log by sensor and value using insertion or merge sort.\n");
            break;
        }
        case FindSensorValue: {
            printf("Search for sensordata.\n");
            break;
        }
        case Help: {
            printf ("Help commands.\n");
            break;
        }
        case Exit: {
            printf("Have a nice day\n");
            break;
        }
            default: {printf("Unknown command."); break;}
    }
}

void forEach(EventLog* log, void (*f)(EventLog* log)) {
    EventLog* current = log;
    if (current == NULL){return;}
    while (current->_next != NULL) {
        (*f)(current);
        current = current->_next;
    }
}

void printEvents(EventLog* log) {

    printf("SensorType: %s Id: %d\n", enumToString(log->_node->_sensor), log->_node->_Id);
    printf("Value: %d %s\n", log->_node->_value, log->_node->_unit);
    printf ("Timestamp: %d:%2d:%d\n", log->_node->_timestamp.tm_hour, log->_node->_timestamp.tm_min,log->_node->_timestamp.tm_sec);
}

const char* enumToString(sensorType s) {
    switch (s) {
        case Temperature: { return "Temperature Sensor";}
        case Humidity: {return "Humidity Sensor";}
        case Light: {return "Light Sensor";}
        default: return "Unknown Sensor";
    }
}

MenuFunctions stringToEnum(const char *string[20]) {
}

void run();
