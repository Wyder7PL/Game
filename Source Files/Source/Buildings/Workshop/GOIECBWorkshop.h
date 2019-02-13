#pragma once

#include "../GOIECreateButton.h"
#include "../BuildingConstruction.h"
#include "WorkshopConstruction.h"

class GOIECBWorkshop:public GOIECreateButton
{
public:
    GOIECBWorkshop(Position,Position,GOIEText&,uint32_t);
    virtual ~GOIECBWorkshop();
    virtual BuildingConstruction* CreateBuildingConstruction();
};
