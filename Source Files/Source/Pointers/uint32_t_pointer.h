#pragma once

#include "SafePointer.h"

class uint32_t_pointer:public SafePointer
{
    uint32_t * pointer;
public:
    uint32_t_pointer(uint32_t*);
    uint32_t * GetPointer();
};
