#include "OIDoubleUint.h"

OIDoubleUint::OIDoubleUint(uint32_t_pointer * pointer1,uint32_t_pointer * pointer2)
:poi1(pointer1),poi2(pointer2){}

uint32_t_pointer * OIDoubleUint::GetFirst()
{
    return poi1;
}
uint32_t_pointer * OIDoubleUint::GetSecond()
{
    return poi2;
}
