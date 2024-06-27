#include "batteryMock.h"

#include <gmock/gmock.h>

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>

#include "battery.h"
#ifdef __cplusplus
}
#endif

static BatteryMock* Mock;

void BatteryMock_SetMock(BatteryMock* mock)
{
    Mock = mock;
}

void Battery_GetBatteryMilliVoltage(uint16_t* milliVoltage)
{
    Mock->Battery_GetBatteryMilliVoltage(milliVoltage);
}
