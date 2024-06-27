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

class BatteryInterface
{
   public:
    BatteryInterface() {}
    virtual ~BatteryInterface() {}
    virtual void Battery_GetBatteryMilliVoltage(uint16_t* milliVoltage) = 0;
};

class BatteryMock : BatteryInterface
{
   public:
    BatteryMock() {}
    ~BatteryMock() {}
    MOCK_METHOD(void, Battery_GetBatteryMilliVoltage, (uint16_t* milliVoltage));
};

void BatteryMock_SetMock(BatteryMock* mock);
