#include <stdbool.h>

#include "CircularBuffer.h"

#include "unity_fixture.h"

#define BUFFER_SIZE 10

static CircularBuffer self;

TEST_GROUP(CircularBuffer);


TEST_SETUP(CircularBuffer)
{
    int size = BUFFER_SIZE;
    self = CircularBuffer_Create(size);
}

TEST_TEAR_DOWN(CircularBuffer)
{
}

IGNORE_TEST(CircularBuffer, CreateCircularBuffer)
{
}

TEST(CircularBuffer, GerBufferSize)
{
    TEST_ASSERT_EQUAL(BUFFER_SIZE, CircularBuffer_GetSize(self));
}

TEST(CircularBuffer, PushValue)
{
    int ret;
    ret = CircularBuffer_Push(self, 1);
    TEST_ASSERT_EQUAL_INT(1, ret);
}

TEST(CircularBuffer, PopValue)
{
    int popValue;
    CircularBuffer_Push(self, 10);
    popValue = CircularBuffer_Pop(self);
    TEST_ASSERT_EQUAL_INT(10, popValue);
}

TEST(CircularBuffer, MultiPushValue)
{
    int ret;
    ret = CircularBuffer_Push(self, 1);
    TEST_ASSERT_EQUAL_INT(1, ret);
    ret = CircularBuffer_Push(self, 2);
    TEST_ASSERT_EQUAL_INT(1, ret);
    ret = CircularBuffer_Push(self, 3);
    TEST_ASSERT_EQUAL_INT(1, ret);
}

TEST(CircularBuffer, MultiPopValue)
{
    int popValue;
    CircularBuffer_Push(self, 1);
    CircularBuffer_Push(self, 2);
    CircularBuffer_Push(self, 3);
    popValue = CircularBuffer_Pop(self);
    TEST_ASSERT_EQUAL_INT(1, popValue);
    popValue = CircularBuffer_Pop(self);
    TEST_ASSERT_EQUAL_INT(2, popValue);
    popValue = CircularBuffer_Pop(self);
    TEST_ASSERT_EQUAL_INT(3, popValue);
}

TEST(CircularBuffer, IsEmptyWithEmptyBuffer)
{
    TEST_ASSERT_TRUE(CircularBuffer_IsEmpty(self));
}

TEST(CircularBuffer, IsEmptyWithFullBuffer)
{

    for(int i = 0; i < BUFFER_SIZE; i++)
    {
        CircularBuffer_Push(self, i);
    }
    TEST_ASSERT_FALSE(CircularBuffer_IsEmpty(self));
}

TEST(CircularBuffer, IsFullWithEmptyBuffer)
{
    TEST_ASSERT_FALSE(CircularBuffer_IsFull(self));
}
