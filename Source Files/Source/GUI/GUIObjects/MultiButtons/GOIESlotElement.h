#pragma once

#include "../GUIObjectInfoElement.h"
#include "../../../Markable/Clickable2.h"
#include "GOIESingleClickButton.h"
#include "../../../Textures/Textures.h"

class GOIESlotElement:public Object,public GUIObjectInfoElement
{
    sf::Sprite item;
    GOIESingleClickButton kick;
    sf::RectangleShape border;

    void Constructor();
public:
    GOIESlotElement(Position,void_pointer*,void_pointer*);
    GOIESlotElement(Position,const sf::Texture&,void_pointer*,void_pointer*);
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual uint32_t GetHeight();
    virtual void ChangePosition(Position);
    virtual void SetToDestroy();
};
