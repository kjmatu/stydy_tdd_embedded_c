#include "unity_fixture.h"

TEST_GROUP_RUNNER(sprintf)
{
    RUN_TEST_CASE(sprintf, NoFormatOperations);
    RUN_TEST_CASE(sprintf, InsertString);
    RUN_TEST_CASE(sprintf, InsertNumber);
    RUN_TEST_CASE(sprintf, OutputSmallCaseHex);
    RUN_TEST_CASE(sprintf, OutputBigCaseHex);
}
