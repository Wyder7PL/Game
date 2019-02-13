#include "OIText.h"


OIText::OIText(Position dimension,sf::Color color,std::string s)
:wAh(dimension),col(color),str(s)
{

}

Position OIText::GetWah()
{
    return wAh;
}
sf::Color OIText::GetCol()
{
    return col;
}
std::string OIText::GetStr()
{
    return str;
}

GUIObjectInfoElement * OIText::Create(Position pos)
{
    return new GOIEText(pos,wAh,col,str);
}
