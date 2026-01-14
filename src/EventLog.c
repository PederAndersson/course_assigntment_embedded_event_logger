//
// Created by peder on 2026-01-12.
//
#include <stddef.h>
#include <stdlib.h>

#include "../header/EventLog.h"


static List* createLog(Event e) {
    List* event_log = malloc(sizeof(List));
    if (!event_log) return NULL;
    event_log->_node = e;
    event_log->_next = NULL;

    return event_log;
}

List* createEmptyList(void) {
    return NULL;
}

bool isEmpty(ListPtr l) {
    if (l == NULL) return true;
    return false;
}


void logDestroyList(ListPtr *l) {
    if (isEmpty(*l)) return;

    while (*l != NULL) {
        List* listToRemove = *l;
        (*l) = (*l)->_next;
        free(listToRemove);
    }
}

void logDestroyElement(ListPtr* l, const Data d ) {
    if (isEmpty(*l)) return;
    while (*l != NULL && (*l)->_node._value == d) {
        List* logToRemove = *l;
        (*l) = (*l)->_next;
        free(logToRemove);
    }
    ListPtr CurrentNode = *l;
    if (isEmpty(CurrentNode)) return;
    while (CurrentNode->_next != NULL) {
        if (CurrentNode->_next->_node._value == d) {
            List* logToRemove = CurrentNode->_next;
            CurrentNode->_next = logToRemove->_next;
            free(logToRemove);
        }else {
            CurrentNode = CurrentNode->_next;
        }
    }
}

void logDestroySensor(ListPtr*l, sensorType s) {
    if (isEmpty(*l)) return;

    while (*l != NULL && (*l)->_node._sensor == s) {
        List* logToRemove = *l;
        (*l) = (*l)->_next;
        free(logToRemove);
    }

    List* currentLog = *l;
    if (isEmpty(currentLog)) return;
    while (currentLog->_next != NULL) {
        if (currentLog->_next->_node._sensor == s) {
            List* logToRemove = currentLog->_next;
            currentLog->_next = logToRemove->_next;
            free(logToRemove);
        }else {
            currentLog = currentLog->_next;
        }
    }
}

void logAppend(ListPtr *l, Event e) {
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


int logSize(List* l) {
    int size = 0;
    while (l != NULL) {
        size++;
        l = l->_next;
    }
    return size;
}


