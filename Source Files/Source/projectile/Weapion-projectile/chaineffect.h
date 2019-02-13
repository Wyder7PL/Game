#pragma once
#include "../projectileEff.h"
#include "../../Functions.h"

class chaineffect:public Object
{
    sf::CircleShape TEST;
    public:
        chaineffect(Position);
        virtual ~chaineffect();

        virtual void Step();
        virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;

        uint32_t Existance;
};
