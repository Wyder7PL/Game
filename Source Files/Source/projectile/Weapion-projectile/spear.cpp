#include "spear.h"

spear::spear(Position pos,uint32_t f)
:projectile(pos,f)
{
    spearEff * eff = new spearEff(GetID());
    eff->SetFractions(GetFractions());
    AddObject add;
    add.Add(eff);

    physicshape = new Circle(10);
    mask = 1;

    TEST.setRadius(10);
    TEST.setOrigin(10,10);
    TEST.setFillColor(sf::Color(20,20,20));
}

spear::~spear()
{
    //dtor
}

void spear::Step()
{
    Destroy();
    TEST.setPosition(sfLocalPos(PhysicObject::GetPosition()));
}
void spear::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(TEST,states);
}
