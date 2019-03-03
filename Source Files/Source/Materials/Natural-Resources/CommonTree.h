#pragma once

#include "../../Markable/TileOccupy.h"
#include "../../HP/WoodenHP.h"
#include "NaturalResource.h"
#include "TreeCollision.h"
#include "../../AddObject.h"

class CommonTree:public NaturalResource,public TileOccupy
{
    sf::CircleShape shape;
    WoodenHP * hp;
public:
    CommonTree(Position);
    virtual ~CommonTree();

    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;

    virtual bool TakeResource();

    virtual void DealDamage(uint32_t,uint32_t);
    virtual void CreateInfo(std::list<Info>&);

};
