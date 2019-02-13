#pragma once

#include "GOIECBStoneTower.h"
#include "../OICreateButton.h"

class OICBStoneTower:public OICreateButton
{
public:
    OICBStoneTower(OIText,uint32_t);
    virtual GUIObjectInfoElement * Create(Position);
};
