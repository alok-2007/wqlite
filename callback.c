#include <stdlib.h>
#include "callback.h"

void freeInputBuffer(InputBuffer* ptr) {
    free(ptr);
} 