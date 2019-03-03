#include "OIMBSelectOne.h"

OIMBSelectOne::OIMBSelectOne(uint32_t buam,Position dim,Position bdim,uint32_t_pointer * sel)
:Selected(sel),ButtonsAmount(buam),Dimension(dim),ButtonDimension(bdim),triset(false){}

OIMBSelectOne::OIMBSelectOne(uint32_t buam,Position dim,std::list<CTextureReferenceIllusion> t,Position bdim,uint32_t_pointer * sel)
:Selected(sel),ButtonsAmount(buam),Dimension(dim),ButtonDimension(bdim),TRI(t),triset(true){}

OIMBSelectOne::~OIMBSelectOne()
{

}

GUIObjectInfoElement * OIMBSelectOne::Create(Position pos)
{
    if(triset)
        return new GOIEMBSelectOne(pos,Dimension,TRI,ButtonDimension,ButtonsAmount,Selected);
    return new GOIEMBSelectOne(pos,Dimension,ButtonDimension,ButtonsAmount,Selected);
}
uint32_t OIMBSelectOne::GetButtonsAmount(){return ButtonsAmount;}
Position OIMBSelectOne::GetDimension()
{
    return Dimension;
}
Position OIMBSelectOne::GetButtonDimension()
{
    return ButtonDimension;
}
uint32_t_pointer* OIMBSelectOne::GetSelected()
{
    return Selected;
}
std::list<CTextureReferenceIllusion> OIMBSelectOne::GetTRI()
{
    return TRI;
}
bool OIMBSelectOne::Gettriset()
{
    return triset;
}
