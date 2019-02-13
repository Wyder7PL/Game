#include "OINumber.h"


OINumber::OINumber(Position dimensions,sf::Color color,int32_t number)
:wAh(dimensions),col(color),num(number)
{

}

GUIObjectInfoElement * OINumber::Create(Position pos)
{
    GOIENumber * obj = new GOIENumber(pos,wAh,col);
    obj->SetNumber(num);
    return obj;
}
