#pragma once

#include "../OICreateButton.h"
#include "GOIECBTavern.h"


class OICBTavern:public OICreateButton
{
public:
    OICBTavern(OIText,uint32_t);
    virtual GUIObjectInfoElement * Create(Position);
};
