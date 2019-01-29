#include "unity_fixture.h"

#include "FakeTimeService.h"

TEST_GROUP_RUNNER(LightScheduler)
{
    RUN_TEST_CASE(LightScheduler, NoChangeToLightsDuringInitialization);
    RUN_TEST_CASE(LightScheduler, NoScheduleNothingHappens);
}
