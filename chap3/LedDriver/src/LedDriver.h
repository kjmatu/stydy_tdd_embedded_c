#ifndef D_LedDriver_H
#define D_LedDriver_H

#include <stdint.h>

void LedDriver_Create(uint16_t * address);
void LedDriver_TurnOn(uint16_t ledNumber);
void LedDriver_TurnOff(uint16_t ledNumber);
void LedDriver_Destroy(void);

#endif