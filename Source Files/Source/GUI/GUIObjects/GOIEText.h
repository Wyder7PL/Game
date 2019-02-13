#pragma once
#include "GUIObjectInfoElement.h"
#include "../../WrapedText.h"
#include "../../Functions.h"


class GOIEText:public Object,public GUIObjectInfoElement
{

    sf::RectangleShape shape;
    WrapedText tex;
public:
    GOIEText(Position,Position,sf::Color,std::string);
    virtual ~GOIEText();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void ChangePosition(Position);
    virtual uint32_t GetHeight();
    virtual void SetToDestroy();
};
