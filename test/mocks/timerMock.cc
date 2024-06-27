#include "timerMock.h"

#include <gmock/gmock.h>

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdbool.h>

#include "timer.h"
#ifdef __cplusplus
}
#endif

static TimerMock* Mock;

void TimerMock_SetMock(TimerMock* mock)
{
    Mock = mock;
}

void Timer_Initialize(void)
{
    Mock->Timer_Initialize();
}

void Timer_CreateHandler(TimerHandler_t* handler, Time_t time, bool isEnableInterval, void (*callback)(void))
{
    Mock->Timer_CreateHandler(handler, time, isEnableInterval, callback);
}

void Timer_Start(TimerHandler_t* handler)
{
    Mock->Timer_Start(handler);
}

void Timer_Stop(TimerHandler_t* handler)
{
    Mock->Timer_Stop(handler);
}
