#include "LightScheduler.h"
#include "LightController.h"

typedef enum
{
    UNUSED, TURN_ON, TURN_OFF
} LightScheduleEvent;

typedef struct
{
    int id;
    int minutesOfDay;
    Day dayOfWeek;
    LightScheduleEvent event;
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

    if (scheduledEvent.event == TURN_ON) {
        LightController_TurnOn(scheduledEvent.id);
    }
    else if (scheduledEvent.event == TURN_OFF) {
        LightController_TurnOff(scheduledEvent.id);
    }
}

void LightScheduler_TurnOn(int id, Day day, int minuteOfDay)
{
    scheduledEvent.id = id;
    scheduledEvent.minutesOfDay = minuteOfDay;
    scheduledEvent.dayOfWeek = day;
    scheduledEvent.event = TURN_ON;
}


void LightScheduler_TurnOff(int id, Day day, int minuteOfDay)
{
    scheduledEvent.id = id;
    scheduledEvent.minutesOfDay = minuteOfDay;
    scheduledEvent.dayOfWeek = day;
    scheduledEvent.event = TURN_OFF;
}
