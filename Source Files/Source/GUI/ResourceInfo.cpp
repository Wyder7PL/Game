#include "ResourceInfo.h"

ResourceInfo::ResourceInfo(Position pos)
:Object(pos),Value(Position(pos.GetX()+30,pos.GetY()+5),Position(50,20),sf::Color(30,30,30))
{
    resource.setSize(sf::Vector2f(20,20));
    resource.setOrigin(10,10);
    resource.setFillColor(sf::Color(100,0,0));

    resource2.setOrigin(50,50);
    resource2.setScale(0.2,0.2);


    physicshape = new Circle(1);
    mask = 0;
}
ResourceInfo::~ResourceInfo(){}
void ResourceInfo::Step()
{
    Value.SetPosition(position.GetX()+30,position.GetY()+5);
    Position pos = LocalPos(position);
    resource.setPosition(pos.GetX()+15,pos.GetY()+15);
    resource2.setPosition(pos.GetX()+15,pos.GetY()+15);
    Value.Step();
}
void ResourceInfo::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(resource,states);
    target.draw(resource2,states);
    Value.draw(target,states);
}

void ResourceInfo::SetAmount(int32_t a)
{
    Value.SetNumber(a);
}
void ResourceInfo::SetTexture(sf::Texture&t)
{
    resource2.setTexture(t);
}
