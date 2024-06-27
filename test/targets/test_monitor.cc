#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "batteryMock.h"
#include "timerMock.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "monitor.h"
#ifdef __cplusplus
}
#endif

using ::testing::_;
using ::testing::Args;
using ::testing::DoAll;
using ::testing::NiceMock;
using ::testing::NotNull;
using ::testing::Return;
using ::testing::SaveArg;
using ::testing::SetArgPointee;

class MonitorInitializeTest : public ::testing::Test
{
   protected:
    virtual void SetUp()
    {
        batteryMock = new NiceMock<BatteryMock>;
        timerMock   = new NiceMock<TimerMock>;

        BatteryMock_SetMock(batteryMock);
        TimerMock_SetMock(timerMock);
    }
    virtual void TearDown()
    {
        delete batteryMock;
        delete timerMock;
    }
    NiceMock<BatteryMock>* batteryMock;
    NiceMock<TimerMock>*   timerMock;
};

TEST_F(MonitorInitializeTest, ShouldExecuteTimerInitialize)
{
    EXPECT_CALL(*timerMock, Timer_Initialize())
        .Times(1);
    Monitor_Initialize();
}

TEST_F(MonitorInitializeTest, ShouldCreateTimerHandler)
{
    Time_t time = {0, 0};
    EXPECT_CALL(*timerMock, Timer_CreateHandler(NotNull(), _, true, NotNull()))
        .Times(1)
        .WillOnce(SaveArg<1>(&time));
    EXPECT_EQ(time.second, 0);
    EXPECT_EQ(time.milliSecond, 0);
    Monitor_Initialize();
    EXPECT_EQ(time.second, 5);
    EXPECT_EQ(time.milliSecond, 0);
}

TEST_F(MonitorInitializeTest, ShouldStartTimer)
{
    EXPECT_CALL(*timerMock, Timer_Start(NotNull()))
        .Times(1);
    Monitor_Initialize();
}

TEST_F(MonitorInitializeTest, ShouldReturnBatteryLevelLow)
{
    Monitor_Initialize();
    EXPECT_EQ(Monitor_GetBatteryLevel(), BATTERY_LEVEL_LOW);
}

class MonitorUpdateBatteryLevelTest : public ::testing::Test
{
   protected:
    virtual void SetUp()
    {
        batteryMock = new NiceMock<BatteryMock>;
        timerMock   = new NiceMock<TimerMock>;

        BatteryMock_SetMock(batteryMock);
        TimerMock_SetMock(timerMock);

        ON_CALL(*timerMock, Timer_CreateHandler(_, _, _, _))
            .WillByDefault(SaveArg<3>(&timerCallback));
        Monitor_Initialize();
    }
    virtual void TearDown()
    {
        delete batteryMock;
        delete timerMock;
    }
    NiceMock<BatteryMock>* batteryMock;
    NiceMock<TimerMock>*   timerMock;

    void (*timerCallback)(void);
};

TEST_F(MonitorUpdateBatteryLevelTest, ShouldGetBatteryMilliVoltage)
{
    EXPECT_CALL(*batteryMock, Battery_GetBatteryMilliVoltage(NotNull()))
        .Times(1);
    timerCallback();
}

TEST_F(MonitorUpdateBatteryLevelTest, ShouldReturnBatteryLevelLowWhenBatteryMilliVoltageIs0)
{
    EXPECT_EQ(Monitor_GetBatteryLevel(), BATTERY_LEVEL_LOW);
    EXPECT_CALL(*batteryMock, Battery_GetBatteryMilliVoltage(_))
        .Times(1)
        .WillOnce(SetArgPointee<0>(0));
    timerCallback();
    EXPECT_EQ(Monitor_GetBatteryLevel(), BATTERY_LEVEL_LOW);
}

TEST_F(MonitorUpdateBatteryLevelTest, ShouldReturnBatteryLevelLowWhenBatteryMilliVoltageIs1000)
{
    EXPECT_EQ(Monitor_GetBatteryLevel(), BATTERY_LEVEL_LOW);
    EXPECT_CALL(*batteryMock, Battery_GetBatteryMilliVoltage(_))
        .Times(1)
        .WillOnce(SetArgPointee<0>(1000));
    timerCallback();
    EXPECT_EQ(Monitor_GetBatteryLevel(), BATTERY_LEVEL_LOW);
}

TEST_F(MonitorUpdateBatteryLevelTest, ShouldReturnBatteryLevelMidWhenBatteryMilliVoltageIs1001)
{
    EXPECT_EQ(Monitor_GetBatteryLevel(), BATTERY_LEVEL_LOW);
    EXPECT_CALL(*batteryMock, Battery_GetBatteryMilliVoltage(_))
        .Times(1)
        .WillOnce(SetArgPointee<0>(1001));
    timerCallback();
    EXPECT_EQ(Monitor_GetBatteryLevel(), BATTERY_LEVEL_MID);
}

TEST_F(MonitorUpdateBatteryLevelTest, ShouldReturnBatteryLevelMidWhenBatteryMilliVoltageIs2000)
{
    EXPECT_EQ(Monitor_GetBatteryLevel(), BATTERY_LEVEL_LOW);
    EXPECT_CALL(*batteryMock, Battery_GetBatteryMilliVoltage(_))
        .Times(1)
        .WillOnce(SetArgPointee<0>(2000));
    timerCallback();
    EXPECT_EQ(Monitor_GetBatteryLevel(), BATTERY_LEVEL_MID);
}

TEST_F(MonitorUpdateBatteryLevelTest, ShouldReturnBatteryLevelHighWhenBatteryMilliVoltageIs2001)
{
    EXPECT_EQ(Monitor_GetBatteryLevel(), BATTERY_LEVEL_LOW);
    EXPECT_CALL(*batteryMock, Battery_GetBatteryMilliVoltage(_))
        .Times(1)
        .WillOnce(SetArgPointee<0>(2001));
    timerCallback();
    EXPECT_EQ(Monitor_GetBatteryLevel(), BATTERY_LEVEL_HIGH);
}

TEST_F(MonitorUpdateBatteryLevelTest, ShouldReturnBatteryLevelHighWhenBatteryMilliVoltageIs5000)
{
    EXPECT_EQ(Monitor_GetBatteryLevel(), BATTERY_LEVEL_LOW);
    EXPECT_CALL(*batteryMock, Battery_GetBatteryMilliVoltage(_))
        .Times(1)
        .WillOnce(SetArgPointee<0>(5000));
    timerCallback();
    EXPECT_EQ(Monitor_GetBatteryLevel(), BATTERY_LEVEL_HIGH);
}
