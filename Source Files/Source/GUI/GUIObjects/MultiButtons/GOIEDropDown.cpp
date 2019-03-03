#include "GOIEDropDown.h"

GOIEDropDown::GOIEDropDown(Position pos,Position dim,void_pointer * l)
:Object(pos),Elements(l)
{
    physicshape = new NRR(dim);
    mask = 0;
}
GOIEDropDown::~GOIEDropDown(){}
void GOIEDropDown::Step()
{
    if(Elements==NULL||Elements->DestroyMe())
    {
        Destroy();
        return;
    }
    uint32_t height = 0;
    std::list <GUIObjectInfoElement*> * s = &(*(reinterpret_cast<std::list <GUIObjectInfoElement*>*>(Elements->GetPointer())));
    for(std::list <GUIObjectInfoElement*>::iterator ite = s->begin();ite != s->end();ite++)
    {
        (*ite)->ChangePosition(Position(position.GetX()+5,position.GetY()+5+height));
        (*ite)->Step();
        height += (*ite)->GetHeight()+5;
    }
}
void GOIEDropDown::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    std::list <GUIObjectInfoElement*> * s = &(*(reinterpret_cast<std::list <GUIObjectInfoElement*>*>(Elements->GetPointer())));
    for(std::list <GUIObjectInfoElement*>::const_iterator ite = s->begin();ite != s->end();ite++)
    {
        (*ite)->draw(target,states);
    }
}

void GOIEDropDown::ChangePosition(Position pos)
{
    position = pos;
}

uint32_t GOIEDropDown::GetHeight()
{
    if(Elements==NULL||Elements->DestroyMe())
    {
        Destroy();
        return 0;
    }
    uint32_t height = 0;
    std::list <GUIObjectInfoElement*> * s = &(*(reinterpret_cast< std::list <GUIObjectInfoElement*>* >(Elements->GetPointer())));
    for(std::list <GUIObjectInfoElement*>::iterator ite = s->begin();ite != s->end();ite++)
    {
        height += (*ite)->GetHeight();
    }
    return height;
}

void GOIEDropDown::SetToDestroy()
{
    Destroy();
}
