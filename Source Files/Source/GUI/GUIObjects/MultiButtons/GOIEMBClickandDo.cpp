#include "GOIEMBClickandDo.h"


GOIEMBClickandDo::GOIEMBClickandDo(Position pos,Position dim,Position bdim,uint32_t bc,uint32_t_pointer * s)
:GOIEMBSelectOne(pos,dim,bdim,bc,s){}

GOIEMBClickandDo::GOIEMBClickandDo(Position pos,Position dim,std::list<CTextureReferenceIllusion> t,Position bdim,uint32_t bc,uint32_t_pointer * s)
:GOIEMBSelectOne(pos,dim,t,bdim,bc,s){}

void GOIEMBClickandDo::Step()
{

    uint32_t i = 0;
    DeselectAll();
    for(std::list<GOIEMBSelectOneButton*>::iterator ite = Buttons.begin();ite != Buttons.end();ite++)
    {
        (*ite)->SetPosition(position.GetX()+i*(ButtonWidth+5)+5,position.GetY()+5);
        (*ite)->Step();
        i++;
    }
    i = 1;
    *Selected->GetPointer() = 0;
    for(std::list<GOIEMBSelectOneButton*>::const_iterator ite = Buttons.begin();ite != Buttons.end();ite++)
    {
        if((*ite)->IsSelected())
        {
            *Selected->GetPointer() = i;
            (*ite)->Selected();
            break;
        }
        i++;
    }
}
