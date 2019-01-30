#include "FakeTimeService.h"


static Time fTime;
static WakeUpCallback callback;
static int periodSec;

void TimeService_Create(void)
{
    fTime.minuteOfDay = TIME_UNKNOWN;
    fTime.dayOfWeek = TIME_UNKNOWN;
}

void TimeService_Destroy(void)
{
    fTime.minuteOfDay = TIME_UNKNOWN;
    fTime.dayOfWeek = TIME_UNKNOWN;
}

int TimeService_GetMinute(void)
{
    return 0;
}

int TimeService_GetDay(void)
{
    return 0;
}

void TimeService_GetTime(Time *time)
{
    *time = fTime;
}

void TimeService_SetPeriodicAlarmInSeconds(int seconds, WakeUpCallback inCb)
{
    callback = inCb;
    periodSec = seconds;
}

void TimeService_CancelPeriodicAlarmInSeconds(int seconds, WakeUpCallback cb)
{
    if (cb == callback && periodSec == seconds)
    {
        callback = NULL;
        periodSec = 0;
    }
}

void FakeTimeService_SetMinute(int minutes)
{
    fTime.minuteOfDay = minutes;
}

void FakeTimeService_SetDay(Day day)
{
    fTime.dayOfWeek = day;
}

WakeUpCallback FakeTimeService_GetAlarmCallback(void)
{
    return callback;
}

int FakeTimeService_GetAlarmPeriod(void)
{
    return periodSec;
}


