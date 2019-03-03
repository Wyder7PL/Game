#include "GOIEText.h"

GOIEText::GOIEText(Position pos,Position siz,sf::Color col,std::string str)
:Object(pos),tex(str,pos,siz,14)
{
    tex.SetColor(sf::Color(180,180,180));
    tex.SetFont(Fonts::baloo);

    shape.setSize(sf::Vector2f(siz.GetX(),siz.GetY()));
    shape.setFillColor(col);

    physicshape = new Circle(1);
    mask = 0;
}
GOIEText::~GOIEText(){}

void GOIEText::Step()
{
    Position pos = LocalPos(PhysicObject::GetPosition());
    shape.setPosition(pos.GetX(),pos.GetY());
    tex.SetPosition(pos);
}
void GOIEText::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(shape,states);
    tex.draw(target,states);
}

void GOIEText::ChangePosition(Position pos)
{
    position = pos;
}

uint32_t GOIEText::GetHeight()
{
    return shape.getSize().y;
}

void GOIEText::SetToDestroy()
{
    Destroy();
}

