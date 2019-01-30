#ifndef D_LIGHT_SCHEDULER_H
#define D_LIGHT_SCHEDULER_H

#include "TimeService.h"

void LightScheduler_Wakeup(void);
void LightScheduler_Create(void);
void LightScheduler_Destroy(void);
void LightScheduler_TurnOn(int id, Day day, int minuteOfDay);
void LightScheduler_TurnOff(int id, Day day, int minuteOfDay);

#endif
