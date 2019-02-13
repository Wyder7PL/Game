#pragma once

#include "OnBuildingDestroy.h"
#include "../Buildings/Tower/Barracks.h"

class OnBarracksDestroy:public Barracks,public OnBuildingDestroy
{
public:
    OnBarracksDestroy(Position,uint32_t,std::list<BarrackUnitStorage>,bool);
};
