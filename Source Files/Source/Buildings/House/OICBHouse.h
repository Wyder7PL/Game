#pragma once

#include "../OICreateButton.h"
#include "GOIECBHouse.h"

class OICBHouse:public OICreateButton
{
public:
    OICBHouse(OIText,uint32_t);
    virtual GUIObjectInfoElement * Create(Position);
};
