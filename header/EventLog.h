//
// Created by peder on 2026-01-12.
//

#ifndef COURSE_ASSIGNTMENT_EVENTLOG_H
#define COURSE_ASSIGNTMENT_EVENTLOG_H
#include <stdbool.h>

#include "Event.h"
typedef struct Node* List;

List createEmptylist();
bool isEmpty(List l);
void findValue(List l, struct Data d);
void findId(List l, int Id);
void findType(List l, char type[]);
void findFirst(List l);
void findLast(List l);
bool addFirst(List* l, int type);
bool addLast(List* l, int type);
bool insertElement(List* l, int type);
bool removeFirst(List* l);
bool removeLast(List* l);
bool removeElement(List* l, struct Data d);
bool removeType(List* l, int type);


#endif //COURSE_ASSIGNTMENT_EVENTLOG_H