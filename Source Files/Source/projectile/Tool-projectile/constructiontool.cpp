#include "constructiontool.h"

constructiontool::constructiontool(Position pos,uint32_t f,uint32_t Rtype)
:projectile(pos,f)
{
    constructiontoolEff * eff = new constructiontoolEff(GetID(),Rtype);
    eff->SetFractions(GetFractions());
    AddObject add;
    add.Add(eff);
    physicshape = new Circle(5);
    mask = 1;

    TEST.setRadius(5);
    TEST.setOrigin(5,5);
    TEST.setFillColor(sf::Color(120,120,120));
}
constructiontool::~constructiontool()
{
    //dtor
}
void constructiontool::Step()
{
    TEST.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    Destroy();
}
void constructiontool::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(TEST,states);
}
