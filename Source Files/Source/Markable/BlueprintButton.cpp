#include "BlueprintButton.h"

BlueprintButton::BlueprintButton(Position pos,uint32_t * f)
:Clickable1(pos)
{
    PlayerFraction = f;
    border.setSize(sf::Vector2f(20,20));
    border.setFillColor(sf::Color(0,0,0,0));
    border.setOutlineThickness(5);
    border.setOutlineColor(sf::Color(30,30,30));
}
BlueprintButton::~BlueprintButton(){}

void BlueprintButton::Step()
{
    Position pos = PhysicObject::GetPosition();
    border.setPosition(sfLocalPos(pos));
    Clickable1::Step();
    if(!selected)
        border.setOutlineColor(sf::Color(30,30,30));
}
void BlueprintButton::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(border,states);
}

void BlueprintButton::Selected()
{
    Markable::SetSelectedType(3);
    Markable::MarkedObjectInfo.changed = true;
    border.setOutlineColor(sf::Color(240,240,240));
}
