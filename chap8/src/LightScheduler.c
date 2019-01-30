#include "LightScheduler.h"
#include "LightController.h"

typedef enum
{
    UNUSED
} LightScheduleEvent;

typedef struct
{
    int id;
    int minutesOfDay;
    Day dayOfWeek;
} ScheduledLightEvent;

static ScheduledLightEvent scheduledEvent;


void LightScheduler_Create(void)
{
    scheduledEvent.id = UNUSED;
}

void LightScheduler_Destroy(void)
{

}

void LightScheduler_Wakeup(void)
{
    Time time;
    TimeService_GetTime(&time);

    if (scheduledEvent.id == UNUSED) return;

    if (time.minuteOfDay != scheduledEvent.minutesOfDay) return;

    LightController_TurnOn(scheduledEvent.id);
}

void LightScheduler_TurnOn(int id, Day day, int minuteOfDay)
{
    scheduledEvent.id = id;
    scheduledEvent.minutesOfDay = minuteOfDay;
    scheduledEvent.dayOfWeek = day;
}
