#include <stdlib.h>
#include <stdint.h>
#include <memory.h>

#include "LedDriver.h"

static uint16_t * ledsAdress;

enum {ALL_LEDS_ON = ~0, ALL_LEDS_OFF = ~ALL_LEDS_ON};

static uint16_t convertLedNumberToBit(int ledNumber)
{
    return 1 << (ledNumber - 1);
}

void LedDriver_Create(uint16_t * address)
{
    ledsAdress = address;
    *ledsAdress = ALL_LEDS_OFF;
}

void LedDriver_TurnOn(uint16_t ledNumber)
{
    *ledsAdress |= convertLedNumberToBit(ledNumber);
}

void LedDriver_TurnOff(uint16_t ledNumber)
{
    *ledsAdress &= ~convertLedNumberToBit(ledNumber);
}

void LedDriver_TurnAllOn(void)
{
    *ledsAdress = ALL_LEDS_ON;
}

void LedDriver_Destroy(void)
{
}


