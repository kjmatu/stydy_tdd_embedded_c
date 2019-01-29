#include "FakeTimeService.h"

#include "unity_fixture.h"

#include "TimeService.h"

TEST_GROUP(FakeTimeService);

TEST_SETUP(FakeTimeService)
{
    TimeService_Create();
}

TEST_TEAR_DOWN(FakeTimeService)
{
    TimeService_Destroy();
}

TEST(FakeTimeService, Create)
{
    Time time;
    TimeService_GetTime(&time);
    TEST_ASSERT_EQUAL_INT(TIME_UNKNOWN, time.minuteOfDay);
    TEST_ASSERT_EQUAL_INT(TIME_UNKNOWN, time.dayOfWeek);
}

TEST(FakeTimeService, Set)
{
    Time time;
    FakeTimeService_SetMinute(42);
    FakeTimeService_SetDay(SATURDAY);
    TimeService_GetTime(&time);
    TEST_ASSERT_EQUAL_INT(42, time.minuteOfDay);
    TEST_ASSERT_EQUAL_INT(SATURDAY, time.dayOfWeek);
}
