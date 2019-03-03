#pragma once

#include "../GOIECreateButton.h"
#include "../BuildingConstruction.h"
#include "TowerConstruction.h"

class GOIECBTower:public GOIECreateButton
{
public:
    GOIECBTower(Position,Position,GOIEText&,uint32_t);
    virtual ~GOIECBTower();
    virtual BuildingConstruction* CreateBuildingConstruction();
};
