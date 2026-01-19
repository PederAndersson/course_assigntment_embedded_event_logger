#include "../header/sortAlgo.h"

#include <stdlib.h>

void insertionSort(EventLog *log) {
    EventLog* current = log;
    EventLog* temp = createEmptyList();
    if (!temp){free(temp);return;}
        if (current == NULL) {
            temp->_next = current;
        }
    while (current != NULL) {
        if (current->_node->_Id == temp->_node->_Id && temp->_node->_value < current->_node->_value) {
            temp->_next = current;
        }else {

        }
    }
}

void merge(EventLog *log) {
}

void mergeSort(EventLog *log) {
}
