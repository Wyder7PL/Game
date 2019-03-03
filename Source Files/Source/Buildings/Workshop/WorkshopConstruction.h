#pragma once

#include "../BuildingConstruction.h"
#include "Workshop.h"

class WorkshopConstruction:public BuildingConstruction
{
public:
    WorkshopConstruction(Position,uint32_t);
protected:
    virtual void Create();
};
