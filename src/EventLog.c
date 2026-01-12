//
// Created by peder on 2026-01-12.
//
#include <stddef.h>

#include "../header/EventLog.h"
List createEmptylist() {
    return NULL;
}

bool isEmpty(List l) {
    if (l == NULL) return 1;
    return 0;
}

void findValue(List l, struct Data d) {
    if (!isEmpty(l)) return;
    struct Node* tempNode = &l;
    while (tempNode->_next != NULL /*&& tempNode->_data._value != d*/) {

    }

}

void findId(List l, int Id) {
}

void findType(List l, char type[]) {
}

void findFirst(List l) {
}

void findLast(List l) {
}

bool addFirst(List* l, int type) {
}

bool addLast(List* l, int type) {
}

bool insertElement(List* l, int type) {
}

bool removeFirst(List* l) {
}

bool removeLast(List* l) {
}

bool removeElement(List* l, struct Data d) {
}

bool removeType(List* l, int type) {
}