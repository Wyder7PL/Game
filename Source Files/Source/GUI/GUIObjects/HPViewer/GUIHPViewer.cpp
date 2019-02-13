#include "GUIHPViewer.h"

GUIHPViewer::GUIHPViewer(Position pos,uint32_t_pointer * n1,uint32_t_pointer * n2)
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
