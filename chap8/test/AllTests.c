#include "unity_fixture.h"

static void RunAllTests(void)
{
    RUN_TEST_GROUP(LightScheduler);
    RUN_TEST_GROUP(LightControllerSpy);
    RUN_TEST_GROUP(FakeTimeService);
}

int main(int argc, const char * argv[])
{
    return UnityMain(argc, argv, RunAllTests);
}
