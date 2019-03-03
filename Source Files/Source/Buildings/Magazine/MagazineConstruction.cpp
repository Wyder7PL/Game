#include "MagazineConstruction.h"

MagazineConstruction::MagazineConstruction(Position pos,uint32_t f)
:BuildingConstruction(pos,f)
{

}

void MagazineConstruction::Create()
{
    AddObject add;
    Magazine * m = new Magazine(position,fraction);
    add.Add(m);
}
