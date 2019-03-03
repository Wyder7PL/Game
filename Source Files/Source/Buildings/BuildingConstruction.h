#pragma once

#include "Collision.h"
#include "Building.h"



class BuildingConstruction:public Construction
{

    sf::RectangleShape shape;
public:
    BuildingConstruction(Position,uint32_t=0);
    virtual ~BuildingConstruction();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void CreateInfo(std::list<Info>&);
    void TESTCreateDemand(uint32_t,uint32_t);
protected:
    virtual void Create();
};

