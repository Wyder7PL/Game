#pragma once

#include "Markable.h"
#include "../Functions.h"


class Clickable1:public Markable
{
    bool pressed;
public:
    Clickable1(Position);
    virtual ~Clickable1();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void Selected()=0;
    virtual void Deselected();

};
