#pragma once

#include "../OICreateButton.h"
#include "GOIECBWorkshop.h"

class OICBWorkshop:public OICreateButton
{
public:
    OICBWorkshop(OIText,uint32_t);
    virtual GUIObjectInfoElement * Create(Position);
};
