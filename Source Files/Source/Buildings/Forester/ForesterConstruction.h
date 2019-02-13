#pragma once

#include "../BuildingConstruction.h"
#include "Forester.h"

class ForesterConstruction:public BuildingConstruction
{
public:
    ForesterConstruction(Position,uint32_t);
protected:
    virtual void Create();
};
