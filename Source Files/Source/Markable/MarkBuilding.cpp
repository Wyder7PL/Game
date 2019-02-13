#include "MarkBuilding.h"

MarkBuilding::MarkBuilding(Position pos)
:Clickable1(pos),TileOccupy()
{

}
MarkBuilding::~MarkBuilding()
{

}

void MarkBuilding::Step()
{


    if(FirstStep())
    {
        if(SetGrid(position,GetShape()->GetSize()))
            Destroy();
    }

    Clickable1::Step();

    mark.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    if(selected)
        mark.setOutlineColor(sf::Color(250,250,250,100));
    else
        mark.setOutlineColor(sf::Color(0,0,0,0));
}
void MarkBuilding::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    Clickable1::draw(target,states);
    target.draw(mark,states);
}

void MarkBuilding::Selected()
{
    Markable::SetSelectedType(1);
    Markable::MarkedObjectInfo.changed = true;

}

void MarkBuilding::MarkSize(float siz)
{
    mark.setRadius(siz);
    mark.setOrigin(siz,siz);
    mark.setOutlineThickness(5);
    mark.setOutlineColor(sf::Color(150,150,150,100));
    mark.setFillColor(sf::Color(0,0,0,0));
}
