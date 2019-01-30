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

static void setTimeTo(int day, int minuteOfDay)
{
    FakeTimeService_SetDay(day);
    FakeTimeService_SetMinute(minuteOfDay);
}

static void checkLightState(int id, int level)
{
    TEST_ASSERT_EQUAL_INT(id, LightControllerSpy_GetLastId());
    TEST_ASSERT_EQUAL_INT(level, LightControllerSpy_GetLastState());
}

TEST(LightScheduler, NoChangeToLightsDuringInitialization)
{
    LightScheduler_Wakeup();
    TEST_ASSERT_EQUAL_INT32(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastId());
    TEST_ASSERT_EQUAL_INT32(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastState());
}

TEST(LightScheduler, NoScheduleNothingHappens)
{
    setTimeTo(MONDAY, 100);
    LightScheduler_Wakeup();
    checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
}

TEST(LightScheduler, ScheduleOnEverydayNotTimeYet)
{
    LightScheduler_TurnOn(3, EVERYDAY, 1200);
    setTimeTo(MONDAY, 1199);
    LightScheduler_Wakeup();
    checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
}

TEST(LightScheduler, ScheduleOnEverydayItsTime)
{
    LightScheduler_TurnOn(3, EVERYDAY, 1200);
    setTimeTo(MONDAY, 1200);
    LightScheduler_Wakeup();
    checkLightState(3, LIGHT_ON);
}

TEST(LightScheduler, ScheduleOffEverydayItsTime)
{
    LightScheduler_TurnOff(3, EVERYDAY, 1200);
    setTimeTo(MONDAY, 1200);
    LightScheduler_Wakeup();
    checkLightState(3, LIGHT_OFF);
}

TEST(LightScheduler, ScheduleWeekEndItsMonday)
{
    LightScheduler_TurnOn(3, WEEKEND, 1200);
    setTimeTo(MONDAY, 1200);
    LightScheduler_Wakeup();
    checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
}

TEST(LightScheduler, ShceduleTuesdayButItsMonday)
{
    LightScheduler_TurnOn(3, TUESDAY, 1200);
    setTimeTo(MONDAY, 1200);
    LightScheduler_Wakeup();
    checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
}


TEST(LightScheduler, ScheduleTuesdayAndItsTuesday)
{
    LightScheduler_TurnOn(3, TUESDAY, 1200);
    setTimeTo(TUESDAY, 1200);
    LightScheduler_Wakeup();
    checkLightState(3, LIGHT_ON);
}
