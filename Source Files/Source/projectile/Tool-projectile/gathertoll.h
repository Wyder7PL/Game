#pragma once
#include "../projectile.h"
#include "gathertollEff.h"

class gathertoll:public projectile
{
    uint32_t id;
public:
    gathertoll(Position,uint32_t,uint32_t);
    virtual ~gathertoll();

    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
};
