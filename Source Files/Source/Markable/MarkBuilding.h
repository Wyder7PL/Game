#pragma once



#include "Clickable1.h"
#include "TileOccupy.h"


class MarkBuilding:public Clickable1,public TileOccupy
{
    sf::CircleShape mark;
public:
    MarkBuilding(Position);
    virtual ~MarkBuilding();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void Selected();
    virtual void DealDamage(uint32_t,uint32_t)=0;
    void MarkSize(float);
protected:
};
