#include "GOIENumber.h"

GOIENumber::GOIENumber(Position pos,Position siz,sf::Color col)
:Object(pos),number(0)
{
    tex.setColor(sf::Color(180,180,180));
    tex.setFont(Fonts::SMB);
    tex.setCharacterSize(16);

    shape.setSize(sf::Vector2f(siz.GetX(),siz.GetY()));
    shape.setFillColor(col);

    physicshape = new Circle(1);
    mask = 0;
}
GOIENumber::~GOIENumber(){}

void GOIENumber::Step()
{
    tex.setString(intToStr(number));
    Position pos = LocalPos(position);
    shape.setPosition(pos.GetX(),pos.GetY());

    tex.setOrigin(tex.getLocalBounds().width,0);
    tex.setPosition(pos.GetX()+shape.getLocalBounds().width,pos.GetY());
}
void GOIENumber::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(shape,states);
    target.draw(tex,states);
}

void GOIENumber::ChangePosition(Position pos)
{
    position = pos;
}

uint32_t GOIENumber::GetHeight()
{
    return shape.getSize().y;
}
uint32_t GOIENumber::GetTextWidth()
{
    return tex.getLocalBounds().width;
}

void GOIENumber::SetToDestroy()
{
    Destroy();
}

void GOIENumber::SetNumber(int32_t i)
{
    number = i;
}
