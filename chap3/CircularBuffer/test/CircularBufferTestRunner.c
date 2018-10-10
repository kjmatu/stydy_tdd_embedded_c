#include "unity_fixture.h"

TEST_GROUP_RUNNER(CircularBuffer)
{
    RUN_TEST_CASE(CircularBuffer, CreateCircularBuffer);
    RUN_TEST_CASE(CircularBuffer, DeleteCircularBuffer);
    RUN_TEST_CASE(CircularBuffer, GerBufferSize);
    RUN_TEST_CASE(CircularBuffer, PushValue);
    RUN_TEST_CASE(CircularBuffer, PopValue);
    RUN_TEST_CASE(CircularBuffer, MultiPushValue);
    RUN_TEST_CASE(CircularBuffer, MultiPopValue);
    RUN_TEST_CASE(CircularBuffer, IsEmptyWithEmptyBuffer);
    RUN_TEST_CASE(CircularBuffer, IsEmptyWithFullBuffer);
    RUN_TEST_CASE(CircularBuffer, IsFullWithEmptyBuffer);
    RUN_TEST_CASE(CircularBuffer, IsFullWithFullBuffer);
    RUN_TEST_CASE(CircularBuffer, FullBufferPushError);
    RUN_TEST_CASE(CircularBuffer, EmptyBufferPopError);
    RUN_TEST_CASE(CircularBuffer, SizeZeroBufferCreate);
    RUN_TEST_CASE(CircularBuffer, FullPushFullPopAfterOnePush);
    RUN_TEST_CASE(CircularBuffer, CheckBufferOverRunWhenInit);
    RUN_TEST_CASE(CircularBuffer, CheckBufferOverRunWhenFullPushFullPopAfterOnePush);
    RUN_TEST_CASE(CircularBuffer, CheckBufferOverRunWhenFullPushFullPopAfterOnePushPop);
}