//
// Created by peder on 2026-01-18.
//

#ifndef COURSE_ASSIGNTMENT_RUNMANAGER_H
#define COURSE_ASSIGNTMENT_RUNMANAGER_H

#include "EventLog.h"

typedef enum  {
    Run,
    PrintLog,
    SortLog,
    FindSensorValue,
    Help,
    Exit,
}MenuFunctions;

void run(MenuFunctions m);
void printMainMenu();
void printSubmenu(MenuFunctions m);

void forEach(EventLog* log, void(*f)(EventLog* log));
void printEvents(EventLog* log);
const char* enumToString(sensorType s);
MenuFunctions stringToEnum(const char* string[20]);


#endif //COURSE_ASSIGNTMENT_RUNMANAGER_H