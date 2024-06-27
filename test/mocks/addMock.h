#ifndef ADDMOCK_H
#define ADDMOCK_H

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

class AddInterface
{
   public:
    AddInterface() {}
    virtual ~AddInterface() {}
    virtual uint8_t Add(uint8_t a, uint8_t b) = 0;
    virtual uint8_t Sub(uint8_t a, uint8_t b) = 0;
};

class AddMock : AddInterface
{
   public:
    AddMock() {}
    ~AddMock() {}
    MOCK_METHOD(uint8_t, Add, (uint8_t a, uint8_t b));
    MOCK_METHOD(uint8_t, Sub, (uint8_t a, uint8_t b));
};

void AddMock_SetMock(AddMock* mock);

#endif  // ADDMOCK_H
