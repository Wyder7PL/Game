#include "GOIECBHouse.h"

GOIECBHouse::GOIECBHouse(Position pos,Position dim,GOIEText & t,uint32_t fra)
:GOIECreateButton(pos,dim,t,fra){}
GOIECBHouse::~GOIECBHouse(){}
BuildingConstruction* GOIECBHouse::CreateBuildingConstruction()
{
    HouseConstruction * m = new HouseConstruction(Position(rand()%800+170,rand()%700),PlayerFraction);
    m->TESTCreateDemand(1,8);
    return m;
}
