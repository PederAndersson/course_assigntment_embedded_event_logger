
#ifndef COURSE_ASSIGNTMENT_OBSERVER_H
#define COURSE_ASSIGNTMENT_OBSERVER_H

#include "alarmSet.h"
#include "context.h"


void notifyAll(Event* e, Context* ctx);
void notifyAlarm(Context* ctx,Event *e);
void notifyLogger(Context* ctx, Event* e);

#endif //COURSE_ASSIGNTMENT_OBSERVER_H