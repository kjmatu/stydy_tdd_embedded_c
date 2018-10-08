#include <stdlib.h>
#include <stdint.h>
#include <memory.h>

#include "LedDriver.h"

static uint16_t * ledsAdress;
static uint16_t ledsImage;

enum {ALL_LEDS_ON = ~0, ALL_LEDS_OFF = ~ALL_LEDS_ON};

static uint16_t convertLedNumberToBit(int ledNumber)
{
    return 1 << (ledNumber - 1);
}

void LedDriver_Create(uint16_t * address)
{
    ledsAdress = address;
    ledsImage = ALL_LEDS_OFF;
    *ledsAdress = ledsImage;
}

void LedDriver_TurnOn(uint16_t ledNumber)
{
    ledsImage |= convertLedNumberToBit(ledNumber);
    *ledsAdress = ledsImage;
}

void LedDriver_TurnOff(uint16_t ledNumber)
{
    ledsImage &= ~(convertLedNumberToBit(ledNumber));
    *ledsAdress = ledsImage;
}

void LedDriver_TurnAllOn(void)
{
    ledsImage = ALL_LEDS_ON;
    *ledsAdress = ledsImage;
}

void LedDriver_Destroy(void)
{
}


