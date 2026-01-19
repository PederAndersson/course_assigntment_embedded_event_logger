#include "../header/ProgramManager.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

void printMainMenu() {
    printf("1. Start program.\n"
    "2. Print log\n"
    "3. Sort log.\n"
    "4. Find Sensor and value.\n"
    "6. Help. \n"
    "7. Exit.\n\n\n"
    "Input: ");
}

void run(MenuFunctions m, bool *isRunning) {
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
            *isRunning = false;
            break;
        }
        case Unknown: {printf("Unknown command."); break;}
    }
}

void forEach(EventLog* log, void (*f)(EventLog* log)) {
    EventLog* current = log;
    if (current == NULL){return;}
    while (current != NULL) {
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

MenuFunctions stringToEnum(char *string) {
    trim(string);
    normalizeString(string);
    static const cmdEntry Table[] = {
        {._cmd = "run",._m = Run},
        {._cmd = "print",._m =  PrintLog},
        {._cmd = "sort", ._m = SortLog},
        {._cmd = "search",._m =  FindSensorValue},
        {._cmd = "help",._m =  Help},
        {._cmd = "exit",._m =  Exit}
    };
    for (int i = 0; i < (int)(sizeof(Table)/sizeof(Table[0])); i++) {
        if (strcmp(string,Table[i]._cmd) == 0) {
            return Table[i]._m;
        }
    }
    return Unknown;
}

void normalizeString(char *str) {
    for (; *str != '\0'; ++str) {
        *str = (char)tolower((unsigned char)*str);
    }
}

void trim(char *str) {
    size_t len = strlen(str);

    while (len > 0 && isspace((unsigned char) str[len - 1])) {
        str[len - 1] = '\0';
        len--;
    }
}

