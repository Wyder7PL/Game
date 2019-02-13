#include "hook.h"

hook::hook(Position pos,uint32_t f)
:projectile(pos,f),step(0),Existance(100)
{


    physicshape = new Circle(10);
    mask = 1;
    SetMass(0.3);
    PhysicObject::SetMaxSpeed(7);

    TEST.setRadius(10);
    TEST.setOrigin(5,5);
    TEST.setFillColor(sf::Color(120,120,120));
}

hook::~hook()
{
    //dtor
}

void hook::Step()
{
    step++;
    if(step>2&&step<4)
    {
        hookEff * eff = new hookEff(GetID());
        eff->SetFractions(GetFractions());
        AddObject add;
        add.Add(eff);
    }
    if(Existance == 0)
        {Destroy();TEST.setFillColor(sf::Color(240,120,120));}
    else
        Existance--;
    TEST.setPosition(sfLocalPos(PhysicObject::GetPosition()));
}
void hook::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(TEST,states);
}
