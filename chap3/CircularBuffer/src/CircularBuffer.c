#include <stdlib.h>

#include "CircularBuffer.h"

CircularBuffer CircularBuffer_Create(int bufferSize)
{
    CircularBuffer buff = calloc(bufferSize, sizeof(int));
    return buff;
}