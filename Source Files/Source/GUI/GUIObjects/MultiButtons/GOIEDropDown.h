#pragma once

#include "../GUIObjectInfoElement.h"
#include "../../../Markable/Clickable2.h"
#include "../../../Pointers/void_pointer.h"

class GOIEDropDown:public Object,public GUIObjectInfoElement
{
    void_pointer * Elements;
public:
    GOIEDropDown(Position,Position,void_pointer*);
    virtual ~GOIEDropDown();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual uint32_t GetHeight();
    virtual void SetToDestroy();
    virtual void ChangePosition(Position);
private:
};
