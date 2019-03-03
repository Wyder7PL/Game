#include "bullet.h"

bullet::bullet(Position pos,uint32_t f,uint32_t d)
:projectile(pos,f),damage(d),step(0),Existance(100)
{


    physicshape = new Circle(1);
    mask = 1;
    SetMass(0.1);
    PhysicObject::SetMaxSpeed(10);

    TEST.setRadius(2);
    TEST.setOrigin(1,1);
    TEST.setFillColor(sf::Color(120,180,20));
}

bullet::~bullet()
{
    //dtor
}

void bullet::Step()
{
    step++;
    if(step>2&&step<4)
    {
        bulletEff * eff = new bulletEff(GetID(),damage);
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
void bullet::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(TEST,states);
}
