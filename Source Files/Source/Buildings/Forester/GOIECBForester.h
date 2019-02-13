#pragma once

#include "../GOIECreateButton.h"
#include "../BuildingConstruction.h"
#include "ForesterConstruction.h"


class GOIECBForester:public GOIECreateButton
{
public:
    GOIECBForester(Position,Position,GOIEText&,uint32_t);
    virtual ~GOIECBForester();
    virtual BuildingConstruction* CreateBuildingConstruction();
};
