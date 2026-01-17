#include "../header/EventLoop.h"

#include <stdlib.h>


void eventProducer(Queue* q, int amount) {

    for ( int i = 0; i < amount; i++) {
        Event *e = newEvent(randomSensor());
        eventPtr *pe = malloc(sizeof(eventPtr));
        *pe = e;
        if (!queueEnqueue(q,*pe)){ free(e); free(pe);}
    }

}

void eventConsumer(Queue* q, logPtr* log, int amount) {
    for (int i = 0; i < amount; i++) {
        Event* e = NULL;
        if (!queueDequeue(q,&e)){return;}
        if (e == NULL){return;};
        logAppend(log,e);

    }
}

void tick(Queue *q, logPtr* log, int amount) {
    eventProducer(q, amount);
    eventConsumer(q, log, amount);
}