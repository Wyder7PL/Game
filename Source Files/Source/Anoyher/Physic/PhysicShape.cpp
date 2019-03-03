#include "PhysicShape.h"



PhysicShape::~PhysicShape(){};

int32_t PhysicShape::GetShape()
{
    return shape;
}

Position PhysicShape::GetClosestEdge(Position pos1,Position pos2,float d)
{
    return pos1;
}

