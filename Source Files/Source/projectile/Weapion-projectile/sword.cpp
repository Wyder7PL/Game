#include "sword.h"

sword::sword(Position pos,uint32_t f,float range,uint32_t damage)
:projectile(pos,f)
{
    swordEff * eff = new swordEff(GetID(),damage);
    eff->SetFractions(GetFractions());
    AddObject add;
    add.Add(eff);

    physicshape = new Circle(range);
    mask = 1;

    TEST.setRadius(range);
    TEST.setOrigin(range,range);
    TEST.setFillColor(sf::Color(120,120,120));
}

void sword::Step()
{
    Destroy();
    TEST.setPosition(sfLocalPos(PhysicObject::GetPosition()));
}
void sword::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(TEST,states);
}
