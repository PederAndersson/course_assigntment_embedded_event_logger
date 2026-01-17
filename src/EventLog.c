//
// Created by peder on 2026-01-12.
//
#include <stddef.h>
#include <stdlib.h>

#include "../header/EventLog.h"


static EventLog* createLog(Event *e) {
    EventLog* event_log = malloc(sizeof(EventLog));
    if (!event_log) return NULL;
    event_log->_node = e;
    event_log->_next = NULL;

    return event_log;
}

EventLog* createEmptyList(void) {
    return NULL;
}

bool isEmpty(logPtr l) {
    if (l == NULL) return true;
    return false;
}


void logDestroyList(logPtr *l) {
    if (isEmpty(*l)) return;

    while (*l != NULL) {
        EventLog* listToRemove = *l;
        (*l) = (*l)->_next;
        free(listToRemove);
    }
}

void logDestroyElement(logPtr* l, const Data d ) {
    if (isEmpty(*l)) return;
    while (*l != NULL && (*l)->_node->_value == d) {
        EventLog* logToRemove = *l;
        (*l) = (*l)->_next;
        free(logToRemove);
    }
    logPtr CurrentNode = *l;
    if (isEmpty(CurrentNode)) return;
    while (CurrentNode->_next != NULL) {
        if (CurrentNode->_next->_node->_value == d) {
            EventLog* logToRemove = CurrentNode->_next;
            CurrentNode->_next = logToRemove->_next;
            free(logToRemove);
        }else {
            CurrentNode = CurrentNode->_next;
        }
    }
}

void logDestroySensor(logPtr*l, sensorType s) {
    if (isEmpty(*l)) return;

    while (*l != NULL && (*l)->_node->_sensor == s) {
        EventLog* logToRemove = *l;
        (*l) = (*l)->_next;
        free(logToRemove);
    }

    EventLog* currentLog = *l;
    if (isEmpty(currentLog)) return;
    while (currentLog->_next != NULL) {
        if (currentLog->_next->_node->_sensor == s) {
            EventLog* logToRemove = currentLog->_next;
            currentLog->_next = logToRemove->_next;
            free(logToRemove);
        }else {
            currentLog = currentLog->_next;
        }
    }
}

void logAppend(logPtr *l, Event *e) {
    EventLog* newLog = createLog(e);
    if (!newLog) return;
    if (*l == NULL) {
        newLog->_next = *l;
        (*l) = newLog;
    }else {
        EventLog* currentLog = *l;
        while (currentLog->_next != NULL) {
            currentLog = currentLog->_next;
        }
        if (currentLog->_next == NULL) {
            currentLog->_next = newLog;
        }
    }
}


int logSize(EventLog* l) {
    int size = 0;
    while (l != NULL) {
        size++;
        l = l->_next;
    }
    return size;
}


