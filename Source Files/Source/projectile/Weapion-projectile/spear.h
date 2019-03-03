#pragma once
#include "spearEff.h"
#include "../projectile.h"

class spear:public projectile
{
    sf::CircleShape TEST;
    public:
        spear(Position,uint32_t);
        virtual ~spear();
        virtual void Step();
        virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
};
