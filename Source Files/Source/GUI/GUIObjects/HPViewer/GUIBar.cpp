#include "GUIBar.h"

GUIBar::GUIBar(Position pos,float w,sf::Color c,uint32_t_pointer * n1,uint32_t_pointer * n2)
:Object(pos),BarWidth(w),GUIDoubleUint(n1,n2)
{
    bar.setFillColor(c);
    bar.setSize(sf::Vector2f(BarWidth,2));
    frame.setSize(sf::Vector2f(BarWidth,2));
    frame.setFillColor(sf::Color(0,0,0,0));
    frame.setOutlineThickness(2);
    frame.setOutlineColor(sf::Color::Black);
}
GUIBar::~GUIBar(){}


void GUIBar::Step()
{
    if(first->DestroyMe()||second->DestroyMe())
    {
        Destroy();
        return;
    }
    float width = *first->GetPointer(),maxwidth = *second->GetPointer();
    if(maxwidth==0)
        maxwidth=1;
    float FinalWidth =(width/maxwidth)*BarWidth;
    bar.setSize(sf::Vector2f(FinalWidth,2));

    Position pos = LocalPos(PhysicObject::GetPosition());
    bar.setPosition(pos.GetX(),pos.GetY());
    frame.setPosition(pos.GetX(),pos.GetY());
}
void GUIBar::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(frame,states);
    target.draw(bar,states);
}
void GUIBar::ChangePosition(Position pos)
{
    position = pos;
}
uint32_t GUIBar::GetHeight()
{
    return 6+10;
}
void GUIBar::SetToDestroy()
{
    Destroy();
}
