#include "OIDropDown.h"

OIDropDown::OIDropDown(Position dim,void_pointer * ele)
:Elements(ele),Dimension(dim){}
GUIObjectInfoElement * OIDropDown::Create(Position pos)
{
    return new GOIEDropDown(pos,Dimension,Elements);
}
