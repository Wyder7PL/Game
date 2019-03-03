#pragma once

#include "GOIEMBSelectOneButton.h"
#include "../GUIObjectInfoElement.h"
#include "../../../Markable/Clickable2.h"
#include "../../../GUI/GUIObjects/CTextureReferenceIllusion.h"
#include "../../../Pointers/uint32_t_pointer.h"

class GOIEMBSelectOne:public Object,public GUIObjectInfoElement
{
protected:
    uint32_t_pointer * Selected;
    std::list <GOIEMBSelectOneButton*> Buttons;
    uint32_t ButtonWidth;
public:
    GOIEMBSelectOne(Position,Position,Position,uint32_t,uint32_t_pointer*);
    GOIEMBSelectOne(Position,Position,std::list<CTextureReferenceIllusion>,Position,uint32_t,uint32_t_pointer*);
    virtual ~GOIEMBSelectOne();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual uint32_t GetHeight();
    virtual void SetToDestroy();
    virtual void ChangePosition(Position);
    void Disable(uint32_t,bool);
protected:
    void DeselectAll();
};
