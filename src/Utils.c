#include "../header/Utils.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void findSensorId(Context* ctx) {
    int id = ctx->id;
    int prints = 0;

    for (EventLog* cur = (ctx->log); cur != NULL; cur = cur->_next) {
        if (cur->_node->_Id == id) {
            printEvents(cur);
            prints++;
        }
    }
    if (prints == 0) puts("No sensors found.");
}

void printSortedLog(sortFunc func, EventLog *log) {
    int size = 0;
    Event** tempArr = func(log, &size);
    for (int i = 0; i < size; i++) {
        printf("sensor: %s Id: %d\n", enumToString(tempArr[i]->_sensor), tempArr[i]->_Id);
        printf("Value : %d %s\n", tempArr[i]->_value, tempArr[i]->_unit);
        printf("time: %d:%d:%d\n", tempArr[i]->_timestamp.tm_hour, tempArr[i]->_timestamp.tm_min, tempArr[i]->_timestamp.tm_sec);
    }
    free(tempArr);
}


void printEvents(EventLog* log) {

    printf("SensorType: %s Id: %d\n", enumToString(log->_node->_sensor), log->_node->_Id);
    printf("Value: %d %s\n", log->_node->_value, log->_node->_unit);
    printf ("Timestamp: %d:%2d:%d\n", log->_node->_timestamp.tm_hour, log->_node->_timestamp.tm_min,log->_node->_timestamp.tm_sec);
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

void forEach(Context* ctx, void (*f)(EventLog* log)) {
    EventLog* current = ctx->log;
    if (current == NULL){return;}
    while (current != NULL) {
        (*f)(current);
        current = current->_next;
    }
}

const char* enumToString(sensorType s) {
    switch (s) {
        case Temperature: { return "Temperature Sensor";}
        case Humidity: {return "Humidity Sensor";}
        case Light: {return "Light Sensor";}
        default: return "Unknown Sensor";
    }
}

sortFunc chosenSort(Context *ctx) {
    sortFunc chosen = {};
    if (strcmp(ctx->argString, "merge") == 0) {
        chosen = mergeSort;
    }
    else if (strcmp(ctx->argString, "insertion") == 0) {
        chosen = insertionSort;
    }else {
        printf("Algorithms available: merge or insertion.");
    }
    return chosen;
}

void clearContext(Context *ctx) {
    ctx->ammount = 0;
    ctx->id = 0;
    clearString(ctx->argString);
    clearString(ctx->cmdstring);
}

void clearString(char *string) {
    for (int i = 0; i < BUFFER_SIZE; i++) {
        string[i] = '\0';
    }
}
