#include "LightControllerSpy.h"

static int lastId;
static int lastState;
static int lightStateList[MAX_LIGHTS] = {LIGHT_STATE_UNKNOWN};

void LightController_Create(void)
{
    lastId = LIGHT_ID_UNKNOWN;
    lastState = LIGHT_STATE_UNKNOWN;
}

void LightController_Destroy(void)
{
    lastId = LIGHT_ID_UNKNOWN;
    lastState = LIGHT_STATE_UNKNOWN;
}

void LightController_TurnOn(int id)
{
    lastId = id;
    lastState = LIGHT_ON;
    lightStateList[id] = LIGHT_ON;
}

void LightController_TurnOff(int id)
{
    lastId = id;
    lastState = LIGHT_OFF;
    lightStateList[id] = LIGHT_OFF;
}

int LightControllerSpy_GetLastId(void)
{
    return lastId;
}

int LightControllerSpy_GetLastState(void)
{
    return lastState;
}

int LightControllerSpy_GetLightState(int id)
{
    return lightStateList[id];
}
