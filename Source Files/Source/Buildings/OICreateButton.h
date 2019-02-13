#pragma once

#include "../GUI/GUIObjects/GUIObjectInfoElement.h"
#include "../GUI/GUIObjects/OIText.h"
#include "GOIECreateButton.h"

class OICreateButton:public ObjectInfo
{
    OIText tex;
    uint32_t PlayerFraction;
public:
    virtual GUIObjectInfoElement * Create(Position);
    OICreateButton(OIText,uint32_t);
    virtual ~OICreateButton();
    OIText GetTex();
    uint32_t GetPlayerFraction();
};
