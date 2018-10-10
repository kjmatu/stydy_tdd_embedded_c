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

TEST(CircularBuffer, CreateCircularBuffer)
{
    TEST_ASSERT_EQUAL_INT(BUFFER_SIZE, CircularBuffer_GetSize(self));
    TEST_ASSERT_TRUE(CircularBuffer_IsEmpty(self));
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
    int popValue, ret;
    CircularBuffer_Push(self, 10);
    ret = CircularBuffer_Pop(self, &popValue);
    TEST_ASSERT_EQUAL_INT(10, popValue);
    TEST_ASSERT_EQUAL_INT(1, ret);
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
    int popValue, ret;
    CircularBuffer_Push(self, 1);
    CircularBuffer_Push(self, 2);
    CircularBuffer_Push(self, 3);
    ret = CircularBuffer_Pop(self, &popValue);
    TEST_ASSERT_EQUAL_INT(1, popValue);
    TEST_ASSERT_EQUAL_INT(1, ret);

    ret = CircularBuffer_Pop(self, &popValue);
    TEST_ASSERT_EQUAL_INT(2, popValue);
    TEST_ASSERT_EQUAL_INT(1, ret);

    ret = CircularBuffer_Pop(self, &popValue);
    TEST_ASSERT_EQUAL_INT(3, popValue);
    TEST_ASSERT_EQUAL_INT(1, ret);
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

TEST(CircularBuffer, IsFullWithFullBuffer)
{
    for(int i = 0; i < BUFFER_SIZE; i++)
    {
        CircularBuffer_Push(self, i);
    }
    TEST_ASSERT_TRUE(CircularBuffer_IsFull(self));
}

TEST(CircularBuffer, FullBufferPushError)
{
    for(int i = 0; i < BUFFER_SIZE; i++)
    {
        CircularBuffer_Push(self, i);
    }
    int ret = CircularBuffer_Push(self, 11);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

TEST(CircularBuffer, EmptyBufferPopError)
{
    int popValue, ret;
    ret = CircularBuffer_Pop(self, &popValue);
    TEST_ASSERT_EQUAL_INT(0, ret);
    TEST_ASSERT_EQUAL_INT(0, popValue);
}

TEST(CircularBuffer, SizeZeroBufferCreate)
{
    self = CircularBuffer_Create(0);
    TEST_ASSERT_NULL(self);
}

TEST(CircularBuffer, FullPushFullPopAfterOnePush)
{
    for(int i = 0; i < BUFFER_SIZE; i++) {
        CircularBuffer_Push(self, i);
    }

    int popValue = 0xFFFFF;
    for(int i = 0; i < BUFFER_SIZE; i++) {
        CircularBuffer_Pop(self, &popValue);
    }

    int ret = CircularBuffer_Push(self, 0xFF);
    TEST_ASSERT_EQUAL_INT(ret, 1);
}

TEST(CircularBuffer, CheckBufferOverRunWhenInit)
{
    TEST_ASSERT_TRUE(CircularBuffer_CheckBufferOverRun(self));
}

TEST(CircularBuffer, CheckBufferOverRunWhenFullPushFullPopAfterOnePush)
{
    for(int i = 0; i < BUFFER_SIZE; i++) {
        CircularBuffer_Push(self, i);
    }

    int popValue = 0xFFFFF;
    for(int i = 0; i < BUFFER_SIZE; i++) {
        CircularBuffer_Pop(self, &popValue);
    }
    CircularBuffer_Push(self, 0xFF);
    TEST_ASSERT_TRUE(CircularBuffer_CheckBufferOverRun(self));
}

TEST(CircularBuffer, CheckBufferOverRunWhenFullPushFullPopAfterOnePushPop)
{
    for(int i = 0; i < BUFFER_SIZE; i++) {
        CircularBuffer_Push(self, i);
    }

    int popValue = 0xFFFFF;
    for(int i = 0; i < BUFFER_SIZE; i++) {
        CircularBuffer_Pop(self, &popValue);
    }
    CircularBuffer_Push(self, 0xFF);
    int ret = CircularBuffer_Pop(self, &popValue);
    TEST_ASSERT_EQUAL_INT(0xFF, popValue);
    TEST_ASSERT_EQUAL_INT(1, ret);
}
