#pragma once

#include "../OICreateButton.h"
#include "GOIECBMagazine.h"

class OICBMagazine:public OICreateButton
{
public:
    OICBMagazine(OIText,uint32_t);
    virtual GUIObjectInfoElement * Create(Position);
};
