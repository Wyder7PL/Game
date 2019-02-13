#include "GOIESingleClickButton.h"


GOIESingleClickButton::GOIESingleClickButton(Position pos,Position dim,void_pointer * st,void_pointer * dis)
:Clickable2(pos),state(st),disabled(dis)
{
    physicshape = new NRR(dim);
    mask = 0;
    shape.setSize(sf::Vector2f(dim.GetX(),dim.GetY()));
    shape.setFillColor(sf::Color(190,90,90));
}
GOIESingleClickButton::GOIESingleClickButton(Position pos,Position dim,sf::Texture & t,void_pointer * st,void_pointer * dis)
:Clickable2(pos),state(st),disabled(dis)
{
    physicshape = new NRR(dim);
    mask = 0;
    shape.setSize(sf::Vector2f(dim.GetX(),dim.GetY()));
    shape.setFillColor(sf::Color(190,90,90));

    sprite.setTexture(t);
    sprite.setScale((dim.GetX()/100),(dim.GetY()/100));
}
void GOIESingleClickButton::Step()
{
    Clickable2::Step();
    shape.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    sprite.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    if((*reinterpret_cast<bool*>(disabled->GetPointer())))
       shape.setFillColor(sf::Color(130,50,50));
}
void GOIESingleClickButton::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    Clickable2::draw(target,states);
    target.draw(shape,states);
    target.draw(sprite,states);
}
uint32_t GOIESingleClickButton::GetHeight()
{
    return physicshape->GetSize().GetY();
}
void GOIESingleClickButton::SetToDestroy()
{
    Destroy();
}
void GOIESingleClickButton::ChangePosition(Position pos)
{
    position = pos;
}
void GOIESingleClickButton::Selected()
{
    if(!(*reinterpret_cast<bool*>(disabled->GetPointer())))
    {
        shape.setFillColor(sf::Color(150,50,50));
        (*reinterpret_cast<bool*>(state->GetPointer()))=true;
    }
}
