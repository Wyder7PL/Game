#pragma once

#include "GOIECBForester.h"
#include "../OICreateButton.h"



class OICBForester:public OICreateButton
{
public:
    OICBForester(OIText,uint32_t);
    virtual GUIObjectInfoElement * Create(Position);
};
