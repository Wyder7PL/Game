#include "CollideAll.h"


CollideAll::CollideAll()
{
    shape = 3;
}
CollideAll::~CollideAll(){}

bool CollideAll::CollideV2(PhysicShape*obj,Position pos1,Position pos2){return true;}

bool CollideAll::InArea(Position position,Position pos){return true;}

Position CollideAll::GetSize(){return Position(0,0);}

