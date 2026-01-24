//
// Created by peder on 2026-01-12.
//

#ifndef COURSE_ASSIGNTMENT_EVENTLOOP_H
#define COURSE_ASSIGNTMENT_EVENTLOOP_H


#include "EventLog.h"
#include "EventQueue.h"
#include "../header/Observer.h"


void eventProducer(Queue* q, int amount);
void eventConsumer(Queue* q, Context* ctx, int amount);

#endif //COURSE_ASSIGNTMENT_EVENTLOOP_H