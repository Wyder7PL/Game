#pragma once

#include "../GOIECreateButton.h"
#include "../BuildingConstruction.h"
#include "StoneTowerConstruction.h"

class GOIECBStoneTower:public GOIECreateButton
{
public:
    GOIECBStoneTower(Position,Position,GOIEText&,uint32_t);
    virtual ~GOIECBStoneTower();
    virtual BuildingConstruction* CreateBuildingConstruction();
};






