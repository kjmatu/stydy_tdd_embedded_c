#ifndef __FAKE_TIME_SERCIVE__
#define __FAKE_TIME_SERCIVE__

#include "TimeService.h"

enum
{
    MINUTE_UNKNOWN = -1, DAY_UNKNOWN = -1
};

void FakeTimeService_SetMinute(int minute);
void FakeTimeService_SetDay(int day);

#endif