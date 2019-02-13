#include "TavernConstruction.h"

TavernConstruction::TavernConstruction(Position pos,uint32_t f)
:BuildingConstruction(pos,f)
{

}

void TavernConstruction::Create()
{
    AddObject add;
    Tavern * m = new Tavern(position,fraction);
    add.Add(m);
}
