#pragma once

#include "../../Map/Map.h"
#include "../../Creature/PreBuilding.h"

class PreMineConstruction:public PreBuilding
{
public:
    PreMineConstruction(Position,Object*);
protected:
    virtual bool TileCheck();
};
