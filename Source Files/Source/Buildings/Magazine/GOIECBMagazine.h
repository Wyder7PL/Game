#pragma once

#include "../GOIECreateButton.h"
#include "../BuildingConstruction.h"
#include "MagazineConstruction.h"

class GOIECBMagazine:public GOIECreateButton
{
public:
    GOIECBMagazine(Position,Position,GOIEText&,uint32_t);
    virtual ~GOIECBMagazine();
    virtual BuildingConstruction* CreateBuildingConstruction();
};
