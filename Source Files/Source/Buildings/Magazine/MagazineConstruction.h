#pragma once

#include "../BuildingConstruction.h"
#include "Magazine.h"

class MagazineConstruction:public BuildingConstruction
{
public:
    MagazineConstruction(Position,uint32_t);
protected:
    virtual void Create();
};
