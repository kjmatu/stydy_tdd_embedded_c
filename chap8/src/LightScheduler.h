#ifndef __LIGHT_SCHEDULER__
#define __LIGHT_SCHEDULER__

#include "TimeService.h"

void LightScheduler_Create(void);
void LightScheduler_Destroy(void);
void LightScheduler_Wakeup(void);
void LightScheduler_ScheduleTurnOn(int id, Day day, int minuteOfDay);

#endif