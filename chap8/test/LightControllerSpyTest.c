#include "LightControllerSpy.h"

#include "unity_fixture.h"

TEST_GROUP(LightControllerSpy);

TEST_SETUP(LightControllerSpy)
{
    LightController_Create();
}

TEST_TEAR_DOWN(LightControllerSpy)
{
    LightController_Destroy();
}

TEST(LightControllerSpy, Create)
{
    TEST_ASSERT_EQUAL_INT(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastId());
    TEST_ASSERT_EQUAL_INT(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastState());
}

TEST(LightControllerSpy, RememberTheLastLightIdControlled)
{
    LightController_TurnOn(10);
    TEST_ASSERT_EQUAL_INT(10, LightControllerSpy_GetLastId());
    TEST_ASSERT_EQUAL_INT(LIGHT_ON, LightControllerSpy_GetLastState());
}

TEST(LightControllerSpy, RememberAllLightStates)
{
    LightController_TurnOn(0);
    LightController_TurnOff(31);
    TEST_ASSERT_EQUAL_INT(LIGHT_ON, LightControllerSpy_GetLightState(0));
    TEST_ASSERT_EQUAL_INT(LIGHT_OFF, LightControllerSpy_GetLightState(31));
}
