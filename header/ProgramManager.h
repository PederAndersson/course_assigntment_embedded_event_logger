//
// Created by peder on 2026-01-18.
//

#ifndef COURSE_ASSIGNTMENT_RUNMANAGER_H
#define COURSE_ASSIGNTMENT_RUNMANAGER_H

#include "Utils.h"
#include "EventLoop.h"



void printMainMenu();
void run(Context* ctx);
void parseString(char* string, Context* ctx);
void help();
void tick(Context* ctx);
void print(Context* ctx);
void sort(Context* ctx);
void findId(Context* ctx);
void quit(Context* ctx);
void printActivAlarm(Context* ctx);



#endif //COURSE_ASSIGNTMENT_RUNMANAGER_H