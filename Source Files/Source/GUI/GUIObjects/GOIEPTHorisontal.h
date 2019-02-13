#pragma once

#include "GUIObjectInfoElement.h"
#include "CTextureReferenceIllusion.h"
#include "GOIEPicture.h"

class GOIEPTHorisontal:public Object,public GUIObjectInfoElement
{
    sf::RectangleShape background;
    std::list<GOIEPicture*> pictures;
    float border;
    float psx;
public:
    GOIEPTHorisontal(Position,Position,Position,sf::Color,std::list<CTextureReferenceIllusion>);
    virtual ~GOIEPTHorisontal();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void ChangePosition(Position);
    virtual uint32_t GetHeight();
    virtual void SetToDestroy();
};
