#include "LightScheduler.h"

#include "unity_fixture.h"

#include "LightControllerSpy.h"

TEST_GROUP(LightScheduler);

TEST_SETUP(LightScheduler)
{
    LightController_Create();
}

TEST_TEAR_DOWN(LightScheduler)
{
}

TEST(LightScheduler, NoChangeToLightsDuringInitialization)
{
    LightScheduler_Wakeup();
    TEST_ASSERT_EQUAL_INT32(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastId());
    TEST_ASSERT_EQUAL_INT32(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastState());
}
