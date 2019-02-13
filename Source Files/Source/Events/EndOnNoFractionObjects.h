#pragma once

#include "../Anoyher/Object.hpp"
#include "../AddObject.h"
#include "CollisionFractionEffect.h"
#include "RoundEnd.h"

class EndOnNoFractionObjects:public Object
{
    bool SoWhat;
    bool stillexists;
    uint32_t fraction;
public:
    EndOnNoFractionObjects(bool,uint32_t);
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    void StillExists(bool);
};
