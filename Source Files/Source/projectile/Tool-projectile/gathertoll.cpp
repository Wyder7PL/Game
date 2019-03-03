#include "gathertoll.h"

gathertoll::gathertoll(Position pos,uint32_t f,uint32_t i)
:projectile(pos,f),id(i)
{
    gathertollEff * eff = new gathertollEff(GetID(),id);
    eff->SetFractions(GetFractions());
    AddObject add;
    add.Add(eff);
    physicshape = new Circle(5);
    mask = 1;
}
gathertoll::~gathertoll()
{
    //dtor
}
void gathertoll::Step()
{
    Destroy();
}
void gathertoll::draw(sf::RenderTarget & target,sf::RenderStates states) const{}
