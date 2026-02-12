#include <stdio.h>
#include <stdlib.h>
#include "prompter.h"
#include "reader.h"
#include <unistd.h>
#include <string.h>
#include "callback.h"

int main(int argc, char* argv[]) {
    initial_prompt();
    while (true) {
        print_prompt(TakeInput);
        InputBuffer *ptr = (InputBuffer *)malloc(sizeof(InputBuffer));
        ptr->size = 0;
        ptr = reader(ptr);
        if (strcmp(ptr->buffer, ".exit\n") == 0) {
            resetInputBuffer(ptr);
            exit(EXIT_SUCCESS);
        } else {
            write(1,"\n",1);
            write(1,ptr->buffer,ptr->size);
            write(1,"\n",1);    
        }
        resetInputBuffer(ptr);
    }
    return 0;
};
