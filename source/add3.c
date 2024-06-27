#ifdef __cplusplus
extern "C"
{
#endif
#include "add3.h"

#include "add.h"
#ifdef __cplusplus
}
#endif

uint8_t Add3(uint8_t a, uint8_t b)
{
    return Sub(a, b) - 3;
}
