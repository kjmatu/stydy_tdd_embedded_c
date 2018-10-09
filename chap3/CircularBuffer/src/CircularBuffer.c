#include <stdlib.h>
#include <stdbool.h>

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
    if (bufferSize == 0) return NULL;
    CircularBuffer self = calloc(1, sizeof(CircularBufferStruct));
    self->value = (int *)calloc(bufferSize, sizeof(int));
    self->size = bufferSize;
    self->pushIndex = 0;
    self->popIndex = 0;
    return self;
}

int CircularBuffer_Push(CircularBuffer self, int pushVal)
{
    int capacity = self->pushIndex - self->popIndex;
    if (capacity >= self->size) return 0;
    self->value[self->pushIndex] = pushVal;
    self->pushIndex++;
    return 1;
}

int CircularBuffer_Pop(CircularBuffer self, int *output)
{
    if (self->popIndex >= self->pushIndex) {
        *output = 0;
        return -1;
    }
    *output = self->value[self->popIndex];
    self->popIndex++;
    return 0;
}

int CircularBuffer_GetSize(CircularBuffer self)
{
    return self->size;
}

bool CircularBuffer_IsEmpty(CircularBuffer self)
{
    if (self->pushIndex == 0) return true;
    else return false;
}

bool CircularBuffer_IsFull(CircularBuffer self)
{
    return false;
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