#pragma once
#include <stdint.h>
#include "../Anoyher/Position.h"

struct BuildOrder
{
    BuildOrder();
    bool ordered = false;
    Position pos;
    uint32_t TargetID;
    uint32_t Type;
    uint32_t Hits;
};
