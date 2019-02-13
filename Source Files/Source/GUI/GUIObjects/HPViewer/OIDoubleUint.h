#pragma once

#include "../ObjectInfo.h"
#include "../../../Pointers/uint32_t_pointer.h"

class OIDoubleUint:public ObjectInfo
{
    uint32_t_pointer * poi1;
    uint32_t_pointer * poi2;
public:
    OIDoubleUint(uint32_t_pointer*,uint32_t_pointer*);
    uint32_t_pointer * GetFirst();
    uint32_t_pointer * GetSecond();
};
