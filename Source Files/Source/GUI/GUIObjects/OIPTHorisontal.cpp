#include "OIPTHorisontal.h"

OIPTHorisontal::OIPTHorisontal(Position dim,Position picdim,sf::Color c,std::list<CTextureReferenceIllusion> t)
:wAh(dim),picsiz(picdim),col(c),ctri(t){}

GUIObjectInfoElement * OIPTHorisontal::Create(Position pos)
{
    return new GOIEPTHorisontal(pos,wAh,picsiz,col,ctri);
}

Position OIPTHorisontal::GetWah()
{
    return wAh;
}
Position OIPTHorisontal::GetPicSiz()
{
    return picsiz;
}
sf::Color OIPTHorisontal::GetCol()
{
    return col;
}
std::list<CTextureReferenceIllusion> OIPTHorisontal::GetTRI()
{
    return ctri;
}

