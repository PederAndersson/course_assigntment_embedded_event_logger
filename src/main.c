#include <stdio.h>
#include <stdlib.h>


#include "../header/Event.h"
#include "../header/EventLog.h"
#include "../header/EventQueue.h"
#include "../header/EventLoop.h"
#include "../header/ProgramManager.h"



int main(void) {
    /*initRand();
    int arrayCapacity = 100;
    Queue* queue = newQueue(arrayCapacity);
    EventLog* log = createEmptyList();
    tick(queue,&log,15);

    forEach(log, printEvents);

    logDestroyList(&log);
    queueDestroy(queue);*/

    bool isRunning = true;
    while (isRunning == true) {
        char input[CMD_SIZE] = {};
        printMainMenu();
        fgets(input,sizeof(input),stdin);
        run(stringToEnum(input), &isRunning);
    }


    return 0;
}