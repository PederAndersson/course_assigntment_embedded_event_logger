#include "../header/Observer.h"

void notifyAll(Event *e, Context* ctx ) {

    notifyAlarm(ctx,e);
    notifyLogger(ctx,e);
}

void notifyAlarm(Context* ctx, Event *e) {
    if (!ctx || !ctx->alarm || !e) return;
    if (e->_Id > 0 && e->_Id <= 5) {
        if (e->_value > 30) addAlarm(ctx->alarm, e);
        else                removeAlarm(ctx->alarm, e);
    }
    else if (e->_Id >= 6 && e->_Id <= 10) {
        if (e->_value > 60) addAlarm(ctx->alarm, e);
        else                removeAlarm(ctx->alarm, e);
    }
    else if (e->_Id >= 11 && e->_Id <= 15) {
        if (e->_value > 350) addAlarm(ctx->alarm, e);
        else                 removeAlarm(ctx->alarm, e);
    }

}


void notifyLogger(Context* ctx, Event *e) {
    if (!logAppend(&ctx->log,e)){destroyEvent(e);}
}

