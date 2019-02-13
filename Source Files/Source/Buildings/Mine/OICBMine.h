#pragma once

#include "../OICreateButton.h"
#include "GOIECBMine.h"

class OICBMine:public OICreateButton
{
public:
    OICBMine(OIText,uint32_t);
    virtual GUIObjectInfoElement * Create(Position);
};
