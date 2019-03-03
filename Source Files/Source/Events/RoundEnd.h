#pragma once

#include "../Anoyher/Object.hpp"
#include "../Fonts/Fonts.h"

class RoundEnd:public Object
{
    uint32_t TillTheEnd;
    sf::Text TheLastThingYouSee;
public:
    static uint32_t RoundEndState;
    RoundEnd(Position,bool);
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
};
