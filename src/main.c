
#include "../header/Event.h"
#include "../header/EventLog.h"
#include "../header/EventQueue.h"
#include "../header/ProgramManager.h"




int main(void) {
    initRand();
    int arrayCapacity = 100;
    Queue* queue = newQueue(arrayCapacity);
    EventLog* log = createEmptyList();
    bool isRunning = true;

    Context ctx = {
        .log = log,
        .queue = queue,
        .Running = &isRunning,
        .ammount = 0,
        .id = 0,
        .cmdstring = {},
        .argString = {}
    };
    printMainMenu();
    while (isRunning) {
    run(&ctx);
    }


    return 0;
}