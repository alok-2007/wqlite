#ifndef PROMPTER_H
#define PROMPTER_H

enum printPromptType {
    TakeInput
};

extern int initial_prompt(void);
extern int print_prompt(enum printPromptType); 

#endif