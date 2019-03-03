#include "chaineffect.h"

chaineffect::chaineffect(Position pos)
:Object(pos),Existance(20)
{
    SetZIndex(6);

    physicshape = new Circle(6);
    mask = 1;
    SetMass(0.3);


    TEST.setRadius(2);
    TEST.setOrigin(3,3);
    TEST.setFillColor(sf::Color(0,0,0,0));
    TEST.setOutlineThickness(1);
}

chaineffect::~chaineffect()
{
    //dtor
}

void chaineffect::Step()
{
    TEST.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    TEST.setOutlineColor(sf::Color(120,120,120,255*Existance/20));
    if(Existance == 0)
        {Destroy();}
    else
        Existance--;
}
void chaineffect::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(TEST,states);
}
