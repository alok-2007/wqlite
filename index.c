#include <stdio.h>
#include <stdlib.h>
#include "prompter.h"
#include "reader.h"
#include <unistd.h>
#include <string.h>
#include "callback.h"
#include "commandHandler.h"
#include "executer.h"

int main(int argc, char* argv[]) {
    initial_prompt();
    while (true) {
        print_prompt(TakeInput);
        InputBuffer *ptr = reader();
       
       if (ptr->buffer[0] == '.') {
            switch (do_meta_command(ptr)) {
                case (META_COMMAND_SUCCESS):
                    freeInputBuffer(ptr);
                    continue;
                case (META_COMMAND_UNRECOGNIZED_COMMAND):
                    printf("Unrecognized command '%s'\n",ptr->buffer);
                    freeInputBuffer(ptr);
                    continue;
            }
       }

        Statement statement;

        switch (prepare_statement(ptr, &statement)) {
            case (PREPARE_SUCCESS):
                break;
            case (PREPARE_UNRECOGNIZED_STATEMENT):
                printf("prepare unrecognized statement '%s'\n",ptr->buffer);
                freeInputBuffer(ptr);
                continue;
        }

        execute_statement(&statement);
        printf("Executed.\n");
        freeInputBuffer(ptr);
    }
    return 0;
};
