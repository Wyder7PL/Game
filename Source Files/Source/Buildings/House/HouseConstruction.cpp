#include "HouseConstruction.h"

HouseConstruction::HouseConstruction(Position pos,uint32_t f)
:BuildingConstruction(pos,f)
{

}

void HouseConstruction::Create()
{
    AddObject add;
    House * m = new House(position,fraction);
    add.Add(m);
}
