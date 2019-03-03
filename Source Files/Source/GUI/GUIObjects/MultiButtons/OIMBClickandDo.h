#pragma once

#include "OIMBSelectOne.h"
#include "GOIEMBClickandDo.h"

class OIMBClickandDo:public OIMBSelectOne
{
public:
    OIMBClickandDo(uint32_t,Position,Position,uint32_t_pointer*);
    OIMBClickandDo(uint32_t,Position,std::list<CTextureReferenceIllusion>,Position,uint32_t_pointer*);
    virtual ~OIMBClickandDo();
    virtual GUIObjectInfoElement * Create(Position);
};
