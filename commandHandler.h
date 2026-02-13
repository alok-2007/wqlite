#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include <stdlib.h>
#include "callback.h"
#include <stdio.h>
#include <string.h>

typedef enum {
  META_COMMAND_SUCCESS,
  META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

typedef enum { 
    PREPARE_SUCCESS,
    PREPARE_UNRECOGNIZED_STATEMENT 
} PrepareResult;

typedef enum { 
    STATEMENT_INSERT,
    STATEMENT_SELECT 
} StatementType;

typedef struct {
  StatementType type;
} Statement;



MetaCommandResult do_meta_command(InputBuffer*);
PrepareResult prepare_statement(InputBuffer*,Statement*);

#endif