#pragma once

#include "../GUIObjectInfoElement.h"
#include "OIDoubleUint.h"
#include "GUIHPViewer.h"

class OIHPViewer:public OIDoubleUint
{
public:
    OIHPViewer(uint32_t_pointer*,uint32_t_pointer*);
    virtual GUIObjectInfoElement * Create(Position);
};
