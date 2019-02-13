#pragma once

#include "../GOIECreateButton.h"
#include "../BuildingConstruction.h"
#include "MineConstruction.h"
#include "PreMineConstruction.h"

class GOIECBMine:public GOIECreateButton
{
public:
    GOIECBMine(Position,Position,GOIEText&,uint32_t);
    virtual ~GOIECBMine();
    virtual BuildingConstruction* CreateBuildingConstruction();
protected:
    virtual PreBuilding * CreatePre(Position,Object*);
};
