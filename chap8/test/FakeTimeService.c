#include "FakeTimeService.h"

void TimeService_GetTime(Time *fakeTime)
{
    fakeTime->minuteOfDay = TIME_UNKNOWN;
    fakeTime->dayOfWeek = TIME_UNKNOWN;
}