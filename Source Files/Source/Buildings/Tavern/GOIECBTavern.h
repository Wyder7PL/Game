#pragma once

#include "../GOIECreateButton.h"
#include "../BuildingConstruction.h"
#include "TavernConstruction.h"

class GOIECBTavern:public GOIECreateButton
{
public:
    GOIECBTavern(Position,Position,GOIEText&,uint32_t);
    virtual ~GOIECBTavern();
    virtual BuildingConstruction* CreateBuildingConstruction();
};

