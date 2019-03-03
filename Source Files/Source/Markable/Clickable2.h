#pragma once

#include "Markable.h"
#include "../Functions.h"


class Clickable2:public Markable
{
    bool pressed;
public:
    Clickable2(Position);
    virtual ~Clickable2();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void Selected()=0;
};

