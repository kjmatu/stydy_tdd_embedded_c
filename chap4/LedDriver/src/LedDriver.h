#ifndef D_LedDriver_H
#define D_LedDriver_H

#include <stdint.h>
#include <stdbool.h>

void LedDriver_Create(uint16_t * address);
void LedDriver_TurnOn(uint16_t ledNumber);
void LedDriver_TurnOff(uint16_t ledNumber);
void LedDriver_TurnAllOn(void);
void LedDriver_TurnAllOff(void);
bool LedDriver_IsOn(uint16_t ledNumber);
bool LedDriver_IsOff(uint16_t ledNumber);
void LedDriver_Destroy(void);

#endif