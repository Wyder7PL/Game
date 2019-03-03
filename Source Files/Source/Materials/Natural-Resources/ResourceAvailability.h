#pragma once

#include <stdint.h>

class ResourceAvailability
{
    uint32_t amoumt;
    uint32_t type;
public:
    ResourceAvailability(uint32_t);
    uint32_t GetAmount();
    uint32_t GetType();
    void SetAmount(uint32_t);
    void SetType(uint32_t);
};
