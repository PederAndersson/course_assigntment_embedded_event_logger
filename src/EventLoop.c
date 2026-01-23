#include "../header/EventLoop.h"



void eventProducer(Queue* q, int amount) {

    for ( int i = 0; i < amount; i++) {
        Event *e = newEvent(randomSensor());

        if (!queueEnqueue(q,e)){ destroyEvent(e);}
    }

}

void eventConsumer(Queue* q, logPtr* log, int amount) {
    for (int i = 0; i < amount; i++) {
        Event* e = NULL;
        if (!queueDequeue(q,&e)){return;}
        if (e == NULL){return;}
        if (!logAppend(log,e)){destroyEvent(e);}
    }
}

