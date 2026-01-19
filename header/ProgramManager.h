//
// Created by peder on 2026-01-18.
//

#ifndef COURSE_ASSIGNTMENT_RUNMANAGER_H
#define COURSE_ASSIGNTMENT_RUNMANAGER_H

#define CMD_SIZE 20
#include "EventLog.h"

typedef enum  {
    Run,
    PrintLog,
    SortLog,
    FindSensorValue,
    Help,
    Exit,
    Unknown
}MenuFunctions;

typedef struct {
    const char* _cmd;
    MenuFunctions _m;
} cmdEntry;

void printMainMenu();
void run(MenuFunctions m, bool *isRunning);

void forEach(EventLog* log, void(*f)(EventLog* log));
void printEvents(EventLog* log);
const char* enumToString(sensorType s);
MenuFunctions stringToEnum(char* string);
void normalizeString(char* str);
void trim(char* str);


#endif //COURSE_ASSIGNTMENT_RUNMANAGER_H