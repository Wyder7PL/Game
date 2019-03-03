#pragma once

#include "../GUIObjectInfoElement.h"
#include "../../../Markable/Clickable2.h"
#include "../CTextureReferenceIllusion.h"
#include "GOIESlotElement.h"

class GOIESlotElementsStorage:public Object,public GUIObjectInfoElement
{
    std::list<GOIESlotElement*> Slots;
public:
    GOIESlotElementsStorage(Position,std::list<void_pointer*>,std::list<CTextureReferenceIllusion>);
    ~GOIESlotElementsStorage();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual uint32_t GetHeight();
    virtual void ChangePosition(Position);
    virtual void SetToDestroy();
};
