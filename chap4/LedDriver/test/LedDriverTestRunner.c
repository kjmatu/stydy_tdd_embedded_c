#include "unity_fixture.h"

TEST_GROUP_RUNNER(LedDriver)
{
    RUN_TEST_CASE(LedDriver, LedsOffAfterCreate);
    RUN_TEST_CASE(LedDriver, TurnOnLedOne);
    RUN_TEST_CASE(LedDriver, TurnOffLedOne);
    RUN_TEST_CASE(LedDriver, TurnOnMultipleLeds);
    RUN_TEST_CASE(LedDriver, AllOn);
    RUN_TEST_CASE(LedDriver, AllOff);
    RUN_TEST_CASE(LedDriver, TurnOffAnyLed);
    RUN_TEST_CASE(LedDriver, LedMemoryIsNotRedable);
    RUN_TEST_CASE(LedDriver, UpperAndLowerBounds);
    RUN_TEST_CASE(LedDriver, OutOfBoundsChangesNothing);
    RUN_TEST_CASE(LedDriver, OutOfBoundsTurnOffDoesNoHarm);
    RUN_TEST_CASE(LedDriver, IsOn);
    RUN_TEST_CASE(LedDriver, IsOff);
    RUN_TEST_CASE(LedDriver, OutOfBoundsLedsAreaAlwaysOff);
    RUN_TEST_CASE(LedDriver, TurnOffMultipleLeds);
}