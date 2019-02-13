#include "GOIEMBSelectOne.h"

GOIEMBSelectOne::GOIEMBSelectOne(Position pos,Position dim,Position bdim,uint32_t bc,uint32_t_pointer * s)
:Object(pos),Selected(s),ButtonWidth(bdim.GetX())
{
    physicshape = new NRR(dim);
    mask = 0;
    for(uint32_t i = 0;i < bc;i++)
    {
        GOIEMBSelectOneButton * b = new GOIEMBSelectOneButton(Position(pos.GetX()+25*i+5,pos.GetX()+5),bdim);
        if(i+1==*Selected->GetPointer())
            b->Selected();
        Buttons.push_back(b);
    }
}
GOIEMBSelectOne::GOIEMBSelectOne(Position pos,Position dim,std::list<CTextureReferenceIllusion> t,Position bdim,uint32_t bc,uint32_t_pointer * s)
:Object(pos),Selected(s),ButtonWidth(bdim.GetX())
{
    physicshape = new NRR(dim);
    mask = 0;
    std::list<CTextureReferenceIllusion>::iterator ite = t.begin();
    for(uint32_t i = 0;i < bc;i++)
    {
        GOIEMBSelectOneButton * b;
        if(ite!=t.end())
            b = new GOIEMBSelectOneButton(Position(pos.GetX()+25*i+5,pos.GetX()+5),bdim,(*ite++).Ref);
        else
            b = new GOIEMBSelectOneButton(Position(pos.GetX()+25*i+5,pos.GetX()+5),bdim);
        if(i+1==*Selected->GetPointer())
            b->Selected();
        Buttons.push_back(b);
    }
}
GOIEMBSelectOne::~GOIEMBSelectOne()
{
    for(std::list<GOIEMBSelectOneButton*>::iterator ite = Buttons.begin();ite != Buttons.end();)
    {
        delete (*ite);
        ite = Buttons.erase(ite);
    }
}
void GOIEMBSelectOne::Step()
{

    uint32_t i = 0;
    for(std::list<GOIEMBSelectOneButton*>::iterator ite = Buttons.begin();ite != Buttons.end();ite++)
    {
        (*ite)->SetPosition(position.GetX()+i*(ButtonWidth+5)+5,position.GetY()+5);
        (*ite)->Step();
        i++;
    }
    i = 1;
    for(std::list<GOIEMBSelectOneButton*>::const_iterator ite = Buttons.begin();ite != Buttons.end();ite++)
    {
        if((*ite)->IsSelected() && *Selected->GetPointer() != i)
        {
            DeselectAll();
            *Selected->GetPointer() = i;
            (*ite)->Selected();
            break;
        }
        i++;
    }
}
void GOIEMBSelectOne::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    for(std::list<GOIEMBSelectOneButton*>::const_iterator ite = Buttons.begin();ite != Buttons.end();ite++)
    {
        (*ite)->draw(target,states);
    }
}

void GOIEMBSelectOne::ChangePosition(Position pos)
{
    position = pos;
}

uint32_t GOIEMBSelectOne::GetHeight()
{
    if(Buttons.size()>0)
        return (*Buttons.begin())->GetHeight()+5;
    return 0;
}

void GOIEMBSelectOne::SetToDestroy()
{
    for(std::list<GOIEMBSelectOneButton*>::iterator ite = Buttons.begin();ite != Buttons.end();ite++)
    {
        (*ite)->SetToDestroy();
    }
    Destroy();
}

void GOIEMBSelectOne::Disable(uint32_t b,bool s)
{
    if(b <= Buttons.size())
        (*(Buttons.begin()) + b-1)->Disable(s);
}

void GOIEMBSelectOne::DeselectAll()
{
    for(std::list<GOIEMBSelectOneButton*>::iterator ite = Buttons.begin();ite != Buttons.end();ite++)
    {
        (*ite)->Deselect();
    }
}
