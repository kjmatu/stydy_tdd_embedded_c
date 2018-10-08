#include <stdlib.h>
#include <stdint.h>
#include <memory.h>

#include "LedDriver.h"

static uint16_t * ledsAddress;
static uint16_t ledsImage;

enum {ALL_LEDS_ON = ~0, ALL_LEDS_OFF = ~ALL_LEDS_ON};

static uint16_t convertLedNumberToBit(int ledNumber)
{
    return 1 << (ledNumber - 1);
}

void LedDriver_Create(uint16_t * address)
{
    // Ledを直接読めないのでledsImageに一旦書き込み用のバッファを用意し
    // 書き込むときはledsImageからledsAddressに書き込む
    // こうすることで外部からledsAddressに書き込まれても
    // ledsImageとledsAddressを同期すればドライバ経由での書き込み
    // 状態を保持できる
    ledsAddress = address;
    ledsImage = ALL_LEDS_OFF;
    *ledsAddress = ledsImage;
}

void LedDriver_TurnOn(uint16_t ledNumber)
{
    ledsImage |= convertLedNumberToBit(ledNumber);
    *ledsAddress = ledsImage;
}

void LedDriver_TurnOff(uint16_t ledNumber)
{
    ledsImage &= ~(convertLedNumberToBit(ledNumber));
    *ledsAddress = ledsImage;
}

void LedDriver_TurnAllOn(void)
{
    ledsImage = ALL_LEDS_ON;
    *ledsAddress = ledsImage;
}

void LedDriver_Destroy(void)
{
}


