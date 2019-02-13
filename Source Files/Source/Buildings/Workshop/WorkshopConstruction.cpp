#include "WorkshopConstruction.h"

WorkshopConstruction::WorkshopConstruction(Position pos,uint32_t f)
:BuildingConstruction(pos,f)
{

}

void WorkshopConstruction::Create()
{
    AddObject add;
    Workshop * w = new Workshop(position,fraction);
    add.Add(w);
}
