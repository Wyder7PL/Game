#pragma once

#include "../BuildingConstruction.h"
#include "House.h"

class HouseConstruction:public BuildingConstruction
{
public:
    HouseConstruction(Position,uint32_t);
protected:
    virtual void Create();
};
