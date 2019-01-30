#include "LightScheduler.h"
#include "LightController.h"

typedef enum
{
    UNUSED, TURN_ON, TURN_OFF
} LightScheduleEvent;

typedef struct
{
    int id;
    int minuteOfDay;
    Day day;
    LightScheduleEvent event;
} ScheduledLightEvent;

static ScheduledLightEvent scheduledEvent;


static void scheduleEvent(int id, Day day, int minuteOfDay, int event)
{
    scheduledEvent.id = id;
    scheduledEvent.day = day;
    scheduledEvent.minuteOfDay = minuteOfDay;
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

static int DoesLightRespondToday(Time *time, int reactionDay)
{
    int today = time->dayOfWeek;

    if (reactionDay == EVERYDAY) return TRUE;

    if (reactionDay == today) return TRUE;

    if (reactionDay == WEEKEND && (SATURDAY == today || SUNDAY == today)) return TRUE;

    if (reactionDay == WEEKDAY && today >= MONDAY && today <= FRIDAY) return TRUE;

    return FALSE;
}

static void processEventDueNow(Time *time, ScheduledLightEvent *lightEvent)
{
    if (lightEvent->id == UNUSED) return;

    if (!DoesLightRespondToday(time, lightEvent->day)) return;

    if (lightEvent->minuteOfDay != time->minuteOfDay) return;

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
