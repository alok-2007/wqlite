#ifndef READER_H
#define READER_H

typedef struct {
    size_t size;
    char buffer[];
} InputBuffer;
InputBuffer * reader(InputBuffer*);
#endif