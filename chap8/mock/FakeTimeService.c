#include "FakeTimeService.h"


static Time fTime;
static WakeUpCallback cb;
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
    cb = inCb;
    periodSec = seconds;
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
    return cb;
}

int FakeTimeService_GetAlarmPeriod(void)
{
    return periodSec;
}


