#ifndef __CIRCULAR_BUFFER__
#define __CIRCULAR_BUFFER__

typedef struct CircularBufferStruct* CircularBuffer;

CircularBuffer CircularBuffer_Create(int bufferSize);
int CircularBuffer_GetSize(CircularBuffer self);
void CircularBuffer_Print(CircularBuffer self);
int CircularBuffer_Push(CircularBuffer self, int pushVal);
int CircularBuffer_Pop(CircularBuffer self);
bool CircularBuffer_IsEmpty(CircularBuffer self);

#endif