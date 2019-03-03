#include "MineConstruction.h"

MineConstruction::MineConstruction(Position pos,uint32_t f)
:BuildingConstruction(pos,f)
{

}

void MineConstruction::Create()
{
    AddObject add;
    Mine * m = new Mine(position,fraction);
    add.Add(m);
}
