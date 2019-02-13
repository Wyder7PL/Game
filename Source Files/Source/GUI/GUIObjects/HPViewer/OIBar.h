#pragma once

#include "OIDoubleUint.h"
#include "GUIBar.h"

class OIBar:public OIDoubleUint
{
    sf::Color col;
    float width;
public:
    OIBar(uint32_t_pointer*,uint32_t_pointer*,sf::Color,float);
    virtual GUIObjectInfoElement * Create(Position);
};

