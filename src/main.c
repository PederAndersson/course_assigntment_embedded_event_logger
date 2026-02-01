#include "../header/Event.h"
#include "../header/EventLog.h"
#include "../header/ProgramManager.h"





int main(void) {
    initRand();
    int arrayCapacity = 100;
    Queue* queue = newQueue(arrayCapacity);
    EventLog* log = createEmptyList();
    Alarm alarmSet;
    alarmInit(&alarmSet);
    bool isRunning = true;
    // struct containing all relevant variables
    Context ctx = {
        .log = log,
        .queue = queue,
        .Running = &isRunning,
        .alarm = &alarmSet,
        .ammount = 0,
        .id = 0,
        .cmdstring = {},
        .argString = {}
    };
    while (isRunning) {
    run(&ctx);
    }


    return 0;
}