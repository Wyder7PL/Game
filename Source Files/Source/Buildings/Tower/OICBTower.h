#pragma once

#include "../OICreateButton.h"
#include "GOIECBTower.h"

class OICBTower:public OICreateButton
{
public:
    OICBTower(OIText,uint32_t);
    virtual GUIObjectInfoElement * Create(Position);
};
