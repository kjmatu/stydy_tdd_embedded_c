#include <stdlib.h>
#include <stdint.h>
#include <memory.h>

#include "LedDriver.h"

static uint16_t * ledsAdress;

void LedDriver_Create(uint16_t * address)
{
    ledsAdress = address;
    *ledsAdress = 0;
}

void LedDriver_TurnOn(uint16_t ledNumber)
{
    *ledsAdress = 1;
}

void LedDriver_TurnOff(uint16_t ledNumber)
{
    *ledsAdress = 0;
}

void LedDriver_Destroy(void)
{
}


