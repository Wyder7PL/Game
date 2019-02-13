#include "OIBar.h"

OIBar::OIBar(uint32_t_pointer * pointer1,uint32_t_pointer * pointer2,sf::Color c,float w)
:OIDoubleUint(pointer1,pointer2),col(c),width(w)
{

}
GUIObjectInfoElement * OIBar::Create(Position pos)
{
    return new GUIBar(pos,width,col,GetFirst(),GetSecond());
}











