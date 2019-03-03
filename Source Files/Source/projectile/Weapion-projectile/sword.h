#pragma once
#include "../projectile.h"
#include "swordEff.h"

class sword:public projectile
{
    sf::CircleShape TEST;
    public:
        sword(Position,uint32_t,float,uint32_t);

        virtual void Step();
        virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;

};
