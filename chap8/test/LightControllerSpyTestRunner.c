#include "unity_fixture.h"

#include "LightControllerSpy.h"

TEST_GROUP_RUNNER(LightControllerSpy)
{
    RUN_TEST_CASE(LightControllerSpy, Create);
    RUN_TEST_CASE(LightControllerSpy, RememberTheLastLightIdControlled);
    RUN_TEST_CASE(LightControllerSpy, RememberAllLightStates);
}
