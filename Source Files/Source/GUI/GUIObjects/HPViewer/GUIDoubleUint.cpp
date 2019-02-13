#include "GUIDoubleUint.h"

GUIDoubleUint::GUIDoubleUint(uint32_t_pointer * f,uint32_t_pointer * s)
:first(f),second(s)
{

}

GUIDoubleUint::~GUIDoubleUint(){}

void GUIDoubleUint::Istep()
{
    Step();
}

void GUIDoubleUint::Idraw(sf::RenderTarget & target,sf::RenderStates states)
{
    draw(target,states);
}
