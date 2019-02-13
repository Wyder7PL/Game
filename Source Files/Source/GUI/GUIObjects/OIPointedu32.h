#pragma once

#include "OINumber.h"
#include "GOIEPointed.h"

class OIPointedu32:public ObjectInfo
{
    uint32_t_pointer * poi;
    OINumber num;
public:
    OIPointedu32(uint32_t_pointer*,OINumber);
    virtual GUIObjectInfoElement * Create(Position);
};
