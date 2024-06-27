#include "addMock.h"

#include <gmock/gmock.h>

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>

#include "add.h"
#ifdef __cplusplus
}
#endif

static AddMock* Mock;

void AddMock_SetMock(AddMock* mock)
{
    Mock = mock;
}

uint8_t Add(uint8_t a, uint8_t b)
{
    return Mock->Add(a, b);
}
