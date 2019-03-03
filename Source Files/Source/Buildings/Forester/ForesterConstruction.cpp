#include "ForesterConstruction.h"

ForesterConstruction::ForesterConstruction(Position pos,uint32_t f)
:BuildingConstruction(pos,f)
{

}

void ForesterConstruction::Create()
{
    AddObject add;
    Forester * m = new Forester(position,fraction);
    add.Add(m);
}
