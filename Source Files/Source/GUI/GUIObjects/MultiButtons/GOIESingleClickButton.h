#pragma once

#include "../GUIObjectInfoElement.h"
#include "../../../Markable/Clickable2.h"
#include "../../../Pointers/void_pointer.h"


class GOIESingleClickButton:public GUIObjectInfoElement,public Clickable2
{
    sf::RectangleShape shape;
    sf::Sprite sprite;
    void_pointer * state;
    void_pointer * disabled;
public:
    GOIESingleClickButton(Position,Position,void_pointer*,void_pointer*);
    GOIESingleClickButton(Position,Position,sf::Texture&,void_pointer*,void_pointer*);
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual uint32_t GetHeight();
    virtual void SetToDestroy();
    virtual void ChangePosition(Position);
    virtual void Selected();
};
