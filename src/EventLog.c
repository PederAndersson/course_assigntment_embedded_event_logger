//
// Created by peder on 2026-01-12.
//
#include <stddef.h>
#include <stdlib.h>

#include "../header/EventLog.h"

#include <assert.h>


static EventLog* createLog(Event *e) {
    EventLog* event_log = malloc(sizeof(EventLog));
    if (!event_log){ return NULL;}
    event_log->_node = e;
    event_log->_next = NULL;

    return event_log;
}

EventLog* newLog(Event * e) {
    EventLog* logg = createLog(e);
    return logg;
}

EventLog* createEmptyList(void) {
    return NULL;
}

bool isEmpty(logPtr l) {
    if (l == NULL) return true;
    return false;
}


void logDestroyList(logPtr *l) {
    assert(l != NULL);

    while (*l != NULL) {
        EventLog* listToRemove = *l;
        (*l) = (*l)->_next;
        destroyEvent(listToRemove->_node);
        free(listToRemove);
    }
    assert(isEmpty(*l));
}

void logDestroyElement(logPtr* l, const Data d ) {
    assert(l != NULL);
    if (isEmpty(*l)) return;
    while (*l != NULL && (*l)->_node->_value == d) {
        EventLog* logToRemove = *l;
        (*l) = (*l)->_next;
        destroyEvent(logToRemove->_node);
        free(logToRemove);
    }
    logPtr CurrentNode = *l;
    if (isEmpty(CurrentNode)) return;
    while (CurrentNode->_next != NULL) {
        if (CurrentNode->_next->_node->_value == d) {
            EventLog* logToRemove = CurrentNode->_next;
            CurrentNode->_next = logToRemove->_next;
            destroyEvent(logToRemove->_node);
            free(logToRemove);
        }else {
            CurrentNode = CurrentNode->_next;
        }
    }
}

void logDestroySensor(logPtr*l, sensorType s) {
    assert(l != NULL);
    if (isEmpty(*l)) return;

    while (*l != NULL && (*l)->_node->_sensor == s) {
        EventLog* logToRemove = *l;
        (*l) = (*l)->_next;
        destroyEvent(logToRemove->_node);
        free(logToRemove);
    }

    EventLog* currentLog = *l;
    if (isEmpty(currentLog)) return;
    while (currentLog->_next != NULL) {
        if (currentLog->_next->_node->_sensor == s) {
            EventLog* logToRemove = currentLog->_next;
            currentLog->_next = logToRemove->_next;
            destroyEvent(logToRemove->_node);
            free(logToRemove);
        }else {
            currentLog = currentLog->_next;
        }
    }
}

bool logAppend(logPtr *l, Event *e) {
    assert(l != NULL);
    assert(e != NULL);
    EventLog* newLog = createLog(e);
    if (!newLog) return false;
    if (*l == NULL) {
        newLog->_next = *l;
        (*l) = newLog;
        return true;
    }
    EventLog* currentLog = *l;
    while (currentLog->_next != NULL) {
        currentLog = currentLog->_next;
    }
    if (currentLog->_next == NULL) {
        currentLog->_next = newLog;
    }
    return true;
}

void logInsert(logPtr*l, int place, Event *e) {
    assert(l != NULL);
    assert(e != NULL);
    assert(place >= 0 && place <= logSize(*l));
    EventLog* newLog = createLog(e);
    if (!newLog){return;}
    if (place == 0) {
        newLog->_next = *l;
        *l = newLog;
        return;
    }
    EventLog *current = *l;
    for (int i = 0; i < place - 1; i++) {
        current = current->_next;
    }
    newLog->_next = current->_next;
    current->_next = newLog;
}

Event* logGet(logPtr*l, int place) {
    assert(l != NULL);
    assert(place >= 0 && place < logSize(*l));
    EventLog* current = *l;
    for (int i = 0; i < place; i++) {
        current = current->_next;
    }
    return current->_node;
}


int logSize(EventLog* l) {
    int size = 0;
    while (l != NULL) {
        size++;
        l = l->_next;
    }
    return size;
}


