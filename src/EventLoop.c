#include "../header/EventLoop.h"




void eventProducer(Queue* q, int amount) {

    for ( int i = 0; i < amount; i++) {
        Event *e = newEvent(randomSensor());

        if (!queueEnqueue(q,e)){ destroyEvent(e);}
    }

}

void eventConsumer(Queue* q, Context* ctx, int amount) {
    if (!q || !ctx || amount <= 0){return;}
    for (int i = 0; i < amount; i++) {
        Event* e = NULL;
        if (!queueDequeue(q,&e) || e == NULL ){break;}
        notifyAll(e,ctx);
    }
}

