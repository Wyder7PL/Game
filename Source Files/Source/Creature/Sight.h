#pragma once

#include "SightEffect.h"

class Sight:public Object
{
    bool ready;
    bool destroy;
public:
    Sight(Position,float);
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    std::list <Info> Objects;
    void SetReady();
    bool Ready();
    void Erase();
};
