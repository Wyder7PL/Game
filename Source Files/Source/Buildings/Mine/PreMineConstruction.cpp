#include "PreMineConstruction.h"

PreMineConstruction::PreMineConstruction(Position pos,Object* obj)
:PreBuilding(pos,obj){}

bool PreMineConstruction::TileCheck()
{
    uint32_t t = Map::ActualMap->GetTileType(position.GetX()-160,position.GetY());
    if(t==11||t==12)
        return true;
    return false;
}
