#include "GOIEPicture.h"

GOIEPicture::GOIEPicture(Position pos,Position siz,sf::Color col,const sf::Texture& t)
:Object(pos)
{
    picture.setTexture(t);
    shape.setSize(sf::Vector2f(siz.GetX(),siz.GetY()));
    shape.setFillColor(col);

    picture.setScale((siz.GetX()/100),(siz.GetY()/100));

    physicshape = new Circle(1);
    mask = 0;
}
GOIEPicture::~GOIEPicture(){}


void GOIEPicture::Step()
{
    shape.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    picture.setPosition(sfLocalPos(PhysicObject::GetPosition()));
}
void GOIEPicture::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(shape,states);
    target.draw(picture,states);
}

void GOIEPicture::ChangePosition(Position pos)
{
    position = pos;
}

uint32_t GOIEPicture::GetHeight()
{
    return shape.getSize().y;
}

void GOIEPicture::SetToDestroy()
{
    Destroy();
}

