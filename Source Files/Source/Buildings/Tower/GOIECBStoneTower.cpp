#include "GOIECBStoneTower.h"

GOIECBStoneTower::GOIECBStoneTower(Position pos,Position dim,GOIEText & t,uint32_t fra)
:GOIECreateButton(pos,dim,t,fra){}
GOIECBStoneTower::~GOIECBStoneTower(){}
BuildingConstruction* GOIECBStoneTower::CreateBuildingConstruction()
{
    StoneTowerConstruction * m = new StoneTowerConstruction(Position(0,0),PlayerFraction);
    m->TESTCreateDemand(2,10);
    return m;
}
