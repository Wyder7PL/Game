#include "OIMBClickandDo.h"

OIMBClickandDo::OIMBClickandDo(uint32_t buam,Position dim,Position bdim,uint32_t_pointer * sel)
:OIMBSelectOne(buam,dim,bdim,sel){}

OIMBClickandDo::OIMBClickandDo(uint32_t buam,Position dim,std::list<CTextureReferenceIllusion> t,Position bdim,uint32_t_pointer * sel)
:OIMBSelectOne(buam,dim,t,bdim,sel){}

OIMBClickandDo::~OIMBClickandDo(){}

GUIObjectInfoElement * OIMBClickandDo::Create(Position pos)
{
    if(Gettriset())
        return new GOIEMBClickandDo(pos,GetDimension(),GetTRI(),GetButtonDimension(),GetButtonsAmount(),GetSelected());
    return new GOIEMBClickandDo(pos,GetDimension(),GetButtonDimension(),GetButtonsAmount(),GetSelected());
}
