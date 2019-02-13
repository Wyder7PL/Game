#pragma once

#include "../BuildingConstruction.h"
#include "Mine.h"

class MineConstruction:public BuildingConstruction
{
public:
    MineConstruction(Position,uint32_t);
protected:
    virtual void Create();
};
