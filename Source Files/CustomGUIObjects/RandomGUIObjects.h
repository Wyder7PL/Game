#ifndef RANDOMGUIOBJECTS_H
#define RANDOMGUIOBJECTS_H

#include "../include/ObjectInfo.h"

class GOIEPTHorisontal:public Object,public GOIEvirtual
{
    sf::RectangleShape background;
    std::list<GOIEPicture*> pictures;
    float border;
    float psx;
public:
    GOIEPTHorisontal(Position,Position,Position,sf::Color,std::list<CTextureReferenceIllusion>);
    virtual ~GOIEPTHorisontal();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void ChangePosition(Position);
    virtual uint32_t GetHeight();
    virtual void SetToDestroy();
};
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

#endif // RANDOMGUIOBJECTS_H
