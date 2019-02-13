#pragma once

#include "../BuildingConstruction.h"
#include "Tower.h"

class TowerConstruction:public BuildingConstruction
{
public:
    TowerConstruction(Position,uint32_t);
protected:
    virtual void Create();
};
