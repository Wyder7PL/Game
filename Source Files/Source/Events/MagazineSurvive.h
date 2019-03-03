#pragma once

#include "../Buildings/Magazine/Magazine.h"
#include "BuildingSurvive.h"

class MagazineSurvive:public Magazine,public BuildingSurvive
{
public:
    MagazineSurvive(Position,uint32_t,bool,uint32_t);
    virtual void Step();
};
