#include <stdio.h>

#include "CircularBuffer.h"

#include "unity_fixture.h"

TEST_GROUP(CircularBuffer);


TEST_SETUP(CircularBuffer)
{
}

TEST_TEAR_DOWN(CircularBuffer)
{
}

TEST(CircularBuffer, CreateCircularBuffer)
{
    int size = 10;
    CircularBuffer buff = CircularBuffer_Create(size);
    int expArray[10] = {0};

    for(size_t i = 0; i < 10; i++)
    {
        printf("%d\n", buff[i]);
    }

    TEST_ASSERT_EQUAL_INT_ARRAY(expArray, buff, size);
}
