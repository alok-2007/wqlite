#include <unistd.h>
#include <stdio.h>
#include "reader.h"
#include <stdlib.h>

InputBuffer* reader(InputBuffer* inputPtr) {
    int n = 0;
    char bufferChunk[100];
    while((n = read(0,bufferChunk,100)) > 0) {
        size_t inputBufferSize = inputPtr->size;

        InputBuffer * tem_ptr = (void*)realloc(inputPtr,    sizeof(InputBuffer) + inputBufferSize + n);

        if (tem_ptr == NULL) {
            printf("realloc faild");
            exit(0);
        }

        inputPtr = tem_ptr;
        
        for (int i = 0; i < n; i++) {
            inputPtr->buffer[inputBufferSize + i] = bufferChunk[i];
        }
        inputBufferSize += n;
        inputPtr->size = inputBufferSize;
        if (bufferChunk[n-1] == '\n') {
            break;
        }
        n = 0;
    }
    return inputPtr;
}