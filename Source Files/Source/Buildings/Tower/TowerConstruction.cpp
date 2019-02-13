#include "TowerConstruction.h"

TowerConstruction::TowerConstruction(Position pos,uint32_t f)
:BuildingConstruction(pos,f)
{

}

void TowerConstruction::Create()
{
    AddObject add;
    Tower * m = new Tower(position,fraction);
    add.Add(m);
}
