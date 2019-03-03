#pragma once
#include "../projectile.h"
#include "bulletEff.h"

class bullet:public projectile
{
    uint32_t damage;
    uint32_t step;
    sf::CircleShape TEST;
    public:
        bullet(Position,uint32_t,uint32_t);
        virtual ~bullet();

        virtual void Step();
        virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;

        uint32_t Existance;

    protected:
    private:
};
