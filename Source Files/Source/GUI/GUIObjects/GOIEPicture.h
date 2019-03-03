#pragma once
#include "GUIObjectInfoElement.h"
#include "../../Functions.h"

class GOIEPicture:public Object,public GUIObjectInfoElement
{
    sf::RectangleShape shape;
    sf::Sprite picture;
public:
    GOIEPicture(Position,Position,sf::Color,const sf::Texture&);
    virtual ~GOIEPicture();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void ChangePosition(Position);
    virtual uint32_t GetHeight();
    virtual void SetToDestroy();
};
