#include "GOIECBWorkshop.h"

GOIECBWorkshop::GOIECBWorkshop(Position pos,Position dim,GOIEText & t,uint32_t fra)
:GOIECreateButton(pos,dim,t,fra){}

GOIECBWorkshop::~GOIECBWorkshop(){}

BuildingConstruction* GOIECBWorkshop::CreateBuildingConstruction()
{
    WorkshopConstruction * w = new WorkshopConstruction(Position(0,0),PlayerFraction);
    w->TESTCreateDemand(1,3);
    return w;
}
