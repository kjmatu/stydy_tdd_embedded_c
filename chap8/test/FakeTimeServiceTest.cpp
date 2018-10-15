#include "CppUTest/TestHarness.h"

extern "C"
{
    #include "FakeTimeService.h"
}

TEST_GROUP(FakeTimeService)
{
    void setup()
    {
        TimeService_Create();
    }

    void teardown()
    {
       TimeService_Destroy();
    }
};


TEST(FakeTimeService, Create)
{
    LONGS_EQUAL(MINUTE_UNKNOWN, TimeService_GetMinute());
    LONGS_EQUAL(DAY_UNKNOWN, TimeService_GetDay());
}


TEST(FakeTimeService, Set)
{
    FakeTimeService_SetMinute(42);
    FakeTimeService_SetDay(SATURDAY);
    LONGS_EQUAL(42, TimeService_GetMinute());
    LONGS_EQUAL(SATURDAY, TimeService_GetDay());
}
