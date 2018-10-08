#include <stdlib.h>
#include <stdbool.h>
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

static void setLedImageBit(int ledNumber)
{
    ledsImage |= convertLedNumberToBit(ledNumber);
}

static void clearLedImageBit(int ledNumber)
{
    ledsImage &= ~convertLedNumberToBit(ledNumber);
}

enum {FIRST_LED = 1, LAST_LED = 16};
static bool IsLedOutOfBounds(int ledNumber)
{
    return (ledNumber < FIRST_LED) || (ledNumber > LAST_LED);
}

static void upateHardware(void)
{
    *ledsAddress = ledsImage;
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
    upateHardware();
}

void LedDriver_TurnOn(uint16_t ledNumber)
{
    if (IsLedOutOfBounds(ledNumber))
        return;
    setLedImageBit(ledNumber);
    upateHardware();
}

void LedDriver_TurnOff(uint16_t ledNumber)
{
    if (IsLedOutOfBounds(ledNumber))
         return;
    clearLedImageBit(ledNumber);
    upateHardware();
}

void LedDriver_TurnAllOn(void)
{
    ledsImage = ALL_LEDS_ON;
    upateHardware();
}

bool LedDriver_IsOn(uint16_t ledNumber)
{
    uint16_t ledStatus = ledsImage & convertLedNumberToBit(ledNumber);
    return (0 != ledStatus);
}

bool LedDriver_IsOff(uint16_t ledNumber)
{
    return !LedDriver_IsOn(ledNumber);
}

void LedDriver_Destroy(void)
{
}


