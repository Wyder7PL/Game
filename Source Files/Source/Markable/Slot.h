#pragma once

#include "Markable.h"

class Slot
{
public:
    Slot();
    Markable * Occupant;
    uint32_t type;
    bool reserved;
    bool FirstHour;
};

