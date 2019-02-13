#pragma once

#include "../../GUI/GUIObjects/GOIENumber.h"
#include "../../GUI/GUIObjects/MultiButtons/GOIESingleClickButton.h"

class GOIEPushareButton:public Object,public GUIObjectInfoElement
{
    GOIENumber number;
    GOIESingleClickButton button;
public:
    GOIEPushareButton(Position,Position,sf::Color,void_pointer*,void_pointer*);
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void ChangePosition(Position);
    virtual uint32_t GetHeight();
    virtual void SetToDestroy();
    void SetNumber(uint32_t);
};
