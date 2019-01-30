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
    Day day;
    LightScheduleEvent event;
} ScheduledLightEvent;

static ScheduledLightEvent scheduledEvent;


static void scheduleEvent(int id, Day day, int minutesOfDay, int event)
{
    scheduledEvent.id = id;
    scheduledEvent.day = day;
    scheduledEvent.minutesOfDay = minutesOfDay;
    scheduledEvent.event = event;
}

static void operateLight(ScheduledLightEvent *lightEvent)
{
    if (lightEvent->event == TURN_ON) {
        LightController_TurnOn(lightEvent->id);
    }
    else if (lightEvent->event == TURN_OFF) {
        LightController_TurnOff(lightEvent->id);
    }
}

static void processEventDueNow(Time *time, ScheduledLightEvent *lightEvent)
{
    int reactionDay = lightEvent->day;
    int today = time->dayOfWeek;

    if (lightEvent->id == UNUSED) return;

    if (reactionDay != EVERYDAY && reactionDay != today) return;

    if (lightEvent->minutesOfDay != time->minuteOfDay) return;

    operateLight(lightEvent);
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

    processEventDueNow(&time, &scheduledEvent);
}

void LightScheduler_TurnOn(int id, Day day, int minuteOfDay)
{
    scheduleEvent(id, day, minuteOfDay, TURN_ON);
}


void LightScheduler_TurnOff(int id, Day day, int minuteOfDay)
{
    scheduleEvent(id, day, minuteOfDay, TURN_OFF);
}
