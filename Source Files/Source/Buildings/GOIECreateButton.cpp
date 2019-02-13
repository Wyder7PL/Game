#include "GOIECreateButton.h"

GOIECreateButton::GOIECreateButton(Position pos,Position dim,GOIEText t,uint32_t fraction)
:Clickable2(pos),tex(t),PlayerFraction(fraction)
{
    physicshape = new NRR(dim);
    mask = 0;
}
GOIECreateButton::~GOIECreateButton(){}

void GOIECreateButton::Step()
{
    Clickable2::Step();
    Position pos = GetPosition();
    tex.SetPosition(pos.GetX(),pos.GetY());
    tex.Step();
}
void GOIECreateButton::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    Clickable2::draw(target,states);
    tex.draw(target,states);
}

void GOIECreateButton::ChangePosition(Position pos)
{
    position = pos;
}

uint32_t GOIECreateButton::GetHeight()
{
    return tex.GetHeight();
}

void GOIECreateButton::SetToDestroy()
{
    tex.SetToDestroy();
    Destroy();
}

void GOIECreateButton::Selected()
{
    if(Markable::GetSelectedType() != 4)
    {
        Markable::SetSelectedType(4);
        BuildingConstruction * b = new BuildingConstruction(Position(0,0),PlayerFraction);
        b->TESTCreateDemand(1,10);
        PreBuilding * p = new PreBuilding(position,b);
        AddObject a;
        a.Add(p);
    }
}
