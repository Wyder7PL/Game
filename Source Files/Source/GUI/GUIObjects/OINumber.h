#pragma once

#include "ObjectInfo.h"
#include "GOIENumber.h"

class OINumber:public ObjectInfo
{
    Position wAh;
    sf::Color col;
    int32_t num;
public:
    OINumber(Position,sf::Color,int32_t);
    virtual GUIObjectInfoElement * Create(Position);
};
