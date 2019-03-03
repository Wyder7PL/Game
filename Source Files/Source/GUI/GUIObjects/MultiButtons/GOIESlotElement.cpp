#include "GOIESlotElement.h"

GOIESlotElement::GOIESlotElement(Position pos,void_pointer*poi1,void_pointer*poi2)
:Object(pos),kick(pos,Position(40,40),Textures::textures->Exit,poi1,poi2)
{
    Constructor();
}
GOIESlotElement::GOIESlotElement(Position pos,const sf::Texture&t,void_pointer*poi1,void_pointer*poi2)
:Object(pos),kick(pos,Position(40,40),Textures::textures->Exit,poi1,poi2)
{
    Constructor();
    item.setTexture(t);
    item.scale(0.4,0.4);
}
void GOIESlotElement::Constructor()
{
    border.setSize(sf::Vector2f(40,92));
    border.setFillColor(sf::Color(0,0,0,0));
    border.setOrigin(2,2);
    border.setOutlineColor(sf::Color(0,0,0));
    border.setOutlineThickness(2);

}
void GOIESlotElement::Step()
{
    Position pos = LocalPos(PhysicObject::GetPosition());
    border.setPosition(pos.GetX(),pos.GetY());
    item.setPosition(pos.GetX(),pos.GetY());
    kick.SetPosition(position.GetX(),position.GetY()+50);
    kick.Step();
}
void GOIESlotElement::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(border,states);
    target.draw(item,states);
    kick.draw(target,states);
}
uint32_t GOIESlotElement::GetHeight()
{
    return 90;
}
void GOIESlotElement::ChangePosition(Position pos)
{
    position = pos;
}
void GOIESlotElement::SetToDestroy()
{
    Destroy();
    kick.SetToDestroy();
}
