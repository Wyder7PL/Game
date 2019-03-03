#include "GOIEMBSelectOneButton.h"

GOIEMBSelectOneButton::GOIEMBSelectOneButton(Position pos,Position dim)
:Clickable2(pos),selected(false),disabled(false)
{
    shape.setSize(sf::Vector2f(dim.GetX(),dim.GetY()));
    shape.setFillColor(sf::Color(90,90,90));
    physicshape = new NRR(dim);
    mask = 0;
}
GOIEMBSelectOneButton::GOIEMBSelectOneButton(Position pos,Position dim,const sf::Texture & t)
:Clickable2(pos),selected(false),disabled(false)
{
    shape.setSize(sf::Vector2f(dim.GetX(),dim.GetY()));
    shape.setFillColor(sf::Color(90,90,90));
    physicshape = new NRR(dim);
    mask = 0;
    sprite.setTexture(t);
    sprite.setScale((dim.GetX()/100),(dim.GetY()/100));
}
void GOIEMBSelectOneButton::Step()
{
    Clickable2::Step();
    shape.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    sprite.setPosition(sfLocalPos(PhysicObject::GetPosition()));
}
void GOIEMBSelectOneButton::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    Clickable2::draw(target,states);
    target.draw(shape,states);
    target.draw(sprite,states);
}

void GOIEMBSelectOneButton::ChangePosition(Position pos)
{
    position = pos;
}

uint32_t GOIEMBSelectOneButton::GetHeight()
{
    return shape.getSize().y;
}

void GOIEMBSelectOneButton::SetToDestroy()
{
    Destroy();
}
void GOIEMBSelectOneButton::Selected()
{
    if(!disabled)
    {
        shape.setFillColor(sf::Color(70,70,70));
        selected = true;
    }
}
bool GOIEMBSelectOneButton::IsSelected()
{
    return selected;
}
void GOIEMBSelectOneButton::Deselect()
{
    selected = false;
    shape.setFillColor(sf::Color(90,90,90));
}
void GOIEMBSelectOneButton::Disable(bool d)
{
    disabled = d;
    if(disabled)
        shape.setFillColor(sf::Color(50,50,50));
    else
        shape.setFillColor(sf::Color(90,90,90));
}
