#include <stdio.h>
#include "../header/ProgramManager.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char cmd[BUFFER_SIZE];
    void (*function)(Context*);
}command;

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

void parseString(char* string, Context* ctx) {
    //sort str + str, find str + int, tick str + int
    int strIdx = 0;
    int cmdIdx = 0;
    int argIdx = 0;

    while (string[strIdx] == ' ' || string[strIdx] == '\t') {
        strIdx++;
    }

    while (string[strIdx] != ' '  && string[strIdx] != '\t' && string[strIdx] != '\0' && string[strIdx] != '\n') {
        if (cmdIdx >= BUFFER_SIZE-1){break;}
        ctx->cmdstring[cmdIdx++] = (char)tolower((unsigned char)string[strIdx++]);
    }
    ctx->cmdstring[cmdIdx] = '\0';
    while (string[strIdx] == ' ' || string[strIdx] == '\t') {
        strIdx++;
    }
    if (strcmp(ctx->cmdstring,"sort") == 0) {
        while (string[strIdx] != ' '  && string[strIdx] != '\t' && string[strIdx] != '\0' && string[strIdx] != '\n') {
            if (argIdx >= BUFFER_SIZE-1){break;}
            ctx->argString[argIdx++] = (char)tolower((unsigned char)string[strIdx++]);
        }
        ctx->argString[argIdx] = '\0';
    }

    else if (strcmp(ctx->cmdstring,"find") == 0) {
        char temp[BUFFER_SIZE];
        int idx = 0;
        while (string[strIdx] != ' '  && string[strIdx] != '\t' && string[strIdx] != '\0' && string[strIdx] != '\n' && idx < BUFFER_SIZE-1) {
            temp[idx++] = string[strIdx++];
        }
        temp[idx] = '\0';
        char* end = NULL;
        int value = (int)strtol(temp, &end, 10);
        if (end == temp) {
            ctx->id = -1;
        } else {
            ctx->id = value;
        }
    }else if (strcmp(ctx->cmdstring,"tick") == 0) {
        char temp[BUFFER_SIZE];
        int idx = 0;
        while (string[strIdx] != ' '  && string[strIdx] != '\t' && string[strIdx] != '\0' && string[strIdx] != '\n' && idx < BUFFER_SIZE-1) {
            temp[idx++] = string[strIdx++];
        }
        temp[idx] = '\0';
        char* end = NULL;
        int value = (int)strtol(temp, &end, 10);
        if (end == temp) {
            ctx->ammount = -1;
        } else {
            ctx->ammount = value;
        }
    }
}

void tick(Context* ctx) {
    eventProducer(ctx->queue, ctx->ammount);
    eventConsumer(ctx->queue, (Context*)&ctx->log, ctx->ammount);
}

void print(Context* ctx) {
    forEach(ctx,printEvents);
}

void sort(Context* ctx) {

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
    logDestroyList(&ctx->log);
    queueDestroy(ctx->queue);
    *ctx->Running = false;
}