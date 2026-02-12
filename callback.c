#include <stdlib.h>
#include "callback.h"

void resetInputBuffer(InputBuffer* ptr) {
    free(ptr);
} 