#pragma once
#include "../projectile.h"
#include "hookEff.h"
#include "chaineffect.h"

class hook:public projectile
{
    uint32_t step;
    sf::CircleShape TEST;
    public:
        hook(Position,uint32_t);
        virtual ~hook();

        virtual void Step();
        virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;

        uint32_t Existance;

    protected:
    private:
};
