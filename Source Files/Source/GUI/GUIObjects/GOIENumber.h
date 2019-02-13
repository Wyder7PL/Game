#pragma once

#include "GUIObjectInfoElement.h"
#include "../../Fonts/Fonts.h"
#include "../../Functions.h"


class GOIENumber:public Object,public GUIObjectInfoElement
{
    int32_t number;
    sf::RectangleShape shape;
    sf::Text tex;
public:
    GOIENumber(Position,Position,sf::Color);
    virtual ~GOIENumber();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void ChangePosition(Position);
    virtual uint32_t GetHeight();
    virtual uint32_t GetTextWidth();
    virtual void SetToDestroy();
    void SetNumber(int32_t);
};
