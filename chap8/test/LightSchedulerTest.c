#include "LightScheduler.h"

#include "unity_fixture.h"

#include "LightControllerSpy.h"
#include "FakeTimeService.h"

TEST_GROUP(LightScheduler);

TEST_SETUP(LightScheduler)
{
    LightController_Create();
    LightScheduler_Create();
}

TEST_TEAR_DOWN(LightScheduler)
{
    LightController_Destroy();
    LightScheduler_Destroy();
}

TEST(LightScheduler, NoChangeToLightsDuringInitialization)
{
    LightScheduler_Wakeup();
    TEST_ASSERT_EQUAL_INT32(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastId());
    TEST_ASSERT_EQUAL_INT32(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastState());
}

TEST(LightScheduler, NoScheduleNothingHappens)
{
    FakeTimeService_SetDay(MONDAY);
    FakeTimeService_SetMinute(100);
    LightScheduler_Wakeup();
    TEST_ASSERT_EQUAL_INT(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastId());
    TEST_ASSERT_EQUAL_INT(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastState());
}

TEST(LightScheduler, ScheduleOnEverydayNotTimeYet)
{
    LightScheduler_TurnOn(3, EVERYDAY, 1200);
    FakeTimeService_SetDay(MONDAY);
    FakeTimeService_SetMinute(1199);
    LightScheduler_Wakeup();
    TEST_ASSERT_EQUAL_INT(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastId());
    TEST_ASSERT_EQUAL_INT(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastState());
}

TEST(LightScheduler, ScheduleOnEverydayItsTime)
{
    LightScheduler_TurnOn(3, EVERYDAY, 1200);
    FakeTimeService_SetDay(MONDAY);
    FakeTimeService_SetMinute(1200);

    LightScheduler_Wakeup();

    TEST_ASSERT_EQUAL_INT(3, LightControllerSpy_GetLastId());
    TEST_ASSERT_EQUAL_INT(LIGHT_ON, LightControllerSpy_GetLastState());
}

TEST(LightScheduler, ScheduleOffEverydayItsTime)
{
    LightScheduler_TurnOff(3, EVERYDAY, 1200);
    FakeTimeService_SetDay(MONDAY);
    FakeTimeService_SetMinute(1200);
    LightScheduler_Wakeup();

    TEST_ASSERT_EQUAL_INT(3, LightControllerSpy_GetLastId());
    TEST_ASSERT_EQUAL_INT(LIGHT_OFF, LightControllerSpy_GetLastState());
}
