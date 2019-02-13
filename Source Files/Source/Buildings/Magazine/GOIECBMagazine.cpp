#include "GOIECBMagazine.h"

GOIECBMagazine::GOIECBMagazine(Position pos,Position dim,GOIEText & t,uint32_t fra)
:GOIECreateButton(pos,dim,t,fra){}

GOIECBMagazine::~GOIECBMagazine(){}

BuildingConstruction* GOIECBMagazine::CreateBuildingConstruction()
{
    MagazineConstruction * m = new MagazineConstruction(Position(rand()%800+170,rand()%700),PlayerFraction);
    m->TESTCreateDemand(1,5);
    return m;
}
