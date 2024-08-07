#ifdef __cplusplus
extern "C"
{
#endif
#include "add4.h"

#include "add.h"
#ifdef __cplusplus
}
#endif

uint8_t Add4(uint8_t a, uint8_t b)
{
    return Sub(a, b) + 4;
}
