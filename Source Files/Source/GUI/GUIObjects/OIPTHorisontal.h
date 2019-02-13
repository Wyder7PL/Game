#pragma once

#include "ObjectInfo.h"
#include "CTextureReferenceIllusion.h"
#include "GOIEPTHorisontal.h"

class OIPTHorisontal:public ObjectInfo
{
    Position wAh;
    Position picsiz;
    sf::Color col;
    std::list<CTextureReferenceIllusion> ctri;
public:
    OIPTHorisontal(Position,Position,sf::Color,std::list<CTextureReferenceIllusion>);
    virtual GUIObjectInfoElement * Create(Position);

    Position GetWah();
    Position GetPicSiz();
    sf::Color GetCol();
    std::list<CTextureReferenceIllusion> GetTRI();
};
