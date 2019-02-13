#pragma once
#include "../projectile.h"
#include "constructiontoolEff.h"

class constructiontool:public projectile
{
    sf::CircleShape TEST;
public:
    constructiontool(Position,uint32_t,uint32_t);
    virtual ~constructiontool();

    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
};
