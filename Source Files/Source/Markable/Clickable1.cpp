#include "Clickable1.h"

Clickable1::Clickable1(Position pos)
:Markable(pos),pressed(false)
{

}
Clickable1::~Clickable1(){}

void Clickable1::Step()
{
    bool wait = false;
    if(!pressed)
    {
        if(Keyboard::MouseLW() && InArea( MousePos() ) )
            pressed = true;
    }
    else if(Keyboard::MouseLP() &&((1 << GetSelectedType()) & ( (1<<4) + (1<<6) + (1<<7))) == 0)
    {
        pressed = false;
        if(InArea( MousePos()))
        {
            selected = true;
            this->Selected();
            wait = true;
        }
    }
    if(selected && !wait && Keyboard::MouseLW()
                    && (!InArea( MousePos())
                         && !(Keyboard::MouseX()<170&&Keyboard::MouseY()>500) )
                         && (GetSelectedType() != 4 ||  GetSelectedType() == 5))
    {
        selected = false;
        this->Deselected();
    }

    Markable::Step();
}
void Clickable1::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    Markable::draw(target,states);
}

void Clickable1::Deselected()
{
    SetSelectedType(0);
}
