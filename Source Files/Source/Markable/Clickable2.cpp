#include "Clickable2.h"

Clickable2::Clickable2(Position pos)
:Markable(pos),pressed(false)
{

}
Clickable2::~Clickable2(){}

void Clickable2::Step()
{
    if(!pressed)
    {
        if(Keyboard::MouseLW() && InArea( MousePos() ) )
            pressed = true;
    }
    else if(Keyboard::MouseLP())
    {
        pressed = false;
        if(InArea(MousePos()))
            this->Selected();
    }
    Markable::Step();
}
void Clickable2::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    Markable::draw(target,states);
}

