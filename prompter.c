#include <time.h>
#include <stdio.h>
#include "prompter.h"
#include <unistd.h>

int initial_prompt(void) {
    time_t now;
    time(&now);

    printf(
    "~wqlite3\n"
    "WQLite version 3.16.0 %s"
    "Enter \".help\" for usage hints.\n"
    "Connected to a transient in-memory database.\n"
    "Use \".open FILENAME\" to reopen on a persistent database.\n",
    ctime(&now));
};

int print_prompt(enum printPromptType choice) {
    switch (choice) {
        case TakeInput:
            write(1,"wqlite>\t",7);
            break;
        default:
            write(1,"In valid choice\n",14);
            break;
    }
    return 0;
}
