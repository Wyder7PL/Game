#include "GUIHPViewer.h"

GUIDoubleUint::GUIDoubleUint(uint32_t_pointer * f,uint32_t_pointer * s)
:first(f),second(s)
{

}
GUIDoubleUint::~GUIDoubleUint(){}
void GUIDoubleUint::Istep(){Step();}
void GUIDoubleUint::Idraw(sf::RenderTarget & target,sf::RenderStates states){draw(target,states);}

OIDoubleUint::OIDoubleUint(uint32_t_pointer * pointer1,uint32_t_pointer * pointer2)
:poi1(pointer1),poi2(pointer2){}
uint32_t_pointer * OIDoubleUint::GetFirst(){return poi1;}
uint32_t_pointer * OIDoubleUint::GetSecond(){return poi2;}


GUIHPViewer::GUIHPViewer(Position pos,/*sf::RectangleShape picture,*/uint32_t_pointer * n1,uint32_t_pointer * n2)
:Object(pos),GUIDoubleUint(n1,n2)
{
    shlash.setFont(Fonts::SMB);
    shlash.setCharacterSize(20);
}
GUIHPViewer::~GUIHPViewer(){}


void GUIHPViewer::Step()
{
    std::string str = "";
    str+=U32PToString(first);
    str+=" / ";
    str+=U32PToString(second);

    Position pos = LocalPos(PhysicObject::GetPosition());

    shlash.setString(str);
    shlash.setOrigin(shlash.getLocalBounds().width,0);
    shlash.setPosition(pos.GetX()+shlash.getLocalBounds().width,pos.GetY());
}
void GUIHPViewer::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(shlash,states);
}
void GUIHPViewer::ChangePosition(Position pos)
{
    position = pos;
}
uint32_t GUIHPViewer::GetHeight()
{
    return shlash.getLocalBounds().height+10; //pic.GetHeight();
}
void GUIHPViewer::SetToDestroy()
{
    Destroy();
}
std::string GUIHPViewer::U32PToString(uint32_t_pointer * pointer)
{
    std::string str = "";
    if(pointer == NULL )
        str += "---";
    else if(pointer->DestroyMe())
        pointer = NULL;
    else
        str += intToStr(*pointer->GetPointer());
    return str;
}


OIHPViewer::OIHPViewer(uint32_t_pointer * pointer1,uint32_t_pointer * pointer2)
:OIDoubleUint(pointer1,pointer2)
{

}
GUIObjectInfoElement * OIHPViewer::Create(Position pos)
{
    return new GUIHPViewer(pos,GetFirst(),GetSecond());
}




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

OIBar::OIBar(uint32_t_pointer * pointer1,uint32_t_pointer * pointer2,sf::Color c,float w)
:OIDoubleUint(pointer1,pointer2),col(c),width(w)
{

}
GUIObjectInfoElement * OIBar::Create(Position pos)
{
    return new GUIBar(pos,width,col,GetFirst(),GetSecond());
}











