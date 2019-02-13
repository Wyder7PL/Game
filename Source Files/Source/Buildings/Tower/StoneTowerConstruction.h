#pragma once

#include "../BuildingConstruction.h"
#include "StoneTower.h"

class StoneTowerConstruction:public BuildingConstruction
{
public:
    StoneTowerConstruction(Position,uint32_t);
protected:
    virtual void Create();
};
