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

class TimerInterface
{
   public:
    TimerInterface() {}
    virtual ~TimerInterface() {}
    virtual void Timer_Initialize(void)                                                                                   = 0;
    virtual void Timer_CreateHandler(TimerHandler_t* handler, Time_t time, bool isEnableInterval, void (*callback)(void)) = 0;
    virtual void Timer_Start(TimerHandler_t* handler)                                                                     = 0;
    virtual void Timer_Stop(TimerHandler_t* handler)                                                                      = 0;
};

class TimerMock : TimerInterface
{
   public:
    TimerMock() {}
    ~TimerMock() {}
    MOCK_METHOD(void, Timer_Initialize, ());
    MOCK_METHOD(void, Timer_CreateHandler, (TimerHandler_t * handler, Time_t time, bool isEnableInterval, void (*callback)(void)));
    MOCK_METHOD(void, Timer_Start, (TimerHandler_t * handler));
    MOCK_METHOD(void, Timer_Stop, (TimerHandler_t * handler));
};

void TimerMock_SetMock(TimerMock* mock);
