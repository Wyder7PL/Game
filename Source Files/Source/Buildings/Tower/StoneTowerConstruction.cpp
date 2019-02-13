#include "StoneTowerConstruction.h"

StoneTowerConstruction::StoneTowerConstruction(Position pos,uint32_t f)
:BuildingConstruction(pos,f)
{

}

void StoneTowerConstruction::Create()
{
    AddObject add;
    Tower * m = new StoneTower(position,fraction);
    add.Add(m);
}
