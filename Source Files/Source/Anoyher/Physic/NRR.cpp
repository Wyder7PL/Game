#include "NRR.h"

NRR::NRR()
:dimensions(Position(1,1))
{
    shape = 2;
}

NRR::NRR(Position s)
:dimensions(s)
{
    shape = 2;
}

NRR::~NRR(){}

bool NRR::CollideV2(PhysicShape * obj,Position pos1,Position pos2)
{
    return false;
}

bool NRR::InArea(Position position,Position pos)
{
    if(position.GetX()<pos.GetX() && position.GetX()+dimensions.GetX()>pos.GetX())
    {
        if(position.GetY()<pos.GetY() && position.GetY()+dimensions.GetY()>pos.GetY())
            return true;
    }
    return false;
}

Position NRR::CollideCircle(Circle * cir,Position position,Position pos)
{
    Position force(0,0);
    return force;
}
bool NRR::CollideCircleV2(Circle * cir,Position position,Position pos)
{
    return false;
}

void NRR::SetSize(Position s)
{
    dimensions = s;
}

Position NRR::GetSize()
{
    return dimensions;
}







