#include <stdio.h>
#include "../header/ProgramManager.h"


#include <stdlib.h>
#include <string.h>



typedef struct {
    char cmd[BUFFER_SIZE];
    void (*function)(Context*);
}command;
// command pattern for the runtime commands
command commandList[] = {
    {.cmd = "help", .function = help},
    {.cmd = "tick", .function = tick},
    {.cmd = "print", .function = print},
    {.cmd = "find", .function = findId},
    {.cmd = "sort", .function = sort},
    {.cmd = "quit", .function = quit},
    {.cmd = "alarm", .function = printActivAlarm}
};

void printMainMenu() {
    printf("Input: ");
}

void help(Context* ctx, char* ch ) {
    printf("AVAILABLE COMMANDS:\n");
    printf("- Help lists all commands.\n"
        "- tick amount ex. 'tick 25' creates 25 events\n"
        "- print prints the eventlog\n"
        "- sort sorting algorithm ex. 'sort merge' sorts and prints the log with mergesort\n"
        "  available algorithms merge and insertion\n"
        "- find id ex 'find 1' prints all the sensors with id 1\n"
        "- alarm to see if any alarms are active."
        "- quit exits the program\n"
        );

}

void run(Context* ctx) {
    printMainMenu();
    char string[BUFFER_SIZE];
    fgets(string,BUFFER_SIZE,stdin);
    parseString(string, ctx);
    int size = sizeof(commandList)/sizeof(command);
    for (int i = 0; i < size; i++) {
        if (strcmp(commandList[i].cmd,ctx->cmdstring) == 0) {
            return commandList[i].function(ctx);
        }
    }

    clearContext(ctx);
}



void tick(Context* ctx) {
    eventProducer(ctx->queue, ctx->ammount);
    eventConsumer(ctx->queue, (Context*)&ctx->log, ctx->ammount);
}

void print(Context* ctx) {
    //HoF to print the entire log
    forEach(ctx,printEvents);
}

void sort(Context* ctx) {
    //strategy light for choosing what sorting algorithm
    sortFunc chosen = chosenSort(ctx);

    printSortedLog(chosen,ctx->log);
}

void findId(Context* ctx) {
    findSensorId(ctx);
}

void printActivAlarm(Context* ctx) {
    for (int i = 0; i < ctx->alarm->size; i++) {
        printf("Alarm active on Sensor ID: %d\n", ctx->alarm->sensorId[i]);
    }
}

void quit(Context* ctx) {
    //frees all allocated memory
    logDestroyList(&ctx->log);
    queueDestroy(ctx->queue);
    *ctx->Running = false;
}