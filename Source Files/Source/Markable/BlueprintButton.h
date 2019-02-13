#pragma once

#include "Clickable1.h"
#include "../Functions.h"

class BlueprintButton:public Clickable1
{
    sf::RectangleShape border;
public:
    BlueprintButton(Position,uint32_t*);
    virtual ~BlueprintButton();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void Selected();
protected:
    uint32_t * PlayerFraction;
};
