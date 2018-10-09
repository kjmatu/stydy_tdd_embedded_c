#include <stdlib.h>

#include "CircularBuffer.h"
#include "Utils.h"

typedef struct CircularBufferStruct {
    int *value;
    int size;
    int pushIndex;
    int popIndex;
} CircularBufferStruct;

CircularBuffer CircularBuffer_Create(int bufferSize)
{

    CircularBuffer self = calloc(1, sizeof(CircularBufferStruct));
    self->value = (int *)calloc(bufferSize, sizeof(int));
    self->size = bufferSize;
    self->pushIndex = 0;
    self->popIndex = 0;
    return self;
}

int CircularBuffer_Push(CircularBuffer self, int pushVal)
{
    self->value[self->pushIndex] = pushVal;
    self->pushIndex++;
    return 1;
}

int CircularBuffer_Pop(CircularBuffer self)
{
    int popValue;
    popValue = self->value[self->popIndex];
    self->popIndex++;
    return popValue;
}

int CircularBuffer_GetSize(CircularBuffer self)
{
    return self->size;
}

// void CircularBuffer_Print(CircularBuffer self)
// {
//     FormatOutput("CircularBufferValues\n");
//     int size = CircularBuffer_GetSize(self);
//     for (int i = 0; i < size; i++)
//     {
//         if(i != 0) FormatOutput(", ");
//         FormatOutput("%d", self->value[i]);
//     }
//     FormatOutput("\n");
// }