#ifndef __CIRCULAR_BUFFER__
#define __CIRCULAR_BUFFER__

typedef struct CircularBufferStruct* CircularBuffer;

CircularBuffer CircularBuffer_Create(int bufferSize);
int CircularBuffer_Delete(CircularBuffer self);
int CircularBuffer_GetSize(CircularBuffer self);
int CircularBuffer_Push(CircularBuffer self, int pushVal);
int CircularBuffer_Pop(CircularBuffer self, int *output);
bool CircularBuffer_IsEmpty(CircularBuffer self);
bool CircularBuffer_IsFull(CircularBuffer self);
bool CircularBuffer_CheckBufferOverRun(CircularBuffer self);

#endif