#include "../header/Utils.h"

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void findSensorId(Context* ctx) {
    assert(ctx != NULL);
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
    assert(func != NULL);
    assert(log != NULL);
    int size = 0;
    Event** tempArr = func(log, &size);
    for (int i = 0; i < size; i++) {
        printf("sensor: %s Id: %d\n", enumToString(tempArr[i]->_sensor), tempArr[i]->_Id);
        printf("Value : %d %s\n", tempArr[i]->_value, tempArr[i]->_unit);
        convertTime(&log->_node->_timestamp);
    }
    free(tempArr);
}


void printEvents(EventLog* log) {
    assert(log != NULL);
    assert(log->_node != NULL);
    printf("SensorType: %s Id: %d\n", enumToString(log->_node->_sensor), log->_node->_Id);
    printf("Value: %d %s\n", log->_node->_value, log->_node->_unit);
    convertTime(&log->_node->_timestamp);
}

void normalizeString(char *str) {
    assert(str != NULL);
    for (; *str != '\0'; ++str) {
        *str = (char)tolower((unsigned char)*str);
    }
}


void trim(char *str) {
    assert(str != NULL);
    size_t len = strlen(str);

    while (len > 0 && isspace((unsigned char) str[len - 1])) {
        str[len - 1] = '\0';
        len--;
    }
}

void forEach(Context* ctx, void (*f)(EventLog* log)) {
    assert(ctx != NULL);
    assert(f != NULL);
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

    while (strcmp(ctx->argString, "merge") != 0 && strcmp(ctx->argString, "insertion")!= 0) {
        printf("Algorithms available: merge or insertion.\n"
        "Input: ");
        clearString(ctx->argString);
        char string[BUFFER_SIZE];
        fgets (string,BUFFER_SIZE,stdin);
        trim(string);
        memcpy(ctx->argString, string, strlen(string));
    }
    if (strcmp(ctx->argString, "merge") == 0) {
        chosen = mergeSort;
    }
    else if (strcmp(ctx->argString, "insertion") == 0) {
        chosen = insertionSort;
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

void convertTime(time_t* t) {
    assert(t != NULL);
    struct tm *currentTime = localtime(t);
    printf("%d:%d:%d\n",currentTime->tm_hour,currentTime->tm_min,currentTime->tm_sec);
}

void parseString(char* string, Context* ctx) {
    assert(string != NULL);
    assert(ctx != NULL);
    int strIdx = 0;
    int cmdIdx = 0;
    int argIdx = 0;

    while (string[strIdx] == ' ' || string[strIdx] == '\t') {
        strIdx++;
    }

    while (string[strIdx] != ' '  && string[strIdx] != '\t' && string[strIdx] != '\0' && string[strIdx] != '\n') {
        if (cmdIdx >= BUFFER_SIZE-1){break;}
        ctx->cmdstring[cmdIdx++] = (char)tolower((unsigned char)string[strIdx++]);
    }
    ctx->cmdstring[cmdIdx] = '\0';
    while (string[strIdx] == ' ' || string[strIdx] == '\t') {
        strIdx++;
    }
    if (strcmp(ctx->cmdstring,"sort") == 0) {
        while (string[strIdx] != ' '  && string[strIdx] != '\t' && string[strIdx] != '\0' && string[strIdx] != '\n') {
            if (argIdx >= BUFFER_SIZE-1){break;}
            ctx->argString[argIdx++] = (char)tolower((unsigned char)string[strIdx++]);
        }
        ctx->argString[argIdx] = '\0';
    }

    else if (strcmp(ctx->cmdstring,"find") == 0) {
        char temp[BUFFER_SIZE];
        int idx = 0;
        while (string[strIdx] != ' '  && string[strIdx] != '\t' && string[strIdx] != '\0' && string[strIdx] != '\n' && idx < BUFFER_SIZE-1) {
            temp[idx++] = string[strIdx++];
        }
        temp[idx] = '\0';
        char* end = NULL;
        int value = (int)strtol(temp, &end, 10);
        if (end == temp) {
            ctx->id = -1;
        } else {
            ctx->id = value;
        }
    }else if (strcmp(ctx->cmdstring,"tick") == 0) {
        char temp[BUFFER_SIZE];
        int idx = 0;
        while (string[strIdx] != ' '  && string[strIdx] != '\t' && string[strIdx] != '\0' && string[strIdx] != '\n' && idx < BUFFER_SIZE-1) {
            temp[idx++] = string[strIdx++];
        }
        temp[idx] = '\0';
        char* end = NULL;
        int value = (int)strtol(temp, &end, 10);
        if (end == temp) {
            ctx->ammount = -1;
        } else {
            ctx->ammount = value;
        }
    }
}