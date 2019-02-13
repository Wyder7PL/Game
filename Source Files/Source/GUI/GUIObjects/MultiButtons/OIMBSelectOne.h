#pragma once

#include "../ObjectInfo.h"
#include "../CTextureReferenceIllusion.h"
#include "GOIEMBSelectOne.h"

class OIMBSelectOne:public ObjectInfo
{
    uint32_t_pointer * Selected;
    uint32_t ButtonsAmount;
    Position Dimension;
    Position ButtonDimension;
    std::list<CTextureReferenceIllusion> TRI;
    bool triset;
public:
    OIMBSelectOne(uint32_t,Position,Position,uint32_t_pointer*);
    OIMBSelectOne(uint32_t,Position,std::list<CTextureReferenceIllusion>,Position,uint32_t_pointer*);
    virtual ~OIMBSelectOne();
    virtual GUIObjectInfoElement * Create(Position);
protected:
    uint32_t GetButtonsAmount();
    Position GetDimension();
    Position GetButtonDimension();
    uint32_t_pointer* GetSelected();
    std::list<CTextureReferenceIllusion> GetTRI();
    bool Gettriset();
};
