#include "GOIECBTower.h"

GOIECBTower::GOIECBTower(Position pos,Position dim,GOIEText & t,uint32_t fra)
:GOIECreateButton(pos,dim,t,fra){}
GOIECBTower::~GOIECBTower(){}
BuildingConstruction* GOIECBTower::CreateBuildingConstruction()
{
    TowerConstruction * m = new TowerConstruction(Position(0,0),PlayerFraction);
    m->TESTCreateDemand(1,10);
    return m;
}
