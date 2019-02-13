#pragma once

#include "../GOIECreateButton.h"
#include "../BuildingConstruction.h"
#include "HouseConstruction.h"

class GOIECBHouse:public GOIECreateButton
{
public:
    GOIECBHouse(Position,Position,GOIEText&,uint32_t);
    virtual ~GOIECBHouse();
    virtual BuildingConstruction* CreateBuildingConstruction();
};
