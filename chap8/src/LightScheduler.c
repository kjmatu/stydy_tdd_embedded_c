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


static void scheduleEvent(int id, Day day, int minutesOfDay, int event)
{
    scheduledEvent.id = id;
    scheduledEvent.dayOfWeek = day;
    scheduledEvent.minutesOfDay = minutesOfDay;
    scheduledEvent.event = event;
}

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
    scheduleEvent(id, day, minuteOfDay, TURN_ON);
}


void LightScheduler_TurnOff(int id, Day day, int minuteOfDay)
{
    scheduleEvent(id, day, minuteOfDay, TURN_OFF);
}
