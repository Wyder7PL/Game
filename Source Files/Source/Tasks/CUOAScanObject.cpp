#include "CUOAScanObject.h"

CUOAScanObject::CUOAScanObject(Position pos,float range)
:Object(pos)
{
    physicshape = new Circle(range/2);
    mask = 1;
    SetZIndex(10);

    PhysicObject::SetPosition(pos.GetX(),pos.GetY());

    temp.setPosition(position.GetX(),position.GetY());
    temp.setOrigin(range,range);
    temp.setRadius(range);
    temp.setFillColor(sf::Color(20,20,20,20));
}

void CUOAScanObject::SetToDestroy()
{
    Destroy();
}

void CUOAScanObject::Step()
{
    temp.setPosition(sfLocalPos(position));
}
void CUOAScanObject::draw(sf::RenderTarget & target,sf::RenderStates states) const{}
