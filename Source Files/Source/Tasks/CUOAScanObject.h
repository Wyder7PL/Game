#pragma once

#include "../Anoyher/Object.hpp"
#include "../Functions.h"

class CUOAScanObject:public Object
{
    sf::CircleShape temp;
public:
    CUOAScanObject(Position,float);
    virtual void SetToDestroy();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
};
