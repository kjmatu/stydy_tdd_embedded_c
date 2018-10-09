#include "unity_fixture.h"

TEST_GROUP_RUNNER(CircularBuffer)
{
    RUN_TEST_CASE(CircularBuffer, CreateCircularBuffer);
    RUN_TEST_CASE(CircularBuffer, GerBufferSize);
    RUN_TEST_CASE(CircularBuffer, PushValue);
    RUN_TEST_CASE(CircularBuffer, PopValue);
    RUN_TEST_CASE(CircularBuffer, MultiPushValue);
    RUN_TEST_CASE(CircularBuffer, MultiPopValue);
    RUN_TEST_CASE(CircularBuffer, IsEmptyWithEmptyBuffer);
    RUN_TEST_CASE(CircularBuffer, IsEmptyWithFullBuffer);
    RUN_TEST_CASE(CircularBuffer, IsFullWithEmptyBuffer);
}