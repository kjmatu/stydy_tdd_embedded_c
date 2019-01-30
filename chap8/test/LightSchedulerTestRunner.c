#include "unity_fixture.h"

#include "FakeTimeService.h"

TEST_GROUP_RUNNER(LightScheduler)
{
    RUN_TEST_CASE(LightScheduler, NoChangeToLightsDuringInitialization);
    RUN_TEST_CASE(LightScheduler, NoScheduleNothingHappens);
    RUN_TEST_CASE(LightScheduler, ScheduleOnEverydayNotTimeYet);
    RUN_TEST_CASE(LightScheduler, ScheduleOnEverydayItsTime);
    RUN_TEST_CASE(LightScheduler, ScheduleOffEverydayItsTime);
    RUN_TEST_CASE(LightScheduler, ScheduleWeekEndItsMonday);
}
