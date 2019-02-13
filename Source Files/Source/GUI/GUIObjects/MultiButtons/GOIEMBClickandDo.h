#pragma once

#include "GOIEMBSelectOne.h"

class GOIEMBClickandDo:public GOIEMBSelectOne
{
public:
    GOIEMBClickandDo(Position,Position,Position,uint32_t,uint32_t_pointer*);
    GOIEMBClickandDo(Position,Position,std::list<CTextureReferenceIllusion>,Position,uint32_t,uint32_t_pointer*);
    virtual void Step();
};
