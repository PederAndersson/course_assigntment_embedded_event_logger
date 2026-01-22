#include <stdio.h>
#include <stdlib.h>


#include "../header/Event.h"
#include "../header/EventLog.h"
#include "../header/EventQueue.h"
#include "../header/EventLoop.h"
#include "../header/ProgramManager.h"
#include "../header/sortAlgo.h"



int main(void) {
    initRand();
    int arrayCapacity = 100;
    Queue* queue = newQueue(arrayCapacity);
    EventLog* log = createEmptyList();
    tick(queue,&log,15);

    forEach(log, printEvents);

    printf("----------------------------");
    int size ;
    Event** sort = mergeSort(log,&size);

    for (int i = 0; i < size; i++) {
        printf("sensor: %s Id: %d\n", enumToString(sort[i]->_sensor), sort[i]->_Id);
        printf("Value : %d %s\n", sort[i]->_value, sort[i]->_unit);
        printf("time: %d:%d:%d\n", sort[i]->_timestamp.tm_hour, sort[i]->_timestamp.tm_min, sort[i]->_timestamp.tm_sec);
    }
    free(sort);
    logDestroyList(&log);
    queueDestroy(queue);



    return 0;
}