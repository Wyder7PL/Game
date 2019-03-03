#include "GOIECBTavern.h"


GOIECBTavern::GOIECBTavern(Position pos,Position dim,GOIEText & t,uint32_t fra)
:GOIECreateButton(pos,dim,t,fra){}
GOIECBTavern::~GOIECBTavern(){}
BuildingConstruction* GOIECBTavern::CreateBuildingConstruction()
{
    TavernConstruction * m = new TavernConstruction(Position(rand()%800+170,rand()%700),PlayerFraction);
    m->TESTCreateDemand(1,5);
    return m;
}


