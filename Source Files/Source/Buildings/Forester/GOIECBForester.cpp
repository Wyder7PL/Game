#include "GOIECBForester.h"

GOIECBForester::GOIECBForester(Position pos,Position dim,GOIEText & t,uint32_t fra)
:GOIECreateButton(pos,dim,t,fra){}

GOIECBForester::~GOIECBForester(){}

BuildingConstruction* GOIECBForester::CreateBuildingConstruction()
{
    ForesterConstruction * m = new ForesterConstruction(Position(0,0),PlayerFraction);
    m->TESTCreateDemand(1,12);
    return m;
}









