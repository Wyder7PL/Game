#include "Tavern.h"

GOIEPushareButton::GOIEPushareButton(Position pos,Position dim,sf::Color col,void_pointer*st,void_pointer*dis)
:Object(pos),number(pos,Position(50,dim.GetY()),col)
,button(Position(pos.GetX()+60,pos.GetY()),Position(50,dim.GetY()),st,dis)
{

}
void GOIEPushareButton::Step()
{
    number.Step();
    button.Step();
}
void GOIEPushareButton::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    number.draw(target,states);
    button.draw(target,states);
}
void GOIEPushareButton::ChangePosition(Position pos)
{
    position = pos;
    number.ChangePosition(pos);
    button.ChangePosition(Position(pos.GetX()+60,pos.GetY()));
}
uint32_t GOIEPushareButton::GetHeight()
{
    return button.GetHeight();
}
void GOIEPushareButton::SetToDestroy()
{
    number.SetToDestroy();
    button.SetToDestroy();
    Destroy();
}
void GOIEPushareButton::SetNumber(uint32_t n)
{
    number.SetNumber(n);
}
