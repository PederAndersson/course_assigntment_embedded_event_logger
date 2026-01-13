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

List* createEmptylist(void) {
    return NULL;
}

bool isEmpty(List *l) {
    if (l == NULL) return true;
    return false;
}

void logDestroyList(List *l) {
    if (isEmpty(l)) return;

    while (l != NULL) {
        Event* nodeToRemove = &l->_node;
        List* listToRemove = l;
        l = l->_next;
        free(nodeToRemove);
        free(listToRemove);
    }
}

void logDestroyElement(List* l, const Data d ) {
    if (isEmpty(l)) return;
    while (l->_node._value != d && l->_next != NULL) {
        l = l->_next;
    }
    if (l->_node._value == d) {
        List* logToRemove = l;
        l->_next = logToRemove->_next;
        free(logToRemove);
    }
}

void logDestroySensor(List*l, sensorType s) {
    if (isEmpty(l)) return;
}

void logAppend(List*l, Event e) {
}


int logSize(List* l) {
    int size = 0;
    while (l != NULL) {
        size++;
        l = l->_next;
    }
    return size;
}

Event logGetSensor(const List l, sensorType s) {
}

Event logGetData(const List l,Data d ) {

}


