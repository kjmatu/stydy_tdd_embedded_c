#ifndef D_FAKE_TIME_SERVICE_H
#define D_FAKE_TIME_SERVICE_H

#include "TimeService.h"

enum
{
    TIME_UNKNOWN = -1
};

void FakeTimeService_SetMinute(int minutes);
void FakeTimeService_SetDay(Day day);
WakeUpCallback FakeTimeService_GetAlarmCallback(void);
int FakeTimeService_GetAlarmPeriod(void);

#endif
