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
    TEST_ASSERT_EQUAL_INT32(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastId());
    TEST_ASSERT_EQUAL_INT32(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastState());
}

TEST(LightControllerSpy, RememberTheLastLightIdControlled)
{
    LightController_TurnOn(10);
    TEST_ASSERT_EQUAL_INT32(10, LightControllerSpy_GetLastId());
    TEST_ASSERT_EQUAL_INT32(LIGHT_ON, LightControllerSpy_GetLastState());
}
