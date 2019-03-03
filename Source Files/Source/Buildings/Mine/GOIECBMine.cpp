#include "GOIECBMine.h"

GOIECBMine::GOIECBMine(Position pos,Position dim,GOIEText & t,uint32_t fra)
:GOIECreateButton(pos,dim,t,fra){}

GOIECBMine::~GOIECBMine(){}

BuildingConstruction* GOIECBMine::CreateBuildingConstruction()
{
    MineConstruction * m = new MineConstruction(Position(0,0),PlayerFraction);
    m->TESTCreateDemand(1,15);
    return m;
}
PreBuilding * GOIECBMine::CreatePre(Position pos,Object* obj)
{
    return new PreMineConstruction(pos,obj);
}
