#pragma once

#include "Tavern.h"
#include "../BuildingConstruction.h"

class TavernConstruction:public BuildingConstruction
{
public:
    TavernConstruction(Position,uint32_t);
protected:
    virtual void Create();
};
